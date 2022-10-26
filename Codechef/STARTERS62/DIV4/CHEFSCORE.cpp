#include <iostream>
#define testCase \
    int t;       \
    cin >> t;    \
    while (t--)
using namespace std;

int main()
{
    testCase
    {
        int n, x, y;
        cin >> n >> x >> y;
        if (y % x == 0 && y / x <= n)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
/*
INPUT
5
1 8 4
3 6 12
4 5 0
10 10 100
8 5 36

OUTPUT
NO
YES
YES
YES
NO
*/