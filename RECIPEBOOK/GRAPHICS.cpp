#include "GRAPHICS.h"
#include "SearchEngine.h"
#include "Recipe.h"
#include "Utils.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]

void Main(array<String^>^ args) {

	Application::SetCompatibleTextRenderingDefault(false);

	Application::EnableVisualStyles();

	RECIPEBOOK::GRAPHICS GRAPHICS;

	Application::Run(% GRAPHICS);
	
}

//Load form
System::Void RECIPEBOOK::GRAPHICS::GRAPHICS_Load(System::Object^ sender, System::EventArgs^ e)
{
	if (currentRecipePictureBox->AllowDrop)
	{
		searchLabel->Text = "GJFADSUH<TDFAJWDYG";
	}
	return System::Void();
}

//Search start
System::Void RECIPEBOOK::GRAPHICS::startSearchButton_Click(System::Object^ sender, System::EventArgs^ e)
{

	SearchData searchData;

	searchData.name = Utils::ConvertToSTDString(nameSearchTextBox->Text);
	
	searchData.categories = Utils::ConvertFromSysSrtToArray(categoriesSearchTextBox->Text);
	
	searchData.ingridients = Utils::ConvertFromSysSrtToArray(ingridientsSearchTextBox->Text);
	
	searchData.phraseFromComment = Utils::ConvertToSTDString(commentTextBox->Text);
	
	searchData.phraseFromSteps = Utils::ConvertToSTDString(stepTextBox->Text);
	
	searchData.dishMark =
		std::make_pair(Utils::ConvertToSTDString(minMarkTextBox->Text), 
			Utils::ConvertToSTDString(maxMarkTextBox->Text));
	
	searchData.calories =
		std::make_pair(Utils::ConvertToSTDString(minCaloriesTextBox->Text),
			Utils::ConvertToSTDString(maxCaloriesTextBox->Text));

	searchData.preparingTime =
		std::make_pair(Utils::ConvertToSTDString(minPreparingTimeTextBox->Text),
			Utils::ConvertToSTDString(maxPreparingTimeTextBox->Text));

	searchData.cookingTime =
		std::make_pair(Utils::ConvertToSTDString(minCookingTimeTextBox->Text),
			Utils::ConvertToSTDString(maxCookingTimeTextBox->Text));

	searchData.allTime =
		std::make_pair(Utils::ConvertToSTDString(minAllTimeTextBox->Text),
			Utils::ConvertToSTDString(maxAllTimeTextBox->Text));


	searchData.operationType = true;
	if (selectUnionRadioButton->Checked) searchData.operationType = true;
	else if (selectIntersectionRadioButton->Checked) searchData.operationType = false;

	std::vector<Recipe> searchResult = SearchEngine::Start(searchData);

	resultRecipeListBox->Items->Clear();

	if (!searchResult.empty())
	{
		for (int i = 0; i < searchResult.size(); i++)
		{
			resultRecipeListBox->Items->Add(Utils::ConvertToSysString(searchResult[i].dishName));
		}
	}

	return System::Void();
}

