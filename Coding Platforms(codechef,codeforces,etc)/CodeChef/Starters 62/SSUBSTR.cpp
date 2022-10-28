#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin>>n;
        string bin;
        cin>>bin;
        int ans=0;
        char buf=bin[0];
        int flag=0;
        for(int i=0;i<n;i++){
            if(bin[i]>=buf){
                buf=bin[i];
            }
            else{
                if(buf=='0'){
                    if(bin[i]>buf){
                        ans++;
                        buf=bin[i];
                    }
                }
                else if(buf=='1'){
                    if(bin[i]<buf){
                        ans++;
                        buf=bin[i];
                    }
                }
            }
            
        }
        cout<<ans<<endl;
    }
return 0;
}