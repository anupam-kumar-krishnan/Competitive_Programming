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
    ll n;
    cin>>n;
    v(ll) v1;
    vcin(v1,n)
    f(i,0,n,1)
    {
        double d=(double)v1[i];
        ll s=sqrt(d);
        ll s1=sqrt((double)s);
        if(s*s!=v1[i]||v1[i]==1)
        cout<<"NO\n";
        else
        {
            ll f=0;
            f(i,2,s1+1,1)
            {
                if(s%i==0)
                f=1;
            }
            if(f==1)
            cout<<"NO\n";
            else
            cout<<"YES\n";
        }
    }
    return 0;
}
