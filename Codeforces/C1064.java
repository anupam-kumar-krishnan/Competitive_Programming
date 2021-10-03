import java.util.Arrays;
import java.util.Scanner;

public class C1064 {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int n = scan.nextInt();
        char[] c = scan.next().toCharArray();

        Arrays.parallelSort(c);
        System.out.println(String.valueOf(c));
    }
}
