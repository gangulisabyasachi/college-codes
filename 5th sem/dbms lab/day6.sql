-- Drop old tables if rerunning
DROP TABLE IF EXISTS Supply_Detail;
DROP TABLE IF EXISTS Supply_Detail_3NF;
DROP TABLE IF EXISTS Supply_Detail_2NF;
DROP TABLE IF EXISTS Supply_Detail_1NF;
DROP TABLE IF EXISTS Supply_Detail_UNF;
DROP TABLE IF EXISTS Project;
DROP TABLE IF EXISTS Part;
DROP TABLE IF EXISTS Supplier;

-- ==============================
-- UNNORMALIZED FORM (UNF)
-- ==============================
CREATE TABLE Supply_Detail_UNF (
  Supplier_ID INT,
  Supplier_Name VARCHAR(60),
  Supplier_City VARCHAR(40),
  Part_List VARCHAR(4000), 
  Project_List VARCHAR(4000), 
  Qty_List VARCHAR(4000)
);

-- ==============================
-- FIRST NORMAL FORM (1NF)
-- ==============================
CREATE TABLE Supply_Detail_1NF (
  Supplier_ID INT,
  Supplier_Name VARCHAR(60),
  Supplier_City VARCHAR(40),
  Part_ID VARCHAR(20),
  Project_ID VARCHAR(20),
  Quantity INT
);

-- ==============================
-- SUPPLIER TABLE (for higher NF)
-- ==============================
CREATE TABLE Supplier (
  Supplier_ID INT PRIMARY KEY,
  Supplier_Name VARCHAR(60),
  Supplier_City VARCHAR(40)
);

-- ==============================
-- SECOND NORMAL FORM (2NF)
-- ==============================
CREATE TABLE Supply_Detail_2NF (
  Supplier_ID INT,
  Part_ID VARCHAR(20),
  Project_ID VARCHAR(20),
  Quantity INT,
  PRIMARY KEY (Supplier_ID, Part_ID, Project_ID),
  FOREIGN KEY (Supplier_ID) REFERENCES Supplier(Supplier_ID)
);

-- ==============================
-- PART & PROJECT TABLES
-- ==============================
CREATE TABLE Part (
  Part_ID VARCHAR(20) PRIMARY KEY,
  Part_Name VARCHAR(60)
);

CREATE TABLE Project (
  Project_ID VARCHAR(20) PRIMARY KEY,
  Project_Name VARCHAR(60),
  Client_Name VARCHAR(60)
);

-- ==============================
-- THIRD NORMAL FORM (3NF)
-- ==============================
CREATE TABLE Supply_Detail_3NF (
  Supplier_ID INT,
  Part_ID VARCHAR(20),
  Project_ID VARCHAR(20),
  Quantity INT,
  PRIMARY KEY (Supplier_ID, Part_ID, Project_ID),
  FOREIGN KEY (Supplier_ID) REFERENCES Supplier(Supplier_ID),
  FOREIGN KEY (Part_ID) REFERENCES Part(Part_ID),
  FOREIGN KEY (Project_ID) REFERENCES Project(Project_ID)
);

-- ==============================
-- FINAL (3NF) - SAME AS Supply_Detail_3NF
-- ==============================
CREATE TABLE Supply_Detail (
  Supplier_ID INT,
  Part_ID VARCHAR(20),
  Project_ID VARCHAR(20),
  Quantity INT,
  PRIMARY KEY (Supplier_ID, Part_ID, Project_ID),
  FOREIGN KEY (Supplier_ID) REFERENCES Supplier(Supplier_ID),
  FOREIGN KEY (Part_ID) REFERENCES Part(Part_ID),
  FOREIGN KEY (Project_ID) REFERENCES Project(Project_ID)
);

-- ==============================
-- INSERT DATA
-- ==============================
-- Suppliers
INSERT INTO Supplier VALUES (1, 'Alpha Electronics', 'Mumbai');
INSERT INTO Supplier VALUES (2, 'Beta Components', 'Delhi');
INSERT INTO Supplier VALUES (3, 'Gamma Circuits', 'Bangalore');

-- Parts
INSERT INTO Part VALUES ('P1', 'Resistor');
INSERT INTO Part VALUES ('P2', 'Capacitor');
INSERT INTO Part VALUES ('P3', 'Microcontroller');

-- Projects
INSERT INTO Project VALUES ('J1', 'Smartphone Project', 'Samsung');
INSERT INTO Project VALUES ('J2', 'Drone Project', 'DRDO');
INSERT INTO Project VALUES ('J3', 'IoT Device Project', 'Amazon');

-- Final Supply Details (3NF)
INSERT INTO Supply_Detail VALUES (1, 'P1', 'J1', 500);
INSERT INTO Supply_Detail VALUES (1, 'P2', 'J1', 300);
INSERT INTO Supply_Detail VALUES (2, 'P3', 'J2', 200);
INSERT INTO Supply_Detail VALUES (3, 'P1', 'J3', 400);
INSERT INTO Supply_Detail VALUES (3, 'P3', 'J3', 450);

-- ==============================
-- QUERIES
-- ==============================

-- a) Who the suppliers are?
SELECT Supplier_ID, Supplier_Name, Supplier_City
FROM Supplier;

-- b) Which part was delivered?
SELECT DISTINCT Part_ID, Part_Name
FROM Part;

-- c) For which project the delivery was received?
SELECT DISTINCT Project_ID, Project_Name
FROM Project;

-- d) How many units came in that batch from specific Supplier City?
SELECT s.Supplier_City, SUM(sd.Quantity) AS Total_Units
FROM Supply_Detail sd
JOIN Supplier s ON sd.Supplier_ID = s.Supplier_ID
GROUP BY s.Supplier_City;
