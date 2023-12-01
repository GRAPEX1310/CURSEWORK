#include "NEWRECIPE.h"
#include "RecipeCreator.h"
#include "Recipe.h"
#include "Utils.h"

System::Void RECIPEBOOK::NEWRECIPE::finalButton_Click(System::Object^ sender, System::EventArgs^ e)
{
    Recipe recipe;

    if (!Utils::ConvertToSTDString(nameSearchTextBox->Text).empty())
        recipe.dishName = Utils::ConvertToSTDString(nameSearchTextBox->Text);
    else
    {
        correctStatusLabel->Text = "некорректные данные";
        return System::Void();
    }

    if (!Utils::ConvertToSTDString(categoriesSearchTextBox->Text).empty())
        recipe.dishTypes = Recipe::ConvertToDishTypes(Recipe::ParseCategories(Utils::ConvertToSTDString(categoriesSearchTextBox->Text)));
    else
    {
        correctStatusLabel->Text = "некорректные данные";
        return System::Void();
    }
    
    if (!Utils::ConvertToSTDString(ingridientsSearchTextBox->Text).empty())
        recipe.ingridients = Recipe::ConvertToIngridients(Recipe::ParseIngridients(Utils::ConvertToSTDString(ingridientsSearchTextBox->Text)));
    else
    {
        correctStatusLabel->Text = "некорректные данные";
        return System::Void();
    }

    if (!Utils::ConvertToSTDString(markTextBox->Text).empty())
        recipe.mark = std::stoi(Utils::ConvertToSTDString(markTextBox->Text));
    else
    {
        correctStatusLabel->Text = "некорректные данные";
        return System::Void();
    }

    if (!Utils::ConvertToSTDString(сaloriesTextBox->Text).empty())
        recipe.dishCalories = std::stoi(Utils::ConvertToSTDString(сaloriesTextBox->Text));
    else
    {
        correctStatusLabel->Text = "некорректные данные";
        return System::Void();
    }

    if (!Utils::ConvertToSTDString(preparingTimeTextBox->Text).empty())
        recipe.preparingTime = std::stoi(Utils::ConvertToSTDString(preparingTimeTextBox->Text));
    else
    {
        correctStatusLabel->Text = "некорректные данные";
        return System::Void();
    }
    
    if (!Utils::ConvertToSTDString(cookingTimeTextBox->Text).empty())
        recipe.cookingTime = std::stoi(Utils::ConvertToSTDString(cookingTimeTextBox->Text));
    else
    {
        correctStatusLabel->Text = "некорректные данные";
        return System::Void();
    }
    
    if (!Utils::ConvertToSTDString(allTimeTextBox->Text).empty())
        recipe.allTime = std::stoi(Utils::ConvertToSTDString(allTimeTextBox->Text));
    else
    {
        correctStatusLabel->Text = "некорректные данные";
        return System::Void();
    }
    
    if (!Utils::ConvertToSTDString(commentTextBox->Text).empty())
        recipe.comment = Utils::ConvertToSTDString(commentTextBox->Text);
    else
    {
        correctStatusLabel->Text = "некорректные данные";
        return System::Void();
    }

    correctStatusLabel->Text = "сохранено";

    return System::Void();
}

System::Void RECIPEBOOK::NEWRECIPE::previousStepButton_Click(System::Object^ sender, System::EventArgs^ e)
{
    int currentStep = Utils::GetCurrentStep(Utils::ConvertToSTDString(currentStepLabel->Text));

    if (currentStep > 1)
    {

    }

    return System::Void();
}

System::Void RECIPEBOOK::NEWRECIPE::nextStepButton_Click(System::Object^ sender, System::EventArgs^ e)
{
    return System::Void();
}
