#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        int a[50];
        for(int i=0;i<n;i++) cin>>a[i];
        int count=0;
        for(int i=0;i<n-1;i++){
            float l=max(a[i],a[i+1]);
            float s=min(a[i],a[i+1]);
            while(l>(s*2)){
                count++;
                l=ceil(l/2);
            }
        }
        cout<<count<<'\n'; 
    }

    return 0;
}
