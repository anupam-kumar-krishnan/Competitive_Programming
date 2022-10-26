public class BUTTERFLY_PATTERN {
    public static void main(String[] args) {

        java.util.Scanner sc = new java.util.Scanner(System.in);
        System.out.println("Enter the value of n");
        int n = sc.nextInt();

        for (int i = 1; i <= n; i++) {
            for (int st = 1; st <= i; st++) {
                System.out.print("*");
            }
            for (int sp = 1; sp <= 2 * (n - i); sp++) {
                System.out.print(" ");
            }
            for (int st = 1; st <= i; st++) {
                System.out.print("*");
            }
            System.out.println();
        }
        for (int i = n; i >= 1; i--) {
            for (int st = 1; st <= i; st++) {
                System.out.print("*");
            }
            for (int sp = 1; sp <= 2 * (n - i); sp++) {
                System.out.print(" ");
            }
            for (int st = 1; st <= i; st++) {
                System.out.print("*");
            }
            System.out.println();
        }
    }
}
