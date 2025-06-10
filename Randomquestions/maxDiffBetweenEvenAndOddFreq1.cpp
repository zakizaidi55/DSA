class Solution {
public:
    int maxDifference(string s) {
        vector<int>freq(26, 0);
        for(int i=0; i<s.size(); i++) {
            char ch = s[i];
            freq[ch-'a']++;
        }

        int maxOddFreq = INT_MIN;
        int minEvenFreq = INT_MAX;

        for(int i=0; i<26; i++) {
            if(freq[i] == 0)
                continue;
            if(freq[i]&1) {
                //odd freq
                maxOddFreq = max(maxOddFreq, freq[i]);
            }

            else {
                //even freq
                minEvenFreq = min(minEvenFreq, freq[i]);
            }
        }
        return maxOddFreq - minEvenFreq;
    }
};


