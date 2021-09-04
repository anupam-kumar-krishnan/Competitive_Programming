#include <iostream>
using namespace std;

#define N 4 
#define M 4

void spiralMatrixPrint(int rows, int cols, int arr[N][M])  {
 
  int top = 0, bottom = rows - 1, left = 0, right = cols - 1;
  
  
  int dir = 1;
 
  while (top <= bottom && left <= right) {

    if (dir == 1) {    
      for (int i = left; i <= right; ++i) {
        cout<<arr[top][i]  << " ";
      }

      ++top;
      dir = 2;
    } 
    else if (dir == 2) {  
      for (int i = top; i <= bottom; ++i) {
          cout<<arr[i][right]  << " ";
      }
      
      --right;
      dir = 3;
    } 
    else if (dir == 3) {  
      for (int i = right; i >= left; --i) {
          cout<<arr[bottom][i] << " ";
      }
      
      --bottom;
      dir = 4;
    } 
    else if (dir == 4) {  
      for (int i = bottom; i >= top; --i) {
          cout<< arr[i][left] << " ";
      }
      
      ++left;
      dir = 1;
    }
  }
}

int main() {
  int mat[N][M] = { { 1, 2, 3, 4 }, 
                  { 12, 13, 14, 5 }, 
                  { 11, 16, 15, 6 }, 
                  { 10, 9, 8, 7 } };
  
  spiralMatrixPrint(N, M, mat); 
  return 0; 
}
