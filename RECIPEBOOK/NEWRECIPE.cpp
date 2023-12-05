#include "NEWRECIPE.h"
#include "RecipeCreator.h"
#include "Recipe.h"
#include "Utils.h"

System::Void RECIPEBOOK::NEWRECIPE::NEWRECIPE_Load(System::Object^ sender, System::EventArgs^ e)
{
    stepsListBox->Items->Add(stepEditTextBox->Text);
    return System::Void();
}

System::Void RECIPEBOOK::NEWRECIPE::stepsListBox_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e)
{
    int currentStep = Utils::GetCurrentStep(Utils::ConvertToSTDString(currentStepLabel->Text));
    stepsListBox->Items[currentStep - 1] = stepEditTextBox->Text;

    int newStep = stepsListBox->SelectedIndex;

    currentStepLabel->Text = "Шаг " + Utils::ConvertToSysString(std::to_string(newStep + 1));
    stepEditTextBox->Text = stepsListBox->Items[newStep]->ToString();

    return System::Void();
}

System::Void RECIPEBOOK::NEWRECIPE::deleteStepButton_Click(System::Object^ sender, System::EventArgs^ e)
{
    int currentStep = Utils::GetCurrentStep(Utils::ConvertToSTDString(currentStepLabel->Text));

    if (stepsListBox->Items->Count > 1)
    {
        stepsListBox->Items->RemoveAt(currentStep - 1);

        currentStep = 1;

        currentStepLabel->Text = "Шаг " + Utils::ConvertToSysString(std::to_string(currentStep));
        stepEditTextBox->Text = stepsListBox->Items[currentStep - 1]->ToString();

    }

    return System::Void();
}

System::Void RECIPEBOOK::NEWRECIPE::stepEditTextBox_TextChanged(System::Object^ sender, System::EventArgs^ e)
{
    int currentStep = Utils::GetCurrentStep(Utils::ConvertToSTDString(currentStepLabel->Text));
    stepsListBox->Items[currentStep - 1] = stepEditTextBox->Text;

    return System::Void();
}

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
        recipe.dishTypes = Recipe::ConvertToDishTypes(Recipe::ParseCategories(Utils::ConvertToSTDString(categoriesSearchTextBox->Text), 1));
    else
    {
        correctStatusLabel->Text = "некорректные данные";
        return System::Void();
    }
    
    if (!Utils::ConvertToSTDString(ingridientsSearchTextBox->Text).empty())
        recipe.ingridients = Recipe::ConvertToIngridients(Recipe::ParseIngridients(Utils::ConvertToSTDString(ingridientsSearchTextBox->Text), 1));
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

    recipe.SetNewId();

    std::vector<std::string> stepsText;

    for (int i = 0; i < stepsListBox->Items->Count; i++)
    {
        stepsText.push_back(Utils::ConvertToSTDString(stepsListBox->Items[i]->ToString()));
    }

    recipe.ParseInstructionText(stepsText);
    correctStatusLabel->Text = "сохранено";
    recipe.CreateRecipe();
    return System::Void();
}

System::Void RECIPEBOOK::NEWRECIPE::previousStepButton_Click(System::Object^ sender, System::EventArgs^ e)
{
    int currentStep = Utils::GetCurrentStep(Utils::ConvertToSTDString(currentStepLabel->Text));

    if (currentStep - 1 >= 1)
    {
        stepsListBox->Items[currentStep - 1] = stepEditTextBox->Text;
        
        currentStep--;

        currentStepLabel->Text = "Шаг " + Utils::ConvertToSysString(std::to_string(currentStep));
        stepEditTextBox->Text = stepsListBox->Items[currentStep - 1]->ToString();
    }

    return System::Void();
}

System::Void RECIPEBOOK::NEWRECIPE::nextStepButton_Click(System::Object^ sender, System::EventArgs^ e)
{
    int currentStep = Utils::GetCurrentStep(Utils::ConvertToSTDString(currentStepLabel->Text));

    if (currentStep < stepsListBox->Items->Count)
    {
        stepsListBox->Items[currentStep - 1] = stepEditTextBox->Text;

        currentStep++;

        currentStepLabel->Text = "Шаг " + Utils::ConvertToSysString(std::to_string(currentStep));
        stepEditTextBox->Text = stepsListBox->Items[currentStep - 1]->ToString();
    }
    else
    {
        stepsListBox->Items[currentStep - 1] = stepEditTextBox->Text;
        stepEditTextBox->Text = "Введите текст текущего шага";
        stepsListBox->Items->Add(stepEditTextBox->Text);

        currentStep++;

        currentStepLabel->Text = "Шаг " + Utils::ConvertToSysString(std::to_string(currentStep));
    }

    return System::Void();
}
