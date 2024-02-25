class Solution {
public:
    bool checkWord(vector<string>&wordDict, string& s) {
        for(auto i:wordDict) {
            if(s == i)
                return true;
            
        }

        return false;
    }

    bool solve(string& s, vector<string>& wordDict, int start) {
        if(start == s.size()) 
            return true;
        
        // one case , make a string
        string word = "";
        bool flag = false;
        for(int i=start; i<s.size(); i++) {
            word += s[i];
            if(checkWord(wordDict, word)) {
                flag = flag || solve(s, wordDict, i+1);
            }
        }

        return flag;
    }

    // bool solveUsingMem(string& s, vector<string>& wordDict, int start, vector<int>&dp) {
    //     vector<int>dp(s.size()+1, -1);
    //     if(start == s.size()) 
    //         return true;
        

    //     // one case , make a string
    //     string word = "";
    //     bool flag = false;
    //     for(int i=start; i<s.size(); i++) {
    //         word += s[i];
    //         if(checkWord(wordDict, word)) {
    //             flag = flag || solveUsingMem(s, wordDict, i+1, dp);
    //         }
    //     }

    //     dp[start] = flag;
    //     return dp[start];
    // }


    bool solveUsingTab(string& s, vector<string>& wordDict) {

        vector<int>dp(s.size()+1, true);
        
        for(int start=s.size()-1; start>=0; start--) {
            string word = "";
            bool flag = false;
            for(int i=start; i<s.size(); i++) {
                word += s[i];
                if(checkWord(wordDict, word)) {
                    flag = flag || dp[i+1];
                }
            }

            dp[start] = flag;
            
        }

        return dp[0];

    }


    bool wordBreak(string s, vector<string>& wordDict) {
        // return solve(s, wordDict, 0);
        // vector<int>dp(s.size()+1, -1);
        // return solveUsingMem(s, wordDict, 0, dp);
        return solveUsingTab(s, wordDict);

    }
};