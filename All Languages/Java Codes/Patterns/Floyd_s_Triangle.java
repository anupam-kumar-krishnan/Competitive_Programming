public class Floyd_s_Triangle {
    public static void main(String[] args) {
        java.util.Scanner sc = new java.util.Scanner(System.in);
        System.out.println("Enter the value of n");
        int n = sc.nextInt();
        int ft = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= i; j++) {
                System.out.print(ft + " ");
                ft++;
            }
            System.out.println();

        }
    }
}
