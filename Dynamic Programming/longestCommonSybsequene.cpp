class Solution {
public:
    int solveUsingRecursion(string text1, string text2, int i, int j) {
        // base case
        if(i >= text1.size() || j >= text2.size()) {
            return 0;
        }

        int ans = 0;
        if(text1[i] == text2[j]) {
            ans = 1 + solveUsingRecursion(text1, text2, i+1, j+1);
        }

        else {
            ans = 0 + max(solveUsingRecursion(text1, text2, i, j+1), solveUsingRecursion(text1, text2, i+1, j)); 
        }

        return ans;
        
    }

     int solveUsingMem(string &text1, string &text2, int i, int j, vector<vector<int> >&dp) {
        // base case
        if(i >= text1.size() || j >= text2.size()) {
            return 0;
        }

        if(dp[i][j] != -1) {
            return dp[i][j];
        }

        int ans = 0;
        if(text1[i] == text2[j]) {
            ans = 1 + solveUsingMem(text1, text2, i+1, j+1,dp);
        }

        else {
            ans = 0 + max(solveUsingMem(text1, text2, i, j+1, dp), solveUsingMem(text1, text2, i+1, j, dp)); 
        }

        dp[i][j] = ans;
        return dp[i][j];
        
    }

    int solveUsingTabulation(string text1, string text2) {
        vector<vector<int> >dp(text1.length()+1, vector<int>(text2.length()+1, -1));

        for(int i_index=text1.length()-1; i_index>=0; i_index--) {
            for(int j_index=text2.length()-1; j_index>=0; j_index--) {
                int ans = 0;
                if(text1[i_index] == text2[j_index]) {
                    ans = 1 + dp[i_index+1][j_index+1];
                }

                else {
                    ans = 0 + max(dp[i_index][j_index+1], dp[i_index+1][j_index]); 
                }

                dp[i_index][j_index] = ans;
            }
        }

        return dp[0][0]+1;
        
    }


    int solveUsingTabulationSO(string text1, string text2) {
        vector<int>curr(text1.length()+1, 0);
        vector<int>next(text1.length()+1, 0);
        for(int j_index=text2.length()-1; j_index>=0; j_index--) {
            for(int i_index=text1.length()-1; i_index>=0; i_index--) {
            
                int ans = 0;
                if(text1[i_index] == text2[j_index]) {
                    ans = 1 + next[i_index+1];
                }

                else {
                    ans = 0 + max(next[i_index], curr[i_index+1]); 
                }

                curr[i_index] = ans;
            }

            // shifting
            next = curr;
        }

        return next[0];
        
    }
    int longestCommonSubsequence(string text1, string text2) {
        int i = 0;
        int j = 0;
        // vector<vector<int> >dp(text1.length()+1, vector<int>(text2.length()+1, -1));
        // return solveUsingRecursion(text1, text2,i , j);

        // return solveUsingMem(text1, text2, i, j, dp);

        return solveUsingTabulationSO(text1, text2);
    
    }
};