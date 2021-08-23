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
----------------------------------------
                 Method 2
----------------------------------------
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    
    int a[n],i;
    for(int i=0;i<n;++i)
        cin>>a[i];
        
    int c0=0,c1=0,c2=0;
    for(i=0;i<n;++i)
    {
        if(a[i]==0)
            c0++;
        else if(a[i]==1)
            c1++;
        else
            c2++;
    }
    for(i=0;i<c0;++i)
        a[i]=0;
    
    for(i=c0;i<c0+c1;++i)
        a[i]=1;
        
    while(c2--)
    {
        a[i++]=2;
    }
    
    for(i=0;i<n;++i)
        cout<<a[i]<<" ";
}
