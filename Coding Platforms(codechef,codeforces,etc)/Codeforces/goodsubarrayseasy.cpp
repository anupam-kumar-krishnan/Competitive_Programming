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
       long long int ans = 0;
       int mn = 1e9;int d = 0;
       for(int i=n-1;i>=0;--i){
           mn--;d++;

           ans = d;
           if(mn < 0) d=0,mn = a[i];
           else if(mn)
       }
       cout << ans <<'\n';
    }
    return 0;
}