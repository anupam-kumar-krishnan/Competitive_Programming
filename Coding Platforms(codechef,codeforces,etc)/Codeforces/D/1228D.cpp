#include <bits/stdc++.h>
#define ll long long
#define int long long
#define ld long double
#define vi vector<ll>
#define pi pair<ll, ll>
#define vpi vector<pi>
#define endl '\n'
using namespace std;
#define all(x) begin(x), end(x)
unsigned long long power(unsigned long long x,
                         ll y, ll p)
{
    unsigned long long res = 1; // Initialize result

    x = x % p; // Update x if it is more than or
    // equal to p

    while (y > 0)
    {

        // If y is odd, multiply x with result
        if (y & 1)
            res = (res * x) % p;

        // y must be even now
        y = y >> 1; // y = y/2
        x = (x * x) % p;
    }
    return res;
}

// Returns n^(-1) mod p
unsigned long long modInverse(unsigned long long n,
                              int p)
{
    return power(n, p - 2, p);
}

// Returns nCr % p using Fermat's little
// theorem.
vector<ll> fac;
void initfact(int n, ll p = pow(10, 9) + 7)
{
    fac.resize(n + 1);
    fac[0] = 1;
    for (ll i = 1; i <= n; i++)
        fac[i] = (fac[i - 1] * i) % p;
}
unsigned long long nCrModPFermat(unsigned long long n,
                                 int r, int p)
{
    // If n<r, then nCr should return 0
    if (n < r)
        return 0;
    // Base case
    if (n == 0 && r == 0)
        return 1;
    if (n == 0)
        return 0;
    if (r == 0)
        return 1;

    // Fill factorial array so that we
    // can find all factorial of r, n
    // and n-r

    return (fac[n] * modInverse(fac[r], p) % p * modInverse(fac[n - r], p) % p) % p;
}

ll countSetBits(ll n)
{
    ll count = 0;
    while (n)
    {
        count += n & 1;
        n >>= 1;
    }
    return count;
}

struct dsu
{
    vector<ll> data;
    int components = 0;

    dsu(int n = -1)
    {
        if (n >= 0)
            init(n);
    }

    void init(int n)
    {
        data.assign(n + 1, -1);
        components = n;
    }

    int find(int x)
    {
        return data[x] < 0 ? x : data[x] = find(data[x]);
    }

    int get_size(int x)
    {
        return -data[find(x)];
    }

    bool unite(int x, int y)
    {
        x = find(x);
        y = find(y);

        if (x == y)
            return false;

        if (-data[x] < -data[y])
            swap(x, y);
        data[x] += data[y];
        data[y] = x;
        components--;
        return true;
    }
};

ll setBitNumber(ll n)
{
    if (n == 0)
        return 0;

    ll msb = 0;
    n = n / 2;
    while (n != 0)
    {
        n = n / 2;
        msb++;
    }

    return (1 << msb);
}
ll countBits(ll number)
{

    // log function in base 2
    // take only integer part
    return (ll)log2(number) + 1;
}
ll sum(ll k)
{
    return k * (k + 1) / 2;
}
ll mul(ll a, ll b, ll mod = 998244353)
{
    return ((a % mod) * (b % mod)) % mod;
}
int kmp(string s)
{
    string chk = s;
    vector<int> lps(s.size(), 0);

    for (int i = 1; i < (int)lps.size(); ++i)
    {
        int prev_idx = lps[i - 1];

        while (prev_idx > 0 && s[i] != s[prev_idx])
        {
            prev_idx = lps[prev_idx - 1];
        }

        lps[i] = prev_idx + (s[i] == s[prev_idx] ? 1 : 0);
    }

    return lps[lps.size() - 1];
}
ll p = pow(10, 9) + 7;
ll mod2 = 998244353;

struct FenwickTree
{
    vector<int> bit; // binary indexed tree
    int n;

    FenwickTree(int n)
    {
        this->n = n;
        bit.assign(n, 0);
    }

    FenwickTree(vector<int> a) : FenwickTree(a.size())
    {
        for (size_t i = 0; i < a.size(); i++)
            add(i, a[i]);
    }

    int sum(int r)
    {
        int ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ret += bit[r];
        return ret;
    }

    int sum(int l, int r)
    {
        return sum(r) - sum(l - 1);
    }

    void add(int idx, int delta)
    {
        for (; idx < n; idx = idx | (idx + 1))
            bit[idx] += delta;
    }
};