//ListBox selection changed
System::Void RECIPEBOOK::GRAPHICS::resultRecipeListBox_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e)
{
	stepEditTextBox->Visible = false;
	auto defaultPicture = Utils::ConvertToSysString((fs::current_path() / "default.jpg").string());
	//get selected recipe
	String^ name = resultRecipeListBox->GetItemText(resultRecipeListBox->SelectedItem);
	Recipe currentRecipe = SearchEngine::FindCurrentRecipe(Utils::ConvertToSTDString(name));

	//output recipe data init
	currentRecipeLabel->Text = Utils::ConvertToSysString(currentRecipe.dishName);
	currentRecipeCommentTextLabel->Text = Utils::ConvertToSysString(currentRecipe.comment);
	currentRecipeMarkLabel->Text = Utils::ConvertToSysString("Личная оценка: " + std::to_string(currentRecipe.mark) + "/10");
	currentRecipeCategoryLabel->Text = Utils::ConvertToSysString(Recipe::MakeCategoryOutput(currentRecipe.dishTypes));
	currentRecipeCaloriesLabel->Text = Utils::ConvertToSysString("Калорийность: " + std::to_string(currentRecipe.dishCalories));
	currentRecipePreparingTimeLabel->Text = Utils::ConvertToSysString("Время подготовки: " + std::to_string(currentRecipe.preparingTime));
	currentRecipeCookingTimeLabel->Text = Utils::ConvertToSysString("Время приготовления: " + std::to_string(currentRecipe.cookingTime));
	currentRecipeAllTimeLabel->Text = Utils::ConvertToSysString("Общее время: " + std::to_string(currentRecipe.allTime));
	currentRecipeIngridientsLabel->Text = Utils::ConvertToSysString(Recipe::MakeIngridientsOutput(currentRecipe.ingridients));

	//main image load
	if (currentRecipe.picturePath != "none")
	{
		currentRecipePictureBox->Image = currentRecipePictureBox->Image->FromFile(Utils::ConvertToSysString(currentRecipe.picturePath.string()));
	}
	else
	{
		currentRecipePictureBox->Image = currentRecipePictureBox->Image->FromFile(defaultPicture);
	}

	//first step init
	currentStepLabel->Text = "Шаг 1";
	currentStepButton->Text = "Шаг 1/" + Utils::ConvertToSysString(std::to_string(currentRecipe.stepByStepManual.size())) + " (редактировать шаг)";
	currentStepTextLabel->Text = Utils::ConvertToSysString(currentRecipe.stepByStepManual[0].stepText);

	//first step image load
	if (currentRecipe.stepByStepManual[0].picturePath != "none")
	{
		currentStepPictureBox->Image = currentStepPictureBox->Image->FromFile(Utils::ConvertToSysString(currentRecipe.stepByStepManual[0].picturePath.string()));
	}
	else
	{
		currentRecipePictureBox->Image = currentRecipePictureBox->Image->FromFile(defaultPicture);
	}

	currentRecipe.ParseIngridients(Utils::ConvertToSTDString(currentRecipeIngridientsLabel->Text));
	currentRecipe.ParseCaloriesAndTime(Utils::ConvertToSTDString(currentRecipeAllTimeLabel->Text));
	
	return System::Void();
}

//Step changed
System::Void RECIPEBOOK::GRAPHICS::nextStepButton_Click(System::Object^ sender, System::EventArgs^ e)
{
	auto defaultPicture = Utils::ConvertToSysString((fs::current_path() / "default.jpg").string());
	String^ name = resultRecipeListBox->GetItemText(resultRecipeListBox->SelectedItem);
	Recipe currentRecipe = SearchEngine::FindCurrentRecipe(Utils::ConvertToSTDString(name));
	int currentStep = Utils::GetCurrentStep(Utils::ConvertToSTDString(currentStepLabel->Text));
	if (currentStep < currentRecipe.stepByStepManual.size())
	{
		stepEditTextBox->Visible = false;
		currentStep++;

		//next step init
		currentStepLabel->Text = "Шаг " + Utils::ConvertToSysString(std::to_string(currentStep));
		currentStepButton->Text = currentStepLabel->Text + "/" + Utils::ConvertToSysString(std::to_string(currentRecipe.stepByStepManual.size())) + " (редактировать шаг)";
		currentStepTextLabel->Text = Utils::ConvertToSysString(currentRecipe.stepByStepManual[currentStep - 1].stepText);

		//next step image load
		if (currentRecipe.stepByStepManual[currentStep - 1].picturePath != "none")
		{
			currentStepPictureBox->Image = currentStepPictureBox->Image->FromFile(Utils::ConvertToSysString(currentRecipe.stepByStepManual[currentStep - 1].picturePath.string()));
		}
		else
		{
			currentStepPictureBox->Image = currentStepPictureBox->Image->FromFile(defaultPicture);
		}
	}

	return System::Void();
}

