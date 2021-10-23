class Solution {
    public static int[][] visited;
    public int numIslands(char[][] grid) {  
        int sum = 0;
        visited = new int[grid.length][grid[0].length];
        for(int i = 0; i < grid.length; i++){
            for(int j = 0; j < grid[0].length; j++){
                if(grid[i][j]-'0'==1&&visited[i][j]==0){
                    sum++;
                    traverse(i, j, grid);
                }
            }
        }
        return sum;
    }
    public static void traverse(int i, int j, char[][] grid){
        visited[i][j] = 1;
        if(i-1>=0&&grid[i-1][j]-'0'==1&&visited[i-1][j]==0){
            traverse(i-1, j, grid);
        }
        if(j-1>=0&&grid[i][j-1]-'0'==1&&visited[i][j-1]==0){
            traverse(i, j-1, grid);
        }
        if(i+1<grid.length&&grid[i+1][j]-'0'==1&&visited[i+1][j]==0){
            traverse(i+1, j, grid);
        }
        if(j+1<grid[0].length&&grid[i][j+1]-'0'==1&&visited[i][j+1]==0){
            traverse(i, j+1, grid);
        }
    }
}
