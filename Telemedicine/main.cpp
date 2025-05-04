#include <windows.h>
#include <Unknwn.h>// For Windows IServiceProvider
#include"PatientLogin.h"
#include"DoctorLogin.h"
#include "MainMenu.h"
#include"PatientDashboard.h"
#include"DoctorDashboard.h"
#include"BookAppointment.h"
#include"SeeAppointment.h"
#include"PatientMedicalRecord.h"
#include"PatientRegister.h"


using namespace System;
using namespace System::Windows::Forms;

[System::STAThreadAttribute]
int APIENTRY wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPWSTR lpCmdLine, int nCmdShow)
{
    // Initialize COM
    //System::Threading::Thread::CurrentThread->ApartmentState = System::Threading::ApartmentState::STA;

    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    //Telemedicine::PatientLogin patientLogin;
    //patientLogin.ShowDialog();
    Patient^ patient = nullptr; 
    Doctor^ doctor = nullptr;
    while (true) {
        Telemedicine::MainMenu mainMenu;
        mainMenu.ShowDialog();
        if (mainMenu.isPatient) {

            while (true) {
                Telemedicine::PatientLogin patientLogin;
                patientLogin.ShowDialog();
                if (patientLogin.switchToRegister) {
                    Telemedicine::PatientRegister patientRegister;
                    patientRegister.ShowDialog();
                    if (!patientRegister.switchToLogin) {
                        patient = patientRegister.patient;
                        break;
                    }
                    else {
                        continue;
                    }
                }
                else {
                    patient = patientLogin.patient;
                    break;
                }
            }
            if (patient != nullptr) {

                while (true) {
                    Telemedicine::PatientDashboard patientDashboard(patient);
                    patientDashboard.ShowDialog();

                    if (patientDashboard.isBookAppointment) {
                        Telemedicine::BookAppointment bookAppointment(patient);
                        bookAppointment.ShowDialog();
                        continue;

                    }
                    else if (patientDashboard.isSeeAppointment) {
                        Telemedicine::SeeAppointment seeAppointment(patient);
                        seeAppointment.ShowDialog();
                        continue;
                    }
                    else if (patientDashboard.isMedicalRecord) {
                        Telemedicine::PatientMedicalRecord patientMedicalRecord(patient);
                        patientMedicalRecord.ShowDialog();
                        continue;
                    }
                    else
                        break;
                }

            }
            continue;
        }
        else if (mainMenu.isDoctor) {
            Telemedicine::DoctorLogin doctorLogin;
            doctorLogin.ShowDialog();
            doctor = doctorLogin.doctor;
            if (doctor != nullptr) {
                Telemedicine::DoctorDashboard doctorDashboard(doctor);
                doctorDashboard.ShowDialog();
            }
            continue;
        }
        else
            break;
    }

        
           
    

    if (patient != nullptr)
    {
        MessageBox::Show("Autentication successful " + patient->patientFirstName,
            "Successful", MessageBoxButtons::OK);

    }
    
    else if (doctor != nullptr) {
        MessageBox::Show("Autentication successful " + doctor->doctorFirstName,
            "Successful", MessageBoxButtons::OK);
    }

    else
    {
        MessageBox::Show("Authentication canceled",
            "Source.cpp",
            MessageBoxButtons::OK);
    }

    return 0;
}