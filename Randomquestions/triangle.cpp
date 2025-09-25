class Solution {
public:
    int solveUsingMem(vector<vector<int>>& triangle, int row, int col, vector<vector<int> >&dp) {
        if(row == triangle.size()-1) {
            return triangle[row][col];
        }

        if(dp[row][col] != INT_MIN)
            return dp[row][col];

        int sameColAns = triangle[row][col] + solveUsingMem(triangle, row+1, col, dp);
        int nextColAns = triangle[row][col] + solveUsingMem(triangle, row+1, col+1, dp);

        dp[row][col] = min(sameColAns, nextColAns);

        return dp[row][col];
    }

    int solveUsingTab(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int> >dp(n, vector<int>(n, 0));

        for(int col=0; col<n; col++) {
            dp[n-1][col] = triangle[n-1][col];
        }

        for(int row=n-2; row>=0; row--) {
            for(int col=0; col<=row; col++) {
                int sameColAns = triangle[row][col] + dp[row+1][col];
                int nextColAns = triangle[row][col] + dp[row+1][col+1];

                dp[row][col] = min(sameColAns, nextColAns);
            }
        }

        return dp[0][0];
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        int row = 0;
        int col = 0;
        // vector<vector<int> >dp(triangle.size(), vector<int>(triangle.size(), INT_MIN));
        // return solveUsingMem(triangle, row, col, dp);

        return solveUsingTab(triangle);
    }
};


