// File: Problem2.java
import java.util.ArrayList;
import java.util.Iterator;

public class Problem2 {
    public static void main(String[] args) {
        // Setup data (same as Problem 1)
        ArrayList<Employee> empList = new ArrayList<>();
        empList.add(new Employee(101, "Alice", 30, 50000));
        empList.add(new Employee(102, "Bob", 35, 60000));
        empList.add(new Employee(103, "Charlie", 28, 45000));
        empList.add(new Employee(104, "Diana", 32, 70000));

        System.out.println("--- Employee List (Using Iterator) ---");
        
        // Get Iterator
        Iterator<Employee> it = empList.iterator();

        // Iterate
        while (it.hasNext()) {
            Employee e = it.next();
            System.out.println(e);
        }
    }
}