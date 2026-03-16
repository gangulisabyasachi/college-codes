// File: Problem4.java
import java.util.LinkedHashMap;
import java.util.Iterator;
import java.util.Map;

public class Problem4 {
    public static void main(String[] args) {
        // Create LinkedHashMap <ID, Name>
        LinkedHashMap<Integer, String> students = new LinkedHashMap<>();

        // Add 6 students
        students.put(101, "John");
        students.put(102, "Emma");
        students.put(103, "Oliver");
        students.put(104, "Sophia");
        students.put(105, "Liam");
        students.put(106, "Ava");

        // Print size
        System.out.println("Size of map: " + students.size());

        System.out.println("--- Map Data (Using Iterator) ---");
        // Iterate using entrySet and Iterator
        Iterator<Map.Entry<Integer, String>> it = students.entrySet().iterator();
        
        while(it.hasNext()){
            Map.Entry<Integer, String> entry = it.next();
            System.out.println("ID: " + entry.getKey() + ", Name: " + entry.getValue());
        }

        // Check for a key
        int searchKey = 103;
        System.out.println("\n--- Search ---");
        if(students.containsKey(searchKey)) {
            System.out.println("Student with ID " + searchKey + " is found: " + students.get(searchKey));
        } else {
            System.out.println("Student with ID " + searchKey + " not found.");
        }
    }
}