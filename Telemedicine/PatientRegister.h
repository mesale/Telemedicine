#pragma once

#include"patient.h"

namespace Telemedicine {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Data::SqlClient;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for PatientRegister
	/// </summary>
	public ref class PatientRegister : public System::Windows::Forms::Form
	{
	public:
		PatientRegister(void)
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
		~PatientRegister()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	protected:
	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel1;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::TextBox^ tbxPatientPhoneNumber;

	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::TextBox^ tbxPatientRegisterEmail;

	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::TextBox^ tbxPatientLastName;

	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ tbxPatientFirestName;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::TextBox^ tbxPatientRegisterPasswordConfirm;

	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::TextBox^ tbxPatientRegisterPassword;

	private: System::Windows::Forms::Label^ label7;

	private: System::Windows::Forms::LinkLabel^ llLogin;

	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel2;
	private: System::Windows::Forms::Button^ btnRegister;
	private: System::Windows::Forms::Button^ btnRegisterCancel;
	private: System::Windows::Forms::DateTimePicker^ dpkDateOfBirth;






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
			this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->tbxPatientRegisterPasswordConfirm = (gcnew System::Windows::Forms::TextBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->tbxPatientRegisterPassword = (gcnew System::Windows::Forms::TextBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->tbxPatientPhoneNumber = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->tbxPatientRegisterEmail = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->tbxPatientLastName = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->tbxPatientFirestName = (gcnew System::Windows::Forms::TextBox());
			this->dpkDateOfBirth = (gcnew System::Windows::Forms::DateTimePicker());
			this->llLogin = (gcnew System::Windows::Forms::LinkLabel());
			this->tableLayoutPanel2 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->btnRegisterCancel = (gcnew System::Windows::Forms::Button());
			this->btnRegister = (gcnew System::Windows::Forms::Button());
			this->tableLayoutPanel1->SuspendLayout();
			this->tableLayoutPanel2->SuspendLayout();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Calibri", 36, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(243, 44);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(232, 73);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Register";
			// 
			// tableLayoutPanel1
			// 
			this->tableLayoutPanel1->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->tableLayoutPanel1->ColumnCount = 2;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				39.63816F)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				60.36184F)));
			this->tableLayoutPanel1->Controls->Add(this->label9, 0, 6);
			this->tableLayoutPanel1->Controls->Add(this->tbxPatientRegisterPasswordConfirm, 1, 6);
			this->tableLayoutPanel1->Controls->Add(this->label8, 0, 5);
			this->tableLayoutPanel1->Controls->Add(this->tbxPatientRegisterPassword, 1, 5);
			this->tableLayoutPanel1->Controls->Add(this->label7, 0, 4);
			this->tableLayoutPanel1->Controls->Add(this->label6, 0, 3);
			this->tableLayoutPanel1->Controls->Add(this->tbxPatientPhoneNumber, 1, 3);
			this->tableLayoutPanel1->Controls->Add(this->label5, 0, 2);
			this->tableLayoutPanel1->Controls->Add(this->tbxPatientRegisterEmail, 1, 2);
			this->tableLayoutPanel1->Controls->Add(this->label4, 0, 1);
			this->tableLayoutPanel1->Controls->Add(this->tbxPatientLastName, 1, 1);
			this->tableLayoutPanel1->Controls->Add(this->label2, 0, 0);
			this->tableLayoutPanel1->Controls->Add(this->tbxPatientFirestName, 1, 0);
			this->tableLayoutPanel1->Controls->Add(this->dpkDateOfBirth, 1, 4);
			this->tableLayoutPanel1->Location = System::Drawing::Point(67, 153);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 7;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 14.28571F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 14.28571F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 14.28571F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 14.28571F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 14.28571F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 14.28571F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 14.28571F)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(608, 307);
			this->tableLayoutPanel1->TabIndex = 1;
			// 
			// label9
			// 
			this->label9->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->label9->Font = (gcnew System::Drawing::Font(L"Calibri", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label9->Location = System::Drawing::Point(3, 258);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(235, 49);
			this->label9->TabIndex = 0;
			this->label9->Text = L"Confirm Password";
			this->label9->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// tbxPatientRegisterPasswordConfirm
			// 
			this->tbxPatientRegisterPasswordConfirm->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
			this->tbxPatientRegisterPasswordConfirm->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->tbxPatientRegisterPasswordConfirm->Location = System::Drawing::Point(244, 266);
			this->tbxPatientRegisterPasswordConfirm->Name = L"tbxPatientRegisterPasswordConfirm";
			this->tbxPatientRegisterPasswordConfirm->Size = System::Drawing::Size(361, 32);
			this->tbxPatientRegisterPasswordConfirm->TabIndex = 1;
			// 
			// label8
			// 
			this->label8->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->label8->Font = (gcnew System::Drawing::Font(L"Calibri", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label8->Location = System::Drawing::Point(3, 215);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(235, 43);
			this->label8->TabIndex = 0;
			this->label8->Text = L"Password";
			this->label8->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// tbxPatientRegisterPassword
			// 
			this->tbxPatientRegisterPassword->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
			this->tbxPatientRegisterPassword->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->tbxPatientRegisterPassword->Location = System::Drawing::Point(244, 220);
			this->tbxPatientRegisterPassword->Name = L"tbxPatientRegisterPassword";
			this->tbxPatientRegisterPassword->Size = System::Drawing::Size(361, 32);
			this->tbxPatientRegisterPassword->TabIndex = 1;
			// 
			// label7
			// 
			this->label7->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->label7->Font = (gcnew System::Drawing::Font(L"Calibri", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label7->Location = System::Drawing::Point(3, 172);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(235, 43);
			this->label7->TabIndex = 0;
			this->label7->Text = L"Date of Birth";
			this->label7->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// label6
			// 
			this->label6->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->label6->Font = (gcnew System::Drawing::Font(L"Calibri", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label6->Location = System::Drawing::Point(3, 129);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(235, 43);
			this->label6->TabIndex = 0;
			this->label6->Text = L"Phone Number";
			this->label6->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// tbxPatientPhoneNumber
			// 
			this->tbxPatientPhoneNumber->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
			this->tbxPatientPhoneNumber->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->tbxPatientPhoneNumber->Location = System::Drawing::Point(244, 134);
			this->tbxPatientPhoneNumber->Name = L"tbxPatientPhoneNumber";
			this->tbxPatientPhoneNumber->Size = System::Drawing::Size(361, 32);
			this->tbxPatientPhoneNumber->TabIndex = 1;
			// 
			// label5
			// 
			this->label5->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->label5->Font = (gcnew System::Drawing::Font(L"Calibri", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->Location = System::Drawing::Point(3, 86);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(235, 43);
			this->label5->TabIndex = 0;
			this->label5->Text = L"Email";
			this->label5->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// tbxPatientRegisterEmail
			// 
			this->tbxPatientRegisterEmail->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
			this->tbxPatientRegisterEmail->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->tbxPatientRegisterEmail->Location = System::Drawing::Point(244, 91);
			this->tbxPatientRegisterEmail->Name = L"tbxPatientRegisterEmail";
			this->tbxPatientRegisterEmail->Size = System::Drawing::Size(361, 32);
			this->tbxPatientRegisterEmail->TabIndex = 1;
			// 
			// label4
			// 
			this->label4->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->label4->Font = (gcnew System::Drawing::Font(L"Calibri", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(3, 43);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(235, 43);
			this->label4->TabIndex = 0;
			this->label4->Text = L"Last Name";
			this->label4->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// tbxPatientLastName
			// 
			this->tbxPatientLastName->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
			this->tbxPatientLastName->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->tbxPatientLastName->Location = System::Drawing::Point(244, 48);
			this->tbxPatientLastName->Name = L"tbxPatientLastName";
			this->tbxPatientLastName->Size = System::Drawing::Size(361, 32);
			this->tbxPatientLastName->TabIndex = 1;
			// 
			// label2
			// 
			this->label2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->label2->Font = (gcnew System::Drawing::Font(L"Calibri", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(3, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(235, 43);
			this->label2->TabIndex = 0;
			this->label2->Text = L"First Name";
			this->label2->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// tbxPatientFirestName
			// 
			this->tbxPatientFirestName->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
			this->tbxPatientFirestName->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->tbxPatientFirestName->Location = System::Drawing::Point(244, 5);
			this->tbxPatientFirestName->Name = L"tbxPatientFirestName";
			this->tbxPatientFirestName->Size = System::Drawing::Size(361, 32);
			this->tbxPatientFirestName->TabIndex = 1;
			// 
			// dpkDateOfBirth
			// 
			this->dpkDateOfBirth->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
			this->dpkDateOfBirth->CustomFormat = L"yyyy-MM-dd ";
			this->dpkDateOfBirth->Format = System::Windows::Forms::DateTimePickerFormat::Custom;
			this->dpkDateOfBirth->Location = System::Drawing::Point(244, 182);
			this->dpkDateOfBirth->Name = L"dpkDateOfBirth";
			this->dpkDateOfBirth->Size = System::Drawing::Size(361, 22);
			this->dpkDateOfBirth->TabIndex = 2;
			// 
			// llLogin
			// 
			this->llLogin->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->llLogin->AutoSize = true;
			this->llLogin->Font = (gcnew System::Drawing::Font(L"Calibri", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->llLogin->Location = System::Drawing::Point(592, 612);
			this->llLogin->Name = L"llLogin";
			this->llLogin->Size = System::Drawing::Size(77, 35);
			this->llLogin->TabIndex = 2;
			this->llLogin->TabStop = true;
			this->llLogin->Text = L"Login";
			this->llLogin->LinkClicked += gcnew System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, &PatientRegister::llLogin_LinkClicked);
			// 
			// tableLayoutPanel2
			// 
			this->tableLayoutPanel2->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->tableLayoutPanel2->ColumnCount = 2;
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel2->Controls->Add(this->btnRegisterCancel, 1, 0);
			this->tableLayoutPanel2->Controls->Add(this->btnRegister, 0, 0);
			this->tableLayoutPanel2->Location = System::Drawing::Point(64, 513);
			this->tableLayoutPanel2->Name = L"tableLayoutPanel2";
			this->tableLayoutPanel2->RowCount = 1;
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel2->Size = System::Drawing::Size(608, 55);
			this->tableLayoutPanel2->TabIndex = 3;
			// 
			// btnRegisterCancel
			// 
			this->btnRegisterCancel->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->btnRegisterCancel->Font = (gcnew System::Drawing::Font(L"Calibri", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnRegisterCancel->Location = System::Drawing::Point(307, 3);
			this->btnRegisterCancel->Name = L"btnRegisterCancel";
			this->btnRegisterCancel->Size = System::Drawing::Size(298, 49);
			this->btnRegisterCancel->TabIndex = 1;
			this->btnRegisterCancel->Text = L"Cancel";
			this->btnRegisterCancel->UseVisualStyleBackColor = true;
			this->btnRegisterCancel->Click += gcnew System::EventHandler(this, &PatientRegister::btnRegisterCancel_Click);
			// 
			// btnRegister
			// 
			this->btnRegister->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->btnRegister->Font = (gcnew System::Drawing::Font(L"Calibri", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnRegister->Location = System::Drawing::Point(3, 3);
			this->btnRegister->Name = L"btnRegister";
			this->btnRegister->Size = System::Drawing::Size(298, 49);
			this->btnRegister->TabIndex = 0;
			this->btnRegister->Text = L"Register";
			this->btnRegister->UseVisualStyleBackColor = true;
			this->btnRegister->Click += gcnew System::EventHandler(this, &PatientRegister::btnRegister_Click);
			// 
			// PatientRegister
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::LightSeaGreen;
			this->ClientSize = System::Drawing::Size(718, 686);
			this->Controls->Add(this->tableLayoutPanel2);
			this->Controls->Add(this->llLogin);
			this->Controls->Add(this->tableLayoutPanel1);
			this->Controls->Add(this->label1);
			this->MinimumSize = System::Drawing::Size(736, 733);
			this->Name = L"PatientRegister";
			this->Text = L"PatientRegister";
			this->tableLayoutPanel1->ResumeLayout(false);
			this->tableLayoutPanel1->PerformLayout();
			this->tableLayoutPanel2->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void btnRegisterCancel_Click(System::Object^ sender, System::EventArgs^ e) {
		this, Close();
	}
	public: Patient^ patient = nullptr;
	private: System::Void btnRegister_Click(System::Object^ sender, System::EventArgs^ e) {
		patient = gcnew Patient;
		patient->patientFirstName = this->tbxPatientFirestName->Text;
		patient->patientLastName = this->tbxPatientLastName->Text;
		patient->patientEmail = this->tbxPatientRegisterEmail->Text;
		patient->patientPassword = this->tbxPatientRegisterPassword->Text;
		patient->patientPhone = this->tbxPatientPhoneNumber->Text;
		patient->patientDateOfBirth = this->dpkDateOfBirth->Text;

		if (!patient->patientFirstName || !patient->patientLastName || !patient->patientEmail || !patient->patientPassword || !patient->patientPhone) {
			MessageBox::Show("Please fill out all forms",
				"Missing information", MessageBoxButtons::OK);
			return;
		}
		if (String::Compare(patient->patientPassword, this->tbxPatientRegisterPasswordConfirm->Text) != 0) {
			MessageBox::Show("Password and Confirm password doesn't match",
				"Password mismatch", MessageBoxButtons::OK);
			return;
		}
		try {
			String^ connString = "Data Source=localhost\\sqlexpress;Initial Catalog=test;Integrated Security=True;Encrypt=True;TrustServerCertificate=True";
			SqlConnection sqlConn(connString);
			sqlConn.Open();

			String^ sqlQuery = "INSERT INTO patient (first_name, last_name, email, phone, password_hash, date_of_birth) VALUES (@firstName, @lastName, @email, @phone, @password, @dateOfBirth);";
			SqlCommand command(sqlQuery, % sqlConn);
			command.Parameters->AddWithValue("@firstName", patient->patientFirstName);
			command.Parameters->AddWithValue("@lastName", patient->patientLastName);
			command.Parameters->AddWithValue("@email", patient->patientEmail);
			command.Parameters->AddWithValue("@phone", patient->patientPhone);
			command.Parameters->AddWithValue("@password", patient->patientPassword);
			command.Parameters->AddWithValue("@dateOfBirth", patient->patientDateOfBirth);
			int rowsAffected = command.ExecuteNonQuery();
			if (rowsAffected > 0) {
				MessageBox::Show("Registration successful!",
					"Registered", MessageBoxButtons::OK);
				this->Close();
			}
			else {
				MessageBox::Show("Registration unsuccessful",
					"Failed to register", MessageBoxButtons::OK);
			}
			String^ sqlQuery2 = "SELECT patient_id FROM patient WHERE email=@email AND password_hash=@pwd;";
			SqlCommand command2(sqlQuery2, % sqlConn);
			command2.Parameters->AddWithValue("@email", patient->patientEmail);
			command2.Parameters->AddWithValue("@pwd", patient->patientPassword);

			SqlDataReader^ reader = command2.ExecuteReader();

			if (reader->Read()) {
				patient->patientId = reader->GetInt32(0);

				this->DialogResult = System::Windows::Forms::DialogResult::OK;
					this->Close();
			}
			sqlConn.Close();
			this->Close();
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

	public: bool switchToLogin = false;

	private: System::Void llLogin_LinkClicked(System::Object^ sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^ e) {
		this->switchToLogin = true;
		this->Close();
	}
};
}
