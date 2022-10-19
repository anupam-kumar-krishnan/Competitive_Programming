/*
jay has a magical chessboard . it looks like a normal except its size is N . Therefore the number of cells in the chessboard is N*N . He is intrested in counting the number of squares in the chessborad . it is a very tough task for him , so he is looking for your help
sample input 
3
1
2
3
output 
1
5
14

constraints 
1<= T <= 100
1<= N <= 100
*/

#include <iostream>
using namespace std ; 
int main (){
    int T ,j ;
    cin >> T;
    int arr[100];
    for (int i=0 ; i<T; i++)
    {
        cin >> j ;
        arr[i]= j;
    }
    for (int k=0 ; k<T ; k++)
    {
        int ans =0  ; 
        for (int i = arr[k]; i>0 ;i--)
        {
            ans = (ans + (i*i));
        }
        cout << ans << endl;
    }
    return 0;
}