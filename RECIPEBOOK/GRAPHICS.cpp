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

System::Void RECIPEBOOK::GRAPHICS::GRAPHICS_Load(System::Object^ sender, System::EventArgs^ e)
{
	/*
	Recipe recipe;
	recipe.SetDishName("ASDASD");
	recipe.CreateRecipeFolder(recipe.GetDishName());
	recipe.DeleteRecipeFolder(recipe.GetDishName());
	//recipe.CreateRecipeFolder("TTT");

	bool aa = recipe.CreateRecipeFolder("AAA");
	String^ ss;
	if (aa)
	{
		ss = "ok";
	}
	else
	{
		ss = "!";
	}
	searchLabel->Text = ss;

	bool bb = recipe.CreateRecipeFolder("BBB");
	
	if (bb)
	{
		ss = "ok";
	}
	else
	{
		ss = "!";
	}
	markLabel->Text = ss;
	bool cc = recipe.DeleteRecipeFolder("TTT");

	if (cc)
	{
		ss = "ok";
	}
	else
	{
		ss = "!";
	}
	preparingTimeLabel->Text = ss;
	*/
	return System::Void();
}

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

System::Void RECIPEBOOK::GRAPHICS::resultRecipeListBox_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e)
{
	//get selected recipe
	String^ name = resultRecipeListBox->GetItemText(resultRecipeListBox->SelectedItem);
	Recipe currentRecipe = SearchEngine::FindCurrentRecipe(Utils::ConvertToSTDString(name));

	//output recipe data
	currentRecipeLabel->Text = Utils::ConvertToSysString(currentRecipe.dishName);
	currentRecipeCommentTextLabel->Text = Utils::ConvertToSysString(currentRecipe.comment);
	currentRecipeMarkLabel->Text = Utils::ConvertToSysString("Личная оценка: " + std::to_string(currentRecipe.dishCalories) + "/10");
	currentRecipeCategoryLabel->Text = Utils::ConvertToSysString(Recipe::MakeCategoryOutput(currentRecipe.dishTypes));
	currentRecipeCaloriesLabel->Text = Utils::ConvertToSysString("Калорийность: " + std::to_string(currentRecipe.dishCalories));
	currentRecipePreparingTimeLabel->Text = Utils::ConvertToSysString("Время подготовки: " + std::to_string(currentRecipe.preparingTime));
	currentRecipeCookingTimeLabel->Text = Utils::ConvertToSysString("Время приготовления: " + std::to_string(currentRecipe.cookingTime));
	currentRecipeAllTimeLabel->Text = Utils::ConvertToSysString("Общее время: " + std::to_string(currentRecipe.allTime));
	currentRecipeIngridientsLabel->Text = Utils::ConvertToSysString(Recipe::MakeIngridientsOutput(currentRecipe.ingridients));

	//main image work
	currentRecipePictureBox->Image = currentRecipePictureBox->Image->FromFile(Utils::ConvertToSysString(currentRecipe.picturePath.string()));


	return System::Void();
}

