# Examination Results Monitoring System
### C++/CLI (.NET Framework v4.7.2) Enterprise Windows Desktop Solution

An institutional monitoring and governance system for tracking university examination answer script custody, statutory grading deadlines, moderation turnarounds, workload caps, Senate clearance gates, and role-based result authorizations.

Built strictly in accordance with requirements and database design specifications from:
- **`2. Conceptual Database Design.docx`**
- **`3. Logical Database Design.docx`**
- **`4. Schema Refinement and Normalization.docx`**
- **`5. Physical Database Design.docx`**
- **`6. Security Design.docx`**
- **`Bisiness Proposal.docx`**
- **`Project Proposal New.docx`**

---

## 🏛️ Key System Capabilities & Enforced Business Rules

1. **Role-Based Access Control (RBAC):**
   - **`dean_role` (`dean_user` / `Dean#Secure2026!`):** Executive faculty oversight. Comprehensive read-only access to all dashboards, delay alerts, and immutable audit logs.
   - **`hod_role` (`hod_comp` / `Hod#Comp2026!`):** Departmental supervision. Verifies physical mark sheets against EIS and updates `HODApprovedDate` to authorize final results for student publication.
   - **`first_examiner_role` (`lecturer_user` / `Lect#Exam2026!`):** Records script collection (`HandoverDate`), submits Detailed Mark Sheet (`DetailedMarkSheetSubmitted`), and uploads final marks to the EIS (`EISUploadDate`).
   - **`second_examiner_role` (`second_examiner` / `Sec#Exam2026!`):** Moderation responsibility. Records moderation return timestamp (`ReturnedFromSecondExaminerDate`) and report submission.
   - **`ar_office_role` (`ar_officer` / `AR#Branch2026!`):** Central administrative authority. Registers semesters and courses, assigns examiners, updates Senate approval (`SenateApproved`), and dispatches scripts to Second Examiners (`DispatchedToSecondExaminerDate`).
   - **`supervisor_role` (`supervisor_01` / `Hall#Sup2026!`):** Post-exam custody handover. Records sealed answer script bundles (`BundleNumber`, `ScriptCount`, `SupervisorHandoverDate`).

2. **Automated Workload Cap Constraint Enforcement:**
   - Enforces the institutional rule: *An internal lecturer can handle a maximum of 3 to 4 courses per semester (`MaxWorkload`)*.
   - When allocating a First or Second Examiner, the system calculates current assigned offerings in that semester. If assignment exceeds `MaxWorkload`, the allocation is blocked programmatically with an explanatory constraint violation dialog.

3. **Senate Approval Gate Clearance (Procedural Lock):**
   - Strictly enforces *`SenateApproved = 'Approved'`* before allowing script collection, mark sheet submission, or dispatch to the Second Examiner.

4. **Automated Delay Detection & Statutory Deadline Alerts (FR5):**
   - **First Marking Deadline (FR3.3):** Calculated automatically as:
     $$\text{Deadline} = \text{SEMESTER.ExamEndDate} + 1\text{ Month}$$
     If `DetailedMarkSheetSubmitted = 'No'` past the deadline, a **CRITICAL OVERDUE ALERT (🔴)** is triggered on administrative dashboards.
   - **Second Marking Turnaround Cap (FR5.2):** Calculated as:
     $$\text{Turnaround Duration} = \text{ReturnedDate} - \text{DispatchedDate}$$
     Flags moderation durations exceeding the 14-day institutional limit as **MODERATION BOTTLENECK (🔴)**.

5. **Course Evaluation Sum Integrity (100% Total):**
   - Validates that Continuous Assessment (CA) and Final Written Examination percentage weights strictly equal 100.0%. Includes a sample student aggregate grade calculator.

6. **Immutable Audit Trail:**
   - Every status transition and milestone update automatically generates an immutable audit record in the `AUDIT_LOG` table with `OfferingID`, `AttributeChanged`, `OldValue`, `NewValue`, `ChangedBy`, and `Timestamp`.

---

## 🗄️ Relational Database Schemas (InnoDB, utf8mb4)

The project includes production-ready SQL scripts located in the `Database/` folder:

