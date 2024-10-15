class Solution {
public:
    long long minimumSteps(string s) {
        long long count = 0;

        long long blackCount = 0;

        int i = 0;

        while(i < s.size()) {
            if(s[i] == '0') {
                // white ball encounter
                count += blackCount;
            }

            else {
                blackCount++;
            }

            i++;
        }

        return count;
    }
};