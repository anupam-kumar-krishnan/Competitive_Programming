//************************************//
#include<iostream>
#include<bits/stdc++.h>
#define ll long long
#define new '\n' 
#define fo(a) for( ll int i=0;i<a;i++)
#define mp make_pair
#define even(num) if ((num & 1) == 0)
const int M=1e9+7;
using namespace std;
//*************************************//
int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
    ll int t;
    cin>>t;
    while (t--)
    {
        ll int n;
 
        bool x=true;
        cin>>n;
        int arr[n];
        fo(n){
            cin>>arr[i];
        }
        sort(arr,arr+n);
        fo(n-1){
            if(arr[i]==arr[i+1]){
                x=false;
                break;
            }
        }
        if(x==true){
            cout<<"YES"<<new;
        }
        else{
            cout<<"NO"<<new;
        }
    }
    
 
return 0;
//************************************//
}
