#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
        int doUnions(int a[],int n,int b[],int m){
            set<int> s;
            for(int i=0;i<n;i++)
       	    	s.insert(a[i]);

            for(int i=0;i<m;i++)
             	s.insert(b[i]);

     return s.size() ;
   }
};

int main()
{
    int n,m;
    cin>>n>>m;

    int a[n],b[m];
    for(int i=0;i<n;i++)
        cin>>a[n];

    for(int j=0;j<m;j++)
        cin>>b[j];
    
    Solution ob;
    cout << ob.doUnions(a,n,b,m);
}
