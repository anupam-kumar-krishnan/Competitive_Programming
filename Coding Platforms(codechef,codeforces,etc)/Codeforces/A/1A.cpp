#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using lld = long double;
using ii = pair<ll,ll>;

const ll mod = 1e9+7;
// const ll mod = 998244353;

#define endl "\n"
#define pb push_back
#define F first
#define S second
#define MP make_pair
#define len(x) ((ll)((x).size()))
#define rep(i,x) for(ll i=0;i<(x);i++)
#define all(x) (x).begin(),(x).end()

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
uniform_int_distribution<int> dist(1, (int) 2e9);
/*cout<<dist(rng)<<endl;*/

inline ll mul(ll x,ll y){
    x%=mod;y%=mod;
    x+=mod;y+=mod;
    return x*y %mod;
}

inline ll add(ll x,ll y){
    x%=mod;y%=mod;
    x+=mod;y+=mod;
    return (x+y) %mod;
}

inline ll power(ll x,ll y){
    x%=mod;
    ll res=1;
    while(y){
        if(y&1)
            res=res*x %mod;
        x=x*x %mod;
        y/=2;
    }
    return res;
}

// #define M_TESTCASE

void solve(){
    ll n,m,a;
    cin>>n>>m>>a;
    cout<<(n+a-1)/a*((m+a-1)/a)<<endl;
    return ;    
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        // freopen("output.txt","w",stdout);
    #endif
    int t=1;
    #ifdef M_TESTCASE
    cin>>t;
    #endif        
    int i=0;
    // string s;getline(cin,s);
    while(++i<=t){
        // cout<<"Case #"<<i<<": ";
        solve();
    }
    return 0;
}
