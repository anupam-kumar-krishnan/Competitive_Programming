#include<iostream>
using namespace std;
int main()
{
	int n;
	cin >> n;
	int a[100][3];
	for (int i = 0; i < n; i++)
		cin >> a[i][0] >> a[i][1] >> a[i][2];
	int o =0,p=0,q=0;
	for (int j = 0; j < n; j++)
		o+=a[j][0];
	for (int k = 0; k < n; k++)
		p += a[k][1];
	for (int l = 0; l < n; l++)
		q += a[l][2];
	if (o==0&&p==0&&q==0)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
	return 0;
}
