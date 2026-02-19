class Solution {
public:
    int countBinarySubstrings(string s) {
        int prev = 0;
        int curr = 1;
        int result = 0;
        int i = 1;

        while(i < s.size()) {
            if(s[i] == s[i-1]) {
                curr++;
            }

            else {
                result += min(curr, prev);
                prev = curr;
                curr = 1;
            }
            i++;
        }

        return result += min(prev, curr);
    }
};


