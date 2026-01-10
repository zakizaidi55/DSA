class Solution {
public:
    int solveUsingMem(string&s1, string&s2, int i, int j, vector<vector<int> >&dp) {
        if(i >= s1.size() && j >= s2.size()) 
            return 0;
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        if(i >= s1.size()) 
            return s2[j] + solveUsingMem(s1, s2, i, j+1, dp);
        
        if(j >= s2.size()) 
            return s1[i] + solveUsingMem(s1, s2, i+1, j, dp);
        
        if(s1[i] == s2[j]) 
            return solveUsingMem(s1, s2, i+1, j+1, dp);
        
        int option1 = s1[i] + solveUsingMem(s1, s2, i+1, j, dp);
        int option2 = s2[j] + solveUsingMem(s1, s2, i, j+1, dp);

        return dp[i][j] = min(option1, option2);
    }
    int minimumDeleteSum(string s1, string s2) {
        int i = 0; // to traverse over s1
        int j = 0; // to traverse over s2
        vector<vector<int> >dp(s1.size()+1, vector<int>(s2.size()+1, -1));
        return solveUsingMem(s1, s2, i, j, dp);
    }
};


