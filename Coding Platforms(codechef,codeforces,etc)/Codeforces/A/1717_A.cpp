#include <bits/stdc++.h>
using namespace std;
#define sp " "
#define all(v) \
     v.begin(), v.end()
#define at auto
#define ll long long
#define te        \
     ll test;     \
     cin >> test; \
     for (ll tes = 1; tes <= test; tes++)
#define fast                           \
     ios_base::sync_with_stdio(false); \
     cin.tie(NULL);
#define endl \
     "\n"
#define nxt cout << endl;
#define in(v)          \
     for (auto &x : v) \
          cin >> x;
#define out(v)              \
     for (auto &x : v)      \
     {                      \
          cout << x << " "; \
     }                      \
     nxt;
#define mout(v)                                       \
     for (auto &x : v)                                \
     {                                                \
          cout << x.first << " " << x.second << endl; \
     }                                                \
     // nxt
#define FL                             \
     freopen("input.txt", "r", stdin); \
     freopen("output.txt", "w", stdout);
// fucntion
bool isPossible(map<ll, ll> &mp, ll tt, ll m)
{
     ll xx = 0;
     for (auto &x : mp)
     {
          if (x.second < tt)
          {
               xx += x.second;
               xx += (tt - x.second) / 2;
          }
          else
          {
               xx += tt;
          }
     }
     if (xx >= m)
     {
          return true;
     }
     return false;
}
int main()
{
     fast;
     te
     {
          ll num;
          cin >> num;
          ll ans = 0;
          ans += (num / 3) * 2;
          ans += (num/2)*2;
          cout << ans + num << endl;
     }
}
