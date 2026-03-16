// File: Problem3.java
import java.util.LinkedList;

public class Problem3 {
    public static void main(String[] args) {
        // 1. Create LinkedList of 6 employees
        LinkedList<Employee> empList = new LinkedList<>();
        empList.add(new Employee(1, "Emp1", 25, 30000));
        empList.add(new Employee(2, "Emp2", 26, 31000));
        empList.add(new Employee(3, "Emp3", 27, 32000));
        empList.add(new Employee(4, "Emp4", 28, 33000));
        empList.add(new Employee(5, "Emp5", 29, 34000));
        empList.add(new Employee(6, "Emp6", 30, 35000));
        
        System.out.println("--- Initial List ---");
        printList(empList);

        // 2. Add at the beginning
        empList.addFirst(new Employee(0, "StartEmp", 22, 25000));
        System.out.println("\n--- After adding at Beginning ---");
        printList(empList);

        // 3. Add at position 2 (Index 2)
        empList.add(2, new Employee(99, "MiddleEmp", 40, 90000));
        System.out.println("\n--- After adding at Position 2 ---");
        printList(empList);

        // 4. Remove First and Last
        empList.removeFirst();
        empList.removeLast();
        System.out.println("\n--- After removing First and Last ---");
        printList(empList);
    }

    private static void printList(LinkedList<Employee> list) {
        for (Employee e : list) {
            System.out.println(e.getName() + " (ID: " + e.getId() + ")");
        }
    }
}