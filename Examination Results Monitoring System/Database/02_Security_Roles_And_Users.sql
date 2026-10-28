USE exam_monitoring_db;



CREATE ROLE IF NOT EXISTS 'dean_role';

CREATE ROLE IF NOT EXISTS 'hod_role';

CREATE ROLE IF NOT EXISTS 'first_examiner_role';

CREATE ROLE IF NOT EXISTS 'second_examiner_role';

CREATE ROLE IF NOT EXISTS 'ar_office_role';

CREATE ROLE IF NOT EXISTS 'supervisor_role';



GRANT SELECT ON exam_monitoring_db.* TO 'dean_role';



GRANT SELECT ON exam_monitoring_db.* TO 'hod_role';

GRANT UPDATE (HODApprovedDate) ON exam_monitoring_db.COURSE_OFFERING TO 'hod_role';



GRANT SELECT ON exam_monitoring_db.SEMESTER TO 'first_examiner_role';

GRANT SELECT ON exam_monitoring_db.COURSE TO 'first_examiner_role';

GRANT SELECT ON exam_monitoring_db.ANSWER_SCRIPT TO 'first_examiner_role';

GRANT SELECT, UPDATE (HandoverDate, DetailedMarkSheetSubmitted, EISUploadDate)

    ON exam_monitoring_db.COURSE_OFFERING TO 'first_examiner_role';



GRANT SELECT ON exam_monitoring_db.COURSE_OFFERING TO 'second_examiner_role';

GRANT SELECT ON exam_monitoring_db.ANSWER_SCRIPT TO 'second_examiner_role';

GRANT UPDATE (ReturnedFromSecondExaminerDate)

    ON exam_monitoring_db.COURSE_OFFERING TO 'second_examiner_role';



GRANT SELECT, INSERT, UPDATE ON exam_monitoring_db.SEMESTER TO 'ar_office_role';

GRANT SELECT, INSERT, UPDATE ON exam_monitoring_db.COURSE TO 'ar_office_role';

GRANT SELECT, INSERT, UPDATE ON exam_monitoring_db.ACADEMIC_STAFF TO 'ar_office_role';

GRANT SELECT, INSERT, UPDATE ON exam_monitoring_db.NON_ACADEMIC_STAFF TO 'ar_office_role';

GRANT SELECT, INSERT, UPDATE ON exam_monitoring_db.INTERNAL_STAFF TO 'ar_office_role';

GRANT SELECT, INSERT, UPDATE ON exam_monitoring_db.EXTERNAL_STAFF TO 'ar_office_role';

GRANT SELECT, INSERT, UPDATE ON exam_monitoring_db.COURSE_OFFERING TO 'ar_office_role';

GRANT SELECT, INSERT, UPDATE ON exam_monitoring_db.ANSWER_SCRIPT TO 'ar_office_role';

GRANT SELECT ON exam_monitoring_db.AUDIT_LOG TO 'ar_office_role';



GRANT SELECT ON exam_monitoring_db.COURSE_OFFERING TO 'supervisor_role';

GRANT SELECT, INSERT ON exam_monitoring_db.ANSWER_SCRIPT TO 'supervisor_role';



CREATE OR REPLACE VIEW View_Examiner_Approved_Offerings AS

SELECT

    OfferingID, SemesterID, CourseCode, First_userID,

    HandoverDate, DetailedMarkSheetSubmitted, EISUploadDate, SenateApproved

FROM COURSE_OFFERING

WHERE SenateApproved = 'Approved'

WITH CHECK OPTION;



GRANT SELECT, UPDATE (HandoverDate, DetailedMarkSheetSubmitted, EISUploadDate)

    ON exam_monitoring_db.View_Examiner_Approved_Offerings TO 'first_examiner_role';



CREATE USER IF NOT EXISTS 'dean_user'@'localhost' IDENTIFIED BY 'Dean#Secure2026!';

GRANT 'dean_role' TO 'dean_user'@'localhost';

SET DEFAULT ROLE 'dean_role' TO 'dean_user'@'localhost';



CREATE USER IF NOT EXISTS 'hod_comp'@'localhost' IDENTIFIED BY 'Hod#Comp2026!';

GRANT 'hod_role' TO 'hod_comp'@'localhost';

SET DEFAULT ROLE 'hod_role' TO 'hod_comp'@'localhost';



CREATE USER IF NOT EXISTS 'lecturer_user'@'localhost' IDENTIFIED BY 'Lect#Exam2026!';

GRANT 'first_examiner_role' TO 'lecturer_user'@'localhost';

SET DEFAULT ROLE 'first_examiner_role' TO 'lecturer_user'@'localhost';



CREATE USER IF NOT EXISTS 'second_examiner'@'localhost' IDENTIFIED BY 'Sec#Exam2026!';

GRANT 'second_examiner_role' TO 'second_examiner'@'localhost';

SET DEFAULT ROLE 'second_examiner_role' TO 'second_examiner'@'localhost';



CREATE USER IF NOT EXISTS 'ar_officer'@'localhost' IDENTIFIED BY 'AR#Branch2026!';

GRANT 'ar_office_role' TO 'ar_officer'@'localhost';

SET DEFAULT ROLE 'ar_office_role' TO 'ar_officer'@'localhost';



CREATE USER IF NOT EXISTS 'supervisor_01'@'localhost' IDENTIFIED BY 'Hall#Sup2026!';

GRANT 'supervisor_role' TO 'supervisor_01'@'localhost';

SET DEFAULT ROLE 'supervisor_role' TO 'supervisor_01'@'localhost';



FLUSH PRIVILEGES;

