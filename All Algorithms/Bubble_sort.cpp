#include <bits/stdc++.h>
using namespace std;

void bubble_sort(vector<int>&arr,int n){
    int flag=0;
    for(int i=0;i<n-1;i++){
        flag=0;
        for(int j=0;j<n-1-i;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
                flag=1;
            }
        }
        if(flag==0)break;
    }
}

void print_array(vector<int>a,int n){
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    int n;
    cin>>n;
    vector<int>arr;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        arr.push_back(x);
    }
    cout<<"Unsorted Array : ";
    print_array(arr,n);
    bubble_sort(arr,n);
    cout<<"Sorted Array : ";
    print_array(arr,n);
    return 0;
    
}
