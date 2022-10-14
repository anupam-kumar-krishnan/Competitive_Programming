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
    int t;
    cin>>t;
    while (t--)
    {
        int arr[3];
        fo(3){
            cin>>arr[i];
        }
        sort(arr,arr+3);
        if((arr[0]+arr[1])==arr[2]){
            cout<<"YES"<<new;
        }
        else{
            cout<<"NO"<<new;
        }
    }
    
 
return 0;
//************************************//
}
