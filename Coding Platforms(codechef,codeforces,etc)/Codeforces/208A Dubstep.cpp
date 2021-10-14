#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long int
int main(){
    fast;
    string s;
    cin>>s;
    string s1="WUB";
    while(s.find(s1)!=string::npos){
        int y=s.find(s1);
        if(y==0)s.erase(0,3);
        else {
            s.replace(y,1," ");
            s.erase(y+1,2);
        }
        
    }
    for(int i=1;i<s.length()-1;i++){
        if(s[i]==' '){
            if(s[i+1]==' '){
                s.erase(i+1,1);
            }
        }
    }
    cout<<s;
    return 0;
}