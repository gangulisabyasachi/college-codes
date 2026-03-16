import java.util.Scanner;

public class day4 {

    static void stringInfo() {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter a string: ");
        String s = sc.nextLine();
        System.out.println("Length of String: " + s.length());
        System.out.println("Upp: " + s.toUpperCase());
        System.out.println("Low: " + s.toLowerCase());
        String rev = new StringBuilder(s).reverse().toString();
        System.out.println("Reversed String: " + rev);

        int volCount = 0;
        for(int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                volCount++;
            }
        }
        System.out.println("Vowels in string: " + volCount);
    }

    static void checkPalindrome() {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter a string: ");
        String s = sc.nextLine();

        String rev = new StringBuilder(s).reverse().toString();

        if(rev.equals(s)) {
            System.out.println("palindrome");
        }
        else {
            System.out.println("not a palindrome");
        }
    }

    static void arrOps() {
        int arr[] = new int[10];
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter 10 nums: ");
        for(int i = 0; i < 10; i++) {
            arr[i] = sc.nextInt();
        }

        int max = arr[0];
        int min = arr[0];
        double sum = 0;

        for(int i : arr) {
            if(max < i) {
                max = i;
            }
            if(min > i) {
                min = i;
            }
            sum += i;
        }

        System.out.println("Max: " + max);
        System.out.println("Min: " + min);
        System.out.println("Sum: " + sum);
        System.out.println("Average: " + sum / 10);
    }

    static void searchArr() {
        int arr[] = new int[10];
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter 10 nums: ");
        for(int i = 0; i < 10; i++) {
            arr[i] = sc.nextInt();
        }
        System.out.println("Enter search int: ");
        int search = sc.nextInt();

        for(int i = 0; i < 10; i++) {
            if(search == arr[i]) {
                System.out.println("Found\nIndex: " + i);
                return;
            }
        }
        System.out.println("Not Found");
    }

    public static void main(String args[]) {
        //stringInfo();
        //checkPalindrome();
        //arrOps();
        searchArr();
    }
}