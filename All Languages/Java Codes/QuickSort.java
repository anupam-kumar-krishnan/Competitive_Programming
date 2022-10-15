
// Java program to demonstrate working of Arrays.toString()
import java.util.*;

class QuickSort{
    static void Quick(int arr[],int low,int high){
        if (low>=high) {
            return;
        }
        int start=low;
        int end=high;
        int mid=(start)+(end-start)/2;
        int pivot=arr[mid];
        while (start<=end) {
            while (arr[start]<pivot) {
                start++;
            }
            while (arr[end]>pivot) {
                end--;
            }
            if(start<=end){
                int temp=arr[start];
                arr[start]=arr[end];
                arr[end]=temp;
                start++;
                end--;
                
            }
        }
        Quick(arr,low,end);
        Quick(arr,start,high);
    }
    public static void main(String[] args) {
       int arr[]=new int[10];
       for (int i = 0; i < arr.length; i++) {
        arr[i]=10-i;
       }
       Quick(arr,0,9);
       System.out.println(Arrays.toString(arr));
    }

    
}