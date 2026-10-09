class Solution {
public:
    int minInsertions(string s) {
        int ans = 0;
        int openCount = 0;
        int i = 0;
        
        while(i < s.size()) {
            if(s[i] == '(') {
                openCount++;
                i++;
            }
            else {
                if(openCount > 0) {
                    openCount--;
                }

                else {
                    ans++;
                }

                if(s[i+1] == ')') {
                    i+=2;
                }

                else {
                    ans++;
                    i++;
                }
            }
        }

        return ans + (openCount*2);
    }
};


