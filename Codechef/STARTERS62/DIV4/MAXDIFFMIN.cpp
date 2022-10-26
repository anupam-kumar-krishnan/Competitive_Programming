#include <iostream>
#define testCase \
    int t;       \
    cin >> t;    \
    while (t--)
using namespace std;

int max(int a, int b, int c)
{
    if (a >= b && a >= c)
        return a;
    else if (b >= a && b >= c)
        return b;
    else if (c >= a && c >= b)
        return c;
}

int min(int a, int b, int c)
{
    if (a <= b && a <= c)
        return a;
    else if (b <= a && b <= c)
        return b;
    else if (c <= a && c <= b)
        return c;
}

int main()
{
    testCase
    {
        int a, b, c;
        cin >> a >> b >> c;
        cout << max(a, b, c) - min(a, b, c) << endl;
    }
    return 0;
}
/*
INPUT
4
1 3 10
5 6 7
3 8 9
2 5 6

OUTPUT
9
2
6
4
*/