class Solution {
public: 
    const int MOD = 1e9 + 7;
    int solveUsingRec(vector<vector<int>>& grid, int i, int j, int m, int n, int cameFrom) {
        if(i >= m || j >= n) 
            return 0;
        
        if(i == m-1 && j == n-1) 
            return 1;
        
        if(grid[i][j] == 1) {
            // ab mujhe check karna h ki m yha kaha se aaya hu
            if(cameFrom == 0) {
                // iska matlab m left se aaya hu toh niche jana h
                return solveUsingRec(grid, i+1, j, m, n, 1) % MOD;
            }

            else {
                // iska matlab m  upar se aaya hu, right jana h
                return solveUsingRec(grid, i, j+1, m, n, 0) % MOD;
            }
        }

        // ab m simple 0 value par stand kar rha hu 
        int totalAns = 0;
        totalAns += solveUsingRec(grid, i+1, j, m, n, 1) % MOD;
        totalAns += solveUsingRec(grid, i, j+1, m, n, 0) % MOD;

        return totalAns;
    }

    int solveUsingMem(vector<vector<int>>& grid, int i, int j, int m, int n, int cameFrom, vector<vector<vector<int> > >&dp) {
        if(i >= m || j >= n) 
            return 0;
        
        if(i == m-1 && j == n-1) 
            return 1;
        
        if(dp[i][j][cameFrom] != -1) 
            return dp[i][j][cameFrom];
        
        if(grid[i][j] == 1) {
            // ab mujhe check karna h ki m yha kaha se aaya hu
            if(cameFrom == 0) {
                // iska matlab m left se aaya hu toh niche jana h
                return dp[i][j][cameFrom] = solveUsingMem(grid, i+1, j, m, n, 1, dp) % MOD;
            }

            else {
                // iska matlab m  upar se aaya hu, right jana h
                return dp[i][j][cameFrom] = solveUsingMem(grid, i, j+1, m, n, 0, dp) % MOD;
            }
        }

        // ab m simple 0 value par stand kar rha hu 
        int totalAns = 0;
        totalAns += solveUsingMem(grid, i+1, j, m, n, 1, dp) % MOD;
        totalAns += solveUsingMem(grid, i, j+1, m, n, 0, dp) % MOD;

        return dp[i][j][cameFrom] = totalAns;
    }

    int uniquePaths(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int i = 0;
        int j = 0;
        int cameFrom = 0; // 0- left, 1-up
        // return solveUsingRec(grid, i, j, m, n, cameFrom) % MOD;
        vector<vector<vector<int > > >dp(m+1, vector<vector<int > >(n+1, vector<int>(3, -1)));
        return solveUsingMem(grid, i, j, m, n, cameFrom, dp) % MOD;
    }
};


