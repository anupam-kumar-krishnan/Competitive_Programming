#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

int gcd(int a,int b){
    if(b==0) return a;
    return gcd(b,a%b);
}
int main(){
    int t;cin>> t;
    while(t--){
        int n ; cin >> n;

        vector<int> a(n), b(n+1);
        for(int i=0; i < n; ++i) cin >> a[i];
        bool ch = 1;
//        for(int i=1;i+1<n;++i){ int d = gcd(a[i-1],a[i+1]); if(d > a[i] &&d%a[i] ==0) { ch = 0;break;} }
        b[0] = a[0];
        for(int i=0;i<n;++i){
            b[i] = (1ll*b[i]*a[i])/gcd(b[i],a[i]);
            b[i+1] = a[i];
        }
        for(int i=0;i<n;++i){ int d = gcd(b[i+1],b[i]); if(d != a[i] ) { ch = 0;break;} }
        ch?cout<<"YES\n":cout<<"NO\n";
    }
    return 0;
}