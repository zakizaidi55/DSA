class Solution {
public:
    int maximumLengthSubstring(string s) {
        vector<int>freq(26, 0);
        int maxLength = 0;
        int i = 0;
        int j = 0;

        while(j < s.size()) {
            freq[s[j] - 'a']++;
            while(freq[s[j] - 'a'] > 2) {
                freq[s[i] - 'a']--;
                i++;
            }

            int len = j - i + 1;
            maxLength = max(maxLength, len);
            j++;
        }

        return maxLength;
    }
};


