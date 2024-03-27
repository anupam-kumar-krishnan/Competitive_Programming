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
    
    int n;
    cin>>n;
    if(n==3){
        cout<<"-1"<<new;
    }
    else if(n%2==0){
        for(int i=n;i>=1;i--){
            cout<<i<<" ";
        }
        cout<<new;
    }else{
        cout<<n<<" "<<n-1<<" ";
        for(int i=1;i<n-1;i++){
            cout<<i<<" ";
        }
        cout<<new;
    }
   }
   
 
return 0;
//************************************//
}
