#include<bits/stdc++.h>
using namespace std;

bool BinarySearch(int arr[], int key, int size){
    int left = 0;
    int right = size-1;
    int mid = left + ((right-left)/2);

    while(left<=right){
        if(arr[mid] == key){
            return true;
        }else{
            if(arr[mid]<key){
                left = mid+1;
            }else{
                right = mid-1;
            }
            mid = left + ((right-left)/2);
        }
    }
    return false;
}

int first(int arr[],int k, int low,int high){
    int ans = -1;
    while(low<=high){
        int mid = low + (high - low) / 2;
        int midVal = arr[mid];
        if(midVal == k){
            ans = mid; 
            high = mid-1;
        }else{
            if(midVal>k){
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
    }
    return ans;
}

int last(int arr[],int k, int low,int high){
    int ans = -1;
    while(low<=high){
        int mid = low + (high - low) / 2; 
        int midVal = arr[mid];
        if(midVal == k){
            ans = mid;
            low = mid+1;
        }else{
            if(midVal>k){
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
    }
    return ans;
}

int occur(int key,int size,int arr[]){
    int begin = first(arr, key, 0 , size-1);
    int end = last(arr, key, 0 , size-1);
    // int begin = first(int arr[], int key, int low,int high)
    return (end - begin + 1);
}

int main(){
    int arr[] = {0 ,0 ,0 ,0};
    int size = sizeof(arr)/sizeof(int);
    if(size == 0){
        cout<<"Array is empty";
        return 0;
    }

    cout<<"Input the element you are searching for ";
    int key;
    cin>>key;

    if(BinarySearch(arr , key, size)){
        int res = occur(key,size,arr);
        cout<<"Total number of occurences of "<<key<<" is "<<res<<endl;
    }
    else{
        cout<<"Element not present in the array"<<endl;
    }
    // int start = first(arr,key,0,size-1);
    // int end = first(arr,key,0,size-1);
    // int res = end - start +1;
    // cout<<res;
    return 0;
}