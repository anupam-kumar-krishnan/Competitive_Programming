#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:
    //Function to find minimum number of attempts needed in 
    //order to find the critical floor.
    int eggDrop(int n, int k) 
    {
        // your code here
        int i,j;
        int d[n+1][k+1];
        for(i=1;i<=n;i++)
        {
            d[i][1]=1;
            d[i][0]=0;
        }
        int r;
        for(j=1;j<=k;j++)
        d[1][j]=j;
        for(i=2;i<=n;i++)
        {
            for(j=2;j<=k;j++)
            {
                d[i][j]=INT_MAX;
                for(int x=1;x<=j;x++)
                {
                    r=1+max(d[i-1][x-1],d[i][j-x]);
                    if(r<d[i][j])
                    d[i][j]=r;
                }
            }
        }
        return d[n][k];
    }
};

// { Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking eggs and floors count
        int n, k;
        cin>>n>>k;
        Solution ob;
        //calling function eggDrop()
        cout<<ob.eggDrop(n, k)<<endl;
    }
    return 0;
}
  // } Driver Code Ends