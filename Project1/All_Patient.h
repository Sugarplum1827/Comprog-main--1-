#pragma once

#include "Search_Patient.h"
#include <string>
#include <vector>
#include <msclr/marshal_cppstd.h>
#include <System::Data::SqlClient.h>

std::vector<std::string> GetAllPatientNames();

namespace Project1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Data::SqlClient;

	/// <summary>
	/// Summary for MyForm11
	/// </summary>
	public ref class MyForm11 : public System::Windows::Forms::Form
	{
	public:
		MyForm11(void)
		{
			InitializeComponent();
			//
			// Fetch and display patient names
			//
			DisplayPatientNames();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm11()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::TextBox^ Title;
	private: System::Windows::Forms::TextBox^ PatientInfobox;

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
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->Title = (gcnew System::Windows::Forms::TextBox());
			this->PatientInfobox = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(12, 12);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(74, 29);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Back";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm11::button1_Click);
			// 
			// Title
			// 
			this->Title->BackColor = System::Drawing::SystemColors::ControlLight;
			this->Title->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->Title->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 36, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Title->Location = System::Drawing::Point(194, 36);
			this->Title->Name = L"Title";
			this->Title->Size = System::Drawing::Size(223, 56);
			this->Title->TabIndex = 1;
			this->Title->Text = L"All Patient";
			this->Title->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// PatientInfobox
			// 
			this->PatientInfobox->Location = System::Drawing::Point(117, 98);
			this->PatientInfobox->Multiline = true;
			this->PatientInfobox->Name = L"PatientInfobox";
			this->PatientInfobox->Size = System::Drawing::Size(401, 236);
			this->PatientInfobox->TabIndex = 3;
			// 
			// MyForm11
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::CadetBlue;
			this->ClientSize = System::Drawing::Size(633, 377);
			this->Controls->Add(this->PatientInfobox);
			this->Controls->Add(this->Title);
			this->Controls->Add(this->button1);
			this->Name = L"MyForm11";
			this->Text = L"MyForm11";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: 
		void DisplayPatientNames()
		{
			// Fetch patient names from the database
			std::vector<std::string> patientNames = GetAllPatientNames();
			
			// Clear the PatientInfobox
			PatientInfobox->Clear();

			// Check if there are any patients
			if (patientNames.empty())
			{
				PatientInfobox->AppendText("There are no patients in the database." + Environment::NewLine);
			}
			else
			{
				// Populate the PatientInfobox with patient names
				for each (std::string name in patientNames)
				{
					PatientInfobox->AppendText(gcnew String(name.c_str()) + Environment::NewLine);
				}
			}
		}

		System::Void button1_Click(System::Object^ sender, System::EventArgs^ e)
		{
			// Navigate to the Search_Patient form
			Search_Patient^ searchPatientForm = gcnew Search_Patient();
			searchPatientForm->Show();
			this->Hide();
		}
	};
}

// Function to fetch patient names from the database
std::vector<std::string> GetAllPatientNames()
{
	std::vector<std::string> patientNames;
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
			std::string name = msclr::interop::marshal_as<std::string>(reader["Name"]->ToString());
			patientNames.push_back(name);
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

	return patientNames;
}
