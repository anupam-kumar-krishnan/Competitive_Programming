#include<bits/stdc++.h>

using namespace std;

void solve(){

	int n, m;
	cin >> n >> m;
	int a[n];
	for(int i=0; i<n; i++)
		cin >> a[i];

	while (n > 0 && a[n-1] == n)
		n--;

	double ans = 1;
	for(int i=0; i<m; i++){
		int r;
		double p;
		cin >> r >> p;

		if (r >= n)
			ans *= 1 - p;

	}

	if(!n)
		cout << 1 << endl;
	else
		cout << 1 - ans << endl;
}

int main(){

	int t;
	cin >> t;

	while (t--) solve();

	return 0;
}