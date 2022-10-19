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
          ll num, k, r, c;
          cin >> num >> k >> r >> c;
          char s[num][num];
          for (ll i = 0; i < num; i++)
          {
               for (ll j = 0; j < num; j++)
               {
                    s[i][j] = '.';
                    if (i == r - 1 && j == c - 1)
                    {
                         s[i][j] = '*';
                    }
               }
          }
          for (ll i = r - 1; i < num; i += k)
          {
               s[i][c - 1] = '*';
          }
          for (ll i = r - 1; i >= 0; i -= k)
          {
               s[i][c - 1] = '*';
          }
          for (ll i = c - 1; i < num; i += k)
          {
               s[r - 1][i] = '*';
          }
          for (ll i = c - 1; i >= 0; i -= k)
          {
               s[r - 1][i] = '*';
          }
          for (ll i = 0; i < num; i++)
          {
               for (ll j = 0; j < num; j++)
               {
                    if (s[i][j] == '*')
                    {
                         ll m = i, n = j;
                         while (m < num && n < num)
                         {
                              s[m][n] = '*';
                              m++;
                              n++;
                         }
                         m = i, n = j;
                         while (m >= 0 && n >= 0)
                         {
                              s[m][n] = '*';
                              m--;
                              n--;
                         }
                    }
               }
          }
          for (ll i = 0; i < num; i++)
          {
               for (ll j = 0; j < num; j++)
               {
                    if (s[i][j] != '*')
                    {
                         ll t = -1, a = -1;
                         for (ll m = max(0LL, i - k + 1); m < min(num, i + k); m++)
                         {
                              if (s[m][j] == '*')
                              {
                                   t = 1;
                                   break;
                              }
                         }
                         for (ll m = max(0LL, j - k + 1); m < min(num, j + k); m++)
                         {
                              if (s[i][m] == '*')
                              {
                                   t = 1;
                                   break;
                              }
                         }
                         if (t == -1 && a == -1)
                         {
                              s[i][j] = '*';
                         }
                    }
               }
          }
          for (ll i = 0; i < num; i++)
          {
               for (ll j = 0; j < num; j++)
               {
                    if (s[i][j] == '*')
                    {
                         s[i][j] = 'X';
                    }
 
                    cout << s[i][j];
               }
               nxt;
          }
     }
}
