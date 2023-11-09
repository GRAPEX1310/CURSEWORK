#pragma once

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
	private: System::Windows::Forms::ListBox^ listBox1;
	private: System::Windows::Forms::Label^ currentRecipeLabel;
	private: System::Windows::Forms::PictureBox^ currentRecipePictureBox;
	private: System::Windows::Forms::Label^ currentReciepeCommentLabel;

	private: System::Windows::Forms::Label^ currentRecipeCategoryLabel;
	private: System::Windows::Forms::Label^ currentRecipePreparingTimeLabel;


	private: System::Windows::Forms::Label^ currentRecipeIngridientsLabel;
	private: System::Windows::Forms::Label^ currentRecipeAllTimeLabel;


	private: System::Windows::Forms::Label^ currentRecipeCookingTimeLabel;

	private: System::Windows::Forms::Label^ currentREcipeCaloriesLabel;

	private: System::Windows::Forms::Label^ currentRecipeMarkLabel;
	private: System::Windows::Forms::Button^ startSearchButton;
	private: System::Windows::Forms::GroupBox^ radioButtonsGroupBox;








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
			this->listBox1 = (gcnew System::Windows::Forms::ListBox());
			this->currentRecipeLabel = (gcnew System::Windows::Forms::Label());
			this->currentRecipePictureBox = (gcnew System::Windows::Forms::PictureBox());
			this->currentReciepeCommentLabel = (gcnew System::Windows::Forms::Label());
			this->currentRecipeCategoryLabel = (gcnew System::Windows::Forms::Label());
			this->currentRecipePreparingTimeLabel = (gcnew System::Windows::Forms::Label());
			this->currentRecipeIngridientsLabel = (gcnew System::Windows::Forms::Label());
			this->currentRecipeAllTimeLabel = (gcnew System::Windows::Forms::Label());
			this->currentRecipeCookingTimeLabel = (gcnew System::Windows::Forms::Label());
			this->currentREcipeCaloriesLabel = (gcnew System::Windows::Forms::Label());
			this->currentRecipeMarkLabel = (gcnew System::Windows::Forms::Label());
			this->startSearchButton = (gcnew System::Windows::Forms::Button());
			this->radioButtonsGroupBox = (gcnew System::Windows::Forms::GroupBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->currentRecipePictureBox))->BeginInit();
			this->radioButtonsGroupBox->SuspendLayout();
			this->SuspendLayout();
			// 
			// searchLabel
			// 
			this->searchLabel->AutoSize = true;
			this->searchLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->searchLabel->Location = System::Drawing::Point(39, 9);
			this->searchLabel->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->searchLabel->Name = L"searchLabel";
			this->searchLabel->Size = System::Drawing::Size(230, 31);
			this->searchLabel->TabIndex = 0;
			this->searchLabel->Text = L"Поиск рецептов";
			// 
			// nameSearchTextBox
			// 
			this->nameSearchTextBox->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->nameSearchTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.749998F, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->nameSearchTextBox->ForeColor = System::Drawing::SystemColors::MenuText;
			this->nameSearchTextBox->Location = System::Drawing::Point(45, 85);
			this->nameSearchTextBox->Margin = System::Windows::Forms::Padding(4, 3, 4, 3);
			this->nameSearchTextBox->Name = L"nameSearchTextBox";
			this->nameSearchTextBox->Size = System::Drawing::Size(224, 22);
			this->nameSearchTextBox->TabIndex = 1;
			// 
			// caloriesLabel
			// 
			this->caloriesLabel->AutoSize = true;
			this->caloriesLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->caloriesLabel->Location = System::Drawing::Point(55, 345);
			this->caloriesLabel->Name = L"caloriesLabel";
			this->caloriesLabel->Size = System::Drawing::Size(205, 20);
			this->caloriesLabel->TabIndex = 2;
			this->caloriesLabel->Text = L"Калорийность (от - до)";
			// 
			// minCaloriesTextBox
			// 
			this->minCaloriesTextBox->Location = System::Drawing::Point(48, 378);
			this->minCaloriesTextBox->Name = L"minCaloriesTextBox";
			this->minCaloriesTextBox->Size = System::Drawing::Size(63, 20);
			this->minCaloriesTextBox->TabIndex = 3;
			// 
			// maxCaloriesTextBox
			// 
			this->maxCaloriesTextBox->Location = System::Drawing::Point(212, 382);
			this->maxCaloriesTextBox->Name = L"maxCaloriesTextBox";
			this->maxCaloriesTextBox->Size = System::Drawing::Size(60, 20);
			this->maxCaloriesTextBox->TabIndex = 4;
			// 
			// dashLabel1
			// 
			this->dashLabel1->AutoSize = true;
			this->dashLabel1->Location = System::Drawing::Point(144, 612);
			this->dashLabel1->Name = L"dashLabel1";
			this->dashLabel1->Size = System::Drawing::Size(23, 13);
			this->dashLabel1->TabIndex = 5;
			this->dashLabel1->Text = L"----";
			// 
			// dishNameSearchLabel
			// 
			this->dishNameSearchLabel->AutoSize = true;
			this->dishNameSearchLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->dishNameSearchLabel->Location = System::Drawing::Point(71, 52);
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
			this->commentSearchLabel->Location = System::Drawing::Point(24, 649);
			this->commentSearchLabel->Name = L"commentSearchLabel";
			this->commentSearchLabel->Size = System::Drawing::Size(280, 20);
			this->commentSearchLabel->TabIndex = 7;
			this->commentSearchLabel->Text = L"Фраза из личного комментария";
			// 
			// categoriesSearchTextBox
			// 
			this->categoriesSearchTextBox->Location = System::Drawing::Point(48, 157);
			this->categoriesSearchTextBox->Name = L"categoriesSearchTextBox";
			this->categoriesSearchTextBox->Size = System::Drawing::Size(224, 20);
			this->categoriesSearchTextBox->TabIndex = 8;
			// 
			// stepPhraseSearchLabel
			// 
			this->stepPhraseSearchLabel->AutoSize = true;
			this->stepPhraseSearchLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->stepPhraseSearchLabel->Location = System::Drawing::Point(63, 724);
			this->stepPhraseSearchLabel->Name = L"stepPhraseSearchLabel";
			this->stepPhraseSearchLabel->Size = System::Drawing::Size(189, 20);
			this->stepPhraseSearchLabel->TabIndex = 9;
			this->stepPhraseSearchLabel->Text = L"Фраза из инструкции";
			// 
			// commentTextBox
			// 
			this->commentTextBox->Location = System::Drawing::Point(48, 683);
			this->commentTextBox->Name = L"commentTextBox";
			this->commentTextBox->Size = System::Drawing::Size(215, 20);
			this->commentTextBox->TabIndex = 10;
			// 
			// maxMarkTextBox
			// 
			this->maxMarkTextBox->Location = System::Drawing::Point(212, 307);
			this->maxMarkTextBox->Name = L"maxMarkTextBox";
			this->maxMarkTextBox->Size = System::Drawing::Size(60, 20);
			this->maxMarkTextBox->TabIndex = 11;
			// 
			// minCookingTimeTextBox
			// 
			this->minCookingTimeTextBox->Location = System::Drawing::Point(48, 535);
			this->minCookingTimeTextBox->Name = L"minCookingTimeTextBox";
			this->minCookingTimeTextBox->Size = System::Drawing::Size(63, 20);
			this->minCookingTimeTextBox->TabIndex = 12;
			// 
			// minAllTimeTextBox
			// 
			this->minAllTimeTextBox->Location = System::Drawing::Point(48, 609);
			this->minAllTimeTextBox->Name = L"minAllTimeTextBox";
			this->minAllTimeTextBox->Size = System::Drawing::Size(66, 20);
			this->minAllTimeTextBox->TabIndex = 13;
			// 
			// minMarkTextBox
			// 
			this->minMarkTextBox->Location = System::Drawing::Point(48, 307);
			this->minMarkTextBox->Name = L"minMarkTextBox";
			this->minMarkTextBox->Size = System::Drawing::Size(63, 20);
			this->minMarkTextBox->TabIndex = 14;
			// 
			// maxCookingTimeTextBox
			// 
			this->maxCookingTimeTextBox->Location = System::Drawing::Point(212, 535);
			this->maxCookingTimeTextBox->Name = L"maxCookingTimeTextBox";
			this->maxCookingTimeTextBox->Size = System::Drawing::Size(60, 20);
			this->maxCookingTimeTextBox->TabIndex = 15;
			// 
			// maxAllTimeTextBox
			// 
			this->maxAllTimeTextBox->Location = System::Drawing::Point(212, 609);
			this->maxAllTimeTextBox->Name = L"maxAllTimeTextBox";
			this->maxAllTimeTextBox->Size = System::Drawing::Size(60, 20);
			this->maxAllTimeTextBox->TabIndex = 16;
			// 
			// maxPreparingTimeTextBox
			// 
			this->maxPreparingTimeTextBox->Location = System::Drawing::Point(212, 456);
			this->maxPreparingTimeTextBox->Name = L"maxPreparingTimeTextBox";
			this->maxPreparingTimeTextBox->Size = System::Drawing::Size(60, 20);
			this->maxPreparingTimeTextBox->TabIndex = 17;
			// 
			// minPreparingTimeTextBox
			// 
			this->minPreparingTimeTextBox->Location = System::Drawing::Point(48, 456);
			this->minPreparingTimeTextBox->Name = L"minPreparingTimeTextBox";
			this->minPreparingTimeTextBox->Size = System::Drawing::Size(63, 20);
			this->minPreparingTimeTextBox->TabIndex = 18;
			// 
			// categoriesLabel
			// 
			this->categoriesLabel->AutoSize = true;
			this->categoriesLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->categoriesLabel->Location = System::Drawing::Point(100, 121);
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
			this->cookingTimeLabel->Location = System::Drawing::Point(63, 494);
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
			this->preparingTimeLabel->Location = System::Drawing::Point(76, 419);
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
			this->markLabel->Location = System::Drawing::Point(87, 273);
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
			this->allTimeLabel->Location = System::Drawing::Point(38, 576);
			this->allTimeLabel->Name = L"allTimeLabel";
			this->allTimeLabel->Size = System::Drawing::Size(257, 20);
			this->allTimeLabel->TabIndex = 23;
			this->allTimeLabel->Text = L"Общее время приготовления";
			// 
			// stepTextBox
			// 
			this->stepTextBox->Location = System::Drawing::Point(48, 764);
			this->stepTextBox->Name = L"stepTextBox";
			this->stepTextBox->Size = System::Drawing::Size(215, 20);
			this->stepTextBox->TabIndex = 24;
			// 
			// dashLabel2
			// 
			this->dashLabel2->AutoSize = true;
			this->dashLabel2->Location = System::Drawing::Point(144, 310);
			this->dashLabel2->Name = L"dashLabel2";
			this->dashLabel2->Size = System::Drawing::Size(23, 13);
			this->dashLabel2->TabIndex = 25;
			this->dashLabel2->Text = L"----";
			// 
			// dashLabel3
			// 
			this->dashLabel3->AutoSize = true;
			this->dashLabel3->Location = System::Drawing::Point(144, 385);
			this->dashLabel3->Name = L"dashLabel3";
			this->dashLabel3->Size = System::Drawing::Size(23, 13);
			this->dashLabel3->TabIndex = 26;
			this->dashLabel3->Text = L"----";
			// 
			// dashLabel4
			// 
			this->dashLabel4->AutoSize = true;
			this->dashLabel4->Location = System::Drawing::Point(144, 459);
			this->dashLabel4->Name = L"dashLabel4";
			this->dashLabel4->Size = System::Drawing::Size(23, 13);
			this->dashLabel4->TabIndex = 27;
			this->dashLabel4->Text = L"----";
			// 
			// dashLabel5
			// 
			this->dashLabel5->AutoSize = true;
			this->dashLabel5->Location = System::Drawing::Point(144, 538);
			this->dashLabel5->Name = L"dashLabel5";
			this->dashLabel5->Size = System::Drawing::Size(23, 13);
			this->dashLabel5->TabIndex = 28;
			this->dashLabel5->Text = L"----";
			// 
			// ingridientLabel
			// 
			this->ingridientLabel->AutoSize = true;
			this->ingridientLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->ingridientLabel->Location = System::Drawing::Point(100, 194);
			this->ingridientLabel->Name = L"ingridientLabel";
			this->ingridientLabel->Size = System::Drawing::Size(123, 20);
			this->ingridientLabel->TabIndex = 29;
			this->ingridientLabel->Text = L"Ингридиенты";
			// 
			// ingridientsSearchTextBox
			// 
			this->ingridientsSearchTextBox->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->ingridientsSearchTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.749998F, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->ingridientsSearchTextBox->ForeColor = System::Drawing::SystemColors::MenuText;
			this->ingridientsSearchTextBox->Location = System::Drawing::Point(48, 232);
			this->ingridientsSearchTextBox->Margin = System::Windows::Forms::Padding(4, 3, 4, 3);
			this->ingridientsSearchTextBox->Name = L"ingridientsSearchTextBox";
			this->ingridientsSearchTextBox->Size = System::Drawing::Size(224, 22);
			this->ingridientsSearchTextBox->TabIndex = 30;
			// 
			// resultLabel
			// 
			this->resultLabel->AutoSize = true;
			this->resultLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->resultLabel->Location = System::Drawing::Point(367, 9);
			this->resultLabel->Name = L"resultLabel";
			this->resultLabel->Size = System::Drawing::Size(274, 31);
			this->resultLabel->TabIndex = 31;
			this->resultLabel->Text = L"Результаты поиска";
			// 
			// selectUnionRadioButton
			// 
			this->selectUnionRadioButton->AutoSize = true;
			this->selectUnionRadioButton->Location = System::Drawing::Point(43, 19);
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
			this->selectIntersectionRadioButton->Location = System::Drawing::Point(43, 52);
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
			this->selectModeLabel->Location = System::Drawing::Point(71, 799);
			this->selectModeLabel->Name = L"selectModeLabel";
			this->selectModeLabel->Size = System::Drawing::Size(167, 20);
			this->selectModeLabel->TabIndex = 34;
			this->selectModeLabel->Text = L"Связь параметров";
			// 
			// listBox1
			// 
			this->listBox1->FormattingEnabled = true;
			this->listBox1->Location = System::Drawing::Point(373, 85);
			this->listBox1->Name = L"listBox1";
			this->listBox1->Size = System::Drawing::Size(268, 797);
			this->listBox1->TabIndex = 35;
			// 
			// currentRecipeLabel
			// 
			this->currentRecipeLabel->AutoSize = true;
			this->currentRecipeLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->currentRecipeLabel->Location = System::Drawing::Point(724, 9);
			this->currentRecipeLabel->Name = L"currentRecipeLabel";
			this->currentRecipeLabel->Size = System::Drawing::Size(235, 31);
			this->currentRecipeLabel->TabIndex = 36;
			this->currentRecipeLabel->Text = L"Текущий рецепт";
			// 
			// currentRecipePictureBox
			// 
			this->currentRecipePictureBox->Location = System::Drawing::Point(730, 85);
			this->currentRecipePictureBox->Name = L"currentRecipePictureBox";
			this->currentRecipePictureBox->Size = System::Drawing::Size(150, 200);
			this->currentRecipePictureBox->TabIndex = 37;
			this->currentRecipePictureBox->TabStop = false;
			// 
			// currentReciepeCommentLabel
			// 
			this->currentReciepeCommentLabel->AutoSize = true;
			this->currentReciepeCommentLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->currentReciepeCommentLabel->Location = System::Drawing::Point(1333, 85);
			this->currentReciepeCommentLabel->Name = L"currentReciepeCommentLabel";
			this->currentReciepeCommentLabel->Size = System::Drawing::Size(365, 20);
			this->currentReciepeCommentLabel->TabIndex = 38;
			this->currentReciepeCommentLabel->Text = L"Личный комментарий к текущему рецепту";
			// 
			// currentRecipeCategoryLabel
			// 
			this->currentRecipeCategoryLabel->AutoSize = true;
			this->currentRecipeCategoryLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->currentRecipeCategoryLabel->Location = System::Drawing::Point(886, 85);
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
			this->currentRecipePreparingTimeLabel->Location = System::Drawing::Point(886, 185);
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
			this->currentRecipeIngridientsLabel->Location = System::Drawing::Point(886, 110);
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
			this->currentRecipeAllTimeLabel->Location = System::Drawing::Point(886, 235);
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
			this->currentRecipeCookingTimeLabel->Location = System::Drawing::Point(886, 210);
			this->currentRecipeCookingTimeLabel->Name = L"currentRecipeCookingTimeLabel";
			this->currentRecipeCookingTimeLabel->Size = System::Drawing::Size(202, 20);
			this->currentRecipeCookingTimeLabel->TabIndex = 43;
			this->currentRecipeCookingTimeLabel->Text = L"Время приготовления:";
			// 
			// currentREcipeCaloriesLabel
			// 
			this->currentREcipeCaloriesLabel->AutoSize = true;
			this->currentREcipeCaloriesLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->currentREcipeCaloriesLabel->Location = System::Drawing::Point(886, 160);
			this->currentREcipeCaloriesLabel->Name = L"currentREcipeCaloriesLabel";
			this->currentREcipeCaloriesLabel->Size = System::Drawing::Size(135, 20);
			this->currentREcipeCaloriesLabel->TabIndex = 44;
			this->currentREcipeCaloriesLabel->Text = L"Калорийность:";
			// 
			// currentRecipeMarkLabel
			// 
			this->currentRecipeMarkLabel->AutoSize = true;
			this->currentRecipeMarkLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->currentRecipeMarkLabel->Location = System::Drawing::Point(886, 135);
			this->currentRecipeMarkLabel->Name = L"currentRecipeMarkLabel";
			this->currentRecipeMarkLabel->Size = System::Drawing::Size(141, 20);
			this->currentRecipeMarkLabel->TabIndex = 45;
			this->currentRecipeMarkLabel->Text = L"Личная оценка:";
			// 
			// startSearchButton
			// 
			this->startSearchButton->Location = System::Drawing::Point(277, 16);
			this->startSearchButton->Name = L"startSearchButton";
			this->startSearchButton->Size = System::Drawing::Size(75, 23);
			this->startSearchButton->TabIndex = 46;
			this->startSearchButton->Text = L"поиск";
			this->startSearchButton->UseVisualStyleBackColor = true;
			this->startSearchButton->Click += gcnew System::EventHandler(this, &GRAPHICS::startSearchButton_Click);
			// 
			// radioButtonsGroupBox
			// 
			this->radioButtonsGroupBox->Controls->Add(this->selectUnionRadioButton);
			this->radioButtonsGroupBox->Controls->Add(this->selectIntersectionRadioButton);
			this->radioButtonsGroupBox->Location = System::Drawing::Point(48, 834);
			this->radioButtonsGroupBox->Name = L"radioButtonsGroupBox";
			this->radioButtonsGroupBox->Size = System::Drawing::Size(215, 85);
			this->radioButtonsGroupBox->TabIndex = 47;
			this->radioButtonsGroupBox->TabStop = false;
			// 
			// GRAPHICS
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(7, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->ClientSize = System::Drawing::Size(1904, 1041);
			this->Controls->Add(this->radioButtonsGroupBox);
			this->Controls->Add(this->startSearchButton);
			this->Controls->Add(this->currentRecipeMarkLabel);
			this->Controls->Add(this->currentREcipeCaloriesLabel);
			this->Controls->Add(this->currentRecipeCookingTimeLabel);
			this->Controls->Add(this->currentRecipeAllTimeLabel);
			this->Controls->Add(this->currentRecipeIngridientsLabel);
			this->Controls->Add(this->currentRecipePreparingTimeLabel);
			this->Controls->Add(this->currentRecipeCategoryLabel);
			this->Controls->Add(this->currentReciepeCommentLabel);
			this->Controls->Add(this->currentRecipePictureBox);
			this->Controls->Add(this->currentRecipeLabel);
			this->Controls->Add(this->listBox1);
			this->Controls->Add(this->selectModeLabel);
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
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.249999F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Margin = System::Windows::Forms::Padding(4, 3, 4, 3);
			this->Name = L"GRAPHICS";
			this->Text = L"RECIPEBOOK";
			this->Load += gcnew System::EventHandler(this, &GRAPHICS::GRAPHICS_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->currentRecipePictureBox))->EndInit();
			this->radioButtonsGroupBox->ResumeLayout(false);
			this->radioButtonsGroupBox->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void GRAPHICS_Load(System::Object^ sender, System::EventArgs^ e);
private: System::Void startSearchButton_Click(System::Object^ sender, System::EventArgs^ e);
};
}
