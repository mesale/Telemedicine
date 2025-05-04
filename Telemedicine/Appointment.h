#pragma once

using namespace System;

public ref class Appointment {
public:
	int appointmentId;
	int patientId;
	int doctorId;
	String^ scheduledTime;
	int durationMinuits;
	String^ status; 
};