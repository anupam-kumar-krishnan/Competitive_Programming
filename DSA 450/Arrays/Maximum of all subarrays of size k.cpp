// problem link--https://practice.geeksforgeeks.org/problems/maximum-of-all-subarrays-of-size-k3101/1

#include<iostream>
#include<vector>
#include<deque>
using namespace std;

class Solution
{
  public:
    //Function to find maximum of each subarray of size k.
    vector <int> max_of_subarrays(int *arr, int n, int k)
    {
        // your code here
        deque<int>dq;
        vector<int>ans;
        
        
        for(int i=0;i<k;i++){
            
            while( !dq.empty()  &&  dq.back()<arr[i] ){
                dq.pop_back();
            }
            dq.push_back(arr[i]);
        }
        
        ans.push_back(dq.front());
        
        for(int i=k;i<n;i++){
            
            if(dq.front()==arr[i-k]){
                   dq.pop_front();
            }
            
        while( !dq.empty()  && dq.back()<arr[i] ){
                dq.pop_back();
                 }
           
            dq.push_back(arr[i]);
            ans.push_back(dq.front());
       }
        return ans;
    }
};

int main(){
    int t;
    cin>>t;
     while(t--){
        int n,k;
        cin>>n>>k;

        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];

            Solution obj;

            vector<int> res=obj.max_of_subarrays(arr,n,k);

            for (int i = 0; i < res.size(); i++)
               cout<<res[i]<<" ";
               cout<<endl;
         
     }
     return 0;
}