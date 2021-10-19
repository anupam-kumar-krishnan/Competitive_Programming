// https://codeforces.com/problemset/problem/178/F3
// also works for F1 and F2 
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <math.h>
#include <string>
#include <cstring>
#include <set>
#include <map>
#include <unordered_map>
#include <assert.h>
#include <array>
#include <random>
#include <chrono>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<int, pair<int, int>> piii;
typedef vector<int> vi;
typedef vector<pii> vii;

int dadsadasda;

#define ri(a) dadsadasda=scanf("%d", &a)
#define rii(a,b) dadsadasda=scanf("%d %d", &a, &b)
#define riii(a,b,c) dadsadasda=scanf("%d %d %d", &a, &b, &c)
#define rl(a) dadsadasda=scanf("%lld", &a)
#define rll(a,b) dadsadasda=scanf("%lld %lld", &a, &b)
#define FOR(i,n,m) for(int i=n; i<m; i++)
#define ROF(i,n,m) for(int i=n; i>m; i--)
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define F first
#define S second
#define ALL(s) s.begin(),s.end()
#define SZ(s) (int)s.size()

const int INF = 0x3f3f3f3f;
const ll LLINF = 1e18;
const int MAXN = 2010; // CAMBIAR ESTE
//mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

// GJNM
int N, K;

int T = 1;
int TRIE[MAXN * 500][26];
int SIZ[MAXN * 500];
vi NXT[MAXN * 500];
void insert(const string &s) {
    int u = 0;
    ++SIZ[u];
    for (auto c : s) {
        int v = c - 'a';
        if (TRIE[u][v] == 0) {
            NXT[u].pb(T);
            TRIE[u][v] = T++;
        }
        u = TRIE[u][v];
        ++SIZ[u];
    }
}

vi dfs(int u) {
    if (SZ(NXT[u]) == 0) {
        vi ret(min(K, SIZ[u]) + 1);
        for (int i = 1; i < SZ(ret); ++i)
            ret[i] = (i * i - i) >> 1;
        return ret;
    }
    else {
        int mx = NXT[u][0];
        for (auto nxt : NXT[u]) {
            if (SIZ[nxt] > SIZ[mx])
                mx = nxt;
        }
        auto ret = dfs(mx);
        ret.resize(min(K, SIZ[u]) + 1);
        FOR(i, 1, SZ(ret)) ret[i] = max(ret[i], ret[i - 1]);

        for (auto nxt : NXT[u]) if (nxt != mx) {
                auto aux = dfs(nxt);
                for (int i = SZ(ret) - 1; i >= 0; --i)
                    for (int j = 0; j < SZ(aux) && i + j < SZ(ret); ++j)
                        ret[i + j] = max(ret[i + j], ret[i] + aux[j]);

            }
        if (u != 0)
            for (int i = 1; i < SZ(ret); ++i)
                ret[i] += (i * i - i) >> 1;
        return ret;
    }
}

int main() {
    rii(N, K);
    FOR(i, 0, N) {
        string s; cin >> s;
        insert(s);
    }
    auto ans = dfs(0);
    printf("%d\n", ans[K]);
    return 0;
}
