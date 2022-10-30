/*
Problem Link:-

https://codeforces.com/contest/126/problem/B
*/
#include <bits/stdc++.h>

#define S second
#define F first
using namespace std;
typedef long long ll;
#define clr(x, y, n) memset(x, y,n* sizeof(x[0]))
const ll N = 1e4 + 5, M = 2e5 + 5, mod = 1e9 + 7, llinf = 0x3f3f3f3f3f3f3f3f;
const int iinf = 0x3f3f3f3f;

ll gcd(ll a, ll b) {
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

ll lcm(ll a, ll b) {
    return (a / gcd(a, b)) * b;
}

int n;
string s;
vector<int> pre;

void build() {
    pre = vector<int>(n);
    pre[0] = 0;
    int border = 0;
    for (int i = 1; i < n; ++i) {
        while (border > 0 && s[i] != s[border])
            border = pre[border - 1];
        if (s[i] == s[border])++border;
        pre[i] = border;
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> s;
    n = s.length();
    build();
    if (!pre[n - 1]) {
        cout << "Just a legend";
        return 0;
    }
    for (int i = 0; i < n - 1; ++i) {
        if (pre[i] == pre[n - 1]) {
            cout << s.substr(0, pre[n - 1]);
            return 0;
        }
    }
    if (pre[pre[n - 1] - 1])cout << s.substr(0, pre[pre[n - 1] - 1]);
    else
        cout << "Just a legend";
    return 0;
}