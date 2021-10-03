import java.util.Scanner;

public class C515 {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        StringBuilder sb = new StringBuilder();

        int n = scan.nextInt();
        long a = scan.nextLong();
        int[] freq = new int[10];
        while(a > 0) {
            int digit = (int) (a % 10);
            a /= 10;

            switch(digit) {
                case 0:
                case 1:
                    freq[0]++;
                    break;
                case 2:
                    freq[2]++;
                    break;
                case 3:
                    freq[3]++;
                    break;
                case 4:
                    freq[3]++;
                    freq[2] += 2;
                    break;
                case 5:
                    freq[5]++;
                    break;
                case 6:
                    freq[3]++;
                    freq[5]++;
                    break;
                case 7:
                    freq[7]++;
                    break;
                case 8:
                    freq[7]++;
                    freq[2] += 3;
                    break;
                default :
                    freq[7]++;
                    freq[3] += 2;
                    freq[2]++;
            }
        }
        for(int i=9;i>0;i--) {
            if(freq[i] > 0) {
                for(int j=0;j<freq[i];j++) {
                    sb.append(i);
                }
            }
        }
        System.out.print(sb);
    }
}
