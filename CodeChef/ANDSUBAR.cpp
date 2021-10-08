#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, count = 0, x,i,p,y,k;
        cin >> n;
        p=log2(n);
        k=pow(2,p);
        x=k/2;
        y=n-k+1;
        if(x>y)
        cout<<x<<endl;
        else
        cout<<y<<endl;
       
    }
}
