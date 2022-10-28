#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        string ans="YES";
        int n,x,y;
        cin>>n>>x>>y;
        if(x>y && y>0){
            ans="NO";
        }
        else if(y%x!=0){
            ans="NO";
        }
        else if(y>n*x){
            ans="NO";
        }
        cout<<ans<<endl;
        
        
    }
return 0;
}