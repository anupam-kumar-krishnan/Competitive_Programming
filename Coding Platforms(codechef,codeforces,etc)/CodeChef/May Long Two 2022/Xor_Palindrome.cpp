#include "bits/stdc++.h"
using namespace std;
int main()
{
    long long int t;
    cin >> t;
    while (t--)
    {
        long long int n;
        cin >> n;
        string s1;
        cin >> s1;
        long long int answer = 0;
        for (long long int i = 0; i < n / 2; i++)
        {
            if (s1[i] != s1[n - i - 1])
                answer++;
        }
        answer = answer + 1;
        cout << answer / 2 << endl;
    }
}
