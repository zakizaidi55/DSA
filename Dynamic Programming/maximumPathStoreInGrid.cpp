class Solution {
public:
    int solveUsingRec(vector<vector<int>>& grid, int i, int j, int cost, int k) {
        // base case
        int m = grid.size();
        int n = grid[0].size();
        if(i >= m || j >= n)
            return -1;
        
        int newCost = cost + (grid[i][j] == 0 ? 0 : 1);
        if(newCost > k)
            return -1;
        
        if(i == m-1 && j == n-1) 
            return grid[i][j];

        int right = solveUsingRec(grid, i, j+1, newCost, k);
        int down = solveUsingRec(grid, i+1, j, newCost, k);

        int best = max(right, down);
        if(best == -1)
            return -1;

        return grid[i][j] + best;
    }
    int solveUsingMem(vector<vector<int>>& grid, int i, int j, int cost, int k, vector<vector<vector<int> > >&dp) {
        // base case
        int m = grid.size();
        int n = grid[0].size();
        if(i >= m || j >= n)
            return -1;
        
        int newCost = cost + (grid[i][j] == 0 ? 0 : 1);
        if(newCost > k)
            return -1;
        
        if(i == m-1 && j == n-1) 
            return grid[i][j];
        
        if(dp[i][j][newCost] != INT_MIN)
            return dp[i][j][newCost];

        int right = solveUsingMem(grid, i, j+1, newCost, k, dp);
        int down = solveUsingMem(grid, i+1, j, newCost, k, dp);

        int best = max(right, down);

        if(best == -1)
            return dp[i][j][newCost] = -1;

        return dp[i][j][newCost] = grid[i][j] + best;
    }
    int maxPathScore(vector<vector<int>>& grid, int k) {
        int score = 0;
        int cost = 0;
        // 3d dp
        vector<vector<vector<int> > >dp(grid.size()+1, vector<vector<int> >(grid[0].size()+1, vector<int>(k+1, INT_MIN)));
        // return solveUsingRec(grid, 0, 0, cost, k);
        return solveUsingMem(grid, 0, 0, cost, k, dp);
    }
};


