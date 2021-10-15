#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {   
        string s;
         cin>>s;
       long long int c1=0,r1=0,c2=0,i,j;
       
        
       long long int l=s.length();
        for(i=l-1;i>=0;i--)
        {
            if(s[i]=='0')
            break;
            c1++;
        }
        for(j=i-1;j>=0;j--)
        {
            if(s[j]=='0'||s[j]=='5')
            break;
            c1++;
        }
       r1=c1;
        for(i=l-1;i>=0;i--)
        {
            if(s[i]=='5')
            break;
            c2++;
        }
        for(j=i-1;j>=0;j--)
        {
            if(s[j]=='2'||s[j]=='7')
            break;
            c2++;
        }
        if(s=="0")
        cout<<0<<"\n";
        else
        {
            if(r1>c2)
            r1=c2;
            cout<<r1<<"\n";
        }

    }
}
