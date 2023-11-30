#pragma once
#include "Recipe.h"
#include "NEWRECIPE.h"

namespace RECIPEBOOK {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for GRAPHICS
	/// </summary>
	public ref class GRAPHICS : public System::Windows::Forms::Form
	{
	public:
		GRAPHICS(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~GRAPHICS()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ searchLabel;
	private: System::Windows::Forms::TextBox^ nameSearchTextBox;
	protected:

	private: System::Windows::Forms::Label^ caloriesLabel;
	private: System::Windows::Forms::TextBox^ minCaloriesTextBox;
	private: System::Windows::Forms::TextBox^ maxCaloriesTextBox;
	private: System::Windows::Forms::Label^ dashLabel1;

	private: System::Windows::Forms::Label^ dishNameSearchLabel;
	private: System::Windows::Forms::Label^ commentSearchLabel;
	private: System::Windows::Forms::TextBox^ categoriesSearchTextBox;

	private: System::Windows::Forms::Label^ stepPhraseSearchLabel;
	private: System::Windows::Forms::TextBox^ commentTextBox;

	private: System::Windows::Forms::TextBox^ maxMarkTextBox;
	private: System::Windows::Forms::TextBox^ minCookingTimeTextBox;
	private: System::Windows::Forms::TextBox^ minAllTimeTextBox;



	private: System::Windows::Forms::TextBox^ minMarkTextBox;
	private: System::Windows::Forms::TextBox^ maxCookingTimeTextBox;
	private: System::Windows::Forms::TextBox^ maxAllTimeTextBox;



	private: System::Windows::Forms::TextBox^ maxPreparingTimeTextBox;

	private: System::Windows::Forms::TextBox^ minPreparingTimeTextBox;
	private: System::Windows::Forms::Label^ categoriesLabel;


	private: System::Windows::Forms::Label^ cookingTimeLabel;

	private: System::Windows::Forms::Label^ preparingTimeLabel;
	private: System::Windows::Forms::Label^ markLabel;


	private: System::Windows::Forms::Label^ allTimeLabel;
	private: System::Windows::Forms::TextBox^ stepTextBox;



	private: System::Windows::Forms::Label^ dashLabel2;
	private: System::Windows::Forms::Label^ dashLabel3;
	private: System::Windows::Forms::Label^ dashLabel4;
	private: System::Windows::Forms::Label^ dashLabel5;
	private: System::Windows::Forms::Label^ ingridientLabel;
	private: System::Windows::Forms::TextBox^ ingridientsSearchTextBox;

	private: System::Windows::Forms::Label^ resultLabel;
	private: System::Windows::Forms::RadioButton^ selectUnionRadioButton;
	private: System::Windows::Forms::RadioButton^ selectIntersectionRadioButton;
	private: System::Windows::Forms::Label^ selectModeLabel;
	private: System::Windows::Forms::ListBox^ resultRecipeListBox;

	private: System::Windows::Forms::Label^ currentRecipeLabel;
	private: System::Windows::Forms::PictureBox^ currentRecipePictureBox;
	private: System::Windows::Forms::Label^ currentRecipeCommentLabel;


	private: System::Windows::Forms::Label^ currentRecipeCategoryLabel;
	private: System::Windows::Forms::Label^ currentRecipePreparingTimeLabel;


	private: System::Windows::Forms::Label^ currentRecipeIngridientsLabel;
	private: System::Windows::Forms::Label^ currentRecipeAllTimeLabel;


	private: System::Windows::Forms::Label^ currentRecipeCookingTimeLabel;
	private: System::Windows::Forms::Label^ currentRecipeCaloriesLabel;



	private: System::Windows::Forms::Label^ currentRecipeMarkLabel;
	private: System::Windows::Forms::Button^ startSearchButton;
	private: System::Windows::Forms::GroupBox^ radioButtonsGroupBox;
	private: System::Windows::Forms::Label^ currentRecipeCommentTextLabel;
	private: System::Windows::Forms::Label^ currentRecipeStepLabel;
	private: System::Windows::Forms::Label^ currentStepTextLabel;
	private: System::Windows::Forms::PictureBox^ currentStepPictureBox;
	private: System::Windows::Forms::Label^ currentStepLabel;
	private: System::Windows::Forms::Button^ previousStepButton;
	private: System::Windows::Forms::Button^ nextStepButton;
	private: System::Windows::Forms::Button^ currentStepButton;
private: System::Windows::Forms::RichTextBox^ stepEditTextBox;
private: System::Windows::Forms::Button^ addNewRecipeButton;
private: System::Windows::Forms::Button^ deleteCurrentRecipeButton;









	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(GRAPHICS::typeid));
			this->searchLabel = (gcnew System::Windows::Forms::Label());
			this->nameSearchTextBox = (gcnew System::Windows::Forms::TextBox());
			this->caloriesLabel = (gcnew System::Windows::Forms::Label());
			this->minCaloriesTextBox = (gcnew System::Windows::Forms::TextBox());
			this->maxCaloriesTextBox = (gcnew System::Windows::Forms::TextBox());
			this->dashLabel1 = (gcnew System::Windows::Forms::Label());
			this->dishNameSearchLabel = (gcnew System::Windows::Forms::Label());
			this->commentSearchLabel = (gcnew System::Windows::Forms::Label());
			this->categoriesSearchTextBox = (gcnew System::Windows::Forms::TextBox());
			this->stepPhraseSearchLabel = (gcnew System::Windows::Forms::Label());
			this->commentTextBox = (gcnew System::Windows::Forms::TextBox());
			this->maxMarkTextBox = (gcnew System::Windows::Forms::TextBox());
			this->minCookingTimeTextBox = (gcnew System::Windows::Forms::TextBox());
			this->minAllTimeTextBox = (gcnew System::Windows::Forms::TextBox());
			this->minMarkTextBox = (gcnew System::Windows::Forms::TextBox());
			this->maxCookingTimeTextBox = (gcnew System::Windows::Forms::TextBox());
			this->maxAllTimeTextBox = (gcnew System::Windows::Forms::TextBox());
			this->maxPreparingTimeTextBox = (gcnew System::Windows::Forms::TextBox());
			this->minPreparingTimeTextBox = (gcnew System::Windows::Forms::TextBox());
			this->categoriesLabel = (gcnew System::Windows::Forms::Label());
			this->cookingTimeLabel = (gcnew System::Windows::Forms::Label());
			this->preparingTimeLabel = (gcnew System::Windows::Forms::Label());
			this->markLabel = (gcnew System::Windows::Forms::Label());
			this->allTimeLabel = (gcnew System::Windows::Forms::Label());
			this->stepTextBox = (gcnew System::Windows::Forms::TextBox());
			this->dashLabel2 = (gcnew System::Windows::Forms::Label());
			this->dashLabel3 = (gcnew System::Windows::Forms::Label());
			this->dashLabel4 = (gcnew System::Windows::Forms::Label());
			this->dashLabel5 = (gcnew System::Windows::Forms::Label());
			this->ingridientLabel = (gcnew System::Windows::Forms::Label());
			this->ingridientsSearchTextBox = (gcnew System::Windows::Forms::TextBox());
			this->resultLabel = (gcnew System::Windows::Forms::Label());
			this->selectUnionRadioButton = (gcnew System::Windows::Forms::RadioButton());
			this->selectIntersectionRadioButton = (gcnew System::Windows::Forms::RadioButton());
			this->selectModeLabel = (gcnew System::Windows::Forms::Label());
			this->resultRecipeListBox = (gcnew System::Windows::Forms::ListBox());
			this->currentRecipeLabel = (gcnew System::Windows::Forms::Label());
			this->currentRecipePictureBox = (gcnew System::Windows::Forms::PictureBox());
			this->currentRecipeCommentLabel = (gcnew System::Windows::Forms::Label());
			this->currentRecipeCategoryLabel = (gcnew System::Windows::Forms::Label());
			this->currentRecipePreparingTimeLabel = (gcnew System::Windows::Forms::Label());
			this->currentRecipeIngridientsLabel = (gcnew System::Windows::Forms::Label());
			this->currentRecipeAllTimeLabel = (gcnew System::Windows::Forms::Label());
			this->currentRecipeCookingTimeLabel = (gcnew System::Windows::Forms::Label());
			this->currentRecipeCaloriesLabel = (gcnew System::Windows::Forms::Label());
			this->currentRecipeMarkLabel = (gcnew System::Windows::Forms::Label());
			this->startSearchButton = (gcnew System::Windows::Forms::Button());
			this->radioButtonsGroupBox = (gcnew System::Windows::Forms::GroupBox());
			this->currentRecipeCommentTextLabel = (gcnew System::Windows::Forms::Label());
			this->currentRecipeStepLabel = (gcnew System::Windows::Forms::Label());
			this->currentStepTextLabel = (gcnew System::Windows::Forms::Label());
			this->currentStepPictureBox = (gcnew System::Windows::Forms::PictureBox());
			this->currentStepLabel = (gcnew System::Windows::Forms::Label());
			this->previousStepButton = (gcnew System::Windows::Forms::Button());
			this->nextStepButton = (gcnew System::Windows::Forms::Button());
			this->currentStepButton = (gcnew System::Windows::Forms::Button());
			this->stepEditTextBox = (gcnew System::Windows::Forms::RichTextBox());
			this->addNewRecipeButton = (gcnew System::Windows::Forms::Button());
			this->deleteCurrentRecipeButton = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->currentRecipePictureBox))->BeginInit();
			this->radioButtonsGroupBox->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->currentStepPictureBox))->BeginInit();
			this->SuspendLayout();
			// 
			// searchLabel
			// 
			this->searchLabel->AutoSize = true;
			this->searchLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->searchLabel->Location = System::Drawing::Point(66, 47);
			this->searchLabel->Name = L"searchLabel";
			this->searchLabel->Size = System::Drawing::Size(186, 25);
			this->searchLabel->TabIndex = 0;
			this->searchLabel->Text = L"Поиск рецептов";
			// 
			// nameSearchTextBox
			// 
			this->nameSearchTextBox->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->nameSearchTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.749998F, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->nameSearchTextBox->ForeColor = System::Drawing::SystemColors::MenuText;
			this->nameSearchTextBox->Location = System::Drawing::Point(59, 108);
			this->nameSearchTextBox->Name = L"nameSearchTextBox";
			this->nameSearchTextBox->Size = System::Drawing::Size(193, 22);
			this->nameSearchTextBox->TabIndex = 1;
			// 
			// caloriesLabel
			// 
			this->caloriesLabel->AutoSize = true;
			this->caloriesLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->caloriesLabel->Location = System::Drawing::Point(57, 344);
			this->caloriesLabel->Name = L"caloriesLabel";
			this->caloriesLabel->Size = System::Drawing::Size(205, 20);
			this->caloriesLabel->TabIndex = 2;
			this->caloriesLabel->Text = L"Калорийность (от - до)";
			// 
			// minCaloriesTextBox
			// 
			this->minCaloriesTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->minCaloriesTextBox->Location = System::Drawing::Point(59, 367);
			this->minCaloriesTextBox->Name = L"minCaloriesTextBox";
			this->minCaloriesTextBox->Size = System::Drawing::Size(55, 20);
			this->minCaloriesTextBox->TabIndex = 3;
			// 
			// maxCaloriesTextBox
			// 
			this->maxCaloriesTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->maxCaloriesTextBox->Location = System::Drawing::Point(200, 367);
			this->maxCaloriesTextBox->Name = L"maxCaloriesTextBox";
			this->maxCaloriesTextBox->Size = System::Drawing::Size(52, 20);
			this->maxCaloriesTextBox->TabIndex = 4;
			// 
			// dashLabel1
			// 
			this->dashLabel1->AutoSize = true;
			this->dashLabel1->Location = System::Drawing::Point(140, 605);
			this->dashLabel1->Name = L"dashLabel1";
			this->dashLabel1->Size = System::Drawing::Size(19, 13);
			this->dashLabel1->TabIndex = 5;
			this->dashLabel1->Text = L"----";
			// 
			// dishNameSearchLabel
			// 
			this->dishNameSearchLabel->AutoSize = true;
			this->dishNameSearchLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->dishNameSearchLabel->Location = System::Drawing::Point(80, 85);
			this->dishNameSearchLabel->Name = L"dishNameSearchLabel";
			this->dishNameSearchLabel->Size = System::Drawing::Size(152, 20);
			this->dishNameSearchLabel->TabIndex = 6;
			this->dishNameSearchLabel->Text = L"Название блюда";
			// 
			// commentSearchLabel
			// 
			this->commentSearchLabel->AutoSize = true;
			this->commentSearchLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->commentSearchLabel->Location = System::Drawing::Point(25, 664);
			this->commentSearchLabel->Name = L"commentSearchLabel";
			this->commentSearchLabel->Size = System::Drawing::Size(280, 20);
			this->commentSearchLabel->TabIndex = 7;
			this->commentSearchLabel->Text = L"Фраза из личного комментария";
			// 
			// categoriesSearchTextBox
			// 
			this->categoriesSearchTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->categoriesSearchTextBox->Location = System::Drawing::Point(59, 170);
			this->categoriesSearchTextBox->Name = L"categoriesSearchTextBox";
			this->categoriesSearchTextBox->Size = System::Drawing::Size(193, 20);
			this->categoriesSearchTextBox->TabIndex = 8;
			// 
			// stepPhraseSearchLabel
			// 
			this->stepPhraseSearchLabel->AutoSize = true;
			this->stepPhraseSearchLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->stepPhraseSearchLabel->Location = System::Drawing::Point(63, 746);
			this->stepPhraseSearchLabel->Name = L"stepPhraseSearchLabel";
			this->stepPhraseSearchLabel->Size = System::Drawing::Size(189, 20);
			this->stepPhraseSearchLabel->TabIndex = 9;
			this->stepPhraseSearchLabel->Text = L"Фраза из инструкции";
			// 
			// commentTextBox
			// 
			this->commentTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->commentTextBox->Location = System::Drawing::Point(59, 687);
			this->commentTextBox->Name = L"commentTextBox";
			this->commentTextBox->Size = System::Drawing::Size(193, 20);
			this->commentTextBox->TabIndex = 10;
			// 
			// maxMarkTextBox
			// 
			this->maxMarkTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->maxMarkTextBox->Location = System::Drawing::Point(200, 293);
			this->maxMarkTextBox->Name = L"maxMarkTextBox";
			this->maxMarkTextBox->Size = System::Drawing::Size(52, 20);
			this->maxMarkTextBox->TabIndex = 11;
			// 
			// minCookingTimeTextBox
			// 
			this->minCookingTimeTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->minCookingTimeTextBox->Location = System::Drawing::Point(59, 520);
			this->minCookingTimeTextBox->Name = L"minCookingTimeTextBox";
			this->minCookingTimeTextBox->Size = System::Drawing::Size(55, 20);
			this->minCookingTimeTextBox->TabIndex = 12;
			// 
			// minAllTimeTextBox
			// 
			this->minAllTimeTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->minAllTimeTextBox->Location = System::Drawing::Point(59, 602);
			this->minAllTimeTextBox->Name = L"minAllTimeTextBox";
			this->minAllTimeTextBox->Size = System::Drawing::Size(55, 20);
			this->minAllTimeTextBox->TabIndex = 13;
			// 
			// minMarkTextBox
			// 
			this->minMarkTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->minMarkTextBox->Location = System::Drawing::Point(59, 296);
			this->minMarkTextBox->Name = L"minMarkTextBox";
			this->minMarkTextBox->Size = System::Drawing::Size(55, 20);
			this->minMarkTextBox->TabIndex = 14;
			// 
			// maxCookingTimeTextBox
			// 
			this->maxCookingTimeTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->maxCookingTimeTextBox->Location = System::Drawing::Point(200, 520);
			this->maxCookingTimeTextBox->Name = L"maxCookingTimeTextBox";
			this->maxCookingTimeTextBox->Size = System::Drawing::Size(52, 20);
			this->maxCookingTimeTextBox->TabIndex = 15;
			// 
			// maxAllTimeTextBox
			// 
			this->maxAllTimeTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->maxAllTimeTextBox->Location = System::Drawing::Point(200, 602);
			this->maxAllTimeTextBox->Name = L"maxAllTimeTextBox";
			this->maxAllTimeTextBox->Size = System::Drawing::Size(52, 20);
			this->maxAllTimeTextBox->TabIndex = 16;
			// 
			// maxPreparingTimeTextBox
			// 
			this->maxPreparingTimeTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->maxPreparingTimeTextBox->Location = System::Drawing::Point(200, 443);
			this->maxPreparingTimeTextBox->Name = L"maxPreparingTimeTextBox";
			this->maxPreparingTimeTextBox->Size = System::Drawing::Size(52, 20);
			this->maxPreparingTimeTextBox->TabIndex = 17;
			// 
			// minPreparingTimeTextBox
			// 
			this->minPreparingTimeTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->minPreparingTimeTextBox->Location = System::Drawing::Point(59, 443);
			this->minPreparingTimeTextBox->Name = L"minPreparingTimeTextBox";
			this->minPreparingTimeTextBox->Size = System::Drawing::Size(55, 20);
			this->minPreparingTimeTextBox->TabIndex = 18;
			// 
			// categoriesLabel
			// 
			this->categoriesLabel->AutoSize = true;
			this->categoriesLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->categoriesLabel->Location = System::Drawing::Point(102, 147);
			this->categoriesLabel->Name = L"categoriesLabel";
			this->categoriesLabel->Size = System::Drawing::Size(98, 20);
			this->categoriesLabel->TabIndex = 19;
			this->categoriesLabel->Text = L"Категории";
			// 
			// cookingTimeLabel
			// 
			this->cookingTimeLabel->AutoSize = true;
			this->cookingTimeLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->cookingTimeLabel->Location = System::Drawing::Point(57, 497);
			this->cookingTimeLabel->Name = L"cookingTimeLabel";
			this->cookingTimeLabel->Size = System::Drawing::Size(197, 20);
			this->cookingTimeLabel->TabIndex = 20;
			this->cookingTimeLabel->Text = L"Время приготовления";
			// 
			// preparingTimeLabel
			// 
			this->preparingTimeLabel->AutoSize = true;
			this->preparingTimeLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->preparingTimeLabel->Location = System::Drawing::Point(67, 420);
			this->preparingTimeLabel->Name = L"preparingTimeLabel";
			this->preparingTimeLabel->Size = System::Drawing::Size(167, 20);
			this->preparingTimeLabel->TabIndex = 21;
			this->preparingTimeLabel->Text = L"Время подготовки";
			// 
			// markLabel
			// 
			this->markLabel->AutoSize = true;
			this->markLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->markLabel->Location = System::Drawing::Point(80, 273);
			this->markLabel->Name = L"markLabel";
			this->markLabel->Size = System::Drawing::Size(136, 20);
			this->markLabel->TabIndex = 22;
			this->markLabel->Text = L"Личная оценка";
			// 
			// allTimeLabel
			// 
			this->allTimeLabel->AutoSize = true;
			this->allTimeLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->allTimeLabel->Location = System::Drawing::Point(35, 579);
			this->allTimeLabel->Name = L"allTimeLabel";
			this->allTimeLabel->Size = System::Drawing::Size(257, 20);
			this->allTimeLabel->TabIndex = 23;
			this->allTimeLabel->Text = L"Общее время приготовления";
			// 
			// stepTextBox
			// 
			this->stepTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->stepTextBox->Location = System::Drawing::Point(59, 769);
			this->stepTextBox->Name = L"stepTextBox";
			this->stepTextBox->Size = System::Drawing::Size(193, 20);
			this->stepTextBox->TabIndex = 24;
			// 
			// dashLabel2
			// 
			this->dashLabel2->AutoSize = true;
			this->dashLabel2->Location = System::Drawing::Point(140, 299);
			this->dashLabel2->Name = L"dashLabel2";
			this->dashLabel2->Size = System::Drawing::Size(19, 13);
			this->dashLabel2->TabIndex = 25;
			this->dashLabel2->Text = L"----";
			// 
			// dashLabel3
			// 
			this->dashLabel3->AutoSize = true;
			this->dashLabel3->Location = System::Drawing::Point(141, 370);
			this->dashLabel3->Name = L"dashLabel3";
			this->dashLabel3->Size = System::Drawing::Size(19, 13);
			this->dashLabel3->TabIndex = 26;
			this->dashLabel3->Text = L"----";
			// 
			// dashLabel4
			// 
			this->dashLabel4->AutoSize = true;
			this->dashLabel4->Location = System::Drawing::Point(141, 446);
			this->dashLabel4->Name = L"dashLabel4";
			this->dashLabel4->Size = System::Drawing::Size(19, 13);
			this->dashLabel4->TabIndex = 27;
			this->dashLabel4->Text = L"----";
			// 
			// dashLabel5
			// 
			this->dashLabel5->AutoSize = true;
			this->dashLabel5->Location = System::Drawing::Point(140, 523);
			this->dashLabel5->Name = L"dashLabel5";
			this->dashLabel5->Size = System::Drawing::Size(19, 13);
			this->dashLabel5->TabIndex = 28;
			this->dashLabel5->Text = L"----";
			// 
			// ingridientLabel
			// 
			this->ingridientLabel->AutoSize = true;
			this->ingridientLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->ingridientLabel->Location = System::Drawing::Point(93, 207);
			this->ingridientLabel->Name = L"ingridientLabel";
			this->ingridientLabel->Size = System::Drawing::Size(123, 20);
			this->ingridientLabel->TabIndex = 29;
			this->ingridientLabel->Text = L"Ингридиенты";
			// 
			// ingridientsSearchTextBox
			// 
			this->ingridientsSearchTextBox->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->ingridientsSearchTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->ingridientsSearchTextBox->ForeColor = System::Drawing::SystemColors::MenuText;
			this->ingridientsSearchTextBox->Location = System::Drawing::Point(59, 230);
			this->ingridientsSearchTextBox->Name = L"ingridientsSearchTextBox";
			this->ingridientsSearchTextBox->Size = System::Drawing::Size(193, 22);
			this->ingridientsSearchTextBox->TabIndex = 30;
			// 
			// resultLabel
			// 
			this->resultLabel->AutoSize = true;
			this->resultLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->resultLabel->Location = System::Drawing::Point(399, 44);
			this->resultLabel->Name = L"resultLabel";
			this->resultLabel->Size = System::Drawing::Size(223, 25);
			this->resultLabel->TabIndex = 31;
			this->resultLabel->Text = L"Результаты поиска";
			// 
			// selectUnionRadioButton
			// 
			this->selectUnionRadioButton->AutoSize = true;
			this->selectUnionRadioButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->selectUnionRadioButton->Location = System::Drawing::Point(37, 29);
			this->selectUnionRadioButton->Name = L"selectUnionRadioButton";
			this->selectUnionRadioButton->Size = System::Drawing::Size(105, 17);
			this->selectUnionRadioButton->TabIndex = 32;
			this->selectUnionRadioButton->TabStop = true;
			this->selectUnionRadioButton->Text = L"Объединение";
			this->selectUnionRadioButton->UseVisualStyleBackColor = true;
			// 
			// selectIntersectionRadioButton
			// 
			this->selectIntersectionRadioButton->AutoSize = true;
			this->selectIntersectionRadioButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->selectIntersectionRadioButton->Location = System::Drawing::Point(37, 52);
			this->selectIntersectionRadioButton->Name = L"selectIntersectionRadioButton";
			this->selectIntersectionRadioButton->Size = System::Drawing::Size(103, 17);
			this->selectIntersectionRadioButton->TabIndex = 33;
			this->selectIntersectionRadioButton->TabStop = true;
			this->selectIntersectionRadioButton->Text = L"Пересечение";
			this->selectIntersectionRadioButton->UseVisualStyleBackColor = true;
			// 
			// selectModeLabel
			// 
			this->selectModeLabel->AutoSize = true;
			this->selectModeLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->selectModeLabel->Location = System::Drawing::Point(67, 819);
			this->selectModeLabel->Name = L"selectModeLabel";
			this->selectModeLabel->Size = System::Drawing::Size(167, 20);
			this->selectModeLabel->TabIndex = 34;
			this->selectModeLabel->Text = L"Связь параметров";
			// 
			// resultRecipeListBox
			// 
			this->resultRecipeListBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->resultRecipeListBox->FormattingEnabled = true;
			this->resultRecipeListBox->Location = System::Drawing::Point(404, 87);
			this->resultRecipeListBox->Name = L"resultRecipeListBox";
			this->resultRecipeListBox->Size = System::Drawing::Size(218, 836);
			this->resultRecipeListBox->TabIndex = 35;
			this->resultRecipeListBox->SelectedIndexChanged += gcnew System::EventHandler(this, &GRAPHICS::resultRecipeListBox_SelectedIndexChanged);
			// 
			// currentRecipeLabel
			// 
			this->currentRecipeLabel->AutoSize = true;
			this->currentRecipeLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->currentRecipeLabel->Location = System::Drawing::Point(1491, 41);
			this->currentRecipeLabel->Name = L"currentRecipeLabel";
			this->currentRecipeLabel->Size = System::Drawing::Size(235, 31);
			this->currentRecipeLabel->TabIndex = 36;
			this->currentRecipeLabel->Text = L"Текущий рецепт";
			// 
			// currentRecipePictureBox
			// 
			this->currentRecipePictureBox->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->currentRecipePictureBox->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"currentRecipePictureBox.Image")));
			this->currentRecipePictureBox->Location = System::Drawing::Point(691, 85);
			this->currentRecipePictureBox->Name = L"currentRecipePictureBox";
			this->currentRecipePictureBox->Size = System::Drawing::Size(450, 300);
			this->currentRecipePictureBox->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->currentRecipePictureBox->TabIndex = 37;
			this->currentRecipePictureBox->TabStop = false;
			// 
			// currentRecipeCommentLabel
			// 
			this->currentRecipeCommentLabel->AutoSize = true;
			this->currentRecipeCommentLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->currentRecipeCommentLabel->Location = System::Drawing::Point(1153, 232);
			this->currentRecipeCommentLabel->Name = L"currentRecipeCommentLabel";
			this->currentRecipeCommentLabel->Size = System::Drawing::Size(476, 25);
			this->currentRecipeCommentLabel->TabIndex = 38;
			this->currentRecipeCommentLabel->Text = L"Личный комментарий к текущему рецепту";
			// 
			// currentRecipeCategoryLabel
			// 
			this->currentRecipeCategoryLabel->AutoSize = true;
			this->currentRecipeCategoryLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->currentRecipeCategoryLabel->Location = System::Drawing::Point(1154, 87);
			this->currentRecipeCategoryLabel->Name = L"currentRecipeCategoryLabel";
			this->currentRecipeCategoryLabel->Size = System::Drawing::Size(103, 20);
			this->currentRecipeCategoryLabel->TabIndex = 39;
			this->currentRecipeCategoryLabel->Text = L"Категории:";
			// 
			// currentRecipePreparingTimeLabel
			// 
			this->currentRecipePreparingTimeLabel->AutoSize = true;
			this->currentRecipePreparingTimeLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->currentRecipePreparingTimeLabel->Location = System::Drawing::Point(1154, 147);
			this->currentRecipePreparingTimeLabel->Name = L"currentRecipePreparingTimeLabel";
			this->currentRecipePreparingTimeLabel->Size = System::Drawing::Size(177, 20);
			this->currentRecipePreparingTimeLabel->TabIndex = 40;
			this->currentRecipePreparingTimeLabel->Text = L"Время подготовки: ";
			// 
			// currentRecipeIngridientsLabel
			// 
			this->currentRecipeIngridientsLabel->AutoSize = true;
			this->currentRecipeIngridientsLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->currentRecipeIngridientsLabel->Location = System::Drawing::Point(1154, 207);
			this->currentRecipeIngridientsLabel->Name = L"currentRecipeIngridientsLabel";
			this->currentRecipeIngridientsLabel->Size = System::Drawing::Size(128, 20);
			this->currentRecipeIngridientsLabel->TabIndex = 41;
			this->currentRecipeIngridientsLabel->Text = L"Ингридиенты:";
			// 
			// currentRecipeAllTimeLabel
			// 
			this->currentRecipeAllTimeLabel->AutoSize = true;
			this->currentRecipeAllTimeLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->currentRecipeAllTimeLabel->Location = System::Drawing::Point(1154, 187);
			this->currentRecipeAllTimeLabel->Name = L"currentRecipeAllTimeLabel";
			this->currentRecipeAllTimeLabel->Size = System::Drawing::Size(133, 20);
			this->currentRecipeAllTimeLabel->TabIndex = 42;
			this->currentRecipeAllTimeLabel->Text = L"Общее время: ";
			// 
			// currentRecipeCookingTimeLabel
			// 
			this->currentRecipeCookingTimeLabel->AutoSize = true;
			this->currentRecipeCookingTimeLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->currentRecipeCookingTimeLabel->Location = System::Drawing::Point(1154, 167);
			this->currentRecipeCookingTimeLabel->Name = L"currentRecipeCookingTimeLabel";
			this->currentRecipeCookingTimeLabel->Size = System::Drawing::Size(202, 20);
			this->currentRecipeCookingTimeLabel->TabIndex = 43;
			this->currentRecipeCookingTimeLabel->Text = L"Время приготовления:";
			// 
			// currentRecipeCaloriesLabel
			// 
			this->currentRecipeCaloriesLabel->AutoSize = true;
			this->currentRecipeCaloriesLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->currentRecipeCaloriesLabel->Location = System::Drawing::Point(1154, 127);
			this->currentRecipeCaloriesLabel->Name = L"currentRecipeCaloriesLabel";
			this->currentRecipeCaloriesLabel->Size = System::Drawing::Size(135, 20);
			this->currentRecipeCaloriesLabel->TabIndex = 44;
			this->currentRecipeCaloriesLabel->Text = L"Калорийность:";
			// 
			// currentRecipeMarkLabel
			// 
			this->currentRecipeMarkLabel->AutoSize = true;
			this->currentRecipeMarkLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->currentRecipeMarkLabel->Location = System::Drawing::Point(1154, 107);
			this->currentRecipeMarkLabel->Name = L"currentRecipeMarkLabel";
			this->currentRecipeMarkLabel->Size = System::Drawing::Size(141, 20);
			this->currentRecipeMarkLabel->TabIndex = 45;
			this->currentRecipeMarkLabel->Text = L"Личная оценка:";
			// 
			// startSearchButton
			// 
			this->startSearchButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->startSearchButton->Location = System::Drawing::Point(314, 44);
			this->startSearchButton->Name = L"startSearchButton";
			this->startSearchButton->Size = System::Drawing::Size(64, 25);
			this->startSearchButton->TabIndex = 46;
			this->startSearchButton->Text = L"поиск";
			this->startSearchButton->UseVisualStyleBackColor = true;
			this->startSearchButton->Click += gcnew System::EventHandler(this, &GRAPHICS::startSearchButton_Click);
			// 
			// radioButtonsGroupBox
			// 
			this->radioButtonsGroupBox->Controls->Add(this->selectUnionRadioButton);
			this->radioButtonsGroupBox->Controls->Add(this->selectIntersectionRadioButton);
			this->radioButtonsGroupBox->Location = System::Drawing::Point(61, 842);
			this->radioButtonsGroupBox->Name = L"radioButtonsGroupBox";
			this->radioButtonsGroupBox->Size = System::Drawing::Size(184, 85);
			this->radioButtonsGroupBox->TabIndex = 47;
			this->radioButtonsGroupBox->TabStop = false;
			// 
			// currentRecipeCommentTextLabel
			// 
			this->currentRecipeCommentTextLabel->AutoSize = true;
			this->currentRecipeCommentTextLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->currentRecipeCommentTextLabel->Location = System::Drawing::Point(1154, 273);
			this->currentRecipeCommentTextLabel->Name = L"currentRecipeCommentTextLabel";
			this->currentRecipeCommentTextLabel->Size = System::Drawing::Size(412, 40);
			this->currentRecipeCommentTextLabel->TabIndex = 48;
			this->currentRecipeCommentTextLabel->Text = L"Здесь будет личный комментарий\r\nНе то что бы по вкусу вкусно, но по сути вкусно\r\n"
				L"";
			// 
			// currentRecipeStepLabel
			// 
			this->currentRecipeStepLabel->AutoSize = true;
			this->currentRecipeStepLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->currentRecipeStepLabel->Location = System::Drawing::Point(686, 415);
			this->currentRecipeStepLabel->Name = L"currentRecipeStepLabel";
			this->currentRecipeStepLabel->Size = System::Drawing::Size(454, 25);
			this->currentRecipeStepLabel->TabIndex = 49;
			this->currentRecipeStepLabel->Text = L"Инструкция по приготовлению по шагам";
			// 
			// currentStepTextLabel
			// 
			this->currentStepTextLabel->AutoSize = true;
			this->currentStepTextLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->currentStepTextLabel->Location = System::Drawing::Point(1154, 456);
			this->currentStepTextLabel->Name = L"currentStepTextLabel";
			this->currentStepTextLabel->Size = System::Drawing::Size(470, 80);
			this->currentStepTextLabel->TabIndex = 50;
			this->currentStepTextLabel->Text = L"Здесь будет текст шага выбранного рецепта\r\nБудет вкусно\r\nПотому что почти из чего"
				L" угодно можно сварить пиво\r\nА пиво, как мы знаем, лучший продукт\r\n";
			// 
			// currentStepPictureBox
			// 
			this->currentStepPictureBox->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->currentStepPictureBox->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"currentStepPictureBox.Image")));
			this->currentStepPictureBox->Location = System::Drawing::Point(691, 456);
			this->currentStepPictureBox->Name = L"currentStepPictureBox";
			this->currentStepPictureBox->Size = System::Drawing::Size(450, 300);
			this->currentStepPictureBox->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->currentStepPictureBox->TabIndex = 51;
			this->currentStepPictureBox->TabStop = false;
			// 
			// currentStepLabel
			// 
			this->currentStepLabel->AutoSize = true;
			this->currentStepLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->currentStepLabel->Location = System::Drawing::Point(1264, 415);
			this->currentStepLabel->Name = L"currentStepLabel";
			this->currentStepLabel->Size = System::Drawing::Size(180, 25);
			this->currentStepLabel->TabIndex = 52;
			this->currentStepLabel->Text = L"Шаг Undefinded";
			// 
			// previousStepButton
			// 
			this->previousStepButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->previousStepButton->Location = System::Drawing::Point(691, 920);
			this->previousStepButton->Name = L"previousStepButton";
			this->previousStepButton->Size = System::Drawing::Size(312, 55);
			this->previousStepButton->TabIndex = 53;
			this->previousStepButton->Text = L"<< Предыдущий шаг";
			this->previousStepButton->UseVisualStyleBackColor = true;
			this->previousStepButton->Click += gcnew System::EventHandler(this, &GRAPHICS::previousStepButton_Click);
			// 
			// nextStepButton
			// 
			this->nextStepButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->nextStepButton->Location = System::Drawing::Point(1515, 920);
			this->nextStepButton->Name = L"nextStepButton";
			this->nextStepButton->Size = System::Drawing::Size(312, 55);
			this->nextStepButton->TabIndex = 54;
			this->nextStepButton->Text = L"Следующий шаг >>";
			this->nextStepButton->UseVisualStyleBackColor = true;
			this->nextStepButton->Click += gcnew System::EventHandler(this, &GRAPHICS::nextStepButton_Click);
			// 
			// currentStepButton
			// 
			this->currentStepButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->currentStepButton->Location = System::Drawing::Point(1106, 920);
			this->currentStepButton->Name = L"currentStepButton";
			this->currentStepButton->Size = System::Drawing::Size(312, 55);
			this->currentStepButton->TabIndex = 55;
			this->currentStepButton->Text = L"Шаг N/N (редактировать шаг)";
			this->currentStepButton->UseVisualStyleBackColor = true;
			this->currentStepButton->Click += gcnew System::EventHandler(this, &GRAPHICS::currentStepButton_Click);
			// 
			// stepEditTextBox
			// 
			this->stepEditTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->stepEditTextBox->Location = System::Drawing::Point(691, 769);
			this->stepEditTextBox->Name = L"stepEditTextBox";
			this->stepEditTextBox->Size = System::Drawing::Size(1136, 126);
			this->stepEditTextBox->TabIndex = 56;
			this->stepEditTextBox->Text = L"Вы не должны видеть этот текст просто так";
			this->stepEditTextBox->Visible = false;
			this->stepEditTextBox->TextChanged += gcnew System::EventHandler(this, &GRAPHICS::stepEditTextBox_TextChanged);
			// 
			// addNewRecipeButton
			// 
			this->addNewRecipeButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->addNewRecipeButton->Location = System::Drawing::Point(691, 47);
			this->addNewRecipeButton->Name = L"addNewRecipeButton";
			this->addNewRecipeButton->Size = System::Drawing::Size(200, 25);
			this->addNewRecipeButton->TabIndex = 57;
			this->addNewRecipeButton->Text = L"+ новый рецепт";
			this->addNewRecipeButton->UseVisualStyleBackColor = true;
			this->addNewRecipeButton->Click += gcnew System::EventHandler(this, &GRAPHICS::addNewRecipeButton_Click);
			// 
			// deleteCurrentRecipeButton
			// 
			this->deleteCurrentRecipeButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->deleteCurrentRecipeButton->Location = System::Drawing::Point(941, 47);
			this->deleteCurrentRecipeButton->Name = L"deleteCurrentRecipeButton";
			this->deleteCurrentRecipeButton->Size = System::Drawing::Size(200, 25);
			this->deleteCurrentRecipeButton->TabIndex = 58;
			this->deleteCurrentRecipeButton->Text = L"- удалить рецепт";
			this->deleteCurrentRecipeButton->UseVisualStyleBackColor = true;
			this->deleteCurrentRecipeButton->Click += gcnew System::EventHandler(this, &GRAPHICS::deleteCurrentRecipeButton_Click);
			// 
			// GRAPHICS
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->ClientSize = System::Drawing::Size(1904, 1041);
			this->Controls->Add(this->deleteCurrentRecipeButton);
			this->Controls->Add(this->addNewRecipeButton);
			this->Controls->Add(this->selectModeLabel);
			this->Controls->Add(this->stepEditTextBox);
			this->Controls->Add(this->currentStepButton);
			this->Controls->Add(this->nextStepButton);
			this->Controls->Add(this->previousStepButton);
			this->Controls->Add(this->currentStepLabel);
			this->Controls->Add(this->currentStepPictureBox);
			this->Controls->Add(this->currentStepTextLabel);
			this->Controls->Add(this->currentRecipeStepLabel);
			this->Controls->Add(this->currentRecipeCommentTextLabel);
			this->Controls->Add(this->radioButtonsGroupBox);
			this->Controls->Add(this->startSearchButton);
			this->Controls->Add(this->currentRecipeMarkLabel);
			this->Controls->Add(this->currentRecipeCaloriesLabel);
			this->Controls->Add(this->currentRecipeCookingTimeLabel);
			this->Controls->Add(this->currentRecipeAllTimeLabel);
			this->Controls->Add(this->currentRecipeIngridientsLabel);
			this->Controls->Add(this->currentRecipePreparingTimeLabel);
			this->Controls->Add(this->currentRecipeCategoryLabel);
			this->Controls->Add(this->currentRecipeCommentLabel);
			this->Controls->Add(this->currentRecipePictureBox);
			this->Controls->Add(this->currentRecipeLabel);
			this->Controls->Add(this->resultRecipeListBox);
			this->Controls->Add(this->resultLabel);
			this->Controls->Add(this->ingridientsSearchTextBox);
			this->Controls->Add(this->ingridientLabel);
			this->Controls->Add(this->dashLabel5);
			this->Controls->Add(this->dashLabel4);
			this->Controls->Add(this->dashLabel3);
			this->Controls->Add(this->dashLabel2);
			this->Controls->Add(this->stepTextBox);
			this->Controls->Add(this->allTimeLabel);
			this->Controls->Add(this->markLabel);
			this->Controls->Add(this->preparingTimeLabel);
			this->Controls->Add(this->cookingTimeLabel);
			this->Controls->Add(this->categoriesLabel);
			this->Controls->Add(this->minPreparingTimeTextBox);
			this->Controls->Add(this->maxPreparingTimeTextBox);
			this->Controls->Add(this->maxAllTimeTextBox);
			this->Controls->Add(this->maxCookingTimeTextBox);
			this->Controls->Add(this->minMarkTextBox);
			this->Controls->Add(this->minAllTimeTextBox);
			this->Controls->Add(this->minCookingTimeTextBox);
			this->Controls->Add(this->maxMarkTextBox);
			this->Controls->Add(this->commentTextBox);
			this->Controls->Add(this->stepPhraseSearchLabel);
			this->Controls->Add(this->categoriesSearchTextBox);
			this->Controls->Add(this->commentSearchLabel);
			this->Controls->Add(this->dishNameSearchLabel);
			this->Controls->Add(this->dashLabel1);
			this->Controls->Add(this->maxCaloriesTextBox);
			this->Controls->Add(this->minCaloriesTextBox);
			this->Controls->Add(this->caloriesLabel);
			this->Controls->Add(this->nameSearchTextBox);
			this->Controls->Add(this->searchLabel);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"GRAPHICS";
			this->Text = L"RECIPEBOOK";
			this->Load += gcnew System::EventHandler(this, &GRAPHICS::GRAPHICS_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->currentRecipePictureBox))->EndInit();
			this->radioButtonsGroupBox->ResumeLayout(false);
			this->radioButtonsGroupBox->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->currentStepPictureBox))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void GRAPHICS_Load(System::Object^ sender, System::EventArgs^ e);
	private: System::Void startSearchButton_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void resultRecipeListBox_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void nextStepButton_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void previousStepButton_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void currentStepButton_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void stepEditTextBox_TextChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void addNewRecipeButton_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void deleteCurrentRecipeButton_Click(System::Object^ sender, System::EventArgs^ e);
};
}
