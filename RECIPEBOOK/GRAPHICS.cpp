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
	Recipe recipe;
	recipe.SetDishName("ASDASD");
	recipe.CreateRecipeFolder(recipe.GetDishName());
	recipe.DeleteRecipeFolder(recipe.GetDishName());
	recipe.CreateRecipeFolder("TTT");
	recipe.DeleteRecipeFolder("TTT");

	return System::Void();
}

System::Void RECIPEBOOK::GRAPHICS::startSearchButton_Click(System::Object^ sender, System::EventArgs^ e)
{
	/*
	String^ ass = searchLabel->Text;
	std::string ss = msclr::interop::marshal_as<std::string>(ass);
	*/

	SearchData searchData;

	searchData.name = Utils::ConvertToSTDString(nameSearchTextBox->Text);
	
	searchData.categories = Utils::ConvertToArray(categoriesSearchTextBox->Text);
	
	searchData.ingridients = Utils::ConvertToArray(ingridientsSearchTextBox->Text);
	
	searchData.phraseFromComment = Utils::ConvertToArray(commentTextBox->Text);
	
	searchData.phraseFromSteps = Utils::ConvertToArray(stepTextBox->Text);
	
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


	searchData.operationType = false;
	if (selectUnionRadioButton->Checked) searchData.operationType = true;
	else if (selectIntersectionRadioButton->Checked) searchData.operationType = false;

	SearchEngine::Start(searchData);

	return System::Void();
}
