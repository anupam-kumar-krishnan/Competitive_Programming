// https://codeforces.com/problemset/problem/37/D
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
const int MAXN = 104; // CAMBIAR ESTE
const int MOD = 1e9 + 7;
//mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

// GJNM
int BIN[MAXN * 10][MAXN];
ll pick(int n, int k) {
    if (BIN[n][k] != 0)
        return BIN[n][k];
    if (k == 0 || k == n)
        return BIN[n][k] = 1;
    int ret = pick(n - 1, k) + pick(n - 1, k - 1);
    if (ret >= MOD)
        ret -= MOD;
    return BIN[n][k] = ret;
}

int N, X[MAXN], Y[MAXN];
int S[MAXN];
ll DP[MAXN][MAXN * 10];
ll f(int p, int r) {
    // printf("%d %d\n", p, r);
    if (DP[p][r] != -1)
        return DP[p][r];
    if (p == N) {
        // printf("\t%d %d %d\n", p, r, r == 0);
        return DP[p][r] = r == 0;
    }
    DP[p][r] = 0;
    int new_r = r + X[p];
    FOR(i, 0, min(Y[p], new_r) + 1) {
        ll aux = (pick(S[p], X[p]) * pick(new_r, i)) % MOD;
        DP[p][r] = (DP[p][r] + aux * f(p + 1, new_r - i)) % MOD;
    }
    // printf("\t%d %d %lld\n", p, r, DP[p][r]);
    return DP[p][r];
}

int main() {
    memset(DP, -1, sizeof(DP));
    ri(N);
    FOR(i, 0, N) ri(X[i]);
    FOR(i, 0, N) ri(Y[i]);
    for (int i = N - 1; i >= 0; --i) S[i] = X[i] + S[i + 1];
    int sm = 0;
    FOR(i, 0, N) sm += X[i];
    printf("%lld\n", f(0, 0));
    return 0;
}
