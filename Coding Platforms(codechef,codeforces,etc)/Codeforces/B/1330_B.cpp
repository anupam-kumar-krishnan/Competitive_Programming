#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define v(T) vector<T>
#define f(i,l,u,a) for(ll i=l;i<u;i+=a)
#define rf(i,u,l,s) for(ll i=u;i>=l;i-=s)
#define pb push_back
#define sortt(v) sort(v.begin(),v.end())
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
        v(ll) v1;
        vcin(v1,n);
        set<ll> s1,s2,s3,s4;
        ll f1=0,f2=0;
        f(i,0,n,1)
        {
            if(f1==0&&s1.find(v1[i])==s1.end())
            s1.insert(v1[i]);
            else if(f1==0&&s1.find(v1[i])!=s1.end())
            {
            f1=1;
            s2.insert(v1[i]);
            }
            if(f1==1)
            s2.insert(v1[i]);
        }
        rf(i,n-1,0,1)
        {
            if(f2==0&&s3.find(v1[i])==s3.end())
            s3.insert(v1[i]);
            else if(f2==0&&s1.find(v1[i])!=s1.end())
            {
                f2=1;
                s4.insert(v1[i]);
            }
            if(f2==1)
            {
                s4.insert(v1[i]);
            }
        }
        ll c1=1,c2=1;
        ll i1=1,i2=1;
        for(auto val:s1)
        {
            if(val!=i1)
            c1=0;
            else
            i1+=1;
        }
        for(auto val:s2)
        {
            if(val!=i2)
            c1=0;
            else
            i2+=1;
        }
        if(s1.size()+s2.size()!=n)
        c1=0;
        i1=1,i2=1;
        for(auto val:s3)
        {
            if(val!=i1)
            c2=0;
            else
            i1+=1;
        }
        for(auto val:s4)
        {
            if(val!=i2)
            c2=0;
            else
            i2+=1;
        }
        if(s3.size()+s4.size()!=n)
        c2=0;
        if(s1==(s4)&&s2==(s3))
        c2=0;
        cout<<c1+c2<<"\n";
        if(c1!=0)
        {
            cout<<s1.size()<<" "<<s2.size()<<"\n";
        }
        if(c2!=0)
        cout<<s4.size()<<" "<<s3.size()<<"\n";
    }
    return 0;
}
