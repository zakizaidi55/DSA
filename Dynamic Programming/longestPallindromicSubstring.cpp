class Solution {
public:
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
    int longestPalindromeSubseq(string s) {
        string a = s;
        reverse(a.begin(), a.end());
        int ans = solveUsingTabulationSO(s, a);
        return ans;
    }
};