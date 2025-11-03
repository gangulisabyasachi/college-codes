-- Apply key constraints & participation constraints for the following relations.
-- emp(eid,ename,sal)
-- dept(did,dname,location)
-- manages(did,eid,day)
-- (i)Create Table emp, dept ,manages .
-- (ii)Alter Table structure if required .
-- (iii)Apply constraints on columns /tables , PRIMARY KEY ,FOREIGN KEY ,UNIQUE ,NOT NULL .
-- (iv)Add record in the TABLE.
-- (v a)Create a view / materialize view using one or more TABLE using JOIN.
-- (vi)Create a materialize view using one or more TABLE using JOIN.


-- (i)Create Table emp, dept ,manages .
CREATE TABLE emp (
    eid INT PRIMARY KEY,           
    ename VARCHAR(50) NOT NULL,    
    sal DECIMAL(10,2) NOT NULL,    
    UNIQUE (ename)                 
);

CREATE TABLE dept (
    did INT PRIMARY KEY,           
    dname VARCHAR(50) NOT NULL,    
    location VARCHAR(50) NOT NULL, 
    UNIQUE (dname)                 
);

CREATE TABLE manages (
    did INT NOT NULL,              
    eid INT NOT NULL,              
    day DATE NOT NULL,            
    PRIMARY KEY (did, eid),        
    FOREIGN KEY (did) REFERENCES dept(did) ON DELETE CASCADE,
    FOREIGN KEY (eid) REFERENCES emp(eid) ON DELETE CASCADE
);

DESC manages;


-- (ii)Alter Table structure if required .
-- (iii)Apply constraints on columns /tables , PRIMARY KEY ,FOREIGN KEY ,UNIQUE ,NOT NULL .
ALTER TABLE emp ADD email VARCHAR(100) UNIQUE;

-- (iv)Add record in the TABLE.
INSERT INTO emp (eid, ename, sal, email) VALUES
(1, 'Rahul Sharma', 55000, 'rahul@example.com'),
(2, 'Priya Das', 60000, 'priya@example.com'),
(3, 'Amit Kumar', 50000, 'amit@example.com');

INSERT INTO dept (did, dname, location) VALUES
(101, 'HR', 'Kolkata'),
(102, 'IT', 'Delhi'),
(103, 'Finance', 'Mumbai');

INSERT INTO manages (did, eid, day) VALUES
(101, 1, '2025-07-01'),
(102, 2, '2025-07-05'),
(103, 3, '2025-07-10');

-- (v a)Create a view using one or more TABLE using JOIN.
CREATE VIEW emp_dept_view AS
SELECT e.eid, e.ename, e.sal, e.email, d.dname, d.location, m.day
FROM emp e
JOIN manages m ON e.eid = m.eid
JOIN dept d ON m.did = d.did;
-- (v b)

SELECT * FROM emp_dept_view;

-- (vi)Create a materialize view using one or more TABLE using JOIN.
-- Create a "materialized view" table
CREATE TABLE emp_dept_mv AS
SELECT e.eid, e.ename, e.sal, e.email, d.dname, d.location, m.day
FROM emp e
JOIN manages m ON e.eid = m.eid
JOIN dept d ON m.did = d.did;

-- To "refresh" it manually later (equivalent to REFRESH COMPLETE)
TRUNCATE TABLE emp_dept_mv;
INSERT INTO emp_dept_mv
SELECT e.eid, e.ename, e.sal, e.email, d.dname, d.location, m.day
FROM emp e
JOIN manages m ON e.eid = m.eid
JOIN dept d ON m.did = d.did;
