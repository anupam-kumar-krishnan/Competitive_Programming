// https://practice.geeksforgeeks.org/problems/flood-fill-algorithm1856/1

class Solution {
    private:
    void dfs(int row, int col, vector<vector<int>>& ans, vector<vector<int>>& image, 
    int newcolor, int delrow[], int delcol[], int inicolor){
        ans[row][col] = newcolor;
        int n = image.size();
        int m = image[0].size();
        for(int i=0; i<4; i++){
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && 
            image[nrow][ncol] == inicolor && ans[nrow][ncol] != newcolor){
                dfs(nrow, ncol, ans, image, newcolor, delrow, delcol, inicolor);
            }
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newcolor) {
        // Code here 
        int inicolor = image[sr][sc];
        vector<vector<int>> ans = image;
        int delrow[] = {-1, 0, +1, 0};
        int delcol[] = {0, +1, 0, -1};
        dfs(sr, sc, ans, image, newcolor, delrow, delcol, inicolor);
        return ans;
    }
};