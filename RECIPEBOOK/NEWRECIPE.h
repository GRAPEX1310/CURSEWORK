#pragma once

namespace RECIPEBOOK {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for NEWRECIPE
	/// </summary>
	public ref class NEWRECIPE : public System::Windows::Forms::Form
	{
	public:
		NEWRECIPE(void)
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
		~NEWRECIPE()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ dishNameSearchLabel;
	private: System::Windows::Forms::Label^ createRecipeLabel;
	private: System::Windows::Forms::TextBox^ nameSearchTextBox;
	private: System::Windows::Forms::Label^ categoriesLabel;
	private: System::Windows::Forms::TextBox^ categoriesSearchTextBox;
	private: System::Windows::Forms::Label^ ingridientLabel;
	private: System::Windows::Forms::TextBox^ ingridientsSearchTextBox;
	private: System::Windows::Forms::Label^ markLabel;
	private: System::Windows::Forms::TextBox^ markTextBox;
	private: System::Windows::Forms::Label^ caloriesLabel;
	private: System::Windows::Forms::TextBox^ ñaloriesTextBox;
	private: System::Windows::Forms::Label^ preparingTimeLabel;
	private: System::Windows::Forms::TextBox^ preparingTimeTextBox;
	private: System::Windows::Forms::Label^ cookingTimeLabel;
	private: System::Windows::Forms::TextBox^ cookingTimeTextBox;
	private: System::Windows::Forms::Label^ allTimeLabel;
	private: System::Windows::Forms::TextBox^ allTimeTextBox;
	private: System::Windows::Forms::Label^ commentSearchLabel;
	private: System::Windows::Forms::TextBox^ commentTextBox;
	private: System::Windows::Forms::Label^ currentRecipeStepLabel;
	private: System::Windows::Forms::Label^ currentStepLabel;
	private: System::Windows::Forms::RichTextBox^ stepEditTextBox;
	private: System::Windows::Forms::Button^ previousStepButton;
	private: System::Windows::Forms::Button^ nextStepButton;
	private: System::Windows::Forms::Button^ finalButton;

	protected:

	protected:

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(NEWRECIPE::typeid));
			this->dishNameSearchLabel = (gcnew System::Windows::Forms::Label());
			this->createRecipeLabel = (gcnew System::Windows::Forms::Label());
			this->nameSearchTextBox = (gcnew System::Windows::Forms::TextBox());
			this->categoriesLabel = (gcnew System::Windows::Forms::Label());
			this->categoriesSearchTextBox = (gcnew System::Windows::Forms::TextBox());
			this->ingridientLabel = (gcnew System::Windows::Forms::Label());
			this->ingridientsSearchTextBox = (gcnew System::Windows::Forms::TextBox());
			this->markLabel = (gcnew System::Windows::Forms::Label());
			this->markTextBox = (gcnew System::Windows::Forms::TextBox());
			this->caloriesLabel = (gcnew System::Windows::Forms::Label());
			this->ñaloriesTextBox = (gcnew System::Windows::Forms::TextBox());
			this->preparingTimeLabel = (gcnew System::Windows::Forms::Label());
			this->preparingTimeTextBox = (gcnew System::Windows::Forms::TextBox());
			this->cookingTimeLabel = (gcnew System::Windows::Forms::Label());
			this->cookingTimeTextBox = (gcnew System::Windows::Forms::TextBox());
			this->allTimeLabel = (gcnew System::Windows::Forms::Label());
			this->allTimeTextBox = (gcnew System::Windows::Forms::TextBox());
			this->commentSearchLabel = (gcnew System::Windows::Forms::Label());
			this->commentTextBox = (gcnew System::Windows::Forms::TextBox());
			this->currentRecipeStepLabel = (gcnew System::Windows::Forms::Label());
			this->currentStepLabel = (gcnew System::Windows::Forms::Label());
			this->stepEditTextBox = (gcnew System::Windows::Forms::RichTextBox());
			this->previousStepButton = (gcnew System::Windows::Forms::Button());
			this->nextStepButton = (gcnew System::Windows::Forms::Button());
			this->finalButton = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// dishNameSearchLabel
			// 
			this->dishNameSearchLabel->AutoSize = true;
			this->dishNameSearchLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->dishNameSearchLabel->Location = System::Drawing::Point(129, 59);
			this->dishNameSearchLabel->Name = L"dishNameSearchLabel";
			this->dishNameSearchLabel->Size = System::Drawing::Size(152, 20);
			this->dishNameSearchLabel->TabIndex = 7;
			this->dishNameSearchLabel->Text = L"Íàçâàíèå áëþäà";
			// 
			// createRecipeLabel
			// 
			this->createRecipeLabel->AutoSize = true;
			this->createRecipeLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->createRecipeLabel->Location = System::Drawing::Point(245, 9);
			this->createRecipeLabel->Name = L"createRecipeLabel";
			this->createRecipeLabel->Size = System::Drawing::Size(424, 29);
			this->createRecipeLabel->TabIndex = 8;
			this->createRecipeLabel->Text = L"Ââåäèòå äàííûå íîâîãî ðåöåïòà";
			// 
			// nameSearchTextBox
			// 
			this->nameSearchTextBox->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->nameSearchTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.749998F, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->nameSearchTextBox->ForeColor = System::Drawing::SystemColors::MenuText;
			this->nameSearchTextBox->Location = System::Drawing::Point(110, 82);
			this->nameSearchTextBox->Name = L"nameSearchTextBox";
			this->nameSearchTextBox->Size = System::Drawing::Size(193, 22);
			this->nameSearchTextBox->TabIndex = 9;
			// 
			// categoriesLabel
			// 
			this->categoriesLabel->AutoSize = true;
			this->categoriesLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->categoriesLabel->Location = System::Drawing::Point(156, 124);
			this->categoriesLabel->Name = L"categoriesLabel";
			this->categoriesLabel->Size = System::Drawing::Size(98, 20);
			this->categoriesLabel->TabIndex = 20;
			this->categoriesLabel->Text = L"Êàòåãîðèè";
			// 
			// categoriesSearchTextBox
			// 
			this->categoriesSearchTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->categoriesSearchTextBox->Location = System::Drawing::Point(110, 147);
			this->categoriesSearchTextBox->Name = L"categoriesSearchTextBox";
			this->categoriesSearchTextBox->Size = System::Drawing::Size(193, 20);
			this->categoriesSearchTextBox->TabIndex = 21;
			// 
			// ingridientLabel
			// 
			this->ingridientLabel->AutoSize = true;
			this->ingridientLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->ingridientLabel->Location = System::Drawing::Point(141, 197);
			this->ingridientLabel->Name = L"ingridientLabel";
			this->ingridientLabel->Size = System::Drawing::Size(123, 20);
			this->ingridientLabel->TabIndex = 30;
			this->ingridientLabel->Text = L"Èíãðèäèåíòû";
			// 
			// ingridientsSearchTextBox
			// 
			this->ingridientsSearchTextBox->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->ingridientsSearchTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->ingridientsSearchTextBox->ForeColor = System::Drawing::SystemColors::MenuText;
			this->ingridientsSearchTextBox->Location = System::Drawing::Point(110, 220);
			this->ingridientsSearchTextBox->Name = L"ingridientsSearchTextBox";
			this->ingridientsSearchTextBox->Size = System::Drawing::Size(193, 22);
			this->ingridientsSearchTextBox->TabIndex = 31;
			// 
			// markLabel
			// 
			this->markLabel->AutoSize = true;
			this->markLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->markLabel->Location = System::Drawing::Point(141, 271);
			this->markLabel->Name = L"markLabel";
			this->markLabel->Size = System::Drawing::Size(136, 20);
			this->markLabel->TabIndex = 32;
			this->markLabel->Text = L"Ëè÷íàÿ îöåíêà";
			// 
			// markTextBox
			// 
			this->markTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->markTextBox->Location = System::Drawing::Point(110, 294);
			this->markTextBox->Name = L"markTextBox";
			this->markTextBox->Size = System::Drawing::Size(193, 20);
			this->markTextBox->TabIndex = 33;
			// 
			// caloriesLabel
			// 
			this->caloriesLabel->AutoSize = true;
			this->caloriesLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->caloriesLabel->Location = System::Drawing::Point(141, 342);
			this->caloriesLabel->Name = L"caloriesLabel";
			this->caloriesLabel->Size = System::Drawing::Size(130, 20);
			this->caloriesLabel->TabIndex = 34;
			this->caloriesLabel->Text = L"Êàëîðèéíîñòü";
			// 
			// ñaloriesTextBox
			// 
			this->ñaloriesTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->ñaloriesTextBox->Location = System::Drawing::Point(110, 365);
			this->ñaloriesTextBox->Name = L"ñaloriesTextBox";
			this->ñaloriesTextBox->Size = System::Drawing::Size(193, 20);
			this->ñaloriesTextBox->TabIndex = 35;
			// 
			// preparingTimeLabel
			// 
			this->preparingTimeLabel->AutoSize = true;
			this->preparingTimeLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->preparingTimeLabel->Location = System::Drawing::Point(129, 414);
			this->preparingTimeLabel->Name = L"preparingTimeLabel";
			this->preparingTimeLabel->Size = System::Drawing::Size(167, 20);
			this->preparingTimeLabel->TabIndex = 36;
			this->preparingTimeLabel->Text = L"Âðåìÿ ïîäãîòîâêè";
			// 
			// preparingTimeTextBox
			// 
			this->preparingTimeTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->preparingTimeTextBox->Location = System::Drawing::Point(110, 437);
			this->preparingTimeTextBox->Name = L"preparingTimeTextBox";
			this->preparingTimeTextBox->Size = System::Drawing::Size(193, 20);
			this->preparingTimeTextBox->TabIndex = 37;
			// 
			// cookingTimeLabel
			// 
			this->cookingTimeLabel->AutoSize = true;
			this->cookingTimeLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->cookingTimeLabel->Location = System::Drawing::Point(106, 490);
			this->cookingTimeLabel->Name = L"cookingTimeLabel";
			this->cookingTimeLabel->Size = System::Drawing::Size(197, 20);
			this->cookingTimeLabel->TabIndex = 38;
			this->cookingTimeLabel->Text = L"Âðåìÿ ïðèãîòîâëåíèÿ";
			// 
			// cookingTimeTextBox
			// 
			this->cookingTimeTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->cookingTimeTextBox->Location = System::Drawing::Point(110, 513);
			this->cookingTimeTextBox->Name = L"cookingTimeTextBox";
			this->cookingTimeTextBox->Size = System::Drawing::Size(193, 20);
			this->cookingTimeTextBox->TabIndex = 39;
			// 
			// allTimeLabel
			// 
			this->allTimeLabel->AutoSize = true;
			this->allTimeLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->allTimeLabel->Location = System::Drawing::Point(80, 569);
			this->allTimeLabel->Name = L"allTimeLabel";
			this->allTimeLabel->Size = System::Drawing::Size(257, 20);
			this->allTimeLabel->TabIndex = 40;
			this->allTimeLabel->Text = L"Îáùåå âðåìÿ ïðèãîòîâëåíèÿ";
			// 
			// allTimeTextBox
			// 
			this->allTimeTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->allTimeTextBox->Location = System::Drawing::Point(110, 592);
			this->allTimeTextBox->Name = L"allTimeTextBox";
			this->allTimeTextBox->Size = System::Drawing::Size(193, 20);
			this->allTimeTextBox->TabIndex = 41;
			// 
			// commentSearchLabel
			// 
			this->commentSearchLabel->AutoSize = true;
			this->commentSearchLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->commentSearchLabel->Location = System::Drawing::Point(106, 650);
			this->commentSearchLabel->Name = L"commentSearchLabel";
			this->commentSearchLabel->Size = System::Drawing::Size(197, 20);
			this->commentSearchLabel->TabIndex = 42;
			this->commentSearchLabel->Text = L"Ëè÷íûé êîììåíòàðèé ";
			// 
			// commentTextBox
			// 
			this->commentTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->commentTextBox->Location = System::Drawing::Point(110, 673);
			this->commentTextBox->Name = L"commentTextBox";
			this->commentTextBox->Size = System::Drawing::Size(193, 20);
			this->commentTextBox->TabIndex = 43;
			// 
			// currentRecipeStepLabel
			// 
			this->currentRecipeStepLabel->AutoSize = true;
			this->currentRecipeStepLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->currentRecipeStepLabel->Location = System::Drawing::Point(448, 54);
			this->currentRecipeStepLabel->Name = L"currentRecipeStepLabel";
			this->currentRecipeStepLabel->Size = System::Drawing::Size(454, 25);
			this->currentRecipeStepLabel->TabIndex = 50;
			this->currentRecipeStepLabel->Text = L"Èíñòðóêöèÿ ïî ïðèãîòîâëåíèþ ïî øàãàì";
			// 
			// currentStepLabel
			// 
			this->currentStepLabel->AutoSize = true;
			this->currentStepLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->currentStepLabel->Location = System::Drawing::Point(448, 102);
			this->currentStepLabel->Name = L"currentStepLabel";
			this->currentStepLabel->Size = System::Drawing::Size(180, 25);
			this->currentStepLabel->TabIndex = 53;
			this->currentStepLabel->Text = L"Øàã Undefinded";
			// 
			// stepEditTextBox
			// 
			this->stepEditTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->stepEditTextBox->Location = System::Drawing::Point(453, 145);
			this->stepEditTextBox->Name = L"stepEditTextBox";
			this->stepEditTextBox->Size = System::Drawing::Size(449, 502);
			this->stepEditTextBox->TabIndex = 57;
			this->stepEditTextBox->Text = L"Ââåäèòå òåêñò òåêóùåãî øàãà";
			// 
			// previousStepButton
			// 
			this->previousStepButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->previousStepButton->Location = System::Drawing::Point(453, 667);
			this->previousStepButton->Name = L"previousStepButton";
			this->previousStepButton->Size = System::Drawing::Size(200, 30);
			this->previousStepButton->TabIndex = 58;
			this->previousStepButton->Text = L"<< Ïðåäûäóùèé øàã";
			this->previousStepButton->UseVisualStyleBackColor = true;
			// 
			// nextStepButton
			// 
			this->nextStepButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->nextStepButton->Location = System::Drawing::Point(702, 667);
			this->nextStepButton->Name = L"nextStepButton";
			this->nextStepButton->Size = System::Drawing::Size(200, 30);
			this->nextStepButton->TabIndex = 60;
			this->nextStepButton->Text = L"Ñëåäóþùèé øàã >>";
			this->nextStepButton->UseVisualStyleBackColor = true;
			// 
			// finalButton
			// 
			this->finalButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->finalButton->Location = System::Drawing::Point(702, 102);
			this->finalButton->Name = L"finalButton";
			this->finalButton->Size = System::Drawing::Size(200, 25);
			this->finalButton->TabIndex = 61;
			this->finalButton->Text = L"Ñîõðàíèòü ðåöåïò";
			this->finalButton->UseVisualStyleBackColor = true;
			// 
			// NEWRECIPE
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->ClientSize = System::Drawing::Size(984, 861);
			this->Controls->Add(this->finalButton);
			this->Controls->Add(this->nextStepButton);
			this->Controls->Add(this->previousStepButton);
			this->Controls->Add(this->stepEditTextBox);
			this->Controls->Add(this->currentStepLabel);
			this->Controls->Add(this->currentRecipeStepLabel);
			this->Controls->Add(this->commentTextBox);
			this->Controls->Add(this->commentSearchLabel);
			this->Controls->Add(this->allTimeTextBox);
			this->Controls->Add(this->allTimeLabel);
			this->Controls->Add(this->cookingTimeTextBox);
			this->Controls->Add(this->cookingTimeLabel);
			this->Controls->Add(this->preparingTimeTextBox);
			this->Controls->Add(this->preparingTimeLabel);
			this->Controls->Add(this->ñaloriesTextBox);
			this->Controls->Add(this->caloriesLabel);
			this->Controls->Add(this->markTextBox);
			this->Controls->Add(this->markLabel);
			this->Controls->Add(this->ingridientsSearchTextBox);
			this->Controls->Add(this->ingridientLabel);
			this->Controls->Add(this->categoriesSearchTextBox);
			this->Controls->Add(this->categoriesLabel);
			this->Controls->Add(this->nameSearchTextBox);
			this->Controls->Add(this->createRecipeLabel);
			this->Controls->Add(this->dishNameSearchLabel);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"NEWRECIPE";
			this->Text = L"NEWRECIPE";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	};
}
