#pragma once
#include"Patient.h"
namespace Telemedicine {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Data::SqlClient;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for PatientMedicalRecord
	/// </summary>
	public ref class PatientMedicalRecord : public System::Windows::Forms::Form
	{
	public:
		Patient^ patient = nullptr;
		PatientMedicalRecord(Patient^ patient)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			this->CenterToScreen();
			this->patient = patient;
			try {
				String^ connString = "Data Source=localhost\\sqlexpress;Initial Catalog=test;Integrated Security=True;Encrypt=True;TrustServerCertificate=True";
				SqlConnection sqlConn(connString);
				sqlConn.Open();

				String^ sqlQuery = "SELECT mr.diagnosis, pr.medication_name, pr.dosage, pr.instructions, pr.refills "
					"FROM patient p "
					"JOIN appointment a ON p.patient_id = a.patient_id "
					"JOIN medical_record mr ON a.appointment_id = mr.appointment_id "
					"JOIN prescription pr ON mr.record_id = pr.record_id "
					"WHERE p.patient_id = @patientId "
					"ORDER BY a.scheduled_time DESC";

				SqlCommand command(sqlQuery, % sqlConn);
				command.Parameters->AddWithValue("@patientId", patient->patientId);

				SqlDataReader^ reader = command.ExecuteReader();

				while (reader->Read()) {
					// Get each field with proper null checking
					String^ diagnosis = reader->IsDBNull(0) ? String::Empty : reader->GetString(0);
					String^ medication = reader->IsDBNull(1) ? String::Empty : reader->GetString(1);
					String^ dosage = reader->IsDBNull(2) ? String::Empty : reader->GetString(2);
					String^ instructions = reader->IsDBNull(3) ? String::Empty : reader->GetString(3);
					int refills = reader->IsDBNull(4) ? 0 : reader->GetInt32(4);

					// Use the data (example: add to ListView or display)
					// listView1->Items->Add(diagnosis); // etc.
					this->lbDiagnosis->Text = diagnosis;
					this->lbMedicationName->Text = medication;
					this->lbDosage->Text = dosage;
					this->lbInstructions->Text = instructions;
					this->lbRefills->Text = refills.ToString();
				}
				reader->Close();
				sqlConn.Close();
			}
			catch (SqlException^ sqlEx) {
				MessageBox::Show("Database error: " + sqlEx->Message);
			}
			catch (Exception^ ex) {
				MessageBox::Show("Error: " + ex->Message);
			}
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~PatientMedicalRecord()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	protected:
	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ lbDiagnosis;

	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ lbRefills;

	private: System::Windows::Forms::Label^ label11;
	private: System::Windows::Forms::Label^ lbInstructions;

	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::Label^ lbDosage;

	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ lbMedicationName;


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
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->lbRefills = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->lbInstructions = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->lbDosage = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->lbMedicationName = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->lbDiagnosis = (gcnew System::Windows::Forms::Label());
			this->tableLayoutPanel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Calibri", 36, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(294, 101);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(417, 73);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Medical Record";
			// 
			// tableLayoutPanel1
			// 
			this->tableLayoutPanel1->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->tableLayoutPanel1->ColumnCount = 2;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				28.30626F)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				71.69373F)));
			this->tableLayoutPanel1->Controls->Add(this->label5, 0, 4);
			this->tableLayoutPanel1->Controls->Add(this->lbRefills, 1, 4);
			this->tableLayoutPanel1->Controls->Add(this->label11, 0, 3);
			this->tableLayoutPanel1->Controls->Add(this->lbInstructions, 1, 3);
			this->tableLayoutPanel1->Controls->Add(this->label9, 0, 2);
			this->tableLayoutPanel1->Controls->Add(this->lbDosage, 1, 2);
			this->tableLayoutPanel1->Controls->Add(this->label7, 0, 1);
			this->tableLayoutPanel1->Controls->Add(this->lbMedicationName, 1, 1);
			this->tableLayoutPanel1->Controls->Add(this->label2, 0, 0);
			this->tableLayoutPanel1->Controls->Add(this->lbDiagnosis, 1, 0);
			this->tableLayoutPanel1->Location = System::Drawing::Point(71, 253);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 5;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 20)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 20)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 20)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 20)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 20)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(862, 424);
			this->tableLayoutPanel1->TabIndex = 1;
			// 
			// label5
			// 
			this->label5->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->label5->Font = (gcnew System::Drawing::Font(L"Calibri", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->Location = System::Drawing::Point(3, 336);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(238, 88);
			this->label5->TabIndex = 0;
			this->label5->Text = L"Refills";
			this->label5->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// lbRefills
			// 
			this->lbRefills->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->lbRefills->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbRefills->Location = System::Drawing::Point(247, 336);
			this->lbRefills->Name = L"lbRefills";
			this->lbRefills->Size = System::Drawing::Size(612, 88);
			this->lbRefills->TabIndex = 1;
			this->lbRefills->Text = L"refills";
			this->lbRefills->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// label11
			// 
			this->label11->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->label11->Font = (gcnew System::Drawing::Font(L"Calibri", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label11->Location = System::Drawing::Point(3, 252);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(238, 84);
			this->label11->TabIndex = 0;
			this->label11->Text = L"Instructions";
			this->label11->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// lbInstructions
			// 
			this->lbInstructions->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->lbInstructions->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbInstructions->Location = System::Drawing::Point(247, 252);
			this->lbInstructions->Name = L"lbInstructions";
			this->lbInstructions->Size = System::Drawing::Size(612, 84);
			this->lbInstructions->TabIndex = 1;
			this->lbInstructions->Text = L"instructions";
			this->lbInstructions->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// label9
			// 
			this->label9->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->label9->Font = (gcnew System::Drawing::Font(L"Calibri", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label9->Location = System::Drawing::Point(3, 168);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(238, 84);
			this->label9->TabIndex = 0;
			this->label9->Text = L"Dosage";
			this->label9->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// lbDosage
			// 
			this->lbDosage->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->lbDosage->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbDosage->Location = System::Drawing::Point(247, 168);
			this->lbDosage->Name = L"lbDosage";
			this->lbDosage->Size = System::Drawing::Size(612, 84);
			this->lbDosage->TabIndex = 1;
			this->lbDosage->Text = L"dosage";
			this->lbDosage->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// label7
			// 
			this->label7->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->label7->Font = (gcnew System::Drawing::Font(L"Calibri", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label7->Location = System::Drawing::Point(3, 84);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(238, 84);
			this->label7->TabIndex = 0;
			this->label7->Text = L"Medication Name";
			this->label7->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// lbMedicationName
			// 
			this->lbMedicationName->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->lbMedicationName->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbMedicationName->Location = System::Drawing::Point(247, 84);
			this->lbMedicationName->Name = L"lbMedicationName";
			this->lbMedicationName->Size = System::Drawing::Size(612, 84);
			this->lbMedicationName->TabIndex = 1;
			this->lbMedicationName->Text = L"medication name";
			this->lbMedicationName->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
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
			this->label2->Size = System::Drawing::Size(238, 84);
			this->label2->TabIndex = 0;
			this->label2->Text = L"Diagnosis";
			this->label2->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// lbDiagnosis
			// 
			this->lbDiagnosis->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->lbDiagnosis->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbDiagnosis->Location = System::Drawing::Point(247, 0);
			this->lbDiagnosis->Name = L"lbDiagnosis";
			this->lbDiagnosis->Size = System::Drawing::Size(612, 84);
			this->lbDiagnosis->TabIndex = 1;
			this->lbDiagnosis->Text = L"diagnosis";
			this->lbDiagnosis->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// PatientMedicalRecord
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(987, 797);
			this->Controls->Add(this->tableLayoutPanel1);
			this->Controls->Add(this->label1);
			this->MinimumSize = System::Drawing::Size(1005, 844);
			this->Name = L"PatientMedicalRecord";
			this->Text = L"PatientMedicalRecord";
			this->tableLayoutPanel1->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	
};
}
