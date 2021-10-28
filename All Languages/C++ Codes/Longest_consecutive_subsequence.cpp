#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
  public:
    // arr[] : the input array
    // N : size of the array arr[]
    
    //Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int arr[], int N)
    {
      map<int,int> mp;
        for(int i=0;i<N;i++){
            mp[arr[i]]++;
        }
        vector<int> ans;
        for(auto it: mp){
            ans.push_back(it.first);
        }
        int ans1=1;
        int count=1;
        for(int i=1;i<ans.size();i++){
            if(ans[i]==ans[i-1]+1){
                count++;
                ans1=max(ans1,count);
            }else{
                count=1;
            }
        }
        return ans1;
    }
};

// { Driver Code Starts.
 
// Driver program
int main()
{
 int  t,n,i,a[100001];
 cin>>t;
 while(t--)
 {
  cin>>n;
  for(i=0;i<n;i++)
  cin>>a[i];
  Solution obj;
  cout<<obj.findLongestConseqSubseq(a, n)<<endl;
 }
      
    return 0;
}  // } Driver Code Ends
