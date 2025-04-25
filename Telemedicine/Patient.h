#pragma once

using namespace System;

public ref class Patient {
public:
	int patientId;
	String^ patientFirstName;
	String^ patientLastName;
	String^ patientEmail;
	String^ patientPhone;
	String^ patientPassword;
	String^ patientDateOfBirth;
};