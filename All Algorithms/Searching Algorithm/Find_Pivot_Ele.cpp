#include<bits/stdc++.h>
using namespace std;

int getPivot(int arr[], int n){
    int s = 0;
    int e = n-1;
    int mid = s + (e - s)/2;

    while(s<e){
        if(arr[mid]>=arr[0]){
            s = mid+1;
        }
        else{
            e = mid;
        }
        mid = s + (e - s)/2;
    }
    return s;
}

int main(){
    int arr[]={8,10,17,1,3};
    int size = sizeof(arr)/sizeof(int);
    cout<<"Pivot element is present at index: "<<getPivot(arr,size)<<endl;
    return 0;
}