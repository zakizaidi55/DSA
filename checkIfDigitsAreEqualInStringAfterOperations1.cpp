class Solution {
public:
    bool hasSameDigits(string s) {
        while(true) {
            string ans;
            int i = 0;
            while(i < s.size()-1) {
                char digit = '0' + ((s[i] - '0' + s[i + 1] - '0') % 10);
                ans.push_back(digit);
                i++;
            }
            s = ans;
            if(s.size() == 2) 
                break;
        }

        return s[0] == s[1];
    }
};


