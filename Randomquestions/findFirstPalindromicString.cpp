class Solution {
public:
    bool checkPalindrome(string str) {
        int start = 0;
        int end = str.size()-1;

        while(start <= end) {
            if(str[start] != str[end]) {
                return false;
            }
            start++;
            end--;
        }

        return true;
    }
    string firstPalindrome(vector<string>& words) {
        string ans = "";
        for(string str:words) {
            if( checkPalindrome(str)) {
               ans = str;
               break;
            }
            
        }

        return ans;
    }
};