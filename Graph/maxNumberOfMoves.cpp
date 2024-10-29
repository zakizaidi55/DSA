class Solution {
public:
    int dfs(int row, int col, vector<vector<int> >&grid, vector<vector<int> >&dp) {
        vector<int>directions = {-1, 0, 1};

        if(dp[row][col] != -1) {
            return dp[row][col];
        }

        int result = 0;
        for(auto&dir: directions) {
            int newRow = row + dir;
            int newCol = col + 1;

            if(newRow >= 0 && newRow < grid.size() && newCol >= 0 && newCol < grid[row].size() && grid[newRow][newCol] > grid[row][col]) {
                result = max(result, 1 + dfs(newRow, newCol, grid, dp) );
            }
        }

        dp[row][col] = result;

        return dp[row][col];
    }
    int maxMoves(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<int> >dp(rows+1, vector<int>(cols+1, -1));
        int result = 0;
        for(int i=0; i<rows; i++) {
            result = max(result, dfs(i, 0, grid, dp));
        }

        return result;
    }
};