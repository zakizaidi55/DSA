class Solution {
public:
    int solveUsingRec(string&s, int k, int i, int n) {
        if(i < 0) {
            return 0;
        }
        int bit = s[i] - '0';
        int decimalValue = pow(2, n-i-1) * bit;
        cout << "decimalVal " << decimalValue << endl;
        int exclude = solveUsingRec(s, k, i-1, n);

        int include = 0;
        if(k - decimalValue >= 0) {
            include = 1 + solveUsingRec(s, k-decimalValue, i-1, n);
        }

        return max(include, exclude);

    }

    int solveUsingMem(string&s, int size, int k, int i, int n, vector<vector<int> >&dp) {
        if(i < 0) {
            return 0;
        }

        if(dp[i][size] != -1) 
            return dp[i][size];

        int bit = s[i] - '0';
        int exclude = solveUsingMem(s, size, k, i-1, n, dp);

        int include = 0;
        if((k-(s[i] - '0')) * pow(2, size) >= 0) {
            include = 1 + solveUsingMem(s,size+1, k-(s[i] - '0') * pow(2, size), i-1, n, dp);
        }

        dp[i][size] = max(include, exclude);
        return dp[i][size];
    }

    int longestSubsequence(string s, int k) {
        int n = s.size();
        int i = n-1;
        int size = 0;

        int length = 0;
        long long powerValue = 1;
        
        for (int i =n-1; i>=0; i--) {
            if (s[i] == '0') {
                length++;
            } 
            else if(powerValue <= k) {
                length++;
                k -= powerValue;
            }

            if (powerValue <= k)
                powerValue <<= 1; 
        }
        
        return length;


        // vector<vector<int> >dp(n+1000, vector<int>(n+1000, -1));
        // // return solveUsingRec(s, k, i,n);
        // return solveUsingMem(s, size, k, i, n, dp);
    } 
};


