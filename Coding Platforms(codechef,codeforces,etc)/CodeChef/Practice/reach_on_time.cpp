#include <iostream>

using namespace std;

int main()
{
    int t, X;
    cin >> t;
    while (t--)
    {
        cin >> X;
        if (X >= 30)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
