class Solution {
public:
    bool solveUsingRec(vector<vector<char>>& grid, int i, int j, int m, int n, int count) {
        count += (grid[i][j] == '(') ? 1 : -1;
        if(count < 0)   
            return false;

        if(i == m-1 && j == n-1)
            return count == 0;

        if(i+1 < m && solveUsingRec(grid, i+1, j, m, n, count)) {
            return true;
        }

        if(j+1 < n && solveUsingRec(grid, i, j+1, m, n, count)) {
            return true;
        }

        return false;
    }


    bool solveUsingMem(vector<vector<char>>& grid, int i, int j, int m, int n, int count, vector<vector<vector<int> > >&dp) {
        count += (grid[i][j] == '(') ? 1 : -1;
        if(count < 0)   
            return false;
        
        if(dp[i][j][count] != -1)
            return dp[i][j][count];

        if(i == m-1 && j == n-1)
            return dp[i][j][count] = (count == 0);

        if(i+1 < m && solveUsingMem(grid, i+1, j, m, n, count, dp)) {
            return dp[i][j][count] = true;
        }

        if(j+1 < n && solveUsingMem(grid, i, j+1, m, n, count, dp)) {
            return dp[i][j][count] = true;
        }

        return dp[i][j][count] = false;
    }

    bool hasValidPath(vector<vector<char>>& grid) {
        int totalRows = grid.size();
        int totalCols = grid[0].size();

        if(totalRows*totalCols % 2 == 1) {
            // total odd count
            return false;
        }

        if(grid[0][0] == ')' || grid[totalRows-1][totalCols-1] == '('){
            return false;
        }
        
        int count = 0;

        vector<vector<vector<int > > >dp(101, vector<vector<int> >(101, vector<int>(201, -1)));
        // return solveUsingRec(grid, 0, 0, totalRows, totalCols, count);
        return solveUsingMem(grid, 0, 0, totalRows, totalCols, count, dp);
    }
};


