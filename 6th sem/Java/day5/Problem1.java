// File: Problem1.java
import java.util.ArrayList;

public class Problem1 {
    public static void main(String[] args) {
        // Create ArrayList
        ArrayList<Employee> empList = new ArrayList<>();

        // Create 4 objects and add to ArrayList
        empList.add(new Employee(101, "Alice", 30, 50000));
        empList.add(new Employee(102, "Bob", 35, 60000));
        empList.add(new Employee(103, "Charlie", 28, 45000));
        empList.add(new Employee(104, "Diana", 32, 70000));

        System.out.println("--- Employee List (Using For Loop) ---");
        // Use standard for loop to display content
        for (int i = 0; i < empList.size(); i++) {
            Employee e = empList.get(i);
            System.out.println(e.toString());
        }
    }
}