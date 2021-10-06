#include"bits/stdc++.h"
using namespace std ;

int main(){
    int t;
    cin>>t;
    while(t--){
        int i,n,c[5],s1=0,s2=0;
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>c[i];
        }
        sort(c,c+n,greater<int>());
        s1=c[0],s2=c[1];
        for(int i=2;i<n;i++){
            if(s1+c[i]<=s2+c[i]){
                s1+=c[i];
            }
            else{
                s2+=c[i];
            }
        }
        if(n==1){
           cout<<c[0]<<endl;
        }   
        else{   
        cout<<max(s1,s2)<<endl;
        }
    }
    return 0;   
}