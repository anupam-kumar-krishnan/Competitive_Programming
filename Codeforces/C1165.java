import java.util.Scanner;

public class C1165 {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int n = scan.nextInt();
        String s = scan.next();
        StringBuilder sb = new StringBuilder();

        int i=0;
        boolean bool = true;
        while(i < s.length()) {
            if(bool) {
                sb.append(s.charAt(i));
                int j = i+1;
                while(j < n && s.charAt(j) == s.charAt(i))
                    j++;
                i = j;
                bool = false;
            }else {
                sb.append(s.charAt(i));
                i++;
                bool = true;
            }
        }
        int size = sb.length();
        if(size % 2 == 1) {
            sb.deleteCharAt(size - 1);
            size--;
        }
        System.out.println(s.length() - size);
        System.out.println(sb);
    }
}
