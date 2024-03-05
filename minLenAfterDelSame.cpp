class Solution {
public:
    int minimumLength(string s) {
        int ans = 0;
        int start = 0;
        int end = s.size()-1;

        while(start < end && s[start] == s[end]) {
            char ch = s[start];
            while(start<=end && s[start] == ch) {
                start++;
            }

            while(end>=start && s[end] == ch) {
                end--;
            }
        } 

        return end-start+1;
 
    }
};