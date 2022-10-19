/*
  Bubble Sort Algorithm in C++

  Time Complexity : O(n^2)
  Space Complexity : O(1)

  (Sorting in increasing order)
  -> Swapping the two elements if right element is greater than left element (repeat until gets a sorted array i.e. n-1 times).
  -> After each traversal we get one element in its right most correct position.
*/

#include<iostream>
using namespace std;

// function to swap two elements
void swap(int *x, int *y) {
  int temp = *x;
  *x = *y;
  *y = temp;
}

// function to print array
void printArr(int arr[], int n) {
  for(int i=0; i<n; i++) {
    cout<<arr[i]<<" ";
  }
  cout<<endl;
}

// function for Bubble Sort
int *bubbleSort(int arr[], int n) {
  for(int i=1; i<n; i++) {
    for(int j=0; j<n-i; j++) {
      if(arr[j] > arr[j+1]) {
        swap(arr[j], arr[j+1]);
      }
    }
  }
  return arr;
}

int main() {
  int unsortedArr[7] = {3, 7, 2, 8, 1, 0, 9};
  int size = sizeof(unsortedArr)/sizeof(unsortedArr[0]);

  cout<<"Unsorted Array : ";
  printArr(unsortedArr, size);

  int *sortedArr = bubbleSort(unsortedArr, size);
  cout<<"Sorted Array : ";
  printArr(sortedArr, size);

  return 0;
}
