Little Elephant and Order
//Problem Link : https://www.codechef.com/submit/LUCKY10

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cassert>
#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <functional>
#include <map>
#include <set>
#include <queue>
using ll = long long;
using pii = std::pair<int, int>;
constexpr int inf = 0x3f3f3f3f;
constexpr int mod2 = 998244353;
constexpr int mod = 1e9 + 7;
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;
    while (T--) {
        string a, b;
        cin >> a >> b;
        int n = a.length();
        vector<int> ca(10), cb(10);
        for (char c : a) ca[c - '0']++;
        for (char c : b) cb[c - '0']++;

        int x[5], y[5];
        x[0] = ca[0] + ca[1] + ca[2] + ca[3];
        x[1] = ca[4];
        x[2] = ca[5] + ca[6];
        x[3] = ca[7];
        x[4] = ca[8] + ca[9];
        y[0] = cb[0] + cb[1] + cb[2] + cb[3];
        y[1] = cb[4];
        y[2] = cb[5] + cb[6];
        y[3] = cb[7];
        y[4] = cb[8] + cb[9];

        int ans7 = 0, ans4 = 0;
        { // max 7 in A
            int t = min(x[3], y[0] + y[2]);
            ans7 += t;
            x[3] -= t;
            if (y[2] >= t) {
                y[2] -= t;
            } else {
                y[0] -= t - y[2];
                y[2] = 0;
            }
            if (x[3]) {
                t = min(x[3], y[1]);
                x[3] -= t;
                y[1] -= t;
                ans7 += t;
            }
        }
        { // max 7 in B
            int t = min(y[3], x[0] + x[2]);
            ans7 += t;
            y[3] -= t;
            if (x[2] >= t) {
                x[2] -= t;
            } else {
                x[0] -= t - x[2];
                x[2] = 0;
            }
            if (y[3]) {
                t = min(y[3], x[1]);
                y[3] -= t;
                x[1] -= t;
                ans7 += t;
            }
        }
        // { // pair 89
        //     int t = min(x[4], y[4]);
        //     x[4] -= t;
        //     y[4] -= t;
        // }
        {
            int t = min(x[3], y[3]);
            x[3] -= t;
            y[3] -= t;
            ans7 += t;
        }
        {
            int t = min(x[1], y[0]);
            ans4 += t;
            x[1] -= t;
            y[0] -= t;
        }
        {
            int t = min(y[1], x[0]);
            ans4 += t;
            y[1] -= t;
            x[0] -= t;
        }
        {
            int t = min(x[1], y[1]);
            x[1] -= t;
            y[1] -= t;
            ans4 += t;
        }

        for (int i = 0; i < ans7; ++i) cout << 7;
        for (int i = 0; i < ans4; ++i) cout << 4;
        cout << '\n';
    }
    return 0;
}