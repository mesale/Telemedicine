#pragma once
#include"Doctor.h"
#include"Patient.h"
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
	/// Summary for PatientDashboardForm
	/// </summary>
	public ref class DoctorDashboard : public System::Windows::Forms::Form
	{
	public:
        Doctor^ doctor = nullptr;
        Patient^ patient1 = nullptr;
        Patient^ patient2 = nullptr;
        Patient^ patient3 = nullptr;
        Appointment^ appointment1 = nullptr;
        Appointment^ appointment2 = nullptr;
    private: System::Windows::Forms::Button^ button1;
    public:
        Appointment^ appointment3 = nullptr;
        DoctorDashboard(Doctor^ doctor)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
            this->CenterToScreen();
            this->lbAppointmentId1->Text = "";
            this->lbAppointmentId2->Text = "";
            this->lbAppointmentId3->Text = "";
            this->lbPatientName1->Text = "";
            this->lbPatientName2->Text = "";
            this->lbPatientName3->Text = "";
            this->lbScheduledTime1->Text = "";
            this->lbScheduledTime2->Text = "";
            this->lbScheduledTime3->Text = "";
            this->lbDurationMinutes1->Text = "";
            this->lbDurationMinutes2->Text = "";
            this->lbDurationMinutes3->Text = "";
            this->lbStatus1->Text = "";
            this->lbStatus2->Text = "";
            this->lbStatus3->Text = "";
            this->doctor = doctor;
            this->lbDoctor->Text = String::Concat(" Dr.", doctor->doctorFirstName);
            try {
                String^ connString = "Data Source=localhost\\sqlexpress;Initial Catalog=test;Integrated Security=True;Encrypt=True;TrustServerCertificate=True";
                SqlConnection sqlConn(connString);
                sqlConn.Open();

                // Modified query to get both appointment and patient data in one query
                String^ sqlQuery = "SELECT TOP 3 a.appointment_id, a.patient_id, a.scheduled_time, "
                    "a.duration_minutes, a.status, p.first_name, p.last_name "
                    "FROM appointment a "
                    "INNER JOIN patient p ON a.patient_id = p.patient_id "
                    "WHERE a.doctor_id = @doctorId "
                    "ORDER BY a.scheduled_time;";

                SqlCommand command(sqlQuery, % sqlConn);
                command.Parameters->AddWithValue("@doctorId", doctor->id);

                SqlDataReader^ reader = command.ExecuteReader();
                Appointment^ currentAppointment = nullptr;;
                int appointmentCount = 0;
                while (reader->Read() && appointmentCount < 3) {
                    appointmentCount++;

                    // Create new patient and appointment objects
                    Patient^ currentPatient = gcnew Patient();
                    currentAppointment = gcnew Appointment();

                    // Read appointment data
                    if (!reader->IsDBNull(0)) currentAppointment->appointmentId = reader->GetInt32(0);
                    if (appointmentCount == 1) this->lbAppointmentId1->Text = currentAppointment->appointmentId.ToString();
                    if (appointmentCount == 2) this->lbAppointmentId2->Text = currentAppointment->appointmentId.ToString();
                    if (!reader->IsDBNull(1)) currentPatient->patientId = reader->GetInt32(1);

                    // Read patient data
                    if (!reader->IsDBNull(5)) currentPatient->patientFirstName = reader->GetString(5);
                    if (!reader->IsDBNull(6)) currentPatient->patientLastName = reader->GetString(6);

                    // Update UI based on which appointment we're processing
                    switch (appointmentCount) {
                    case 1:
                        patient1 = currentPatient;
                        appointment1 = currentAppointment;
                        if (!reader->IsDBNull(2)) this->lbScheduledTime1->Text = reader->GetDateTime(2).ToString();
                        if (!reader->IsDBNull(3)) this->lbDurationMinutes1->Text = reader->GetInt32(3).ToString();
                        if (!reader->IsDBNull(4)) this->lbStatus1->Text = reader->GetString(4);
                        this->lbPatientName1->Text = String::Concat(currentPatient->patientFirstName, " ", currentPatient->patientLastName);
                        break;

                    case 2:
                        patient2 = currentPatient;
                        appointment2 = currentAppointment;
                        if (!reader->IsDBNull(2)) this->lbScheduledTime2->Text = reader->GetDateTime(2).ToString();
                        if (!reader->IsDBNull(3)) this->lbDurationMinutes2->Text = reader->GetInt32(3).ToString();
                        if (!reader->IsDBNull(4)) this->lbStatus2->Text = reader->GetString(4);
                        this->lbPatientName2->Text = String::Concat(currentPatient->patientFirstName, " ", currentPatient->patientLastName);
                        break;

                    case 3:
                        patient3 = currentPatient;
                        appointment3 = currentAppointment;
                        if (!reader->IsDBNull(2)) this->lbScheduledTime3->Text = reader->GetDateTime(2).ToString();
                        if (!reader->IsDBNull(3)) this->lbDurationMinutes3->Text = reader->GetInt32(3).ToString();
                        if (!reader->IsDBNull(4)) this->lbStatus3->Text = reader->GetString(4);
                        this->lbPatientName3->Text = String::Concat(currentPatient->patientFirstName, " ", currentPatient->patientLastName);
                        break;
                    }
                }
                if (appointmentCount == 3) this->lbAppointmentId3->Text = currentAppointment->appointmentId.ToString();

                reader->Close();
                sqlConn.Close();
            }
            catch (SqlException^ sqlEx) {
                MessageBox::Show(String::Format("Database error: {0}", sqlEx->Message),
                    "Database Error", MessageBoxButtons::OK);
            }
            catch (Exception^ ex) {
                MessageBox::Show(String::Format("Error: {0}", ex->Message),
                    "Error", MessageBoxButtons::OK);
            }
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~DoctorDashboard()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
    private: System::Windows::Forms::Label^ lbDoctor;

	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel1;
	private: System::Windows::Forms::TabControl^ tabControl1;
	private: System::Windows::Forms::TabPage^ tabPage1;
	private: System::Windows::Forms::TabPage^ tabPage2;
	private: System::Windows::Forms::Label^ label3;
    private: System::Windows::Forms::Label^ lbAppointmentId1;


	private: System::Windows::Forms::Label^ label5;
    private: System::Windows::Forms::Label^ lbPatientName1;

    private: System::Windows::Forms::Label^ lbStatus1;


	private: System::Windows::Forms::Label^ label12;
	private: System::Windows::Forms::Label^ label13;
    private: System::Windows::Forms::Label^ lbScheduledTime1;
    private: System::Windows::Forms::Label^ lbDurationMinutes1;





	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel2;
    private: System::Windows::Forms::TextBox^ tbxRefills;
    private: System::Windows::Forms::TextBox^ tbxInstructions;



    private: System::Windows::Forms::TextBox^ tbxDosage;

    private: System::Windows::Forms::Label^ label8;
    private: System::Windows::Forms::TextBox^ tbxMedicationName;

    private: System::Windows::Forms::Label^ label18;
    private: System::Windows::Forms::TextBox^ tbxDiagnosis;

    private: System::Windows::Forms::Label^ label17;
    private: System::Windows::Forms::TextBox^ tbxAppointmentId;

    private: System::Windows::Forms::Label^ label16;
private: System::Windows::Forms::Label^ label7;

private: System::Windows::Forms::Label^ label15;



    private: System::Windows::Forms::Button^ btnMedicalRecordSubmit;
    private: System::Windows::Forms::Label^ lbStatus3;

    private: System::Windows::Forms::Label^ lbStatus2;

    private: System::Windows::Forms::Label^ lbScheduledTime3;
    private: System::Windows::Forms::Label^ lbAppointmentId3;


    private: System::Windows::Forms::Label^ lbScheduledTime2;
    private: System::Windows::Forms::Label^ lbAppointmentId2;


    private: System::Windows::Forms::Label^ lbPatientName2;
private: System::Windows::Forms::Label^ lbDurationMinutes2;



    private: System::Windows::Forms::Label^ lbPatientName3;
private: System::Windows::Forms::Label^ lbDurationMinutes3;




















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
            this->lbDoctor = (gcnew System::Windows::Forms::Label());
            this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
            this->label3 = (gcnew System::Windows::Forms::Label());
            this->lbStatus3 = (gcnew System::Windows::Forms::Label());
            this->lbStatus2 = (gcnew System::Windows::Forms::Label());
            this->lbStatus1 = (gcnew System::Windows::Forms::Label());
            this->label12 = (gcnew System::Windows::Forms::Label());
            this->label13 = (gcnew System::Windows::Forms::Label());
            this->lbScheduledTime3 = (gcnew System::Windows::Forms::Label());
            this->lbAppointmentId3 = (gcnew System::Windows::Forms::Label());
            this->lbScheduledTime1 = (gcnew System::Windows::Forms::Label());
            this->lbScheduledTime2 = (gcnew System::Windows::Forms::Label());
            this->lbDurationMinutes1 = (gcnew System::Windows::Forms::Label());
            this->lbAppointmentId2 = (gcnew System::Windows::Forms::Label());
            this->label9 = (gcnew System::Windows::Forms::Label());
            this->lbAppointmentId1 = (gcnew System::Windows::Forms::Label());
            this->label5 = (gcnew System::Windows::Forms::Label());
            this->lbPatientName1 = (gcnew System::Windows::Forms::Label());
            this->lbPatientName2 = (gcnew System::Windows::Forms::Label());
            this->lbDurationMinutes2 = (gcnew System::Windows::Forms::Label());
            this->lbPatientName3 = (gcnew System::Windows::Forms::Label());
            this->lbDurationMinutes3 = (gcnew System::Windows::Forms::Label());
            this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
            this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
            this->button1 = (gcnew System::Windows::Forms::Button());
            this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
            this->btnMedicalRecordSubmit = (gcnew System::Windows::Forms::Button());
            this->tableLayoutPanel2 = (gcnew System::Windows::Forms::TableLayoutPanel());
            this->tbxRefills = (gcnew System::Windows::Forms::TextBox());
            this->tbxInstructions = (gcnew System::Windows::Forms::TextBox());
            this->tbxDosage = (gcnew System::Windows::Forms::TextBox());
            this->label8 = (gcnew System::Windows::Forms::Label());
            this->tbxMedicationName = (gcnew System::Windows::Forms::TextBox());
            this->label18 = (gcnew System::Windows::Forms::Label());
            this->tbxDiagnosis = (gcnew System::Windows::Forms::TextBox());
            this->label17 = (gcnew System::Windows::Forms::Label());
            this->tbxAppointmentId = (gcnew System::Windows::Forms::TextBox());
            this->label16 = (gcnew System::Windows::Forms::Label());
            this->label7 = (gcnew System::Windows::Forms::Label());
            this->label15 = (gcnew System::Windows::Forms::Label());
            this->tableLayoutPanel1->SuspendLayout();
            this->tabControl1->SuspendLayout();
            this->tabPage1->SuspendLayout();
            this->tabPage2->SuspendLayout();
            this->tableLayoutPanel2->SuspendLayout();
            this->SuspendLayout();
            // 
            // label1
            // 
            this->label1->Anchor = System::Windows::Forms::AnchorStyles::None;
            this->label1->AutoSize = true;
            this->label1->Font = (gcnew System::Drawing::Font(L"Calibri", 36, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label1->Location = System::Drawing::Point(408, 62);
            this->label1->Name = L"label1";
            this->label1->Size = System::Drawing::Size(265, 73);
            this->label1->TabIndex = 0;
            this->label1->Text = L"Welcome";
            // 
            // lbDoctor
            // 
            this->lbDoctor->Anchor = System::Windows::Forms::AnchorStyles::None;
            this->lbDoctor->AutoSize = true;
            this->lbDoctor->Font = (gcnew System::Drawing::Font(L"Calibri", 22.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->lbDoctor->Location = System::Drawing::Point(460, 155);
            this->lbDoctor->Name = L"lbDoctor";
            this->lbDoctor->Size = System::Drawing::Size(124, 45);
            this->lbDoctor->TabIndex = 1;
            this->lbDoctor->Text = L"Doctor";
            // 
            // tableLayoutPanel1
            // 
            this->tableLayoutPanel1->Anchor = System::Windows::Forms::AnchorStyles::None;
            this->tableLayoutPanel1->ColumnCount = 5;
            this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
                6.840087F)));
            this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
                26.72191F)));
            this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
                26.30274F)));
            this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
                25.35962F)));
            this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
                14.77564F)));
            this->tableLayoutPanel1->Controls->Add(this->label3, 0, 0);
            this->tableLayoutPanel1->Controls->Add(this->lbStatus3, 4, 3);
            this->tableLayoutPanel1->Controls->Add(this->lbStatus2, 4, 2);
            this->tableLayoutPanel1->Controls->Add(this->lbStatus1, 4, 1);
            this->tableLayoutPanel1->Controls->Add(this->label12, 3, 0);
            this->tableLayoutPanel1->Controls->Add(this->label13, 4, 0);
            this->tableLayoutPanel1->Controls->Add(this->lbScheduledTime3, 2, 3);
            this->tableLayoutPanel1->Controls->Add(this->lbAppointmentId3, 0, 3);
            this->tableLayoutPanel1->Controls->Add(this->lbScheduledTime1, 2, 1);
            this->tableLayoutPanel1->Controls->Add(this->lbScheduledTime2, 2, 2);
            this->tableLayoutPanel1->Controls->Add(this->lbDurationMinutes1, 3, 1);
            this->tableLayoutPanel1->Controls->Add(this->lbAppointmentId2, 0, 2);
            this->tableLayoutPanel1->Controls->Add(this->label9, 2, 0);
            this->tableLayoutPanel1->Controls->Add(this->lbAppointmentId1, 0, 1);
            this->tableLayoutPanel1->Controls->Add(this->label5, 1, 0);
            this->tableLayoutPanel1->Controls->Add(this->lbPatientName1, 1, 1);
            this->tableLayoutPanel1->Controls->Add(this->lbPatientName2, 1, 2);
            this->tableLayoutPanel1->Controls->Add(this->lbDurationMinutes2, 3, 2);
            this->tableLayoutPanel1->Controls->Add(this->lbPatientName3, 1, 3);
            this->tableLayoutPanel1->Controls->Add(this->lbDurationMinutes3, 3, 3);
            this->tableLayoutPanel1->Location = System::Drawing::Point(26, 27);
            this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
            this->tableLayoutPanel1->RowCount = 4;
            this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 25)));
            this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 25)));
            this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 25)));
            this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 25)));
            this->tableLayoutPanel1->Size = System::Drawing::Size(956, 203);
            this->tableLayoutPanel1->TabIndex = 2;
            // 
            // label3
            // 
            this->label3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->label3->Font = (gcnew System::Drawing::Font(L"Calibri", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label3->Location = System::Drawing::Point(3, 0);
            this->label3->Name = L"label3";
            this->label3->Size = System::Drawing::Size(59, 50);
            this->label3->TabIndex = 0;
            this->label3->Text = L"ID";
            this->label3->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            // 
            // lbStatus3
            // 
            this->lbStatus3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->lbStatus3->Font = (gcnew System::Drawing::Font(L"Calibri", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->lbStatus3->Location = System::Drawing::Point(816, 150);
            this->lbStatus3->Name = L"lbStatus3";
            this->lbStatus3->Size = System::Drawing::Size(137, 53);
            this->lbStatus3->TabIndex = 3;
            this->lbStatus3->Text = L"status";
            this->lbStatus3->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            // 
            // lbStatus2
            // 
            this->lbStatus2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->lbStatus2->Font = (gcnew System::Drawing::Font(L"Calibri", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->lbStatus2->Location = System::Drawing::Point(816, 100);
            this->lbStatus2->Name = L"lbStatus2";
            this->lbStatus2->Size = System::Drawing::Size(137, 50);
            this->lbStatus2->TabIndex = 3;
            this->lbStatus2->Text = L"status";
            this->lbStatus2->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            // 
            // lbStatus1
            // 
            this->lbStatus1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->lbStatus1->Font = (gcnew System::Drawing::Font(L"Calibri", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->lbStatus1->Location = System::Drawing::Point(816, 50);
            this->lbStatus1->Name = L"lbStatus1";
            this->lbStatus1->Size = System::Drawing::Size(137, 50);
            this->lbStatus1->TabIndex = 3;
            this->lbStatus1->Text = L"status";
            this->lbStatus1->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            // 
            // label12
            // 
            this->label12->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->label12->Font = (gcnew System::Drawing::Font(L"Calibri", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label12->Location = System::Drawing::Point(574, 0);
            this->label12->Name = L"label12";
            this->label12->Size = System::Drawing::Size(236, 50);
            this->label12->TabIndex = 3;
            this->label12->Text = L"Duration minutes";
            this->label12->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            // 
            // label13
            // 
            this->label13->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->label13->Font = (gcnew System::Drawing::Font(L"Calibri", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label13->Location = System::Drawing::Point(816, 0);
            this->label13->Name = L"label13";
            this->label13->Size = System::Drawing::Size(137, 50);
            this->label13->TabIndex = 2;
            this->label13->Text = L"Status";
            this->label13->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            // 
            // lbScheduledTime3
            // 
            this->lbScheduledTime3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->lbScheduledTime3->Font = (gcnew System::Drawing::Font(L"Calibri", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->lbScheduledTime3->Location = System::Drawing::Point(323, 150);
            this->lbScheduledTime3->Name = L"lbScheduledTime3";
            this->lbScheduledTime3->Size = System::Drawing::Size(245, 53);
            this->lbScheduledTime3->TabIndex = 3;
            this->lbScheduledTime3->Text = L"scheduled time";
            this->lbScheduledTime3->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            // 
            // lbAppointmentId3
            // 
            this->lbAppointmentId3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->lbAppointmentId3->Font = (gcnew System::Drawing::Font(L"Calibri", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->lbAppointmentId3->Location = System::Drawing::Point(3, 150);
            this->lbAppointmentId3->Name = L"lbAppointmentId3";
            this->lbAppointmentId3->Size = System::Drawing::Size(59, 53);
            this->lbAppointmentId3->TabIndex = 1;
            this->lbAppointmentId3->Text = L"id";
            this->lbAppointmentId3->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            // 
            // lbScheduledTime1
            // 
            this->lbScheduledTime1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->lbScheduledTime1->Font = (gcnew System::Drawing::Font(L"Calibri", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->lbScheduledTime1->Location = System::Drawing::Point(323, 50);
            this->lbScheduledTime1->Name = L"lbScheduledTime1";
            this->lbScheduledTime1->Size = System::Drawing::Size(245, 50);
            this->lbScheduledTime1->TabIndex = 3;
            this->lbScheduledTime1->Text = L"scheduled time";
            this->lbScheduledTime1->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            // 
            // lbScheduledTime2
            // 
            this->lbScheduledTime2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->lbScheduledTime2->Font = (gcnew System::Drawing::Font(L"Calibri", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->lbScheduledTime2->Location = System::Drawing::Point(323, 100);
            this->lbScheduledTime2->Name = L"lbScheduledTime2";
            this->lbScheduledTime2->Size = System::Drawing::Size(245, 50);
            this->lbScheduledTime2->TabIndex = 3;
            this->lbScheduledTime2->Text = L"scheduled time";
            this->lbScheduledTime2->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            // 
            // lbDurationMinutes1
            // 
            this->lbDurationMinutes1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->lbDurationMinutes1->Font = (gcnew System::Drawing::Font(L"Calibri", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->lbDurationMinutes1->Location = System::Drawing::Point(574, 50);
            this->lbDurationMinutes1->Name = L"lbDurationMinutes1";
            this->lbDurationMinutes1->Size = System::Drawing::Size(236, 50);
            this->lbDurationMinutes1->TabIndex = 2;
            this->lbDurationMinutes1->Text = L"duration minutes";
            this->lbDurationMinutes1->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            // 
            // lbAppointmentId2
            // 
            this->lbAppointmentId2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->lbAppointmentId2->Font = (gcnew System::Drawing::Font(L"Calibri", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->lbAppointmentId2->Location = System::Drawing::Point(3, 100);
            this->lbAppointmentId2->Name = L"lbAppointmentId2";
            this->lbAppointmentId2->Size = System::Drawing::Size(59, 50);
            this->lbAppointmentId2->TabIndex = 1;
            this->lbAppointmentId2->Text = L"id";
            this->lbAppointmentId2->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            // 
            // label9
            // 
            this->label9->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->label9->Font = (gcnew System::Drawing::Font(L"Calibri", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label9->Location = System::Drawing::Point(323, 0);
            this->label9->Name = L"label9";
            this->label9->Size = System::Drawing::Size(245, 50);
            this->label9->TabIndex = 2;
            this->label9->Text = L"Scheduled Time";
            this->label9->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            // 
            // lbAppointmentId1
            // 
            this->lbAppointmentId1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->lbAppointmentId1->Font = (gcnew System::Drawing::Font(L"Calibri", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->lbAppointmentId1->Location = System::Drawing::Point(3, 50);
            this->lbAppointmentId1->Name = L"lbAppointmentId1";
            this->lbAppointmentId1->Size = System::Drawing::Size(59, 50);
            this->lbAppointmentId1->TabIndex = 1;
            this->lbAppointmentId1->Text = L"id";
            this->lbAppointmentId1->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            // 
            // label5
            // 
            this->label5->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->label5->Font = (gcnew System::Drawing::Font(L"Calibri", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label5->Location = System::Drawing::Point(68, 0);
            this->label5->Name = L"label5";
            this->label5->Size = System::Drawing::Size(249, 50);
            this->label5->TabIndex = 2;
            this->label5->Text = L"Patient Name";
            this->label5->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            // 
            // lbPatientName1
            // 
            this->lbPatientName1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->lbPatientName1->Font = (gcnew System::Drawing::Font(L"Calibri", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->lbPatientName1->Location = System::Drawing::Point(68, 50);
            this->lbPatientName1->Name = L"lbPatientName1";
            this->lbPatientName1->Size = System::Drawing::Size(249, 50);
            this->lbPatientName1->TabIndex = 3;
            this->lbPatientName1->Text = L"patient name";
            this->lbPatientName1->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            // 
            // lbPatientName2
            // 
            this->lbPatientName2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->lbPatientName2->Font = (gcnew System::Drawing::Font(L"Calibri", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->lbPatientName2->Location = System::Drawing::Point(68, 100);
            this->lbPatientName2->Name = L"lbPatientName2";
            this->lbPatientName2->Size = System::Drawing::Size(249, 50);
            this->lbPatientName2->TabIndex = 3;
            this->lbPatientName2->Text = L"patient name";
            this->lbPatientName2->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            // 
            // lbDurationMinutes2
            // 
            this->lbDurationMinutes2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->lbDurationMinutes2->Font = (gcnew System::Drawing::Font(L"Calibri", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->lbDurationMinutes2->Location = System::Drawing::Point(574, 100);
            this->lbDurationMinutes2->Name = L"lbDurationMinutes2";
            this->lbDurationMinutes2->Size = System::Drawing::Size(236, 50);
            this->lbDurationMinutes2->TabIndex = 2;
            this->lbDurationMinutes2->Text = L"duration minutes";
            this->lbDurationMinutes2->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            // 
            // lbPatientName3
            // 
            this->lbPatientName3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->lbPatientName3->Font = (gcnew System::Drawing::Font(L"Calibri", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->lbPatientName3->Location = System::Drawing::Point(68, 150);
            this->lbPatientName3->Name = L"lbPatientName3";
            this->lbPatientName3->Size = System::Drawing::Size(249, 53);
            this->lbPatientName3->TabIndex = 3;
            this->lbPatientName3->Text = L"patient name";
            this->lbPatientName3->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            // 
            // lbDurationMinutes3
            // 
            this->lbDurationMinutes3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->lbDurationMinutes3->Font = (gcnew System::Drawing::Font(L"Calibri", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->lbDurationMinutes3->Location = System::Drawing::Point(574, 150);
            this->lbDurationMinutes3->Name = L"lbDurationMinutes3";
            this->lbDurationMinutes3->Size = System::Drawing::Size(236, 53);
            this->lbDurationMinutes3->TabIndex = 2;
            this->lbDurationMinutes3->Text = L"duration minutes";
            this->lbDurationMinutes3->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            // 
            // tabControl1
            // 
            this->tabControl1->Anchor = System::Windows::Forms::AnchorStyles::None;
            this->tabControl1->Controls->Add(this->tabPage1);
            this->tabControl1->Controls->Add(this->tabPage2);
            this->tabControl1->Font = (gcnew System::Drawing::Font(L"Calibri", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->tabControl1->Location = System::Drawing::Point(30, 236);
            this->tabControl1->Name = L"tabControl1";
            this->tabControl1->SelectedIndex = 0;
            this->tabControl1->Size = System::Drawing::Size(1015, 509);
            this->tabControl1->TabIndex = 3;
            // 
            // tabPage1
            // 
            this->tabPage1->BackColor = System::Drawing::Color::Tomato;
            this->tabPage1->Controls->Add(this->button1);
            this->tabPage1->Controls->Add(this->tableLayoutPanel1);
            this->tabPage1->Location = System::Drawing::Point(4, 24);
            this->tabPage1->Name = L"tabPage1";
            this->tabPage1->Padding = System::Windows::Forms::Padding(3);
            this->tabPage1->Size = System::Drawing::Size(1007, 481);
            this->tabPage1->TabIndex = 0;
            this->tabPage1->Text = L"Appointment";
            // 
            // button1
            // 
            this->button1->Anchor = System::Windows::Forms::AnchorStyles::None;
            this->button1->Font = (gcnew System::Drawing::Font(L"Calibri", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->button1->Location = System::Drawing::Point(458, 323);
            this->button1->Name = L"button1";
            this->button1->Size = System::Drawing::Size(122, 43);
            this->button1->TabIndex = 3;
            this->button1->Text = L"Cancel";
            this->button1->UseVisualStyleBackColor = true;
            this->button1->Click += gcnew System::EventHandler(this, &DoctorDashboard::button1_Click);
            // 
            // tabPage2
            // 
            this->tabPage2->BackColor = System::Drawing::Color::Tomato;
            this->tabPage2->Controls->Add(this->btnMedicalRecordSubmit);
            this->tabPage2->Controls->Add(this->tableLayoutPanel2);
            this->tabPage2->Location = System::Drawing::Point(4, 24);
            this->tabPage2->Name = L"tabPage2";
            this->tabPage2->Padding = System::Windows::Forms::Padding(3);
            this->tabPage2->Size = System::Drawing::Size(1007, 481);
            this->tabPage2->TabIndex = 1;
            this->tabPage2->Text = L"Write Medical Record";
            // 
            // btnMedicalRecordSubmit
            // 
            this->btnMedicalRecordSubmit->Anchor = System::Windows::Forms::AnchorStyles::None;
            this->btnMedicalRecordSubmit->Font = (gcnew System::Drawing::Font(L"Calibri", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->btnMedicalRecordSubmit->Location = System::Drawing::Point(464, 420);
            this->btnMedicalRecordSubmit->Name = L"btnMedicalRecordSubmit";
            this->btnMedicalRecordSubmit->Size = System::Drawing::Size(120, 41);
            this->btnMedicalRecordSubmit->TabIndex = 1;
            this->btnMedicalRecordSubmit->Text = L"Submit";
            this->btnMedicalRecordSubmit->UseVisualStyleBackColor = true;
            this->btnMedicalRecordSubmit->Click += gcnew System::EventHandler(this, &DoctorDashboard::btnMedicalRecordSubmit_Click);
            // 
            // tableLayoutPanel2
            // 
            this->tableLayoutPanel2->Anchor = System::Windows::Forms::AnchorStyles::None;
            this->tableLayoutPanel2->ColumnCount = 2;
            this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
                25.52255F)));
            this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
                74.47745F)));
            this->tableLayoutPanel2->Controls->Add(this->tbxRefills, 1, 5);
            this->tableLayoutPanel2->Controls->Add(this->tbxInstructions, 1, 4);
            this->tableLayoutPanel2->Controls->Add(this->tbxDosage, 1, 3);
            this->tableLayoutPanel2->Controls->Add(this->label8, 0, 5);
            this->tableLayoutPanel2->Controls->Add(this->tbxMedicationName, 1, 2);
            this->tableLayoutPanel2->Controls->Add(this->label18, 0, 4);
            this->tableLayoutPanel2->Controls->Add(this->tbxDiagnosis, 1, 1);
            this->tableLayoutPanel2->Controls->Add(this->label17, 0, 3);
            this->tableLayoutPanel2->Controls->Add(this->tbxAppointmentId, 1, 0);
            this->tableLayoutPanel2->Controls->Add(this->label16, 0, 2);
            this->tableLayoutPanel2->Controls->Add(this->label7, 0, 0);
            this->tableLayoutPanel2->Controls->Add(this->label15, 0, 1);
            this->tableLayoutPanel2->Location = System::Drawing::Point(47, 94);
            this->tableLayoutPanel2->Name = L"tableLayoutPanel2";
            this->tableLayoutPanel2->RowCount = 6;
            this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 16.66667F)));
            this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 16.66667F)));
            this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 16.66667F)));
            this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 16.66667F)));
            this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 16.66667F)));
            this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 16.66667F)));
            this->tableLayoutPanel2->Size = System::Drawing::Size(909, 297);
            this->tableLayoutPanel2->TabIndex = 0;
            // 
            // tbxRefills
            // 
            this->tbxRefills->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
            this->tbxRefills->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->tbxRefills->Location = System::Drawing::Point(234, 255);
            this->tbxRefills->Name = L"tbxRefills";
            this->tbxRefills->Size = System::Drawing::Size(672, 32);
            this->tbxRefills->TabIndex = 0;
            // 
            // tbxInstructions
            // 
            this->tbxInstructions->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
            this->tbxInstructions->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->tbxInstructions->Location = System::Drawing::Point(234, 204);
            this->tbxInstructions->Name = L"tbxInstructions";
            this->tbxInstructions->Size = System::Drawing::Size(672, 32);
            this->tbxInstructions->TabIndex = 0;
            // 
            // tbxDosage
            // 
            this->tbxDosage->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
            this->tbxDosage->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->tbxDosage->Location = System::Drawing::Point(234, 155);
            this->tbxDosage->Name = L"tbxDosage";
            this->tbxDosage->Size = System::Drawing::Size(672, 32);
            this->tbxDosage->TabIndex = 0;
            // 
            // label8
            // 
            this->label8->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->label8->Font = (gcnew System::Drawing::Font(L"Calibri", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label8->Location = System::Drawing::Point(3, 245);
            this->label8->Name = L"label8";
            this->label8->Size = System::Drawing::Size(225, 52);
            this->label8->TabIndex = 1;
            this->label8->Text = L"Refills";
            this->label8->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            // 
            // tbxMedicationName
            // 
            this->tbxMedicationName->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
            this->tbxMedicationName->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->tbxMedicationName->Location = System::Drawing::Point(234, 106);
            this->tbxMedicationName->Name = L"tbxMedicationName";
            this->tbxMedicationName->Size = System::Drawing::Size(672, 32);
            this->tbxMedicationName->TabIndex = 0;
            // 
            // label18
            // 
            this->label18->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->label18->Font = (gcnew System::Drawing::Font(L"Calibri", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label18->Location = System::Drawing::Point(3, 196);
            this->label18->Name = L"label18";
            this->label18->Size = System::Drawing::Size(225, 49);
            this->label18->TabIndex = 1;
            this->label18->Text = L"Instructions";
            this->label18->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            // 
            // tbxDiagnosis
            // 
            this->tbxDiagnosis->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
            this->tbxDiagnosis->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->tbxDiagnosis->Location = System::Drawing::Point(234, 57);
            this->tbxDiagnosis->Name = L"tbxDiagnosis";
            this->tbxDiagnosis->Size = System::Drawing::Size(672, 32);
            this->tbxDiagnosis->TabIndex = 0;
            // 
            // label17
            // 
            this->label17->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->label17->Font = (gcnew System::Drawing::Font(L"Calibri", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label17->Location = System::Drawing::Point(3, 147);
            this->label17->Name = L"label17";
            this->label17->Size = System::Drawing::Size(225, 49);
            this->label17->TabIndex = 1;
            this->label17->Text = L"Dosage";
            this->label17->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            // 
            // tbxAppointmentId
            // 
            this->tbxAppointmentId->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
            this->tbxAppointmentId->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->tbxAppointmentId->Location = System::Drawing::Point(234, 8);
            this->tbxAppointmentId->Name = L"tbxAppointmentId";
            this->tbxAppointmentId->Size = System::Drawing::Size(672, 32);
            this->tbxAppointmentId->TabIndex = 0;
            // 
            // label16
            // 
            this->label16->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->label16->Font = (gcnew System::Drawing::Font(L"Calibri", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label16->Location = System::Drawing::Point(3, 98);
            this->label16->Name = L"label16";
            this->label16->Size = System::Drawing::Size(225, 49);
            this->label16->TabIndex = 1;
            this->label16->Text = L"Medication Name";
            this->label16->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            // 
            // label7
            // 
            this->label7->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->label7->Font = (gcnew System::Drawing::Font(L"Calibri", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label7->Location = System::Drawing::Point(3, 0);
            this->label7->Name = L"label7";
            this->label7->Size = System::Drawing::Size(225, 49);
            this->label7->TabIndex = 1;
            this->label7->Text = L"ID";
            this->label7->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            // 
            // label15
            // 
            this->label15->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->label15->Font = (gcnew System::Drawing::Font(L"Calibri", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label15->Location = System::Drawing::Point(3, 49);
            this->label15->Name = L"label15";
            this->label15->Size = System::Drawing::Size(225, 49);
            this->label15->TabIndex = 1;
            this->label15->Text = L"Diagnosis";
            this->label15->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            // 
            // DoctorDashboard
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->BackColor = System::Drawing::Color::Red;
            this->ClientSize = System::Drawing::Size(1078, 803);
            this->Controls->Add(this->tabControl1);
            this->Controls->Add(this->lbDoctor);
            this->Controls->Add(this->label1);
            this->MinimumSize = System::Drawing::Size(1096, 850);
            this->Name = L"DoctorDashboard";
            this->Text = L"PatientDashboardForm";
            this->tableLayoutPanel1->ResumeLayout(false);
            this->tabControl1->ResumeLayout(false);
            this->tabPage1->ResumeLayout(false);
            this->tabPage2->ResumeLayout(false);
            this->tableLayoutPanel2->ResumeLayout(false);
            this->tableLayoutPanel2->PerformLayout();
            this->ResumeLayout(false);
            this->PerformLayout();

        }
#pragma endregion
	

    private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
        this->Close();
    }
    private: System::Void btnMedicalRecordSubmit_Click(System::Object^ sender, System::EventArgs^ e) {
        try {
            String^ connString = "Data Source=localhost\\sqlexpress;Initial Catalog=test;Integrated Security=True;Encrypt=True;TrustServerCertificate=True";
            SqlConnection sqlConn(connString);
            sqlConn.Open();

            String^ sqlQuery = "INSERT INTO medical_record (appointment_id, diagnosis) VALUES (@appointmentId, @diagnosis);";
            SqlCommand command(sqlQuery, % sqlConn);
            command.Parameters->AddWithValue("@appointmentId",Int32::Parse(tbxAppointmentId->Text));
            command.Parameters->AddWithValue("@diagnosis", this->tbxDiagnosis->Text);
            int rowsAffected = command.ExecuteNonQuery();

            String^ sqlQuery2 = "SELECT record_id FROM medical_record WHERE appointment_id = @appointmentId;";
            SqlCommand command2(sqlQuery2, % sqlConn);
            command2.Parameters->AddWithValue("@appointmentId", Int32::Parse(tbxAppointmentId->Text));
            SqlDataReader^ reader9 = command2.ExecuteReader();
            if (reader9->Read()) {
                int recordId = reader9->GetInt32(0);
                reader9->Close();
                String^ sqlQuery3 = "INSERT INTO prescription (record_id, medication_name, dosage, instructions, refills) VALUES (@recordId, @medicationName, @dosage, @instructions, @refills);";
                SqlCommand command3(sqlQuery3, % sqlConn);
                command3.Parameters->AddWithValue("@recordId", recordId);
                command3.Parameters->AddWithValue("@medicationName", this->tbxMedicationName->Text);
                command3.Parameters->AddWithValue("@dosage", this->tbxDosage->Text);
                command3.Parameters->AddWithValue("@instructions", this->tbxInstructions->Text);
                command3.Parameters->AddWithValue("@refills", this->tbxRefills->Text);
                command3.ExecuteNonQuery();
            }
            
            if (rowsAffected > 0) {
                MessageBox::Show("Record added!",
                    "Success", MessageBoxButtons::OK);
                this->Close();
            }
            else {
                MessageBox::Show("Unable to add record ",
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
