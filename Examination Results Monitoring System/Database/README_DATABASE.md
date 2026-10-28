# Database Implementation & Administration Guide
## Examination Results Monitoring System

This directory contains the production-grade Data Definition Language (DDL), Data Control Language (DCL), and seed data scripts for MySQL InnoDB, strictly adhering to **Document 4 (Schema Refinement & Normalization)**, **Document 5 (Physical Database Design)**, and **Document 6 (Security Design)**.

---

### Scripts Directory:

1. **`01_Create_Database_And_Tables.sql`**
   - **Database:** `exam_monitoring_db`
   - **Storage Engine:** `InnoDB` (ACID compliance, row-level locking, foreign key enforcement)
   - **Character Set & Collation:** `utf8mb4` with `utf8mb4_unicode_ci` (multilingual unicode support)
   - **Entities Created (Parent-before-Child sequence):**
     * `SEMESTER`: Primary Key (`SemesterID`), check constraints on dates (`EndDate >= StartDate`, `ExamEndDate >= ExamStartDate`, `ExamStartDate >= StartDate`), check constraint on semester number (`1, 2`).
     * `COURSE`: Primary Key (`CourseCode`), check constraint on year level (`1 <= YearLevel <= 4`).
     * `NON_ACADEMIC_STAFF`: Primary Key (`userID`), unique constraint on email.
     * `ACADEMIC_STAFF`: Superclass relation with Primary Key (`userID`), unique constraint on email.
     * `INTERNAL_STAFF`: Subclass relation with Primary Key & Foreign Key (`userID`), `DepartmentID`, check constraint on `max_workload >= 0` (`ON DELETE CASCADE ON UPDATE CASCADE`).
     * `EXTERNAL_STAFF`: Subclass relation with Primary Key & Foreign Key (`userID`), `ContactNumber` (`ON DELETE CASCADE ON UPDATE CASCADE`).
     * `COURSE_OFFERING`: Central workflow entity with Primary Key (`OfferingID`), Foreign Keys pointing to `SEMESTER` (`ON DELETE RESTRICT`), `COURSE` (`ON DELETE RESTRICT`), `First_userID` (`ON DELETE RESTRICT`), `Second_userID` (`ON DELETE SET NULL`). Check constraints on `SenateApproved` (`Pending`, `Approved`, `Rejected`), `DetailedMarkSheetSubmitted` (`Yes`, `No`).
     * `ANSWER_SCRIPT`: Weak entity with Composite Primary Key (`OfferingID`, `BundleNumber`), Foreign Key (`OfferingID` `ON DELETE CASCADE`), check constraint on `ScriptCount > 0`.
     * `AUDIT_LOG`: Immutable audit log table recording `LogID`, `OfferingID`, `AttributeChanged`, `OldValue`, `NewValue`, `ChangedBy`, `ChangeTimestamp`.
   - **Indexing Matrix (B+ Tree):**
     * Clustered indexes on all Primary Keys.
     * Secondary Unique indexes on `NON_ACADEMIC_STAFF(email)` and `ACADEMIC_STAFF(email)`.
     * Secondary B+ Tree indexes on `COURSE_OFFERING(SemesterID)` and `COURSE_OFFERING(CourseCode)`.
     * Composite Secondary Index on `COURSE_OFFERING(First_userID, Second_userID)` adhering to the leftmost prefix rule.
     * Secondary index on `ANSWER_SCRIPT(OfferingID)` supporting fast cascade and join queries.

2. **`02_Security_Roles_And_Users.sql`**
   - **Role-Based Access Control (RBAC):**
     * `dean_role`: Read-only (`SELECT`) across all database objects and audit logs.
     * `hod_role`: Read-only on catalogs, with `UPDATE (HODApprovedDate)` on `COURSE_OFFERING`.
     * `first_examiner_role`: Read catalogs, update `HandoverDate`, `DetailedMarkSheetSubmitted`, and `EISUploadDate`.
     * `second_examiner_role`: Read offerings, update `ReturnedFromSecondExaminerDate`.
     * `ar_office_role`: Master administration across all master tables, plus update `SenateApproved` and `DispatchedToSecondExaminerDate`.
     * `supervisor_role`: Custody transfer: `SELECT` offerings, `INSERT` answer script bundles.
   - **Views with `WITH CHECK OPTION`:**
     * `View_Examiner_Approved_Offerings`: Filters offerings where `SenateApproved = 'Approved'` with `WITH CHECK OPTION` to ensure examiners only update Senate-cleared courses.
   - **Pre-Configured User Accounts & Passwords (Section 4.1):**
     * `dean_user` (`Dean#Secure2026!`)
     * `hod_comp` (`Hod#Comp2026!`)
     * `lecturer_user` (`Lect#Exam2026!`)
     * `second_examiner` (`Sec#Exam2026!`)
     * `ar_officer` (`AR#Branch2026!`)
     * `supervisor_01` (`Hall#Sup2026!`)

3. **`03_Sample_Seed_Data.sql`**
   - Contains curriculum data for Computer Science and Information Technology programs (`ICT1101`, `ICT1407`, `ICT2102`, `ICT2203`, `ICT3103`, `ICT3204`, `ICT4104`, `ICT4205`).
   - Pre-seeds realistic active scenarios:
     * Fully finalized & authorized course.
     * Course under active moderation (Second Marking).
     * Course flagged as **Overdue in Moderation (> 14 days)**.
     * Course flagged as **Overdue in First Marking (> 1 Month past ExamEndDate)**.
     * Course locked by **Pending Senate Approval**.
   - Populates initial Answer Script bundles and audit logs.

4. **`04_Backup_And_Recovery_Procedures.sql`**
   - **Nightly Logical Backup:** `mysqldump --single-transaction --routines --triggers exam_monitoring_db` ensuring ACID consistency without blocking live transactions.
   - **Point-in-Time Recovery (PITR):** Restoring full dump baseline and replaying binary logs (`mysqlbinlog --start-datetime`) up to the point of failure.
   - **Crash Recovery:** Automatic InnoDB undo/redo log rollback and roll-forward execution.

---

### Executing Scripts in MySQL:

To load the database into MySQL Server:

```bash
mysql -u root -p < "01_Create_Database_And_Tables.sql"
mysql -u root -p < "02_Security_Roles_And_Users.sql"
mysql -u root -p < "03_Sample_Seed_Data.sql"
```
