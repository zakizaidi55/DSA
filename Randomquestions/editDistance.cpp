class Solution {
public:
    int solve(string& word1, string& word2, int i, int j) {
        // base case
        if(i >= word1.length()) {
            // word1 string is empty
            return word2.length() - j;
        }

        if(j >= word2.length()) {
            // word2 string end
            return word1.length() - i;
        }

        int ans = 0;
        if(word1[i] == word2[j]) {
            ans = 0 + solve(word1, word2, i+1, j+1);
     
        }

        else {
            // no match
            // perform operation
            // 1. insert
            int option1 = 1 + solve(word1, word2, i, j+1);
            // 2. remove
            int option2 = 1 + solve(word1, word2, i+1, j);
            // 3.replace
            int option3 = 1+ solve(word1, word2, i+1, j+1);
            ans = min(option1, min(option2, option3));
        }

        
        return ans;
    }
    int minDistance(string word1, string word2) {
        int i = 0;
        int j = 0;
        int ans = solve(word1, word2, i,j);
        return ans;
    }
};