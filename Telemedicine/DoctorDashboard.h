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
    private: System::Windows::Forms::DataGridView^ dataGridView1;
    private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column1;
    private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column2;
    private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column3;
    private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column4;
    private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column5;










    public:
        Appointment^ appointment3 = nullptr;
        DoctorDashboard(Doctor^ doctor)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
            this->CenterToScreen();

            this->doctor = doctor;
            this->lbDoctor->Text = String::Concat(" Dr.", doctor->doctorFirstName);
            try {
                String^ connString = "Data Source=localhost\\sqlexpress;Initial Catalog=test;Integrated Security=True;Encrypt=True;TrustServerCertificate=True";
                SqlConnection sqlConn(connString);
                sqlConn.Open();

                // Modified query to get both appointment and patient data in one query
                String^ sqlQuery = "SELECT  a.appointment_id, a.patient_id, a.scheduled_time, "
                    "a.duration_minutes, a.status, p.first_name, p.last_name "
                    "FROM appointment a "
                    "INNER JOIN patient p ON a.patient_id = p.patient_id "
                    "WHERE a.doctor_id = @doctorId "
                    "ORDER BY a.scheduled_time;";

                SqlCommand command(sqlQuery, % sqlConn);
                command.Parameters->AddWithValue("@doctorId", doctor->id);

                SqlDataReader^ reader = command.ExecuteReader();
                //Appointment^ currentAppointment = nullptr;
                while (reader->Read())
                {

                    int appointmentId = safe_cast<int>(reader["appointment_id"]);
                    String^ patientFirstName = safe_cast<String^>(reader["first_name"]);
                    String^ patientLastName = safe_cast<String^>(reader["last_name"]);
                    String^ formattedTime = (reader["scheduled_time"]->ToString());
                    int durationMinutes = safe_cast<int>(reader["duration_minutes"]);
                    String^ status = safe_cast<String^>(reader["status"]);
                    this->dataGridView1->Rows->Add(appointmentId, patientFirstName + " " + patientLastName, formattedTime, durationMinutes, status);

                }

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


	private: System::Windows::Forms::TabControl^ tabControl1;
	private: System::Windows::Forms::TabPage^ tabPage1;
	private: System::Windows::Forms::TabPage^ tabPage2;

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
            this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
            this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
            this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
            this->Column1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->Column2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->Column3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->Column4 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->Column5 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
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
            this->tabControl1->SuspendLayout();
            this->tabPage1->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
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
            this->tabPage1->Controls->Add(this->dataGridView1);
            this->tabPage1->Controls->Add(this->button1);
            this->tabPage1->Location = System::Drawing::Point(4, 24);
            this->tabPage1->Name = L"tabPage1";
            this->tabPage1->Padding = System::Windows::Forms::Padding(3);
            this->tabPage1->Size = System::Drawing::Size(1007, 481);
            this->tabPage1->TabIndex = 0;
            this->tabPage1->Text = L"Appointment";
            // 
            // dataGridView1
            // 
            this->dataGridView1->AllowUserToAddRows = false;
            this->dataGridView1->AllowUserToDeleteRows = false;
            this->dataGridView1->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
            this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
            this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(5) {
                this->Column1,
                    this->Column2, this->Column3, this->Column4, this->Column5
            });
            this->dataGridView1->Location = System::Drawing::Point(-4, 0);
            this->dataGridView1->Name = L"dataGridView1";
            this->dataGridView1->ReadOnly = true;
            this->dataGridView1->RowHeadersWidth = 51;
            this->dataGridView1->RowTemplate->Height = 24;
            this->dataGridView1->Size = System::Drawing::Size(1011, 317);
            this->dataGridView1->TabIndex = 4;
            // 
            // Column1
            // 
            this->Column1->HeaderText = L"ID";
            this->Column1->MinimumWidth = 6;
            this->Column1->Name = L"Column1";
            // 
            // Column2
            // 
            this->Column2->HeaderText = L"Patient Name";
            this->Column2->MinimumWidth = 6;
            this->Column2->Name = L"Column2";
            // 
            // Column3
            // 
            this->Column3->HeaderText = L"Schedule Time";
            this->Column3->MinimumWidth = 6;
            this->Column3->Name = L"Column3";
            // 
            // Column4
            // 
            this->Column4->HeaderText = L"Duration Minutes";
            this->Column4->MinimumWidth = 6;
            this->Column4->Name = L"Column4";
            // 
            // Column5
            // 
            this->Column5->HeaderText = L"Status";
            this->Column5->MinimumWidth = 6;
            this->Column5->Name = L"Column5";
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
            this->tabControl1->ResumeLayout(false);
            this->tabPage1->ResumeLayout(false);
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
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
