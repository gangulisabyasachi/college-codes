import java.io.*;
import java.util.Scanner;

public class q6 {
    public static void main(String[] args) {
        try {
            File inputFile = new File("students.csv");
            Scanner sc = new Scanner(inputFile);

            FileWriter writer = new FileWriter("student_records.txt");

            while (sc.hasNextLine()) {
                String line = sc.nextLine();
                writer.write(line + "\n");
            }

            sc.close();
            writer.close();

            System.out.println("Student records saved to student_records.txt");

            Scanner read = new Scanner(new File("student_records.txt"));
            System.out.println("\nDisplaying records:");
            while (read.hasNextLine()) {
                System.out.println(read.nextLine());
            }
            read.close();

        } catch (Exception e) {
            System.out.println("Error processing records.");
        }
    }
}