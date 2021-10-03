import java.io.PrintWriter;
import java.util.Scanner;

public class C1512 {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        PrintWriter p = new PrintWriter(System.out);
        StringBuilder sb = new StringBuilder();

        int t = scan.nextInt();
        while (t-- > 0) {
            int a = scan.nextInt();
            int b = scan.nextInt();
            String s = scan.next();
            int n = s.length();

            sb.append(solve(s.toCharArray(), a, b, n)).append('\n');
        }
        p.print(sb);
        p.close();
    }
    static String solve(char[] c, int a, int b, int n) {
        int count = 0;
        for(int i=0;i<n;i++) {
            if(c[i] == '0') {
                if(c[n-i-1] == '1')
                    return "-1";
                a--;
            }
            else if(c[i] == '1') {
                if(c[n-i-1] == '0')
                    return "-1";
                b--;
            }
            else {
                if(c[n-i-1] == '0') {
                    c[i] = c[n-i-1];
                    a--;
                }else if(c[n-i-1] == '1') {
                    c[i] = c[n-i-1];
                    b--;
                }else {
                    count++;
                }
            }
        }
        if(((count & 1) == 1) && ((n & 1) != 1) && c[n/2] != '?')
            return "-1";

        for(int i=0;i<n;i++) {
            if(c[i] == '?') {
                if((n & 1) == 1 && i == n/2) {
                    if(a >0 && (a & 1) == 1) {
                        c[i] = '0';
                        a--;
                    }else if(b > 0 && (b & 1) == 1) {
                        c[i] = '1';
                        b--;
                    }else {
                        return "-1";
                    }
                }else if(a >= 2) {
                    c[i] = '0';
                    c[n-i-1] = '0';
                    a -= 2;
                }else if(b >= 2) {
                    c[i] = '1';
                    c[n-i-1] = '1';
                    b -= 2;
                }else {
                    return "-1";
                }
            }
        }
        return (a == 0 && b == 0)? String.valueOf(c): "-1";
    }
}
