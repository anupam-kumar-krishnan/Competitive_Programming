#include <iostream>
#include <vector>
#include <algorithm >
using namespace std;

void setZeroes(vector<vector<int>>& matrix) {
    vector<int> rowz(matrix.size(),1);
    vector<int> columnz(matrix[0].size(),1);
    for (int i=0; i<matrix.size();i++){
        for (int j=0; j<matrix[0].size();j++){
            if (matrix[i][j]==0){
                rowz[i]=0;
                columnz[j]=0;
                
            }
        }
    }
    for (int i=0; i<matrix.size();i++){
        for (int j=0; j<matrix[0].size();j++){
            if(rowz[i]==0 || columnz[j]==0){
                matrix[i][j]=0;
            }
        }
    }
    
    
}
int main(){
    vector<vector<int>> nums={{0,1,2,0},{3,4,5,2},{1,3,1,5}};
    setZeroes(nums);
    for(int i=0; i<nums.size(); i++){
        for(int j=0; j<nums[i].size(); j++){
            cout<<nums[i][j]<<" ";
        }
    }
}
