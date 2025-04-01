class Solution {
public:
    long long solveUsingRec(vector<vector<int>>& questions, int index) {
        if(index >= questions.size()) {
            return 0;
        }

        long long include = questions[index][0] + solveUsingRec(questions, index+questions[index][1] + 1);
        long long exclude = solveUsingRec(questions, index+1);

        return max(include, exclude);
        
    }

    long long solveUsingMem(vector<vector<int>>& questions, int index, vector<long long>&dp) {
        if(index >= questions.size()) {
            return 0;
        }

        if(dp[index] != -1)
            return dp[index];

        long long include = questions[index][0] + solveUsingMem(questions, index+questions[index][1] + 1, dp);
        long long exclude = solveUsingMem(questions, index+1, dp);

        dp[index] = max(include, exclude);

        return dp[index];
        
    }
    long long mostPoints(vector<vector<int>>& questions) {
        int i = 0;
        vector<long long>dp(questions.size()+1, -1);
        // return solveUsingRec(questions, i);
        return solveUsingMem(questions, i, dp);
    }
};



