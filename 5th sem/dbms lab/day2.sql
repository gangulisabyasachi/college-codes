-- Create students table
CREATE TABLE students (
    sid INT PRIMARY KEY,
    sname VARCHAR(50) NOT NULL,
    address VARCHAR(100)
);

-- Create courses table
CREATE TABLE courses (
    cid INT PRIMARY KEY,
    cname VARCHAR(50) NOT NULL,
    fee DECIMAL(10,2) NOT NULL
);

-- Create enrolled table with Foreign Keys
CREATE TABLE enrolled (
    cid INT,
    sid INT,
    doj DATE NOT NULL,
    fee_paid DECIMAL(10,2) DEFAULT 0,
    PRIMARY KEY (cid, sid),
    FOREIGN KEY (cid) REFERENCES courses(cid) ON DELETE CASCADE,
    FOREIGN KEY (sid) REFERENCES students(sid) ON DELETE CASCADE
);

-- Insert data into students
INSERT INTO students (sid, sname, address) VALUES
(1, 'Rahul Sharma', 'Kolkata'),
(2, 'Priya Das', 'Delhi'),
(3, 'Amit Kumar', 'Mumbai'),
(4, 'Neha Gupta', 'Chennai');

-- Insert data into courses
INSERT INTO courses (cid, cname, fee) VALUES
(101, 'Database Systems', 5000),
(102, 'Data Structures', 4500),
(103, 'Operating Systems', 4800);

-- Insert data into enrolled
INSERT INTO enrolled (cid, sid, doj, fee_paid) VALUES
(101, 1, '2025-07-05', 5000),
(102, 1, '2025-07-10', 4500),
(101, 2, '2025-07-15', 0),
(103, 3, '2025-07-20', 4800),
(102, 4, '2025-06-25', 0);

-- (i) Get all students
SELECT * FROM students;

-- (ii) Get all courses being taught in a semester
SELECT * FROM courses;

-- (iii) List students along with the courses they are enrolled in
SELECT s.sid, s.sname, c.cname, e.doj
FROM students s
JOIN enrolled e ON s.sid = e.sid
JOIN courses c ON e.cid = c.cid;

-- (iv) List all students who enrolled after 01-JUL-2025
SELECT s.sid, s.sname, e.doj
FROM students s
JOIN enrolled e ON s.sid = e.sid
WHERE e.doj > '2025-07-01';

-- (v) Find the number of students enrolled in each course
SELECT c.cname, COUNT(e.sid) AS total_students
FROM courses c
LEFT JOIN enrolled e ON c.cid = e.cid
GROUP BY c.cname;

-- (vi) Get the total fee collected per course
SELECT c.cname, SUM(e.fee_paid) AS total_fee_collected
FROM courses c
JOIN enrolled e ON c.cid = e.cid
GROUP BY c.cname;

-- (vii) Get the list of students who need to pay the fee
SELECT s.sid, s.sname, c.cname, c.fee - e.fee_paid AS fee_due
FROM students s
JOIN enrolled e ON s.sid = e.sid
JOIN courses c ON e.cid = c.cid
WHERE e.fee_paid < c.fee;
