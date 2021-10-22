#include <bits/stdc++.h>
#include <algorithm>
#include <set>
#include <math.h>
#include <vector>
int32_t main(){
    int n;
    cin>>n;
    char s[n]; 
    int a[n];
    for(int i=0;i<n;i++) cin>>s[i]>>a[i];
    bool visited[1000001]={false};
    int ans=0 , c=0;
    for(int i=0;i<n;i++){
        if(s[i]=='+'){
            visited[a[i]]=true;
            c++;
        }
        else if(visited[a[i]]){
            c--;
            visited[a[i]]=false;
        }
        else{
            ans++;
        }
        ans=max(c , ans);
    }
    cout<<ans<<endl;
    return 0;
}