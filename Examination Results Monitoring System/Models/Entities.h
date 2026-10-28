#pragma once



using namespace System;

using namespace System::Collections::Generic;



namespace ExaminationResultsMonitoringSystem {

namespace Models {



    public ref class Roles {

    public:

        literal String^ Dean = "dean_role";

        literal String^ HOD = "hod_role";

        literal String^ FirstExaminer = "first_examiner_role";

        literal String^ SecondExaminer = "second_examiner_role";

        literal String^ AROffice = "ar_office_role";

        literal String^ Supervisor = "supervisor_role";



        static String^ GetDisplayName(String^ role) {

            if (role == Dean) return "Dean (Executive Oversight)";

            if (role == HOD) return "Head of Department (HOD)";

            if (role == FirstExaminer) return "First Examiner / Lecturer";

            if (role == SecondExaminer) return "Second Examiner (Moderator)";

            if (role == AROffice) return "AR Office / Exam Branch";

            if (role == Supervisor) return "Exam Hall Supervisor";

            return role;

        }

    };



    public ref class UserSession {

    public:

        property String^ UserID;

        property String^ Name;

        property String^ Email;

        property String^ Role;

        property String^ DepartmentID;



        UserSession(String^ userId, String^ name, String^ email, String^ role, String^ dept) {

            UserID = userId;

            Name = name;

            Email = email;

            Role = role;

            DepartmentID = dept;

        }



        bool IsDean() { return Role == Roles::Dean; }

        bool IsHOD() { return Role == Roles::HOD; }

        bool IsFirstExaminer() { return Role == Roles::FirstExaminer; }

        bool IsSecondExaminer() { return Role == Roles::SecondExaminer; }

        bool IsAROffice() { return Role == Roles::AROffice; }

        bool IsSupervisor() { return Role == Roles::Supervisor; }



        bool CanManageSemesters() { return IsAROffice(); }

        bool CanManageCourses() { return IsAROffice(); }

        bool CanManageStaff() { return IsAROffice(); }

        bool CanManageOfferings() { return IsAROffice(); }

        bool CanApproveSenate() { return IsAROffice(); }

        bool CanDispatchToSecond() { return IsAROffice(); }

        bool CanHandoverScripts() { return IsSupervisor() || IsAROffice(); }

        bool CanCollectScripts() { return IsFirstExaminer() || IsAROffice(); }

        bool CanSubmitMarksheet() { return IsFirstExaminer() || IsAROffice(); }

        bool CanUploadEIS() { return IsFirstExaminer() || IsAROffice(); }

        bool CanReturnSecondMarking() { return IsSecondExaminer() || IsAROffice(); }

        bool CanApproveHOD() { return IsHOD() || IsAROffice(); }

        bool CanViewAuditLog() { return IsDean() || IsHOD() || IsAROffice(); }

    };



    public ref class Semester {

    public:

        property String^ SemesterID;

        property String^ AcademicYear;

        property int SemesterNumber;

        property DateTime StartDate;

        property DateTime EndDate;

        property DateTime ExamStartDate;

        property DateTime ExamEndDate;



        Semester() {

            SemesterNumber = 1;

            StartDate = DateTime::Now.Date;

            EndDate = DateTime::Now.Date.AddMonths(4);

            ExamStartDate = EndDate.AddDays(-20);

            ExamEndDate = EndDate;

        }



        Semester(String^ id, String^ year, int num, DateTime start, DateTime end, DateTime examStart, DateTime examEnd) {

            SemesterID = id;

            AcademicYear = year;

            SemesterNumber = num;

            StartDate = start;

            EndDate = end;

            ExamStartDate = examStart;

            ExamEndDate = examEnd;

        }



        DateTime GetFirstMarkingDeadline() {

            return ExamEndDate.AddMonths(1);

        }

    };



    public ref class Course {

    public:

        property String^ CourseCode;

        property String^ CourseTitle;

        property int YearLevel;



        Course() { YearLevel = 1; }

        Course(String^ code, String^ title, int level) {

            CourseCode = code;

            CourseTitle = title;

            YearLevel = level;

        }

    };



    public ref class Staff {

    public:

        property String^ UserID;

        property String^ Name;

        property String^ Email;

        property String^ Role;

        property bool IsAcademic;

        property bool IsInternal;

        property String^ DepartmentID;

        property int MaxWorkload;

        property String^ ContactNumber;



        Staff() {

            IsAcademic = true;

            IsInternal = true;

            MaxWorkload = 4;

            DepartmentID = "DEPT_CS";

            ContactNumber = "";

        }



        Staff(String^ id, String^ name, String^ email, String^ role, bool isAcademic, bool isInternal, String^ dept, int maxWorkload, String^ contact) {

            UserID = id;

            Name = name;

            Email = email;

            Role = role;

            IsAcademic = isAcademic;

            IsInternal = isInternal;

            DepartmentID = dept;

            MaxWorkload = maxWorkload;

            ContactNumber = contact;

        }

    };



