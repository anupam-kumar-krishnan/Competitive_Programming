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
	while(t--){
		int n;
		cin>>n;
		int a[n];
		int ans = 0;
		int z = 0;
 
		int z1 = 0;
 
		for(int i = 0;i<n;i++){
			cin>>a[i];
			if(a[i] == 0){
				z++;
			}
		}
		int b[n];
		for(int i = 0;i<n;i++){
			cin>>b[i];
			if(b[i] == 0){
				z1++;
			}
		}
		for(int i = 0;i<n;i++){
		
			if(a[i] == b[i]){
				continue;
			}
			ans++;
			
 
		}
		cout<<min(ans,abs(z1 - z)+1)<<endl;}
 
return 0;
//************************************//
}
