#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubarraySum((int a[], int n){
	long long maxh = 0, maxf = INT_MIN;

	for(int i=0;i<n;i++){
		maxh+=a[i];
		maxf=max(maxh,maxf);

		if(maxh<0)
			maxh=0;
	}
	retun maxf;	
}
};


int main(){

	int t,n;
	cin>>t;

	while(t--){
	
		cin>>n;
		int a[n];

		for(int i=0;i<n;i++){
			cin>>a[i];
		}

		Solution ob;
		cout<<ob.maxSubarraySum(a,n)<<endl;

	return 0;
}
