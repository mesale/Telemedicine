#pragma once

namespace Telemedicine {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MainMenu : public System::Windows::Forms::Form
	{
	public:
		MainMenu(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			this->CenterToScreen();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MainMenu()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel1;
	private: System::Windows::Forms::Button^ lbMainMenuDoctor;

	private: System::Windows::Forms::Button^ lbMainMenuPatient;

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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->lbMainMenuDoctor = (gcnew System::Windows::Forms::Button());
			this->lbMainMenuPatient = (gcnew System::Windows::Forms::Button());
			this->tableLayoutPanel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label1->Font = (gcnew System::Drawing::Font(L"Calibri", 36, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(136, 71);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(294, 72);
			this->label1->TabIndex = 0;
			this->label1->Text = L"WELCOME";
			// 
			// label2
			// 
			this->label2->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Calibri", 22.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(79, 185);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(450, 45);
			this->label2->TabIndex = 1;
			this->label2->Text = L"To The Telemedicine System";
			// 
			// label3
			// 
			this->label3->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Calibri", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(218, 366);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(105, 35);
			this->label3->TabIndex = 2;
			this->label3->Text = L"Are You";
			// 
			// tableLayoutPanel1
			// 
			this->tableLayoutPanel1->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->tableLayoutPanel1->ColumnCount = 3;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				43.97394F)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				12.05212F)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				43.97394F)));
			this->tableLayoutPanel1->Controls->Add(this->lbMainMenuDoctor, 0, 0);
			this->tableLayoutPanel1->Controls->Add(this->lbMainMenuPatient, 2, 0);
			this->tableLayoutPanel1->Location = System::Drawing::Point(131, 423);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 1;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(277, 61);
			this->tableLayoutPanel1->TabIndex = 3;
			// 
			// lbMainMenuDoctor
			// 
			this->lbMainMenuDoctor->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->lbMainMenuDoctor->Font = (gcnew System::Drawing::Font(L"Calibri", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbMainMenuDoctor->Location = System::Drawing::Point(3, 3);
			this->lbMainMenuDoctor->Name = L"lbMainMenuDoctor";
			this->lbMainMenuDoctor->Size = System::Drawing::Size(115, 55);
			this->lbMainMenuDoctor->TabIndex = 0;
			this->lbMainMenuDoctor->TabStop = false;
			this->lbMainMenuDoctor->Text = L"Doctor";
			this->lbMainMenuDoctor->UseVisualStyleBackColor = true;
			this->lbMainMenuDoctor->Click += gcnew System::EventHandler(this, &MainMenu::button1_Click);
			// 
			// lbMainMenuPatient
			// 
			this->lbMainMenuPatient->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->lbMainMenuPatient->Font = (gcnew System::Drawing::Font(L"Calibri", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbMainMenuPatient->Location = System::Drawing::Point(157, 3);
			this->lbMainMenuPatient->Name = L"lbMainMenuPatient";
			this->lbMainMenuPatient->Size = System::Drawing::Size(117, 55);
			this->lbMainMenuPatient->TabIndex = 1;
			this->lbMainMenuPatient->TabStop = false;
			this->lbMainMenuPatient->Text = L"Patient";
			this->lbMainMenuPatient->UseVisualStyleBackColor = true;
			this->lbMainMenuPatient->Click += gcnew System::EventHandler(this, &MainMenu::button2_Click);
			// 
			// MainMenu
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(17, 31);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::LemonChiffon;
			this->ClientSize = System::Drawing::Size(551, 579);
			this->Controls->Add(this->tableLayoutPanel1);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Margin = System::Windows::Forms::Padding(6);
			this->MinimumSize = System::Drawing::Size(569, 626);
			this->Name = L"MainMenu";
			this->Text = L"MyForm";
			this->tableLayoutPanel1->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	public: bool isDoctor = false;

	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		this->isDoctor = true;
		this->Close();
	}

	public: bool isPatient = false;

	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		this->isPatient = true;
		this->Close();
	}
};
}
