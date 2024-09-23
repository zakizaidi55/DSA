class Solution {
public:
    int solveUsingRec(int index, unordered_set<string>&st, string&s, int n) {
        if(index >= n) {
            return 0;
        }

        // exclude curr character
        int result = 1 + solveUsingRec(index+1, st, s, n);

        // include the current character

        for(int j=index; j<n; j++) {
            string currStr = s.substr(index, j-index+1);

            // check if it is present or not
            if(st.count(currStr)) {
                result = min(result, solveUsingRec(j+1, st, s, n));
            }
        }

        return result;
    }

    // int solveUsingMem(int index, unordered_set<string>&st, string&s, int n, vector<int>&dp) {
    //     if(index >= n) {
    //         return 0;
    //     }   


    //     if(dp[index] != -1) {
    //         return dp[index];
    //     }

    //     // exclude curr character
    //     int result = 1 + solveUsingMem(index+1, st, s, n, dp);

    //     // include the current character

    //     for(int j=index; j<n; j++) {
    //         string currStr = s.substr(index, j-index+1);

    //         // check if it is present or not
    //         if(st.count(currStr)) {
    //             result = min(result, solveUsingMem(j+1, st, s, n, dp));
    //         }
    //     }

    //     dp[index] = result;
    //     return dp[index];
    // }

    int solveUsingTab(unordered_set<string>&st, string&s, int n) {
        vector<int>dp(n+1, 0);

        for(int i=n-1; i>=0; i--) {
            // exclude curr character
            dp[i] = 1 + dp[i+1];

            // include the current character

            for(int j=i; j<n; j++) {
                string currStr = s.substr(i, j-i+1);

                // check if it is present or not
                if(st.count(currStr)) {
                    dp[i] = min(dp[i], dp[j+1]);
                }
            }
        }

        return dp[0];
    }

    int minExtraChar(string s, vector<string>& dict) {
        unordered_set<string>st(begin(dict), end(dict));

        return solveUsingTab( st, s, s.size());
        // vector<int>dp(s.size()+1, -1);

        // return solveUsingMem(0, st, s, s.size(), dp);
    }
};