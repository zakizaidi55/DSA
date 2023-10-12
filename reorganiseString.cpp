class Solution {
public:
    string reorganizeString(string s) {
        int hash[26] = {0};

        for(int i=0; i<s.size(); i++) {
            hash[s[i] - 'a']++;
        }

        // find the most frequent character
        char mostFreqCh;
        int maxFreq = INT_MIN;

        for(int i=0; i<26; i++) {
            if(hash[i] > maxFreq) {
                maxFreq = hash[i];
                mostFreqCh = i + 'a';
            }
        }

        int index = 0;
        while(maxFreq > 0 && index < s.size()) {
            s[index] = mostFreqCh;
            maxFreq--;
            index += 2;
        }

        if(maxFreq != 0) {
            return "";
        }

        hash[mostFreqCh - 'a'] = 0;

        // lets place the rest of the ch
        for(int i=0; i<26; i++) {
            while(hash[i] > 0) {
                index = index >= s.size()?1 : index;
                s[index] = i + 'a';
                hash[i]--;
                index += 2;

            }
        }

        return s;
    }
};