#pragma once
#include"Patient.h"
#include"Doctor.h"
#include"Appointment.h"

namespace Telemedicine {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Data::SqlClient;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for BookAppointment
	/// </summary>
	
	public ref class BookAppointment : public System::Windows::Forms::Form
	{
	public:
		Patient^ patient = nullptr;
		BookAppointment(Patient^ patient)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			this->patient = patient;
			this->CenterToScreen();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~BookAppointment()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::ComboBox^ cbxDoctorSpecialization;
	protected:

	private: System::Windows::Forms::DateTimePicker^ dpkAppointmentDateTime;

	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::ComboBox^ cbxPaymentMethod;

	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel2;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::LinkLabel^ llBackToPatientDashboard;
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
			this->cbxDoctorSpecialization = (gcnew System::Windows::Forms::ComboBox());
			this->dpkAppointmentDateTime = (gcnew System::Windows::Forms::DateTimePicker());
			this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->cbxPaymentMethod = (gcnew System::Windows::Forms::ComboBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->tableLayoutPanel2 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->llBackToPatientDashboard = (gcnew System::Windows::Forms::LinkLabel());
			this->tableLayoutPanel1->SuspendLayout();
			this->tableLayoutPanel2->SuspendLayout();
			this->SuspendLayout();
			// 
			// cbxDoctorSpecialization
			// 
			this->cbxDoctorSpecialization->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
			this->cbxDoctorSpecialization->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cbxDoctorSpecialization->Font = (gcnew System::Drawing::Font(L"Calibri", 12));
			this->cbxDoctorSpecialization->FormattingEnabled = true;
			this->cbxDoctorSpecialization->Items->AddRange(gcnew cli::array< System::Object^  >(5) {
				L"Cardiology", L"Dermatologist",
					L"Psyciatrist", L"Dentist", L"Medical Doctor"
			});
			this->cbxDoctorSpecialization->Location = System::Drawing::Point(275, 89);
			this->cbxDoctorSpecialization->Name = L"cbxDoctorSpecialization";
			this->cbxDoctorSpecialization->Size = System::Drawing::Size(335, 32);
			this->cbxDoctorSpecialization->TabIndex = 0;
			// 
			// dpkAppointmentDateTime
			// 
			this->dpkAppointmentDateTime->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
			this->dpkAppointmentDateTime->Checked = false;
			this->dpkAppointmentDateTime->CustomFormat = L"yyyy-MM-dd HH:mm:ss";
			this->dpkAppointmentDateTime->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->dpkAppointmentDateTime->Format = System::Windows::Forms::DateTimePickerFormat::Custom;
			this->dpkAppointmentDateTime->Location = System::Drawing::Point(275, 19);
			this->dpkAppointmentDateTime->Name = L"dpkAppointmentDateTime";
			this->dpkAppointmentDateTime->ShowUpDown = true;
			this->dpkAppointmentDateTime->Size = System::Drawing::Size(335, 32);
			this->dpkAppointmentDateTime->TabIndex = 1;
			this->dpkAppointmentDateTime->Value = System::DateTime(2025, 4, 24, 1, 36, 0, 0);
			// 
			// tableLayoutPanel1
			// 
			this->tableLayoutPanel1->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->tableLayoutPanel1->ColumnCount = 2;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				44.53507F)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				55.46493F)));
			this->tableLayoutPanel1->Controls->Add(this->dpkAppointmentDateTime, 1, 0);
			this->tableLayoutPanel1->Controls->Add(this->cbxDoctorSpecialization, 1, 1);
			this->tableLayoutPanel1->Controls->Add(this->label1, 0, 0);
			this->tableLayoutPanel1->Controls->Add(this->label2, 0, 1);
			this->tableLayoutPanel1->Controls->Add(this->label3, 0, 2);
			this->tableLayoutPanel1->Controls->Add(this->label4, 0, 3);
			this->tableLayoutPanel1->Controls->Add(this->cbxPaymentMethod, 1, 3);
			this->tableLayoutPanel1->Controls->Add(this->label5, 0, 4);
			this->tableLayoutPanel1->Controls->Add(this->label6, 1, 4);
			this->tableLayoutPanel1->Controls->Add(this->label7, 1, 2);
			this->tableLayoutPanel1->Location = System::Drawing::Point(55, 161);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 5;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 20)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 20)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 20)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 20)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 20)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(613, 350);
			this->tableLayoutPanel1->TabIndex = 2;
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
			this->label1->Size = System::Drawing::Size(266, 70);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Date and Time";
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// label2
			// 
			this->label2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->label2->Font = (gcnew System::Drawing::Font(L"Calibri", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(3, 70);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(266, 70);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Doctor Specialization";
			this->label2->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// label3
			// 
			this->label3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->label3->Font = (gcnew System::Drawing::Font(L"Calibri", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(3, 140);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(266, 70);
			this->label3->TabIndex = 4;
			this->label3->Text = L"Duration";
			this->label3->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// label4
			// 
			this->label4->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->label4->Font = (gcnew System::Drawing::Font(L"Calibri", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(3, 210);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(266, 70);
			this->label4->TabIndex = 5;
			this->label4->Text = L"Payment Method";
			this->label4->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// cbxPaymentMethod
			// 
			this->cbxPaymentMethod->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
			this->cbxPaymentMethod->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cbxPaymentMethod->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->cbxPaymentMethod->FormattingEnabled = true;
			this->cbxPaymentMethod->Items->AddRange(gcnew cli::array< System::Object^  >(5) {
				L"TeleBirr", L"MPessa", L"CommercialBank of Ethiopia",
					L"Awash Bank", L"Abyssinia Bank"
			});
			this->cbxPaymentMethod->Location = System::Drawing::Point(275, 229);
			this->cbxPaymentMethod->Name = L"cbxPaymentMethod";
			this->cbxPaymentMethod->Size = System::Drawing::Size(335, 32);
			this->cbxPaymentMethod->TabIndex = 0;
			// 
			// label5
			// 
			this->label5->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->label5->Font = (gcnew System::Drawing::Font(L"Calibri", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->Location = System::Drawing::Point(3, 280);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(266, 70);
			this->label5->TabIndex = 6;
			this->label5->Text = L"Amount";
			this->label5->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// label6
			// 
			this->label6->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->label6->Font = (gcnew System::Drawing::Font(L"Calibri", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label6->Location = System::Drawing::Point(275, 280);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(335, 70);
			this->label6->TabIndex = 7;
			this->label6->Text = L"1000 Birr";
			this->label6->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// label7
			// 
			this->label7->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->label7->Font = (gcnew System::Drawing::Font(L"Calibri", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label7->Location = System::Drawing::Point(275, 140);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(335, 70);
			this->label7->TabIndex = 8;
			this->label7->Text = L"45 minutes";
			this->label7->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// label8
			// 
			this->label8->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Calibri", 36, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label8->Location = System::Drawing::Point(124, 61);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(503, 73);
			this->label8->TabIndex = 3;
			this->label8->Text = L"Book Appointment";
			// 
			// tableLayoutPanel2
			// 
			this->tableLayoutPanel2->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->tableLayoutPanel2->ColumnCount = 2;
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel2->Controls->Add(this->button1, 0, 0);
			this->tableLayoutPanel2->Controls->Add(this->button2, 1, 0);
			this->tableLayoutPanel2->Location = System::Drawing::Point(92, 531);
			this->tableLayoutPanel2->Name = L"tableLayoutPanel2";
			this->tableLayoutPanel2->RowCount = 1;
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel2->Size = System::Drawing::Size(544, 63);
			this->tableLayoutPanel2->TabIndex = 4;
			// 
			// button1
			// 
			this->button1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->button1->Font = (gcnew System::Drawing::Font(L"Calibri", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(3, 3);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(266, 57);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Book";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &BookAppointment::button1_Click);
			// 
			// button2
			// 
			this->button2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->button2->Font = (gcnew System::Drawing::Font(L"Calibri", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button2->Location = System::Drawing::Point(275, 3);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(266, 57);
			this->button2->TabIndex = 1;
			this->button2->Text = L"Cancel";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &BookAppointment::button2_Click);
			// 
			// llBackToPatientDashboard
			// 
			this->llBackToPatientDashboard->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->llBackToPatientDashboard->AutoSize = true;
			this->llBackToPatientDashboard->Font = (gcnew System::Drawing::Font(L"Calibri", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->llBackToPatientDashboard->Location = System::Drawing::Point(566, 607);
			this->llBackToPatientDashboard->Name = L"llBackToPatientDashboard";
			this->llBackToPatientDashboard->Size = System::Drawing::Size(70, 35);
			this->llBackToPatientDashboard->TabIndex = 5;
			this->llBackToPatientDashboard->TabStop = true;
			this->llBackToPatientDashboard->Text = L"Back";
			// 
			// BookAppointment
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::LightSeaGreen;
			this->ClientSize = System::Drawing::Size(717, 660);
			this->Controls->Add(this->llBackToPatientDashboard);
			this->Controls->Add(this->tableLayoutPanel2);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->tableLayoutPanel1);
			this->Name = L"BookAppointment";
			this->Text = L"BookAppointment";
			this->tableLayoutPanel1->ResumeLayout(false);
			this->tableLayoutPanel2->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
	 public: Doctor^ doctor = nullptr;
	public: Appointment^ appointment = nullptr;
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {


		if (!(this->dpkAppointmentDateTime) || !(this->cbxDoctorSpecialization->SelectedItem) || !(this->cbxPaymentMethod->SelectedItem)) {
			MessageBox::Show("Please fill out all forms	",
				"Missing form", MessageBoxButtons::OK);
			return;
		}

	
		String^ appointmentDateTime = this->dpkAppointmentDateTime->Text;
		String^ specialization = this->cbxDoctorSpecialization->SelectedItem->ToString();
		String^ paymentMethod = this->cbxPaymentMethod->SelectedItem->ToString();
		MessageBox::Show(appointmentDateTime + " " + specialization + " " + paymentMethod, "Result", MessageBoxButtons::OK);
		try {
			String^ connString = "Data Source=localhost\\sqlexpress;Initial Catalog=test;Integrated Security=True;Encrypt=True;TrustServerCertificate=True";
			SqlConnection sqlConn(connString);
			sqlConn.Open();

			String^ sqlQuery1 = "WITH DoctorAppointmentCount AS (SELECT d.doctor_id, d.first_name, d.last_name, d.specialization, COUNT(a.appointment_id) AS current_appointment_count FROM doctor d LEFT JOIN appointment a ON d.doctor_id = a.doctor_id AND CONVERT(DATE, a.scheduled_time) = CONVERT(DATE, @desired_datetime) AND a.status NOT IN('Cancelled', 'Rejected') GROUP BY d.doctor_id, d.first_name, d.last_name, d.specialization ), AvailableDoctors AS( SELECT * FROM DoctorAppointmentCount WHERE doctor_id NOT IN( SELECT doctor_id FROM appointment WHERE scheduled_time = @desired_datetime AND status NOT IN('Cancelled', 'Rejected') ) ) SELECT doctor_id, first_name, last_name, specialization, current_appointment_count FROM AvailableDoctors ORDER BY current_appointment_count ASC;";
			SqlCommand command(sqlQuery1, % sqlConn);
			command.Parameters->AddWithValue("@desired_datetime", appointmentDateTime);

			SqlDataReader^ reader = command.ExecuteReader();
			if (reader->Read()) {
				doctor = gcnew Doctor;
				doctor->id = reader->GetInt32(0);
				doctor->doctorFirstName = reader->GetString(1);
				doctor->doctorLastName = reader->GetString(2);
				doctor->specialization = reader->GetString(3);
				reader->Close();

			}
			String^ sqlQuery2 = "INSERT INTO appointment (patient_id, doctor_id, scheduled_time, status) VALUES (@patientId, @doctorId, @scheduledTime, 'Scheduled');";
			SqlCommand command2(sqlQuery2, % sqlConn);
			command2.Parameters->AddWithValue("@patientId", patient->patientId);
			command2.Parameters->AddWithValue("@doctorId", doctor->id);
			command2.Parameters->AddWithValue("@scheduledTime", appointmentDateTime);

			int rowsAffected = command2.ExecuteNonQuery();

			if (rowsAffected > 0) {
				MessageBox::Show("Appointment created successfully!",
					"Success", MessageBoxButtons::OK);
				this->Close();
			}
			else {
				MessageBox::Show("Failed to create appointment",
					"Error", MessageBoxButtons::OK);
			}
			String^ sqlQuery3 = "SELECT appointment_id FROM appointment WHERE patient_id = @patientId AND scheduled_time = @appointmentTime;";
			SqlCommand command3(sqlQuery3, % sqlConn);
			command3.Parameters->AddWithValue("@patientId", patient->patientId);
			command3.Parameters->AddWithValue("@appointmentTime", appointmentDateTime);
			SqlDataReader^ reader2 = command3.ExecuteReader();
			if (reader2->Read()) {
				appointment = gcnew Appointment;
				appointment->appointmentId = reader2->GetInt32(0);
				reader2->Close();
			}
			String^ sqlQuery4 = "INSERT INTO payment (appointment_id, amount, status, payment_method, transaction_date) VALUES (@appointmentId, 1000.00, 'Completed', @paymentMethod, CURRENT_TIMESTAMP);";
			SqlCommand command4(sqlQuery4, % sqlConn);
			command4.Parameters->AddWithValue("@appointmentId", appointment->appointmentId);
			command4.Parameters->AddWithValue("@paymentMethod", paymentMethod);
			command4.Parameters->AddWithValue("@scheduledTime", appointmentDateTime);

			int rowsAffected2 = command4.ExecuteNonQuery();

			if (rowsAffected2 > 0) {
				MessageBox::Show("Payment transaction successfull! \n1000.00Birr paid using \n" + paymentMethod,
					"Success", MessageBoxButtons::OK);
				this->Close();
			}
			else {
				MessageBox::Show("Transaction failed",
					"Error", MessageBoxButtons::OK);
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
};
}
