// Given an integer array of coins[ ] of size N representing different types of currency and an integer sum, 
// The task is to find the number of ways to make sum by using different combinations from coins[].

// Input: sum = 10, coins[] = {2, 5, 3, 6}
// Output: 5
// Explanation: There are five solutions: 
// {2,2,2,2,2}, {2,2,3,3}, {2,2,6}, {2,3,5} and {5,5}.

// Recursive C++ program for
// coin change problem.
#include <bits/stdc++.h>
using namespace std;

int count(int coins[], int n, int sum)
{
	if (sum == 0)
		return 1;

	if (sum < 0)
		return 0;

	if (n <= 0)
		return 0;

	return count(coins, n - 1, sum)
		+ count(coins, n, sum - coins[n - 1]);
}

// Driver code
int main()
{
	int i, j;
	int coins[] = { 1, 2, 3 };
	int n = sizeof(coins) / sizeof(coins[0]);
	int sum = 4;

	cout << " " << count(coins, n, sum);

	return 0;
}

// Contributed by Komal vishwakarma
