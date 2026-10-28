CREATE DATABASE IF NOT EXISTS exam_monitoring_db

  CHARACTER SET utf8mb4

  COLLATE utf8mb4_unicode_ci;



USE exam_monitoring_db;



DROP TABLE IF EXISTS ANSWER_SCRIPT;

DROP TABLE IF EXISTS COURSE_OFFERING;

DROP TABLE IF EXISTS EXTERNAL_STAFF;

DROP TABLE IF EXISTS INTERNAL_STAFF;

DROP TABLE IF EXISTS ACADEMIC_STAFF;

DROP TABLE IF EXISTS NON_ACADEMIC_STAFF;

DROP TABLE IF EXISTS COURSE;

DROP TABLE IF EXISTS SEMESTER;

DROP TABLE IF EXISTS AUDIT_LOG;



CREATE TABLE SEMESTER (

    SemesterID VARCHAR(10) NOT NULL,

    AcademicYear VARCHAR(9) NOT NULL,

    SemesterNumber INT NOT NULL,

    StartDate DATE NOT NULL,

    EndDate DATE NOT NULL,

    ExamStartDate DATE NOT NULL,

    ExamEndDate DATE NOT NULL,

    PRIMARY KEY (SemesterID),

    CONSTRAINT chk_sem_number CHECK (SemesterNumber IN (1, 2)),

    CONSTRAINT chk_sem_dates CHECK (EndDate >= StartDate),

    CONSTRAINT chk_exam_dates CHECK (ExamEndDate >= ExamStartDate),

    CONSTRAINT chk_exam_window CHECK (ExamStartDate >= StartDate)

) ENGINE = InnoDB CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci;



CREATE TABLE COURSE (

    CourseCode VARCHAR(10) NOT NULL,

    CourseTitle VARCHAR(100) NOT NULL,

    YearLevel INT NOT NULL,

    PRIMARY KEY (CourseCode),

    CONSTRAINT chk_year_level CHECK (YearLevel BETWEEN 1 AND 4)

) ENGINE = InnoDB CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci;



CREATE TABLE NON_ACADEMIC_STAFF (

    userID VARCHAR(10) NOT NULL,

    name VARCHAR(100) NOT NULL,

    email VARCHAR(100) NOT NULL,

    role VARCHAR(50) NOT NULL,

    PRIMARY KEY (userID),

    CONSTRAINT uq_nonacademic_email UNIQUE (email)

) ENGINE = InnoDB CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci;



CREATE TABLE ACADEMIC_STAFF (

    userID VARCHAR(10) NOT NULL,

    name VARCHAR(100) NOT NULL,

    email VARCHAR(100) NOT NULL,

    role VARCHAR(50) NOT NULL,

    PRIMARY KEY (userID),

    CONSTRAINT uq_academic_email UNIQUE (email)

) ENGINE = InnoDB CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci;



CREATE TABLE INTERNAL_STAFF (

    userID VARCHAR(10) NOT NULL,

    departmentID VARCHAR(10) NOT NULL,

    max_workload INT NOT NULL,

    PRIMARY KEY (userID),

    CONSTRAINT fk_internal_staff_user

        FOREIGN KEY (userID)

        REFERENCES ACADEMIC_STAFF(userID)

        ON DELETE CASCADE ON UPDATE CASCADE,

    CONSTRAINT chk_max_workload CHECK (max_workload >= 0)

) ENGINE = InnoDB CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci;



CREATE TABLE EXTERNAL_STAFF (

    userID VARCHAR(10) NOT NULL,

    ContactNumber VARCHAR(15) NOT NULL,

    PRIMARY KEY (userID),

    CONSTRAINT fk_external_staff_user

        FOREIGN KEY (userID)

        REFERENCES ACADEMIC_STAFF(userID)

        ON DELETE CASCADE ON UPDATE CASCADE

) ENGINE = InnoDB CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci;



CREATE TABLE COURSE_OFFERING (

    OfferingID VARCHAR(15) NOT NULL,

    SemesterID VARCHAR(10) NOT NULL,

    CourseCode VARCHAR(10) NOT NULL,

    First_userID VARCHAR(10) NOT NULL,

    Second_userID VARCHAR(10) DEFAULT NULL,

    SenateApproved VARCHAR(20) NOT NULL DEFAULT 'Pending',

    EISUploadDate DATE DEFAULT NULL,

    HODApprovedDate DATE DEFAULT NULL,

    HandoverDate DATE DEFAULT NULL,

    DetailedMarkSheetSubmitted VARCHAR(10) NOT NULL DEFAULT 'No',

    DispatchedToSecondExaminerDate DATE DEFAULT NULL,

    ReturnedFromSecondExaminerDate DATE DEFAULT NULL,

    PRIMARY KEY (OfferingID),

    CONSTRAINT fk_offering_semester

        FOREIGN KEY (SemesterID)

        REFERENCES SEMESTER(SemesterID)

        ON DELETE RESTRICT ON UPDATE CASCADE,

    CONSTRAINT fk_offering_course

        FOREIGN KEY (CourseCode)

        REFERENCES COURSE(CourseCode)

        ON DELETE RESTRICT ON UPDATE CASCADE,

    CONSTRAINT fk_offering_first_examiner

        FOREIGN KEY (First_userID)

        REFERENCES ACADEMIC_STAFF(userID)

        ON DELETE RESTRICT ON UPDATE CASCADE,

    CONSTRAINT fk_offering_second_examiner

        FOREIGN KEY (Second_userID)

        REFERENCES ACADEMIC_STAFF(userID)

        ON DELETE SET NULL ON UPDATE CASCADE,

    CONSTRAINT chk_senate_approval

        CHECK (SenateApproved IN ('Pending', 'Approved', 'Rejected')),

    CONSTRAINT chk_marksheet_status

        CHECK (DetailedMarkSheetSubmitted IN ('Yes', 'No')),

    INDEX idx_offering_semester (SemesterID),

    INDEX idx_offering_course (CourseCode),

    INDEX idx_offering_examiners (First_userID, Second_userID)

) ENGINE = InnoDB CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci;



CREATE TABLE ANSWER_SCRIPT (

    OfferingID VARCHAR(15) NOT NULL,

    BundleNumber INT NOT NULL,

    ScriptCount INT NOT NULL,

    SupervisorHandoverDate DATE DEFAULT NULL,

    PRIMARY KEY (OfferingID, BundleNumber),

    CONSTRAINT fk_answerscript_offering

        FOREIGN KEY (OfferingID)

        REFERENCES COURSE_OFFERING(OfferingID)

        ON DELETE CASCADE ON UPDATE CASCADE,

    CONSTRAINT chk_script_count CHECK (ScriptCount > 0),

    INDEX idx_script_offering (OfferingID)

) ENGINE = InnoDB CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci;



CREATE TABLE AUDIT_LOG (

    LogID INT AUTO_INCREMENT PRIMARY KEY,

    OfferingID VARCHAR(15) NOT NULL,

    AttributeChanged VARCHAR(50) NOT NULL,

    OldValue VARCHAR(100) NULL,

    NewValue VARCHAR(100) NULL,

    ChangedBy VARCHAR(50) NOT NULL,

    ChangeTimestamp TIMESTAMP DEFAULT CURRENT_TIMESTAMP,

    INDEX idx_audit_offering (OfferingID)

) ENGINE = InnoDB CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci;

