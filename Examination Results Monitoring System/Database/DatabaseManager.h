#pragma once



#include "..\Models\Entities.h"



using namespace System;

using namespace System::IO;

using namespace System::Collections::Generic;

using namespace System::Xml::Serialization;

using namespace ExaminationResultsMonitoringSystem::Models;



namespace ExaminationResultsMonitoringSystem {

namespace Database {



    public ref class DatabaseManager {

    private:

        static DatabaseManager^ _instance = nullptr;

        String^ _dataFilePath;

        int _nextAuditId;



    public:



        List<Semester^>^ Semesters;

        List<Course^>^ Courses;

        List<Staff^>^ StaffMembers;

        List<CourseOffering^>^ Offerings;

        List<AnswerScript^>^ AnswerScripts;

        List<AuditEntry^>^ AuditLogs;



        static DatabaseManager^ GetInstance() {

            if (_instance == nullptr) {

                _instance = gcnew DatabaseManager();

            }

            return _instance;

        }



        DatabaseManager() {

            Semesters = gcnew List<Semester^>();

            Courses = gcnew List<Course^>();

            StaffMembers = gcnew List<Staff^>();

            Offerings = gcnew List<CourseOffering^>();

            AnswerScripts = gcnew List<AnswerScript^>();

            AuditLogs = gcnew List<AuditEntry^>();

            _nextAuditId = 1;



            _dataFilePath = Path::Combine(AppDomain::CurrentDomain->BaseDirectory, "exam_monitoring_data.xml");



            if (File::Exists(_dataFilePath)) {

                try {

                    LoadFromXml();

                } catch (Exception^) {

                    SeedDefaultData();

                    SaveToXml();

                }

            } else {

                SeedDefaultData();

                SaveToXml();

            }

        }



        void SeedDefaultData() {

            Semesters->Clear();

            Courses->Clear();

            StaffMembers->Clear();

            Offerings->Clear();

            AnswerScripts->Clear();

            AuditLogs->Clear();



            Semesters->Add(gcnew Semester("SEM2025_S2", "2024/2025", 2,

                DateTime(2025, 6, 1), DateTime(2025, 10, 31),

                DateTime(2025, 10, 1), DateTime(2025, 10, 20)));



            Semesters->Add(gcnew Semester("SEM2026_S1", "2025/2026", 1,

                DateTime(2026, 1, 15), DateTime(2026, 5, 30),

                DateTime(2026, 5, 2), DateTime(2026, 5, 22)));



            Semesters->Add(gcnew Semester("SEM2026_S2", "2025/2026", 2,

                DateTime(2026, 6, 15), DateTime(2026, 11, 15),

                DateTime(2026, 10, 15), DateTime(2026, 11, 5)));



            Courses->Add(gcnew Course("ICT1101", "Fundamentals of Computing and Programming", 1));

            Courses->Add(gcnew Course("ICT1407", "Database Management Systems", 1));

            Courses->Add(gcnew Course("ICT2102", "Data Structures and Algorithms", 2));

            Courses->Add(gcnew Course("ICT2203", "Object Oriented Programming with C++", 2));

            Courses->Add(gcnew Course("ICT3103", "Operating Systems and System Programming", 3));

            Courses->Add(gcnew Course("ICT3204", "Software Engineering and Quality Assurance", 3));

            Courses->Add(gcnew Course("ICT4104", "Distributed Systems and Cloud Computing", 4));

            Courses->Add(gcnew Course("ICT4205", "Machine Learning and Predictive Analytics", 4));



            StaffMembers->Add(gcnew Staff("NAS001", "Mrs. K. A. Perera", "kperera.ar@univ.ac.lk", "Assistant Registrar", false, false, "EXAM_BRANCH", 0, ""));

            StaffMembers->Add(gcnew Staff("NAS002", "Mr. D. N. Silva", "dsilva.exam@univ.ac.lk", "Senior Assistant Registrar", false, false, "EXAM_BRANCH", 0, ""));

            StaffMembers->Add(gcnew Staff("NAS003", "Mr. S. M. Fernando", "sfernando.sup@univ.ac.lk", "Exam Hall Supervisor", false, false, "EXAM_BRANCH", 0, ""));



            StaffMembers->Add(gcnew Staff("STF001", "Prof. A. C. Jayawardena", "cjayawardena@univ.ac.lk", "Dean / Senior Professor", true, true, "DEPT_CS", 3, ""));

            StaffMembers->Add(gcnew Staff("STF002", "Dr. M. S. Wickramasinghe", "mwickrama@univ.ac.lk", "HOD / Senior Lecturer", true, true, "DEPT_CS", 4, ""));

            StaffMembers->Add(gcnew Staff("STF003", "Dr. N. L. Bandara", "nbandara@univ.ac.lk", "Senior Lecturer Gr. I", true, true, "DEPT_CS", 4, ""));

            StaffMembers->Add(gcnew Staff("STF004", "Mr. K. T. Rathnayake", "krathnayake@univ.ac.lk", "Lecturer (Unconfirmed)", true, true, "DEPT_IT", 3, ""));

            StaffMembers->Add(gcnew Staff("STF005", "Mrs. P. H. Gunawardana", "pgunawardana@univ.ac.lk", "Lecturer", true, true, "DEPT_IT", 4, ""));



            StaffMembers->Add(gcnew Staff("EXT001", "Prof. R. M. Dissanayake", "rdissanayake@external.ac.lk", "Visiting Professor", true, false, "EXTERNAL", 0, "+94712345678"));

            StaffMembers->Add(gcnew Staff("EXT002", "Dr. H. K. Samarasekara", "hsamarasekara@external.ac.lk", "External Examiner", true, false, "EXTERNAL", 0, "+94778901234"));



            CourseOffering^ off1 = gcnew CourseOffering("OFF2025_ICT1101", "SEM2025_S2", "ICT1101", "STF003", "EXT001");

            off1->SenateApproved = "Approved";

            off1->HandoverDate = DateTime(2025, 10, 22);

            off1->DetailedMarkSheetSubmitted = "Yes";

            off1->DispatchedToSecondExaminerDate = DateTime(2025, 11, 5);

            off1->ReturnedFromSecondExaminerDate = DateTime(2025, 11, 15);

            off1->EISUploadDate = DateTime(2025, 11, 20);

            off1->HODApprovedDate = DateTime(2025, 11, 25);

            Offerings->Add(off1);



            CourseOffering^ off2 = gcnew CourseOffering("OFF2026_ICT1407", "SEM2026_S1", "ICT1407", "STF004", "STF003");

            off2->SenateApproved = "Approved";

            off2->HandoverDate = DateTime(2026, 5, 24);

            off2->DetailedMarkSheetSubmitted = "Yes";

            off2->DispatchedToSecondExaminerDate = DateTime(2026, 6, 2);

            Offerings->Add(off2);



            CourseOffering^ off3 = gcnew CourseOffering("OFF2026_ICT2102", "SEM2026_S1", "ICT2102", "STF005", "EXT002");

            off3->SenateApproved = "Approved";

            off3->HandoverDate = DateTime(2026, 5, 23);

            off3->DetailedMarkSheetSubmitted = "Yes";

            off3->DispatchedToSecondExaminerDate = DateTime(2026, 5, 28);

            Offerings->Add(off3);



            CourseOffering^ off4 = gcnew CourseOffering("OFF2026_ICT2203", "SEM2026_S1", "ICT2203", "STF003", "STF002");

            off4->SenateApproved = "Approved";

            off4->HandoverDate = DateTime(2026, 5, 25);

            off4->DetailedMarkSheetSubmitted = "No";

            Offerings->Add(off4);



            CourseOffering^ off5 = gcnew CourseOffering("OFF2026_ICT3103", "SEM2026_S1", "ICT3103", "STF002", "EXT001");

            off5->SenateApproved = "Pending";

            Offerings->Add(off5);



            AnswerScripts->Add(gcnew AnswerScript("OFF2025_ICT1101", 1, 60, DateTime(2025, 10, 21)));

            AnswerScripts->Add(gcnew AnswerScript("OFF2025_ICT1101", 2, 58, DateTime(2025, 10, 21)));

            AnswerScripts->Add(gcnew AnswerScript("OFF2026_ICT1407", 1, 75, DateTime(2026, 5, 23)));

            AnswerScripts->Add(gcnew AnswerScript("OFF2026_ICT1407", 2, 70, DateTime(2026, 5, 23)));

            AnswerScripts->Add(gcnew AnswerScript("OFF2026_ICT2102", 1, 65, DateTime(2026, 5, 23)));

            AnswerScripts->Add(gcnew AnswerScript("OFF2026_ICT2203", 1, 80, DateTime(2026, 5, 24)));

            AnswerScripts->Add(gcnew AnswerScript("OFF2026_ICT3103", 1, 55, DateTime(2026, 5, 25)));



            AuditLogs->Add(gcnew AuditEntry(_nextAuditId++, "OFF2026_ICT1407", "SenateApproved", "Pending", "Approved", "ar_officer", DateTime(2026, 5, 10, 9, 30, 0)));

            AuditLogs->Add(gcnew AuditEntry(_nextAuditId++, "OFF2026_ICT1407", "HandoverDate", "NULL", "2026-05-24", "lecturer_user", DateTime(2026, 5, 24, 14, 15, 0)));

            AuditLogs->Add(gcnew AuditEntry(_nextAuditId++, "OFF2026_ICT1407", "DetailedMarkSheetSubmitted", "No", "Yes", "lecturer_user", DateTime(2026, 6, 1, 16, 45, 0)));

            AuditLogs->Add(gcnew AuditEntry(_nextAuditId++, "OFF2026_ICT1407", "DispatchedToSecondExaminerDate", "NULL", "2026-06-02", "ar_officer", DateTime(2026, 6, 2, 11, 0, 0)));

        }



        int GetStaffActiveWorkload(String^ staffId, String^ semesterId, String^ excludeOfferingId) {

            int count = 0;

            for each (CourseOffering^ off in Offerings) {

                if (off->SemesterID == semesterId) {

                    if (!String::IsNullOrEmpty(excludeOfferingId) && off->OfferingID == excludeOfferingId) {

                        continue;

                    }

                    if (off->First_userID == staffId || off->Second_userID == staffId) {

                        count++;

                    }

                }

            }

            return count;

        }



        Staff^ FindStaff(String^ staffId) {

            for each (Staff^ s in StaffMembers) {

                if (s->UserID == staffId) return s;

            }

            return nullptr;

        }



        Semester^ FindSemester(String^ semesterId) {

            for each (Semester^ sem in Semesters) {

                if (sem->SemesterID == semesterId) return sem;

            }

            return nullptr;

        }



        Course^ FindCourse(String^ courseCode) {

            for each (Course^ c in Courses) {

                if (c->CourseCode == courseCode) return c;

            }

            return nullptr;

        }



        CourseOffering^ FindOffering(String^ offeringId) {

            for each (CourseOffering^ o in Offerings) {

                if (o->OfferingID == offeringId) return o;

            }

            return nullptr;

        }



        bool ValidateStaffWorkload(String^ staffId, String^ semesterId, String^ excludeOfferingId, String^% outError) {

            Staff^ staff = FindStaff(staffId);

            if (staff == nullptr) {

                outError = "Staff member '" + staffId + "' does not exist.";

                return false;

            }



            if (staff->IsAcademic && staff->IsInternal) {

                int currentCount = GetStaffActiveWorkload(staffId, semesterId, excludeOfferingId);

                if (currentCount >= staff->MaxWorkload) {

                    outError = "WORKLOAD CONSTRAINT VIOLATION:\n" +

                        "Lecturer " + staff->Name + " (" + staff->UserID + ") is currently assigned to " +

                        currentCount.ToString() + " courses in " + semesterId + ".\n" +

                        "Institutional MaxWorkload cap is " + staff->MaxWorkload.ToString() + " courses per semester.\n" +

                        "Assignment is blocked according to Faculty Regulations.";

                    return false;

                }

            }

            return true;

        }



        bool ValidateSemesterDates(DateTime start, DateTime end, DateTime examStart, DateTime examEnd, String^% outError) {

            if (end < start) {

                outError = "Validation Error: Semester EndDate must be on or after StartDate.";

                return false;

            }

            if (examEnd < examStart) {

                outError = "Validation Error: Exam EndDate must be on or after Exam StartDate.";

                return false;

            }

            if (examStart < start) {

                outError = "Validation Error: Examination period cannot begin before the semester start date.";

                return false;

            }

            if (examEnd > end) {

                outError = "Validation Error: Examination period cannot end after the semester end date.";

                return false;

            }

            return true;

        }



        bool SaveSemester(Semester^ sem, bool isNew, String^% outError) {

            if (String::IsNullOrWhiteSpace(sem->SemesterID)) {

                outError = "Semester ID cannot be empty.";

                return false;

            }

            if (sem->SemesterNumber != 1 && sem->SemesterNumber != 2) {

                outError = "Semester number must be 1 or 2.";

                return false;

            }

            if (!ValidateSemesterDates(sem->StartDate, sem->EndDate, sem->ExamStartDate, sem->ExamEndDate, outError)) {

                return false;

            }



            Semester^ existing = FindSemester(sem->SemesterID);

            if (isNew) {

                if (existing != nullptr) {

                    outError = "Semester ID '" + sem->SemesterID + "' already exists.";

                    return false;

                }

                Semesters->Add(sem);

            } else {

                if (existing == nullptr) {

                    outError = "Semester not found.";

                    return false;

                }

                existing->AcademicYear = sem->AcademicYear;

                existing->SemesterNumber = sem->SemesterNumber;

                existing->StartDate = sem->StartDate;

                existing->EndDate = sem->EndDate;

                existing->ExamStartDate = sem->ExamStartDate;

                existing->ExamEndDate = sem->ExamEndDate;

            }

            SaveToXml();

            return true;

        }



        bool SaveCourse(Course^ course, bool isNew, String^% outError) {

            if (String::IsNullOrWhiteSpace(course->CourseCode)) {

                outError = "Course Code cannot be empty.";

                return false;

            }

            if (String::IsNullOrWhiteSpace(course->CourseTitle)) {

                outError = "Course Title cannot be empty.";

                return false;

            }

            if (course->YearLevel < 1 || course->YearLevel > 4) {

                outError = "Year Level must be between 1 and 4.";

                return false;

            }



            Course^ existing = FindCourse(course->CourseCode);

            if (isNew) {

                if (existing != nullptr) {

                    outError = "Course Code '" + course->CourseCode + "' already exists.";

                    return false;

                }

                Courses->Add(course);

            } else {

                if (existing == nullptr) {

                    outError = "Course not found.";

                    return false;

                }

                existing->CourseTitle = course->CourseTitle;

                existing->YearLevel = course->YearLevel;

            }

            SaveToXml();

            return true;

        }



        bool SaveStaff(Staff^ staff, bool isNew, String^% outError) {

            if (String::IsNullOrWhiteSpace(staff->UserID)) {

                outError = "Staff UserID cannot be empty.";

                return false;

            }

            if (String::IsNullOrWhiteSpace(staff->Name)) {

                outError = "Staff Name cannot be empty.";

                return false;

            }

            if (String::IsNullOrWhiteSpace(staff->Email)) {

                outError = "Staff Email cannot be empty.";

                return false;

            }



            Staff^ existing = FindStaff(staff->UserID);

            if (isNew) {

                if (existing != nullptr) {

                    outError = "Staff ID '" + staff->UserID + "' already exists.";

                    return false;

                }

                StaffMembers->Add(staff);

            } else {

                if (existing == nullptr) {

                    outError = "Staff not found.";

                    return false;

                }

                existing->Name = staff->Name;

                existing->Email = staff->Email;

                existing->Role = staff->Role;

                existing->IsAcademic = staff->IsAcademic;

                existing->IsInternal = staff->IsInternal;

                existing->DepartmentID = staff->DepartmentID;

                existing->MaxWorkload = staff->MaxWorkload;

                existing->ContactNumber = staff->ContactNumber;

            }

            SaveToXml();

            return true;

        }



        bool SaveOffering(CourseOffering^ off, bool isNew, String^ changedBy, String^% outError) {

            if (String::IsNullOrWhiteSpace(off->OfferingID)) {

                outError = "Offering ID cannot be empty.";

                return false;

            }

            if (FindSemester(off->SemesterID) == nullptr) {

                outError = "Referenced Semester '" + off->SemesterID + "' does not exist.";

                return false;

            }

            if (FindCourse(off->CourseCode) == nullptr) {

                outError = "Referenced Course '" + off->CourseCode + "' does not exist.";

                return false;

            }

            if (String::IsNullOrWhiteSpace(off->First_userID) || FindStaff(off->First_userID) == nullptr) {

                outError = "First Examiner must be a valid academic staff member.";

                return false;

            }

            if (!String::IsNullOrEmpty(off->Second_userID) && off->First_userID == off->Second_userID) {

                outError = "First Examiner and Second Examiner must be distinct staff members.";

                return false;

            }



            if (!ValidateStaffWorkload(off->First_userID, off->SemesterID, isNew ? "" : off->OfferingID, outError)) {

                return false;

            }



            if (!String::IsNullOrEmpty(off->Second_userID)) {

                if (!ValidateStaffWorkload(off->Second_userID, off->SemesterID, isNew ? "" : off->OfferingID, outError)) {

                    return false;

                }

            }



            CourseOffering^ existing = FindOffering(off->OfferingID);

            if (isNew) {

                if (existing != nullptr) {

                    outError = "Offering ID '" + off->OfferingID + "' already exists.";

                    return false;

                }

                Offerings->Add(off);

                AddAuditLog(off->OfferingID, "Creation", "NONE", "Created offering " + off->OfferingID, changedBy);

            } else {

                if (existing == nullptr) {

                    outError = "Offering not found.";

                    return false;

                }



                if (existing->First_userID != off->First_userID) {

                    AddAuditLog(off->OfferingID, "First_userID", existing->First_userID, off->First_userID, changedBy);

                    existing->First_userID = off->First_userID;

                }

                if (existing->Second_userID != off->Second_userID) {

                    AddAuditLog(off->OfferingID, "Second_userID", existing->Second_userID, off->Second_userID, changedBy);

                    existing->Second_userID = off->Second_userID;

                }

                existing->SemesterID = off->SemesterID;

                existing->CourseCode = off->CourseCode;

            }

            SaveToXml();

            return true;

        }



        bool AddAnswerScriptBundle(String^ offeringId, int bundleNum, int scriptCount, Nullable<DateTime> handover, String^ changedBy, String^% outError) {

            if (FindOffering(offeringId) == nullptr) {

                outError = "Offering '" + offeringId + "' does not exist.";

                return false;

            }

            if (bundleNum <= 0) {

                outError = "Bundle Number must be greater than zero.";

                return false;

            }

            if (scriptCount <= 0) {

                outError = "Script Count must be greater than zero (chk_script_count violation).";

                return false;

            }



            for each (AnswerScript^ script in AnswerScripts) {

                if (script->OfferingID == offeringId && script->BundleNumber == bundleNum) {

                    outError = "Bundle #" + bundleNum.ToString() + " for offering '" + offeringId + "' already exists.";

                    return false;

                }

            }



            AnswerScripts->Add(gcnew AnswerScript(offeringId, bundleNum, scriptCount, handover));

            AddAuditLog(offeringId, "AnswerScriptBundle", "NONE", "Added Bundle #" + bundleNum.ToString() + " (" + scriptCount.ToString() + " scripts)", changedBy);

            SaveToXml();

            return true;

        }



        bool UpdateMilestone(String^ offeringId, String^ milestoneName, Object^ newValue, UserSession^ user, String^% outError) {

            CourseOffering^ off = FindOffering(offeringId);

            if (off == nullptr) {

                outError = "Offering not found.";

                return false;

            }



            if (milestoneName != "SenateApproved" && off->SenateApproved != "Approved") {

                outError = "PROCEDURAL GATE VIOLATION:\n" +

                    "Course Offering '" + offeringId + "' is currently '" + off->SenateApproved + "'.\n" +

                    "Grading milestones and second-marking dispatch remain LOCKED until formal Senate clearance (SenateApproved = 'Approved') is confirmed.";

                return false;

            }



            if (milestoneName == "SenateApproved") {

                if (!user->CanApproveSenate()) {

                    outError = "SECURITY VIOLATION: Only AR Office / Exam Branch personnel can update Senate approval status.";

                    return false;

                }

                String^ oldVal = off->SenateApproved;

                off->SenateApproved = (String^)newValue;

                AddAuditLog(offeringId, "SenateApproved", oldVal, off->SenateApproved, user->UserID);

            }

            else if (milestoneName == "HandoverDate") {

                if (!user->CanCollectScripts()) {

                    outError = "SECURITY VIOLATION: Only the First Examiner (or AR Office) can log script collection.";

                    return false;

                }

                String^ oldVal = off->HandoverDate.HasValue ? off->HandoverDate.Value.ToString("yyyy-MM-dd") : "NULL";

                off->HandoverDate = (Nullable<DateTime>)newValue;

                AddAuditLog(offeringId, "HandoverDate", oldVal, off->HandoverDate.Value.ToString("yyyy-MM-dd"), user->UserID);

            }

            else if (milestoneName == "DetailedMarkSheetSubmitted") {

                if (!user->CanSubmitMarksheet()) {

                    outError = "SECURITY VIOLATION: Only the First Examiner (or AR Office) can submit the Detailed Mark Sheet.";

                    return false;

                }

                String^ oldVal = off->DetailedMarkSheetSubmitted;

                off->DetailedMarkSheetSubmitted = (String^)newValue;

                AddAuditLog(offeringId, "DetailedMarkSheetSubmitted", oldVal, off->DetailedMarkSheetSubmitted, user->UserID);

            }

            else if (milestoneName == "DispatchedToSecondExaminerDate") {

                if (!user->CanDispatchToSecond()) {

                    outError = "SECURITY VIOLATION: Only AR Office can log dispatch to the Second Examiner.";

                    return false;

                }

                if (off->DetailedMarkSheetSubmitted != "Yes") {

                    outError = "WORKFLOW ERROR: Cannot dispatch scripts to Second Examiner before Detailed Mark Sheet is submitted by the First Examiner.";

                    return false;

                }

                String^ oldVal = off->DispatchedToSecondExaminerDate.HasValue ? off->DispatchedToSecondExaminerDate.Value.ToString("yyyy-MM-dd") : "NULL";

                off->DispatchedToSecondExaminerDate = (Nullable<DateTime>)newValue;

                AddAuditLog(offeringId, "DispatchedToSecondExaminerDate", oldVal, off->DispatchedToSecondExaminerDate.Value.ToString("yyyy-MM-dd"), user->UserID);

            }

            else if (milestoneName == "ReturnedFromSecondExaminerDate") {

                if (!user->CanReturnSecondMarking()) {

                    outError = "SECURITY VIOLATION: Only the Second Examiner (or AR Office) can record moderation return.";

                    return false;

                }

                if (!off->DispatchedToSecondExaminerDate.HasValue) {

                    outError = "WORKFLOW ERROR: Cannot return scripts before they have been dispatched to the Second Examiner.";

                    return false;

                }

                Nullable<DateTime> returnDate = (Nullable<DateTime>)newValue;

                if (returnDate.HasValue && returnDate.Value < off->DispatchedToSecondExaminerDate.Value) {

                    outError = "CHRONOLOGICAL CONSTRAINT VIOLATION:\nReturnedFromSecondExaminerDate cannot be earlier than DispatchedToSecondExaminerDate.";

                    return false;

                }

                String^ oldVal = off->ReturnedFromSecondExaminerDate.HasValue ? off->ReturnedFromSecondExaminerDate.Value.ToString("yyyy-MM-dd") : "NULL";

                off->ReturnedFromSecondExaminerDate = returnDate;

                AddAuditLog(offeringId, "ReturnedFromSecondExaminerDate", oldVal, off->ReturnedFromSecondExaminerDate.Value.ToString("yyyy-MM-dd"), user->UserID);

            }

            else if (milestoneName == "EISUploadDate") {

                if (!user->CanUploadEIS()) {

                    outError = "SECURITY VIOLATION: Only the First Examiner (or AR Office) can record mark upload to the EIS.";

                    return false;

                }

                if (off->DetailedMarkSheetSubmitted != "Yes") {

                    outError = "WORKFLOW ERROR: Final marks cannot be uploaded to the EIS before Detailed Mark Sheet is completed.";

                    return false;

                }

                String^ oldVal = off->EISUploadDate.HasValue ? off->EISUploadDate.Value.ToString("yyyy-MM-dd") : "NULL";

                off->EISUploadDate = (Nullable<DateTime>)newValue;

                AddAuditLog(offeringId, "EISUploadDate", oldVal, off->EISUploadDate.Value.ToString("yyyy-MM-dd"), user->UserID);

            }

            else if (milestoneName == "HODApprovedDate") {

                if (!user->CanApproveHOD()) {

                    outError = "SECURITY VIOLATION: Only the Head of Department (HOD) can authorize final results.";

                    return false;

                }

                if (!off->EISUploadDate.HasValue) {

                    outError = "WORKFLOW ERROR: HOD authorization cannot take place before marks are uploaded to the EIS.";

                    return false;

                }

                Nullable<DateTime> hodDate = (Nullable<DateTime>)newValue;

                if (hodDate.HasValue && hodDate.Value < off->EISUploadDate.Value) {

                    outError = "CHRONOLOGICAL CONSTRAINT VIOLATION:\nHODApprovedDate cannot be earlier than EISUploadDate.";

                    return false;

                }

                String^ oldVal = off->HODApprovedDate.HasValue ? off->HODApprovedDate.Value.ToString("yyyy-MM-dd") : "NULL";

                off->HODApprovedDate = hodDate;

                AddAuditLog(offeringId, "HODApprovedDate", oldVal, off->HODApprovedDate.Value.ToString("yyyy-MM-dd"), user->UserID);

            }

            else {

                outError = "Unknown milestone: " + milestoneName;

                return false;

            }



            SaveToXml();

            return true;

        }



        void AddAuditLog(String^ offeringId, String^ attributeChanged, String^ oldValue, String^ newValue, String^ changedBy) {

            AuditLogs->Add(gcnew AuditEntry(_nextAuditId++, offeringId, attributeChanged, oldValue, newValue, changedBy, DateTime::Now));

        }



        int GetTotalScriptsForOffering(String^ offeringId) {

            int total = 0;

            for each (AnswerScript^ script in AnswerScripts) {

                if (script->OfferingID == offeringId) {

                    total += script->ScriptCount;

                }

            }

            return total;

        }



        int GetBundleCountForOffering(String^ offeringId) {

            int count = 0;

            for each (AnswerScript^ script in AnswerScripts) {

                if (script->OfferingID == offeringId) {

                    count++;

                }

            }

            return count;

        }



        List<CourseOffering^>^ GetOfferingsBySemester(String^ semesterId) {

            List<CourseOffering^>^ list = gcnew List<CourseOffering^>();

            for each (CourseOffering^ o in Offerings) {

                if (String::IsNullOrEmpty(semesterId) || o->SemesterID == semesterId) {

                    list->Add(o);

                }

            }

            return list;

        }



        void SaveToXml() {

            try {

                using namespace System::Xml;

                XmlDocument^ doc = gcnew XmlDocument();

                XmlElement^ root = doc->CreateElement("ExaminationMonitoringDatabase");

                doc->AppendChild(root);



                XmlElement^ semNode = doc->CreateElement("Semesters");

                root->AppendChild(semNode);

                for each (Semester^ s in Semesters) {

                    XmlElement^ el = doc->CreateElement("Semester");

                    el->SetAttribute("SemesterID", s->SemesterID);

                    el->SetAttribute("AcademicYear", s->AcademicYear);

                    el->SetAttribute("SemesterNumber", s->SemesterNumber.ToString());

                    el->SetAttribute("StartDate", s->StartDate.ToString("yyyy-MM-dd"));

                    el->SetAttribute("EndDate", s->EndDate.ToString("yyyy-MM-dd"));

                    el->SetAttribute("ExamStartDate", s->ExamStartDate.ToString("yyyy-MM-dd"));

                    el->SetAttribute("ExamEndDate", s->ExamEndDate.ToString("yyyy-MM-dd"));

                    semNode->AppendChild(el);

                }



                XmlElement^ crsNode = doc->CreateElement("Courses");

                root->AppendChild(crsNode);

                for each (Course^ c in Courses) {

                    XmlElement^ el = doc->CreateElement("Course");

                    el->SetAttribute("CourseCode", c->CourseCode);

                    el->SetAttribute("CourseTitle", c->CourseTitle);

                    el->SetAttribute("YearLevel", c->YearLevel.ToString());

                    crsNode->AppendChild(el);

                }



                XmlElement^ stfNode = doc->CreateElement("StaffMembers");

                root->AppendChild(stfNode);

                for each (Staff^ st in StaffMembers) {

                    XmlElement^ el = doc->CreateElement("Staff");

                    el->SetAttribute("UserID", st->UserID);

                    el->SetAttribute("Name", st->Name);

                    el->SetAttribute("Email", st->Email);

                    el->SetAttribute("Role", st->Role);

                    el->SetAttribute("IsAcademic", st->IsAcademic.ToString());

                    el->SetAttribute("IsInternal", st->IsInternal.ToString());

                    el->SetAttribute("DepartmentID", st->DepartmentID);

                    el->SetAttribute("MaxWorkload", st->MaxWorkload.ToString());

                    el->SetAttribute("ContactNumber", st->ContactNumber);

                    stfNode->AppendChild(el);

                }



                XmlElement^ offNode = doc->CreateElement("Offerings");

                root->AppendChild(offNode);

                for each (CourseOffering^ o in Offerings) {

                    XmlElement^ el = doc->CreateElement("Offering");

                    el->SetAttribute("OfferingID", o->OfferingID);

                    el->SetAttribute("SemesterID", o->SemesterID);

                    el->SetAttribute("CourseCode", o->CourseCode);

                    el->SetAttribute("First_userID", o->First_userID);

                    el->SetAttribute("Second_userID", o->Second_userID != nullptr ? o->Second_userID : "");

                    el->SetAttribute("SenateApproved", o->SenateApproved);

                    el->SetAttribute("DetailedMarkSheetSubmitted", o->DetailedMarkSheetSubmitted);

                    el->SetAttribute("HandoverDate", o->HandoverDate.HasValue ? o->HandoverDate.Value.ToString("yyyy-MM-dd") : "");

                    el->SetAttribute("DispatchedToSecondExaminerDate", o->DispatchedToSecondExaminerDate.HasValue ? o->DispatchedToSecondExaminerDate.Value.ToString("yyyy-MM-dd") : "");

                    el->SetAttribute("ReturnedFromSecondExaminerDate", o->ReturnedFromSecondExaminerDate.HasValue ? o->ReturnedFromSecondExaminerDate.Value.ToString("yyyy-MM-dd") : "");

                    el->SetAttribute("EISUploadDate", o->EISUploadDate.HasValue ? o->EISUploadDate.Value.ToString("yyyy-MM-dd") : "");

                    el->SetAttribute("HODApprovedDate", o->HODApprovedDate.HasValue ? o->HODApprovedDate.Value.ToString("yyyy-MM-dd") : "");

                    el->SetAttribute("ContinuousAssessmentWeight", o->ContinuousAssessmentWeight.ToString());

                    el->SetAttribute("FinalExamWeight", o->FinalExamWeight.ToString());

                    offNode->AppendChild(el);

                }



                XmlElement^ scrNode = doc->CreateElement("AnswerScripts");

                root->AppendChild(scrNode);

                for each (AnswerScript^ a in AnswerScripts) {

                    XmlElement^ el = doc->CreateElement("Script");

                    el->SetAttribute("OfferingID", a->OfferingID);

                    el->SetAttribute("BundleNumber", a->BundleNumber.ToString());

                    el->SetAttribute("ScriptCount", a->ScriptCount.ToString());

                    el->SetAttribute("SupervisorHandoverDate", a->SupervisorHandoverDate.HasValue ? a->SupervisorHandoverDate.Value.ToString("yyyy-MM-dd") : "");

                    scrNode->AppendChild(el);

                }



                XmlElement^ audNode = doc->CreateElement("AuditLogs");

                root->AppendChild(audNode);

                for each (AuditEntry^ ae in AuditLogs) {

                    XmlElement^ el = doc->CreateElement("AuditEntry");

                    el->SetAttribute("LogID", ae->LogID.ToString());

                    el->SetAttribute("OfferingID", ae->OfferingID);

                    el->SetAttribute("AttributeChanged", ae->AttributeChanged);

                    el->SetAttribute("OldValue", ae->OldValue);

                    el->SetAttribute("NewValue", ae->NewValue);

                    el->SetAttribute("ChangedBy", ae->ChangedBy);

                    el->SetAttribute("ChangeTimestamp", ae->ChangeTimestamp.ToString("o"));

                    audNode->AppendChild(el);

                }



                doc->Save(_dataFilePath);

            } catch (Exception^) {



            }

        }



        void LoadFromXml() {

            using namespace System::Xml;

            XmlDocument^ doc = gcnew XmlDocument();

            doc->Load(_dataFilePath);



            Semesters->Clear();

            Courses->Clear();

            StaffMembers->Clear();

            Offerings->Clear();

            AnswerScripts->Clear();

            AuditLogs->Clear();



            XmlNodeList^ semList = doc->SelectNodes("//Semesters/Semester");

            for each (XmlNode^ n in semList) {

                XmlElement^ el = (XmlElement^)n;

                Semesters->Add(gcnew Semester(

                    el->GetAttribute("SemesterID"),

                    el->GetAttribute("AcademicYear"),

                    Int32::Parse(el->GetAttribute("SemesterNumber")),

                    DateTime::Parse(el->GetAttribute("StartDate")),

                    DateTime::Parse(el->GetAttribute("EndDate")),

                    DateTime::Parse(el->GetAttribute("ExamStartDate")),

                    DateTime::Parse(el->GetAttribute("ExamEndDate"))

                ));

            }



            XmlNodeList^ crsList = doc->SelectNodes("//Courses/Course");

            for each (XmlNode^ n in crsList) {

                XmlElement^ el = (XmlElement^)n;

                Courses->Add(gcnew Course(

                    el->GetAttribute("CourseCode"),

                    el->GetAttribute("CourseTitle"),

                    Int32::Parse(el->GetAttribute("YearLevel"))

                ));

            }



            XmlNodeList^ stfList = doc->SelectNodes("//StaffMembers/Staff");

            for each (XmlNode^ n in stfList) {

                XmlElement^ el = (XmlElement^)n;

                StaffMembers->Add(gcnew Staff(

                    el->GetAttribute("UserID"),

                    el->GetAttribute("Name"),

                    el->GetAttribute("Email"),

                    el->GetAttribute("Role"),

                    Boolean::Parse(el->GetAttribute("IsAcademic")),

                    Boolean::Parse(el->GetAttribute("IsInternal")),

                    el->GetAttribute("DepartmentID"),

                    Int32::Parse(el->GetAttribute("MaxWorkload")),

                    el->GetAttribute("ContactNumber")

                ));

            }



            XmlNodeList^ offList = doc->SelectNodes("//Offerings/Offering");

            for each (XmlNode^ n in offList) {

                XmlElement^ el = (XmlElement^)n;

                CourseOffering^ o = gcnew CourseOffering(

                    el->GetAttribute("OfferingID"),

                    el->GetAttribute("SemesterID"),

                    el->GetAttribute("CourseCode"),

                    el->GetAttribute("First_userID"),

                    el->GetAttribute("Second_userID")

                );

                o->SenateApproved = el->GetAttribute("SenateApproved");

                o->DetailedMarkSheetSubmitted = el->GetAttribute("DetailedMarkSheetSubmitted");



                String^ dtHand = el->GetAttribute("HandoverDate");

                if (!String::IsNullOrEmpty(dtHand)) o->HandoverDate = DateTime::Parse(dtHand);



                String^ dtDisp = el->GetAttribute("DispatchedToSecondExaminerDate");

                if (!String::IsNullOrEmpty(dtDisp)) o->DispatchedToSecondExaminerDate = DateTime::Parse(dtDisp);



                String^ dtRet = el->GetAttribute("ReturnedFromSecondExaminerDate");

                if (!String::IsNullOrEmpty(dtRet)) o->ReturnedFromSecondExaminerDate = DateTime::Parse(dtRet);



                String^ dtEis = el->GetAttribute("EISUploadDate");

                if (!String::IsNullOrEmpty(dtEis)) o->EISUploadDate = DateTime::Parse(dtEis);



                String^ dtHod = el->GetAttribute("HODApprovedDate");

                if (!String::IsNullOrEmpty(dtHod)) o->HODApprovedDate = DateTime::Parse(dtHod);



                String^ caW = el->GetAttribute("ContinuousAssessmentWeight");

                if (!String::IsNullOrEmpty(caW)) o->ContinuousAssessmentWeight = Double::Parse(caW);



                String^ feW = el->GetAttribute("FinalExamWeight");

                if (!String::IsNullOrEmpty(feW)) o->FinalExamWeight = Double::Parse(feW);



                Offerings->Add(o);

            }



            XmlNodeList^ scrList = doc->SelectNodes("//AnswerScripts/Script");

            for each (XmlNode^ n in scrList) {

                XmlElement^ el = (XmlElement^)n;

                Nullable<DateTime> hDate;

                String^ dtH = el->GetAttribute("SupervisorHandoverDate");

                if (!String::IsNullOrEmpty(dtH)) hDate = DateTime::Parse(dtH);



                AnswerScripts->Add(gcnew AnswerScript(

                    el->GetAttribute("OfferingID"),

                    Int32::Parse(el->GetAttribute("BundleNumber")),

                    Int32::Parse(el->GetAttribute("ScriptCount")),

                    hDate

                ));

            }



            XmlNodeList^ audList = doc->SelectNodes("//AuditLogs/AuditEntry");

            for each (XmlNode^ n in audList) {

                XmlElement^ el = (XmlElement^)n;

                int id = Int32::Parse(el->GetAttribute("LogID"));

                if (id >= _nextAuditId) _nextAuditId = id + 1;

                AuditLogs->Add(gcnew AuditEntry(

                    id,

                    el->GetAttribute("OfferingID"),

                    el->GetAttribute("AttributeChanged"),

                    el->GetAttribute("OldValue"),

                    el->GetAttribute("NewValue"),

                    el->GetAttribute("ChangedBy"),

                    DateTime::Parse(el->GetAttribute("ChangeTimestamp"))

                ));

            }

        }

    };



}

}

