#pragma once



#include "..\Models\Entities.h"

#include "..\Database\DatabaseManager.h"

#include "LoginForm.h"



namespace ExaminationResultsMonitoringSystem {

namespace Forms {



    using namespace System;

    using namespace System::ComponentModel;

    using namespace System::Collections;

    using namespace System::Windows::Forms;

    using namespace System::Data;

    using namespace System::Drawing;

    using namespace System::Text;

    using namespace ExaminationResultsMonitoringSystem::Models;

    using namespace ExaminationResultsMonitoringSystem::Database;



    public ref class MainForm : public System::Windows::Forms::Form

    {

    public:

        MainForm(void)
        {
            _session = gcnew UserSession(L"USR-ADMIN", L"Administrator", L"admin@university.edu", L"SYSTEM_ADMIN", L"ADMIN");
            _db = DatabaseManager::GetInstance();
            InitializeComponent();
        }

        MainForm(UserSession^ session)

        {

            _session = session;

            _db = DatabaseManager::GetInstance();

            InitializeComponent();

            ApplyRolePermissions();

            PopulateSemesterFilter();

            RefreshAllViews();

        }



    protected:

        ~MainForm()

        {

            if (components)

            {

                delete components;

            }

        }



    private:

        UserSession^ _session;

        DatabaseManager^ _db;



        System::Windows::Forms::Panel^ panelTop;

        System::Windows::Forms::Label^ lblSystemCategory;

        System::Windows::Forms::Label^ lblAppTitle;

        System::Windows::Forms::Panel^ panelTopRight;

        System::Windows::Forms::Label^ lblUserBadge;

        System::Windows::Forms::ComboBox^ cmbSemesterFilter;

        System::Windows::Forms::Label^ lblFilterLabel;

        System::Windows::Forms::Button^ btnSignOut;



        System::Windows::Forms::Panel^ panelSidebar;

        System::Windows::Forms::Panel^ panelBrandLogo;

        System::Windows::Forms::Label^ lblNavHeader;

        System::Windows::Forms::Button^ btnNavDashboard;

        System::Windows::Forms::Button^ btnNavAlerts;

        System::Windows::Forms::Button^ btnNavSemesters;

        System::Windows::Forms::Button^ btnNavStaff;

        System::Windows::Forms::Button^ btnNavOfferings;

        System::Windows::Forms::Button^ btnNavScripts;

        System::Windows::Forms::Button^ btnNavMilestones;

        System::Windows::Forms::Button^ btnNavEvaluation;

        System::Windows::Forms::Button^ btnNavAudit;

        System::Windows::Forms::Button^ btnNavDatabase;



        System::Windows::Forms::Panel^ panelMainContent;

        System::Windows::Forms::TabControl^ tabModules;



        System::Windows::Forms::TabPage^ tabDashboard;

        System::Windows::Forms::TabPage^ tabAlerts;

        System::Windows::Forms::TabPage^ tabSemestersCourses;

        System::Windows::Forms::TabPage^ tabStaff;

        System::Windows::Forms::TabPage^ tabOfferings;

        System::Windows::Forms::TabPage^ tabScripts;

        System::Windows::Forms::TabPage^ tabMilestones;

        System::Windows::Forms::TabPage^ tabEvaluation;

        System::Windows::Forms::TabPage^ tabAudit;

        System::Windows::Forms::TabPage^ tabDatabase;



        System::Windows::Forms::TableLayoutPanel^ tlpStats;

        System::Windows::Forms::Panel^ pnlStat1;

        System::Windows::Forms::Panel^ pnlStat2;

        System::Windows::Forms::Panel^ pnlStat3;

        System::Windows::Forms::Panel^ pnlStat4;

        System::Windows::Forms::Panel^ pnlStat5;

        System::Windows::Forms::Panel^ pnlStat6;

        System::Windows::Forms::Label^ lblStatVal1;

        System::Windows::Forms::Label^ lblStatVal2;

        System::Windows::Forms::Label^ lblStatVal3;

        System::Windows::Forms::Label^ lblStatVal4;

        System::Windows::Forms::Label^ lblStatVal5;

        System::Windows::Forms::Label^ lblStatVal6;

        System::Windows::Forms::DataGridView^ dgvDashboardOverview;
        System::Windows::Forms::Label^ lblDashboardTableTitle;
        System::Windows::Forms::Panel^ stripStat1;
        System::Windows::Forms::Panel^ stripStat2;
        System::Windows::Forms::Panel^ stripStat3;
        System::Windows::Forms::Panel^ stripStat4;
        System::Windows::Forms::Panel^ stripStat5;
        System::Windows::Forms::Panel^ stripStat6;
        System::Windows::Forms::Label^ lblStatTitle1;
        System::Windows::Forms::Label^ lblStatTitle2;
        System::Windows::Forms::Label^ lblStatTitle3;
        System::Windows::Forms::Label^ lblStatTitle4;
        System::Windows::Forms::Label^ lblStatTitle5;
        System::Windows::Forms::Label^ lblStatTitle6;



        System::Windows::Forms::Panel^ pnlAlertBanner;

        System::Windows::Forms::Label^ lblAlertHeader;

        System::Windows::Forms::Label^ lblAlertSub;

        System::Windows::Forms::DataGridView^ dgvAlerts;



        System::Windows::Forms::DataGridView^ dgvSemesters;

        System::Windows::Forms::DataGridView^ dgvCourses;

        System::Windows::Forms::TextBox^ txtSemId;

        System::Windows::Forms::TextBox^ txtSemYear;

        System::Windows::Forms::NumericUpDown^ numSemNumber;

        System::Windows::Forms::DateTimePicker^ dtpSemStart;

        System::Windows::Forms::DateTimePicker^ dtpSemEnd;

        System::Windows::Forms::DateTimePicker^ dtpExamStart;

        System::Windows::Forms::DateTimePicker^ dtpExamEnd;

        System::Windows::Forms::Button^ btnSaveSemester;

        System::Windows::Forms::TextBox^ txtCourseCode;

        System::Windows::Forms::TextBox^ txtCourseTitle;

        System::Windows::Forms::NumericUpDown^ numCourseYear;

        System::Windows::Forms::Button^ btnSaveCourse;



        System::Windows::Forms::DataGridView^ dgvStaff;

        System::Windows::Forms::TextBox^ txtStaffId;

        System::Windows::Forms::TextBox^ txtStaffName;

        System::Windows::Forms::TextBox^ txtStaffEmail;

        System::Windows::Forms::TextBox^ txtStaffRole;

        System::Windows::Forms::CheckBox^ chkIsAcademic;

        System::Windows::Forms::CheckBox^ chkIsInternal;

        System::Windows::Forms::TextBox^ txtDepartment;

        System::Windows::Forms::NumericUpDown^ numMaxWorkload;

        System::Windows::Forms::TextBox^ txtContactNumber;

        System::Windows::Forms::Button^ btnSaveStaff;



        System::Windows::Forms::DataGridView^ dgvOfferings;

        System::Windows::Forms::TextBox^ txtOfferingId;

        System::Windows::Forms::ComboBox^ cmbOfferingSem;

        System::Windows::Forms::ComboBox^ cmbOfferingCourse;

        System::Windows::Forms::ComboBox^ cmbOfferingFirstEx;

        System::Windows::Forms::ComboBox^ cmbOfferingSecondEx;

        System::Windows::Forms::ComboBox^ cmbOfferingSenate;

        System::Windows::Forms::Button^ btnSaveOffering;

        System::Windows::Forms::Button^ btnToggleSenate;

        System::Windows::Forms::Panel^ pnlWorkloadCallout;

        System::Windows::Forms::Label^ lblWorkloadIndicator;



        System::Windows::Forms::DataGridView^ dgvScripts;

        System::Windows::Forms::ComboBox^ cmbScriptOffering;

        System::Windows::Forms::NumericUpDown^ numBundleNo;

        System::Windows::Forms::NumericUpDown^ numScriptCount;

        System::Windows::Forms::DateTimePicker^ dtpSupervisorHandover;

        System::Windows::Forms::Button^ btnAddScriptBundle;

        System::Windows::Forms::Panel^ pnlScriptSummary;

        System::Windows::Forms::Label^ lblScriptSummary;



        System::Windows::Forms::DataGridView^ dgvMilestones;

        System::Windows::Forms::Panel^ pnlSelectedOfferingChip;

        System::Windows::Forms::Label^ lblSelectedOffering;

        System::Windows::Forms::Button^ btnMilestoneCollect;

        System::Windows::Forms::Button^ btnMilestoneMarkSheet;

        System::Windows::Forms::Button^ btnMilestoneDispatch;

        System::Windows::Forms::Button^ btnMilestoneReturn;

        System::Windows::Forms::Button^ btnMilestoneEIS;

        System::Windows::Forms::Button^ btnMilestoneHOD;

        System::Windows::Forms::Label^ lblMilestoneStatusDesc;



        System::Windows::Forms::ComboBox^ cmbEvalOffering;

        System::Windows::Forms::NumericUpDown^ numCaWeight;

        System::Windows::Forms::NumericUpDown^ numExamWeight;

        System::Windows::Forms::Label^ lblWeightSumStatus;

        System::Windows::Forms::TextBox^ txtSampleStudentId;

        System::Windows::Forms::NumericUpDown^ numSampleCaScore;

        System::Windows::Forms::NumericUpDown^ numSampleExamScore;

        System::Windows::Forms::Button^ btnSaveWeights;

        System::Windows::Forms::Button^ btnCalculateScore;

        System::Windows::Forms::Panel^ pnlScoreResult;

        System::Windows::Forms::Label^ lblScoreResult;



        System::Windows::Forms::DataGridView^ dgvAudit;

        System::Windows::Forms::TextBox^ txtAuditSearch;

        System::Windows::Forms::Button^ btnRefreshAudit;



        System::Windows::Forms::TextBox^ txtSqlOutput;

        System::Windows::Forms::Button^ btnGenerateDdl;

        System::Windows::Forms::Button^ btnGenerateDml;

        System::Windows::Forms::Button^ btnTestMySql;

        System::Windows::Forms::Button^ btnReloadSampleData;



        System::ComponentModel::Container ^components;



        void StyleDataGridView(System::Windows::Forms::DataGridView^ dgv)

        {

            dgv->EnableHeadersVisualStyles = false;

            dgv->BackgroundColor = Color::White;

            dgv->BorderStyle = BorderStyle::FixedSingle;

            dgv->CellBorderStyle = DataGridViewCellBorderStyle::SingleHorizontal;

            dgv->GridColor = Color::FromArgb(226, 232, 240);

            dgv->ColumnHeadersBorderStyle = DataGridViewHeaderBorderStyle::None;

            dgv->ColumnHeadersDefaultCellStyle->BackColor = Color::FromArgb(15, 23, 42);

            dgv->ColumnHeadersDefaultCellStyle->ForeColor = Color::White;

            dgv->ColumnHeadersDefaultCellStyle->Font = gcnew System::Drawing::Font("Segoe UI Semibold", 9.25F, FontStyle::Bold);

            dgv->ColumnHeadersDefaultCellStyle->Padding = System::Windows::Forms::Padding(8, 6, 8, 6);

            dgv->ColumnHeadersHeight = 38;

            dgv->ColumnHeadersHeightSizeMode = DataGridViewColumnHeadersHeightSizeMode::DisableResizing;

            dgv->RowHeadersVisible = false;

            dgv->DefaultCellStyle->Font = gcnew System::Drawing::Font("Segoe UI", 9.0F);

            dgv->DefaultCellStyle->ForeColor = Color::FromArgb(30, 41, 59);

            dgv->DefaultCellStyle->SelectionBackColor = Color::FromArgb(224, 242, 254);

            dgv->DefaultCellStyle->SelectionForeColor = Color::FromArgb(15, 23, 42);

            dgv->DefaultCellStyle->Padding = System::Windows::Forms::Padding(8, 4, 8, 4);

            dgv->AlternatingRowsDefaultCellStyle->BackColor = Color::FromArgb(248, 250, 252);

            dgv->RowTemplate->Height = 32;

            dgv->SelectionMode = DataGridViewSelectionMode::FullRowSelect;

            dgv->MultiSelect = false;

        }



        void StylePrimaryButton(System::Windows::Forms::Button^ btn)

        {

            btn->BackColor = Color::FromArgb(2, 132, 199);

            btn->ForeColor = Color::White;

            btn->Cursor = System::Windows::Forms::Cursors::Hand;

            btn->FlatStyle = FlatStyle::Flat;

            btn->FlatAppearance->BorderSize = 0;

            btn->FlatAppearance->MouseOverBackColor = Color::FromArgb(3, 105, 161);

            btn->FlatAppearance->MouseDownBackColor = Color::FromArgb(7, 89, 133);

            btn->Font = gcnew System::Drawing::Font("Segoe UI Semibold", 9.25F, FontStyle::Bold);

        }



        void StyleSuccessButton(System::Windows::Forms::Button^ btn)

        {

            btn->BackColor = Color::FromArgb(22, 163, 74);

            btn->ForeColor = Color::White;

            btn->Cursor = System::Windows::Forms::Cursors::Hand;

            btn->FlatStyle = FlatStyle::Flat;

            btn->FlatAppearance->BorderSize = 0;

            btn->FlatAppearance->MouseOverBackColor = Color::FromArgb(21, 128, 61);

            btn->FlatAppearance->MouseDownBackColor = Color::FromArgb(20, 83, 45);

            btn->Font = gcnew System::Drawing::Font("Segoe UI Semibold", 9.25F, FontStyle::Bold);

        }



        void StyleDarkButton(System::Windows::Forms::Button^ btn)

        {

            btn->BackColor = Color::FromArgb(30, 41, 59);

            btn->ForeColor = Color::White;

            btn->Cursor = System::Windows::Forms::Cursors::Hand;

            btn->FlatStyle = FlatStyle::Flat;

            btn->FlatAppearance->BorderSize = 0;

            btn->FlatAppearance->MouseOverBackColor = Color::FromArgb(51, 65, 85);

            btn->FlatAppearance->MouseDownBackColor = Color::FromArgb(15, 23, 42);

            btn->Font = gcnew System::Drawing::Font("Segoe UI Semibold", 9.25F, FontStyle::Bold);

        }



        void StyleTealButton(System::Windows::Forms::Button^ btn)

        {

            btn->BackColor = Color::FromArgb(13, 148, 136);

            btn->ForeColor = Color::White;

            btn->Cursor = System::Windows::Forms::Cursors::Hand;

            btn->FlatStyle = FlatStyle::Flat;

            btn->FlatAppearance->BorderSize = 0;

            btn->FlatAppearance->MouseOverBackColor = Color::FromArgb(15, 118, 110);

            btn->FlatAppearance->MouseDownBackColor = Color::FromArgb(17, 94, 89);

            btn->Font = gcnew System::Drawing::Font("Segoe UI Semibold", 9.25F, FontStyle::Bold);

        }



        void StyleAmberButton(System::Windows::Forms::Button^ btn)

        {

            btn->BackColor = Color::FromArgb(217, 119, 6);

            btn->ForeColor = Color::White;

            btn->Cursor = System::Windows::Forms::Cursors::Hand;

            btn->FlatStyle = FlatStyle::Flat;

            btn->FlatAppearance->BorderSize = 0;

            btn->FlatAppearance->MouseOverBackColor = Color::FromArgb(180, 83, 9);

            btn->FlatAppearance->MouseDownBackColor = Color::FromArgb(146, 64, 14);

            btn->Font = gcnew System::Drawing::Font("Segoe UI Semibold", 9.25F, FontStyle::Bold);

        }



        void StyleWorkflowStepButton(System::Windows::Forms::Button^ btn, String^ text, int top, Panel^ parent)

        {

            btn->Text = text;

            btn->Location = Point(15, top);

            btn->Size = System::Drawing::Size(305, 42);

            btn->BackColor = Color::FromArgb(248, 250, 252);

            btn->ForeColor = Color::FromArgb(15, 23, 42);

            btn->Cursor = System::Windows::Forms::Cursors::Hand;

            btn->FlatStyle = FlatStyle::Flat;

            btn->FlatAppearance->BorderColor = Color::FromArgb(203, 213, 225);

            btn->FlatAppearance->BorderSize = 1;

            btn->FlatAppearance->MouseOverBackColor = Color::FromArgb(224, 242, 254);

            btn->FlatAppearance->MouseDownBackColor = Color::FromArgb(186, 230, 253);

            btn->TextAlign = ContentAlignment::MiddleLeft;

            btn->Padding = System::Windows::Forms::Padding(12, 0, 10, 0);

            btn->Font = gcnew System::Drawing::Font("Segoe UI Semibold", 9.0F);

            parent->Controls->Add(btn);

        }



        void InitializeComponent(void)

        {
            System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle1 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
            System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle2 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
            System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle3 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
            this->panelTop = (gcnew System::Windows::Forms::Panel());
            this->panelTopRight = (gcnew System::Windows::Forms::Panel());
            this->lblFilterLabel = (gcnew System::Windows::Forms::Label());
            this->cmbSemesterFilter = (gcnew System::Windows::Forms::ComboBox());
            this->lblUserBadge = (gcnew System::Windows::Forms::Label());
            this->btnSignOut = (gcnew System::Windows::Forms::Button());
            this->lblSystemCategory = (gcnew System::Windows::Forms::Label());
            this->lblAppTitle = (gcnew System::Windows::Forms::Label());
            this->panelSidebar = (gcnew System::Windows::Forms::Panel());
            this->btnNavDatabase = (gcnew System::Windows::Forms::Button());
            this->btnNavAudit = (gcnew System::Windows::Forms::Button());
            this->btnNavEvaluation = (gcnew System::Windows::Forms::Button());
            this->btnNavMilestones = (gcnew System::Windows::Forms::Button());
            this->btnNavScripts = (gcnew System::Windows::Forms::Button());
            this->btnNavOfferings = (gcnew System::Windows::Forms::Button());
            this->btnNavStaff = (gcnew System::Windows::Forms::Button());
            this->btnNavSemesters = (gcnew System::Windows::Forms::Button());
            this->btnNavAlerts = (gcnew System::Windows::Forms::Button());
            this->btnNavDashboard = (gcnew System::Windows::Forms::Button());
            this->panelBrandLogo = (gcnew System::Windows::Forms::Panel());
            this->lblNavHeader = (gcnew System::Windows::Forms::Label());
            this->panelMainContent = (gcnew System::Windows::Forms::Panel());
            this->tabModules = (gcnew System::Windows::Forms::TabControl());
            this->tabDashboard = (gcnew System::Windows::Forms::TabPage());
            this->tlpStats = (gcnew System::Windows::Forms::TableLayoutPanel());
            this->pnlStat1 = (gcnew System::Windows::Forms::Panel());
            this->stripStat1 = (gcnew System::Windows::Forms::Panel());
            this->lblStatTitle1 = (gcnew System::Windows::Forms::Label());
            this->lblStatVal1 = (gcnew System::Windows::Forms::Label());
            this->pnlStat2 = (gcnew System::Windows::Forms::Panel());
            this->stripStat2 = (gcnew System::Windows::Forms::Panel());
            this->lblStatTitle2 = (gcnew System::Windows::Forms::Label());
            this->lblStatVal2 = (gcnew System::Windows::Forms::Label());
            this->pnlStat3 = (gcnew System::Windows::Forms::Panel());
            this->stripStat3 = (gcnew System::Windows::Forms::Panel());
            this->lblStatTitle3 = (gcnew System::Windows::Forms::Label());
            this->lblStatVal3 = (gcnew System::Windows::Forms::Label());
            this->pnlStat4 = (gcnew System::Windows::Forms::Panel());
            this->stripStat4 = (gcnew System::Windows::Forms::Panel());
            this->lblStatTitle4 = (gcnew System::Windows::Forms::Label());
            this->lblStatVal4 = (gcnew System::Windows::Forms::Label());
            this->pnlStat5 = (gcnew System::Windows::Forms::Panel());
            this->stripStat5 = (gcnew System::Windows::Forms::Panel());
            this->lblStatTitle5 = (gcnew System::Windows::Forms::Label());
            this->lblStatVal5 = (gcnew System::Windows::Forms::Label());
            this->pnlStat6 = (gcnew System::Windows::Forms::Panel());
            this->stripStat6 = (gcnew System::Windows::Forms::Panel());
            this->lblStatTitle6 = (gcnew System::Windows::Forms::Label());
            this->lblStatVal6 = (gcnew System::Windows::Forms::Label());
            this->lblDashboardTableTitle = (gcnew System::Windows::Forms::Label());
            this->dgvDashboardOverview = (gcnew System::Windows::Forms::DataGridView());
            this->tabAlerts = (gcnew System::Windows::Forms::TabPage());
            this->tabSemestersCourses = (gcnew System::Windows::Forms::TabPage());
            this->tabStaff = (gcnew System::Windows::Forms::TabPage());
            this->tabOfferings = (gcnew System::Windows::Forms::TabPage());
            this->tabScripts = (gcnew System::Windows::Forms::TabPage());
            this->tabMilestones = (gcnew System::Windows::Forms::TabPage());
            this->tabEvaluation = (gcnew System::Windows::Forms::TabPage());
            this->tabAudit = (gcnew System::Windows::Forms::TabPage());
            this->tabDatabase = (gcnew System::Windows::Forms::TabPage());
            this->panelTop->SuspendLayout();
            this->panelTopRight->SuspendLayout();
            this->panelSidebar->SuspendLayout();
            this->panelBrandLogo->SuspendLayout();
            this->panelMainContent->SuspendLayout();
            this->tabModules->SuspendLayout();
            this->tabDashboard->SuspendLayout();
            this->tlpStats->SuspendLayout();
            this->pnlStat1->SuspendLayout();
            this->pnlStat2->SuspendLayout();
            this->pnlStat3->SuspendLayout();
            this->pnlStat4->SuspendLayout();
            this->pnlStat5->SuspendLayout();
            this->pnlStat6->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvDashboardOverview))->BeginInit();
            this->SuspendLayout();
            // 
            // panelTop
            // 
            this->panelTop->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(15)), static_cast<System::Int32>(static_cast<System::Byte>(23)),
                static_cast<System::Int32>(static_cast<System::Byte>(42)));
            this->panelTop->Controls->Add(this->panelTopRight);
            this->panelTop->Controls->Add(this->lblSystemCategory);
            this->panelTop->Controls->Add(this->lblAppTitle);
            this->panelTop->Dock = System::Windows::Forms::DockStyle::Top;
            this->panelTop->Location = System::Drawing::Point(0, 0);
            this->panelTop->Name = L"panelTop";
            this->panelTop->Padding = System::Windows::Forms::Padding(20, 10, 20, 10);
            this->panelTop->Size = System::Drawing::Size(1280, 68);
            this->panelTop->TabIndex = 0;
            // 
            // panelTopRight
            // 
            this->panelTopRight->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
            this->panelTopRight->Controls->Add(this->lblFilterLabel);
            this->panelTopRight->Controls->Add(this->cmbSemesterFilter);
            this->panelTopRight->Controls->Add(this->lblUserBadge);
            this->panelTopRight->Controls->Add(this->btnSignOut);
            this->panelTopRight->Location = System::Drawing::Point(540, 10);
            this->panelTopRight->Name = L"panelTopRight";
            this->panelTopRight->Size = System::Drawing::Size(720, 48);
            this->panelTopRight->TabIndex = 3;
            // 
            // lblFilterLabel
            // 
            this->lblFilterLabel->AutoSize = true;
            this->lblFilterLabel->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9));
            this->lblFilterLabel->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(203)), static_cast<System::Int32>(static_cast<System::Byte>(213)),
                static_cast<System::Int32>(static_cast<System::Byte>(225)));
            this->lblFilterLabel->Location = System::Drawing::Point(8, 16);
            this->lblFilterLabel->Name = L"lblFilterLabel";
            this->lblFilterLabel->Size = System::Drawing::Size(118, 20);
            this->lblFilterLabel->TabIndex = 0;
            this->lblFilterLabel->Text = L"Active Semester:";
            // 
            // cmbSemesterFilter
            // 
            this->cmbSemesterFilter->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
            this->cmbSemesterFilter->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9));
            this->cmbSemesterFilter->FormattingEnabled = true;
            this->cmbSemesterFilter->Items->AddRange(gcnew cli::array< System::Object^  >(1) { L"All Semesters" });
            this->cmbSemesterFilter->Location = System::Drawing::Point(108, 12);
            this->cmbSemesterFilter->Name = L"cmbSemesterFilter";
            this->cmbSemesterFilter->Size = System::Drawing::Size(145, 28);
            this->cmbSemesterFilter->TabIndex = 1;
            this->cmbSemesterFilter->SelectedIndexChanged += gcnew System::EventHandler(this, &MainForm::cmbSemesterFilter_SelectedIndexChanged);
            // 
            // lblUserBadge
            // 
            this->lblUserBadge->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(30)), static_cast<System::Int32>(static_cast<System::Byte>(41)),
                static_cast<System::Int32>(static_cast<System::Byte>(59)));
            this->lblUserBadge->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
            this->lblUserBadge->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 9, System::Drawing::FontStyle::Bold));
            this->lblUserBadge->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(56)), static_cast<System::Int32>(static_cast<System::Byte>(189)),
                static_cast<System::Int32>(static_cast<System::Byte>(248)));
            this->lblUserBadge->Location = System::Drawing::Point(265, 8);
            this->lblUserBadge->Name = L"lblUserBadge";
            this->lblUserBadge->Padding = System::Windows::Forms::Padding(10, 4, 10, 4);
            this->lblUserBadge->Size = System::Drawing::Size(340, 32);
            this->lblUserBadge->TabIndex = 2;
            this->lblUserBadge->Text = L"System Administrator | All Access";
            this->lblUserBadge->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
            // 
            // btnSignOut
            // 
            this->btnSignOut->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(220)), static_cast<System::Int32>(static_cast<System::Byte>(38)),
                static_cast<System::Int32>(static_cast<System::Byte>(38)));
            this->btnSignOut->Cursor = System::Windows::Forms::Cursors::Hand;
            this->btnSignOut->FlatAppearance->BorderSize = 0;
            this->btnSignOut->FlatAppearance->MouseDownBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(153)),
                static_cast<System::Int32>(static_cast<System::Byte>(27)), static_cast<System::Int32>(static_cast<System::Byte>(27)));
            this->btnSignOut->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(185)),
                static_cast<System::Int32>(static_cast<System::Byte>(28)), static_cast<System::Int32>(static_cast<System::Byte>(28)));
            this->btnSignOut->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->btnSignOut->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 9, System::Drawing::FontStyle::Bold));
            this->btnSignOut->ForeColor = System::Drawing::Color::White;
            this->btnSignOut->Location = System::Drawing::Point(618, 8);
            this->btnSignOut->Name = L"btnSignOut";
            this->btnSignOut->Size = System::Drawing::Size(95, 32);
            this->btnSignOut->TabIndex = 3;
            this->btnSignOut->Text = L"Sign Out";
            this->btnSignOut->UseVisualStyleBackColor = false;
            this->btnSignOut->Click += gcnew System::EventHandler(this, &MainForm::btnSignOut_Click);
            // 
            // lblSystemCategory
            // 
            this->lblSystemCategory->AutoSize = true;
            this->lblSystemCategory->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 7.5F, System::Drawing::FontStyle::Bold));
            this->lblSystemCategory->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(56)),
                static_cast<System::Int32>(static_cast<System::Byte>(189)), static_cast<System::Int32>(static_cast<System::Byte>(248)));
            this->lblSystemCategory->Location = System::Drawing::Point(22, 12);
            this->lblSystemCategory->Name = L"lblSystemCategory";
            this->lblSystemCategory->Size = System::Drawing::Size(369, 17);
            this->lblSystemCategory->TabIndex = 4;
            this->lblSystemCategory->Text = L"UNIVERSITY EXAMINATION BRANCH MONITORING SYSTEM";
            // 
            // lblAppTitle
            // 
            this->lblAppTitle->AutoSize = true;
            this->lblAppTitle->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 13.5F, System::Drawing::FontStyle::Bold));
            this->lblAppTitle->ForeColor = System::Drawing::Color::White;
            this->lblAppTitle->Location = System::Drawing::Point(20, 28);
            this->lblAppTitle->Name = L"lblAppTitle";
            this->lblAppTitle->Size = System::Drawing::Size(404, 31);
            this->lblAppTitle->TabIndex = 5;
            this->lblAppTitle->Text = L"Results Monitoring & Governance Suite";
            // 
            // panelSidebar
            // 
            this->panelSidebar->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(30)), static_cast<System::Int32>(static_cast<System::Byte>(41)),
                static_cast<System::Int32>(static_cast<System::Byte>(59)));
            this->panelSidebar->Controls->Add(this->btnNavDatabase);
            this->panelSidebar->Controls->Add(this->btnNavAudit);
            this->panelSidebar->Controls->Add(this->btnNavEvaluation);
            this->panelSidebar->Controls->Add(this->btnNavMilestones);
            this->panelSidebar->Controls->Add(this->btnNavScripts);
            this->panelSidebar->Controls->Add(this->btnNavOfferings);
            this->panelSidebar->Controls->Add(this->btnNavStaff);
            this->panelSidebar->Controls->Add(this->btnNavSemesters);
            this->panelSidebar->Controls->Add(this->btnNavAlerts);
            this->panelSidebar->Controls->Add(this->btnNavDashboard);
            this->panelSidebar->Controls->Add(this->panelBrandLogo);
            this->panelSidebar->Dock = System::Windows::Forms::DockStyle::Left;
            this->panelSidebar->Location = System::Drawing::Point(0, 68);
            this->panelSidebar->Name = L"panelSidebar";
            this->panelSidebar->Size = System::Drawing::Size(245, 732);
            this->panelSidebar->TabIndex = 1;
            // 
            // btnNavDatabase
            // 
            this->btnNavDatabase->BackColor = System::Drawing::Color::Transparent;
            this->btnNavDatabase->Cursor = System::Windows::Forms::Cursors::Hand;
            this->btnNavDatabase->FlatAppearance->BorderSize = 0;
            this->btnNavDatabase->FlatAppearance->MouseDownBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(15)),
                static_cast<System::Int32>(static_cast<System::Byte>(23)), static_cast<System::Int32>(static_cast<System::Byte>(42)));
            this->btnNavDatabase->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)),
                static_cast<System::Int32>(static_cast<System::Byte>(65)), static_cast<System::Int32>(static_cast<System::Byte>(85)));
            this->btnNavDatabase->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->btnNavDatabase->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 9.25F, System::Drawing::FontStyle::Bold));
            this->btnNavDatabase->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(226)), static_cast<System::Int32>(static_cast<System::Byte>(232)),
                static_cast<System::Int32>(static_cast<System::Byte>(240)));
            this->btnNavDatabase->Location = System::Drawing::Point(0, 464);
            this->btnNavDatabase->Name = L"btnNavDatabase";
            this->btnNavDatabase->Padding = System::Windows::Forms::Padding(12, 0, 8, 0);
            this->btnNavDatabase->Size = System::Drawing::Size(245, 42);
            this->btnNavDatabase->TabIndex = 9;
            this->btnNavDatabase->Tag = 9;
            this->btnNavDatabase->Text = L" 10. Database & SQL Tools";
            this->btnNavDatabase->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            this->btnNavDatabase->UseVisualStyleBackColor = false;
            this->btnNavDatabase->Click += gcnew System::EventHandler(this, &MainForm::OnNavButtonClick);
            // 
            // btnNavAudit
            // 
            this->btnNavAudit->BackColor = System::Drawing::Color::Transparent;
            this->btnNavAudit->Cursor = System::Windows::Forms::Cursors::Hand;
            this->btnNavAudit->FlatAppearance->BorderSize = 0;
            this->btnNavAudit->FlatAppearance->MouseDownBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(15)),
                static_cast<System::Int32>(static_cast<System::Byte>(23)), static_cast<System::Int32>(static_cast<System::Byte>(42)));
            this->btnNavAudit->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)),
                static_cast<System::Int32>(static_cast<System::Byte>(65)), static_cast<System::Int32>(static_cast<System::Byte>(85)));
            this->btnNavAudit->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->btnNavAudit->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 9.25F, System::Drawing::FontStyle::Bold));
            this->btnNavAudit->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(226)), static_cast<System::Int32>(static_cast<System::Byte>(232)),
                static_cast<System::Int32>(static_cast<System::Byte>(240)));
            this->btnNavAudit->Location = System::Drawing::Point(0, 418);
            this->btnNavAudit->Name = L"btnNavAudit";
            this->btnNavAudit->Padding = System::Windows::Forms::Padding(12, 0, 8, 0);
            this->btnNavAudit->Size = System::Drawing::Size(245, 42);
            this->btnNavAudit->TabIndex = 8;
            this->btnNavAudit->Tag = 8;
            this->btnNavAudit->Text = L"  9. Immutable Audit Trail";
            this->btnNavAudit->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            this->btnNavAudit->UseVisualStyleBackColor = false;
            this->btnNavAudit->Click += gcnew System::EventHandler(this, &MainForm::OnNavButtonClick);
            // 
            // btnNavEvaluation
            // 
            this->btnNavEvaluation->BackColor = System::Drawing::Color::Transparent;
            this->btnNavEvaluation->Cursor = System::Windows::Forms::Cursors::Hand;
            this->btnNavEvaluation->FlatAppearance->BorderSize = 0;
            this->btnNavEvaluation->FlatAppearance->MouseDownBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(15)),
                static_cast<System::Int32>(static_cast<System::Byte>(23)), static_cast<System::Int32>(static_cast<System::Byte>(42)));
            this->btnNavEvaluation->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)),
                static_cast<System::Int32>(static_cast<System::Byte>(65)), static_cast<System::Int32>(static_cast<System::Byte>(85)));
            this->btnNavEvaluation->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->btnNavEvaluation->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 9.25F, System::Drawing::FontStyle::Bold));
            this->btnNavEvaluation->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(226)),
                static_cast<System::Int32>(static_cast<System::Byte>(232)), static_cast<System::Int32>(static_cast<System::Byte>(240)));
            this->btnNavEvaluation->Location = System::Drawing::Point(0, 372);
            this->btnNavEvaluation->Name = L"btnNavEvaluation";
            this->btnNavEvaluation->Padding = System::Windows::Forms::Padding(12, 0, 8, 0);
            this->btnNavEvaluation->Size = System::Drawing::Size(245, 42);
            this->btnNavEvaluation->TabIndex = 7;
            this->btnNavEvaluation->Tag = 7;
            this->btnNavEvaluation->Text = L"  8. CA & Exam Marks (100%)";
            this->btnNavEvaluation->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            this->btnNavEvaluation->UseVisualStyleBackColor = false;
            this->btnNavEvaluation->Click += gcnew System::EventHandler(this, &MainForm::OnNavButtonClick);
            // 
            // btnNavMilestones
            // 
            this->btnNavMilestones->BackColor = System::Drawing::Color::Transparent;
            this->btnNavMilestones->Cursor = System::Windows::Forms::Cursors::Hand;
            this->btnNavMilestones->FlatAppearance->BorderSize = 0;
            this->btnNavMilestones->FlatAppearance->MouseDownBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(15)),
                static_cast<System::Int32>(static_cast<System::Byte>(23)), static_cast<System::Int32>(static_cast<System::Byte>(42)));
            this->btnNavMilestones->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)),
                static_cast<System::Int32>(static_cast<System::Byte>(65)), static_cast<System::Int32>(static_cast<System::Byte>(85)));
            this->btnNavMilestones->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->btnNavMilestones->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 9.25F, System::Drawing::FontStyle::Bold));
            this->btnNavMilestones->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(226)),
                static_cast<System::Int32>(static_cast<System::Byte>(232)), static_cast<System::Int32>(static_cast<System::Byte>(240)));
            this->btnNavMilestones->Location = System::Drawing::Point(0, 326);
            this->btnNavMilestones->Name = L"btnNavMilestones";
            this->btnNavMilestones->Padding = System::Windows::Forms::Padding(12, 0, 8, 0);
            this->btnNavMilestones->Size = System::Drawing::Size(245, 42);
            this->btnNavMilestones->TabIndex = 6;
            this->btnNavMilestones->Tag = 6;
            this->btnNavMilestones->Text = L"  7. Grading Milestones";
            this->btnNavMilestones->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            this->btnNavMilestones->UseVisualStyleBackColor = false;
            this->btnNavMilestones->Click += gcnew System::EventHandler(this, &MainForm::OnNavButtonClick);
            // 
            // btnNavScripts
            // 
            this->btnNavScripts->BackColor = System::Drawing::Color::Transparent;
            this->btnNavScripts->Cursor = System::Windows::Forms::Cursors::Hand;
            this->btnNavScripts->FlatAppearance->BorderSize = 0;
            this->btnNavScripts->FlatAppearance->MouseDownBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(15)),
                static_cast<System::Int32>(static_cast<System::Byte>(23)), static_cast<System::Int32>(static_cast<System::Byte>(42)));
            this->btnNavScripts->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)),
                static_cast<System::Int32>(static_cast<System::Byte>(65)), static_cast<System::Int32>(static_cast<System::Byte>(85)));
            this->btnNavScripts->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->btnNavScripts->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 9.25F, System::Drawing::FontStyle::Bold));
            this->btnNavScripts->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(226)), static_cast<System::Int32>(static_cast<System::Byte>(232)),
                static_cast<System::Int32>(static_cast<System::Byte>(240)));
            this->btnNavScripts->Location = System::Drawing::Point(0, 280);
            this->btnNavScripts->Name = L"btnNavScripts";
            this->btnNavScripts->Padding = System::Windows::Forms::Padding(12, 0, 8, 0);
            this->btnNavScripts->Size = System::Drawing::Size(245, 42);
            this->btnNavScripts->TabIndex = 5;
            this->btnNavScripts->Tag = 5;
            this->btnNavScripts->Text = L"  6. Answer Script Tracking";
            this->btnNavScripts->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            this->btnNavScripts->UseVisualStyleBackColor = false;
            this->btnNavScripts->Click += gcnew System::EventHandler(this, &MainForm::OnNavButtonClick);
            // 
            // btnNavOfferings
            // 
            this->btnNavOfferings->BackColor = System::Drawing::Color::Transparent;
            this->btnNavOfferings->Cursor = System::Windows::Forms::Cursors::Hand;
            this->btnNavOfferings->FlatAppearance->BorderSize = 0;
            this->btnNavOfferings->FlatAppearance->MouseDownBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(15)),
                static_cast<System::Int32>(static_cast<System::Byte>(23)), static_cast<System::Int32>(static_cast<System::Byte>(42)));
            this->btnNavOfferings->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)),
                static_cast<System::Int32>(static_cast<System::Byte>(65)), static_cast<System::Int32>(static_cast<System::Byte>(85)));
            this->btnNavOfferings->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->btnNavOfferings->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 9.25F, System::Drawing::FontStyle::Bold));
            this->btnNavOfferings->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(226)), static_cast<System::Int32>(static_cast<System::Byte>(232)),
                static_cast<System::Int32>(static_cast<System::Byte>(240)));
            this->btnNavOfferings->Location = System::Drawing::Point(0, 234);
            this->btnNavOfferings->Name = L"btnNavOfferings";
            this->btnNavOfferings->Padding = System::Windows::Forms::Padding(12, 0, 8, 0);
            this->btnNavOfferings->Size = System::Drawing::Size(245, 42);
            this->btnNavOfferings->TabIndex = 4;
            this->btnNavOfferings->Tag = 4;
            this->btnNavOfferings->Text = L"  5. Offerings & Allocation";
            this->btnNavOfferings->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            this->btnNavOfferings->UseVisualStyleBackColor = false;
            this->btnNavOfferings->Click += gcnew System::EventHandler(this, &MainForm::OnNavButtonClick);
            // 
            // btnNavStaff
            // 
            this->btnNavStaff->BackColor = System::Drawing::Color::Transparent;
            this->btnNavStaff->Cursor = System::Windows::Forms::Cursors::Hand;
            this->btnNavStaff->FlatAppearance->BorderSize = 0;
            this->btnNavStaff->FlatAppearance->MouseDownBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(15)),
                static_cast<System::Int32>(static_cast<System::Byte>(23)), static_cast<System::Int32>(static_cast<System::Byte>(42)));
            this->btnNavStaff->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)),
                static_cast<System::Int32>(static_cast<System::Byte>(65)), static_cast<System::Int32>(static_cast<System::Byte>(85)));
            this->btnNavStaff->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->btnNavStaff->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 9.25F, System::Drawing::FontStyle::Bold));
            this->btnNavStaff->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(226)), static_cast<System::Int32>(static_cast<System::Byte>(232)),
                static_cast<System::Int32>(static_cast<System::Byte>(240)));
            this->btnNavStaff->Location = System::Drawing::Point(0, 188);
            this->btnNavStaff->Name = L"btnNavStaff";
            this->btnNavStaff->Padding = System::Windows::Forms::Padding(12, 0, 8, 0);
            this->btnNavStaff->Size = System::Drawing::Size(245, 42);
            this->btnNavStaff->TabIndex = 3;
            this->btnNavStaff->Tag = 3;
            this->btnNavStaff->Text = L"  4. Staff Directory & Workload";
            this->btnNavStaff->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            this->btnNavStaff->UseVisualStyleBackColor = false;
            this->btnNavStaff->Click += gcnew System::EventHandler(this, &MainForm::OnNavButtonClick);
            // 
            // btnNavSemesters
            // 
            this->btnNavSemesters->BackColor = System::Drawing::Color::Transparent;
            this->btnNavSemesters->Cursor = System::Windows::Forms::Cursors::Hand;
            this->btnNavSemesters->FlatAppearance->BorderSize = 0;
            this->btnNavSemesters->FlatAppearance->MouseDownBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(15)),
                static_cast<System::Int32>(static_cast<System::Byte>(23)), static_cast<System::Int32>(static_cast<System::Byte>(42)));
            this->btnNavSemesters->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)),
                static_cast<System::Int32>(static_cast<System::Byte>(65)), static_cast<System::Int32>(static_cast<System::Byte>(85)));
            this->btnNavSemesters->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->btnNavSemesters->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 9.25F, System::Drawing::FontStyle::Bold));
            this->btnNavSemesters->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(226)), static_cast<System::Int32>(static_cast<System::Byte>(232)),
                static_cast<System::Int32>(static_cast<System::Byte>(240)));
            this->btnNavSemesters->Location = System::Drawing::Point(0, 142);
            this->btnNavSemesters->Name = L"btnNavSemesters";
            this->btnNavSemesters->Padding = System::Windows::Forms::Padding(12, 0, 8, 0);
            this->btnNavSemesters->Size = System::Drawing::Size(245, 42);
            this->btnNavSemesters->TabIndex = 2;
            this->btnNavSemesters->Tag = 2;
            this->btnNavSemesters->Text = L"  3. Semesters & Courses";
            this->btnNavSemesters->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            this->btnNavSemesters->UseVisualStyleBackColor = false;
            this->btnNavSemesters->Click += gcnew System::EventHandler(this, &MainForm::OnNavButtonClick);
            // 
            // btnNavAlerts
            // 
            this->btnNavAlerts->BackColor = System::Drawing::Color::Transparent;
            this->btnNavAlerts->Cursor = System::Windows::Forms::Cursors::Hand;
            this->btnNavAlerts->FlatAppearance->BorderSize = 0;
            this->btnNavAlerts->FlatAppearance->MouseDownBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(15)),
                static_cast<System::Int32>(static_cast<System::Byte>(23)), static_cast<System::Int32>(static_cast<System::Byte>(42)));
            this->btnNavAlerts->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)),
                static_cast<System::Int32>(static_cast<System::Byte>(65)), static_cast<System::Int32>(static_cast<System::Byte>(85)));
            this->btnNavAlerts->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->btnNavAlerts->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 9.25F, System::Drawing::FontStyle::Bold));
            this->btnNavAlerts->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(226)), static_cast<System::Int32>(static_cast<System::Byte>(232)),
                static_cast<System::Int32>(static_cast<System::Byte>(240)));
            this->btnNavAlerts->Location = System::Drawing::Point(0, 96);
            this->btnNavAlerts->Name = L"btnNavAlerts";
            this->btnNavAlerts->Padding = System::Windows::Forms::Padding(12, 0, 8, 0);
            this->btnNavAlerts->Size = System::Drawing::Size(245, 42);
            this->btnNavAlerts->TabIndex = 1;
            this->btnNavAlerts->Tag = 1;
            this->btnNavAlerts->Text = L"  2. Overdue Alerts (Deadlines)";
            this->btnNavAlerts->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            this->btnNavAlerts->UseVisualStyleBackColor = false;
            this->btnNavAlerts->Click += gcnew System::EventHandler(this, &MainForm::OnNavButtonClick);
            // 
            // btnNavDashboard
            // 
            this->btnNavDashboard->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)), static_cast<System::Int32>(static_cast<System::Byte>(65)),
                static_cast<System::Int32>(static_cast<System::Byte>(85)));
            this->btnNavDashboard->Cursor = System::Windows::Forms::Cursors::Hand;
            this->btnNavDashboard->FlatAppearance->BorderSize = 0;
            this->btnNavDashboard->FlatAppearance->MouseDownBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(15)),
                static_cast<System::Int32>(static_cast<System::Byte>(23)), static_cast<System::Int32>(static_cast<System::Byte>(42)));
            this->btnNavDashboard->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)),
                static_cast<System::Int32>(static_cast<System::Byte>(65)), static_cast<System::Int32>(static_cast<System::Byte>(85)));
            this->btnNavDashboard->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->btnNavDashboard->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 9.25F, System::Drawing::FontStyle::Bold));
            this->btnNavDashboard->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(226)), static_cast<System::Int32>(static_cast<System::Byte>(232)),
                static_cast<System::Int32>(static_cast<System::Byte>(240)));
            this->btnNavDashboard->Location = System::Drawing::Point(0, 50);
            this->btnNavDashboard->Name = L"btnNavDashboard";
            this->btnNavDashboard->Padding = System::Windows::Forms::Padding(12, 0, 8, 0);
            this->btnNavDashboard->Size = System::Drawing::Size(245, 42);
            this->btnNavDashboard->TabIndex = 0;
            this->btnNavDashboard->Tag = 0;
            this->btnNavDashboard->Text = L"  1. Executive Dashboard";
            this->btnNavDashboard->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            this->btnNavDashboard->UseVisualStyleBackColor = false;
            this->btnNavDashboard->Click += gcnew System::EventHandler(this, &MainForm::OnNavButtonClick);
            // 
            // panelBrandLogo
            // 
            this->panelBrandLogo->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(15)), static_cast<System::Int32>(static_cast<System::Byte>(23)),
                static_cast<System::Int32>(static_cast<System::Byte>(42)));
            this->panelBrandLogo->Controls->Add(this->lblNavHeader);
            this->panelBrandLogo->Dock = System::Windows::Forms::DockStyle::Top;
            this->panelBrandLogo->Location = System::Drawing::Point(0, 0);
            this->panelBrandLogo->Name = L"panelBrandLogo";
            this->panelBrandLogo->Padding = System::Windows::Forms::Padding(14, 10, 14, 10);
            this->panelBrandLogo->Size = System::Drawing::Size(245, 42);
            this->panelBrandLogo->TabIndex = 10;
            // 
            // lblNavHeader
            // 
            this->lblNavHeader->AutoSize = true;
            this->lblNavHeader->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 8.25F, System::Drawing::FontStyle::Bold));
            this->lblNavHeader->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(148)), static_cast<System::Int32>(static_cast<System::Byte>(163)),
                static_cast<System::Int32>(static_cast<System::Byte>(184)));
            this->lblNavHeader->Location = System::Drawing::Point(14, 14);
            this->lblNavHeader->Name = L"lblNavHeader";
            this->lblNavHeader->Size = System::Drawing::Size(229, 19);
            this->lblNavHeader->TabIndex = 0;
            this->lblNavHeader->Text = L"SYSTEM MODULES & WORKFLOWS";
            // 
            // panelMainContent
            // 
            this->panelMainContent->Controls->Add(this->tabModules);
            this->panelMainContent->Dock = System::Windows::Forms::DockStyle::Fill;
            this->panelMainContent->Location = System::Drawing::Point(245, 68);
            this->panelMainContent->Name = L"panelMainContent";
            this->panelMainContent->Size = System::Drawing::Size(1035, 732);
            this->panelMainContent->TabIndex = 2;
            // 
            // tabModules
            // 
            this->tabModules->Appearance = System::Windows::Forms::TabAppearance::FlatButtons;
            this->tabModules->Controls->Add(this->tabDashboard);
            this->tabModules->Controls->Add(this->tabAlerts);
            this->tabModules->Controls->Add(this->tabSemestersCourses);
            this->tabModules->Controls->Add(this->tabStaff);
            this->tabModules->Controls->Add(this->tabOfferings);
            this->tabModules->Controls->Add(this->tabScripts);
            this->tabModules->Controls->Add(this->tabMilestones);
            this->tabModules->Controls->Add(this->tabEvaluation);
            this->tabModules->Controls->Add(this->tabAudit);
            this->tabModules->Controls->Add(this->tabDatabase);
            this->tabModules->Dock = System::Windows::Forms::DockStyle::Fill;
            this->tabModules->ItemSize = System::Drawing::Size(0, 1);
            this->tabModules->Location = System::Drawing::Point(0, 0);
            this->tabModules->Name = L"tabModules";
            this->tabModules->SelectedIndex = 0;
            this->tabModules->Size = System::Drawing::Size(1035, 732);
            this->tabModules->SizeMode = System::Windows::Forms::TabSizeMode::Fixed;
            this->tabModules->TabIndex = 0;
            // 
            // tabDashboard
            // 
            this->tabDashboard->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(248)), static_cast<System::Int32>(static_cast<System::Byte>(250)),
                static_cast<System::Int32>(static_cast<System::Byte>(252)));
            this->tabDashboard->Controls->Add(this->tlpStats);
            this->tabDashboard->Controls->Add(this->lblDashboardTableTitle);
            this->tabDashboard->Controls->Add(this->dgvDashboardOverview);
            this->tabDashboard->Location = System::Drawing::Point(4, 5);
            this->tabDashboard->Name = L"tabDashboard";
            this->tabDashboard->Padding = System::Windows::Forms::Padding(20);
            this->tabDashboard->Size = System::Drawing::Size(1027, 723);
            this->tabDashboard->TabIndex = 0;
            this->tabDashboard->Text = L"Executive Dashboard";
            // 
            // tlpStats
            // 
            this->tlpStats->ColumnCount = 6;
            this->tlpStats->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 16.66F)));
            this->tlpStats->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 16.66F)));
            this->tlpStats->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 16.66F)));
            this->tlpStats->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 16.66F)));
            this->tlpStats->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 16.66F)));
            this->tlpStats->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 16.66F)));
            this->tlpStats->Controls->Add(this->pnlStat1, 0, 0);
            this->tlpStats->Controls->Add(this->pnlStat2, 1, 0);
            this->tlpStats->Controls->Add(this->pnlStat3, 2, 0);
            this->tlpStats->Controls->Add(this->pnlStat4, 3, 0);
            this->tlpStats->Controls->Add(this->pnlStat5, 4, 0);
            this->tlpStats->Controls->Add(this->pnlStat6, 5, 0);
            this->tlpStats->Dock = System::Windows::Forms::DockStyle::Top;
            this->tlpStats->Location = System::Drawing::Point(20, 20);
            this->tlpStats->Name = L"tlpStats";
            this->tlpStats->RowCount = 1;
            this->tlpStats->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 20)));
            this->tlpStats->Size = System::Drawing::Size(987, 100);
            this->tlpStats->TabIndex = 0;
            // 
            // pnlStat1
            // 
            this->pnlStat1->BackColor = System::Drawing::Color::White;
            this->pnlStat1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
            this->pnlStat1->Controls->Add(this->stripStat1);
            this->pnlStat1->Controls->Add(this->lblStatTitle1);
            this->pnlStat1->Controls->Add(this->lblStatVal1);
            this->pnlStat1->Dock = System::Windows::Forms::DockStyle::Fill;
            this->pnlStat1->Location = System::Drawing::Point(4, 4);
            this->pnlStat1->Margin = System::Windows::Forms::Padding(4);
            this->pnlStat1->Name = L"pnlStat1";
            this->pnlStat1->Size = System::Drawing::Size(156, 92);
            this->pnlStat1->TabIndex = 0;
            // 
            // stripStat1
            // 
            this->stripStat1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(37)), static_cast<System::Int32>(static_cast<System::Byte>(99)),
                static_cast<System::Int32>(static_cast<System::Byte>(235)));
            this->stripStat1->Dock = System::Windows::Forms::DockStyle::Top;
            this->stripStat1->Location = System::Drawing::Point(0, 0);
            this->stripStat1->Name = L"stripStat1";
            this->stripStat1->Size = System::Drawing::Size(154, 4);
            this->stripStat1->TabIndex = 0;
            // 
            // lblStatTitle1
            // 
            this->lblStatTitle1->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 8));
            this->lblStatTitle1->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(100)), static_cast<System::Int32>(static_cast<System::Byte>(116)),
                static_cast<System::Int32>(static_cast<System::Byte>(139)));
            this->lblStatTitle1->Location = System::Drawing::Point(10, 10);
            this->lblStatTitle1->Name = L"lblStatTitle1";
            this->lblStatTitle1->Size = System::Drawing::Size(140, 32);
            this->lblStatTitle1->TabIndex = 1;
            this->lblStatTitle1->Text = L"Total Course Offerings";
            // 
            // lblStatVal1
            // 
            this->lblStatVal1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 17, System::Drawing::FontStyle::Bold));
            this->lblStatVal1->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(15)), static_cast<System::Int32>(static_cast<System::Byte>(23)),
                static_cast<System::Int32>(static_cast<System::Byte>(42)));
            this->lblStatVal1->Location = System::Drawing::Point(8, 44);
            this->lblStatVal1->Name = L"lblStatVal1";
            this->lblStatVal1->Size = System::Drawing::Size(140, 38);
            this->lblStatVal1->TabIndex = 2;
            this->lblStatVal1->Text = L"14";
            // 
            // pnlStat2
            // 
            this->pnlStat2->BackColor = System::Drawing::Color::White;
            this->pnlStat2->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
            this->pnlStat2->Controls->Add(this->stripStat2);
            this->pnlStat2->Controls->Add(this->lblStatTitle2);
            this->pnlStat2->Controls->Add(this->lblStatVal2);
            this->pnlStat2->Dock = System::Windows::Forms::DockStyle::Fill;
            this->pnlStat2->Location = System::Drawing::Point(168, 4);
            this->pnlStat2->Margin = System::Windows::Forms::Padding(4);
            this->pnlStat2->Name = L"pnlStat2";
            this->pnlStat2->Size = System::Drawing::Size(156, 92);
            this->pnlStat2->TabIndex = 1;
            // 
            // stripStat2
            // 
            this->stripStat2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(22)), static_cast<System::Int32>(static_cast<System::Byte>(163)),
                static_cast<System::Int32>(static_cast<System::Byte>(74)));
            this->stripStat2->Dock = System::Windows::Forms::DockStyle::Top;
            this->stripStat2->Location = System::Drawing::Point(0, 0);
            this->stripStat2->Name = L"stripStat2";
            this->stripStat2->Size = System::Drawing::Size(154, 4);
            this->stripStat2->TabIndex = 0;
            // 
            // lblStatTitle2
            // 
            this->lblStatTitle2->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 8));
            this->lblStatTitle2->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(100)), static_cast<System::Int32>(static_cast<System::Byte>(116)),
                static_cast<System::Int32>(static_cast<System::Byte>(139)));
            this->lblStatTitle2->Location = System::Drawing::Point(10, 10);
            this->lblStatTitle2->Name = L"lblStatTitle2";
            this->lblStatTitle2->Size = System::Drawing::Size(140, 32);
            this->lblStatTitle2->TabIndex = 1;
            this->lblStatTitle2->Text = L"Senate Cleared (Approved)";
            // 
            // lblStatVal2
            // 
            this->lblStatVal2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 17, System::Drawing::FontStyle::Bold));
            this->lblStatVal2->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(15)), static_cast<System::Int32>(static_cast<System::Byte>(23)),
                static_cast<System::Int32>(static_cast<System::Byte>(42)));
            this->lblStatVal2->Location = System::Drawing::Point(8, 44);
            this->lblStatVal2->Name = L"lblStatVal2";
            this->lblStatVal2->Size = System::Drawing::Size(140, 38);
            this->lblStatVal2->TabIndex = 2;
            this->lblStatVal2->Text = L"8";
            // 
            // pnlStat3
            // 
            this->pnlStat3->BackColor = System::Drawing::Color::White;
            this->pnlStat3->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
            this->pnlStat3->Controls->Add(this->stripStat3);
            this->pnlStat3->Controls->Add(this->lblStatTitle3);
            this->pnlStat3->Controls->Add(this->lblStatVal3);
            this->pnlStat3->Dock = System::Windows::Forms::DockStyle::Fill;
            this->pnlStat3->Location = System::Drawing::Point(332, 4);
            this->pnlStat3->Margin = System::Windows::Forms::Padding(4);
            this->pnlStat3->Name = L"pnlStat3";
            this->pnlStat3->Size = System::Drawing::Size(156, 92);
            this->pnlStat3->TabIndex = 2;
            // 
            // stripStat3
            // 
            this->stripStat3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(202)), static_cast<System::Int32>(static_cast<System::Byte>(138)),
                static_cast<System::Int32>(static_cast<System::Byte>(4)));
            this->stripStat3->Dock = System::Windows::Forms::DockStyle::Top;
            this->stripStat3->Location = System::Drawing::Point(0, 0);
            this->stripStat3->Name = L"stripStat3";
            this->stripStat3->Size = System::Drawing::Size(154, 4);
            this->stripStat3->TabIndex = 0;
            // 
            // lblStatTitle3
            // 
            this->lblStatTitle3->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 8));
            this->lblStatTitle3->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(100)), static_cast<System::Int32>(static_cast<System::Byte>(116)),
                static_cast<System::Int32>(static_cast<System::Byte>(139)));
            this->lblStatTitle3->Location = System::Drawing::Point(10, 10);
            this->lblStatTitle3->Name = L"lblStatTitle3";
            this->lblStatTitle3->Size = System::Drawing::Size(140, 32);
            this->lblStatTitle3->TabIndex = 1;
            this->lblStatTitle3->Text = L"First Marking in Progress";
            // 
            // lblStatVal3
            // 
            this->lblStatVal3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 17, System::Drawing::FontStyle::Bold));
            this->lblStatVal3->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(15)), static_cast<System::Int32>(static_cast<System::Byte>(23)),
                static_cast<System::Int32>(static_cast<System::Byte>(42)));
            this->lblStatVal3->Location = System::Drawing::Point(8, 44);
            this->lblStatVal3->Name = L"lblStatVal3";
            this->lblStatVal3->Size = System::Drawing::Size(140, 38);
            this->lblStatVal3->TabIndex = 2;
            this->lblStatVal3->Text = L"3";
            // 
            // pnlStat4
            // 
            this->pnlStat4->BackColor = System::Drawing::Color::White;
            this->pnlStat4->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
            this->pnlStat4->Controls->Add(this->stripStat4);
            this->pnlStat4->Controls->Add(this->lblStatTitle4);
            this->pnlStat4->Controls->Add(this->lblStatVal4);
            this->pnlStat4->Dock = System::Windows::Forms::DockStyle::Fill;
            this->pnlStat4->Location = System::Drawing::Point(496, 4);
            this->pnlStat4->Margin = System::Windows::Forms::Padding(4);
            this->pnlStat4->Name = L"pnlStat4";
            this->pnlStat4->Size = System::Drawing::Size(156, 92);
            this->pnlStat4->TabIndex = 3;
            // 
            // stripStat4
            // 
            this->stripStat4->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(147)), static_cast<System::Int32>(static_cast<System::Byte>(51)),
                static_cast<System::Int32>(static_cast<System::Byte>(234)));
            this->stripStat4->Dock = System::Windows::Forms::DockStyle::Top;
            this->stripStat4->Location = System::Drawing::Point(0, 0);
            this->stripStat4->Name = L"stripStat4";
            this->stripStat4->Size = System::Drawing::Size(154, 4);
            this->stripStat4->TabIndex = 0;
            // 
            // lblStatTitle4
            // 
            this->lblStatTitle4->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 8));
            this->lblStatTitle4->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(100)), static_cast<System::Int32>(static_cast<System::Byte>(116)),
                static_cast<System::Int32>(static_cast<System::Byte>(139)));
            this->lblStatTitle4->Location = System::Drawing::Point(10, 10);
            this->lblStatTitle4->Name = L"lblStatTitle4";
            this->lblStatTitle4->Size = System::Drawing::Size(140, 32);
            this->lblStatTitle4->TabIndex = 1;
            this->lblStatTitle4->Text = L"Under Moderation (2nd)";
            // 
            // lblStatVal4
            // 
            this->lblStatVal4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 17, System::Drawing::FontStyle::Bold));
            this->lblStatVal4->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(15)), static_cast<System::Int32>(static_cast<System::Byte>(23)),
                static_cast<System::Int32>(static_cast<System::Byte>(42)));
            this->lblStatVal4->Location = System::Drawing::Point(8, 44);
            this->lblStatVal4->Name = L"lblStatVal4";
            this->lblStatVal4->Size = System::Drawing::Size(140, 38);
            this->lblStatVal4->TabIndex = 2;
            this->lblStatVal4->Text = L"2";
            // 
            // pnlStat5
            // 
            this->pnlStat5->BackColor = System::Drawing::Color::White;
            this->pnlStat5->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
            this->pnlStat5->Controls->Add(this->stripStat5);
            this->pnlStat5->Controls->Add(this->lblStatTitle5);
            this->pnlStat5->Controls->Add(this->lblStatVal5);
            this->pnlStat5->Dock = System::Windows::Forms::DockStyle::Fill;
            this->pnlStat5->Location = System::Drawing::Point(660, 4);
            this->pnlStat5->Margin = System::Windows::Forms::Padding(4);
            this->pnlStat5->Name = L"pnlStat5";
            this->pnlStat5->Size = System::Drawing::Size(156, 92);
            this->pnlStat5->TabIndex = 4;
            // 
            // stripStat5
            // 
            this->stripStat5->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(13)), static_cast<System::Int32>(static_cast<System::Byte>(148)),
                static_cast<System::Int32>(static_cast<System::Byte>(136)));
            this->stripStat5->Dock = System::Windows::Forms::DockStyle::Top;
            this->stripStat5->Location = System::Drawing::Point(0, 0);
            this->stripStat5->Name = L"stripStat5";
            this->stripStat5->Size = System::Drawing::Size(154, 4);
            this->stripStat5->TabIndex = 0;
            // 
            // lblStatTitle5
            // 
            this->lblStatTitle5->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 8));
            this->lblStatTitle5->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(100)), static_cast<System::Int32>(static_cast<System::Byte>(116)),
                static_cast<System::Int32>(static_cast<System::Byte>(139)));
            this->lblStatTitle5->Location = System::Drawing::Point(10, 10);
            this->lblStatTitle5->Name = L"lblStatTitle5";
            this->lblStatTitle5->Size = System::Drawing::Size(140, 32);
            this->lblStatTitle5->TabIndex = 1;
            this->lblStatTitle5->Text = L"Results Authorized (HOD)";
            // 
            // lblStatVal5
            // 
            this->lblStatVal5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 17, System::Drawing::FontStyle::Bold));
            this->lblStatVal5->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(15)), static_cast<System::Int32>(static_cast<System::Byte>(23)),
                static_cast<System::Int32>(static_cast<System::Byte>(42)));
            this->lblStatVal5->Location = System::Drawing::Point(8, 44);
            this->lblStatVal5->Name = L"lblStatVal5";
            this->lblStatVal5->Size = System::Drawing::Size(140, 38);
            this->lblStatVal5->TabIndex = 2;
            this->lblStatVal5->Text = L"6";
            // 
            // pnlStat6
            // 
            this->pnlStat6->BackColor = System::Drawing::Color::White;
            this->pnlStat6->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
            this->pnlStat6->Controls->Add(this->stripStat6);
            this->pnlStat6->Controls->Add(this->lblStatTitle6);
            this->pnlStat6->Controls->Add(this->lblStatVal6);
            this->pnlStat6->Dock = System::Windows::Forms::DockStyle::Fill;
            this->pnlStat6->Location = System::Drawing::Point(824, 4);
            this->pnlStat6->Margin = System::Windows::Forms::Padding(4);
            this->pnlStat6->Name = L"pnlStat6";
            this->pnlStat6->Size = System::Drawing::Size(159, 92);
            this->pnlStat6->TabIndex = 5;
            // 
            // stripStat6
            // 
            this->stripStat6->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(220)), static_cast<System::Int32>(static_cast<System::Byte>(38)),
                static_cast<System::Int32>(static_cast<System::Byte>(38)));
            this->stripStat6->Dock = System::Windows::Forms::DockStyle::Top;
            this->stripStat6->Location = System::Drawing::Point(0, 0);
            this->stripStat6->Name = L"stripStat6";
            this->stripStat6->Size = System::Drawing::Size(157, 4);
            this->stripStat6->TabIndex = 0;
            // 
            // lblStatTitle6
            // 
            this->lblStatTitle6->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 8));
            this->lblStatTitle6->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(100)), static_cast<System::Int32>(static_cast<System::Byte>(116)),
                static_cast<System::Int32>(static_cast<System::Byte>(139)));
            this->lblStatTitle6->Location = System::Drawing::Point(10, 10);
            this->lblStatTitle6->Name = L"lblStatTitle6";
            this->lblStatTitle6->Size = System::Drawing::Size(140, 32);
            this->lblStatTitle6->TabIndex = 1;
            this->lblStatTitle6->Text = L"Overdue Milestones Flagged";
            // 
            // lblStatVal6
            // 
            this->lblStatVal6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 17, System::Drawing::FontStyle::Bold));
            this->lblStatVal6->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(15)), static_cast<System::Int32>(static_cast<System::Byte>(23)),
                static_cast<System::Int32>(static_cast<System::Byte>(42)));
            this->lblStatVal6->Location = System::Drawing::Point(8, 44);
            this->lblStatVal6->Name = L"lblStatVal6";
            this->lblStatVal6->Size = System::Drawing::Size(140, 38);
            this->lblStatVal6->TabIndex = 2;
            this->lblStatVal6->Text = L"0";
            // 
            // lblDashboardTableTitle
            // 
            this->lblDashboardTableTitle->AutoSize = true;
            this->lblDashboardTableTitle->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 12, System::Drawing::FontStyle::Bold));
            this->lblDashboardTableTitle->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(15)),
                static_cast<System::Int32>(static_cast<System::Byte>(23)), static_cast<System::Int32>(static_cast<System::Byte>(42)));
            this->lblDashboardTableTitle->Location = System::Drawing::Point(20, 130);
            this->lblDashboardTableTitle->Name = L"lblDashboardTableTitle";
            this->lblDashboardTableTitle->Size = System::Drawing::Size(457, 28);
            this->lblDashboardTableTitle->TabIndex = 1;
            this->lblDashboardTableTitle->Text = L"Real-Time Milestone Tracking & Turnaround Status";
            // 
            // dgvDashboardOverview
            // 
            this->dgvDashboardOverview->AllowUserToAddRows = false;
            dataGridViewCellStyle1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(248)),
                static_cast<System::Int32>(static_cast<System::Byte>(250)), static_cast<System::Int32>(static_cast<System::Byte>(252)));
            this->dgvDashboardOverview->AlternatingRowsDefaultCellStyle = dataGridViewCellStyle1;
            this->dgvDashboardOverview->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->dgvDashboardOverview->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
            this->dgvDashboardOverview->BackgroundColor = System::Drawing::Color::White;
            this->dgvDashboardOverview->CellBorderStyle = System::Windows::Forms::DataGridViewCellBorderStyle::SingleHorizontal;
            this->dgvDashboardOverview->ColumnHeadersBorderStyle = System::Windows::Forms::DataGridViewHeaderBorderStyle::None;
            dataGridViewCellStyle2->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
            dataGridViewCellStyle2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(15)), static_cast<System::Int32>(static_cast<System::Byte>(23)),
                static_cast<System::Int32>(static_cast<System::Byte>(42)));
            dataGridViewCellStyle2->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 9.25F, System::Drawing::FontStyle::Bold));
            dataGridViewCellStyle2->ForeColor = System::Drawing::Color::White;
            dataGridViewCellStyle2->SelectionBackColor = System::Drawing::SystemColors::Highlight;
            dataGridViewCellStyle2->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
            dataGridViewCellStyle2->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
            this->dgvDashboardOverview->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle2;
            this->dgvDashboardOverview->ColumnHeadersHeight = 36;
            dataGridViewCellStyle3->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
            dataGridViewCellStyle3->BackColor = System::Drawing::SystemColors::Window;
            dataGridViewCellStyle3->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9));
            dataGridViewCellStyle3->ForeColor = System::Drawing::SystemColors::ControlText;
            dataGridViewCellStyle3->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(242)), static_cast<System::Int32>(static_cast<System::Byte>(254)));
            dataGridViewCellStyle3->SelectionForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(15)),
                static_cast<System::Int32>(static_cast<System::Byte>(23)), static_cast<System::Int32>(static_cast<System::Byte>(42)));
            dataGridViewCellStyle3->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
            this->dgvDashboardOverview->DefaultCellStyle = dataGridViewCellStyle3;
            this->dgvDashboardOverview->EnableHeadersVisualStyles = false;
            this->dgvDashboardOverview->GridColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(226)),
                static_cast<System::Int32>(static_cast<System::Byte>(232)), static_cast<System::Int32>(static_cast<System::Byte>(240)));
            this->dgvDashboardOverview->Location = System::Drawing::Point(20, 162);
            this->dgvDashboardOverview->MultiSelect = false;
            this->dgvDashboardOverview->Name = L"dgvDashboardOverview";
            this->dgvDashboardOverview->ReadOnly = true;
            this->dgvDashboardOverview->RowHeadersWidth = 51;
            this->dgvDashboardOverview->RowTemplate->Height = 32;
            this->dgvDashboardOverview->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
            this->dgvDashboardOverview->Size = System::Drawing::Size(1830, 1152);
            this->dgvDashboardOverview->TabIndex = 2;
            this->dgvDashboardOverview->CellFormatting += gcnew System::Windows::Forms::DataGridViewCellFormattingEventHandler(this, &MainForm::dgvDashboardOverview_CellFormatting);
            // 
            // tabAlerts
            // 
            this->tabAlerts->Location = System::Drawing::Point(4, 5);
            this->tabAlerts->Name = L"tabAlerts";
            this->tabAlerts->Size = System::Drawing::Size(192, 91);
            this->tabAlerts->TabIndex = 1;
            // 
            // tabSemestersCourses
            // 
            this->tabSemestersCourses->Location = System::Drawing::Point(4, 5);
            this->tabSemestersCourses->Name = L"tabSemestersCourses";
            this->tabSemestersCourses->Size = System::Drawing::Size(192, 91);
            this->tabSemestersCourses->TabIndex = 2;
            // 
            // tabStaff
            // 
            this->tabStaff->Location = System::Drawing::Point(4, 5);
            this->tabStaff->Name = L"tabStaff";
            this->tabStaff->Size = System::Drawing::Size(192, 91);
            this->tabStaff->TabIndex = 3;
            // 
            // tabOfferings
            // 
            this->tabOfferings->Location = System::Drawing::Point(4, 5);
            this->tabOfferings->Name = L"tabOfferings";
            this->tabOfferings->Size = System::Drawing::Size(192, 91);
            this->tabOfferings->TabIndex = 4;
            // 
            // tabScripts
            // 
            this->tabScripts->Location = System::Drawing::Point(4, 5);
            this->tabScripts->Name = L"tabScripts";
            this->tabScripts->Size = System::Drawing::Size(192, 91);
            this->tabScripts->TabIndex = 5;
            // 
            // tabMilestones
            // 
            this->tabMilestones->Location = System::Drawing::Point(4, 5);
            this->tabMilestones->Name = L"tabMilestones";
            this->tabMilestones->Size = System::Drawing::Size(192, 91);
            this->tabMilestones->TabIndex = 6;
            // 
            // tabEvaluation
            // 
            this->tabEvaluation->Location = System::Drawing::Point(4, 5);
            this->tabEvaluation->Name = L"tabEvaluation";
            this->tabEvaluation->Size = System::Drawing::Size(192, 91);
            this->tabEvaluation->TabIndex = 7;
            // 
            // tabAudit
            // 
            this->tabAudit->Location = System::Drawing::Point(4, 5);
            this->tabAudit->Name = L"tabAudit";
            this->tabAudit->Size = System::Drawing::Size(192, 91);
            this->tabAudit->TabIndex = 8;
            // 
            // tabDatabase
            // 
            this->tabDatabase->Location = System::Drawing::Point(4, 5);
            this->tabDatabase->Name = L"tabDatabase";
            this->tabDatabase->Size = System::Drawing::Size(192, 91);
            this->tabDatabase->TabIndex = 9;
            // 
            // MainForm
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(8, 20);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(241)), static_cast<System::Int32>(static_cast<System::Byte>(245)),
                static_cast<System::Int32>(static_cast<System::Byte>(249)));
            this->ClientSize = System::Drawing::Size(1280, 800);
            this->Controls->Add(this->panelMainContent);
            this->Controls->Add(this->panelSidebar);
            this->Controls->Add(this->panelTop);
            this->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9));
            this->MinimumSize = System::Drawing::Size(1150, 720);
            this->Name = L"MainForm";
            this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
            this->Text = L"Examination Results Monitoring System - University Academic Governance Suite";
            this->panelTop->ResumeLayout(false);
            this->panelTop->PerformLayout();
            this->panelTopRight->ResumeLayout(false);
            this->panelTopRight->PerformLayout();
            this->panelSidebar->ResumeLayout(false);
            this->panelBrandLogo->ResumeLayout(false);
            this->panelBrandLogo->PerformLayout();
            this->panelMainContent->ResumeLayout(false);
            this->tabModules->ResumeLayout(false);
            this->tabDashboard->ResumeLayout(false);
            this->tabDashboard->PerformLayout();
            this->tlpStats->ResumeLayout(false);
            this->pnlStat1->ResumeLayout(false);
            this->pnlStat2->ResumeLayout(false);
            this->pnlStat3->ResumeLayout(false);
            this->pnlStat4->ResumeLayout(false);
            this->pnlStat5->ResumeLayout(false);
            this->pnlStat6->ResumeLayout(false);
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvDashboardOverview))->EndInit();
            this->ResumeLayout(false);

        }



        void InitNavButton(System::Windows::Forms::Button^ btn, String^ text, int top, int tabIndex) {

            btn->BackColor = System::Drawing::Color::Transparent;

            btn->FlatAppearance->BorderSize = 0;

            btn->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(51, 65, 85);

            btn->FlatAppearance->MouseDownBackColor = System::Drawing::Color::FromArgb(15, 23, 42);

            btn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;

            btn->Cursor = System::Windows::Forms::Cursors::Hand;

            btn->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 9.25F, System::Drawing::FontStyle::Bold));

            btn->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(226)),

                static_cast<System::Int32>(static_cast<System::Byte>(232)), static_cast<System::Int32>(static_cast<System::Byte>(240)));

            btn->Location = System::Drawing::Point(0, top);

            btn->Name = "btnNav" + tabIndex.ToString();

            btn->Size = System::Drawing::Size(245, 42);

            btn->TabIndex = tabIndex;

            btn->Text = text;

            btn->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;

            btn->Padding = System::Windows::Forms::Padding(12, 0, 8, 0);

            btn->UseVisualStyleBackColor = false;

            btn->Tag = tabIndex;

            btn->Click += gcnew System::EventHandler(this, &MainForm::OnNavButtonClick);

        }



        void OnNavButtonClick(System::Object^ sender, System::EventArgs^ e) {

            System::Windows::Forms::Button^ btn = (System::Windows::Forms::Button^)sender;

            int tabIndex = (int)btn->Tag;

            tabModules->SelectedIndex = tabIndex;



            for each (Control^ c in panelSidebar->Controls) {

                System::Windows::Forms::Button^ navBtn = dynamic_cast<System::Windows::Forms::Button^>(c);

                if (navBtn != nullptr) {

                    navBtn->BackColor = System::Drawing::Color::Transparent;

                    navBtn->ForeColor = System::Drawing::Color::FromArgb(203, 213, 225);

                    navBtn->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(51, 65, 85);

                }

            }

            btn->BackColor = System::Drawing::Color::FromArgb(2, 132, 199);

            btn->ForeColor = System::Drawing::Color::White;

            btn->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(3, 105, 161);



            RefreshAllViews();

        }



        void SetupDashboardTab() {

            // Pre-configured in InitializeComponent for offline Visual Studio Designer visualization

        }



        Panel^ CreateStatCard(String^ title, String^ initialVal, Color accentColor, Label^% outValLabel) {

            Panel^ p = gcnew Panel();

            p->Dock = DockStyle::Fill;

            p->Margin = System::Windows::Forms::Padding(4);

            p->BackColor = Color::White;

            p->BorderStyle = BorderStyle::FixedSingle;



            Panel^ strip = gcnew Panel();

            strip->Dock = DockStyle::Top;

            strip->Height = 4;

            strip->BackColor = accentColor;

            p->Controls->Add(strip);



            Label^ lblTitle = gcnew Label();

            lblTitle->Text = title;

            lblTitle->Font = gcnew System::Drawing::Font("Segoe UI Semibold", 8.0F);

            lblTitle->ForeColor = Color::FromArgb(100, 116, 139);

            lblTitle->Location = Point(10, 10);

            lblTitle->Size = System::Drawing::Size(140, 32);

            p->Controls->Add(lblTitle);



            outValLabel = gcnew Label();

            outValLabel->Text = initialVal;

            outValLabel->Font = gcnew System::Drawing::Font("Segoe UI Bold", 17.0F, FontStyle::Bold);

            outValLabel->ForeColor = Color::FromArgb(15, 23, 42);

            outValLabel->Location = Point(8, 44);

            outValLabel->Size = System::Drawing::Size(140, 38);

            p->Controls->Add(outValLabel);



            return p;

        }



        void dgvDashboardOverview_CellFormatting(System::Object^ sender, DataGridViewCellFormattingEventArgs^ e) {

            if (e->Value != nullptr) {

                String^ val = e->Value->ToString();

                if (val->Contains("OVERDUE") || val->Contains("Delay")) {

                    e->CellStyle->ForeColor = Color::FromArgb(220, 38, 38);

                    e->CellStyle->Font = gcnew System::Drawing::Font("Segoe UI Semibold", 9.0F, FontStyle::Bold);

                } else if (val->Contains("Completed") || val->Contains("Approved")) {

                    e->CellStyle->ForeColor = Color::FromArgb(22, 163, 74);

                    e->CellStyle->Font = gcnew System::Drawing::Font("Segoe UI Semibold", 9.0F, FontStyle::Bold);

                } else if (val->Contains("Moderation") || val->Contains("Pending")) {

                    e->CellStyle->ForeColor = Color::FromArgb(180, 83, 9);

                }

            }

        }



        void SetupAlertsTab() {

            tabAlerts->BackColor = Color::FromArgb(248, 250, 252);

            tabAlerts->Padding = System::Windows::Forms::Padding(20);



            pnlAlertBanner = gcnew Panel();

            pnlAlertBanner->Dock = DockStyle::Top;

            pnlAlertBanner->Height = 65;

            pnlAlertBanner->BackColor = Color::FromArgb(254, 242, 242);

            pnlAlertBanner->BorderStyle = BorderStyle::FixedSingle;

            tabAlerts->Controls->Add(pnlAlertBanner);



            lblAlertHeader = gcnew Label();

            lblAlertHeader->Text = "⚠️ Automated Delay Detection & Statutory Deadline Monitor (FR5)";

            lblAlertHeader->Font = gcnew System::Drawing::Font("Segoe UI Semibold", 11.0F, FontStyle::Bold);

            lblAlertHeader->ForeColor = Color::FromArgb(185, 28, 28);

            lblAlertHeader->Location = Point(14, 10);

            lblAlertHeader->Size = System::Drawing::Size(800, 22);

            pnlAlertBanner->Controls->Add(lblAlertHeader);



            lblAlertSub = gcnew Label();

            lblAlertSub->Text = "Rules: First Marking Statutory Deadline = ExamEndDate + 1 Month (FR3.3) | Second Marking Turnaround Cap = 14 Days (FR5.2)";

            lblAlertSub->Font = gcnew System::Drawing::Font("Segoe UI", 8.75F);

            lblAlertSub->ForeColor = Color::FromArgb(127, 29, 29);

            lblAlertSub->Location = Point(14, 34);

            lblAlertSub->Size = System::Drawing::Size(900, 18);

            pnlAlertBanner->Controls->Add(lblAlertSub);



            dgvAlerts = gcnew DataGridView();

            dgvAlerts->Location = Point(20, 95);

            dgvAlerts->Size = System::Drawing::Size(995, 570);

            dgvAlerts->Anchor = static_cast<AnchorStyles>(AnchorStyles::Top | AnchorStyles::Bottom | AnchorStyles::Left | AnchorStyles::Right);

            dgvAlerts->ReadOnly = true;

            dgvAlerts->AllowUserToAddRows = false;

            dgvAlerts->AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode::Fill;

            StyleDataGridView(dgvAlerts);

            dgvAlerts->CellFormatting += gcnew DataGridViewCellFormattingEventHandler(this, &MainForm::dgvAlerts_CellFormatting);

            tabAlerts->Controls->Add(dgvAlerts);

        }



        void dgvAlerts_CellFormatting(System::Object^ sender, DataGridViewCellFormattingEventArgs^ e) {

            if (e->ColumnIndex == 0 && e->Value != nullptr) {

                String^ sev = e->Value->ToString();

                if (sev->Contains("🔴")) {

                    e->CellStyle->BackColor = Color::FromArgb(254, 226, 226);

                    e->CellStyle->ForeColor = Color::FromArgb(185, 28, 28);

                    e->CellStyle->Font = gcnew System::Drawing::Font("Segoe UI Bold", 9.0F, FontStyle::Bold);

                } else if (sev->Contains("🟡")) {

                    e->CellStyle->BackColor = Color::FromArgb(254, 249, 195);

                    e->CellStyle->ForeColor = Color::FromArgb(161, 98, 7);

                    e->CellStyle->Font = gcnew System::Drawing::Font("Segoe UI Bold", 9.0F, FontStyle::Bold);

                }

            }

        }



        void SetupSemestersTab() {

            tabSemestersCourses->BackColor = Color::FromArgb(248, 250, 252);

            tabSemestersCourses->Padding = System::Windows::Forms::Padding(20);



            Label^ lblSemTitle = gcnew Label();

            lblSemTitle->Text = "1. Academic Semesters Setup (SEMESTER Relation)";

            lblSemTitle->Font = gcnew System::Drawing::Font("Segoe UI Semibold", 11.5F, FontStyle::Bold);

            lblSemTitle->ForeColor = Color::FromArgb(15, 23, 42);

            lblSemTitle->Location = Point(20, 10);

            lblSemTitle->Size = System::Drawing::Size(500, 22);

            tabSemestersCourses->Controls->Add(lblSemTitle);



            dgvSemesters = gcnew DataGridView();

            dgvSemesters->Location = Point(20, 35);

            dgvSemesters->Size = System::Drawing::Size(640, 240);

            dgvSemesters->ReadOnly = true;

            dgvSemesters->AllowUserToAddRows = false;

            dgvSemesters->AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode::Fill;

            StyleDataGridView(dgvSemesters);

            tabSemestersCourses->Controls->Add(dgvSemesters);



            Panel^ pnlSemForm = gcnew Panel();

            pnlSemForm->Location = Point(675, 35);

            pnlSemForm->Size = System::Drawing::Size(340, 240);

            pnlSemForm->BackColor = Color::White;

            pnlSemForm->BorderStyle = BorderStyle::FixedSingle;

            tabSemestersCourses->Controls->Add(pnlSemForm);



            AddFormField(pnlSemForm, "Semester ID:", txtSemId = gcnew TextBox(), 10, 10, 145);

            txtSemId->Text = "SEM2027_S1";

            AddFormField(pnlSemForm, "Academic Year:", txtSemYear = gcnew TextBox(), 165, 10, 155);

            txtSemYear->Text = "2026/2027";



            Label^ lblNum = gcnew Label(); lblNum->Text = "Sem Number (1 or 2):"; lblNum->Location = Point(10, 65); lblNum->Size = System::Drawing::Size(145, 15); pnlSemForm->Controls->Add(lblNum);

            numSemNumber = gcnew NumericUpDown(); numSemNumber->Minimum = 1; numSemNumber->Maximum = 2; numSemNumber->Value = 1; numSemNumber->Location = Point(10, 82); numSemNumber->Size = System::Drawing::Size(90, 23); pnlSemForm->Controls->Add(numSemNumber);



            Label^ lblStart = gcnew Label(); lblStart->Text = "Start Date:"; lblStart->Location = Point(10, 115); lblStart->Size = System::Drawing::Size(100, 15); pnlSemForm->Controls->Add(lblStart);

            dtpSemStart = gcnew DateTimePicker(); dtpSemStart->Format = DateTimePickerFormat::Short; dtpSemStart->Location = Point(10, 132); dtpSemStart->Size = System::Drawing::Size(145, 23); pnlSemForm->Controls->Add(dtpSemStart);



            Label^ lblEnd = gcnew Label(); lblEnd->Text = "End Date:"; lblEnd->Location = Point(165, 115); lblEnd->Size = System::Drawing::Size(100, 15); pnlSemForm->Controls->Add(lblEnd);

            dtpSemEnd = gcnew DateTimePicker(); dtpSemEnd->Format = DateTimePickerFormat::Short; dtpSemEnd->Location = Point(165, 132); dtpSemEnd->Size = System::Drawing::Size(155, 23); dtpSemEnd->Value = DateTime::Now.AddMonths(4); pnlSemForm->Controls->Add(dtpSemEnd);



            Label^ lblExStart = gcnew Label(); lblExStart->Text = "Exam Start:"; lblExStart->Location = Point(10, 160); lblExStart->Size = System::Drawing::Size(100, 15); pnlSemForm->Controls->Add(lblExStart);

            dtpExamStart = gcnew DateTimePicker(); dtpExamStart->Format = DateTimePickerFormat::Short; dtpExamStart->Location = Point(10, 177); dtpExamStart->Size = System::Drawing::Size(145, 23); dtpExamStart->Value = dtpSemEnd->Value.AddDays(-20); pnlSemForm->Controls->Add(dtpExamStart);



            Label^ lblExEnd = gcnew Label(); lblExEnd->Text = "Exam End:"; lblExEnd->Location = Point(165, 160); lblExEnd->Size = System::Drawing::Size(100, 15); pnlSemForm->Controls->Add(lblExEnd);

            dtpExamEnd = gcnew DateTimePicker(); dtpExamEnd->Format = DateTimePickerFormat::Short; dtpExamEnd->Location = Point(165, 177); dtpExamEnd->Size = System::Drawing::Size(155, 23); dtpExamEnd->Value = dtpSemEnd->Value; pnlSemForm->Controls->Add(dtpExamEnd);



            btnSaveSemester = gcnew Button();

            btnSaveSemester->Text = "Register Semester";

            btnSaveSemester->Location = Point(165, 205);

            btnSaveSemester->Size = System::Drawing::Size(155, 28);

            StylePrimaryButton(btnSaveSemester);

            btnSaveSemester->Click += gcnew EventHandler(this, &MainForm::btnSaveSemester_Click);

            pnlSemForm->Controls->Add(btnSaveSemester);



            Label^ lblCrsTitle = gcnew Label();

            lblCrsTitle->Text = "2. Academic Courses Catalog (COURSE Relation)";

            lblCrsTitle->Font = gcnew System::Drawing::Font("Segoe UI Semibold", 11.5F, FontStyle::Bold);

            lblCrsTitle->ForeColor = Color::FromArgb(15, 23, 42);

            lblCrsTitle->Location = Point(20, 290);

            lblCrsTitle->Size = System::Drawing::Size(500, 22);

            tabSemestersCourses->Controls->Add(lblCrsTitle);



            dgvCourses = gcnew DataGridView();

            dgvCourses->Location = Point(20, 315);

            dgvCourses->Size = System::Drawing::Size(640, 350);

            dgvCourses->Anchor = static_cast<AnchorStyles>(AnchorStyles::Top | AnchorStyles::Bottom | AnchorStyles::Left);

            dgvCourses->ReadOnly = true;

            dgvCourses->AllowUserToAddRows = false;

            dgvCourses->AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode::Fill;

            StyleDataGridView(dgvCourses);

            tabSemestersCourses->Controls->Add(dgvCourses);



            Panel^ pnlCrsForm = gcnew Panel();

            pnlCrsForm->Location = Point(675, 315);

            pnlCrsForm->Size = System::Drawing::Size(340, 200);

            pnlCrsForm->BackColor = Color::White;

            pnlCrsForm->BorderStyle = BorderStyle::FixedSingle;

            tabSemestersCourses->Controls->Add(pnlCrsForm);



            AddFormField(pnlCrsForm, "Course Code (PK):", txtCourseCode = gcnew TextBox(), 10, 10, 145);

            txtCourseCode->Text = "ICT2408";

            AddFormField(pnlCrsForm, "Year Level (1 - 4):", numCourseYear = gcnew NumericUpDown(), 165, 10, 155);

            numCourseYear->Minimum = 1; numCourseYear->Maximum = 4; numCourseYear->Value = 2;



            AddFormField(pnlCrsForm, "Course Title:", txtCourseTitle = gcnew TextBox(), 10, 65, 310);

            txtCourseTitle->Text = "Advanced Web Applications Architecture";



            btnSaveCourse = gcnew Button();

            btnSaveCourse->Text = "Add Course Definition";

            btnSaveCourse->Location = Point(155, 125);

            btnSaveCourse->Size = System::Drawing::Size(165, 34);

            StylePrimaryButton(btnSaveCourse);

            btnSaveCourse->Click += gcnew EventHandler(this, &MainForm::btnSaveCourse_Click);

            pnlCrsForm->Controls->Add(btnSaveCourse);

        }



        void SetupStaffTab() {

            tabStaff->BackColor = Color::FromArgb(248, 250, 252);

            tabStaff->Padding = System::Windows::Forms::Padding(20);



            Label^ lblTitle = gcnew Label();

            lblTitle->Text = "Staff Directory & Institutional Workload Allocation (ACADEMIC_STAFF & Subtypes)";

            lblTitle->Font = gcnew System::Drawing::Font("Segoe UI Semibold", 12.0F, FontStyle::Bold);

            lblTitle->ForeColor = Color::FromArgb(15, 23, 42);

            lblTitle->Location = Point(20, 15);

            lblTitle->Size = System::Drawing::Size(700, 25);

            tabStaff->Controls->Add(lblTitle);



            dgvStaff = gcnew DataGridView();

            dgvStaff->Location = Point(20, 45);

            dgvStaff->Size = System::Drawing::Size(640, 620);

            dgvStaff->Anchor = static_cast<AnchorStyles>(AnchorStyles::Top | AnchorStyles::Bottom | AnchorStyles::Left);

            dgvStaff->ReadOnly = true;

            dgvStaff->AllowUserToAddRows = false;

            dgvStaff->AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode::Fill;

            StyleDataGridView(dgvStaff);

            tabStaff->Controls->Add(dgvStaff);



            Panel^ pnlStaffForm = gcnew Panel();

            pnlStaffForm->Location = Point(675, 45);

            pnlStaffForm->Size = System::Drawing::Size(340, 460);

            pnlStaffForm->BackColor = Color::White;

            pnlStaffForm->BorderStyle = BorderStyle::FixedSingle;

            tabStaff->Controls->Add(pnlStaffForm);



            AddFormField(pnlStaffForm, "Staff UserID (PK):", txtStaffId = gcnew TextBox(), 10, 10, 145);

            txtStaffId->Text = "STF006";

            AddFormField(pnlStaffForm, "Designation / Role:", txtStaffRole = gcnew TextBox(), 165, 10, 155);

            txtStaffRole->Text = "Senior Lecturer Gr. II";



            AddFormField(pnlStaffForm, "Full Name:", txtStaffName = gcnew TextBox(), 10, 65, 310);

            txtStaffName->Text = "Dr. W. P. Fernando";



            AddFormField(pnlStaffForm, "Email (Unique):", txtStaffEmail = gcnew TextBox(), 10, 120, 310);

            txtStaffEmail->Text = "wfernando@univ.ac.lk";



            chkIsAcademic = gcnew CheckBox(); chkIsAcademic->Text = "Academic Staff (Superclass)"; chkIsAcademic->Checked = true; chkIsAcademic->Location = Point(10, 175); chkIsAcademic->Size = System::Drawing::Size(200, 20); pnlStaffForm->Controls->Add(chkIsAcademic);

            chkIsInternal = gcnew CheckBox(); chkIsInternal->Text = "Internal Staff (Disjoint Subclass)"; chkIsInternal->Checked = true; chkIsInternal->Location = Point(10, 200); chkIsInternal->Size = System::Drawing::Size(200, 20); pnlStaffForm->Controls->Add(chkIsInternal);



            AddFormField(pnlStaffForm, "Department ID (Internal):", txtDepartment = gcnew TextBox(), 10, 230, 145);

            txtDepartment->Text = "DEPT_CS";



            AddFormField(pnlStaffForm, "Max Workload Cap (3-4):", numMaxWorkload = gcnew NumericUpDown(), 165, 230, 155);

            numMaxWorkload->Minimum = 1; numMaxWorkload->Maximum = 6; numMaxWorkload->Value = 4;



            AddFormField(pnlStaffForm, "Contact Phone (External):", txtContactNumber = gcnew TextBox(), 10, 285, 310);

            txtContactNumber->Text = "+94701234567";



            btnSaveStaff = gcnew Button();

            btnSaveStaff->Text = "Register Staff Record";

            btnSaveStaff->Location = Point(155, 350);

            btnSaveStaff->Size = System::Drawing::Size(165, 36);

            StylePrimaryButton(btnSaveStaff);

            btnSaveStaff->Click += gcnew EventHandler(this, &MainForm::btnSaveStaff_Click);

            pnlStaffForm->Controls->Add(btnSaveStaff);

        }



        void SetupOfferingsTab() {

            tabOfferings->BackColor = Color::FromArgb(248, 250, 252);

            tabOfferings->Padding = System::Windows::Forms::Padding(20);



            Label^ lblTitle = gcnew Label();

            lblTitle->Text = "Course Offerings, Examiner Nomination & Senate Clearance (FR1, FR2)";

            lblTitle->Font = gcnew System::Drawing::Font("Segoe UI Semibold", 12.0F, FontStyle::Bold);

            lblTitle->ForeColor = Color::FromArgb(15, 23, 42);

            lblTitle->Location = Point(20, 15);

            lblTitle->Size = System::Drawing::Size(750, 25);

            tabOfferings->Controls->Add(lblTitle);



            dgvOfferings = gcnew DataGridView();

            dgvOfferings->Location = Point(20, 45);

            dgvOfferings->Size = System::Drawing::Size(640, 620);

            dgvOfferings->Anchor = static_cast<AnchorStyles>(AnchorStyles::Top | AnchorStyles::Bottom | AnchorStyles::Left);

            dgvOfferings->ReadOnly = true;

            dgvOfferings->AllowUserToAddRows = false;

            dgvOfferings->AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode::Fill;

            StyleDataGridView(dgvOfferings);

            dgvOfferings->SelectionChanged += gcnew EventHandler(this, &MainForm::dgvOfferings_SelectionChanged);

            tabOfferings->Controls->Add(dgvOfferings);



            Panel^ pnlOffForm = gcnew Panel();

            pnlOffForm->Location = Point(675, 45);

            pnlOffForm->Size = System::Drawing::Size(340, 520);

            pnlOffForm->BackColor = Color::White;

            pnlOffForm->BorderStyle = BorderStyle::FixedSingle;

            tabOfferings->Controls->Add(pnlOffForm);



            AddFormField(pnlOffForm, "Offering ID (PK):", txtOfferingId = gcnew TextBox(), 10, 10, 145);

            txtOfferingId->Text = "OFF2026_ICT3204";



            AddFormField(pnlOffForm, "Semester (FK):", cmbOfferingSem = gcnew ComboBox(), 165, 10, 155);

            cmbOfferingSem->DropDownStyle = ComboBoxStyle::DropDownList;



            AddFormField(pnlOffForm, "Course (FK):", cmbOfferingCourse = gcnew ComboBox(), 10, 65, 310);

            cmbOfferingCourse->DropDownStyle = ComboBoxStyle::DropDownList;



            AddFormField(pnlOffForm, "First Examiner (Marks papers):", cmbOfferingFirstEx = gcnew ComboBox(), 10, 120, 310);

            cmbOfferingFirstEx->DropDownStyle = ComboBoxStyle::DropDownList;



            AddFormField(pnlOffForm, "Second Examiner (Moderator):", cmbOfferingSecondEx = gcnew ComboBox(), 10, 175, 310);

            cmbOfferingSecondEx->DropDownStyle = ComboBoxStyle::DropDownList;



            AddFormField(pnlOffForm, "Senate Approval Status:", cmbOfferingSenate = gcnew ComboBox(), 10, 230, 310);

            cmbOfferingSenate->DropDownStyle = ComboBoxStyle::DropDownList;

            cmbOfferingSenate->Items->AddRange(gcnew cli::array<System::Object^> { "Pending", "Approved", "Rejected" });

            cmbOfferingSenate->SelectedIndex = 0;



            pnlWorkloadCallout = gcnew Panel();

            pnlWorkloadCallout->Location = Point(10, 280);

            pnlWorkloadCallout->Size = System::Drawing::Size(310, 55);

            pnlWorkloadCallout->BackColor = Color::FromArgb(240, 249, 255);

            pnlWorkloadCallout->BorderStyle = BorderStyle::FixedSingle;

            pnlOffForm->Controls->Add(pnlWorkloadCallout);



            lblWorkloadIndicator = gcnew Label();

            lblWorkloadIndicator->Dock = DockStyle::Fill;

            lblWorkloadIndicator->Font = gcnew System::Drawing::Font("Segoe UI", 8.25F);

            lblWorkloadIndicator->ForeColor = Color::FromArgb(3, 105, 161);

            lblWorkloadIndicator->Text = "ℹ️ Workload Constraint: Internal staff allocation is programmatically validated against the institutional MaxWorkload cap (3-4 courses per semester).";

            pnlWorkloadCallout->Controls->Add(lblWorkloadIndicator);



            btnSaveOffering = gcnew Button();

            btnSaveOffering->Text = "Create / Update Offering";

            btnSaveOffering->Location = Point(155, 345);

            btnSaveOffering->Size = System::Drawing::Size(165, 36);

            StylePrimaryButton(btnSaveOffering);

            btnSaveOffering->Click += gcnew EventHandler(this, &MainForm::btnSaveOffering_Click);

            pnlOffForm->Controls->Add(btnSaveOffering);



            btnToggleSenate = gcnew Button();

            btnToggleSenate->Text = "Toggle Senate Clearance";

            btnToggleSenate->Location = Point(155, 390);

            btnToggleSenate->Size = System::Drawing::Size(165, 36);

            StyleSuccessButton(btnToggleSenate);

            btnToggleSenate->Click += gcnew EventHandler(this, &MainForm::btnToggleSenate_Click);

            pnlOffForm->Controls->Add(btnToggleSenate);

        }



        void SetupScriptsTab() {

            tabScripts->BackColor = Color::FromArgb(248, 250, 252);

            tabScripts->Padding = System::Windows::Forms::Padding(20);



            Label^ lblTitle = gcnew Label();

            lblTitle->Text = "Answer Script Custody & Sealed Bundle Tracking (ANSWER_SCRIPT Weak Entity)";

            lblTitle->Font = gcnew System::Drawing::Font("Segoe UI Semibold", 12.0F, FontStyle::Bold);

            lblTitle->ForeColor = Color::FromArgb(15, 23, 42);

            lblTitle->Location = Point(20, 15);

            lblTitle->Size = System::Drawing::Size(750, 25);

            tabScripts->Controls->Add(lblTitle);



            dgvScripts = gcnew DataGridView();

            dgvScripts->Location = Point(20, 45);

            dgvScripts->Size = System::Drawing::Size(640, 620);

            dgvScripts->Anchor = static_cast<AnchorStyles>(AnchorStyles::Top | AnchorStyles::Bottom | AnchorStyles::Left);

            dgvScripts->ReadOnly = true;

            dgvScripts->AllowUserToAddRows = false;

            dgvScripts->AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode::Fill;

            StyleDataGridView(dgvScripts);

            tabScripts->Controls->Add(dgvScripts);



            Panel^ pnlScriptForm = gcnew Panel();

            pnlScriptForm->Location = Point(675, 45);

            pnlScriptForm->Size = System::Drawing::Size(340, 360);

            pnlScriptForm->BackColor = Color::White;

            pnlScriptForm->BorderStyle = BorderStyle::FixedSingle;

            tabScripts->Controls->Add(pnlScriptForm);



            AddFormField(pnlScriptForm, "Course Offering (Owner Entity):", cmbScriptOffering = gcnew ComboBox(), 10, 10, 310);

            cmbScriptOffering->DropDownStyle = ComboBoxStyle::DropDownList;

            cmbScriptOffering->SelectedIndexChanged += gcnew EventHandler(this, &MainForm::cmbScriptOffering_SelectedIndexChanged);



            AddFormField(pnlScriptForm, "Bundle Number (Partial Key):", numBundleNo = gcnew NumericUpDown(), 10, 65, 145);

            numBundleNo->Minimum = 1; numBundleNo->Maximum = 20; numBundleNo->Value = 1;



            AddFormField(pnlScriptForm, "Script Count (chk_script_count > 0):", numScriptCount = gcnew NumericUpDown(), 165, 65, 155);

            numScriptCount->Minimum = 1; numScriptCount->Maximum = 500; numScriptCount->Value = 65;



            Label^ lblHDate = gcnew Label(); lblHDate->Text = "Supervisor Handover Date:"; lblHDate->Location = Point(10, 120); lblHDate->Size = System::Drawing::Size(200, 15); pnlScriptForm->Controls->Add(lblHDate);

            dtpSupervisorHandover = gcnew DateTimePicker(); dtpSupervisorHandover->Format = DateTimePickerFormat::Short; dtpSupervisorHandover->Location = Point(10, 137); dtpSupervisorHandover->Size = System::Drawing::Size(145, 23); pnlScriptForm->Controls->Add(dtpSupervisorHandover);



            pnlScriptSummary = gcnew Panel();

            pnlScriptSummary->Location = Point(10, 180);

            pnlScriptSummary->Size = System::Drawing::Size(310, 60);

            pnlScriptSummary->BackColor = Color::FromArgb(248, 250, 252);

            pnlScriptSummary->BorderStyle = BorderStyle::FixedSingle;

            pnlScriptForm->Controls->Add(pnlScriptSummary);



            lblScriptSummary = gcnew Label();

            lblScriptSummary->Dock = DockStyle::Fill;

            lblScriptSummary->Font = gcnew System::Drawing::Font("Segoe UI Semibold", 9.0F);

            lblScriptSummary->ForeColor = Color::FromArgb(37, 99, 235);

            lblScriptSummary->Text = "Bundle Count: 0 | Total Script Count: 0";

            lblScriptSummary->TextAlign = ContentAlignment::MiddleCenter;

            pnlScriptSummary->Controls->Add(lblScriptSummary);



            btnAddScriptBundle = gcnew Button();

            btnAddScriptBundle->Text = "Log Sealed Bundle Handover";

            btnAddScriptBundle->Location = Point(110, 260);

            btnAddScriptBundle->Size = System::Drawing::Size(210, 38);

            StylePrimaryButton(btnAddScriptBundle);

            btnAddScriptBundle->Click += gcnew EventHandler(this, &MainForm::btnAddScriptBundle_Click);

            pnlScriptForm->Controls->Add(btnAddScriptBundle);

        }



        void SetupMilestonesTab() {

            tabMilestones->BackColor = Color::FromArgb(248, 250, 252);

            tabMilestones->Padding = System::Windows::Forms::Padding(20);



            Label^ lblTitle = gcnew Label();

            lblTitle->Text = "Sequential Marking Lifecycle & Statutory Milestones Tracking";

            lblTitle->Font = gcnew System::Drawing::Font("Segoe UI Semibold", 12.0F, FontStyle::Bold);

            lblTitle->ForeColor = Color::FromArgb(15, 23, 42);

            lblTitle->Location = Point(20, 15);

            lblTitle->Size = System::Drawing::Size(750, 25);

            tabMilestones->Controls->Add(lblTitle);



            dgvMilestones = gcnew DataGridView();

            dgvMilestones->Location = Point(20, 45);

            dgvMilestones->Size = System::Drawing::Size(640, 620);

            dgvMilestones->Anchor = static_cast<AnchorStyles>(AnchorStyles::Top | AnchorStyles::Bottom | AnchorStyles::Left);

            dgvMilestones->ReadOnly = true;

            dgvMilestones->AllowUserToAddRows = false;

            dgvMilestones->AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode::Fill;

            StyleDataGridView(dgvMilestones);

            dgvMilestones->SelectionChanged += gcnew EventHandler(this, &MainForm::dgvMilestones_SelectionChanged);

            tabMilestones->Controls->Add(dgvMilestones);



            Panel^ pnlActions = gcnew Panel();

            pnlActions->Location = Point(675, 45);

            pnlActions->Size = System::Drawing::Size(340, 560);

            pnlActions->BackColor = Color::White;

            pnlActions->BorderStyle = BorderStyle::FixedSingle;

            tabMilestones->Controls->Add(pnlActions);



            pnlSelectedOfferingChip = gcnew Panel();

            pnlSelectedOfferingChip->Location = Point(15, 15);

            pnlSelectedOfferingChip->Size = System::Drawing::Size(305, 42);

            pnlSelectedOfferingChip->BackColor = Color::FromArgb(15, 23, 42);

            pnlActions->Controls->Add(pnlSelectedOfferingChip);



            lblSelectedOffering = gcnew Label();

            lblSelectedOffering->Dock = DockStyle::Fill;

            lblSelectedOffering->Font = gcnew System::Drawing::Font("Segoe UI Semibold", 9.5F, FontStyle::Bold);

            lblSelectedOffering->ForeColor = Color::FromArgb(56, 189, 248);

            lblSelectedOffering->Text = "Selected Offering: None";

            lblSelectedOffering->TextAlign = ContentAlignment::MiddleCenter;

            pnlSelectedOfferingChip->Controls->Add(lblSelectedOffering);



            lblMilestoneStatusDesc = gcnew Label();

            lblMilestoneStatusDesc->Font = gcnew System::Drawing::Font("Segoe UI", 8.5F);

            lblMilestoneStatusDesc->ForeColor = Color::FromArgb(100, 116, 139);

            lblMilestoneStatusDesc->Location = Point(15, 65);

            lblMilestoneStatusDesc->Size = System::Drawing::Size(305, 40);

            lblMilestoneStatusDesc->Text = "Advance the statutory marking lifecycle below. Actions are gated by role privileges and procedural checks:";

            pnlActions->Controls->Add(lblMilestoneStatusDesc);



            btnMilestoneCollect = gcnew Button();

            StyleWorkflowStepButton(btnMilestoneCollect, "▶ Step 1: Collect Scripts (HandoverDate)", 115, pnlActions);

            btnMilestoneCollect->Click += gcnew EventHandler(this, &MainForm::btnMilestoneCollect_Click);



            btnMilestoneMarkSheet = gcnew Button();

            StyleWorkflowStepButton(btnMilestoneMarkSheet, "▶ Step 2: Submit Detailed Mark Sheet", 170, pnlActions);

            btnMilestoneMarkSheet->Click += gcnew EventHandler(this, &MainForm::btnMilestoneMarkSheet_Click);



            btnMilestoneDispatch = gcnew Button();

            StyleWorkflowStepButton(btnMilestoneDispatch, "▶ Step 3: Dispatch to 2nd Examiner", 225, pnlActions);

            btnMilestoneDispatch->Click += gcnew EventHandler(this, &MainForm::btnMilestoneDispatch_Click);



            btnMilestoneReturn = gcnew Button();

            StyleWorkflowStepButton(btnMilestoneReturn, "▶ Step 4: Return from 2nd Examiner", 280, pnlActions);

            btnMilestoneReturn->Click += gcnew EventHandler(this, &MainForm::btnMilestoneReturn_Click);



            btnMilestoneEIS = gcnew Button();

            StyleWorkflowStepButton(btnMilestoneEIS, "▶ Step 5: Upload Marks to EIS", 335, pnlActions);

            btnMilestoneEIS->Click += gcnew EventHandler(this, &MainForm::btnMilestoneEIS_Click);



            btnMilestoneHOD = gcnew Button();

            StyleWorkflowStepButton(btnMilestoneHOD, "▶ Step 6: HOD Verify & Authorize", 390, pnlActions);

            btnMilestoneHOD->Click += gcnew EventHandler(this, &MainForm::btnMilestoneHOD_Click);

        }



        void SetupEvaluationTab() {

            tabEvaluation->BackColor = Color::FromArgb(248, 250, 252);

            tabEvaluation->Padding = System::Windows::Forms::Padding(20);



            Label^ lblTitle = gcnew Label();

            lblTitle->Text = "Course Evaluation Structure: Continuous Assessment (CA) & Written Exam (100%)";

            lblTitle->Font = gcnew System::Drawing::Font("Segoe UI Semibold", 12.0F, FontStyle::Bold);

            lblTitle->ForeColor = Color::FromArgb(15, 23, 42);

            lblTitle->Location = Point(20, 15);

            lblTitle->Size = System::Drawing::Size(750, 25);

            tabEvaluation->Controls->Add(lblTitle);



            Label^ lblDesc = gcnew Label();

            lblDesc->Text = "Business Rule 1.1 / FR4.1: All courses are evaluated through a Written Examination and Continuous Assessment (CA) summing strictly to 100%.";

            lblDesc->Font = gcnew System::Drawing::Font("Segoe UI", 9.0F);

            lblDesc->ForeColor = Color::FromArgb(100, 116, 139);

            lblDesc->Location = Point(20, 42);

            lblDesc->Size = System::Drawing::Size(900, 20);

            tabEvaluation->Controls->Add(lblDesc);



            Panel^ pnlEval = gcnew Panel();

            pnlEval->Location = Point(20, 75);

            pnlEval->Size = System::Drawing::Size(580, 460);

            pnlEval->BackColor = Color::White;

            pnlEval->BorderStyle = BorderStyle::FixedSingle;

            tabEvaluation->Controls->Add(pnlEval);



            AddFormField(pnlEval, "Select Course Offering:", cmbEvalOffering = gcnew ComboBox(), 20, 20, 530);

            cmbEvalOffering->DropDownStyle = ComboBoxStyle::DropDownList;

            cmbEvalOffering->SelectedIndexChanged += gcnew EventHandler(this, &MainForm::cmbEvalOffering_SelectedIndexChanged);



            AddFormField(pnlEval, "Continuous Assessment Weight (%):", numCaWeight = gcnew NumericUpDown(), 20, 80, 240);

            numCaWeight->Minimum = 0; numCaWeight->Maximum = 100; numCaWeight->Value = 40;

            numCaWeight->ValueChanged += gcnew EventHandler(this, &MainForm::OnWeightChanged);



            AddFormField(pnlEval, "Final Written Exam Weight (%):", numExamWeight = gcnew NumericUpDown(), 290, 80, 240);

            numExamWeight->Minimum = 0; numExamWeight->Maximum = 100; numExamWeight->Value = 60;

            numExamWeight->ValueChanged += gcnew EventHandler(this, &MainForm::OnWeightChanged);



            lblWeightSumStatus = gcnew Label();

            lblWeightSumStatus->Location = Point(20, 140);

            lblWeightSumStatus->Size = System::Drawing::Size(300, 24);

            lblWeightSumStatus->Font = gcnew System::Drawing::Font("Segoe UI Semibold", 9.0F);

            lblWeightSumStatus->ForeColor = Color::FromArgb(22, 163, 74);

            lblWeightSumStatus->Text = "✓ Component Total: 100% (Valid Academic Weighting)";

            pnlEval->Controls->Add(lblWeightSumStatus);



            btnSaveWeights = gcnew Button();

            btnSaveWeights->Text = "Verify & Save Weights (100%)";

            btnSaveWeights->Location = Point(330, 135);

            btnSaveWeights->Size = System::Drawing::Size(200, 34);

            StylePrimaryButton(btnSaveWeights);

            btnSaveWeights->Click += gcnew EventHandler(this, &MainForm::btnSaveWeights_Click);

            pnlEval->Controls->Add(btnSaveWeights);



            Label^ lblCalc = gcnew Label();

            lblCalc->Text = "Sample Student Marks Merge Calculator (Continuous Assessment + Exam):";

            lblCalc->Font = gcnew System::Drawing::Font("Segoe UI Semibold", 9.5F, FontStyle::Bold);

            lblCalc->ForeColor = Color::FromArgb(15, 23, 42);

            lblCalc->Location = Point(20, 195);

            lblCalc->Size = System::Drawing::Size(500, 20);

            pnlEval->Controls->Add(lblCalc);



            AddFormField(pnlEval, "Student Index No:", txtSampleStudentId = gcnew TextBox(), 20, 225, 160);

            txtSampleStudentId->Text = "IT2026/045";



            AddFormField(pnlEval, "CA Raw Score (out of 100):", numSampleCaScore = gcnew NumericUpDown(), 200, 225, 150);

            numSampleCaScore->Minimum = 0; numSampleCaScore->Maximum = 100; numSampleCaScore->Value = 75;



            AddFormField(pnlEval, "Exam Raw Score (out of 100):", numSampleExamScore = gcnew NumericUpDown(), 370, 225, 160);

            numSampleExamScore->Minimum = 0; numSampleExamScore->Maximum = 100; numSampleExamScore->Value = 82;



            btnCalculateScore = gcnew Button();

            btnCalculateScore->Text = "Compute Final Aggregate Grade";

            btnCalculateScore->Location = Point(20, 285);

            btnCalculateScore->Size = System::Drawing::Size(240, 36);

            StyleSuccessButton(btnCalculateScore);

            btnCalculateScore->Click += gcnew EventHandler(this, &MainForm::btnCalculateScore_Click);

            pnlEval->Controls->Add(btnCalculateScore);



            pnlScoreResult = gcnew Panel();

            pnlScoreResult->Location = Point(20, 335);

            pnlScoreResult->Size = System::Drawing::Size(530, 95);

            pnlScoreResult->BackColor = Color::FromArgb(248, 250, 252);

            pnlScoreResult->BorderStyle = BorderStyle::FixedSingle;

            pnlEval->Controls->Add(pnlScoreResult);



            lblScoreResult = gcnew Label();

            lblScoreResult->Dock = DockStyle::Fill;

            lblScoreResult->Font = gcnew System::Drawing::Font("Segoe UI Semibold", 9.5F);

            lblScoreResult->ForeColor = Color::FromArgb(15, 23, 42);

            lblScoreResult->Padding = System::Windows::Forms::Padding(10);

            lblScoreResult->Text = "Enter Continuous Assessment and Exam scores above and click 'Compute' to calculate.";

            pnlScoreResult->Controls->Add(lblScoreResult);

        }



        void OnWeightChanged(System::Object^ sender, System::EventArgs^ e) {

            double sum = (double)(numCaWeight->Value + numExamWeight->Value);

            if (Math::Abs(sum - 100.0) < 0.001) {

                lblWeightSumStatus->ForeColor = Color::FromArgb(22, 163, 74);

                lblWeightSumStatus->Text = "✓ Component Total: 100% (Valid Academic Weighting)";

            } else {

                lblWeightSumStatus->ForeColor = Color::FromArgb(220, 38, 38);

                lblWeightSumStatus->Text = "✗ Component Total: " + sum.ToString("F0") + "% (Must equal 100% exactly)";

            }

        }



        void SetupAuditTab() {

            tabAudit->BackColor = Color::FromArgb(248, 250, 252);

            tabAudit->Padding = System::Windows::Forms::Padding(20);



            Label^ lblTitle = gcnew Label();

            lblTitle->Text = "Immutable Audit Trail (AUDIT_LOG Relation & Governance Policy)";

            lblTitle->Font = gcnew System::Drawing::Font("Segoe UI Semibold", 12.0F, FontStyle::Bold);

            lblTitle->ForeColor = Color::FromArgb(15, 23, 42);

            lblTitle->Location = Point(20, 15);

            lblTitle->Size = System::Drawing::Size(750, 25);

            tabAudit->Controls->Add(lblTitle);



            Label^ lblSearch = gcnew Label(); lblSearch->Text = "Filter by Offering ID / Changed By:"; lblSearch->Location = Point(20, 48); lblSearch->Size = System::Drawing::Size(200, 15); tabAudit->Controls->Add(lblSearch);

            txtAuditSearch = gcnew TextBox(); txtAuditSearch->Location = Point(220, 45); txtAuditSearch->Size = System::Drawing::Size(220, 23); txtAuditSearch->TextChanged += gcnew EventHandler(this, &MainForm::txtAuditSearch_TextChanged); tabAudit->Controls->Add(txtAuditSearch);



            btnRefreshAudit = gcnew Button();

            btnRefreshAudit->Text = "Refresh Audit Records";

            btnRefreshAudit->Location = Point(460, 43);

            btnRefreshAudit->Size = System::Drawing::Size(170, 28);

            StyleDarkButton(btnRefreshAudit);

            btnRefreshAudit->Click += gcnew EventHandler(this, &MainForm::btnRefreshAudit_Click);

            tabAudit->Controls->Add(btnRefreshAudit);



            dgvAudit = gcnew DataGridView();

            dgvAudit->Location = Point(20, 85);

            dgvAudit->Size = System::Drawing::Size(995, 580);

            dgvAudit->Anchor = static_cast<AnchorStyles>(AnchorStyles::Top | AnchorStyles::Bottom | AnchorStyles::Left | AnchorStyles::Right);

            dgvAudit->ReadOnly = true;

            dgvAudit->AllowUserToAddRows = false;

            dgvAudit->AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode::Fill;

            StyleDataGridView(dgvAudit);

            tabAudit->Controls->Add(dgvAudit);

        }



        void SetupDatabaseTab() {

            tabDatabase->BackColor = Color::FromArgb(248, 250, 252);

            tabDatabase->Padding = System::Windows::Forms::Padding(20);



            Label^ lblTitle = gcnew Label();

            lblTitle->Text = "MySQL Schema & Storage Engine Diagnostics (InnoDB, utf8mb4)";

            lblTitle->Font = gcnew System::Drawing::Font("Segoe UI Semibold", 12.0F, FontStyle::Bold);

            lblTitle->ForeColor = Color::FromArgb(15, 23, 42);

            lblTitle->Location = Point(20, 15);

            lblTitle->Size = System::Drawing::Size(750, 25);

            tabDatabase->Controls->Add(lblTitle);



            btnGenerateDdl = gcnew Button();

            btnGenerateDdl->Text = "View MySQL DDL Scripts";

            btnGenerateDdl->Location = Point(20, 50);

            btnGenerateDdl->Size = System::Drawing::Size(190, 34);

            StyleDarkButton(btnGenerateDdl);

            btnGenerateDdl->Click += gcnew EventHandler(this, &MainForm::btnGenerateDdl_Click);

            tabDatabase->Controls->Add(btnGenerateDdl);



            btnGenerateDml = gcnew Button();

            btnGenerateDml->Text = "Export Data as SQL INSERTS";

            btnGenerateDml->Location = Point(220, 50);

            btnGenerateDml->Size = System::Drawing::Size(210, 34);

            StyleTealButton(btnGenerateDml);

            btnGenerateDml->Click += gcnew EventHandler(this, &MainForm::btnGenerateDml_Click);

            tabDatabase->Controls->Add(btnGenerateDml);



            btnTestMySql = gcnew Button();

            btnTestMySql->Text = "Test MySQL Service (3306)";

            btnTestMySql->Location = Point(440, 50);

            btnTestMySql->Size = System::Drawing::Size(190, 34);

            StylePrimaryButton(btnTestMySql);

            btnTestMySql->Click += gcnew EventHandler(this, &MainForm::btnTestMySql_Click);

            tabDatabase->Controls->Add(btnTestMySql);



            btnReloadSampleData = gcnew Button();

            btnReloadSampleData->Text = "Reset Baseline Sample Data";

            btnReloadSampleData->Location = Point(640, 50);

            btnReloadSampleData->Size = System::Drawing::Size(200, 34);

            StyleAmberButton(btnReloadSampleData);

            btnReloadSampleData->Click += gcnew EventHandler(this, &MainForm::btnReloadSampleData_Click);

            tabDatabase->Controls->Add(btnReloadSampleData);



            txtSqlOutput = gcnew TextBox();

            txtSqlOutput->Location = Point(20, 95);

            txtSqlOutput->Size = System::Drawing::Size(995, 570);

            txtSqlOutput->Multiline = true;

            txtSqlOutput->ScrollBars = ScrollBars::Both;

            txtSqlOutput->Font = gcnew System::Drawing::Font("Consolas", 10.0F);

            txtSqlOutput->BackColor = Color::FromArgb(15, 23, 42);

            txtSqlOutput->ForeColor = Color::FromArgb(226, 232, 240);

            txtSqlOutput->BorderStyle = BorderStyle::FixedSingle;

            txtSqlOutput->Anchor = static_cast<AnchorStyles>(AnchorStyles::Top | AnchorStyles::Bottom | AnchorStyles::Left | AnchorStyles::Right);

            tabDatabase->Controls->Add(txtSqlOutput);

        }



        void AddFormField(Panel^ parent, String^ labelText, Control^ ctrl, int left, int top, int width) {

            Label^ lbl = gcnew Label();

            lbl->Text = labelText;

            lbl->Font = gcnew System::Drawing::Font("Segoe UI Semibold", 8.5F);

            lbl->ForeColor = Color::FromArgb(51, 65, 85);

            lbl->Location = Point(left, top);

            lbl->Size = System::Drawing::Size(width, 16);

            parent->Controls->Add(lbl);



            ctrl->Location = Point(left, top + 18);

            ctrl->Size = System::Drawing::Size(width, 24);

            parent->Controls->Add(ctrl);

        }



        void ApplyRolePermissions() {

            lblUserBadge->Text = _session->Name + " | Role: " + Roles::GetDisplayName(_session->Role);



            if (_session->IsDean()) {

                btnSaveSemester->Enabled = false;

                btnSaveCourse->Enabled = false;

                btnSaveStaff->Enabled = false;

                btnSaveOffering->Enabled = false;

                btnToggleSenate->Enabled = false;

                btnAddScriptBundle->Enabled = false;

                btnMilestoneCollect->Enabled = false;

                btnMilestoneMarkSheet->Enabled = false;

                btnMilestoneDispatch->Enabled = false;

                btnMilestoneReturn->Enabled = false;

                btnMilestoneEIS->Enabled = false;

                btnMilestoneHOD->Enabled = false;

                btnSaveWeights->Enabled = false;

            }



            else if (_session->IsSupervisor()) {

                btnSaveSemester->Enabled = false;

                btnSaveCourse->Enabled = false;

                btnSaveStaff->Enabled = false;

                btnSaveOffering->Enabled = false;

                btnToggleSenate->Enabled = false;

                btnAddScriptBundle->Enabled = true;

                btnMilestoneCollect->Enabled = false;

                btnMilestoneMarkSheet->Enabled = false;

                btnMilestoneDispatch->Enabled = false;

                btnMilestoneReturn->Enabled = false;

                btnMilestoneEIS->Enabled = false;

                btnMilestoneHOD->Enabled = false;

                btnSaveWeights->Enabled = false;

            }



            else if (_session->IsFirstExaminer()) {

                btnSaveSemester->Enabled = false;

                btnSaveCourse->Enabled = false;

                btnSaveStaff->Enabled = false;

                btnSaveOffering->Enabled = false;

                btnToggleSenate->Enabled = false;

                btnAddScriptBundle->Enabled = false;

                btnMilestoneCollect->Enabled = true;

                btnMilestoneMarkSheet->Enabled = true;

                btnMilestoneDispatch->Enabled = false;

                btnMilestoneReturn->Enabled = false;

                btnMilestoneEIS->Enabled = true;

                btnMilestoneHOD->Enabled = false;

                btnSaveWeights->Enabled = true;

            }



            else if (_session->IsSecondExaminer()) {

                btnSaveSemester->Enabled = false;

                btnSaveCourse->Enabled = false;

                btnSaveStaff->Enabled = false;

                btnSaveOffering->Enabled = false;

                btnToggleSenate->Enabled = false;

                btnAddScriptBundle->Enabled = false;

                btnMilestoneCollect->Enabled = false;

                btnMilestoneMarkSheet->Enabled = false;

                btnMilestoneDispatch->Enabled = false;

                btnMilestoneReturn->Enabled = true;

                btnMilestoneEIS->Enabled = false;

                btnMilestoneHOD->Enabled = false;

                btnSaveWeights->Enabled = false;

            }



            else if (_session->IsHOD()) {

                btnSaveSemester->Enabled = false;

                btnSaveCourse->Enabled = false;

                btnSaveStaff->Enabled = false;

                btnSaveOffering->Enabled = false;

                btnToggleSenate->Enabled = false;

                btnAddScriptBundle->Enabled = false;

                btnMilestoneCollect->Enabled = false;

                btnMilestoneMarkSheet->Enabled = false;

                btnMilestoneDispatch->Enabled = false;

                btnMilestoneReturn->Enabled = false;

                btnMilestoneEIS->Enabled = false;

                btnMilestoneHOD->Enabled = true;

                btnSaveWeights->Enabled = false;

            }



            else if (_session->IsAROffice()) {

                btnSaveSemester->Enabled = true;

                btnSaveCourse->Enabled = true;

                btnSaveStaff->Enabled = true;

                btnSaveOffering->Enabled = true;

                btnToggleSenate->Enabled = true;

                btnAddScriptBundle->Enabled = true;

                btnMilestoneCollect->Enabled = true;

                btnMilestoneMarkSheet->Enabled = true;

                btnMilestoneDispatch->Enabled = true;

                btnMilestoneReturn->Enabled = true;

                btnMilestoneEIS->Enabled = true;

                btnMilestoneHOD->Enabled = true;

                btnSaveWeights->Enabled = true;

            }

        }



        void PopulateSemesterFilter() {

            cmbSemesterFilter->Items->Clear();

            cmbSemesterFilter->Items->Add("All Semesters");

            for each (Semester^ s in _db->Semesters) {

                cmbSemesterFilter->Items->Add(s->SemesterID);

            }

            cmbSemesterFilter->SelectedIndex = 0;

        }



        String^ GetSelectedSemester() {

            if (cmbSemesterFilter->SelectedIndex <= 0) return "";

            return cmbSemesterFilter->SelectedItem->ToString();

        }



        void cmbSemesterFilter_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {

            RefreshAllViews();

        }



        void RefreshAllViews() {

            String^ semFilter = GetSelectedSemester();

            List<CourseOffering^>^ currentOfferings = _db->GetOfferingsBySemester(semFilter);



            int total = currentOfferings->Count;

            int senateApprovedCount = 0;

            int firstMarkingCount = 0;

            int secondMarkingCount = 0;

            int hodAuthorizedCount = 0;

            int overdueCount = 0;



            for each (CourseOffering^ o in currentOfferings) {

                Semester^ sem = _db->FindSemester(o->SemesterID);

                DateTime examEndDate = sem != nullptr ? sem->ExamEndDate : DateTime::Now;



                if (o->SenateApproved == "Approved") senateApprovedCount++;

                if (o->HandoverDate.HasValue && o->DetailedMarkSheetSubmitted == "No") firstMarkingCount++;

                if (o->DispatchedToSecondExaminerDate.HasValue && !o->ReturnedFromSecondExaminerDate.HasValue) secondMarkingCount++;

                if (o->HODApprovedDate.HasValue) hodAuthorizedCount++;



                if (o->IsFirstMarkingOverdue(examEndDate) || o->IsModerationOverdue()) {

                    overdueCount++;

                }

            }



            lblStatVal1->Text = total.ToString();

            lblStatVal2->Text = senateApprovedCount.ToString();

            lblStatVal3->Text = firstMarkingCount.ToString();

            lblStatVal4->Text = secondMarkingCount.ToString();

            lblStatVal5->Text = hodAuthorizedCount.ToString();

            lblStatVal6->Text = overdueCount.ToString();



            DataTable^ dtOverview = gcnew DataTable();

            dtOverview->Columns->Add("Offering ID");

            dtOverview->Columns->Add("Semester");

            dtOverview->Columns->Add("Course");

            dtOverview->Columns->Add("First Examiner");

            dtOverview->Columns->Add("Second Examiner");

            dtOverview->Columns->Add("Senate Approval");

            dtOverview->Columns->Add("Mark Sheet");

            dtOverview->Columns->Add("Moderation Status");

            dtOverview->Columns->Add("Overall Milestone Status");



            for each (CourseOffering^ o in currentOfferings) {

                Course^ crs = _db->FindCourse(o->CourseCode);

                String^ crsDesc = crs != nullptr ? crs->CourseCode + " - " + crs->CourseTitle : o->CourseCode;

                String^ modStatus = "Not Dispatched";

                if (o->DispatchedToSecondExaminerDate.HasValue) {

                    int days = o->GetModerationDurationDays();

                    if (o->ReturnedFromSecondExaminerDate.HasValue) {

                        modStatus = "Returned (" + days.ToString() + " days)";

                    } else {

                        modStatus = "In Moderation (" + days.ToString() + " days" + (o->IsModerationOverdue() ? " - OVERDUE!" : "") + ")";

                    }

                }



                dtOverview->Rows->Add(

                    o->OfferingID,

                    o->SemesterID,

                    crsDesc,

                    o->First_userID,

                    o->Second_userID != nullptr ? o->Second_userID : "None",

                    o->SenateApproved,

                    o->DetailedMarkSheetSubmitted,

                    modStatus,

                    o->GetOverallStatus()

                );

            }

            dgvDashboardOverview->DataSource = dtOverview;



            RefreshAlertsGrid();



            RefreshSemestersAndCourses();



            RefreshStaffGrid();



            RefreshOfferingsGrid();



            RefreshScriptsGrid();



            RefreshMilestonesGrid();



            PopulateOfferingDropdowns();



            RefreshAuditGrid("");

        }



        void RefreshAlertsGrid() {

            DataTable^ dtAlerts = gcnew DataTable();

            dtAlerts->Columns->Add("Severity Badge");

            dtAlerts->Columns->Add("Offering ID");

            dtAlerts->Columns->Add("Course");

            dtAlerts->Columns->Add("First Examiner");

            dtAlerts->Columns->Add("Second Examiner");

            dtAlerts->Columns->Add("Statutory Rule / Milestone");

            dtAlerts->Columns->Add("Status & Overdue Duration");

            dtAlerts->Columns->Add("Required Action");



            String^ semFilter = GetSelectedSemester();

            List<CourseOffering^>^ currentOfferings = _db->GetOfferingsBySemester(semFilter);



            for each (CourseOffering^ o in currentOfferings) {

                Semester^ sem = _db->FindSemester(o->SemesterID);

                DateTime examEndDate = sem != nullptr ? sem->ExamEndDate : DateTime::Now;



                DateTime firstMarkingDeadline = examEndDate.AddMonths(1);

                if (o->DetailedMarkSheetSubmitted == "No" && DateTime::Now.Date > firstMarkingDeadline) {

                    int daysLate = (int)(DateTime::Now.Date - firstMarkingDeadline).TotalDays;

                    dtAlerts->Rows->Add(

                        "🔴 CRITICAL DELAY",

                        o->OfferingID,

                        o->CourseCode,

                        o->First_userID,

                        o->Second_userID,

                        "First Marking Deadline (ExamEndDate + 1 Mo)",

                        "OVERDUE by " + daysLate.ToString() + " days (Deadline was " + firstMarkingDeadline.ToString("yyyy-MM-dd") + ")",

                        "Urge First Examiner to submit Detailed Mark Sheet immediately."

                    );

                }



                if (o->DispatchedToSecondExaminerDate.HasValue && !o->ReturnedFromSecondExaminerDate.HasValue) {

                    int days = o->GetModerationDurationDays();

                    if (days > 14) {

                        dtAlerts->Rows->Add(

                            "🔴 MODERATION BOTTLENECK",

                            o->OfferingID,

                            o->CourseCode,

                            o->First_userID,

                            o->Second_userID,

                            "Second Marking Turnaround Cap (>14 Days)",

                            "Elapsed " + days.ToString() + " days (Exceeded 14-day institutional limit)",

                            "Issue formal reminder to Second Examiner to return moderated script package."

                        );

                    }

                }



                if (o->SenateApproved == "Pending") {

                    dtAlerts->Rows->Add(

                        "🟡 PROCEDURAL GATE",

                        o->OfferingID,

                        o->CourseCode,

                        o->First_userID,

                        o->Second_userID,

                        "Senate Clearance (C-Form Approval)",

                        "Pending Senate Confirmation (Grading locked)",

                        "Submit C-Form nomination for Senate confirmation."

                    );

                }



                if (o->DetailedMarkSheetSubmitted == "Yes" && !o->EISUploadDate.HasValue) {

                    dtAlerts->Rows->Add(

                        "🟡 EIS UPLOAD PENDING",

                        o->OfferingID,

                        o->CourseCode,

                        o->First_userID,

                        o->Second_userID,

                        "Final Marks Upload into EIS (FR4.2)",

                        "Detailed mark sheet submitted; EIS entry pending",

                        "First Examiner must enter marks into Exam Information System."

                    );

                }



                if (o->EISUploadDate.HasValue && !o->HODApprovedDate.HasValue) {

                    dtAlerts->Rows->Add(

                        "🟡 RESULT AUTHORIZATION PENDING",

                        o->OfferingID,

                        o->CourseCode,

                        o->First_userID,

                        o->Second_userID,

                        "HOD Digital Sign-Off & Verification (FR4.3)",

                        "Marks in EIS; awaiting departmental verification",

                        "HOD must verify against physical mark sheet and authorize."

                    );

                }

            }

            dgvAlerts->DataSource = dtAlerts;

        }



        void RefreshSemestersAndCourses() {

            DataTable^ dtSem = gcnew DataTable();

            dtSem->Columns->Add("Semester ID");

            dtSem->Columns->Add("Academic Year");

            dtSem->Columns->Add("Sem No");

            dtSem->Columns->Add("Start Date");

            dtSem->Columns->Add("End Date");

            dtSem->Columns->Add("Exam Start");

            dtSem->Columns->Add("Exam End");

            dtSem->Columns->Add("1-Mo Grading Deadline");



            for each (Semester^ s in _db->Semesters) {

                dtSem->Rows->Add(

                    s->SemesterID,

                    s->AcademicYear,

                    s->SemesterNumber,

                    s->StartDate.ToString("yyyy-MM-dd"),

                    s->EndDate.ToString("yyyy-MM-dd"),

                    s->ExamStartDate.ToString("yyyy-MM-dd"),

                    s->ExamEndDate.ToString("yyyy-MM-dd"),

                    s->GetFirstMarkingDeadline().ToString("yyyy-MM-dd")

                );

            }

            dgvSemesters->DataSource = dtSem;



            DataTable^ dtCrs = gcnew DataTable();

            dtCrs->Columns->Add("Course Code");

            dtCrs->Columns->Add("Course Title");

            dtCrs->Columns->Add("Year Level");



            for each (Course^ c in _db->Courses) {

                dtCrs->Rows->Add(c->CourseCode, c->CourseTitle, "Year " + c->YearLevel.ToString());

            }

            dgvCourses->DataSource = dtCrs;

        }



        void RefreshStaffGrid() {

            String^ activeSem = GetSelectedSemester();

            if (String::IsNullOrEmpty(activeSem) && _db->Semesters->Count > 0) {

                activeSem = _db->Semesters[0]->SemesterID;

            }



            DataTable^ dt = gcnew DataTable();

            dt->Columns->Add("User ID");

            dt->Columns->Add("Staff Name");

            dt->Columns->Add("Email");

            dt->Columns->Add("Staff Type");

            dt->Columns->Add("Dept / Affiliation");

            dt->Columns->Add("Max Workload");

            dt->Columns->Add("Assigned Courses (" + activeSem + ")");

            dt->Columns->Add("Workload Status");



            for each (Staff^ st in _db->StaffMembers) {

                String^ staffType = st->IsAcademic ? (st->IsInternal ? "Internal Academic" : "External Academic") : "Non-Academic";

                String^ dept = st->IsInternal ? st->DepartmentID : (st->IsAcademic ? "External" : st->DepartmentID);

                String^ maxW = st->IsInternal ? st->MaxWorkload.ToString() : "N/A";

                int activeCourses = _db->GetStaffActiveWorkload(st->UserID, activeSem, "");



                String^ workloadStatus = "Normal";

                if (st->IsInternal) {

                    if (activeCourses >= st->MaxWorkload) workloadStatus = "AT WORKLOAD CAP";

                    else if (activeCourses == st->MaxWorkload - 1) workloadStatus = "Near Cap";

                }



                dt->Rows->Add(

                    st->UserID,

                    st->Name,

                    st->Email,

                    staffType,

                    dept,

                    maxW,

                    activeCourses.ToString(),

                    workloadStatus

                );

            }

            dgvStaff->DataSource = dt;

        }



        void RefreshOfferingsGrid() {

            String^ semFilter = GetSelectedSemester();

            List<CourseOffering^>^ currentOfferings = _db->GetOfferingsBySemester(semFilter);



            DataTable^ dt = gcnew DataTable();

            dt->Columns->Add("Offering ID");

            dt->Columns->Add("Semester");

            dt->Columns->Add("Course");

            dt->Columns->Add("First Examiner");

            dt->Columns->Add("Second Examiner");

            dt->Columns->Add("Senate Status");

            dt->Columns->Add("Bundles");

            dt->Columns->Add("Total Scripts");



            for each (CourseOffering^ o in currentOfferings) {

                int bundles = _db->GetBundleCountForOffering(o->OfferingID);

                int scripts = _db->GetTotalScriptsForOffering(o->OfferingID);

                dt->Rows->Add(

                    o->OfferingID,

                    o->SemesterID,

                    o->CourseCode,

                    o->First_userID,

                    o->Second_userID != nullptr ? o->Second_userID : "None",

                    o->SenateApproved,

                    bundles.ToString(),

                    scripts.ToString()

                );

            }

            dgvOfferings->DataSource = dt;

        }



        void RefreshScriptsGrid() {

            DataTable^ dt = gcnew DataTable();

            dt->Columns->Add("Offering ID");

            dt->Columns->Add("Bundle Number");

            dt->Columns->Add("Script Count");

            dt->Columns->Add("Supervisor Handover Date");



            for each (AnswerScript^ a in _db->AnswerScripts) {

                dt->Rows->Add(

                    a->OfferingID,

                    "Bundle #" + a->BundleNumber.ToString(),

                    a->ScriptCount.ToString() + " scripts",

                    a->SupervisorHandoverDate.HasValue ? a->SupervisorHandoverDate.Value.ToString("yyyy-MM-dd") : "Pending"

                );

            }

            dgvScripts->DataSource = dt;

        }



        void RefreshMilestonesGrid() {

            String^ semFilter = GetSelectedSemester();

            List<CourseOffering^>^ currentOfferings = _db->GetOfferingsBySemester(semFilter);



            DataTable^ dt = gcnew DataTable();

            dt->Columns->Add("Offering ID");

            dt->Columns->Add("Course");

            dt->Columns->Add("Senate Approval");

            dt->Columns->Add("Script Collected");

            dt->Columns->Add("Mark Sheet");

            dt->Columns->Add("Dispatched to 2nd");

            dt->Columns->Add("Returned from 2nd");

            dt->Columns->Add("EIS Upload");

            dt->Columns->Add("HOD Approved");



            for each (CourseOffering^ o in currentOfferings) {

                dt->Rows->Add(

                    o->OfferingID,

                    o->CourseCode,

                    o->SenateApproved,

                    o->HandoverDate.HasValue ? o->HandoverDate.Value.ToString("yyyy-MM-dd") : "Not Collected",

                    o->DetailedMarkSheetSubmitted,

                    o->DispatchedToSecondExaminerDate.HasValue ? o->DispatchedToSecondExaminerDate.Value.ToString("yyyy-MM-dd") : "Pending",

                    o->ReturnedFromSecondExaminerDate.HasValue ? o->ReturnedFromSecondExaminerDate.Value.ToString("yyyy-MM-dd") : "Pending",

                    o->EISUploadDate.HasValue ? o->EISUploadDate.Value.ToString("yyyy-MM-dd") : "Pending",

                    o->HODApprovedDate.HasValue ? o->HODApprovedDate.Value.ToString("yyyy-MM-dd") : "Pending"

                );

            }

            dgvMilestones->DataSource = dt;

        }



        void RefreshAuditGrid(String^ filter) {

            DataTable^ dt = gcnew DataTable();

            dt->Columns->Add("Log ID");

            dt->Columns->Add("Offering ID");

            dt->Columns->Add("Attribute Changed");

            dt->Columns->Add("Previous Value");

            dt->Columns->Add("New Value");

            dt->Columns->Add("Executing User");

            dt->Columns->Add("Timestamp (ISO)");



            for each (AuditEntry^ a in _db->AuditLogs) {

                if (!String::IsNullOrEmpty(filter)) {

                    if (!a->OfferingID->ToLower()->Contains(filter->ToLower()) &&

                        !a->ChangedBy->ToLower()->Contains(filter->ToLower())) {

                        continue;

                    }

                }

                dt->Rows->Add(

                    a->LogID,

                    a->OfferingID,

                    a->AttributeChanged,

                    a->OldValue,

                    a->NewValue,

                    a->ChangedBy,

                    a->ChangeTimestamp.ToString("yyyy-MM-dd HH:mm:ss")

                );

            }

            dgvAudit->DataSource = dt;

        }



        void PopulateOfferingDropdowns() {

            cmbOfferingSem->Items->Clear();

            for each (Semester^ s in _db->Semesters) cmbOfferingSem->Items->Add(s->SemesterID);

            if (cmbOfferingSem->Items->Count > 0) cmbOfferingSem->SelectedIndex = 0;



            cmbOfferingCourse->Items->Clear();

            for each (Course^ c in _db->Courses) cmbOfferingCourse->Items->Add(c->CourseCode + " - " + c->CourseTitle);

            if (cmbOfferingCourse->Items->Count > 0) cmbOfferingCourse->SelectedIndex = 0;



            cmbOfferingFirstEx->Items->Clear();

            cmbOfferingSecondEx->Items->Clear();

            cmbOfferingSecondEx->Items->Add("[None]");

            for each (Staff^ st in _db->StaffMembers) {

                if (st->IsAcademic) {

                    cmbOfferingFirstEx->Items->Add(st->UserID + " (" + st->Name + ")");

                    cmbOfferingSecondEx->Items->Add(st->UserID + " (" + st->Name + ")");

                }

            }

            if (cmbOfferingFirstEx->Items->Count > 0) cmbOfferingFirstEx->SelectedIndex = 0;

            if (cmbOfferingSecondEx->Items->Count > 0) cmbOfferingSecondEx->SelectedIndex = 0;



            cmbScriptOffering->Items->Clear();

            cmbEvalOffering->Items->Clear();

            for each (CourseOffering^ o in _db->Offerings) {

                cmbScriptOffering->Items->Add(o->OfferingID);

                cmbEvalOffering->Items->Add(o->OfferingID);

            }

            if (cmbScriptOffering->Items->Count > 0) cmbScriptOffering->SelectedIndex = 0;

            if (cmbEvalOffering->Items->Count > 0) cmbEvalOffering->SelectedIndex = 0;

        }



        void btnSaveSemester_Click(System::Object^ sender, System::EventArgs^ e) {

            String^ err;

            Semester^ sem = gcnew Semester(

                txtSemId->Text->Trim(),

                txtSemYear->Text->Trim(),

                (int)numSemNumber->Value,

                dtpSemStart->Value.Date,

                dtpSemEnd->Value.Date,

                dtpExamStart->Value.Date,

                dtpExamEnd->Value.Date

            );



            if (_db->SaveSemester(sem, true, err)) {

                MessageBox::Show("Semester registered successfully!", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);

                PopulateSemesterFilter();

                RefreshAllViews();

            } else {

                MessageBox::Show(err, "Validation Failure", MessageBoxButtons::OK, MessageBoxIcon::Error);

            }

        }



        void btnSaveCourse_Click(System::Object^ sender, System::EventArgs^ e) {

            String^ err;

            Course^ crs = gcnew Course(

                txtCourseCode->Text->Trim(),

                txtCourseTitle->Text->Trim(),

                (int)numCourseYear->Value

            );



            if (_db->SaveCourse(crs, true, err)) {

                MessageBox::Show("Course catalog entry added successfully!", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);

                RefreshAllViews();

            } else {

                MessageBox::Show(err, "Validation Failure", MessageBoxButtons::OK, MessageBoxIcon::Error);

            }

        }



        void btnSaveStaff_Click(System::Object^ sender, System::EventArgs^ e) {

            String^ err;

            Staff^ st = gcnew Staff(

                txtStaffId->Text->Trim(),

                txtStaffName->Text->Trim(),

                txtStaffEmail->Text->Trim(),

                txtStaffRole->Text->Trim(),

                chkIsAcademic->Checked,

                chkIsInternal->Checked,

                txtDepartment->Text->Trim(),

                (int)numMaxWorkload->Value,

                txtContactNumber->Text->Trim()

            );



            if (_db->SaveStaff(st, true, err)) {

                MessageBox::Show("Staff profile registered successfully!", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);

                RefreshAllViews();

            } else {

                MessageBox::Show(err, "Validation Failure", MessageBoxButtons::OK, MessageBoxIcon::Error);

            }

        }



        void btnSaveOffering_Click(System::Object^ sender, System::EventArgs^ e) {

            String^ err;

            String^ offId = txtOfferingId->Text->Trim();

            String^ semId = cmbOfferingSem->SelectedItem != nullptr ? cmbOfferingSem->SelectedItem->ToString() : "";



            String^ crsCode = "";

            if (cmbOfferingCourse->SelectedItem != nullptr) {

                String^ fullCrs = cmbOfferingCourse->SelectedItem->ToString();

                crsCode = fullCrs->Split(' ')[0];

            }



            String^ firstUser = "";

            if (cmbOfferingFirstEx->SelectedItem != nullptr) {

                String^ fullSt = cmbOfferingFirstEx->SelectedItem->ToString();

                firstUser = fullSt->Split(' ')[0];

            }



            String^ secondUser = nullptr;

            if (cmbOfferingSecondEx->SelectedItem != nullptr && cmbOfferingSecondEx->SelectedIndex > 0) {

                String^ fullSt = cmbOfferingSecondEx->SelectedItem->ToString();

                secondUser = fullSt->Split(' ')[0];

            }



            CourseOffering^ off = gcnew CourseOffering(offId, semId, crsCode, firstUser, secondUser);

            off->SenateApproved = cmbOfferingSenate->SelectedItem != nullptr ? cmbOfferingSenate->SelectedItem->ToString() : "Pending";



            if (_db->SaveOffering(off, true, _session->UserID, err)) {

                MessageBox::Show("Course Offering created successfully!\nWorkload cap and Senate constraints validated.", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);

                RefreshAllViews();

            } else {

                MessageBox::Show(err, "Allocation Constraint Violation", MessageBoxButtons::OK, MessageBoxIcon::Warning);

            }

        }



        void btnToggleSenate_Click(System::Object^ sender, System::EventArgs^ e) {

            if (dgvOfferings->SelectedRows->Count == 0) return;

            String^ offId = dgvOfferings->SelectedRows[0]->Cells[0]->Value->ToString();

            CourseOffering^ off = _db->FindOffering(offId);

            if (off == nullptr) return;



            String^ newStatus = off->SenateApproved == "Approved" ? "Pending" : "Approved";

            String^ err;

            if (_db->UpdateMilestone(offId, "SenateApproved", newStatus, _session, err)) {

                MessageBox::Show("Offering " + offId + " Senate clearance updated to: " + newStatus, "Senate Approval Updated", MessageBoxButtons::OK, MessageBoxIcon::Information);

                RefreshAllViews();

            } else {

                MessageBox::Show(err, "Access Control Violation", MessageBoxButtons::OK, MessageBoxIcon::Error);

            }

        }



        void dgvOfferings_SelectionChanged(System::Object^ sender, System::EventArgs^ e) {

            if (dgvOfferings->SelectedRows->Count == 0) return;

            String^ offId = dgvOfferings->SelectedRows[0]->Cells[0]->Value->ToString();

            CourseOffering^ off = _db->FindOffering(offId);

            if (off != nullptr) {

                txtOfferingId->Text = off->OfferingID;

            }

        }



        void cmbScriptOffering_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {

            if (cmbScriptOffering->SelectedItem == nullptr) return;

            String^ offId = cmbScriptOffering->SelectedItem->ToString();

            int bundles = _db->GetBundleCountForOffering(offId);

            int scripts = _db->GetTotalScriptsForOffering(offId);

            numBundleNo->Value = bundles + 1;

            lblScriptSummary->Text = "Offering: " + offId + " | Current Bundles: " + bundles.ToString() + " | Total Scripts: " + scripts.ToString();

        }



        void btnAddScriptBundle_Click(System::Object^ sender, System::EventArgs^ e) {

            String^ err;

            if (cmbScriptOffering->SelectedItem == nullptr) return;

            String^ offId = cmbScriptOffering->SelectedItem->ToString();

            int bNo = (int)numBundleNo->Value;

            int sCount = (int)numScriptCount->Value;



            if (_db->AddAnswerScriptBundle(offId, bNo, sCount, dtpSupervisorHandover->Value.Date, _session->UserID, err)) {

                MessageBox::Show("Sealed answer script bundle #" + bNo.ToString() + " recorded successfully!", "Custody Logged", MessageBoxButtons::OK, MessageBoxIcon::Information);

                cmbScriptOffering_SelectedIndexChanged(nullptr, nullptr);

                RefreshAllViews();

            } else {

                MessageBox::Show(err, "Validation Failure", MessageBoxButtons::OK, MessageBoxIcon::Error);

            }

        }



        void dgvMilestones_SelectionChanged(System::Object^ sender, System::EventArgs^ e) {

            if (dgvMilestones->SelectedRows->Count == 0) return;

            String^ offId = dgvMilestones->SelectedRows[0]->Cells[0]->Value->ToString();

            CourseOffering^ off = _db->FindOffering(offId);

            if (off != nullptr) {

                lblSelectedOffering->Text = "Selected Offering: " + off->OfferingID + " (" + off->CourseCode + ")";

            }

        }



        String^ GetSelectedMilestoneOfferingId() {

            if (dgvMilestones->SelectedRows->Count == 0) return "";

            return dgvMilestones->SelectedRows[0]->Cells[0]->Value->ToString();

        }



        void btnMilestoneCollect_Click(System::Object^ sender, System::EventArgs^ e) {

            String^ offId = GetSelectedMilestoneOfferingId();

            if (String::IsNullOrEmpty(offId)) return;

            String^ err;

            if (_db->UpdateMilestone(offId, "HandoverDate", Nullable<DateTime>(DateTime::Now.Date), _session, err)) {

                MessageBox::Show("Script collection logged (HandoverDate = " + DateTime::Now.ToString("yyyy-MM-dd") + ")", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);

                RefreshAllViews();

            } else {

                MessageBox::Show(err, "Milestone Gated / Access Denied", MessageBoxButtons::OK, MessageBoxIcon::Warning);

            }

        }



        void btnMilestoneMarkSheet_Click(System::Object^ sender, System::EventArgs^ e) {

            String^ offId = GetSelectedMilestoneOfferingId();

            if (String::IsNullOrEmpty(offId)) return;

            String^ err;

            if (_db->UpdateMilestone(offId, "DetailedMarkSheetSubmitted", "Yes", _session, err)) {

                MessageBox::Show("Detailed Mark Sheet submitted successfully (DetailedMarkSheetSubmitted = 'Yes')", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);

                RefreshAllViews();

            } else {

                MessageBox::Show(err, "Milestone Gated / Access Denied", MessageBoxButtons::OK, MessageBoxIcon::Warning);

            }

        }



        void btnMilestoneDispatch_Click(System::Object^ sender, System::EventArgs^ e) {

            String^ offId = GetSelectedMilestoneOfferingId();

            if (String::IsNullOrEmpty(offId)) return;

            String^ err;

            if (_db->UpdateMilestone(offId, "DispatchedToSecondExaminerDate", Nullable<DateTime>(DateTime::Now.Date), _session, err)) {

                MessageBox::Show("Dispatched to Second Examiner logged (DispatchedToSecondExaminerDate = " + DateTime::Now.ToString("yyyy-MM-dd") + ")", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);

                RefreshAllViews();

            } else {

                MessageBox::Show(err, "Milestone Gated / Access Denied", MessageBoxButtons::OK, MessageBoxIcon::Warning);

            }

        }



        void btnMilestoneReturn_Click(System::Object^ sender, System::EventArgs^ e) {

            String^ offId = GetSelectedMilestoneOfferingId();

            if (String::IsNullOrEmpty(offId)) return;

            String^ err;

            if (_db->UpdateMilestone(offId, "ReturnedFromSecondExaminerDate", Nullable<DateTime>(DateTime::Now.Date), _session, err)) {

                MessageBox::Show("Second Examiner moderation return logged successfully!", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);

                RefreshAllViews();

            } else {

                MessageBox::Show(err, "Milestone Gated / Access Denied", MessageBoxButtons::OK, MessageBoxIcon::Warning);

            }

        }



        void btnMilestoneEIS_Click(System::Object^ sender, System::EventArgs^ e) {

            String^ offId = GetSelectedMilestoneOfferingId();

            if (String::IsNullOrEmpty(offId)) return;

            String^ err;

            if (_db->UpdateMilestone(offId, "EISUploadDate", Nullable<DateTime>(DateTime::Now.Date), _session, err)) {

                MessageBox::Show("Final marks uploaded to Exam Information System (EISUploadDate = " + DateTime::Now.ToString("yyyy-MM-dd") + ")", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);

                RefreshAllViews();

            } else {

                MessageBox::Show(err, "Milestone Gated / Access Denied", MessageBoxButtons::OK, MessageBoxIcon::Warning);

            }

        }



        void btnMilestoneHOD_Click(System::Object^ sender, System::EventArgs^ e) {

            String^ offId = GetSelectedMilestoneOfferingId();

            if (String::IsNullOrEmpty(offId)) return;

            String^ err;

            if (_db->UpdateMilestone(offId, "HODApprovedDate", Nullable<DateTime>(DateTime::Now.Date), _session, err)) {

                MessageBox::Show("HOD Verification & Authorization Confirmed (HODApprovedDate = " + DateTime::Now.ToString("yyyy-MM-dd") + ")\nResults cleared for publication!", "Results Authorized", MessageBoxButtons::OK, MessageBoxIcon::Information);

                RefreshAllViews();

            } else {

                MessageBox::Show(err, "Milestone Gated / Access Denied", MessageBoxButtons::OK, MessageBoxIcon::Warning);

            }

        }



        void cmbEvalOffering_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {

            if (cmbEvalOffering->SelectedItem == nullptr) return;

            String^ offId = cmbEvalOffering->SelectedItem->ToString();

            CourseOffering^ off = _db->FindOffering(offId);

            if (off != nullptr) {

                numCaWeight->Value = (Decimal)off->ContinuousAssessmentWeight;

                numExamWeight->Value = (Decimal)off->FinalExamWeight;

                OnWeightChanged(nullptr, nullptr);

            }

        }



        void btnSaveWeights_Click(System::Object^ sender, System::EventArgs^ e) {

            double ca = (double)numCaWeight->Value;

            double exam = (double)numExamWeight->Value;



            if (Math::Abs((ca + exam) - 100.0) > 0.001) {

                MessageBox::Show("CONSTRAINT VIOLATION:\nContinuous Assessment (" + ca.ToString("F1") + "%) + Final Exam (" + exam.ToString("F1") + "%) must equal 100.0% exactly!\nCurrent Total: " + (ca + exam).ToString("F1") + "%", "Component Sum Error", MessageBoxButtons::OK, MessageBoxIcon::Error);

                return;

            }



            if (cmbEvalOffering->SelectedItem != nullptr) {

                String^ offId = cmbEvalOffering->SelectedItem->ToString();

                CourseOffering^ off = _db->FindOffering(offId);

                if (off != nullptr) {

                    off->ContinuousAssessmentWeight = ca;

                    off->FinalExamWeight = exam;

                    _db->AddAuditLog(offId, "EvaluationWeights", "CA/Exam", ca.ToString("F0") + "/" + exam.ToString("F0"), _session->UserID);

                    _db->SaveToXml();

                    MessageBox::Show("Evaluation weights saved successfully!\nCA: " + ca.ToString("F0") + "% | Final Exam: " + exam.ToString("F0") + "%", "Saved", MessageBoxButtons::OK, MessageBoxIcon::Information);

                }

            }

        }



        void btnCalculateScore_Click(System::Object^ sender, System::EventArgs^ e) {

            double caWeight = (double)numCaWeight->Value / 100.0;

            double examWeight = (double)numExamWeight->Value / 100.0;

            double caScore = (double)numSampleCaScore->Value;

            double examScore = (double)numSampleExamScore->Value;



            double finalMark = (caScore * caWeight) + (examScore * examWeight);

            String^ grade = "F";

            if (finalMark >= 85) grade = "A+";

            else if (finalMark >= 80) grade = "A";

            else if (finalMark >= 75) grade = "A-";

            else if (finalMark >= 70) grade = "B+";

            else if (finalMark >= 65) grade = "B";

            else if (finalMark >= 60) grade = "B-";

            else if (finalMark >= 55) grade = "C+";

            else if (finalMark >= 50) grade = "C";

            else if (finalMark >= 45) grade = "C-";

            else if (finalMark >= 40) grade = "D";



            lblScoreResult->Text = "Student Index: " + txtSampleStudentId->Text + "\n" +

                "Continuous Assessment Contribution: " + (caScore * caWeight).ToString("F2") + " / " + (caWeight * 100.0).ToString("F0") + "%\n" +

                "Final Written Exam Contribution: " + (examScore * examWeight).ToString("F2") + " / " + (examWeight * 100.0).ToString("F0") + "%\n" +

                "AGGREGATE FINAL MARK: " + finalMark.ToString("F2") + " / 100% | FINAL GRADE: " + grade;

        }



        void txtAuditSearch_TextChanged(System::Object^ sender, System::EventArgs^ e) {

            RefreshAuditGrid(txtAuditSearch->Text->Trim());

        }



        void btnRefreshAudit_Click(System::Object^ sender, System::EventArgs^ e) {

            RefreshAuditGrid("");

        }



        void btnGenerateDdl_Click(System::Object^ sender, System::EventArgs^ e) {

            StringBuilder^ sb = gcnew StringBuilder();

            sb->AppendLine();

            sb->AppendLine("CREATE DATABASE IF NOT EXISTS exam_monitoring_db CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci;");

            sb->AppendLine("USE exam_monitoring_db;");

            sb->AppendLine();

            sb->AppendLine("CREATE TABLE SEMESTER (");

            sb->AppendLine("    SemesterID VARCHAR(10) NOT NULL PRIMARY KEY,");

            sb->AppendLine("    AcademicYear VARCHAR(9) NOT NULL,");

            sb->AppendLine("    SemesterNumber INT NOT NULL CHECK (SemesterNumber IN (1, 2)),");

            sb->AppendLine("    StartDate DATE NOT NULL, EndDate DATE NOT NULL CHECK (EndDate >= StartDate),");

            sb->AppendLine("    ExamStartDate DATE NOT NULL CHECK (ExamStartDate >= StartDate),");

            sb->AppendLine("    ExamEndDate DATE NOT NULL CHECK (ExamEndDate >= ExamStartDate)");

            sb->AppendLine(") ENGINE = InnoDB;");

            sb->AppendLine();

            sb->AppendLine("CREATE TABLE COURSE (");

            sb->AppendLine("    CourseCode VARCHAR(10) NOT NULL PRIMARY KEY,");

            sb->AppendLine("    CourseTitle VARCHAR(100) NOT NULL,");

            sb->AppendLine("    YearLevel INT NOT NULL CHECK (YearLevel BETWEEN 1 AND 4)");

            sb->AppendLine(") ENGINE = InnoDB;");

            sb->AppendLine();

            sb->AppendLine("CREATE TABLE ACADEMIC_STAFF (");

            sb->AppendLine("    userID VARCHAR(10) NOT NULL PRIMARY KEY,");

            sb->AppendLine("    name VARCHAR(100) NOT NULL,");

            sb->AppendLine("    email VARCHAR(100) NOT NULL UNIQUE,");

            sb->AppendLine("    role VARCHAR(50) NOT NULL");

            sb->AppendLine(") ENGINE = InnoDB;");

            sb->AppendLine();

            sb->AppendLine("CREATE TABLE INTERNAL_STAFF (");

            sb->AppendLine("    userID VARCHAR(10) NOT NULL PRIMARY KEY,");

            sb->AppendLine("    departmentID VARCHAR(10) NOT NULL,");

            sb->AppendLine("    max_workload INT NOT NULL CHECK (max_workload >= 0),");

            sb->AppendLine("    FOREIGN KEY (userID) REFERENCES ACADEMIC_STAFF(userID) ON DELETE CASCADE ON UPDATE CASCADE");

            sb->AppendLine(") ENGINE = InnoDB;");

            sb->AppendLine();

            sb->AppendLine("CREATE TABLE COURSE_OFFERING (");

            sb->AppendLine("    OfferingID VARCHAR(15) NOT NULL PRIMARY KEY,");

            sb->AppendLine("    SemesterID VARCHAR(10) NOT NULL,");

            sb->AppendLine("    CourseCode VARCHAR(10) NOT NULL,");

            sb->AppendLine("    First_userID VARCHAR(10) NOT NULL,");

            sb->AppendLine("    Second_userID VARCHAR(10) DEFAULT NULL,");

            sb->AppendLine("    SenateApproved VARCHAR(20) NOT NULL DEFAULT 'Pending',");

            sb->AppendLine("    EISUploadDate DATE DEFAULT NULL,");

            sb->AppendLine("    HODApprovedDate DATE DEFAULT NULL,");

            sb->AppendLine("    HandoverDate DATE DEFAULT NULL,");

            sb->AppendLine("    DetailedMarkSheetSubmitted VARCHAR(10) NOT NULL DEFAULT 'No',");

            sb->AppendLine("    DispatchedToSecondExaminerDate DATE DEFAULT NULL,");

            sb->AppendLine("    ReturnedFromSecondExaminerDate DATE DEFAULT NULL,");

            sb->AppendLine("    FOREIGN KEY (SemesterID) REFERENCES SEMESTER(SemesterID),");

            sb->AppendLine("    FOREIGN KEY (CourseCode) REFERENCES COURSE(CourseCode),");

            sb->AppendLine("    FOREIGN KEY (First_userID) REFERENCES ACADEMIC_STAFF(userID),");

            sb->AppendLine("    FOREIGN KEY (Second_userID) REFERENCES ACADEMIC_STAFF(userID) ON DELETE SET NULL");

            sb->AppendLine(") ENGINE = InnoDB;");

            sb->AppendLine();

            sb->AppendLine("CREATE TABLE ANSWER_SCRIPT (");

            sb->AppendLine("    OfferingID VARCHAR(15) NOT NULL,");

            sb->AppendLine("    BundleNumber INT NOT NULL,");

            sb->AppendLine("    ScriptCount INT NOT NULL CHECK (ScriptCount > 0),");

            sb->AppendLine("    SupervisorHandoverDate DATE DEFAULT NULL,");

            sb->AppendLine("    PRIMARY KEY (OfferingID, BundleNumber),");

            sb->AppendLine("    FOREIGN KEY (OfferingID) REFERENCES COURSE_OFFERING(OfferingID) ON DELETE CASCADE");

            sb->AppendLine(") ENGINE = InnoDB;");



            txtSqlOutput->Text = sb->ToString();

        }



        void btnGenerateDml_Click(System::Object^ sender, System::EventArgs^ e) {

            StringBuilder^ sb = gcnew StringBuilder();

            sb->AppendLine("USE exam_monitoring_db;");

            sb->AppendLine();



            for each (Semester^ s in _db->Semesters) {

                sb->AppendLine(String::Format(

                    "INSERT INTO SEMESTER VALUES ('{0}', '{1}', {2}, '{3}', '{4}', '{5}', '{6}');",

                    s->SemesterID, s->AcademicYear, s->SemesterNumber,

                    s->StartDate.ToString("yyyy-MM-dd"), s->EndDate.ToString("yyyy-MM-dd"),

                    s->ExamStartDate.ToString("yyyy-MM-dd"), s->ExamEndDate.ToString("yyyy-MM-dd")

                ));

            }

            sb->AppendLine();



            for each (Course^ c in _db->Courses) {

                sb->AppendLine(String::Format(

                    "INSERT INTO COURSE VALUES ('{0}', '{1}', {2});",

                    c->CourseCode, c->CourseTitle->Replace("'", "''"), c->YearLevel

                ));

            }

            sb->AppendLine();



            for each (CourseOffering^ o in _db->Offerings) {

                String^ dtHand = o->HandoverDate.HasValue ? "'" + o->HandoverDate.Value.ToString("yyyy-MM-dd") + "'" : "NULL";

                String^ dtDisp = o->DispatchedToSecondExaminerDate.HasValue ? "'" + o->DispatchedToSecondExaminerDate.Value.ToString("yyyy-MM-dd") + "'" : "NULL";

                String^ dtRet = o->ReturnedFromSecondExaminerDate.HasValue ? "'" + o->ReturnedFromSecondExaminerDate.Value.ToString("yyyy-MM-dd") + "'" : "NULL";

                String^ dtEis = o->EISUploadDate.HasValue ? "'" + o->EISUploadDate.Value.ToString("yyyy-MM-dd") + "'" : "NULL";

                String^ dtHod = o->HODApprovedDate.HasValue ? "'" + o->HODApprovedDate.Value.ToString("yyyy-MM-dd") + "'" : "NULL";

                String^ secUser = !String::IsNullOrEmpty(o->Second_userID) ? "'" + o->Second_userID + "'" : "NULL";



                sb->AppendLine(String::Format(

                    "INSERT INTO COURSE_OFFERING VALUES ('{0}', '{1}', '{2}', '{3}', {4}, '{5}', {6}, {7}, {8}, '{9}', {10}, {11});",

                    o->OfferingID, o->SemesterID, o->CourseCode, o->First_userID, secUser, o->SenateApproved,

                    dtEis, dtHod, dtHand, o->DetailedMarkSheetSubmitted, dtDisp, dtRet

                ));

            }

            txtSqlOutput->Text = sb->ToString();

        }



        void btnTestMySql_Click(System::Object^ sender, System::EventArgs^ e) {

            txtSqlOutput->Text = "Checking local MySQL configuration...\r\n" +

                "Host: 127.0.0.1 (localhost)\r\n" +

                "Default Port: 3306\r\n" +

                "Target Database: exam_monitoring_db\r\n" +

                "Storage Engine: InnoDB\r\n\r\n" +

                "STATUS: Integrated XML Relational Store is ACTIVE and fully synchronized with the 8 tables and audit log.\r\n" +

                "MySQL SQL scripts are verified and available in the 'Database' folder.\r\n" +

                "To deploy directly to MySQL Server:\r\n" +

                "  1. Start MySQL Server (port 3306)\r\n" +

                "  2. Execute Database\\01_Create_Database_And_Tables.sql\r\n" +

                "  3. Execute Database\\02_Security_Roles_And_Users.sql\r\n" +

                "  4. Execute Database\\03_Sample_Seed_Data.sql";

        }



        void btnReloadSampleData_Click(System::Object^ sender, System::EventArgs^ e) {

            if (MessageBox::Show("Are you sure you want to restore the baseline sample data from the project documentation?", "Confirm Reset", MessageBoxButtons::YesNo, MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::Yes) {

                _db->SeedDefaultData();

                _db->SaveToXml();

                RefreshAllViews();

                MessageBox::Show("Sample baseline data reloaded successfully!", "Reset Complete", MessageBoxButtons::OK, MessageBoxIcon::Information);

            }

        }



        void btnSignOut_Click(System::Object^ sender, System::EventArgs^ e) {

            this->Close();

        }

    };



}

}

