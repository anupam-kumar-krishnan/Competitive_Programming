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
ll power(ll num, ll x)
{
     ll ans = 1, t = num;
     while (x)
     {
          if (x & 1)
          {
               ans *= t;
               // ans %= M;
          }
 
          t *= t;
          x = x >> 1;
     }
     return ans;
}
ll ssqrt(ll num)
{
     if (num <= 1)
     {
          return num;
     }
     ll st = 1, end = 1e9 + 10;
     while (st <= end)
     {
          unsigned ll mid = (st + end) / 2;
          unsigned ll t = mid * mid;
          if (t == num)
          {
               return mid;
          }
          else if (t > num)
          {
               end = mid - 1;
          }
          else
          {
               st = mid + 1;
          }
     }
     return min(st, end);
}

int main()
{
     fast;
     te
     {
          string s1, s2;
          cin>>s1>>s2;
          ll ct = 1,i=0;
          while (s1[i]=='X')
          {
               ct++;
               i++;
          }
          ll a1 = 0;
          if (s1[i]=='S')
          {
              a1= (-2)*ct; 
          }
          else if (s1[i]=='L')
          {
               a1= 2*ct;
          }
          ct = 1,i=0;
          while (s2[i]=='X')
          {
               ct++;
               i++;
          }
          ll a2 = 0;
          if (s2[i]=='S')
          {
              a2= (-2)*ct; 
          }
          else if (s2[i]=='L')
          {
               a2= 2*ct;
          }
          if (a1==a2)
          {
               cout<<"="<<endl;
          }
          else if (a1<a2)
          {
               cout<<"<"<<endl;
          }
          else
          {
               cout<<">"<<endl;
          }
          
          
     }
     return 0;
}
