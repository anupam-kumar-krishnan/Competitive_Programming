#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    unordered_map<int ,int>vmap;
	    vector<int>v,k;
	    int flag=0;
	    for(int i=0;i<n;i++)
	    {
	        int x;
	        cin>>x;
	        vmap[x]++;
	    }
	    for(auto it:vmap)
	    {
	        v.push_back(it.second);
	    }
	    for(int i=0;i<v.size();i++)
	    {
	        int t=*max_element(v.begin(),v.end());
	        if(t==v[i])
	        {
	            flag++;
	        }
	        
	    }
	    if(flag>1)
	    cout<<"NO"<<endl;
	    else
	    cout<<"YES"<<endl;
	}
	return 0;
}