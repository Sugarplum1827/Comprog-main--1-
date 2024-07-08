#pragma once

#include "Search_Patient.h"
#include <sqlclient.h>

namespace Project1 {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;
    using namespace System::Data::SqlClient; // Add this for SQL connection

    public ref class MyForm1 : public System::Windows::Forms::Form
    {
    public:
        MyForm1(void)
        {
            InitializeComponent();
        }

    protected:
        ~MyForm1()
        {
            if (components)
            {
                delete components;
            }
        }

    private: System::Windows::Forms::TextBox^ Fullname;
    private: System::Windows::Forms::Label^ label1;
    private: System::Windows::Forms::Label^ label2;
    private: System::Windows::Forms::TextBox^ age;
    private: System::Windows::Forms::Label^ label3;
    private: System::Windows::Forms::Label^ label4;
    private: System::Windows::Forms::TextBox^ Contact;
    private: System::Windows::Forms::Label^ label5;
    private: System::Windows::Forms::TextBox^ Address;
    private: System::Windows::Forms::Label^ label6;
    private: System::Windows::Forms::TextBox^ birthplace;
    private: System::Windows::Forms::Label^ label7;
    private: System::Windows::Forms::TextBox^ nationality;
    private: System::Windows::Forms::Label^ label8;
    private: System::Windows::Forms::TextBox^ religion;
    private: System::Windows::Forms::Label^ label9;
    private: System::Windows::Forms::Label^ label10;
    private: System::Windows::Forms::TextBox^ textBox10;
    private: System::Windows::Forms::Label^ label11;
    private: System::Windows::Forms::TextBox^ bloodtype;
    private: System::Windows::Forms::Label^ label12;
    private: System::Windows::Forms::TextBox^ email;
    private: System::Windows::Forms::TextBox^ Diagnosis;
    private: System::Windows::Forms::Button^ button1;
    private: System::Windows::Forms::Button^ button2;
    private: System::Windows::Forms::Button^ BackButton;
    private: System::Windows::Forms::Label^ label14;
    private: System::Windows::Forms::ComboBox^ Gender;
    private: System::Windows::Forms::ComboBox^ CivilStatus;

    private:
        System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
        void InitializeComponent(void)
        {
            this->Fullname = (gcnew System::Windows::Forms::TextBox());
            this->label1 = (gcnew System::Windows::Forms::Label());
            this->label2 = (gcnew System::Windows::Forms::Label());
            this->age = (gcnew System::Windows::Forms::TextBox());
            this->label3 = (gcnew System::Windows::Forms::Label());
            this->label4 = (gcnew System::Windows::Forms::Label());
            this->Contact = (gcnew System::Windows::Forms::TextBox());
            this->label5 = (gcnew System::Windows::Forms::Label());
            this->Address = (gcnew System::Windows::Forms::TextBox());
            this->label6 = (gcnew System::Windows::Forms::Label());
            this->birthplace = (gcnew System::Windows::Forms::TextBox());
            this->label7 = (gcnew System::Windows::Forms::Label());
            this->nationality = (gcnew System::Windows::Forms::TextBox());
            this->label8 = (gcnew System::Windows::Forms::Label());
            this->religion = (gcnew System::Windows::Forms::TextBox());
            this->label9 = (gcnew System::Windows::Forms::Label());
            this->label10 = (gcnew System::Windows::Forms::Label());
            this->textBox10 = (gcnew System::Windows::Forms::TextBox());
            this->label11 = (gcnew System::Windows::Forms::Label());
            this->bloodtype = (gcnew System::Windows::Forms::TextBox());
            this->label12 = (gcnew System::Windows::Forms::Label());
            this->email = (gcnew System::Windows::Forms::TextBox());
            this->Diagnosis = (gcnew System::Windows::Forms::TextBox());
            this->button1 = (gcnew System::Windows::Forms::Button());
            this->button2 = (gcnew System::Windows::Forms::Button());
            this->BackButton = (gcnew System::Windows::Forms::Button());
            this->label14 = (gcnew System::Windows::Forms::Label());
            this->Gender = (gcnew System::Windows::Forms::ComboBox());
            this->CivilStatus = (gcnew System::Windows::Forms::ComboBox());
            this->SuspendLayout();
            // 
            // Fullname
            // 
            this->Fullname->Location = System::Drawing::Point(109, 43);
            this->Fullname->Name = L"Fullname";
            this->Fullname->Size = System::Drawing::Size(207, 20);
            this->Fullname->TabIndex = 0;
            // 
            // label1
            // 
            this->label1->AutoSize = true;
            this->label1->Location = System::Drawing::Point(38, 46);
            this->label1->Name = L"label1";
            this->label1->Size = System::Drawing::Size(52, 13);
            this->label1->TabIndex = 1;
            this->label1->Text = L"Full name";
            // 
            // label2
            // 
            this->label2->AutoSize = true;
            this->label2->Location = System::Drawing::Point(41, 79);
            this->label2->Name = L"label2";
            this->label2->Size = System::Drawing::Size(26, 13);
            this->label2->TabIndex = 2;
            this->label2->Text = L"Age";
            // 
            // age
            // 
            this->age->Location = System::Drawing::Point(109, 79);
            this->age->Name = L"age";
            this->age->Size = System::Drawing::Size(49, 20);
            this->age->TabIndex = 3;
            // 
            // label3
            // 
            this->label3->AutoSize = true;
            this->label3->Location = System::Drawing::Point(41, 113);
            this->label3->Name = L"label3";
            this->label3->Size = System::Drawing::Size(42, 13);
            this->label3->TabIndex = 4;
            this->label3->Text = L"Gender";
            // 
            // label4
            // 
            this->label4->AutoSize = true;
            this->label4->Location = System::Drawing::Point(41, 145);
            this->label4->Name = L"label4";
            this->label4->Size = System::Drawing::Size(44, 13);
            this->label4->TabIndex = 6;
            this->label4->Text = L"Contact";
            // 
            // Contact
            // 
            this->Contact->Location = System::Drawing::Point(109, 145);
            this->Contact->Name = L"Contact";
            this->Contact->Size = System::Drawing::Size(100, 20);
            this->Contact->TabIndex = 7;
            // 
            // label5
            // 
            this->label5->AutoSize = true;
            this->label5->Location = System::Drawing::Point(41, 176);
            this->label5->Name = L"label5";
            this->label5->Size = System::Drawing::Size(45, 13);
            this->label5->TabIndex = 8;
            this->label5->Text = L"Address";
            // 
            // Address
            // 
            this->Address->Location = System::Drawing::Point(109, 176);
            this->Address->Name = L"Address";
            this->Address->Size = System::Drawing::Size(207, 20);
            this->Address->TabIndex = 9;
            // 
            // label6
            // 
            this->label6->AutoSize = true;
            this->label6->Location = System::Drawing::Point(41, 209);
            this->label6->Name = L"label6";
            this->label6->Size = System::Drawing::Size(54, 13);
            this->label6->TabIndex = 10;
            this->label6->Text = L"Birth place";
            // 
            // birthplace
            // 
            this->birthplace->Location = System::Drawing::Point(109, 209);
            this->birthplace->Name = L"birthplace";
            this->birthplace->Size = System::Drawing::Size(207, 20);
            this->birthplace->TabIndex = 11;
            // 
            // label7
            // 
            this->label7->AutoSize = true;
            this->label7->Location = System::Drawing::Point(41, 243);
            this->label7->Name = L"label7";
            this->label7->Size = System::Drawing::Size(56, 13);
            this->label7->TabIndex = 12;
            this->label7->Text = L"Nationality";
            // 
            // nationality
            // 
            this->nationality->Location = System::Drawing::Point(109, 243);
            this->nationality->Name = L"nationality";
            this->nationality->Size = System::Drawing::Size(100, 20);
            this->nationality->TabIndex = 13;
            // 
            // label8
            // 
            this->label8->AutoSize = true;
            this->label8->Location = System::Drawing::Point(41, 278);
            this->label8->Name = L"label8";
            this->label8->Size = System::Drawing::Size(45, 13);
            this->label8->TabIndex = 14;
            this->label8->Text = L"Religion";
            // 
            // religion
            // 
            this->religion->Location = System::Drawing::Point(109, 278);
            this->religion->Name = L"religion";
            this->religion->Size = System::Drawing::Size(100, 20);
            this->religion->TabIndex = 15;
            // 
            // label9
            // 
            this->label9->AutoSize = true;
            this->label9->Location = System::Drawing::Point(41, 312);
            this->label9->Name = L"label9";
            this->label9->Size = System::Drawing::Size(55, 13);
            this->label9->TabIndex = 16;
            this->label9->Text = L"Civil status";
            // 
            // label10
            // 
            this->label10->AutoSize = true;
            this->label10->Location = System::Drawing::Point(41, 343);
            this->label10->Name = L"label10";
            this->label10->Size = System::Drawing::Size(49, 13);
            this->label10->TabIndex = 18;
            this->label10->Text = L"Birthdate";
            // 
            // textBox10
            // 
            this->textBox10->Location = System::Drawing::Point(109, 343);
            this->textBox10->Name = L"textBox10";
            this->textBox10->Size = System::Drawing::Size(100, 20);
            this->textBox10->TabIndex = 19;
            // 
            // label11
            // 
            this->label11->AutoSize = true;
            this->label11->Location = System::Drawing::Point(41, 376);
            this->label11->Name = L"label11";
            this->label11->Size = System::Drawing::Size(55, 13);
            this->label11->TabIndex = 20;
            this->label11->Text = L"Blood type";
            // 
            // bloodtype
            // 
            this->bloodtype->Location = System::Drawing::Point(109, 376);
            this->bloodtype->Name = L"bloodtype";
            this->bloodtype->Size = System::Drawing::Size(49, 20);
            this->bloodtype->TabIndex = 21;
            // 
            // label12
            // 
            this->label12->AutoSize = true;
            this->label12->Location = System::Drawing::Point(41, 406);
            this->label12->Name = L"label12";
            this->label12->Size = System::Drawing::Size(32, 13);
            this->label12->TabIndex = 22;
            this->label12->Text = L"Email";
            // 
            // email
            // 
            this->email->Location = System::Drawing::Point(109, 406);
            this->email->Name = L"email";
            this->email->Size = System::Drawing::Size(100, 20);
            this->email->TabIndex = 23;
            // 
            // Diagnosis
            // 
            this->Diagnosis->Location = System::Drawing::Point(109, 440);
            this->Diagnosis->Name = L"Diagnosis";
            this->Diagnosis->Size = System::Drawing::Size(207, 20);
            this->Diagnosis->TabIndex = 25;
            // 
            // button1
            // 
            this->button1->Location = System::Drawing::Point(44, 488);
            this->button1->Name = L"button1";
            this->button1->Size = System::Drawing::Size(75, 23);
            this->button1->TabIndex = 26;
            this->button1->Text = L"Submit";
            this->button1->UseVisualStyleBackColor = true;
            this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
            // 
            // button2
            // 
            this->button2->Location = System::Drawing::Point(135, 488);
            this->button2->Name = L"button2";
            this->button2->Size = System::Drawing::Size(75, 23);
            this->button2->TabIndex = 27;
            this->button2->Text = L"Clear";
            this->button2->UseVisualStyleBackColor = true;
            this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
            // 
            // Gender
            // 
            this->Gender->FormattingEnabled = true;
            this->Gender->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"Male", L"Female", L"Other" });
            this->Gender->Location = System::Drawing::Point(109, 113);
            this->Gender->Name = L"Gender";
            this->Gender->Size = System::Drawing::Size(100, 21);
            this->Gender->TabIndex = 28;
            // 
            // CivilStatus
            // 
            this->CivilStatus->FormattingEnabled = true;
            this->CivilStatus->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"Single", L"Married", L"Other" });
            this->CivilStatus->Location = System::Drawing::Point(109, 312);
            this->CivilStatus->Name = L"CivilStatus";
            this->CivilStatus->Size = System::Drawing::Size(100, 21);
            this->CivilStatus->TabIndex = 29;
            // 
            // Form1
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(800, 539);
            this->Controls->Add(this->CivilStatus);
            this->Controls->Add(this->Gender);
            this->Controls->Add(this->button2);
            this->Controls->Add(this->button1);
            this->Controls->Add(this->Diagnosis);
            this->Controls->Add(this->email);
            this->Controls->Add(this->label12);
            this->Controls->Add(this->bloodtype);
            this->Controls->Add(this->label11);
            this->Controls->Add(this->textBox10);
            this->Controls->Add(this->label10);
            this->Controls->Add(this->label9);
            this->Controls->Add(this->religion);
            this->Controls->Add(this->label8);
            this->Controls->Add(this->nationality);
            this->Controls->Add(this->label7);
            this->Controls->Add(this->birthplace);
            this->Controls->Add(this->label6);
            this->Controls->Add(this->Address);
            this->Controls->Add(this->label5);
            this->Controls->Add(this->Contact);
            this->Controls->Add(this->label4);
            this->Controls->Add(this->label3);
            this->Controls->Add(this->age);
            this->Controls->Add(this->label2);
            this->Controls->Add(this->label1);
            this->Controls->Add(this->Fullname);
            this->Name = L"Form1";
            this->Text = L"Form1";
            this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
            this->ResumeLayout(false);
            this->PerformLayout();

        }
