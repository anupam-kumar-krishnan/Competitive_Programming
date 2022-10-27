// Problem statement 
// Find the top k most frequent number in an array



#include <bits/stdc++.h>
using namespace std;


bool compare(pair<int, int> p1, pair<int, int> p2)
{
	// If frequencies of two elements are same
	// then the larger number should come first
	if (p1.second == p2.second)
		return p1.first > p2.first;

	// Sort on the basis of decreasing order
	// of frequencies
	return p1.second > p2.second;
}

// Function to print the k numbers with most occurrences
void print_N_mostFrequentNumber(int arr[], int N, int K)
{
	unordered_map<int, int> mp;
	for (int i = 0; i < N; i++)
		mp[arr[i]]++;
	vector<pair<int, int> > freq_arr(mp.begin(), mp.end());

	// Sort the vector 'freq_arr' on the basis of the
	// 'compare' function
	sort(freq_arr.begin(), freq_arr.end(), compare);

	// display the top k numbers
	cout << K << " numbers with most occurrences are:\n";
	for (int i = 0; i < K; i++)
		cout << freq_arr[i].first << " ";
}

int main()
{
	int arr[] = { 3, 1, 4, 4, 5, 2, 6, 1 };
	int N = sizeof(arr) / sizeof(arr[0]);
	int K = 2;

	// Function call
	print_N_mostFrequentNumber(arr, N, K);

	return 0;
}
