#include <bits/stdc++.h>
using namespace std;
#define sp " "
#define all(v) \
    v.begin(), v.end()
#define at auto
#define ll long long
#define te       \
    ll test;     \
    cin >> test; \
    while (test--)
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define endl \
    "\n"
#define nxt cout << endl;
#define in(v)         \
    for (auto &x : v) \
        cin >> x;
#define out(v)            \
    for (auto &x : v)     \
    {                     \
        cout << x << " "; \
    }                     \
    nxt
#define FL                            \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);
// functions column
// ll power(ll num, ll x)
// {
//      ll ans = 1, t = num;
//      while (x)
//      {
//           if (x & 1)
//           {
//                ans *= t;
//           }
 
//           t *= t;
//           x = x >> 1;
//      }
//      return ans;
// }
 
// now code :: :)
ll al = 1e9;
int main()
{
    fast;
    te
    {
        ll num;
        cin >> num;
        vector<ll> arr(num, 0);
        if (num % 4 == 0)
        {
            for (ll i = 0; i < num; i += 4)
            {
                arr[i] = i;
                arr[i + 1] = i + 2;
                arr[i + 2] = i + 1;
                arr[i + 3] = i + 3;
            }
        }
        else if ((num % 4) == 3)
        {
            arr.push_back(0);
            for (ll i = 0; i < num; i += 4)
            {
                arr[i] = i;
                arr[i + 1] = i + 2;
                arr[i + 2] = i + 1;
                arr[i + 3] = i + 3;
            }
            arr.erase(arr.begin());
        }
        else
        {
            if ((num & 1) == 0)
            {
                ll x = 0, y = 0;
                // cin>>x>>y;
                for (ll i = 1; i <= num - 2; i++)
                {
                    cout << i << " ";
                    if ((i & 1) == 1)
                    {
                        x ^= i;
                    }
                    else
                    {
                        y ^= i;
                    }
                }
                if ((num & 1) == 0)
                {
                    cout << (al ^ y) << " ";
                    cout << (al ^ x) << endl;
                }
                else
                {
                    cout << (al ^ x) << " ";
                    cout << (al ^ y) << endl;
                }
            }
            else
            {
                ll x = 0, y = 0;
                // cin>>x>>y;
                for (ll i = 0; i < num - 2; i++)
                {
                    cout << i << " ";
                    if ((i & 1) == 1)
                    {
                        x ^= i;
                    }
                    else
                    {
                        y ^= i;
                    }
                }
                if ((num & 1) == 0)
                {
                    cout << (al ^ y) << " ";
                    cout << (al ^ x) << endl;
                }
                else
                {
                    cout << (al ^ x) << " ";
                    cout << (al ^ y) << endl;
                }
            }
 
            continue;
        }
 
        out(arr);
    }
}
