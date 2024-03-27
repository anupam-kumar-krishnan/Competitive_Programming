#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n;
    cin >> n;
    vector<char> resp(n);
    string s;
    cin >> s;
    int ini;
    bool left;
    if(n % 2) {
        ini = n/2;
        left = false;
    } else {
        ini = n/2 - 1;
        left = true;
    }
    for(int i = 0; i < n; i++) {
        if(left) {
            resp[ini] = s[i];
        } else {
            resp[n-ini-1] = s[i];
            ini--;
        }
        left = !left;
    }
 
    for(int i = 0; i < n; i++) cout << resp[i];
    cout << '\n';
 
    return 0;
}