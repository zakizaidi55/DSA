class Solution {
public:
    const int M = 1e9 + 7;
    string states[12] = {"RYG", "RGY", "RYR", "RGR", "YRG", "YGR", "YGY", "YRY", "GRY", "GYR", "GRG", "GYG"};

    int solveUsingRec(int n, int prev) {
        if(n == 0)
            return 1;
        
        int result = 0;
        string last = states[prev];

        for(int curr=0; curr<12; curr++) {
            if(curr == prev)
                continue;
            
            string currPath = states[curr];
            bool isConflict = false;
            for(int col=0; col<3; col++) {
                if(last[col] == currPath[col]){
                    isConflict = true;
                    break;
                }
            }   

            if(!isConflict) {
                result = (result + solveUsingRec(n-1, curr)) %M;
            }                

        }

        return result;
    }

    int solveUsingMem(int n, int prev, vector<vector<int> >&dp) {
        if(n == 0)
            return 1;
        

        if(dp[n][prev] != -1)   
            return dp[n][prev];
        int result = 0;
        string last = states[prev];

        for(int curr=0; curr<12; curr++) {
            if(curr == prev)
                continue;
            
            string currPath = states[curr];
            bool isConflict = false;
            for(int col=0; col<3; col++) {
                if(last[col] == currPath[col]){
                    isConflict = true;
                    break;
                }
            }   

            if(!isConflict) {
                result = (result + solveUsingMem(n-1, curr, dp)) %M;
            }                

        }

        return dp[n][prev] = result;
    }

    int numOfWays(int n) {
        int result = 0;
        vector<vector<int> >dp(n, vector<int>(12, -1));
        for(int i=0; i<12; i++) {
            // result = (result + solveUsingRec(n-1, i)) % M;
            result = (result + solveUsingMem(n-1, i, dp)) % M;
        }

        return (result) % M;
    }
};


