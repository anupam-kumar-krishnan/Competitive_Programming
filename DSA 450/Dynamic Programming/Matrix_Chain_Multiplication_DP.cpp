#include <bits/stdc++.h>
using namespace std;

/*Following is the implementation of the Matrix Chain Multiplication problem 
  using Dynamic Programming */

class Solution{
public:
    int dp[102][102];
    int fun(int a[],int n,int i,int j)
    {
        if(i>=j)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int mn=INT_MAX;
        for(int k=i;k<j;k++)
        {
            int temp=fun(a,n,i,k)+fun(a,n,k+1,j)+a[i-1]*a[k]*a[j];
            mn=min(mn,temp);
        }
        return dp[i][j]=mn;
    }
    int matrixMultiplication(int N, int arr[])
    {
        memset(dp,-1,sizeof(dp));
        return fun(arr,N,1,N-1);
    }
};

int main(){
    
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.matrixMultiplication(N, arr)<<endl;

    return 0;
}  