class Solution {
public:
    // int solveUsingRec(int i, int j, vector<vector<int>>& grid) {
    //     int n = grid.size();
    //     if(i == n-1) {
    //         return grid[i][j];
    //     }

    //     if(j < 0 || j >= n) {
    //         return INT_MAX;
    //     }

    //     int ans = INT_MAX;
    //     for(int col=0; col<n; col++) {
    //         if(col != j) {
    //             ans = min(ans, grid[i][j] + solveUsingRec(i+1, col, grid));
    //         }
    //     }

    //     return ans;
    // }
    

        int solveUsingMem(int i, int j, vector<vector<int>>& grid, vector<vector<int> >&dp) {
        int n = grid.size();
        if(i == n-1) {
            return grid[i][j];
        }

        if(j < 0 || j >= n) {
            return INT_MAX;
        }
        if(dp[i][j] != -1) {
            return dp[i][j];
        }

        int ans = INT_MAX;
        for(int col=0; col<n; col++) {
            if(col != j) {
                ans = min(ans, grid[i][j] + solveUsingMem(i+1, col, grid, dp));
            }
        }

        return dp[i][j] = ans;
    }

    int minFallingPathSum(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        vector<vector<int> >dp(row+1, vector<int>(col+1, -1));
        int ans = INT_MAX;
        for(int j=0; j<col; j++) {
            ans = min(ans, solveUsingMem(0, j, grid, dp));
        }

        return ans;
    }
};