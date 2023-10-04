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
	protected:
	private: System::Windows::Forms::TextBox^ searchTextBox;
	private: System::Windows::Forms::CheckBox^ foodCategoryCheckBox;
	private: System::Windows::Forms::Label^ categoryLabel;

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
			this->searchTextBox = (gcnew System::Windows::Forms::TextBox());
			this->foodCategoryCheckBox = (gcnew System::Windows::Forms::CheckBox());
			this->categoryLabel = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// searchLabel
			// 
			this->searchLabel->AutoSize = true;
			this->searchLabel->Font = (gcnew System::Drawing::Font(L"Aqum two", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->searchLabel->Location = System::Drawing::Point(13, 9);
			this->searchLabel->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->searchLabel->Name = L"searchLabel";
			this->searchLabel->Size = System::Drawing::Size(251, 37);
			this->searchLabel->TabIndex = 0;
			this->searchLabel->Text = L"Поиск рецептов";
			// 
			// searchTextBox
			// 
			this->searchTextBox->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->searchTextBox->Font = (gcnew System::Drawing::Font(L"Aqum two", 9.749998F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->searchTextBox->ForeColor = System::Drawing::SystemColors::MenuText;
			this->searchTextBox->Location = System::Drawing::Point(14, 57);
			this->searchTextBox->Margin = System::Windows::Forms::Padding(4, 3, 4, 3);
			this->searchTextBox->Name = L"searchTextBox";
			this->searchTextBox->Size = System::Drawing::Size(250, 25);
			this->searchTextBox->TabIndex = 1;
			// 
			// foodCategoryCheckBox
			// 
			this->foodCategoryCheckBox->AutoSize = true;
			this->foodCategoryCheckBox->Location = System::Drawing::Point(12, 130);
			this->foodCategoryCheckBox->Margin = System::Windows::Forms::Padding(4, 3, 4, 3);
			this->foodCategoryCheckBox->Name = L"foodCategoryCheckBox";
			this->foodCategoryCheckBox->Size = System::Drawing::Size(57, 19);
			this->foodCategoryCheckBox->TabIndex = 2;
			this->foodCategoryCheckBox->Text = L"Мяса";
			this->foodCategoryCheckBox->UseVisualStyleBackColor = true;
			// 
			// categoryLabel
			// 
			this->categoryLabel->AutoSize = true;
			this->categoryLabel->Font = (gcnew System::Drawing::Font(L"Aqum two", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->categoryLabel->Location = System::Drawing::Point(12, 96);
			this->categoryLabel->Name = L"categoryLabel";
			this->categoryLabel->Size = System::Drawing::Size(97, 22);
			this->categoryLabel->TabIndex = 3;
			this->categoryLabel->Text = L"Категории";
			// 
			// GRAPHICS
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(7, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->ClientSize = System::Drawing::Size(1148, 1061);
			this->Controls->Add(this->categoryLabel);
			this->Controls->Add(this->foodCategoryCheckBox);
			this->Controls->Add(this->searchTextBox);
			this->Controls->Add(this->searchLabel);
			this->Font = (gcnew System::Drawing::Font(L"Aqum two", 8.249999F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Margin = System::Windows::Forms::Padding(4, 3, 4, 3);
			this->Name = L"GRAPHICS";
			this->Text = L"GRAPHICS";
			this->Load += gcnew System::EventHandler(this, &GRAPHICS::GRAPHICS_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void GRAPHICS_Load(System::Object^ sender, System::EventArgs^ e);
	};
}