void vscode()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
}
int CeilIndex(std::vector<ll>& v, int l, int r, int key)
{
    while (r - l > 1) {
        int m = l + (r - l) / 2;
        if (v[m] >= key)
            r = m;
        else
            l = m;
    }
 
    return r;
}
 
int LongestIncreasingSubsequenceLength(std::vector<ll>& v)
{
    if (v.size() == 0)
        return 0;
 
    std::vector<int> tail(v.size(), 0);
    int length = 1; // always points empty slot in tail
 
    tail[0] = v[0];
    for (size_t i = 1; i < v.size(); i++) {
 
        // new smallest value
        if (v[i] < tail[0])
            tail[0] = v[i];
 
        // v[i] extends largest subsequence
        else if (v[i] > tail[length - 1])
            tail[length++] = v[i];
 
        // v[i] will become end candidate of an existing
        // subsequence or Throw away larger elements in all
        // LIS, to make room for upcoming greater elements
        // than v[i] (and also, v[i] would have already
        // appeared in one of LIS, identify the location
        // and replace it)
        else
            tail[CeilIndex(tail, -1, length - 1, v[i])] = v[i];
    }
 
    return length;
}
vector<vector<ll>>g(300001);
vector<ll>vis(300001);
ll n;
int flag;
set<ll> check(int i)
{
   
    set<ll>s;
    for(int i=1;i<=n;i++)
    s.insert(i);
    set<ll>sett;
    for(auto it:g[i])
    {

        s.erase(it);
    }

    for(auto it:s)
    {
        if(vis[it])
        {
            flag=1;
        }
        sett.insert(it);
        vis[it]=1;
    }
    vis[i]=1;
    return sett;
}
void solve()
{
    cin>>n;
    
    for(int i=1;i<=n;i++)
    {
        g[i].clear();
        vis[i]=0;
    }
    ll m;cin>>m;
    for(int i=0;i<m;i++)
    {
        ll a,b;cin>>a>>b;
        g[a].push_back(b);swap(a,b);
        g[a].push_back(b);swap(a,b);
    }
    flag=0;
    set<ll>s1,s2,s3;
    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        if(cnt==3 && vis[i]==0)
        {
            cout<<-1<<endl;
            return;
        }
        if(vis[i]==0)
        {
            flag=0;
            if(cnt==0)
            s1=check(i);
            else if(cnt==1)
            s2=check(i);
            else
            s3=check(i);
            if(flag)
            {
                cout<<-1<<endl;
                return;
            }
            cnt++;
        }
    }
    if(s1.size()==0 || s2.size()==0 || s3.size()==0)
    {
        cout<<-1<<endl;
        return;
    }
    // cout<<s1.size()<<" "<<s2.size()<<" "<<s3.size()<<endl;
    set<ll>cc;
    for(int i=1;i<=n;i++)
    {
        cc.insert(i);
    }
    for(auto it:s1)
    {
        if((int)g[it].size()!=(int)s2.size()+(int)s3.size())
        {
            cout<<-1<<endl;
            return;
        }
        for(auto child:g[it])
        {
            if(s1.find(child)!=s1.end())
            {
                cout<<-1<<endl;return;
            }
        }
    }
    for(auto it:s2)
    {
        if((int)g[it].size()!=(int)s3.size()+(int)s1.size())
        {
            cout<<-1<<endl;
            return;
        }
        for(auto child:g[it])
        {
            if(s2.find(child)!=s2.end())
            {
                cout<<-1<<endl;return;
            }
        }
    }
    for(auto it:s3)
    {
        if((int)g[it].size()!=(int)s2.size()+(int)s1.size())
        {
            cout<<-1<<endl;
            return;
        }
        for(auto child:g[it])
        {
            if(s3.find(child)!=s3.end())
            {
                cout<<-1<<endl;return;
            }
        }
    }
    vector<ll>ans(n+1);
    for(auto it:s1)
    ans[it]=1;
    for(auto it:s2)
    ans[it]=2;
    for(auto it:s3)
    ans[it]=3;
    for(int i=1;i<=n;i++)
    cout<<ans[i]<<" ";
}   



signed main()
{

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout << fixed;

    int t = 1;
    // vscode();

    // cin>>t;
    for (int i = 1; i <= t; i++)
    {
        // cout<<"Case #"<<i<<":"<<" ";
        solve();
    }
    return 0;
}

//
