#include <bits/stdc++.h>
using namespace std;

// Printing all primes in the range [1,n] using Sieve of Eratosthenes
void sieveOfEratosthenes(int n)
{
    vector<bool> is_prime(n + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= n; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= n; j += i)
                is_prime[j] = false;
        }
    }
    for (int i = 1;i <= n;i++)
    {
        if (is_prime[i])
        {
            cout << i << " is prime." << endl;
        }
    }
}
int main()
{
    int n;
    cin >> n;
    sieveOfEratosthenes(n);
    return 0;
}