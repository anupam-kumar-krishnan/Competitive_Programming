// 2 4 1 3 5
// 1 4 2 3 5 - 1 iteration
// 1 2 4 3 5 - 2 iteration
// 1 2 3 4 5 - 3 iteration

#include <bits/stdc++.h>
using namespace std;

int getInvCount(int arr[], int n)
{
    int inv_count = 0;
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (arr[i] > arr[j])
                inv_count++;

    return inv_count;
}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
      cin>>arr[i];
    cout << " Number of inversions are "
         << getInvCount(arr, n);
    return 0;
}
