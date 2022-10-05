/*

You are given a list of positive integers nums and an integer k.
Return whether there exists a combination of integers in nums such
that their sum is k and none of those elements are adjacent in the
original list.
Constraints -> n * k <= 100,000

*/

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> dp; // as the constraints are given for n * k and not for n & k seperately we used a vector instead of a 2D array for memoisation to save space and time.
bool rec(vector<int> nums, int k, int i, int cur)
{
    if (cur > k) return 0;
    
    if (cur == k) return 1;

    if (i >= nums.size()) return 0;
    
    if (dp[i][cur] != -1) return dp[i][cur];
    
    return dp[i][cur] = rec(nums, k, i + 2, cur + nums[i]) || rec(nums, k, i + 1, cur); // if we choose ith element we move pointer to (i + 2)th element and to (i + 1)th otherwise. 
}

int main()
{
    int n, k;
    cin >> n >> k;

    vector<int> nums;

    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;

        nums.push_back(temp);
    }

    dp.resize(n + 5);

    for (auto &it : dp)
    {
        it.resize(k + 5);
    }        
    for (auto &it1: dp)
    {
        for (auto &it: it1)
        {
            it = -1;
        }
    }
    bool ans = rec(nums, k, 0, 0);
    if (ans) cout << "Possible" << endl;
    else cout << "Not possible" << endl;

    return 0;
}