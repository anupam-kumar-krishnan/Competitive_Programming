/*-----Question Link------*/
http://codeforces.com/contest/365/problem/B
/*------------------------*/

#include<bits/stdc++.h>
#define FAST cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0)
using namespace std;

int main()
{
FAST;
inti(n);
long a[n];
for(int i=0;i<n;i++)
    cin>>a[i];
int t=2,m=2;;
for(int i=2;i<n;i++)
{
    if(a[i]==a[i-1]+a[i-2])
        t++;
    else{
        if(t>m)
        m=t;
        t=2;
    }
}if(t>m)
m=t;
cout<<min(m,n)<<'\n';
return 0;
}
