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
        v(string) v1;
        set<string> s1;
        f(i,0,n,1)
        {
            string temp;
            cin>>temp;
            v1.pb(temp);
            s1.insert(temp);
        }
        v(ll) ans;
        f(i,0,n,1)
        {
            string s=v1[i];
            ll f=0;
            f(j,0,s.length()-1,1)
            {
                string st1=s.substr(0,j+1);
                string st2=s.substr(j+1,s.length()-(j+1));
                if(s1.find(st1)!=s1.end()&&s1.find(st2)!=s1.end())
                {
                    f=1;
                }
            }
            ans.pb(f);
        }
        f(i,0,n,1)
        cout<<ans[i];
        cout<<"\n";
    }
    return 0;
}
