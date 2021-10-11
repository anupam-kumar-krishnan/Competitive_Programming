/*
Problem Statement: 
Find the largest rectangular area possible in a given histogram where the largest rectangle can be made of a number of contiguous bars. For simplicity, assume that all bars have the same width and the width is 1 unit, there will be N bars height of each bar will be given by the array arr.
Example 1:

Input:
N = 7
arr[] = {6,2,5,4,5,1,6}
Output: 12
*/




#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
class Solution
{
    vector<ll> nextSmallestToLeft(ll arr[],int n){
        // int n=arr.size();
    stack<ll> s;
    s.push(n-1);
    vector<ll> res(n);
    for(int i=n-2;i>=0;i--){
       while(!s.empty() && arr[i]<arr[s.top()]){
           res[s.top()]=i;
           s.pop();
       }
        s.push(i);
    }
    while(!s.empty()){
        res[s.top()]=-1;
        s.pop();
    }
    return res;
    }
    vector<ll> nextSmallestToRight(ll arr[],int n){
        stack<ll> s;
    s.push(0);
    vector<ll> res(n);
    for(int i=1;i<n;i++){
       while(!s.empty() && arr[i]<arr[s.top()]){
           res[s.top()]=i;
           s.pop();
       }
        s.push(i);
    }
    while(!s.empty()){
        res[s.top()]=n;
        s.pop();
    }
        return res;
    }
    public:
    //Function to find largest rectangular area possible in a given histogram.
    long long getMaxArea(long long arr[], int n)
    {
        auto left=nextSmallestToLeft(arr,n);
        auto right=nextSmallestToRight(arr,n);
        for(int i=0;i<n;i++) 
         if(right[i]==-1)
            right[i]=n;
        vector<ll> res(n);
        ll maxm=LLONG_MIN;
        for(int i=0;i<n;i++){
            int width=right[i]-left[i]-1;
            res[i]=arr[i]*width;
            maxm=max(res[i],maxm);
        }
        return maxm;
    }
};
int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.getMaxArea(arr, n)<<endl;    
    }
	return 0;
}
