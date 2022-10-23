#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;


#define int long long
#define fo(i, n) for(int i=0;i<n;i++)
#define deba(i, a, n) fo(i, n){cout << a[i] << " ";}
#define pb push_back
#define mod 1e9 +7
#define w(x) int x; cin>>x; while(x--)
#define endl "\n"
#define vp(i, a, n) vi a; fo(i, n){int x; cin>>x; a.pb(x);}
#define ap(i, a, n) fo(i, n){cin>>a[i];}

typedef vector<int> vi;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; //*find_by_order(val);   order_of_key(val);

void solution() {
 int n, m;
 cin>>n>>m;
 vp(i, v, n);
 vp(i, v1, m);
 fo(i, n){
 	if(i>0)
 	v[i]= v[i]+v[i-1];
 }
 int d=1, r=1;
 for(auto it: v1){
 	d= lower_bound(v.begin(), v.end(), it)- v.begin()+1;
 	r= it- v[d-2];
 	if(d<2) r= it;
 	cout<<d<<" "<<r<<endl;

 }
}

int32_t main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    // w(t)
    {
        solution();
    }
   
    return 0;
}
