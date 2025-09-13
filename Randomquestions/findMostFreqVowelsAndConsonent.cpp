class Solution {
public:
    int maxFreqSum(string s) {
        unordered_map<char, int>freqCount;
        for(char ch:s) {
            freqCount[ch]++;
        }

        int vowelCount = 0;
        int cononentCount = 0;

        for(auto it: freqCount) {
            if(it.first == 'a' || it.first == 'e' || it.first == 'i' || it.first == 'o' || it.first == 'u') {
                vowelCount = max(vowelCount, it.second);
            }   

            else {
                // consonent
                cononentCount = max(cononentCount, it.second);
            }
        }

        return cononentCount + vowelCount;
    }
};


