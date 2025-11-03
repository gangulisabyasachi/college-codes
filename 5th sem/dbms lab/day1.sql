-- (i) Create the Student table
CREATE TABLE Student (
    Enrollment_No INT PRIMARY KEY,
    CollegeRoll_No INT UNIQUE,
    Student_Name VARCHAR(50) NOT NULL,
    Phone_No VARCHAR(15) NOT NULL,
    Address VARCHAR(100),
    BloodGroup VARCHAR(5)
);

-- Describe the table (this works in MySQL; in SQL Server use sp_help 'Student')
DESC Student;

-- (ii) Insert 7-8 student records
INSERT INTO Student (Enrollment_No, CollegeRoll_No, Student_Name, Phone_No, Address, BloodGroup)
VALUES
(101, 2001, 'Rahul Sharma', '9876543210', 'Kolkata', 'A+'),
(102, 2002, 'Priya Das', '9876501234', 'Delhi', 'B+'),
(103, 2003, 'Amit Kumar', '9001234567', 'Mumbai', 'O+'),
(104, 2004, 'Neha Gupta', '9988776655', 'Chennai', 'A-'),
(105, 2005, 'Sourav Roy', '9876123450', 'Bangalore', 'AB+'),
(106, 2006, 'Sneha Patel', '9123456789', 'Hyderabad', 'B-'),
(107, 2007, 'Ankit Singh', '9012345678', 'Pune', 'O-'),
(108, 2008, 'Riya Sen', '9801234567', 'Jaipur', 'A+');

-- (iii) Select all records
SELECT * FROM Student;

-- (iv) Select phone number and blood group for emergency
SELECT Student_Name, Phone_No, BloodGroup
FROM Student;

-- (v) Add columns State, Country, Branch
ALTER TABLE Student ADD State VARCHAR(30);
ALTER TABLE Student ADD Country VARCHAR(30);
ALTER TABLE Student ADD Branch VARCHAR(50);

-- (vi) Select students between certain enrollment numbers
SELECT * FROM Student
WHERE Enrollment_No BETWEEN 103 AND 107;

-- (vii) Update values using WHERE clause
UPDATE Student
SET State = 'West Bengal', Country = 'India', Branch = 'CSE'
WHERE Enrollment_No = 101;

-- Example: Update multiple records
UPDATE Student
SET State = 'Delhi', Country = 'India', Branch = 'ECE'
WHERE Enrollment_No IN (102, 104);

-- (viii) Drop a column (Example: Address)
ALTER TABLE Student DROP COLUMN Address;

-- (ix) Practice ADD, MODIFY, and RENAME
-- Add a new column Email
ALTER TABLE Student ADD Email VARCHAR(50);

-- Modify datatype of Phone_No
ALTER TABLE Student MODIFY Phone_No VARCHAR(20);

-- Rename a column (rename CollegeRoll_No to Roll_No)
ALTER TABLE Student RENAME COLUMN CollegeRoll_No TO Roll_No;

-- (x) Use of IN operator
SELECT * FROM Student
WHERE BloodGroup IN ('A+', 'O+');

-- (xi) Use of LIKE operator with wildcards
-- Names starting with 'S'
SELECT * FROM Student
WHERE Student_Name LIKE 'S%';

-- Names ending with 'a'
SELECT * FROM Student
WHERE Student_Name LIKE '%a';

-- Names containing 'it'
SELECT * FROM Student
WHERE Student_Name LIKE '%it%';

-- (xii) Example with key constraints
-- Primary key: Enrollment_No already defined
-- Unique: Roll_No already defined
-- NOT NULL: Student_Name, Phone_No
-- Null values allowed for State, Country, Branch unless specified NOT NULL

