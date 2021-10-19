#include<bits/stdc++.h>
using  namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        int c=0,j,i,k=0;
        int n=s.length();
        for(i=0;i<n;i++)
        {
            if(s[i]!='0')
            k=1;
            
        }
        if(k==0)
        {
            cout<<1<<"\n";
            continue;
        }
        for(int i=0;i<n-1;i++)
        {
            if(s[i]=='0'&&s[i+1]=='1')
            c++;
            
        }
        if(s[n-1]=='0')
        c++;
        if(c<2)
        {
            cout<<c<<"\n";
            continue;
        }
        cout<<2<<"\n";
    }
}