System::Void RECIPEBOOK::GRAPHICS::previousStepButton_Click(System::Object^ sender, System::EventArgs^ e)
{
	auto defaultPicture = Utils::ConvertToSysString((fs::current_path() / "default.jpg").string());
	String^ name = resultRecipeListBox->GetItemText(resultRecipeListBox->SelectedItem);
	Recipe currentRecipe = SearchEngine::FindCurrentRecipe(Utils::ConvertToSTDString(name));
	int currentStep = Utils::GetCurrentStep(Utils::ConvertToSTDString(currentStepLabel->Text));
	if (currentStep > 1)
	{
		stepEditTextBox->Visible = false;
		currentStep--;

		//previous step init
		currentStepLabel->Text = "Шаг " + Utils::ConvertToSysString(std::to_string(currentStep));
		currentStepButton->Text = currentStepLabel->Text + "/" + Utils::ConvertToSysString(std::to_string(currentRecipe.stepByStepManual.size())) + " (редактировать шаг)";
		currentStepTextLabel->Text = Utils::ConvertToSysString(currentRecipe.stepByStepManual[currentStep - 1].stepText);

		//next step image load
		if (currentRecipe.stepByStepManual[currentStep - 1].picturePath != "none")
		{
			currentStepPictureBox->Image = currentStepPictureBox->Image->FromFile(Utils::ConvertToSysString(currentRecipe.stepByStepManual[currentStep - 1].picturePath.string()));
		}
		else
		{
			currentStepPictureBox->Image = currentStepPictureBox->Image->FromFile(defaultPicture);
		}
	}

	return System::Void();
}

//Step edit
System::Void RECIPEBOOK::GRAPHICS::currentStepButton_Click(System::Object^ sender, System::EventArgs^ e)
{
	auto defaultPicture = Utils::ConvertToSysString((fs::current_path() / "default.jpg").string());
	String^ name = resultRecipeListBox->GetItemText(resultRecipeListBox->SelectedItem);
	Recipe currentRecipe = SearchEngine::FindCurrentRecipe(Utils::ConvertToSTDString(name));
	int currentStep = Utils::GetCurrentStep(Utils::ConvertToSTDString(currentStepLabel->Text));
	stepEditTextBox->Text = Utils::ConvertToSysString(currentRecipe.stepByStepManual[currentStep - 1].stepText);
	stepEditTextBox->Visible = true;
	return System::Void();
}

System::Void RECIPEBOOK::GRAPHICS::stepEditTextBox_TextChanged(System::Object^ sender, System::EventArgs^ e)
{
	auto defaultPicture = Utils::ConvertToSysString((fs::current_path() / "default.jpg").string());
	String^ name = resultRecipeListBox->GetItemText(resultRecipeListBox->SelectedItem);
	Recipe currentRecipe = SearchEngine::FindCurrentRecipe(Utils::ConvertToSTDString(name));
	int currentStep = Utils::GetCurrentStep(Utils::ConvertToSTDString(currentStepLabel->Text));
	currentRecipe.UpdateStepText(currentStep, Utils::ConvertToSTDString(stepEditTextBox->Text));
	return System::Void();
}

//Add new recipe 
System::Void RECIPEBOOK::GRAPHICS::addNewRecipeButton_Click(System::Object^ sender, System::EventArgs^ e)
{
	NEWRECIPE^ newRecipeForm = gcnew NEWRECIPE;
	newRecipeForm->Show();
	return System::Void();
}

System::Void RECIPEBOOK::GRAPHICS::deleteCurrentRecipeButton_Click(System::Object^ sender, System::EventArgs^ e)
{
	/*
	auto defaultPicture = Utils::ConvertToSysString((fs::current_path() / "default.jpg").string());
	String^ name = resultRecipeListBox->GetItemText(resultRecipeListBox->SelectedItem);
	Recipe currentRecipe = SearchEngine::FindCurrentRecipe(Utils::ConvertToSTDString(name));
	currentRecipe.DeleteRecipe();

	currentRecipeLabel->ResetText();
	*/
	return System::Void();
}
