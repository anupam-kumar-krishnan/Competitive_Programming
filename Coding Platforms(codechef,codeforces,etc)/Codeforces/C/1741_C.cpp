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
          cin >> num;
          vector<ll> arr(num);
          in(arr);
          ll sum = accumulate(all(arr), 0LL);
          ll x = 1, t = -1;
          vector<ll> ans;
          ll an = 0;
          while (x <= num)
          {
               an=0;
               if (sum % x != 0)
               {
                    x++;
                    continue;
               }
               ll i = 0;
               ll required = sum / x;
               ll curr_sum = 0;
               ll chk = 1;
               ll tt = 0;
               while (i < num)
               {
                    tt = i;
                    curr_sum = 0;
                    while (curr_sum < required && i < num)
                    {
                         curr_sum += arr[i];
                         i++;
                    }
                    if (curr_sum != required)
                    {
                         chk = -1;
                         break;
                    }
                    an = max(an, i - tt);
               }
               if (chk == -1)
               {
                    x++;
                    continue;
               }
               if (curr_sum != required)
               {
                    x++;
                    continue;
               }
               else
               {
                    an = max(an, i - tt);
                    t = x;
                    ans.push_back(an);
               }
               x++;
          }
          sort(all(ans));
          cout<<ans[0]<<endl;
     }
     return 0;
}
