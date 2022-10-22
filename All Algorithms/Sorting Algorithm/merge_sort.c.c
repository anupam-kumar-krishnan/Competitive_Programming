
#include<stdio.h>
#include<stdlib.h>

void merge(int arr[], int l, int m, int r){
    int n1 = m - l + 1;
    int n2 = r - m;
    int left[n1];
    int right[n2];
    for( int i = 0; i < n1; i++){
        left[i] = arr[l + i];
    }
    for( int i = 0; i < n2; i++){
        right[i] = arr[m + 1 + i];
    }
    int i = 0;
    int j = 0;
    int k = l;
    while(i < n1 && j <n2){
        if(left[i] <= right[j]){
            arr[k] = left[i];
            i++;
            k++;
        }
        else{
            arr[k] = right[j];
            j++;
            k++;
        }
    }
    while(i < n1){
        arr[k] = left[i];
        i++;
        k++;
    }
    while(j < n2){
        arr[k] = right[j];
        j++;
        k++;
    }
    return;
}

void mergeSort(int arr[], int l, int r){
    if(r > l){
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
    return;
}

int main(){
    int n = 15;
    int arr[n];
    int randArray[n],i;
    for(int i=0;i<n;i++)
      arr[i]=rand()%100;
    mergeSort(arr, 0, n - 1);
    printf("The sorted array is : \n");
    for( i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    return 0;
}

