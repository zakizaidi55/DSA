class Solution {
public:
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0 , 0, -1, 1} ;
    
    int dfs(vector<vector<int> >&grid, int row, int col, int totalRow, int totalCol) {
        // base case
        if(row < 0 || row >= totalRow || col < 0 || col >= totalCol || grid[row][col] == 0) 
            return 0;
            
        int currValue;
        int currGold = grid[row][col];
        currValue = currGold;
        grid[row][col] = 0;

        int localMax = currGold;

        for(int i=0; i<4; i++) {
            int newRow = row + dx[i];
            int newCol = col + dy[i];
            localMax = max(localMax, currGold + dfs(grid, newRow, newCol, totalRow, totalCol));
        }

        // catch - yahi par galti karta hu
        // backtrack
        grid[row][col] = currValue;

        return localMax;
        
    }

    int getMaximumGold(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int maxGold = 0;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j] != 0) {
                    maxGold = max(maxGold, dfs(grid, i, j, n, m));
                }
            }
        }

        return maxGold;
    }
};