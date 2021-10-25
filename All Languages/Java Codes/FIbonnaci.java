import java.util.Scanner;

public class Fibonacci {
  private static long calc_fib(int n) {
	  if(n==0){
		return 0;
		}
		else if(n==1){
			return 1;
			}
		
    long[] F = new long[n+1];
    F[0]=0;
    F[1]=1;
    
    
    for(int i =2;i<=n;i++){
		F[i]=F[i-1]+F[i-2];
		}
    return F[n];
  }

  public static void main(String args[]) {
    Scanner in = new Scanner(System.in);
    int n = in.nextInt();
	
    System.out.println(calc_fib(n));
  }
}