#pragma once
#include "Doctor.h"

namespace Telemedicine {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Data::SqlClient;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for DoctorLogin
	/// </summary>
	public ref class DoctorLogin : public System::Windows::Forms::Form
	{
	public:
		DoctorLogin(void)
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
		~DoctorLogin()
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
	private: System::Windows::Forms::TextBox^ tbxDoctorEmail;
	private: System::Windows::Forms::TextBox^ tbxDoctorPassword;
	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel1;
	private: System::Windows::Forms::Button^ btnDoctorLogin;
	private: System::Windows::Forms::Button^ btnDoctorCancel;



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
			this->tbxDoctorEmail = (gcnew System::Windows::Forms::TextBox());
			this->tbxDoctorPassword = (gcnew System::Windows::Forms::TextBox());
			this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->btnDoctorCancel = (gcnew System::Windows::Forms::Button());
			this->btnDoctorLogin = (gcnew System::Windows::Forms::Button());
			this->tableLayoutPanel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Calibri", 36, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(174, 37);
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
			this->label2->Location = System::Drawing::Point(71, 185);
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
			this->label3->Location = System::Drawing::Point(71, 315);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(126, 35);
			this->label3->TabIndex = 2;
			this->label3->Text = L"Password";
			// 
			// tbxDoctorEmail
			// 
			this->tbxDoctorEmail->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->tbxDoctorEmail->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->tbxDoctorEmail->Location = System::Drawing::Point(98, 236);
			this->tbxDoctorEmail->Name = L"tbxDoctorEmail";
			this->tbxDoctorEmail->Size = System::Drawing::Size(367, 32);
			this->tbxDoctorEmail->TabIndex = 3;
			// 
			// tbxDoctorPassword
			// 
			this->tbxDoctorPassword->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->tbxDoctorPassword->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->tbxDoctorPassword->Location = System::Drawing::Point(95, 366);
			this->tbxDoctorPassword->Name = L"tbxDoctorPassword";
			this->tbxDoctorPassword->PasswordChar = '*';
			this->tbxDoctorPassword->Size = System::Drawing::Size(367, 32);
			this->tbxDoctorPassword->TabIndex = 4;
			// 
			// tableLayoutPanel1
			// 
			this->tableLayoutPanel1->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->tableLayoutPanel1->ColumnCount = 2;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel1->Controls->Add(this->btnDoctorCancel, 1, 0);
			this->tableLayoutPanel1->Controls->Add(this->btnDoctorLogin, 0, 0);
			this->tableLayoutPanel1->Location = System::Drawing::Point(95, 441);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 1;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(367, 63);
			this->tableLayoutPanel1->TabIndex = 5;
			// 
			// btnDoctorCancel
			// 
			this->btnDoctorCancel->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->btnDoctorCancel->Font = (gcnew System::Drawing::Font(L"Calibri", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnDoctorCancel->Location = System::Drawing::Point(186, 3);
			this->btnDoctorCancel->Name = L"btnDoctorCancel";
			this->btnDoctorCancel->Size = System::Drawing::Size(178, 57);
			this->btnDoctorCancel->TabIndex = 1;
			this->btnDoctorCancel->Text = L"Cancel";
			this->btnDoctorCancel->UseVisualStyleBackColor = true;
			this->btnDoctorCancel->Click += gcnew System::EventHandler(this, &DoctorLogin::btnDoctorCancel_Click);
			// 
			// btnDoctorLogin
			// 
			this->btnDoctorLogin->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->btnDoctorLogin->Font = (gcnew System::Drawing::Font(L"Calibri", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnDoctorLogin->Location = System::Drawing::Point(3, 3);
			this->btnDoctorLogin->Name = L"btnDoctorLogin";
			this->btnDoctorLogin->Size = System::Drawing::Size(177, 57);
			this->btnDoctorLogin->TabIndex = 0;
			this->btnDoctorLogin->Text = L"Login";
			this->btnDoctorLogin->UseVisualStyleBackColor = true;
			this->btnDoctorLogin->Click += gcnew System::EventHandler(this, &DoctorLogin::btnDoctorLogin_Click);
			// 
			// DoctorLogin
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Red;
			this->ClientSize = System::Drawing::Size(548, 558);
			this->Controls->Add(this->tableLayoutPanel1);
			this->Controls->Add(this->tbxDoctorPassword);
			this->Controls->Add(this->tbxDoctorEmail);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->MinimumSize = System::Drawing::Size(566, 605);
			this->Name = L"DoctorLogin";
			this->Text = L"DoctorLogin";
			this->tableLayoutPanel1->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void btnDoctorCancel_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}

	public: Doctor^ doctor = nullptr;
	private: System::Void btnDoctorLogin_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ email = this->tbxDoctorEmail->Text;
		String^ password = this->tbxDoctorPassword->Text;
		if (email->Length == 0 || password->Length == 0) {
			MessageBox::Show("Pleaseenter email and password",
				"Email or Passwprd Missing", MessageBoxButtons::OK);
			return;
		}
		try
		{
			String^ connString = "Data Source=localhost\\sqlexpress;Initial Catalog=test;Integrated Security=True;Encrypt=True;TrustServerCertificate=True";
			SqlConnection sqlConn(connString);
			sqlConn.Open();

			// Never store/compare plain text passwords! Use parameterized hashed comparison
			String^ sqlQuery = "SELECT doctor_id, first_name, last_name, email, date_of_birth, phone, specialization FROM doctor WHERE email=@email AND password_hash=@pwd;";
			SqlCommand command(sqlQuery, % sqlConn);
			command.Parameters->AddWithValue("@email", email);
			command.Parameters->AddWithValue("@pwd", password);

			SqlDataReader^ reader = command.ExecuteReader();

			if (reader->Read()) {
				doctor = gcnew Doctor;
				doctor->id = reader->GetInt32(0);
				doctor->doctorFirstName = reader->GetString(1);
				doctor->doctorLastName = reader->GetString(2);
				doctor->doctorEmail = reader->GetString(3);
				doctor->doctorDateOfBirth = (reader->GetDateTime(4)).ToString();
				doctor->doctorPhone = reader->GetString(5);
				doctor->specialization = reader->GetString(6);
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
};
}
