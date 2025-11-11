class Solution {
public:
    // int solveUsingRec(vector<string>& strs, int m, int n, int index) {
    //     if(index == strs.size()) 
    //         return 0;
        
    //     int zeroCount = 0;
    //     int oneCount = 0;
    //     int ans = 0;

    //     for(int i=0; i<strs[index].size(); i++) {
    //         if(strs[index][i] == '0')
    //             zeroCount++;
    //         else
    //             oneCount++;
    //     }

    //     // include if possible
    //     if(m >= zeroCount && n >= oneCount) 
    //         ans = max(ans, 1 + solveUsingRec(strs, m-zeroCount, n-oneCount, index+1));
        
    //     // exclude
    //     ans = max(ans, solveUsingRec(strs, m, n, index+1));
    //     return ans;
    // }


    int solveUsingMem(vector<string>& strs, int m, int n, int index, vector<vector<vector<int> > > &dp) {
        if(index == strs.size()) 
            return 0;
        
        int zeroCount = 0;
        int oneCount = 0;
        int ans = 0;
        if(dp[index][m][n] != -1)
            return dp[index][m][n];
        for(int i=0; i<strs[index].size(); i++) {
            if(strs[index][i] == '0')
                zeroCount++;
            else
                oneCount++;
        }

        // include if possible
        if(m >= zeroCount && n >= oneCount) 
            ans = max(ans, 1 + solveUsingMem(strs, m-zeroCount, n-oneCount, index+1, dp));
        
        // exclude
        ans = max(ans, solveUsingMem(strs, m, n, index+1, dp));
        dp[index][m][n] = ans;
        return ans;
    }

    int findMaxForm(vector<string>& strs, int m, int n) {
        int index = 0;
        vector<vector<vector<int> > >dp(601, vector<vector<int> >(101, vector<int> (101, -1)));
        // return solveUsingRec(strs, m, n, index);
        return solveUsingMem(strs, m, n, index, dp);
    }
};


