import java.io.File;
import java.util.Scanner;

public class q2 {
    public static void main(String[] args) {
        try {
            File file = new File("sample.txt");
            Scanner sc = new Scanner(file);

            System.out.println("Contents of sample.txt:");
            while (sc.hasNextLine()) {
                System.out.println(sc.nextLine());
            }

            sc.close();
        } catch (Exception e) {
            System.out.println("File not found.");
        }
    }
}