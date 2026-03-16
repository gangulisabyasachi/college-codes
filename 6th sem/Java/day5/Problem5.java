// File: Problem5.java

// Department Class
class Department implements Cloneable {
    String id;
    String name;
    String location;

    public Department(String id, String name, String location) {
        this.id = id;
        this.name = name;
        this.location = location;
    }

    // Required for Deep Copying
    @Override
    protected Object clone() throws CloneNotSupportedException {
        return super.clone();
    }

    @Override
    public String toString() {
        return name + " (" + location + ")";
    }
}

// Employee Class specific for Problem 5
class EmpClone implements Cloneable {
    int id;
    String name;
    Department dept; // Reference object

    public EmpClone(int id, String name, Department dept) {
        this.id = id;
        this.name = name;
        this.dept = dept;
    }

    // --- SHALLOW COPY METHOD ---
    public Object shallowCopy() throws CloneNotSupportedException {
        // default clone() creates a shallow copy
        return super.clone();
    }

    // --- DEEP COPY METHOD ---
    public Object deepCopy() throws CloneNotSupportedException {
        // 1. Clone the main employee object
        EmpClone clonedEmp = (EmpClone) super.clone();
        
        // 2. MANUALLY clone the mutable Department object
        clonedEmp.dept = (Department) this.dept.clone();
        
        return clonedEmp;
    }

    @Override
    public String toString() {
        return "Emp: " + name + " | Dept: " + dept.name;
    }
}

public class Problem5 {
    public static void main(String[] args) {
        try {
            Department hr = new Department("D1", "HR", "New York");
            EmpClone original = new EmpClone(1, "Original", hr);

            System.out.println("Original: " + original);

            // 1. Perform Shallow Copy
            EmpClone shallow = (EmpClone) original.shallowCopy();
            
            // 2. Perform Deep Copy
            EmpClone deep = (EmpClone) original.deepCopy();

            System.out.println("\n--- Modifying Department Name to 'Finance' ---");
            // We change the shared department object
            hr.name = "Finance"; 

            // Shallow copy will reflect the change (because it points to the SAME Department object)
            System.out.println("Shallow Copy (Should change): " + shallow);
            
            // Deep copy will NOT reflect the change (because it has its OWN Department object)
            System.out.println("Deep Copy    (Should stay HR): " + deep);

        } catch (CloneNotSupportedException e) {
            e.printStackTrace();
        }
    }
}