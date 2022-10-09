import java.io.*;
import java.util.*;

public class Solution {

    public static void main(String[] args) {
        
        Scanner sc = new Scanner(System.in);
        int len = sc.nextInt();
        int arr[] = new int[len];
        for(int i=0; i<len; i++){
            arr[i] = sc.nextInt();
        }
        
        int count = 0;
        int start = 0, end = 0;
        while(start < len){
            
            
            end++;
            if(sumArr(Arrays.copyOfRange(arr, start, end))<0)count++;
            if(end >= len){
                start++;
                end = start;
            }
           
        }
        System.out.println(count);
    }
    
    public static int sumArr(int[]arr){
        int sum = 0;
        for(int i=0; i<arr.length;i++){
            sum += arr[i];
        }
        return sum;
    }
}
