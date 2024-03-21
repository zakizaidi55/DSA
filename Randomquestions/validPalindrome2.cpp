class Solution {
public:
    bool checkPalindrome(string s, int start, int end) {
        while(start < end) {
            if(s[start] != s[end])
                return false;
            
            else
                start++, end--;
        }
        return true;
    }
    bool validPalindrome(string s) {
        int i = 0;
        int e = s.size() - 1;

        while(i < e) {
            if(s[i] == s[e]) {
                i++;
                e--;
            }

            else {
                // s[i] != s[e]
                // 1 removal allow
                // check palindrome for the remaining string after removal
                bool ans1 = checkPalindrome(s, i+1, e);
                bool ans2 = checkPalindrome(s, i, e-1);

                return ans1 || ans2;
            }
        } 

        // if we reach here it means it is a valid palindrome
        // it means without removal
        return true;
    }
};