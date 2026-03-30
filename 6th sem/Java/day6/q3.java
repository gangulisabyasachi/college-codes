import java.io.FileWriter;
import java.io.IOException;

public class q3 {
    public static void main(String[] args) {
        try {
            FileWriter writer = new FileWriter("sample.txt", true);
            writer.write("\nCourse: B.Tech CSE");
            writer.write("\nSubject: Java Programming");
            writer.close();

            System.out.println("Data appended successfully.");
        } catch (IOException e) {
            System.out.println("Error occurred.");
        }
    }
}