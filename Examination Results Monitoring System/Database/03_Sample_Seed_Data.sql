USE exam_monitoring_db;



INSERT INTO SEMESTER (SemesterID, AcademicYear, SemesterNumber, StartDate, EndDate, ExamStartDate, ExamEndDate) VALUES

('SEM2025_S2', '2024/2025', 2, '2025-06-01', '2025-10-31', '2025-10-01', '2025-10-20'),

('SEM2026_S1', '2025/2026', 1, '2026-01-15', '2026-05-30', '2026-05-02', '2026-05-22'),

('SEM2026_S2', '2025/2026', 2, '2026-06-15', '2026-11-15', '2026-10-15', '2026-11-05');



INSERT INTO COURSE (CourseCode, CourseTitle, YearLevel) VALUES

('ICT1101', 'Fundamentals of Computing and Programming', 1),

('ICT1407', 'Database Management Systems', 1),

('ICT2102', 'Data Structures and Algorithms', 2),

('ICT2203', 'Object Oriented Programming with C++', 2),

('ICT3103', 'Operating Systems and System Programming', 3),

('ICT3204', 'Software Engineering and Quality Assurance', 3),

('ICT4104', 'Distributed Systems and Cloud Computing', 4),

('ICT4205', 'Machine Learning and Predictive Analytics', 4);



INSERT INTO NON_ACADEMIC_STAFF (userID, name, email, role) VALUES

('NAS001', 'Mrs. K. A. Perera', 'kperera.ar@univ.ac.lk', 'Assistant Registrar'),

('NAS002', 'Mr. D. N. Silva', 'dsilva.exam@univ.ac.lk', 'Senior Assistant Registrar'),

('NAS003', 'Mr. S. M. Fernando', 'sfernando.sup@univ.ac.lk', 'Exam Hall Supervisor');



INSERT INTO ACADEMIC_STAFF (userID, name, email, role) VALUES

('STF001', 'Prof. A. C. Jayawardena', 'cjayawardena@univ.ac.lk', 'Dean / Senior Professor'),

('STF002', 'Dr. M. S. Wickramasinghe', 'mwickrama@univ.ac.lk', 'HOD / Senior Lecturer'),

('STF003', 'Dr. N. L. Bandara', 'nbandara@univ.ac.lk', 'Senior Lecturer Gr. I'),

('STF004', 'Mr. K. T. Rathnayake', 'krathnayake@univ.ac.lk', 'Lecturer (Unconfirmed)'),

('STF005', 'Mrs. P. H. Gunawardana', 'pgunawardana@univ.ac.lk', 'Lecturer'),

('EXT001', 'Prof. R. M. Dissanayake', 'rdissanayake@external.ac.lk', 'Visiting Professor'),

('EXT002', 'Dr. H. K. Samarasekara', 'hsamarasekara@external.ac.lk', 'External Examiner');



INSERT INTO INTERNAL_STAFF (userID, departmentID, max_workload) VALUES

('STF001', 'DEPT_CS', 3),

('STF002', 'DEPT_CS', 4),

('STF003', 'DEPT_CS', 4),

('STF004', 'DEPT_IT', 3),

('STF005', 'DEPT_IT', 4);



INSERT INTO EXTERNAL_STAFF (userID, ContactNumber) VALUES

('EXT001', '+94712345678'),

('EXT002', '+94778901234');



INSERT INTO COURSE_OFFERING (OfferingID, SemesterID, CourseCode, First_userID, Second_userID, SenateApproved, EISUploadDate, HODApprovedDate, HandoverDate, DetailedMarkSheetSubmitted, DispatchedToSecondExaminerDate, ReturnedFromSecondExaminerDate) VALUES

('OFF2025_ICT1101', 'SEM2025_S2', 'ICT1101', 'STF003', 'EXT001', 'Approved', '2025-11-20', '2025-11-25', '2025-10-22', 'Yes', '2025-11-05', '2025-11-15');



INSERT INTO COURSE_OFFERING (OfferingID, SemesterID, CourseCode, First_userID, Second_userID, SenateApproved, EISUploadDate, HODApprovedDate, HandoverDate, DetailedMarkSheetSubmitted, DispatchedToSecondExaminerDate, ReturnedFromSecondExaminerDate) VALUES

('OFF2026_ICT1407', 'SEM2026_S1', 'ICT1407', 'STF004', 'STF003', 'Approved', NULL, NULL, '2026-05-24', 'Yes', '2026-06-02', NULL);



INSERT INTO COURSE_OFFERING (OfferingID, SemesterID, CourseCode, First_userID, Second_userID, SenateApproved, EISUploadDate, HODApprovedDate, HandoverDate, DetailedMarkSheetSubmitted, DispatchedToSecondExaminerDate, ReturnedFromSecondExaminerDate) VALUES

('OFF2026_ICT2102', 'SEM2026_S1', 'ICT2102', 'STF005', 'EXT002', 'Approved', NULL, NULL, '2026-05-23', 'Yes', '2026-05-28', NULL);



INSERT INTO COURSE_OFFERING (OfferingID, SemesterID, CourseCode, First_userID, Second_userID, SenateApproved, EISUploadDate, HODApprovedDate, HandoverDate, DetailedMarkSheetSubmitted, DispatchedToSecondExaminerDate, ReturnedFromSecondExaminerDate) VALUES

('OFF2026_ICT2203', 'SEM2026_S1', 'ICT2203', 'STF003', 'STF002', 'Approved', NULL, NULL, '2026-05-25', 'No', NULL, NULL);



INSERT INTO COURSE_OFFERING (OfferingID, SemesterID, CourseCode, First_userID, Second_userID, SenateApproved, EISUploadDate, HODApprovedDate, HandoverDate, DetailedMarkSheetSubmitted, DispatchedToSecondExaminerDate, ReturnedFromSecondExaminerDate) VALUES

('OFF2026_ICT3103', 'SEM2026_S1', 'ICT3103', 'STF002', 'EXT001', 'Pending', NULL, NULL, NULL, 'No', NULL, NULL);



INSERT INTO ANSWER_SCRIPT (OfferingID, BundleNumber, ScriptCount, SupervisorHandoverDate) VALUES

('OFF2025_ICT1101', 1, 60, '2025-10-21'),

('OFF2025_ICT1101', 2, 58, '2025-10-21'),

('OFF2026_ICT1407', 1, 75, '2026-05-23'),

('OFF2026_ICT1407', 2, 70, '2026-05-23'),

('OFF2026_ICT2102', 1, 65, '2026-05-23'),

('OFF2026_ICT2203', 1, 80, '2026-05-24'),

('OFF2026_ICT3103', 1, 55, '2026-05-25');



INSERT INTO AUDIT_LOG (OfferingID, AttributeChanged, OldValue, NewValue, ChangedBy, ChangeTimestamp) VALUES

('OFF2026_ICT1407', 'SenateApproved', 'Pending', 'Approved', 'ar_officer', '2026-05-10 09:30:00'),

('OFF2026_ICT1407', 'HandoverDate', NULL, '2026-05-24', 'lecturer_user', '2026-05-24 14:15:00'),

('OFF2026_ICT1407', 'DetailedMarkSheetSubmitted', 'No', 'Yes', 'lecturer_user', '2026-06-01 16:45:00'),

('OFF2026_ICT1407', 'DispatchedToSecondExaminerDate', NULL, '2026-06-02', 'ar_officer', '2026-06-02 11:00:00');

