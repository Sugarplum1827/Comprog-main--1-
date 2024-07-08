#pragma once

#include "All_Patient.h"
#include "Signupform.h"
#include "Patient_Information.h"

namespace Project1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Data::SqlClient; // Include ADO.NET library

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
		}

	protected:
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Button^ ViewPatient;
	private: System::Windows::Forms::Button^ AddPatient;
	private: System::Windows::Forms::ComboBox^ Search_Patient;
	private: System::Windows::Forms::Label^ SrchPatient;
	private: System::DirectoryServices::DirectorySearcher^ directorySearcher1;
	private: System::Windows::Forms::Label^ Patient_number;
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ exitToolStripMenuItem;
	private: System::Windows::Forms::Label^ PatientRecords;

	protected:

	private:
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->ViewPatient = (gcnew System::Windows::Forms::Button());
			this->AddPatient = (gcnew System::Windows::Forms::Button());
			this->Search_Patient = (gcnew System::Windows::Forms::ComboBox());
			this->SrchPatient = (gcnew System::Windows::Forms::Label());
			this->directorySearcher1 = (gcnew System::DirectoryServices::DirectorySearcher());
			this->Patient_number = (gcnew System::Windows::Forms::Label());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->exitToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->PatientRecords = (gcnew System::Windows::Forms::Label());
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// ViewPatient
			// 
			this->ViewPatient->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ViewPatient->Location = System::Drawing::Point(101, 320);
			this->ViewPatient->Name = L"ViewPatient";
			this->ViewPatient->Padding = System::Windows::Forms::Padding(2);
			this->ViewPatient->Size = System::Drawing::Size(301, 45);
			this->ViewPatient->TabIndex = 3;
			this->ViewPatient->Text = L"VIEW ALL PATIENT";
			this->ViewPatient->UseVisualStyleBackColor = true;
			this->ViewPatient->Click += gcnew System::EventHandler(this, &MyForm::ViewPatient_Click);
			// 
			// AddPatient
			// 
			this->AddPatient->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->AddPatient->Location = System::Drawing::Point(145, 269);
			this->AddPatient->Name = L"AddPatient";
			this->AddPatient->Padding = System::Windows::Forms::Padding(2);
			this->AddPatient->Size = System::Drawing::Size(210, 45);
			this->AddPatient->TabIndex = 4;
			this->AddPatient->Text = L"ADD NEW PATIENT";
			this->AddPatient->UseVisualStyleBackColor = true;
			this->AddPatient->Click += gcnew System::EventHandler(this, &MyForm::AddPatient_Click);
			// 
			// Search_Patient
			// 
			this->Search_Patient->FormattingEnabled = true;
			this->Search_Patient->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Select Name" });
			this->Search_Patient->Location = System::Drawing::Point(145, 118);
			this->Search_Patient->Name = L"Search_Patient";
			this->Search_Patient->Size = System::Drawing::Size(210, 21);
			this->Search_Patient->TabIndex = 5;
			this->Search_Patient->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::Search_Patient_SelectedIndexChanged);
			// 
			// SrchPatient
			// 
			this->SrchPatient->AutoSize = true;
			this->SrchPatient->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->SrchPatient->Location = System::Drawing::Point(187, 90);
			this->SrchPatient->Name = L"SrchPatient";
			this->SrchPatient->Size = System::Drawing::Size(123, 29);
			this->SrchPatient->TabIndex = 7;
			this->SrchPatient->Text = L"Patient Name";
			// 
			// directorySearcher1
			// 
			this->directorySearcher1->ClientTimeout = System::TimeSpan::Parse(L"-00:00:01");
			this->directorySearcher1->ServerPageTimeLimit = System::TimeSpan::Parse(L"-00:00:01");
			this->directorySearcher1->ServerTimeLimit = System::TimeSpan::Parse(L"-00:00:01");
			// 
			// Patient_number
			// 
			this->Patient_number->AutoSize = true;
			this->Patient_number->Location = System::Drawing::Point(210, 151);
			this->Patient_number->Name = L"Patient_number";
			this->Patient_number->Size = System::Drawing::Size(52, 13);
			this->Patient_number->TabIndex = 9;
			this->Patient_number->Text = L"PatientID";
			this->Patient_number->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->exitToolStripMenuItem });
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(497, 24);
			this->menuStrip1->TabIndex = 10;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// exitToolStripMenuItem
			// 
			this->exitToolStripMenuItem->Name = L"exitToolStripMenuItem";
			this->exitToolStripMenuItem->Size = System::Drawing::Size(38, 20);
			this->exitToolStripMenuItem->Text = L"Exit";
			this->exitToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::exitToolStripMenuItem_Click);
			// 
			// PatientRecords
			// 
			this->PatientRecords->AutoSize = true;
			this->PatientRecords->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 27.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->PatientRecords->Location = System::Drawing::Point(145, 39);
			this->PatientRecords->Name = L"PatientRecords";
			this->PatientRecords->Size = System::Drawing::Size(210, 43);
			this->PatientRecords->TabIndex = 11;
			this->PatientRecords->Text = L"Patient Records";
			this->PatientRecords->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->PatientRecords->Click += gcnew System::EventHandler(this, &MyForm::label1_Click_2);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::CadetBlue;
			this->ClientSize = System::Drawing::Size(497, 396);
			this->Controls->Add(this->PatientRecords);
			this->Controls->Add(this->Patient_number);
			this->Controls->Add(this->SrchPatient);
			this->Controls->Add(this->Search_Patient);
			this->Controls->Add(this->AddPatient);
			this->Controls->Add(this->ViewPatient);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label1_Click_1(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void Search_Patient_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
		String^ patient = Search_Patient->Text;
		int^ index = Search_Patient->SelectedIndex;

		SrchPatient->Text = patient;
		Patient_number->Text = index->ToString();

		// Retrieve patient information from the database based on the selected patient
		String^ patientInfo = GetPatientInfoFromDatabase(patient); // Implement this function to fetch patient info from the database

		// Navigate to the MyForm12 form with patient information
		MyForm12^ patientInfoForm = gcnew MyForm12(patientInfo);
		patientInfoForm->Show();
	}
	private: System::Void exitToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		Windows::Forms::DialogResult dr = MessageBox::Show("Are you sure you want to Exit?", "Warning", MessageBoxButtons::YesNo, MessageBoxIcon::Warning);

		if (dr == Windows::Forms::DialogResult::Yes) Application::Exit();
	}
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
		// Populate the Search_Patient combo box with patient names from the database
		PopulatePatientComboBox();
	}
	private: System::Void label1_Click_2(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void ViewPatient_Click(System::Object^ sender, System::EventArgs^ e) {
		// Navigate to the All_Patient form
		All_Patient^ allPatientForm = gcnew All_Patient();
		allPatientForm->Show();
	}
	private: System::Void AddPatient_Click(System::Object^ sender, System::EventArgs^ e) {
		// Navigate to the Signupform form
		Signupform^ signupForm = gcnew Signupform();
		signupForm->Show();
	}

	private: void PopulatePatientComboBox()
	{
		String^ connString = "Server=myServerAddress;Database=myDataBase;User Id=myUsername;Password=myPassword;"; // Update with your actual connection string
		SqlConnection^ conn = gcnew SqlConnection(connString);
		try
		{
			conn->Open();
			String^ query = "SELECT Name FROM Patients";
			SqlCommand^ cmd = gcnew SqlCommand(query, conn);
			SqlDataReader^ reader = cmd->ExecuteReader();

			while (reader->Read())
			{
				Search_Patient->Items->Add(reader["Name"]->ToString());
			}
		}
		catch (Exception^ ex)
		{
			MessageBox::Show(ex->Message);
		}
		finally
		{
			conn->Close();
		}
	}

	private: String^ GetPatientInfoFromDatabase(String^ patientName)
	{
		String^ connString = "your_connection_string_here"; // Update with your actual connection string
		SqlConnection^ conn = gcnew SqlConnection(connString);
		String^ patientInfo = "";

		try
		{
			conn->Open();
			String^ query = "SELECT * FROM Patients WHERE Name = @Name";
			SqlCommand^ cmd = gcnew SqlCommand(query, conn);
			cmd->Parameters->AddWithValue("@Name", patientName);
			SqlDataReader^ reader = cmd->ExecuteReader();

			if (reader->Read())
			{
				patientInfo = "Patient Name: " + reader["Name"]->ToString() + "\r\n" +
					"Age: " + reader["Age"]->ToString() + "\r\n" +
					"Gender: " + reader["Gender"]->ToString() + "\r\n" +
					"Medical History: " + reader["MedicalHistory"]->ToString();
			}
		}
		catch (Exception^ ex)
		{
			MessageBox::Show(ex->Message);
		}
		finally
		{
			conn->Close();
		}

		return patientInfo;
	}
};
}
