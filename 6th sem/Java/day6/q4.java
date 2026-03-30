import java.io.File;
import java.util.Scanner;

public class q4 {
    public static void main(String[] args) {
        int words = 0;
        int lines = 0;
        int characters = 0;

        try {
            File file = new File("sample.txt");
            Scanner sc = new Scanner(file);

            while (sc.hasNextLine()) {
                String line = sc.nextLine();
                lines++;
                characters += line.length();

                String[] wordList = line.split("\\s+");
                words += wordList.length;
            }

            sc.close();

            System.out.println("Number of Lines: " + lines);
            System.out.println("Number of Words: " + words);
            System.out.println("Number of Characters: " + characters);

        } catch (Exception e) {
            System.out.println("Error reading file.");
        }
    }
}