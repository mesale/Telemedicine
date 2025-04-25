#pragma once
#include"Patient.h"
namespace Telemedicine {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for PatientDashboard
	/// </summary>
	
	public ref class PatientDashboard : public System::Windows::Forms::Form
	{
	public:
		
		PatientDashboard(Patient^ patient)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			this->lbPatientName->Text = patient->patientFirstName;
			this->CenterToScreen();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~PatientDashboard()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ lbPatientName;

	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel1;
	private: System::Windows::Forms::Button^ btnBookAppointment;
	private: System::Windows::Forms::Button^ btnSeeAppointment;
	private: System::Windows::Forms::Button^ btnSeeMedicalRecord;



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
			this->lbPatientName = (gcnew System::Windows::Forms::Label());
			this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->btnBookAppointment = (gcnew System::Windows::Forms::Button());
			this->btnSeeAppointment = (gcnew System::Windows::Forms::Button());
			this->btnSeeMedicalRecord = (gcnew System::Windows::Forms::Button());
			this->tableLayoutPanel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Calibri", 36, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(172, 58);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(265, 73);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Welcome";
			// 
			// lbPatientName
			// 
			this->lbPatientName->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->lbPatientName->Font = (gcnew System::Drawing::Font(L"Calibri", 22.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbPatientName->Location = System::Drawing::Point(121, 151);
			this->lbPatientName->Name = L"lbPatientName";
			this->lbPatientName->Size = System::Drawing::Size(343, 43);
			this->lbPatientName->TabIndex = 1;
			this->lbPatientName->Text = L"Patient";
			this->lbPatientName->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// tableLayoutPanel1
			// 
			this->tableLayoutPanel1->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->tableLayoutPanel1->ColumnCount = 3;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				33.33333F)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				33.33333F)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				33.33333F)));
			this->tableLayoutPanel1->Controls->Add(this->btnBookAppointment, 0, 0);
			this->tableLayoutPanel1->Controls->Add(this->btnSeeAppointment, 1, 0);
			this->tableLayoutPanel1->Controls->Add(this->btnSeeMedicalRecord, 2, 0);
			this->tableLayoutPanel1->Location = System::Drawing::Point(49, 308);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 1;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(504, 63);
			this->tableLayoutPanel1->TabIndex = 2;
			// 
			// btnBookAppointment
			// 
			this->btnBookAppointment->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->btnBookAppointment->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnBookAppointment->Location = System::Drawing::Point(3, 3);
			this->btnBookAppointment->Name = L"btnBookAppointment";
			this->btnBookAppointment->Size = System::Drawing::Size(162, 57);
			this->btnBookAppointment->TabIndex = 0;
			this->btnBookAppointment->TabStop = false;
			this->btnBookAppointment->Text = L"Book Appointmrnt";
			this->btnBookAppointment->UseVisualStyleBackColor = true;
			this->btnBookAppointment->Click += gcnew System::EventHandler(this, &PatientDashboard::btnBookAppointment_Click);
			// 
			// btnSeeAppointment
			// 
			this->btnSeeAppointment->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->btnSeeAppointment->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnSeeAppointment->Location = System::Drawing::Point(171, 3);
			this->btnSeeAppointment->Name = L"btnSeeAppointment";
			this->btnSeeAppointment->Size = System::Drawing::Size(162, 57);
			this->btnSeeAppointment->TabIndex = 1;
			this->btnSeeAppointment->TabStop = false;
			this->btnSeeAppointment->Text = L"See Appointments";
			this->btnSeeAppointment->UseVisualStyleBackColor = true;
			this->btnSeeAppointment->Click += gcnew System::EventHandler(this, &PatientDashboard::btnSeeAppointment_Click);
			// 
			// btnSeeMedicalRecord
			// 
			this->btnSeeMedicalRecord->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->btnSeeMedicalRecord->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnSeeMedicalRecord->Location = System::Drawing::Point(339, 3);
			this->btnSeeMedicalRecord->Name = L"btnSeeMedicalRecord";
			this->btnSeeMedicalRecord->Size = System::Drawing::Size(162, 57);
			this->btnSeeMedicalRecord->TabIndex = 2;
			this->btnSeeMedicalRecord->TabStop = false;
			this->btnSeeMedicalRecord->Text = L"See Medical Record";
			this->btnSeeMedicalRecord->UseVisualStyleBackColor = true;
			this->btnSeeMedicalRecord->Click += gcnew System::EventHandler(this, &PatientDashboard::btnSeeMedicalRecord_Click);
			// 
			// PatientDashboard
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::LightSeaGreen;
			this->ClientSize = System::Drawing::Size(606, 535);
			this->Controls->Add(this->tableLayoutPanel1);
			this->Controls->Add(this->lbPatientName);
			this->Controls->Add(this->label1);
			this->MinimumSize = System::Drawing::Size(624, 582);
			this->Name = L"PatientDashboard";
			this->Text = L"PatientDashboard";
			this->tableLayoutPanel1->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion


	public: bool isBookAppointment = false;

	private: System::Void btnBookAppointment_Click(System::Object^ sender, System::EventArgs^ e) {
		this->isBookAppointment = true;
		this->Close();
	}

	public: bool isSeeAppointment = false;

	private: System::Void btnSeeAppointment_Click(System::Object^ sender, System::EventArgs^ e) {
		this->isSeeAppointment = true;
		this->Close();
	}

	public: bool isMedicalRecord = false;

	private: System::Void btnSeeMedicalRecord_Click(System::Object^ sender, System::EventArgs^ e) {
		this->isMedicalRecord = true;
		this->Close();
	}
};
}
