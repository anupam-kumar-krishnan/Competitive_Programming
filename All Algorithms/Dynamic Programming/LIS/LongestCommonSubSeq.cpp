
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
//Top down appraoch
string LCS_Pr(string x, string y, int m, int n, vector<vector<int> >&c)
{
    if (m == 0 || n == 0) {
		return string("");
	}
    //Taking these cases similar with LCS_Length conditions.
	if (x[m - 1] == y[n - 1])
	{
		return LCS_Pr(x, y, m - 1, n - 1, c) + x[m - 1];
		//Concatenating the initial values., top down approach.
	}
	if (c[m - 1][n] > c[m][n - 1]) {
		return LCS_Pr(x, y, m - 1, n, c);
	}
	else {

		return LCS_Pr(x, y, m, n - 1, c);
	}
}

void LCS_Length(string x, string y, vector<vector<int> >&c)
{
    int m = x.length(), n = y.length();
	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (x[i - 1] == y[j - 1]) {
				c[i][j] = c[i - 1][j - 1] + 1;
			}
			/*
			else {
				c[i][j] = max(c[i - 1][j], c[i][j - 1]);
			}
			*/
			else if(c[i-1][j]>=c[i][j-1])
				c[i][j]=c[i-1][j];
			else
				c[i][j]=c[i][j-1];
		}
	}
}

int main()
{
	string x, y;
	cin>>x>>y;
    int m = x.length(), n = y.length();
    
    //To get an OP of 'BCBA',(for the 2nd test case), 
    //we'll reverse our Main String, and the target string. 

    vector<vector<int> > c(y.length()+1,vector<int>(x.length()+1));
	LCS_Length(y, x, c);
	cout<<LCS_Pr(y, x, n, m, c).length()<<endl;
    cout<<LCS_Pr(y, x, n, m, c)<<endl;

	return 0;
}
