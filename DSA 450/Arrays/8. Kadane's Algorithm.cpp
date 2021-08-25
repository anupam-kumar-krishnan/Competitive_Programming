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
	
--------------------------------------------------------
		
#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int n,i;
    cin>>n;

    long long int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];

    long long int cs=arr[0],ms=arr[0];

    for(i=1;i<n;i++)
    {
        cs=max(cs+arr[i],arr[i]);
        ms=max(ms,cs);
    }

    cout<< ms <<endl;

 return 0;   
}
