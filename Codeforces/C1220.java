import java.io.PrintWriter;
import java.util.Scanner;

public class C1220 {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        PrintWriter p = new PrintWriter(System.out);
        StringBuilder sb = new StringBuilder();

        String s = scan.next();
        int n = s.length();
        char[] prefix = new char[n];

        for(int i=0;i<n;i++) {
            if(i == 0) {
                prefix[i] = s.charAt(0);
            }else {
                prefix[i] = (prefix[i-1] < s.charAt(i))? prefix[i-1] : s.charAt(i);
            }
        }

        for(int k=0;k<n;k++) {
            if(prefix[k] < s.charAt(k)) {
                sb.append("Ann").append('\n');
            }else {
                sb.append("Mike").append('\n');
            }
        }

        p.print(sb);
        p.close();
    }
}
