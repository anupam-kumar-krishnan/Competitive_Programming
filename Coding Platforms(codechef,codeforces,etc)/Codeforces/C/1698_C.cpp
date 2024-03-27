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
const ll N=1e6+10;
     
      
long long lcm(ll a,ll b){
return (a*b)/__gcd(a,b);
}
     
long long reversenum(ll n){
ll reverse=0;
while(n>0){
ll d=n%10;
reverse=reverse*10+d;
n/=10;
}
return reverse;
}
  
long long binExp(ll a,ll b){
ll ans=1;
while(b){
if(b&1)
ans=ans*a;
a=a*a;
b>>=1;
}
return ans;
}
 
bool isPowOf2(ll n){
if(n&(n-1))
return false;
return true;
}
 
bool isPrime(ll n){
ll p=1;
if(n==1)
return 0;
if(n==2)
return 1;
for(ll i=2;i*i<=n;i++){
if(n%i==0){
p=0;
break;
}
}
if(p==1)
return 1;
else
return 0;
}
 
ll fact[N];
void factorial(){
fact[0]=1;
f(i,1,N,1)
fact[i]=(fact[i-1]*i)%M;
return;
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        v(ll) v1,p,m;
        ll c=0;
        f(i,0,n,1)
        {
            ll x;
            cin>>x;
            if(x>0)
            p.pb(x);
            if(x<0)
            m.pb(x);
            if(x==0)
            c+=1;
            if(x!=0)
            v1.pb(x);
            else if(c<4)
            v1.pb(x);
        }
        ll f=1;
        if(p.size()>2||m.size()>2)
        f=0;
        else{
        f(i,0,v1.size()-2,1)
        {
            f(j,i+1,v1.size()-1,1)
            {
                f(k,j+1,v1.size(),1)
                {
                    ll sum=v1[i]+v1[j]+v1[k];
                    ll f1=0;
                    f(l,0,v1.size(),1)
                    {
                        if(v1[l]==sum)
                        f1=1;
                    }
                    if(f1==0)
                    {
                        f=0;
                        break;
                    }
                }
                if(f==0)
                break;
            }
            if(f==0)
            break;
        }
        }
        if(f)
        cout<<"YES\n";
        else
        cout<<"NO\n";
    }
    return 0;
}
