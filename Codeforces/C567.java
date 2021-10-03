import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class C567 {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int n = scan.nextInt();

        char[] type = new char[n];
        int[] id = new int[n];
        Set<Integer> entered = new HashSet<>();
        Set<Integer> already = new HashSet<>();
        String temp = scan.nextLine();
        for(int i=0;i<n;i++) {
            String s = scan.nextLine();
            type[i] = s.charAt(0);
            id[i] = Integer.parseInt(s.substring(2));

            if(type[i] == '-' && !entered.contains(id[i]))
                already.add(id[i]);
            else if(type[i] == '+')
                entered.add(id[i]);
        }

        int count = already.size();
        int max = already.size();
        for(int i=0;i<n;i++) {
            if(type[i] == '+') {
                count++;
            }else if(type[i] == '-') {
                count--;
            }
            if(count > max) {
                max = count;
            }
        }
        System.out.println(max);
    }
}
