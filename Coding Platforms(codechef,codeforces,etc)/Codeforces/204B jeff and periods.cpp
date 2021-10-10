//Codeforces 204(div2) B - JEFF AND PERIODS
//Question link : https://codeforces.com/contest/352/problem/B



#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
    int n;
    cin >> n;
    int a[n];//creating an array for input
    int f = 0, count = 0;
    map<int, set<int>>mp;
    map<int, int>mp1;
    int j = 0;
    set<int>s;
    int diff, p;
    set<int>::iterator it;
    int g, h, q, w;
    for (int i = 0; i < n; i++) {cin >> a[i]; mp[a[i]].insert(i);}
    for (auto i : mp) {
        it = i.second.begin();
        g = *it;
        it++;
        h = *(it);
        diff = h - g;
        f = 0;
        it = i.second.begin();
        int count1 = i.second.size() - 1;
        while (count1--) {
            q = *it;/*cout<<q;*/; it++; w = *it; //cout<<w;
            if (w - q == diff) f = 1;
            else {f = 0; break;}

        }
        p = i.first;
        if (i.second.size() == 1) {mp1[p] = 0; count++; continue;}
        if (f) {mp1[p] = diff; count++;}
    }
    cout << count << '\n';
    for (auto i : mp1) cout << i.first << " " << i.second << '\n';
    return 0;
}
