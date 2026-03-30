import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;

public class q5 {
    public static void main(String[] args) {
        try {
            FileInputStream source = new FileInputStream("file1.txt");
            FileOutputStream destination = new FileOutputStream("file2.txt");

            int data;
            while ((data = source.read()) != -1) {
                destination.write(data);
            }

            source.close();
            destination.close();

            System.out.println("Content copied from file1.txt to file2.txt");
        } catch (IOException e) {
            System.out.println("Error copying file.");
        }
    }
}