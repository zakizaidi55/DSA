class Solution {
public:
    bool checkOnesSegment(string s) {
        int count = 0;
        int i = 0;
        while(i < s.size()) {
            if(s[i] == '1') {
                count++;
                while(i < s.size() && s[i] == '1') {
                    i++;
                }
            }

            else {
                i++;
            }
        }

        return count == 1 ? true : false;
    }
};


