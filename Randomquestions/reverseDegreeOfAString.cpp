
class Solution {
public:
    int reverseDegree(string s) {
        int sum = 0;
        for(int i=0; i<s.size(); i++) {
            int index = i+1;
            int ch = 26 - (s[i] - 'a');

            sum += ch*index;
        }

        return sum;
    }
};