    public ref class AnswerScript {

    public:

        property String^ OfferingID;

        property int BundleNumber;

        property int ScriptCount;

        property Nullable<DateTime> SupervisorHandoverDate;



        AnswerScript() {

            BundleNumber = 1;

            ScriptCount = 50;

        }



        AnswerScript(String^ offeringId, int bundleNum, int count, Nullable<DateTime> handover) {

            OfferingID = offeringId;

            BundleNumber = bundleNum;

            ScriptCount = count;

            SupervisorHandoverDate = handover;

        }

    };



    public ref class CourseOffering {

    public:

        property String^ OfferingID;

        property String^ SemesterID;

        property String^ CourseCode;

        property String^ First_userID;

        property String^ Second_userID;

        property String^ SenateApproved;

        property Nullable<DateTime> EISUploadDate;

        property Nullable<DateTime> HODApprovedDate;

        property Nullable<DateTime> HandoverDate;

        property String^ DetailedMarkSheetSubmitted;

        property Nullable<DateTime> DispatchedToSecondExaminerDate;

        property Nullable<DateTime> ReturnedFromSecondExaminerDate;



        property double ContinuousAssessmentWeight;

        property double FinalExamWeight;



        CourseOffering() {

            SenateApproved = "Pending";

            DetailedMarkSheetSubmitted = "No";

            ContinuousAssessmentWeight = 40.0;

            FinalExamWeight = 60.0;

        }



        CourseOffering(String^ offeringId, String^ semId, String^ courseCode, String^ firstUser, String^ secondUser) {

            OfferingID = offeringId;

            SemesterID = semId;

            CourseCode = courseCode;

            First_userID = firstUser;

            Second_userID = secondUser;

            SenateApproved = "Pending";

            DetailedMarkSheetSubmitted = "No";

            ContinuousAssessmentWeight = 40.0;

            FinalExamWeight = 60.0;

        }



        int GetModerationDurationDays() {

            if (!DispatchedToSecondExaminerDate.HasValue) return 0;

            DateTime end = ReturnedFromSecondExaminerDate.HasValue ? ReturnedFromSecondExaminerDate.Value : DateTime::Now.Date;

            TimeSpan span = end - DispatchedToSecondExaminerDate.Value;

            return Math::Max(0, (int)span.TotalDays);

        }



        bool IsModerationOverdue() {

            if (!DispatchedToSecondExaminerDate.HasValue) return false;



            if (ReturnedFromSecondExaminerDate.HasValue) {

                return (ReturnedFromSecondExaminerDate.Value - DispatchedToSecondExaminerDate.Value).TotalDays > 14;

            }



            return (DateTime::Now.Date - DispatchedToSecondExaminerDate.Value).TotalDays > 14;

        }



        bool IsFirstMarkingOverdue(DateTime examEndDate) {

            if (DetailedMarkSheetSubmitted == "Yes") return false;

            DateTime deadline = examEndDate.AddMonths(1);

            return DateTime::Now.Date > deadline;

        }



        String^ GetOverallStatus() {

            if (HODApprovedDate.HasValue) return "Completed & Authorized";

            if (EISUploadDate.HasValue) return "Awaiting HOD Authorization";

            if (ReturnedFromSecondExaminerDate.HasValue) return "Moderation Complete (EIS Upload Pending)";

            if (DispatchedToSecondExaminerDate.HasValue) {

                return IsModerationOverdue() ? "OVERDUE: Moderation Delay (>14 Days)" : "Under Second Marking (Moderation)";

            }

            if (DetailedMarkSheetSubmitted == "Yes") return "Mark Sheet Submitted (Dispatch Pending)";

            if (HandoverDate.HasValue) return "First Marking in Progress";

            if (SenateApproved == "Approved") return "Senate Approved (Awaiting Script Collection)";

            if (SenateApproved == "Rejected") return "Senate Rejected";

            return "Pending Senate Approval (Gated)";

        }

    };



    public ref class AuditEntry {

    public:

        property int LogID;

        property String^ OfferingID;

        property String^ AttributeChanged;

        property String^ OldValue;

        property String^ NewValue;

        property String^ ChangedBy;

        property DateTime ChangeTimestamp;



        AuditEntry() {

            ChangeTimestamp = DateTime::Now;

        }



        AuditEntry(int id, String^ offeringId, String^ attr, String^ oldVal, String^ newVal, String^ changedBy, DateTime ts) {

            LogID = id;

            OfferingID = offeringId;

            AttributeChanged = attr;

            OldValue = oldVal;

            NewValue = newVal;

            ChangedBy = changedBy;

            ChangeTimestamp = ts;

        }

    };



}

}

