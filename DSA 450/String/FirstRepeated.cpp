// C++ program to find the first
// character that is repeated
#include <bits/stdc++.h>
#include <string.h>

using namespace std;
int findRepeatFirstN2(char *s)
{
    // this is O(N^2) method
    int p = -1, i, j;
    for (i = 0; i < strlen(s); i++)
    {
        for (j = i + 1; j < strlen(s); j++)
        {
            if (s[i] == s[j])
            {
                p = i;
                break;
            }
        }
        if (p != -1)
            break;
    }

    return p;
}

// Driver code
int main()
{
    char str[] = "hacktoberfest";
    int pos = findRepeatFirstN2(str);
    if (pos == -1)
        cout << "Not found";
    else
        cout << str[pos];
    return 0;
}
