#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int ans=0;
        int x,y;
        cin>>x>>y;
        ans=x/y+x%y;
        cout<<ans<<endl;
    }
return 0;
}