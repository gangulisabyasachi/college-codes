-- Drop existing tables if you want to re-run cleanly
DROP TABLE IF EXISTS work_on;
DROP TABLE IF EXISTS supervises;
DROP TABLE IF EXISTS grad_stud;
DROP TABLE IF EXISTS projects;
DROP TABLE IF EXISTS professor;

-- Professor table
CREATE TABLE professor(
    ssn INT PRIMARY KEY,
    pname VARCHAR(50),
    age INT NOT NULL,
    rank INT
);

-- Projects table
CREATE TABLE projects(
    proj_no INT PRIMARY KEY,
    sponsor VARCHAR(100),
    start_dt DATE,
    end_dt DATE,
    budget INT
);

-- Graduate student table
CREATE TABLE grad_stud(
    ssn INT PRIMARY KEY,
    sname VARCHAR(50),
    age INT,
    deg VARCHAR(100)
);

-- Supervises table
CREATE TABLE supervises(
    ssn INT,
    proj_no INT,
    PRIMARY KEY(ssn, proj_no),
    FOREIGN KEY(ssn) REFERENCES professor(ssn),
    FOREIGN KEY(proj_no) REFERENCES projects(proj_no)
);

-- Work_on table
CREATE TABLE work_on(
    ssn INT,
    proj_no INT,
    work_hr INT,
    PRIMARY KEY(ssn, proj_no),
    FOREIGN KEY(ssn) REFERENCES grad_stud(ssn),
    FOREIGN KEY(proj_no) REFERENCES projects(proj_no)
);

-- Insert professors
INSERT INTO professor VALUES (11, 'A', 50, 1);
INSERT INTO professor VALUES (21, 'B', 100, 2);

-- Insert projects (YYYY-MM-DD format)
INSERT INTO projects VALUES (101, 'ISRO', '2020-01-01', '2025-01-01', 1000);
INSERT INTO projects VALUES (201, 'NASA', '2020-01-01', '2026-01-01', 2000);
INSERT INTO projects VALUES (301, 'IISc', '2020-01-01', '2027-01-01', 3000);

-- Insert grad students
INSERT INTO grad_stud VALUES (111, 'AA', 20, 'BTech');
INSERT INTO grad_stud VALUES (222, 'BB', 21, 'BSc');
INSERT INTO grad_stud VALUES (333, 'BC', 22, 'MBA');

-- Insert supervises
INSERT INTO supervises VALUES (11, 101);
INSERT INTO supervises VALUES (11, 201);
INSERT INTO supervises VALUES (21, 301);

-- Insert work_on
INSERT INTO work_on VALUES (111, 101, 5);
INSERT INTO work_on VALUES (111, 201, 3);
INSERT INTO work_on VALUES (222, 101, 15);
INSERT INTO work_on VALUES (333, 301, 10);
INSERT INTO work_on VALUES (111, 301, 5);

-- Example queries
SELECT g.sname, g.ssn, w.proj_no, w.work_hr 
FROM grad_stud g 
JOIN work_on w ON g.ssn = w.ssn;

SELECT s.ssn, s.sname, p.proj_no, w.work_hr 
FROM work_on w
JOIN grad_stud s ON s.ssn = w.ssn
JOIN projects p ON p.proj_no = w.proj_no
WHERE p.proj_no = 301;

SELECT p.ssn, p.pname, pr.proj_no, pr.sponsor, pr.start_dt, pr.end_dt 
FROM supervises s
JOIN professor p ON s.ssn = p.ssn
JOIN projects pr ON s.proj_no = pr.proj_no;

-- Trigger to update budget and extend project end date after new work_on entry
DELIMITER $$

CREATE TRIGGER update_budg 
AFTER INSERT ON work_on
FOR EACH ROW
BEGIN
    UPDATE projects
    SET budget = budget + 1000,
        end_dt = DATE_ADD(end_dt, INTERVAL 30 DAY)
    WHERE proj_no = NEW.proj_no;
END$$

DELIMITER ;

-- Test trigger
INSERT INTO work_on VALUES (333, 101, 13);

-- Check projects table after trigger
SELECT * FROM projects;