#pragma endregion
    private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
        Fullname->Clear();
        age->Clear();
        Contact->Clear();
        Address->Clear();
        birthplace->Clear();
        nationality->Clear();
        religion->Clear();
        textBox10->Clear();
        bloodtype->Clear();
        email->Clear();
        Diagnosis->Clear();
        Gender->SelectedIndex = -1;
        CivilStatus->SelectedIndex = -1;
    }

private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
    String^ connectionString = "Server=myServerAddress;Database=myDataBase;User Id=myUsername;Password=myPassword;";

    SqlConnection^ con = gcnew SqlConnection(connectionString);
    SqlCommand^ cmd;

    try {
        con->Open();
        String^ query = "INSERT INTO Patients (FullName, Age, Gender, Contact, Address, BirthPlace, Nationality, Religion, CivilStatus, Birthdate, BloodType, Email, Diagnosis)
VALUES (@FullName, @Age, @Gender, @Contact, @Address, @BirthPlace, @Nationality, @Religion, @CivilStatus, @Birthdate, @BloodType, @Email, @Diagnosis)
";

        cmd = gcnew SqlCommand(query, con);
        cmd->Parameters->AddWithValue("@FullName", Fullname->Text);
        cmd->Parameters->AddWithValue("@Age", age->Text);
        cmd->Parameters->AddWithValue("@Gender", Gender->Text);
        cmd->Parameters->AddWithValue("@Contact", Contact->Text);
        cmd->Parameters->AddWithValue("@Address", Address->Text);
        cmd->Parameters->AddWithValue("@BirthPlace", birthplace->Text);
        cmd->Parameters->AddWithValue("@Nationality", nationality->Text);
        cmd->Parameters->AddWithValue("@Religion", religion->Text);
        cmd->Parameters->AddWithValue("@CivilStatus", CivilStatus->Text);
        cmd->Parameters->AddWithValue("@Birthdate", textBox10->Text);
        cmd->Parameters->AddWithValue("@BloodType", bloodtype->Text);
        cmd->Parameters->AddWithValue("@Email", email->Text);
        cmd->Parameters->AddWithValue("@Diagnosis", Diagnosis->Text);

        cmd->ExecuteNonQuery();

        MessageBox::Show("Patient Information Saved to Database!");
    }
    catch (SqlException^ ex) {
        MessageBox::Show(ex->Message);
    }
    finally {
        con->Close();
    }
}

    private: System::Void Form1_Load(System::Object^ sender, System::EventArgs^ e) {
    }
    };
}

int main()
{
    System::Windows::Forms::Application::Run(gcnew MyApplication::Form1());
    return 0;
}