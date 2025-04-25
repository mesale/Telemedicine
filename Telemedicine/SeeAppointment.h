#pragma once
#include"Patient.h"
#include"PatientDashboard.h"
#include"Doctor.h"
namespace Telemedicine {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Data::SqlClient;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for SeeAppointment
	/// </summary>
	public ref class SeeAppointment : public System::Windows::Forms::Form
	{
	public:
		Patient^ patient;
		Doctor^ doctor = nullptr;
		SeeAppointment(Patient^ patient)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			this->lbDoctorName->Text = "";
			this->lbScheduledTime->Text = "";
			this->lbDurationMinutes->Text = "";
			this->lbStatus->Text = "";
			this->patient = patient;
			  try {
				  String^ connString = "Data Source=localhost\\sqlexpress;Initial Catalog=test;Integrated Security=True;Encrypt=True;TrustServerCertificate=True";
				  SqlConnection sqlConn(connString);
				  sqlConn.Open();

				  String^ sqlQuery = "SELECT doctor_id, scheduled_time, duration_minutes, status FROM appointment WHERE patient_id = @patientId;";
				  SqlCommand command(sqlQuery, % sqlConn);
				  command.Parameters->AddWithValue("@patientId", patient->patientId);

				  SqlDataReader^ reader = command.ExecuteReader();
				  if (reader->Read()) {
					  doctor = gcnew Doctor;
					  doctor->id = reader->GetInt32(0);
					  this->lbScheduledTime->Text = (reader->GetDateTime(1)).ToString();
					  this->lbDurationMinutes->Text = reader->GetInt32(2).ToString();
					  this->lbStatus->Text = reader->GetString(3);
					  reader->Close();

					  String^ sqlQuery2 = "SELECT first_name, last_name FROM doctor WHERE doctor_id = @doctorId;";
					  SqlCommand command2(sqlQuery2, % sqlConn);
					  command2.Parameters->AddWithValue("@doctorId", doctor->id);

					  SqlDataReader^ reader2 = command2.ExecuteReader();
					  if (reader2->Read()) {
						  doctor->doctorFirstName = reader2->GetString(0);
						  doctor->doctorLastName = reader2->GetString(1);
						  reader2->Close();
					  }
					  this->lbDoctorName->Text = String::Concat(doctor->doctorFirstName, " ", doctor->doctorLastName);

				  }
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

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~SeeAppointment()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ lbDoctorName;
	private: System::Windows::Forms::Label^ lbDurationMinutes;
	private: System::Windows::Forms::Label^ lbStatus;



	private: System::Windows::Forms::Label^ lbScheduledTime;

	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Button^ btnCancelAppointment;

	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel2;
	private: System::Windows::Forms::Button^ btnAppointmentCompleted;

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
			this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->lbDurationMinutes = (gcnew System::Windows::Forms::Label());
			this->lbStatus = (gcnew System::Windows::Forms::Label());
			this->lbScheduledTime = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->lbDoctorName = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->btnCancelAppointment = (gcnew System::Windows::Forms::Button());
			this->tableLayoutPanel2 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->btnAppointmentCompleted = (gcnew System::Windows::Forms::Button());
			this->tableLayoutPanel1->SuspendLayout();
			this->tableLayoutPanel2->SuspendLayout();
			this->SuspendLayout();
			// 
			// tableLayoutPanel1
			// 
			this->tableLayoutPanel1->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->tableLayoutPanel1->ColumnCount = 4;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				46.01594F)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				53.98406F)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				232)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				158)));
			this->tableLayoutPanel1->Controls->Add(this->lbDurationMinutes, 2, 1);
			this->tableLayoutPanel1->Controls->Add(this->lbStatus, 3, 1);
			this->tableLayoutPanel1->Controls->Add(this->lbScheduledTime, 1, 1);
			this->tableLayoutPanel1->Controls->Add(this->label7, 3, 0);
			this->tableLayoutPanel1->Controls->Add(this->label6, 1, 0);
			this->tableLayoutPanel1->Controls->Add(this->label5, 2, 0);
			this->tableLayoutPanel1->Controls->Add(this->label1, 0, 0);
			this->tableLayoutPanel1->Controls->Add(this->lbDoctorName, 0, 1);
			this->tableLayoutPanel1->Location = System::Drawing::Point(84, 304);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 2;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(1038, 135);
			this->tableLayoutPanel1->TabIndex = 0;
			// 
			// lbDurationMinutes
			// 
			this->lbDurationMinutes->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->lbDurationMinutes->Font = (gcnew System::Drawing::Font(L"Calibri", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbDurationMinutes->Location = System::Drawing::Point(650, 67);
			this->lbDurationMinutes->Name = L"lbDurationMinutes";
			this->lbDurationMinutes->Size = System::Drawing::Size(226, 68);
			this->lbDurationMinutes->TabIndex = 0;
			this->lbDurationMinutes->Text = L"duration minutes";
			this->lbDurationMinutes->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// lbStatus
			// 
			this->lbStatus->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->lbStatus->Font = (gcnew System::Drawing::Font(L"Calibri", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbStatus->Location = System::Drawing::Point(882, 67);
			this->lbStatus->Name = L"lbStatus";
			this->lbStatus->Size = System::Drawing::Size(153, 68);
			this->lbStatus->TabIndex = 1;
			this->lbStatus->Text = L"status";
			this->lbStatus->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// lbScheduledTime
			// 
			this->lbScheduledTime->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->lbScheduledTime->Font = (gcnew System::Drawing::Font(L"Calibri", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbScheduledTime->Location = System::Drawing::Point(301, 67);
			this->lbScheduledTime->Name = L"lbScheduledTime";
			this->lbScheduledTime->Size = System::Drawing::Size(343, 68);
			this->lbScheduledTime->TabIndex = 0;
			this->lbScheduledTime->Text = L"scheduled time";
			this->lbScheduledTime->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// label7
			// 
			this->label7->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->label7->Font = (gcnew System::Drawing::Font(L"Calibri", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label7->Location = System::Drawing::Point(882, 0);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(153, 67);
			this->label7->TabIndex = 1;
			this->label7->Text = L"Status";
			this->label7->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// label6
			// 
			this->label6->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->label6->Font = (gcnew System::Drawing::Font(L"Calibri", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label6->Location = System::Drawing::Point(301, 0);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(343, 67);
			this->label6->TabIndex = 0;
			this->label6->Text = L"Scheduled Time";
			this->label6->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// label5
			// 
			this->label5->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->label5->Font = (gcnew System::Drawing::Font(L"Calibri", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->Location = System::Drawing::Point(650, 0);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(226, 67);
			this->label5->TabIndex = 1;
			this->label5->Text = L"Duration minutes";
			this->label5->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// label1
			// 
			this->label1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->label1->Font = (gcnew System::Drawing::Font(L"Calibri", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(3, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(292, 67);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Doctor Name";
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// lbDoctorName
			// 
			this->lbDoctorName->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->lbDoctorName->Font = (gcnew System::Drawing::Font(L"Calibri", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbDoctorName->Location = System::Drawing::Point(3, 67);
			this->lbDoctorName->Name = L"lbDoctorName";
			this->lbDoctorName->Size = System::Drawing::Size(292, 68);
			this->lbDoctorName->TabIndex = 1;
			this->lbDoctorName->Text = L"doctor name";
			this->lbDoctorName->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// label3
			// 
			this->label3->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Calibri", 36, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(440, 142);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(362, 73);
			this->label3->TabIndex = 1;
			this->label3->Text = L"Appointment";
			// 
			// btnCancelAppointment
			// 
			this->btnCancelAppointment->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->btnCancelAppointment->Font = (gcnew System::Drawing::Font(L"Calibri", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnCancelAppointment->Location = System::Drawing::Point(355, 3);
			this->btnCancelAppointment->Name = L"btnCancelAppointment";
			this->btnCancelAppointment->Size = System::Drawing::Size(347, 68);
			this->btnCancelAppointment->TabIndex = 2;
			this->btnCancelAppointment->TabStop = false;
			this->btnCancelAppointment->Text = L"Cancel Appointment";
			this->btnCancelAppointment->UseVisualStyleBackColor = true;
			this->btnCancelAppointment->Click += gcnew System::EventHandler(this, &SeeAppointment::btnCancelAppointment_Click);
			// 
			// tableLayoutPanel2
			// 
			this->tableLayoutPanel2->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->tableLayoutPanel2->ColumnCount = 2;
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel2->Controls->Add(this->btnCancelAppointment, 1, 0);
			this->tableLayoutPanel2->Controls->Add(this->btnAppointmentCompleted, 0, 0);
			this->tableLayoutPanel2->Location = System::Drawing::Point(266, 474);
			this->tableLayoutPanel2->Name = L"tableLayoutPanel2";
			this->tableLayoutPanel2->RowCount = 1;
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel2->Size = System::Drawing::Size(705, 74);
			this->tableLayoutPanel2->TabIndex = 3;
			// 
			// btnAppointmentCompleted
			// 
			this->btnAppointmentCompleted->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->btnAppointmentCompleted->Font = (gcnew System::Drawing::Font(L"Calibri", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnAppointmentCompleted->Location = System::Drawing::Point(3, 3);
			this->btnAppointmentCompleted->Name = L"btnAppointmentCompleted";
			this->btnAppointmentCompleted->Size = System::Drawing::Size(346, 68);
			this->btnAppointmentCompleted->TabIndex = 3;
			this->btnAppointmentCompleted->TabStop = false;
			this->btnAppointmentCompleted->Text = L"Appointment Completed";
			this->btnAppointmentCompleted->UseVisualStyleBackColor = true;
			this->btnAppointmentCompleted->Click += gcnew System::EventHandler(this, &SeeAppointment::btnAppointmentCompleted_Click);
			// 
			// SeeAppointment
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1225, 779);
			this->Controls->Add(this->tableLayoutPanel2);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->tableLayoutPanel1);
			this->MinimumSize = System::Drawing::Size(1243, 826);
			this->Name = L"SeeAppointment";
			this->Text = L"SeeAppointment";
			this->tableLayoutPanel1->ResumeLayout(false);
			this->tableLayoutPanel2->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion


	private: System::Void btnAppointmentCompleted_Click(System::Object^ sender, System::EventArgs^ e) {
		try {
			String^ connString = "Data Source=localhost\\sqlexpress;Initial Catalog=test;Integrated Security=True;Encrypt=True;TrustServerCertificate=True";
			SqlConnection sqlConn(connString);
			sqlConn.Open();

			String^ sqlQuery = "UPDATE appointment SET status = 'Completed' WHERE patient_id = @patientId;";
			SqlCommand command(sqlQuery, % sqlConn);
			command.Parameters->AddWithValue("@patientId", patient->patientId);
			int rowsAffected = command.ExecuteNonQuery();
			if (rowsAffected > 0) {
				MessageBox::Show("Appointment status updated!",
					"Appointmrnt completed", MessageBoxButtons::OK);
				this->Close();
			}
			else {
				MessageBox::Show("Unable to update appointment status",
					"Failed to update", MessageBoxButtons::OK);
			}
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

	private: System::Void btnCancelAppointment_Click(System::Object^ sender, System::EventArgs^ e) {
		try {
			String^ connString = "Data Source=localhost\\sqlexpress;Initial Catalog=test;Integrated Security=True;Encrypt=True;TrustServerCertificate=True";
			SqlConnection sqlConn(connString);
			sqlConn.Open();

			String^ sqlQuery = "UPDATE appointment SET status = 'Cancelled' WHERE patient_id = @patientId;";
			SqlCommand command(sqlQuery, % sqlConn);
			command.Parameters->AddWithValue("@patientId", patient->patientId);
			int rowsAffected = command.ExecuteNonQuery();
			if (rowsAffected > 0) {
				MessageBox::Show("Appointment Cancelled!",
					"Success", MessageBoxButtons::OK);
				this->Close();
			}
			else {
				MessageBox::Show("Unable to Cancel appointment ",
					"Failed to update", MessageBoxButtons::OK);
			}
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
