// File: Employee.java
public class Employee {
    private int id;
    private String name;
    private int age;
    private double salary;

    public Employee(int id, String name, int age, double salary) {
        this.id = id;
        this.name = name;
        this.age = age;
        this.salary = salary;
    }

    public double computeTax() {
        // Example logic: 10% tax
        return this.salary * 0.10;
    }

    // Getters and toString for display
    public int getId() { return id; }
    public String getName() { return name; }
    
    @Override
    public String toString() {
        return "ID: " + id + ", Name: " + name + ", Age: " + age + 
               ", Salary: " + salary + ", Tax: " + computeTax();
    }
}