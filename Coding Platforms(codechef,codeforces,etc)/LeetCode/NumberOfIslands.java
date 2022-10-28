class Solution 
{
    public int numIslands(char[][] grid) 
    {
        int n = grid.length;
        int m = grid[0].length;
        boolean[][] vis = new boolean[n][m];
        int islands = 0;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(!vis[i][j] && grid[i][j] == '1')
                {
                    dfs(i, j, grid, vis);
                    islands++;
                }
            }
        }
        return islands;
    }
    
    public void dfs(int i, int j, char[][] grid, boolean[][] vis)
    {
        int n = grid.length;
        int m = grid[0].length;
        if(i < 0 || i >= n || j < 0 || j >= m || vis[i][j] || grid[i][j] == '0')
            return;
        vis[i][j] = true;
        dfs(i+1, j, grid, vis);
        dfs(i-1, j, grid, vis);
        dfs(i, j+1, grid, vis);
        dfs(i, j-1, grid, vis);
    }
}
