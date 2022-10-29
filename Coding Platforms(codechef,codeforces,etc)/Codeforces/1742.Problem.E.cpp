#include<bits/stdc++.h>
using namespace std;

#define int long long 
#define pb push_back
#define ld long double
 
#define forl(n) for(int i=0;i<n;i++)
#define vi vector<int>
#define vii vector<vector<int>>
#define ss size()
#define intake(a,n) vector<int> a(n); for(int i=0;i<n;i++) cin>>a[i];
#define print_map(m) for (auto const &pair: m) {cout <<' '<< pair.first <<' '<< pair.second <<endl;}
#define out(a) for(auto i:a) cout<<i<<' '; cout<<endl;
#define out_2d(a)  for(auto i:a){   for(auto j:i)   cout<<j<<' ';   cout<<endl;}
#define sortf(a) sort(a.begin(),a.end())
#define sortr(a) sort(a.rbegin(),a.rend())
#define get_sum(a) accumulate(a.begin(),a.end(),0LL)
#define get_max(a) *max_element(a.begin(),a.end())
#define get_min(a) *min_element(a.begin(),a.end())
#define pno cout<<'N'<<'O'<<endl
#define pys cout<<'Y'<<'E'<<'S'<<endl
#define sz(x) (int)((x).size())
#define ps(x,y) fixed<<setprecision(y)<<x

const int dom = 998244353;
const int N = 200001, inf = 2100000000;
const long long INF = 4000000000000000000LL;

const int mod = 1000000007;
int fac[1000001];
int binaryexp(int a,int b){
	if(b==0)return 1;
	else if((b%2)==0)return binaryexp((a*a)%mod,b/2)%mod;
	else return (a*binaryexp((a*a)%mod,b/2)%mod)%mod;
}	
//int ncr(int a,int b){
//   return (fac[a]*(binaryexp((fac[b] * fac[a-b])%mod,mod-2))%mod)%mod;
//}
int power(int x,int y){
	int res = 1;
    x = x % mod;
    while (y > 0){
        if (y & 1)	res = (res * x) % mod;
        y = y >> 1; 
        x = (x * x) % mod;
    }
    return res;
}
int modInverse(int n){
    return power(n, mod - 2);
}
int ncr(int n,int r){
    if (n < r)	return 0;
    if (r == 0)	return 1;
    int fac[n + 1];
    fac[0] = 1;
    for (int i = 1; i <= n; i++)	fac[i] = (fac[i - 1] * i) % mod;
    return (fac[n] * modInverse(fac[r]) % mod* modInverse(fac[n - r]) % mod)% mod;
}
//string to_bin(int n, int j){
//    string str=""; for(int i=0;i<j;i++){if(n%2==1)str+="1";else str+="0";n/=2;} reverse(str.begin(),str.end()); return str;
//}





void solve(){
    
    int n,q;
    cin>>n>>q;
    
    intake(arr,n);
    vi premax(n);
    premax[0] = arr[0];
    vi prefix(n+1);
    prefix[0] = 0;
    
    for(int i=1;i<=n;i++){
    	prefix[i] = prefix[i-1]+arr[i-1];
    }
    for(int i=1;i<n;i++){
    	premax[i] = max(premax[i-1], arr[i]);
    }
    
    
    while(q--){
    	int temp;
    	cin>>temp;
    	
    	int index = upper_bound(premax.begin(), premax.end(), temp)-premax.begin();
    	
    	cout<<prefix[index]<<' ';
    }
    cout<<endl;
    
}



int32_t main()    
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL); 

    int tt;  
    cin>>tt; 

    while(tt--){
    solve(); 
    }
    return 0;
}
