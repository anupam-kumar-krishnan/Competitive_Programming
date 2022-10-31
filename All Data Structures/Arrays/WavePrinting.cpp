// For a given two-dimensional integer array/list of size (N x M), print the array/list in a sine wave order, i.e, print the first column top to bottom, next column bottom to top and so on.

// code
#include <iostream>
using namespace std;

void wavePrint(int **input, int nr, int mc)
{
  for(int j=0;j<mc;j++){
     if(j%2==0){
     for(int i=0;i<nr;i++){
         cout<<input[i][j]<<' ';
        }
     }
     else if(j%2!=0){
         for(int i=nr-1;i>=0;i--){
             cout<<input[i][j]<<' ';
         }
     }
 }   
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int row, col;
		cin >> row >> col;
		int **input = new int *[row];
		for (int i = 0; i < row; i++)
		{
			input[i] = new int[col];
			for (int j = 0; j < col; j++)
			{
				cin >> input[i][j];
			}
		}
		wavePrint(input, row, col);
		cout << endl;
	}
}
