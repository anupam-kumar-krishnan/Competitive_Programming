import java.util.Scanner;

public class C304 {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int n = scan.nextInt();

        if((n & 1) != 1) {
            System.out.println(-1);
        }else {
            StringBuilder sb = new StringBuilder();
            for(int i=0;i<n;i++) {
                sb.append(i).append(' ');
            }
            sb.append('\n');
            for(int i=0;i<n;i++) {
                sb.append(i).append('\n');
            }
            sb.append('\n');
            for(int i=0;i<n;i++) {
                sb.append((i << 1) % n).append(' ');
            }
            System.out.println(sb);
        }
    }
}