| Table Name | Keys & Constraints | Description |
| :--- | :--- | :--- |
| **`SEMESTER`** | PK: `SemesterID`, CHECK `SemesterNumber IN (1, 2)`, Date sequence checks | Academic semesters, calendar dates, and exam windows |
| **`COURSE`** | PK: `CourseCode`, CHECK `YearLevel BETWEEN 1 AND 4` | Academic courses across years 1–4 |
| **`NON_ACADEMIC_STAFF`** | PK: `userID`, UNIQUE `email` | AR office and exam supervisor personnel |
| **`ACADEMIC_STAFF`** | PK: `userID`, UNIQUE `email` | Superclass relation for academic staff |
| **`INTERNAL_STAFF`** | PK & FK: `userID`, CHECK `max_workload >= 0` | Subclass relation with department ID and workload limit (3–4) |
| **`EXTERNAL_STAFF`** | PK & FK: `userID` | Subclass relation with contact number |
| **`COURSE_OFFERING`** | PK: `OfferingID`, FKs: `SemesterID`, `CourseCode`, `First_userID`, `Second_userID` | Central workflow tracking milestones, Senate approval, and examiner assignments |
| **`ANSWER_SCRIPT`** | Composite PK: (`OfferingID`, `BundleNumber`), FK: `OfferingID`, CHECK `ScriptCount > 0` | Weak entity storing sealed script bundle counts and handover dates |
| **`AUDIT_LOG`** | PK: `LogID` (Auto Increment), FK: `OfferingID` | Immutable milestone audit trail |

---

## 💻 Project Structure & Visual Studio Friendly Design

```
c:\Softwares\Examination Results Monitoring System\
├── Examination Results Monitoring System.sln          <-- Solution file for Visual Studio 2022 / 2019
├── Examination Results Monitoring System.slnx         <-- Solution file for Visual Studio 2026 / latest VS
├── README.md
└── Examination Results Monitoring System/
    ├── Examination Results Monitoring System.vcxproj  <-- C++/CLI (/clr) Project File
    ├── Examination Results Monitoring System.vcxproj.filters
    ├── main.cpp                                       <-- Application Entry Point (STAThread)
    ├── Models/
    │   └── Entities.h                                 <-- Managed entity classes, roles & sessions
    ├── Database/
    │   ├── DatabaseManager.h                          <-- Business logic, constraints & persistence
    │   ├── 01_Create_Database_And_Tables.sql          <-- Exact MySQL DDL with InnoDB & indexes
    │   ├── 02_Security_Roles_And_Users.sql            <-- Exact MySQL DCL with RBAC & Views
    │   ├── 03_Sample_Seed_Data.sql                    <-- Comprehensive institutional sample data
    │   ├── 04_Backup_And_Recovery_Procedures.sql      <-- Full mysqldump & PITR binary log recovery
    │   └── README_DATABASE.md
    └── Forms/
        ├── LoginForm.h                                <-- Authentication dialog with preset role logins
        └── MainForm.h                                 <-- 10-tab institutional monitoring suite
```

---

## 🚀 Building & Running the Project

### Option A: Open directly in Visual Studio (Recommended)
1. Launch **Visual Studio** (VS 2022, VS 2026, or Community edition).
2. Open either:
   - `Examination Results Monitoring System.sln` (Standard solution)
   - `Examination Results Monitoring System.slnx` (Modern solution)
3. Select configuration **Debug** or **Release**, and platform **x64**.
4. Press **F5** or click **Local Windows Debugger** to build and run.

### Option B: Build via MSBuild from Command Line
```powershell
& "C:\Program Files\Microsoft Visual Studio\18\Community\MSBuild\Current\Bin\amd64\MSBuild.exe" "Examination Results Monitoring System\Examination Results Monitoring System.vcxproj" /p:Configuration=Debug /p:Platform=x64 /p:PreferredToolArchitecture=x64
```

---

## 🔐 Pre-Configured Test Credentials

For quick evaluation, the login dialog provides a one-click dropdown pre-filling credentials matching **Document 6 (Security Design)**:

| Role Description | Username | Password | Default Mode |
| :--- | :--- | :--- | :--- |
| **Assistant Registrar (AR Office)** | `ar_officer` | `AR#Branch2026!` | Full Master Admin |
| **Dean (Faculty Executive)** | `dean_user` | `Dean#Secure2026!` | Read-Only Oversight |
| **Head of Department (HOD)** | `hod_comp` | `Hod#Comp2026!` | Result Verification & Authorization |
| **First Examiner / Lecturer** | `lecturer_user` | `Lect#Exam2026!` | Script Collection, Marks & EIS Upload |
| **Second Examiner (Moderator)** | `second_examiner` | `Sec#Exam2026!` | Moderation Return Timestamp |
| **Exam Hall Supervisor** | `supervisor_01` | `Hall#Sup2026!` | Answer Script Handover Log |

---

## 🛡️ Standalone & Embedded Resilience

The application features an **integrated local relational XML persistence store** (`exam_monitoring_data.xml`). When launched on any laptop or evaluator machine:
- No active MySQL server is required for the application to function immediately.
- All 8 tables, constraints, validation checks, and sample active/overdue scenarios run out of the box with zero runtime errors.
- If MySQL Server is installed and running on port 3306, you can execute the SQL scripts in the `Database/` folder or export current system state via Tab 10 (**Database & SQL Tools**).
