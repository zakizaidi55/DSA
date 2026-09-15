class Solution {
public:
    bool isPalindromic(string&s, int i, int j) {
        while(i < j) {
            if(s[i] != s[j])
                return false;
            i++;
            j--;
        }

        return true;
    }
    int solveUsingRec(string&s, int k, int i, int j, int n) {
        if(i >= n || j >= n)
            return 0;
        
        if(isPalindromic(s, i, j)) {
            // mere pass yha 3 options h
            // option1: ki mujhe jo window mili, usko add karke aage rec se ans mangu
            int take = 1 + solveUsingRec(s, k, j+1, j+k, n);
            // option2: m apni window ka size grow karke check karu
            int grow = solveUsingRec(s, k, i, j+1, n);
            // option3: m window ko slide karke check karu
            int slideWindow = solveUsingRec(s, k, i+1, j+1, n);

            return max({take, grow, slideWindow});
        }
        // agr meri window palindrome nhi h toh mere pas 2 options h
        int grow = solveUsingRec(s, k, i, j+1, n);
        int slideWindow = solveUsingRec(s, k, i+1, j+1, n);

        return max(grow, slideWindow);
    }

    int solveUsingMem(string&s, int k, int i, int j, int n, vector<vector<int> >&dp) {
        if(i >= n || j >= n)
            return 0;
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        if(isPalindromic(s, i, j)) {
            // mere pass yha 3 options h
            // option1: ki mujhe jo window mili, usko add karke aage rec se ans mangu
            int take = 1 + solveUsingMem(s, k, j+1, j+k, n, dp);
            // option2: m apni window ka size grow karke check karu
            int grow = solveUsingMem(s, k, i, j+1, n, dp);
            // option3: m window ko slide karke check karu
            int slideWindow = solveUsingMem(s, k, i+1, j+1, n, dp);

            return dp[i][j] = max({take, grow, slideWindow});
        }
        // agr meri window palindrome nhi h toh mere pas 2 options h
        int grow = solveUsingMem(s, k, i, j+1, n, dp);
        int slideWindow = solveUsingMem(s, k, i+1, j+1, n, dp);

        return dp[i][j] = max(grow, slideWindow);
    }

    int maxPalindromes(string s, int k) {
        int n = s.size();
        if(k == 1)
            return n; // sab chars apne aap me palindrome h

        int i = 0;
        int j = k-1;
        vector<vector<int> >dp(n+1, vector<int>(n+1, -1));
        // return solveUsingRec(s, k, i, j, n);
        return solveUsingMem(s, k, i, j, n, dp);
    }
};
