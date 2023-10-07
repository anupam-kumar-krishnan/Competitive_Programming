#include <iostream>
#include <cstdio>
#include <string>
#include <string.h>
#include <cmath>

using namespace std;

int main() {
	int i, n, t, k, w;
	long long sum=0;

	cin>> k>>n>>w;
	for(i=1; i<=w; i++){
		sum = sum+(i*k);
	}
	if(sum<= n){
		cout <<0<<"\n";
	}
	else cout << sum - n << "\n";

	return 0;
}
