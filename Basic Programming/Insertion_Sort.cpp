// Time Complexity = O(n^2)
// Space Complexity = O(1)

/*
// Time Complexity = O(n^2)
// Space Complexity = O(1)

/*
Insertion Sort
--> Similar to playing cards
--> Insert cards in its correct position in sorted part
--> Insertion Sort is a sorting algorithm that places the input element at its suitable place in each pass.
*/

#include <iostream>
using namespace std;

void insertion_sort(int a[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int current = a[i];
        int prev = i - 1;
        // loop to find the right index where the element current should be placed
        while (prev >= 0 and a[prev] > current)
        {
            a[prev + 1] = a[prev];
            prev--;
        }
        a[prev + 1] = current;
    }
}

int main()
{
    system("CLS");
    int arr[] = {-12, 5, 8, 3, 0, 9, -50, -3, -2, -1};
    int n = sizeof(arr) / sizeof(int);
    insertion_sort(arr, n);
    for (auto x : arr)
        cout << x << " , ";

    return 0;
}--> Similar to playing cards
--> Insert cards in its correct position in sorted part
--> Insertion Sort is a sorting algorithm that places the input element at its suitable place in each pass.
*/

#include <iostream>
using namespace std;

void insertion_sort(int a[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int current = a[i];
        int prev = i - 1;
        // loop to find the right index where the element current should be placed
        while (prev >= 0 and a[prev] > current)
        {
            a[prev + 1] = a[prev];
            prev--;
        }
        a[prev + 1] = current;
    }
}

int main()
{
    system("CLS");
    int arr[] = {-12, 5, 8, 3, 0, 9, -50, -3, -2, -1};
    int n = sizeof(arr) / sizeof(int);
    insertion_sort(arr, n);
    for (auto x : arr)
        cout << x << " , ";

    return 0;
}
