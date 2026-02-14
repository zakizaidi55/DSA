class Solution {
public:
    double solveUsingRec(int poured, int row, int col) {
        if(row < 0 || col < 0 || row < col) 
            return 0;
        
        if(row == 0 && col == 0) 
            return poured;
        
        double leftSideUp = (solveUsingRec(poured, row-1, col-1) - 1)/2.0;
        double rightSideUp = (solveUsingRec(poured, row-1, col) - 1)/2.0;

        if(leftSideUp < 0 )
            leftSideUp = 0;
        
        if(rightSideUp < 0) 
            rightSideUp = 0;
        
        return leftSideUp + rightSideUp;
    }

    double solveUsingMem(int poured, int row, int col, vector<vector<double> >&dp) {
        if(row < 0 || col < 0 || row < col) 
            return 0.0;
        
        if(row == 0 && col == 0) 
            return poured;
        
        if(dp[row][col] != -1) 
            return dp[row][col];
        
        double leftSideUp = (solveUsingMem(poured, row-1, col-1, dp) - 1)/2.0;
        double rightSideUp = (solveUsingMem(poured, row-1, col, dp) - 1)/2.0;

        if(leftSideUp < 0 )
            leftSideUp = 0.0;
        
        if(rightSideUp < 0) 
            rightSideUp = 0.0;
        
        return dp[row][col] = leftSideUp + rightSideUp;
    }

    double champagneTower(int poured, int query_row, int query_glass) {
        vector<vector<double> >dp(101, vector<double>(101, -1));
        // return solveUsingRec(poured, query_row, query_glass);
        // catch yha mistake kari thi agr Champagne zyada hogi toh wo niche hi giregi
        return min(1.0, solveUsingMem(poured, query_row, query_glass, dp));
    }
};


