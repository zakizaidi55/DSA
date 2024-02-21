class Solution {
public:
    int solveUsingRecursion(string s, string t, int i, int j) {
        if(j == t.size() )
            return 1;
        if(i == s.size())
            return 0;
        
        int ans = 0;
        if(s[i] == t[j]) {
            ans += solveUsingRecursion(s, t, i+1, j+1);
        }

        ans += solveUsingRecursion(s,t, i+1, j);

        return ans;
    }

    // int solveUsingMem(string& s, string& t, int i, int j, vector<vector<int> >&dp) {
    //     if(j == t.size() )
    //         return 1;
    //     if(i == s.size())
    //         return 0;
        
    //     int ans = 0;
    //     if(dp[i][j] != -1) {
    //         return dp[i][j];
    //     }
    //     if(s[i] == t[j]) {
    //         ans += solveUsingMem(s, t, i+1, j+1, dp);
    //     }

    //     ans += solveUsingMem(s,t, i+1, j, dp);
    //     dp[i][j] = ans;
    //     return dp[i][j];
    // }

    int solveUsingTab(string&s, string& t) {
        vector<vector<int> >dp(s.size()+1, vector<int>(t.size()+1, 0));
        
        for(int i=0; i<=s.size(); i++) {
            dp[i][t.size()] = 1;
        }

        for(int i=s.size()-1; i>=0; i--) {
            for(int j=t.size()-1; j>=0; j--) {
                long long ans = 0;
                if(s[i] == t[j]) {
                    ans += dp[i+1][j+1];
                }

                ans += dp[i+1][j];
                dp[i][j] = ans;
     
            }
        }

        return dp[0][0];
    }

    int numDistinct(string s, string t) {
        // return solveUsingRecursion(s, t, 0, 0);
        // vector<vector<int> >dp(s.size()+1, vector<int>(t.size()+1, -1));
        // return solveUsingMem(s, t, 0, 0, dp);
        return solveUsingTab(s, t);
    }
};