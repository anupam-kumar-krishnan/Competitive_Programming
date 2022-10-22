// C++ program for insertion sort
 
#include <bits/stdc++.h>
using namespace std;
 
// Function to sort an array using insertion sort
void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}
 
// A utility function to print an array of size n
void printArray(int arr[], int n)
{
  int i;
    for (i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    int arr[] = { 10, 11, 15, 25, 4 };
    int N = sizeof(arr) / sizeof(arr[0]);
 
    insertionSort(arr, N);
    printArray(arr, N);
 
    return 0;
}
