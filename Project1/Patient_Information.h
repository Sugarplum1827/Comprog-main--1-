#pragma once

#include <string>
#include <msclr/marshal_cppstd.h>
#include <System::Data::SqlClient.h>

namespace Project1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Data::SqlClient;

	/// <summary>
	/// Summary for MyForm12
	/// </summary>
	public ref class MyForm12 : public System::Windows::Forms::Form
	{
	public:
		MyForm12(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm12()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::TextBox^ PatientInfobox;
	private: System::Windows::Forms::TextBox^ SearchBox;
	private: System::Windows::Forms::Button^ SearchButton;

	private: System::ComponentModel::BackgroundWorker^ backgroundWorker1;
	private: System::Windows::Forms::Label^ PatientInformation;
	protected:

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
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->PatientInfobox = (gcnew System::Windows::Forms::TextBox());
			this->backgroundWorker1 = (gcnew System::ComponentModel::BackgroundWorker());
			this->PatientInformation = (gcnew System::Windows::Forms::Label());
			this->SearchBox = (gcnew System::Windows::Forms::TextBox());
			this->SearchButton = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(12, 12);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(73, 30);
			this->button2->TabIndex = 0;
			this->button2->Text = L"Back";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm12::button2_Click);
			// 
			// PatientInfobox
			// 
			this->PatientInfobox->Location = System::Drawing::Point(76, 75);
			this->PatientInfobox->Multiline = true;
			this->PatientInfobox->Name = L"PatientInfobox";
			this->PatientInfobox->Size = System::Drawing::Size(390, 228);
			this->PatientInfobox->TabIndex = 2;
			// 
			// PatientInformation
			// 
			this->PatientInformation->AutoSize = true;
			this->PatientInformation->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->PatientInformation->Location = System::Drawing::Point(70, 30);
			this->PatientInformation->Name = L"PatientInformation";
			this->PatientInformation->Size = System::Drawing::Size(234, 37);
			this->PatientInformation->TabIndex = 3;
			this->PatientInformation->Text = L"Patient Information";
			// 
			// SearchBox
			// 
			this->SearchBox->Location = System::Drawing::Point(376, 36);
			this->SearchBox->Name = L"SearchBox";
			this->SearchBox->Size = System::Drawing::Size(100, 20);
			this->SearchBox->TabIndex = 4;
			// 
			// SearchButton
			// 
			this->SearchButton->Location = System::Drawing::Point(482, 33);
			this->SearchButton->Name = L"SearchButton";
			this->SearchButton->Size = System::Drawing::Size(75, 23);
			this->SearchButton->TabIndex = 5;
			this->SearchButton->Text = L"Search";
			this->SearchButton->UseVisualStyleBackColor = true;
			this->SearchButton->Click += gcnew System::EventHandler(this, &MyForm12::SearchButton_Click);
			// 
			// MyForm12
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::CadetBlue;
			this->ClientSize = System::Drawing::Size(586, 377);
			this->Controls->Add(this->SearchButton);
			this->Controls->Add(this->SearchBox);
			this->Controls->Add(this->PatientInformation);
			this->Controls->Add(this->PatientInfobox);
			this->Controls->Add(this->button2);
			this->Name = L"MyForm12";
			this->Text = L"MyForm12";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private:
		System::Void button2_Click(System::Object^ sender, System::EventArgs^ e)
		{
			// Navigate back to MyForm11
			MyForm11^ form11 = gcnew MyForm11();
			form11->Show();
			this->Hide();
		}

		System::Void SearchButton_Click(System::Object^ sender, System::EventArgs^ e)
		{
			String^ patientName = SearchBox->Text;
			PatientInfobox->Clear();
			
			if (String::IsNullOrEmpty(patientName))
			{
				MessageBox::Show("Please enter a patient name to search.");
				return;
			}

			// Fetch patient details from the database
			String^ connString = "Server=myServerAddress;Database=myDataBase;User Id=myUsername;Password=myPassword;"; // Update with your actual connection string
			SqlConnection^ conn = gcnew SqlConnection(connString);

			try
			{
				conn->Open();
				String^ query = "SELECT * FROM Patients WHERE Name = @name";
				SqlCommand^ cmd = gcnew SqlCommand(query, conn);
				cmd->Parameters->AddWithValue("@name", patientName);
				SqlDataReader^ reader = cmd->ExecuteReader();

				if (reader->Read())
				{
					// Display patient information
					PatientInfobox->AppendText("Name: " + reader["Name"]->ToString() + Environment::NewLine);
					PatientInfobox->AppendText("Age: " + reader["Age"]->ToString() + Environment::NewLine);
					PatientInfobox->AppendText("Gender: " + reader["Gender"]->ToString() + Environment::NewLine);
					PatientInfobox->AppendText("Address: " + reader["Address"]->ToString() + Environment::NewLine);
					PatientInfobox->AppendText("Birthplace: " + reader["Name"]->ToString() + Environment::NewLine);
					PatientInfobox->AppendText("Nationality: " + reader["Age"]->ToString() + Environment::NewLine);
					PatientInfobox->AppendText("Religion: " + reader["Gender"]->ToString() + Environment::NewLine);
					PatientInfobox->AppendText("Civil Status: " + reader["Address"]->ToString() + Environment::NewLine);PatientInfobox->AppendText("Name: " + reader["Name"]->ToString() + Environment::NewLine);
					PatientInfobox->AppendText("BirthDate: " + reader["Age"]->ToString() + Environment::NewLine);
					PatientInfobox->AppendText("Bloodtype: " + reader["Gender"]->ToString() + Environment::NewLine);
					PatientInfobox->AppendText("Email: " + reader["Address"]->ToString() + Environment::NewLine);
					PatientInfobox->AppendText("Diagnosis: " + reader["Address"]->ToString() + Environment::NewLine);
				}
				else
				{
					PatientInfobox->AppendText("No patient found with this name." + Environment::NewLine);
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
	};
}
