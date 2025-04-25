#pragma once
#include "Patient.h"
namespace Telemedicine {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Data::SqlClient;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for PatientLogin
	/// </summary>
	public ref class PatientLogin : public System::Windows::Forms::Form
	{
	public:
		PatientLogin(void)
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
		~PatientLogin()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	protected:
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ tbxPatientEmail;
	private: System::Windows::Forms::TextBox^ tbxPatientPassword;


	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel1;
	private: System::Windows::Forms::Button^ btnPatientLogin;

	private: System::Windows::Forms::Button^ btnPatientCancel;
	private: System::Windows::Forms::LinkLabel^ llRegister;



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
			this->tbxPatientEmail = (gcnew System::Windows::Forms::TextBox());
			this->tbxPatientPassword = (gcnew System::Windows::Forms::TextBox());
			this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->btnPatientLogin = (gcnew System::Windows::Forms::Button());
			this->btnPatientCancel = (gcnew System::Windows::Forms::Button());
			this->llRegister = (gcnew System::Windows::Forms::LinkLabel());
			this->tableLayoutPanel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Calibri", 36, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(168, 29);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(164, 73);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Login";
			// 
			// label2
			// 
			this->label2->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Calibri", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(59, 161);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(80, 35);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Email";
			// 
			// label3
			// 
			this->label3->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Calibri", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(59, 289);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(126, 35);
			this->label3->TabIndex = 2;
			this->label3->Text = L"Password";
			// 
			// tbxPatientEmail
			// 
			this->tbxPatientEmail->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->tbxPatientEmail->Font = (gcnew System::Drawing::Font(L"Calibri", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->tbxPatientEmail->Location = System::Drawing::Point(99, 216);
			this->tbxPatientEmail->Name = L"tbxPatientEmail";
			this->tbxPatientEmail->Size = System::Drawing::Size(309, 36);
			this->tbxPatientEmail->TabIndex = 3;
			// 
			// tbxPatientPassword
			// 
			this->tbxPatientPassword->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->tbxPatientPassword->Font = (gcnew System::Drawing::Font(L"Calibri", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->tbxPatientPassword->Location = System::Drawing::Point(99, 343);
			this->tbxPatientPassword->Name = L"tbxPatientPassword";
			this->tbxPatientPassword->PasswordChar = '*';
			this->tbxPatientPassword->Size = System::Drawing::Size(309, 36);
			this->tbxPatientPassword->TabIndex = 4;
			// 
			// tableLayoutPanel1
			// 
			this->tableLayoutPanel1->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->tableLayoutPanel1->ColumnCount = 2;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel1->Controls->Add(this->btnPatientLogin, 0, 0);
			this->tableLayoutPanel1->Controls->Add(this->btnPatientCancel, 1, 0);
			this->tableLayoutPanel1->Location = System::Drawing::Point(99, 403);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 1;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(309, 55);
			this->tableLayoutPanel1->TabIndex = 5;
			// 
			// btnPatientLogin
			// 
			this->btnPatientLogin->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->btnPatientLogin->Font = (gcnew System::Drawing::Font(L"Calibri", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnPatientLogin->Location = System::Drawing::Point(3, 3);
			this->btnPatientLogin->Name = L"btnPatientLogin";
			this->btnPatientLogin->Size = System::Drawing::Size(148, 49);
			this->btnPatientLogin->TabIndex = 0;
			this->btnPatientLogin->Text = L"Login";
			this->btnPatientLogin->UseVisualStyleBackColor = true;
			this->btnPatientLogin->Click += gcnew System::EventHandler(this, &PatientLogin::btnPatientLogin_Click);
			// 
			// btnPatientCancel
			// 
			this->btnPatientCancel->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->btnPatientCancel->Font = (gcnew System::Drawing::Font(L"Calibri", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnPatientCancel->Location = System::Drawing::Point(157, 3);
			this->btnPatientCancel->Name = L"btnPatientCancel";
			this->btnPatientCancel->Size = System::Drawing::Size(149, 49);
			this->btnPatientCancel->TabIndex = 1;
			this->btnPatientCancel->Text = L"Clear";
			this->btnPatientCancel->UseVisualStyleBackColor = true;
			this->btnPatientCancel->Click += gcnew System::EventHandler(this, &PatientLogin::btnPatientCancel_Click);
			// 
			// llRegister
			// 
			this->llRegister->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->llRegister->AutoSize = true;
			this->llRegister->Font = (gcnew System::Drawing::Font(L"Calibri", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->llRegister->Location = System::Drawing::Point(387, 476);
			this->llRegister->Name = L"llRegister";
			this->llRegister->Size = System::Drawing::Size(110, 35);
			this->llRegister->TabIndex = 6;
			this->llRegister->TabStop = true;
			this->llRegister->Text = L"Register";
			this->llRegister->LinkClicked += gcnew System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, &PatientLogin::llRegister_LinkClicked);
			// 
			// PatientLogin
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::LightSeaGreen;
			this->ClientSize = System::Drawing::Size(509, 554);
			this->Controls->Add(this->llRegister);
			this->Controls->Add(this->tableLayoutPanel1);
			this->Controls->Add(this->tbxPatientPassword);
			this->Controls->Add(this->tbxPatientEmail);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->MinimumSize = System::Drawing::Size(527, 601);
			this->Name = L"PatientLogin";
			this->Text = L"PatientLogin";
			this->tableLayoutPanel1->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void btnPatientCancel_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}

	public: Patient^ patient = nullptr;

	private: System::Void btnPatientLogin_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ email = this->tbxPatientEmail->Text;
		String^ password = this->tbxPatientPassword->Text;

		if (email->Length == 0 || password->Length == 0) {
			MessageBox::Show("Please enter email and password ",
				"Email or password error", MessageBoxButtons::OK);
			return;
		}
		try
		{
			String^ connString = "Data Source=localhost\\sqlexpress;Initial Catalog=test;Integrated Security=True;Encrypt=True;TrustServerCertificate=True";
			SqlConnection sqlConn(connString);
			sqlConn.Open();

			// Never store/compare plain text passwords! Use parameterized hashed comparison
			String^ sqlQuery = "SELECT patient_id, first_name, last_name, email, phone, date_of_birth FROM patient WHERE email=@email AND password_hash=@pwd;";
			SqlCommand command(sqlQuery, % sqlConn);
			command.Parameters->AddWithValue("@email", email);
			command.Parameters->AddWithValue("@pwd", password);

			SqlDataReader^ reader = command.ExecuteReader();

			if (reader->Read()) {
				patient = gcnew Patient;
				patient->patientId = reader->GetInt32(0);
				patient->patientFirstName = reader->GetString(1);
				patient->patientLastName = reader->GetString(2);
				patient->patientEmail = reader->GetString(3);
				patient->patientPhone = reader->GetString(4);
				patient->patientDateOfBirth = (reader->GetDateTime(5)).ToString();

				this->DialogResult = System::Windows::Forms::DialogResult::OK;
				this->Close();
			}
			else {
				MessageBox::Show("Incorrect email or password",
					"Authentication Failed", MessageBoxButtons::OK);
			}
			reader->Close(); // Always close the reader
		}
		catch (SqlException^ sqlEx)
		{
			MessageBox::Show(String::Format("Database error: {0}", sqlEx->Message),
				"Database Error", MessageBoxButtons::OK);
		}
		catch (Exception^ ex)
		{
			MessageBox::Show(String::Format("Error: {0}", ex->Message),
				"Error", MessageBoxButtons::OK);
		}
	}
	public: bool switchToRegister = false;
	private: System::Void llRegister_LinkClicked(System::Object^ sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^ e) {
		this->switchToRegister = true;
		this->Close();
	}
};
}
