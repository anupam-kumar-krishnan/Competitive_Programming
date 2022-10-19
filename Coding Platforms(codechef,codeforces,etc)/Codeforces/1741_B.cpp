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
// ll lcm(ll num1, ll num2){
//      return (num1*num2)/__gcd(num1,num2);
// }
int main()
{
     fast;
     te
     {
          ll num;
          cin>>num;
          if (num==1||num==3)
          {
               cout<<-1<<endl;
               continue;
          }
          vector<ll>arr(num);
          for (ll i = 2; i < num; i++)
          {
               arr[i]=i-1;
          }
          arr[0]=num;
          arr[1]=num-1;
          out(arr);
     }
     return 0;
}
