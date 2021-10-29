#include<bits/stdc++.h>
#define ll long long
using namespace std;

bool min(ll *ar, ll n, ll p, ll mid)
{
	ll paratha=0,time=0,flag=0;
	for(int i=0;i<n;++i)
	{
		time=0;
		ll c=1;
		while(time<=mid)
		{	
			time+=(c*ar[i]);
			paratha++;
			c++;
			flag=1;	
		}
		if(flag==1)
			paratha--;
	}
	if(paratha>=p)
		return true;
	return false;
}

int main()
{
	
	ll t;
	cin>>t;
	while(t--)
	{
		ll ans=0,p;
		cin>>p;
		ll n;
		cin>>n;
		ll ar[n];
		for(ll i=0;i<n;++i)
		{
			cin>>ar[i];
		}
		ll start=0,end=100000000;
		
		while(start<=end)
		{
			ll mid=start+(end-start)/2;
			
			if(min(ar,n,p,mid))
			{
				ans=mid;
				end=mid-1;
			}
			else
			{
				start=mid+1;
			}
		}
		cout<<ans<<"\n";
	}
}
