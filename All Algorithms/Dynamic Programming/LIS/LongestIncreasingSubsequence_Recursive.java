
import java.util.Arrays;
import java.util.Scanner;

public class LIS_Recursive {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        int n = input.nextInt();

        int[] arr = new int[n];

        for(int i=0; i < n; i++){
            arr[i] = input.nextInt();
        }

        int longestIncreasingSubsequence = findLongestIncreasingSubsequence(arr, n);

        System.out.println("Longest Increasing Subsequence: " + longestIncreasingSubsequence);
    }

    private static int findLongestIncreasingSubsequence(int[] arr, int n) {

        int[] lis = new int[n];

        Arrays.fill(lis, 1);

        for(int i=0; i < n; i++){
            for(int j=0; j < i; j++){
                if(arr[j] < arr[i] && lis[j] >= lis[i]){
                    lis[i] = 1 + lis[j];
                }
            }
        }

        int maxLength = 0;

        for (int i=0; i < n; i++){
            if(lis[i] > maxLength) maxLength = lis[i];
        }

        System.out.println("LIS: " + Arrays.toString(lis));

        return maxLength;
    }
}
