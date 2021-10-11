#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	while(cin >> n)
	{
		string s;
		cin >> s;
		int num = 0;
		
		for(int i =0;i<s.length();i++)
		if(s[i]=='A')num++;
		
		if(n-num>num)cout<<"Danik"<<endl;
		else if(n-num<num)cout<<"Anton"<<endl;
		else cout<<"Friendship"<<endl;
	}
	return 0;
 } 
