#include <bits/stdc++.h>
using namespace std;

bool isShuffledSubstring(string A, string B)
{
	int n = A.length();
	int m = B.length();

	if (n > m) {
		return false;
	}
	else {


		sort(A.begin(), A.end());

	
		for (int i = 0; i < m; i++) {

			if (i + n - 1 >= m)
				return false;

			string str = "";
			for (int j = 0; j < n; j++)
				str.push_back(B[i + j]);

			sort(str.begin(), str.end());

			if (str == A)
				return true;
		}
	}
}

int main()
{

	string str1;
	string str2;

  cin>>str1;
  cin>>str2;
  
	bool a = isShuffledSubstring(str1, str2);

	if (a)
		cout << "YES";
	else
		cout << "NO";
	cout << endl;
	return 0;
}
