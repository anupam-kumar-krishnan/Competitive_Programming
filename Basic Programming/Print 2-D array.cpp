/*Given a 2-D integer array with n rows and m columns. Print the 0th row from input n times,1 row n-1 times,...,n-1 th row will be printed 1 time*/
#include <iostream>
using namespace std;
void print2DArray(int **input, int row, int col) {
int i,j,k=0;
    for(i=0;i<row;i++)
        
    {  k=0;
     while(k<row-i){
        for(j=0;j<col;j++)
        {
            cout<<input[i][j]<<" ";
        }
        k++;
    cout<<endl;}
     
    }
}
int main() {
    int row, col;
    cin >> row >> col;

    int **input = new int*[row];
    for(int i = 0; i < row; i++) {
	    input[i] = new int[col];
	    for(int j = 0; j < col; j++) {
	        cin >> input[i][j];
	    }
    }
    print2DArray(input, row, col);
  return 0;
}
