#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n,q;
        cin>>n>>q;
        int arr[n];
        int sum = 0;
        for(int i=0;i<n;i++){
            cin>>arr[i];
            sum += arr[i];
        }
        for(int i=0;i<q;i++){
            int l,r;
            cin>>l>>r;
            if((r-l)%2==0){
                sum++;
            }
        }
        cout<<sum<<endl;
        
    }
return 0;
}