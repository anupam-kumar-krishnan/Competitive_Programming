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
        int x, y;
        cin >> x >> y;
        cout << x / y + x % y << endl;
    }
    return 0;
}
/*
INPUT
4
4 2
8 3
3 4
2 1

OUTPUT
2
4
3
2
*/