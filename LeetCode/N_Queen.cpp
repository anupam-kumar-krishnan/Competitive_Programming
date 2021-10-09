// --------------------------------------- ||** HACKTOBERFEST 2021 **|| ---------------------------------------
/*
 * Author : Umesh Kumar
 * Date : 09/10/2021
 * Problem : https://leetcode.com/problems/n-queens/
 */
#include<bits/stdc++.h>
#include <iostream>
using namespace std;


bool isValid(vector<string> sol, int n, int row, int col){
    // row
    for (int c = 0; c < n; c++){
        if(sol[row][c]=='Q')
            return false;
    }
    // col
    for (int r = 0; r < n; r++){
        if(sol[r][col]=='Q')
            return false;
    }
    // current to top-left
    int i = row, j = col;
    while(i>=0 && j>=0){
        if(sol[i][j]=='Q')
            return false;
        i--;
        j--;
    }
    // current to top-right
    i = row; j = col;
    while (i >= 0 && j < n){
        if(sol[i][j]=='Q')
            return false;
        i--;
        j++;
    }
    return true;
}
void helper(vector<vector<string>> &ans, vector<string> &sol, int n, int row){
    if(row >= n){
        ans.push_back(sol);
        return;
    }
    for (int c = 0; c < n; c++){
        if(isValid(sol, n, row, c)){
            sol[row][c] = 'Q';
            helper(ans, sol, n, row + 1);
            sol[row][c] = '.';
        }
    }
}

vector<vector<string>> solveNQueens(int n)
{
    vector<string> arr;
    string t;
    for (int i = 0; i < n; i++)
        t += '.';

    for (int i = 0; i < n; i++)
        arr.push_back(t);

    vector<vector<string>> ans;
    helper(ans, arr, n, 0);
    return ans;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    for(auto v: solveNQueens(4)){
        for(auto s: v)
            cout << s << endl;
    }
    return 0;
}