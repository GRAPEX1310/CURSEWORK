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

	searchData.id = 0;

	std::vector<Recipe> searchResult = SearchEngine::Start(searchData);

	resultRecipeListBox->Items->Clear();

	if (!searchResult.empty())
	{
		for (int i = 0; i < searchResult.size(); i++)
		{
			resultRecipeListBox->Items->Add(Utils::ConvertToSysString("(" + std::to_string(searchResult[i].id) + ") " + searchResult[i].dishName));
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
	Recipe currentRecipe = SearchEngine::FindCurrentRecipe(Utils::GetCurrentRecipeId(Utils::ConvertToSTDString(name)));

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

	
	return System::Void();
}

//Step changed
System::Void RECIPEBOOK::GRAPHICS::nextStepButton_Click(System::Object^ sender, System::EventArgs^ e)
{
	auto defaultPicture = Utils::ConvertToSysString((fs::current_path() / "default.jpg").string());
	String^ name = resultRecipeListBox->GetItemText(resultRecipeListBox->SelectedItem);
	Recipe currentRecipe = SearchEngine::FindCurrentRecipe(Utils::GetCurrentRecipeId(Utils::ConvertToSTDString(name)));
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
	Recipe currentRecipe = SearchEngine::FindCurrentRecipe(Utils::GetCurrentRecipeId(Utils::ConvertToSTDString(name)));
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
	Recipe currentRecipe = SearchEngine::FindCurrentRecipe(Utils::GetCurrentRecipeId(Utils::ConvertToSTDString(name)));
	int currentStep = Utils::GetCurrentStep(Utils::ConvertToSTDString(currentStepLabel->Text));
	stepEditTextBox->Text = Utils::ConvertToSysString(currentRecipe.stepByStepManual[currentStep - 1].stepText);
	stepEditTextBox->Visible = true;
	return System::Void();
}

System::Void RECIPEBOOK::GRAPHICS::stepEditTextBox_TextChanged(System::Object^ sender, System::EventArgs^ e)
{
	auto defaultPicture = Utils::ConvertToSysString((fs::current_path() / "default.jpg").string());
	String^ name = resultRecipeListBox->GetItemText(resultRecipeListBox->SelectedItem);
	Recipe currentRecipe = SearchEngine::FindCurrentRecipe(Utils::GetCurrentRecipeId(Utils::ConvertToSTDString(name)));
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

//Delete current recipe
System::Void RECIPEBOOK::GRAPHICS::deleteCurrentRecipeButton_Click(System::Object^ sender, System::EventArgs^ e)
{
	/*
	auto defaultPicture = Utils::ConvertToSysString((fs::current_path() / "default.jpg").string());
	String^ name = resultRecipeListBox->GetItemText(resultRecipeListBox->SelectedItem);
	Recipe currentRecipe = SearchEngine::FindCurrentRecipe(Utils::GetCurrentRecipeId(Utils::ConvertToSTDString(name)));
	currentRecipe.DeleteRecipe();

	currentRecipeLabel->ResetText();
	*/
	return System::Void();
}

//Update name
System::Void RECIPEBOOK::GRAPHICS::currentRecipeLabel_DoubleClick(System::Object^ sender, System::EventArgs^ e)
{
	nameEditTextBox->Text = currentRecipeLabel->Text;
	currentRecipeLabel->Visible = false;
	nameEditTextBox->Visible = true;
	return System::Void();
}

System::Void RECIPEBOOK::GRAPHICS::nameEditTextBox_DoubleClick(System::Object^ sender, System::EventArgs^ e)
{
	auto defaultPicture = Utils::ConvertToSysString((fs::current_path() / "default.jpg").string());
	String^ name = resultRecipeListBox->GetItemText(resultRecipeListBox->SelectedItem);
	Recipe currentRecipe = SearchEngine::FindCurrentRecipe(Utils::GetCurrentRecipeId(Utils::ConvertToSTDString(name)));

	nameEditTextBox->Visible = false;
	currentRecipeLabel->Text = nameEditTextBox->Text;
	currentRecipeLabel->Visible = true;

	currentRecipe.UpdateRecipeData(0, Utils::ConvertToSTDString(currentRecipeLabel->Text));

	resultRecipeListBox->Items->Clear();
	return System::Void();
}

//Update Category
System::Void RECIPEBOOK::GRAPHICS::currentRecipeCategoryLabel_DoubleClick(System::Object^ sender, System::EventArgs^ e)
{
	categoryEditTextBox->Text = currentRecipeCategoryLabel->Text;
	currentRecipeCategoryLabel->Visible = false;
	categoryEditTextBox->Visible = true;
	return System::Void();
}

System::Void RECIPEBOOK::GRAPHICS::categoryEditTextBox_DoubleClick(System::Object^ sender, System::EventArgs^ e)
{
	auto defaultPicture = Utils::ConvertToSysString((fs::current_path() / "default.jpg").string());
	String^ name = resultRecipeListBox->GetItemText(resultRecipeListBox->SelectedItem);
	Recipe currentRecipe = SearchEngine::FindCurrentRecipe(Utils::GetCurrentRecipeId(Utils::ConvertToSTDString(name)));

	categoryEditTextBox->Visible = false;
	currentRecipeCategoryLabel->Text = categoryEditTextBox->Text;
	currentRecipeCategoryLabel->Visible = true;
	
	currentRecipe.UpdateRecipeData(1, Utils::ConvertToSTDString(currentRecipeCategoryLabel->Text));

	return System::Void();
}

//Update Mark
System::Void RECIPEBOOK::GRAPHICS::currentRecipeMarkLabel_DoubleClick(System::Object^ sender, System::EventArgs^ e)
{
	markEditTextBox->Text = currentRecipeMarkLabel->Text;
	currentRecipeMarkLabel->Visible = false;
	markEditTextBox->Visible = true;
	return System::Void();
}

System::Void RECIPEBOOK::GRAPHICS::markEditTextBox_DoubleClick(System::Object^ sender, System::EventArgs^ e)
{
	auto defaultPicture = Utils::ConvertToSysString((fs::current_path() / "default.jpg").string());
	String^ name = resultRecipeListBox->GetItemText(resultRecipeListBox->SelectedItem);
	Recipe currentRecipe = SearchEngine::FindCurrentRecipe(Utils::GetCurrentRecipeId(Utils::ConvertToSTDString(name)));

	markEditTextBox->Visible = false;
	currentRecipeMarkLabel->Text = markEditTextBox->Text;
	currentRecipeMarkLabel->Visible = true;

	currentRecipe.UpdateRecipeData(2, Utils::ConvertToSTDString(currentRecipeMarkLabel->Text));

	return System::Void();
}

//Update Calories
System::Void RECIPEBOOK::GRAPHICS::currentRecipeCaloriesLabel_DoubleClick(System::Object^ sender, System::EventArgs^ e)
{
	caloriesEditTextBox->Text = currentRecipeCaloriesLabel->Text;
	currentRecipeCaloriesLabel->Visible = false;
	caloriesEditTextBox->Visible = true;
	return System::Void();
}

System::Void RECIPEBOOK::GRAPHICS::caloriesEditTextBox_DoubleClick(System::Object^ sender, System::EventArgs^ e)
{
	auto defaultPicture = Utils::ConvertToSysString((fs::current_path() / "default.jpg").string());
	String^ name = resultRecipeListBox->GetItemText(resultRecipeListBox->SelectedItem);
	Recipe currentRecipe = SearchEngine::FindCurrentRecipe(Utils::GetCurrentRecipeId(Utils::ConvertToSTDString(name)));

	caloriesEditTextBox->Visible = false;
	currentRecipeCaloriesLabel->Text = caloriesEditTextBox->Text;
	currentRecipeCaloriesLabel->Visible = true;

	currentRecipe.UpdateRecipeData(3, Utils::ConvertToSTDString(currentRecipeCaloriesLabel->Text));
	return System::Void();
}

//Update preparing time
System::Void RECIPEBOOK::GRAPHICS::currentRecipePreparingTimeLabel_DoubleClick(System::Object^ sender, System::EventArgs^ e)
{
	preparingTimeEditTextBox->Text = currentRecipePreparingTimeLabel->Text;
	currentRecipePreparingTimeLabel->Visible = false;
	preparingTimeEditTextBox->Visible = true;
	return System::Void();
}

System::Void RECIPEBOOK::GRAPHICS::preparingTimeEditTextBox_DoubleClick(System::Object^ sender, System::EventArgs^ e)
{
	auto defaultPicture = Utils::ConvertToSysString((fs::current_path() / "default.jpg").string());
	String^ name = resultRecipeListBox->GetItemText(resultRecipeListBox->SelectedItem);
	Recipe currentRecipe = SearchEngine::FindCurrentRecipe(Utils::GetCurrentRecipeId(Utils::ConvertToSTDString(name)));

	preparingTimeEditTextBox->Visible = false;
	currentRecipePreparingTimeLabel->Text = preparingTimeEditTextBox->Text;
	currentRecipePreparingTimeLabel->Visible = true;

	currentRecipe.UpdateRecipeData(4, Utils::ConvertToSTDString(currentRecipePreparingTimeLabel->Text));
	return System::Void();
}

//Update cooking time
System::Void RECIPEBOOK::GRAPHICS::currentRecipeCookingTimeLabel_DoubleClick(System::Object^ sender, System::EventArgs^ e)
{
	cookingTimeEditTextBox->Text = currentRecipeCookingTimeLabel->Text;
	currentRecipeCookingTimeLabel->Visible = false;
	cookingTimeEditTextBox->Visible = true;
	return System::Void();
}

System::Void RECIPEBOOK::GRAPHICS::cookingTimeEditTextBox_DoubleClick(System::Object^ sender, System::EventArgs^ e)
{
	auto defaultPicture = Utils::ConvertToSysString((fs::current_path() / "default.jpg").string());
	String^ name = resultRecipeListBox->GetItemText(resultRecipeListBox->SelectedItem);
	Recipe currentRecipe = SearchEngine::FindCurrentRecipe(Utils::GetCurrentRecipeId(Utils::ConvertToSTDString(name)));

	cookingTimeEditTextBox->Visible = false;
	currentRecipeCookingTimeLabel->Text = cookingTimeEditTextBox->Text;
	currentRecipeCookingTimeLabel->Visible = true;

	currentRecipe.UpdateRecipeData(5, Utils::ConvertToSTDString(currentRecipeCookingTimeLabel->Text));
	return System::Void();
}

//Update all time
System::Void RECIPEBOOK::GRAPHICS::currentRecipeAllTimeLabel_DoubleClick(System::Object^ sender, System::EventArgs^ e)
{
	allTimeEditTextBox->Text = currentRecipeAllTimeLabel->Text;
	currentRecipeAllTimeLabel->Visible = false;
	allTimeEditTextBox->Visible = true;
	return System::Void();
}

System::Void RECIPEBOOK::GRAPHICS::allTimeEditTextBox_DoubleClick(System::Object^ sender, System::EventArgs^ e)
{
	auto defaultPicture = Utils::ConvertToSysString((fs::current_path() / "default.jpg").string());
	String^ name = resultRecipeListBox->GetItemText(resultRecipeListBox->SelectedItem);
	Recipe currentRecipe = SearchEngine::FindCurrentRecipe(Utils::GetCurrentRecipeId(Utils::ConvertToSTDString(name)));

	allTimeEditTextBox->Visible = false;
	currentRecipeAllTimeLabel->Text = allTimeEditTextBox->Text;
	currentRecipeAllTimeLabel->Visible = true;

	currentRecipe.UpdateRecipeData(6, Utils::ConvertToSTDString(currentRecipeAllTimeLabel->Text));
	return System::Void();
}

//Update ingridients
System::Void RECIPEBOOK::GRAPHICS::currentRecipeIngridientsLabel_DoubleClick(System::Object^ sender, System::EventArgs^ e)
{
	ingridientsEditTextBox->Text = currentRecipeIngridientsLabel->Text;
	currentRecipeIngridientsLabel->Visible = false;
	ingridientsEditTextBox->Visible = true;
	return System::Void();
}

System::Void RECIPEBOOK::GRAPHICS::ingridientsEditTextBox_DoubleClick(System::Object^ sender, System::EventArgs^ e)
{
	auto defaultPicture = Utils::ConvertToSysString((fs::current_path() / "default.jpg").string());
	String^ name = resultRecipeListBox->GetItemText(resultRecipeListBox->SelectedItem);
	Recipe currentRecipe = SearchEngine::FindCurrentRecipe(Utils::GetCurrentRecipeId(Utils::ConvertToSTDString(name)));

	ingridientsEditTextBox->Visible = false;
	currentRecipeIngridientsLabel->Text = ingridientsEditTextBox->Text;
	currentRecipeIngridientsLabel->Visible = true;

	currentRecipe.UpdateRecipeData(7, Utils::ConvertToSTDString(currentRecipeIngridientsLabel->Text));
	return System::Void();
}
