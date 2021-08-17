#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        void sort012(int nums[],int n){
            int lo = 0;
            int hi = n-1;
            int mid = 0;
            
            while(mid<=hi){
                switch(nums[mid]){
                    case 0:
                        swap(nums[lo++],nums[mid++]);
                        break;
                    case 1:
                        mid++;
                        break;
                    case 2:
                        swap(nums[mid],nums[hi--]);
                        break;
                    
                }
            }
        }
};





int main()
{
    int t;
    cin>>t;
    
    while(t--){
        int n;
            cin>>n;
        
        int arr[n];
        
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }   
        Solution ob;
        ob.sort012(arr,n);
        
        for(int i=0;i<n;i++)
            cout<<arr[i]<<" ";
            
        cout<<endl;
    }
}
