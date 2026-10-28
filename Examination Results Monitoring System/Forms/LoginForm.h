#pragma once



#include "..\Models\Entities.h"

#include "..\Database\DatabaseManager.h"



namespace ExaminationResultsMonitoringSystem {

namespace Forms {



    using namespace System;

    using namespace System::ComponentModel;

    using namespace System::Collections;

    using namespace System::Windows::Forms;

    using namespace System::Data;

    using namespace System::Drawing;

    using namespace ExaminationResultsMonitoringSystem::Models;

    using namespace ExaminationResultsMonitoringSystem::Database;



    public ref class LoginForm : public System::Windows::Forms::Form

    {

    public:

        LoginForm(void)

        {

            InitializeComponent();

            _authenticatedSession = nullptr;

            LoadPredefinedRoles();

        }



        property UserSession^ AuthenticatedSession {

            UserSession^ get() { return _authenticatedSession; }

        }



    protected:

        ~LoginForm()

        {

            if (components)

            {

                delete components;

            }

        }



    private:

        UserSession^ _authenticatedSession;



        System::Windows::Forms::Panel^ panelHeader;

        System::Windows::Forms::Label^ lblSystemBadge;

        System::Windows::Forms::Label^ lblTitle;



        System::Windows::Forms::Panel^ panelCard;

        System::Windows::Forms::Label^ lblLoginTitle;

        System::Windows::Forms::Label^ lblRoleSelect;

        System::Windows::Forms::ComboBox^ cmbPresetRoles;

        System::Windows::Forms::Label^ lblUsername;

        System::Windows::Forms::TextBox^ txtUsername;

        System::Windows::Forms::Label^ lblPassword;

        System::Windows::Forms::TextBox^ txtPassword;

        System::Windows::Forms::Button^ btnLogin;

        System::Windows::Forms::Button^ btnExit;





        System::Windows::Forms::Label^ lblStatus;

        System::ComponentModel::Container ^components;



        void InitializeComponent(void)

        {
            this->panelHeader = (gcnew System::Windows::Forms::Panel());
            this->lblSystemBadge = (gcnew System::Windows::Forms::Label());
            this->lblTitle = (gcnew System::Windows::Forms::Label());
            this->panelCard = (gcnew System::Windows::Forms::Panel());
            this->lblStatus = (gcnew System::Windows::Forms::Label());
            this->btnExit = (gcnew System::Windows::Forms::Button());
            this->btnLogin = (gcnew System::Windows::Forms::Button());
            this->txtPassword = (gcnew System::Windows::Forms::TextBox());
            this->lblPassword = (gcnew System::Windows::Forms::Label());
            this->txtUsername = (gcnew System::Windows::Forms::TextBox());
            this->lblUsername = (gcnew System::Windows::Forms::Label());
            this->cmbPresetRoles = (gcnew System::Windows::Forms::ComboBox());
            this->lblRoleSelect = (gcnew System::Windows::Forms::Label());
            this->lblLoginTitle = (gcnew System::Windows::Forms::Label());
            this->panelHeader->SuspendLayout();
            this->panelCard->SuspendLayout();
            this->SuspendLayout();
            // 
            // panelHeader
            // 
            this->panelHeader->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(15)), static_cast<System::Int32>(static_cast<System::Byte>(23)),
                static_cast<System::Int32>(static_cast<System::Byte>(42)));
            this->panelHeader->Controls->Add(this->lblSystemBadge);
            this->panelHeader->Controls->Add(this->lblTitle);
            this->panelHeader->Dock = System::Windows::Forms::DockStyle::Top;
            this->panelHeader->Location = System::Drawing::Point(0, 0);
            this->panelHeader->Name = L"panelHeader";
            this->panelHeader->Padding = System::Windows::Forms::Padding(35, 18, 35, 18);
            this->panelHeader->Size = System::Drawing::Size(594, 110);
            this->panelHeader->TabIndex = 0;
            // 
            // lblSystemBadge
            // 
            this->lblSystemBadge->AutoSize = true;
            this->lblSystemBadge->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(30)), static_cast<System::Int32>(static_cast<System::Byte>(41)),
                static_cast<System::Int32>(static_cast<System::Byte>(59)));
            this->lblSystemBadge->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 8, System::Drawing::FontStyle::Bold));
            this->lblSystemBadge->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(56)), static_cast<System::Int32>(static_cast<System::Byte>(189)),
                static_cast<System::Int32>(static_cast<System::Byte>(248)));
            this->lblSystemBadge->Location = System::Drawing::Point(35, 18);
            this->lblSystemBadge->Name = L"lblSystemBadge";
            this->lblSystemBadge->Padding = System::Windows::Forms::Padding(6, 2, 6, 2);
            this->lblSystemBadge->Size = System::Drawing::Size(270, 23);
            this->lblSystemBadge->TabIndex = 2;
            this->lblSystemBadge->Text = L"UNIVERSITY ACADEMIC GOVERNANCE";
            // 
            // lblTitle
            // 
            this->lblTitle->AutoSize = true;
            this->lblTitle->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 15.5F, System::Drawing::FontStyle::Bold));
            this->lblTitle->ForeColor = System::Drawing::Color::White;
            this->lblTitle->Location = System::Drawing::Point(33, 42);
            this->lblTitle->Name = L"lblTitle";
            this->lblTitle->Size = System::Drawing::Size(482, 36);
            this->lblTitle->TabIndex = 0;
            this->lblTitle->Text = L"Examination Results Monitoring System";
            // 
            // panelCard
            // 
            this->panelCard->BackColor = System::Drawing::Color::White;
            this->panelCard->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
            this->panelCard->Controls->Add(this->lblStatus);
            this->panelCard->Controls->Add(this->btnExit);
            this->panelCard->Controls->Add(this->btnLogin);
            this->panelCard->Controls->Add(this->txtPassword);
            this->panelCard->Controls->Add(this->lblPassword);
            this->panelCard->Controls->Add(this->txtUsername);
            this->panelCard->Controls->Add(this->lblUsername);
            this->panelCard->Controls->Add(this->cmbPresetRoles);
            this->panelCard->Controls->Add(this->lblRoleSelect);
            this->panelCard->Controls->Add(this->lblLoginTitle);
            this->panelCard->Location = System::Drawing::Point(35, 130);
            this->panelCard->Name = L"panelCard";
            this->panelCard->Padding = System::Windows::Forms::Padding(30);
            this->panelCard->Size = System::Drawing::Size(530, 383);
            this->panelCard->TabIndex = 1;
            // 
            // lblStatus
            // 
            this->lblStatus->AutoSize = true;
            this->lblStatus->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 9, System::Drawing::FontStyle::Bold));
            this->lblStatus->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(220)), static_cast<System::Int32>(static_cast<System::Byte>(38)),
                static_cast<System::Int32>(static_cast<System::Byte>(38)));
            this->lblStatus->Location = System::Drawing::Point(30, 278);
            this->lblStatus->Name = L"lblStatus";
            this->lblStatus->Size = System::Drawing::Size(0, 20);
            this->lblStatus->TabIndex = 10;
            // 
            // btnExit
            // 
            this->btnExit->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(241)), static_cast<System::Int32>(static_cast<System::Byte>(245)),
                static_cast<System::Int32>(static_cast<System::Byte>(249)));
            this->btnExit->Cursor = System::Windows::Forms::Cursors::Hand;
            this->btnExit->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(203)),
                static_cast<System::Int32>(static_cast<System::Byte>(213)), static_cast<System::Int32>(static_cast<System::Byte>(225)));
            this->btnExit->FlatAppearance->MouseDownBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(203)),
                static_cast<System::Int32>(static_cast<System::Byte>(213)), static_cast<System::Int32>(static_cast<System::Byte>(225)));
            this->btnExit->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(226)),
                static_cast<System::Int32>(static_cast<System::Byte>(232)), static_cast<System::Int32>(static_cast<System::Byte>(240)));
            this->btnExit->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->btnExit->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 9.5F, System::Drawing::FontStyle::Bold));
            this->btnExit->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(71)), static_cast<System::Int32>(static_cast<System::Byte>(85)),
                static_cast<System::Int32>(static_cast<System::Byte>(105)));
            this->btnExit->Location = System::Drawing::Point(368, 305);
            this->btnExit->Name = L"btnExit";
            this->btnExit->Size = System::Drawing::Size(130, 42);
            this->btnExit->TabIndex = 8;
            this->btnExit->Text = L"Exit Application";
            this->btnExit->UseVisualStyleBackColor = false;
            this->btnExit->Click += gcnew System::EventHandler(this, &LoginForm::btnExit_Click);
            // 
            // btnLogin
            // 
            this->btnLogin->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(2)), static_cast<System::Int32>(static_cast<System::Byte>(132)),
                static_cast<System::Int32>(static_cast<System::Byte>(199)));
            this->btnLogin->Cursor = System::Windows::Forms::Cursors::Hand;
            this->btnLogin->FlatAppearance->BorderSize = 0;
            this->btnLogin->FlatAppearance->MouseDownBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(7)),
                static_cast<System::Int32>(static_cast<System::Byte>(89)), static_cast<System::Int32>(static_cast<System::Byte>(133)));
            this->btnLogin->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(3)),
                static_cast<System::Int32>(static_cast<System::Byte>(105)), static_cast<System::Int32>(static_cast<System::Byte>(161)));
            this->btnLogin->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->btnLogin->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 10, System::Drawing::FontStyle::Bold));
            this->btnLogin->ForeColor = System::Drawing::Color::White;
            this->btnLogin->Location = System::Drawing::Point(30, 305);
            this->btnLogin->Name = L"btnLogin";
            this->btnLogin->Size = System::Drawing::Size(325, 42);
            this->btnLogin->TabIndex = 7;
            this->btnLogin->Text = L"Sign In to Monitoring Console";
            this->btnLogin->UseVisualStyleBackColor = false;
            this->btnLogin->Click += gcnew System::EventHandler(this, &LoginForm::btnLogin_Click);
            // 
            // txtPassword
            // 
            this->txtPassword->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.5F));
            this->txtPassword->Location = System::Drawing::Point(30, 238);
            this->txtPassword->Name = L"txtPassword";
            this->txtPassword->PasswordChar = '*';
            this->txtPassword->Size = System::Drawing::Size(468, 31);
            this->txtPassword->TabIndex = 6;
            // 
            // lblPassword
            // 
            this->lblPassword->AutoSize = true;
            this->lblPassword->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 9.5F, System::Drawing::FontStyle::Bold));
            this->lblPassword->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)), static_cast<System::Int32>(static_cast<System::Byte>(65)),
                static_cast<System::Int32>(static_cast<System::Byte>(85)));
            this->lblPassword->Location = System::Drawing::Point(28, 218);
            this->lblPassword->Name = L"lblPassword";
            this->lblPassword->Size = System::Drawing::Size(83, 21);
            this->lblPassword->TabIndex = 5;
            this->lblPassword->Text = L"Password:";
            // 
            // txtUsername
            // 
            this->txtUsername->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.5F));
            this->txtUsername->Location = System::Drawing::Point(30, 178);
            this->txtUsername->Name = L"txtUsername";
            this->txtUsername->Size = System::Drawing::Size(468, 31);
            this->txtUsername->TabIndex = 4;
            // 
            // lblUsername
            // 
            this->lblUsername->AutoSize = true;
            this->lblUsername->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 9.5F, System::Drawing::FontStyle::Bold));
            this->lblUsername->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)), static_cast<System::Int32>(static_cast<System::Byte>(65)),
                static_cast<System::Int32>(static_cast<System::Byte>(85)));
            this->lblUsername->Location = System::Drawing::Point(28, 158);
            this->lblUsername->Name = L"lblUsername";
            this->lblUsername->Size = System::Drawing::Size(87, 21);
            this->lblUsername->TabIndex = 3;
            this->lblUsername->Text = L"Username:";
            // 
            // cmbPresetRoles
            // 
            this->cmbPresetRoles->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
            this->cmbPresetRoles->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.75F));
            this->cmbPresetRoles->FormattingEnabled = true;
            this->cmbPresetRoles->Location = System::Drawing::Point(30, 115);
            this->cmbPresetRoles->Name = L"cmbPresetRoles";
            this->cmbPresetRoles->Size = System::Drawing::Size(468, 29);
            this->cmbPresetRoles->TabIndex = 2;
            this->cmbPresetRoles->SelectedIndexChanged += gcnew System::EventHandler(this, &LoginForm::cmbPresetRoles_SelectedIndexChanged);
            // 
            // lblRoleSelect
            // 
            this->lblRoleSelect->AutoSize = true;
            this->lblRoleSelect->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 9.5F, System::Drawing::FontStyle::Bold));
            this->lblRoleSelect->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)), static_cast<System::Int32>(static_cast<System::Byte>(65)),
                static_cast<System::Int32>(static_cast<System::Byte>(85)));
            this->lblRoleSelect->Location = System::Drawing::Point(28, 93);
            this->lblRoleSelect->Name = L"lblRoleSelect";
            this->lblRoleSelect->Size = System::Drawing::Size(294, 21);
            this->lblRoleSelect->TabIndex = 1;
            this->lblRoleSelect->Text = L"Select Role Preset (From Security Doc):";
            // 
            // lblLoginTitle
            // 
            this->lblLoginTitle->AutoSize = true;
            this->lblLoginTitle->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 13.5F, System::Drawing::FontStyle::Bold));
            this->lblLoginTitle->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(15)), static_cast<System::Int32>(static_cast<System::Byte>(23)),
                static_cast<System::Int32>(static_cast<System::Byte>(42)));
            this->lblLoginTitle->Location = System::Drawing::Point(26, 25);
            this->lblLoginTitle->Name = L"lblLoginTitle";
            this->lblLoginTitle->Size = System::Drawing::Size(375, 31);
            this->lblLoginTitle->TabIndex = 0;
            this->lblLoginTitle->Text = L" Login (Role-Based Access Control)\r\n";
            this->lblLoginTitle->Click += gcnew System::EventHandler(this, &LoginForm::lblLoginTitle_Click);
            // 
            // LoginForm
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(8, 19);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(248)), static_cast<System::Int32>(static_cast<System::Byte>(250)),
                static_cast<System::Int32>(static_cast<System::Byte>(252)));
            this->ClientSize = System::Drawing::Size(594, 547);
            this->Controls->Add(this->panelCard);
            this->Controls->Add(this->panelHeader);
            this->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
            this->MaximizeBox = false;
            this->Name = L"LoginForm";
            this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
            this->Text = L"Examination Results Monitoring System - User Authentication";
            this->panelHeader->ResumeLayout(false);
            this->panelHeader->PerformLayout();
            this->panelCard->ResumeLayout(false);
            this->panelCard->PerformLayout();
            this->ResumeLayout(false);

        }



        void LoadPredefinedRoles() {

            cmbPresetRoles->Items->Clear();

            cmbPresetRoles->Items->Add("Assistant Registrar (AR Office) [ar_officer]");

            cmbPresetRoles->Items->Add("Dean (Executive Oversight) [dean_user]");

            cmbPresetRoles->Items->Add("Head of Department (HOD) [hod_comp]");

            cmbPresetRoles->Items->Add("First Examiner / Lecturer [lecturer_user]");

            cmbPresetRoles->Items->Add("Second Examiner (Moderator) [second_examiner]");

            cmbPresetRoles->Items->Add("Exam Hall Supervisor [supervisor_01]");

            cmbPresetRoles->SelectedIndex = 0;

        }



        void cmbPresetRoles_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {

            int idx = cmbPresetRoles->SelectedIndex;

            lblStatus->Text = "";

            switch (idx) {

                case 0:

                    txtUsername->Text = "ar_officer";

                    txtPassword->Text = "AR#Branch2026!";

                    break;

                case 1:

                    txtUsername->Text = "dean_user";

                    txtPassword->Text = "Dean#Secure2026!";

                    break;

                case 2:

                    txtUsername->Text = "hod_comp";

                    txtPassword->Text = "Hod#Comp2026!";

                    break;

                case 3:

                    txtUsername->Text = "lecturer_user";

                    txtPassword->Text = "Lect#Exam2026!";

                    break;

                case 4:

                    txtUsername->Text = "second_examiner";

                    txtPassword->Text = "Sec#Exam2026!";

                    break;

                case 5:

                    txtUsername->Text = "supervisor_01";

                    txtPassword->Text = "Hall#Sup2026!";

                    break;

            }

        }



        void btnLogin_Click(System::Object^ sender, System::EventArgs^ e) {

            String^ username = txtUsername->Text->Trim();

            String^ password = txtPassword->Text;



            if (username == "ar_officer" && password == "AR#Branch2026!") {

                _authenticatedSession = gcnew UserSession("ar_officer", "Mrs. K. A. Perera (AR Office)", "kperera.ar@univ.ac.lk", Roles::AROffice, "EXAM_BRANCH");

            }

            else if (username == "dean_user" && password == "Dean#Secure2026!") {

                _authenticatedSession = gcnew UserSession("dean_user", "Prof. A. C. Jayawardena (Dean)", "cjayawardena@univ.ac.lk", Roles::Dean, "DEPT_CS");

            }

            else if (username == "hod_comp" && password == "Hod#Comp2026!") {

                _authenticatedSession = gcnew UserSession("hod_comp", "Dr. M. S. Wickramasinghe (HOD)", "mwickrama@univ.ac.lk", Roles::HOD, "DEPT_CS");

            }

            else if (username == "lecturer_user" && password == "Lect#Exam2026!") {

                _authenticatedSession = gcnew UserSession("lecturer_user", "Dr. N. L. Bandara (First Examiner)", "nbandara@univ.ac.lk", Roles::FirstExaminer, "DEPT_CS");

            }

            else if (username == "second_examiner" && password == "Sec#Exam2026!") {

                _authenticatedSession = gcnew UserSession("second_examiner", "Prof. R. M. Dissanayake (Second Examiner)", "rdissanayake@external.ac.lk", Roles::SecondExaminer, "EXTERNAL");

            }

            else if (username == "supervisor_01" && password == "Hall#Sup2026!") {

                _authenticatedSession = gcnew UserSession("supervisor_01", "Mr. S. M. Fernando (Hall Supervisor)", "sfernando.sup@univ.ac.lk", Roles::Supervisor, "EXAM_BRANCH");

            }

            else {

                lblStatus->Text = "Authentication Failed: Invalid username or password.";

                return;

            }



            this->DialogResult = System::Windows::Forms::DialogResult::OK;

            this->Close();

        }



        void btnExit_Click(System::Object^ sender, System::EventArgs^ e) {

            this->DialogResult = System::Windows::Forms::DialogResult::Cancel;

            this->Close();

        }

    private: System::Void lblLoginTitle_Click(System::Object^ sender, System::EventArgs^ e) {
    }
private: System::Void lblSecurityNotice_Click(System::Object^ sender, System::EventArgs^ e) {
}
};



}

}

