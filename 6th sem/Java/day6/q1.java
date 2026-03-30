import java.io.FileWriter;
import java.io.IOException;

public class q1 {
    public static void main(String[] args) {
        try {
            FileWriter writer = new FileWriter("sample.txt");
            writer.write("Name: Sabyasachi Ganguli\n");
            writer.write("Roll No: 12345\n");
            writer.close();
            System.out.println("sample.txt created and data written successfully.");
        } catch (IOException e) {
            System.out.println("Error occurred.");
        }
    }
}