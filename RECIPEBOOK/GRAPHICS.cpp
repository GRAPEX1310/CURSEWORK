#include "GRAPHICS.h"
#include "Recipe.h"

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
