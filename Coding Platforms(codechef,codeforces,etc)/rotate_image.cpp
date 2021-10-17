class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix[0].size();
        vector<vector<int>> v( n , vector<int> (n));
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        for(int i=0;i<n;i++)
        {
            int m=v[i].size();
            int k=m-1;
            int j=0;
            while(j<k)
            {
                swap(matrix[i][j],matrix[i][k]);
                j++;
                k--;
            }
        }
       
    }
};
