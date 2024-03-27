#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define v(T) vector<T>
#define f(i,l,u,a) for(ll i=l;i<u;i+=a)
#define rf(i,u,l,s) for(ll i=u;i>=l;i-=s)
#define pb push_back
#define sort(v) sort(v.begin(),v.end())
#define vcin(v,n) f(i,0,n,1){ll x;cin>>x;v.pb(x);}
const ll M=1e9+7;
     
      
long long lcm(long long a,long long b){
return (a*b)/__gcd(a,b);
}
     
long long reversenum(long long n){
ll reverse=0;
while(n>0){
ll d=n%10;
reverse=reverse*10+d;
n/=10;
}
return reverse;
}
 
bool isPowOf2(ll n){
if(n&(n-1))
return false;
return true;
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n,q;
    cin>>n>>q;
    v(ll) v1;
    vcin(v1,n);
    sort(v1);
    v(ll) s;
    ll sum=0;
    f(i,0,n,1)
    sum+=v1[i];
    s.pb(sum);
    f(i,0,n-1,1)
    {
        sum-=v1[i];
        s.pb(sum);
    }
    while(q--)
    {
        ll x,y;
        cin>>x>>y;
        if(x==y)
        cout<<s[n-x]<<"\n";
        else
        cout<<s[n-x]-s[n-x+y]<<"\n";
    }
    return 0;
}
