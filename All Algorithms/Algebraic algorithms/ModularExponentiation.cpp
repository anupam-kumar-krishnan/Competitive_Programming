/*
Modular Exponentiation
Given three numbers x, y and p, compute (x^y)%p

Constraints : 
1 ≤ x, y, p ≤ 10^9

Time Complexity : O(log(n))
Space Complexity : O(1)

Practice Problem Link : https://practice.geeksforgeeks.org/problems/modular-exponentiation-for-large-numbers5537/1

*/


#include <bits/stdc++.h>
using namespace std;

struct Exponentiation{

    long long mod_expo(long long a, long long b, long long mod){
        if (b == 0 || b == 1) return a;
        else if (b & 1){
            long long ans = mod_expo(a, b / 2, mod) % mod;
            return (((1LL * ans * ans) % mod) * a) % mod;
        }
        else{
            long long ans = mod_expo(a, b / 2, mod) % mod;
            return (1LL * ans * ans) % mod;
        }
    }
};

int32_t main()
{
    long long x,y,p;
    cin >> x >> y >> p;
    struct Exponentiation E;
    cout << E.mod_expo(x,y,p) << "\n";
    return 0;
}
