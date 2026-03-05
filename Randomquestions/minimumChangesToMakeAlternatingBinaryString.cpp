
class Solution {
public:
    int minOperations(string s) {
        int n = s.length();
        int startWithZero = 0; // even index par 0 aana chahiye
        int startWithOne = 0; // even index par 1 aana chahiye
        for(int i=0; i<n; i++) {
            if(i % 2 == 0) {
                // even index
                if(s[i] == '1') {
                    startWithZero++;  
                }

                else {
                    startWithOne++;
                }
            }

            else {
                // odd index
                if(s[i] == '0') {
                    startWithZero++;
                }

                else {
                    startWithOne++;
                }
            }
        }

        return min(startWithZero, startWithOne);
    }
};


