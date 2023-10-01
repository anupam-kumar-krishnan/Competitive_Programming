import java.util.*;
class Factorial{
    public static long fact(int n) {
        if (n == 0 || n == 1) {
            // Base case: Factorial of 0 and 1 is 1
            return 1;
        } else {
            // Recursive case: Factorial of n is n times factorial of (n-1)
            return n * fact(n - 1);
        }
    }
    public static void main(String[] args){
        //Factorial of n is the product of all positive descending integers.
        System.out.println("Enter Integer:");
        Scanner sc = new Scanner(System.in);
        int num = sc.nextInt();
        long result = fact(num);
        System.out.println("Factirial of " + num + " is " + result);

    }
}
