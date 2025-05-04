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
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ ID;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column3;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Status;
	private: System::Windows::Forms::DataGridViewButtonColumn^ Cancel;
	private: System::Windows::Forms::DataGridViewButtonColumn^ Completed;

	public:
	 
		   Doctor^ doctor = nullptr;
		SeeAppointment(Patient^ patient)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//

			this->patient = patient;
			  try {
				  String^ connString = "Data Source=localhost\\sqlexpress;Initial Catalog=test;Integrated Security=True;Encrypt=True;TrustServerCertificate=True";
				  SqlConnection sqlConn(connString);
				  sqlConn.Open();

				  String^ sqlQuery = "SELECT a.appointment_id, a.doctor_id, a.scheduled_time,"
									 "a.duration_minutes, a.status, d.first_name, d.last_name "
									 "FROM appointment a INNER JOIN doctor d ON a.doctor_id = d.doctor_id "
									 "WHERE a.patient_id = @patientId "
									 "ORDER BY a.scheduled_time;";
				  SqlCommand command(sqlQuery, % sqlConn);
				  command.Parameters->AddWithValue("@patientId", patient->patientId);

				  SqlDataReader^ reader = command.ExecuteReader();
				  while (reader->Read()) {
					  doctor = gcnew Doctor;
					  int appointmentId = safe_cast<int>(reader["appointment_id"]);
					  doctor->doctorFirstName = safe_cast<String^>(reader["first_name"]);
					  doctor->doctorLastName = safe_cast<String^>(reader["last_name"]);
					  String^ scheduledTime = (reader["scheduled_time"])->ToString();
					  String^ duration =(reader["duration_minutes"])->ToString();
					  String^ status = safe_cast<String^>(reader["status"]);
					  
					  String^ doctorName = String::Concat(doctor->doctorFirstName, " ", doctor->doctorLastName);
						
					  this->dataGridView1->Rows->Add(appointmentId, doctorName, scheduledTime, duration, status);
					  

				  }
					reader->Close();
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













	private: System::Windows::Forms::Label^ label3;





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
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->ID = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Status = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Cancel = (gcnew System::Windows::Forms::DataGridViewButtonColumn());
			this->Completed = (gcnew System::Windows::Forms::DataGridViewButtonColumn());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
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
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToAddRows = false;
			this->dataGridView1->AllowUserToDeleteRows = false;
			this->dataGridView1->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->dataGridView1->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(7) {
				this->ID, this->Column1,
					this->Column2, this->Column3, this->Status, this->Cancel, this->Completed
			});
			this->dataGridView1->Location = System::Drawing::Point(12, 282);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->ReadOnly = true;
			this->dataGridView1->RowHeadersWidth = 51;
			this->dataGridView1->RowTemplate->Height = 24;
			this->dataGridView1->Size = System::Drawing::Size(1201, 401);
			this->dataGridView1->TabIndex = 4;
			this->dataGridView1->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &SeeAppointment::dataGridView1_CellClick);
			// 
			// ID
			// 
			this->ID->HeaderText = L"ID";
			this->ID->MinimumWidth = 6;
			this->ID->Name = L"ID";
			// 
			// Column1
			// 
			this->Column1->HeaderText = L"Doctor Name";
			this->Column1->MinimumWidth = 6;
			this->Column1->Name = L"Column1";
			// 
			// Column2
			// 
			this->Column2->HeaderText = L"Schedule Time";
			this->Column2->MinimumWidth = 6;
			this->Column2->Name = L"Column2";
			// 
			// Column3
			// 
			this->Column3->HeaderText = L"Duration Minutes";
			this->Column3->MinimumWidth = 6;
			this->Column3->Name = L"Column3";
			// 
			// Status
			// 
			this->Status->HeaderText = L"Status";
			this->Status->MinimumWidth = 6;
			this->Status->Name = L"Status";
			// 
			// Cancel
			// 
			this->Cancel->HeaderText = L"Cancel";
			this->Cancel->MinimumWidth = 6;
			this->Cancel->Name = L"Cancel";
			this->Cancel->Text = L"Cancel";
			this->Cancel->UseColumnTextForButtonValue = true;
			// 
			// Completed
			// 
			this->Completed->HeaderText = L"Completed";
			this->Completed->MinimumWidth = 6;
			this->Completed->Name = L"Completed";
			this->Completed->Text = L"Completed";
			this->Completed->UseColumnTextForButtonValue = true;
			// 
			// SeeAppointment
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1225, 779);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->label3);
			this->MinimumSize = System::Drawing::Size(1243, 826);
			this->Name = L"SeeAppointment";
			this->Text = L"SeeAppointment";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion



private: System::Void dataGridView1_CellClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {

	try {
			String^ connString = "Data Source=localhost\\sqlexpress;Initial Catalog=test;Integrated Security=True;Encrypt=True;TrustServerCertificate=True";
			SqlConnection sqlConn(connString);
			sqlConn.Open();

	if (e->ColumnIndex == this->dataGridView1->Columns["Cancel"]->Index && e->RowIndex >= 0) {
		String^ appointmentId = (this->dataGridView1->Rows[e->RowIndex]->Cells["ID"]->Value)->ToString();
		this->dataGridView1->Rows[e->RowIndex]->Cells["Status"]->Value = "Cancelled";
		this->dataGridView1->Rows[e->RowIndex]->Cells["Cancel"]->ReadOnly = true;
		this->dataGridView1->Rows[e->RowIndex]->DefaultCellStyle->BackColor = Color::LightGray;

	
			String^ sqlQuery = "UPDATE appointment SET status = 'Cancelled' WHERE appointment_id = @appointmentId;";
			SqlCommand command(sqlQuery, % sqlConn);
			command.Parameters->AddWithValue("@appointmentId", Int32::Parse(appointmentId));
			int rowsAffected = command.ExecuteNonQuery();
			if (rowsAffected > 0) {
				MessageBox::Show("Appointment Cancelled!",
					"Success", MessageBoxButtons::OK);
				this->Close();
			}
			else {
				MessageBox::Show("Unable to Cancel appointment status",
					"Failed to update", MessageBoxButtons::OK);
			}
	
	}
	else if (e->ColumnIndex == this->dataGridView1->Columns["Completed"]->Index && e->RowIndex >= 0) {
		String^ appointmentId = (this->dataGridView1->Rows[e->RowIndex]->Cells["ID"]->Value)->ToString();
		this->dataGridView1->Rows[e->RowIndex]->Cells["Status"]->Value = "Completed";
		this->dataGridView1->Rows[e->RowIndex]->Cells["Completed"]->ReadOnly = true;

		String^ sqlQuery = "UPDATE appointment SET status = 'Completed' WHERE Appointment_id = @appointmentId;";
		SqlCommand command(sqlQuery, % sqlConn);
		command.Parameters->AddWithValue("@appointmentId", appointmentId);
		int rowsAffected = command.ExecuteNonQuery();
		if (rowsAffected > 0) {
			MessageBox::Show("Appointment status updated!",
				"Success", MessageBoxButtons::OK);
			this->Close();
		}
		else {
			MessageBox::Show("Unable to update appointment status",
				"Failed to update", MessageBoxButtons::OK);
		}

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
