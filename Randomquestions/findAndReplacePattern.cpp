class Solution {
public:
    void createMapping(string& str) {
        char start = 'a';
        char mapping[300] = {0};
        
        for(auto ch: str) {
            if(mapping[ch] == 0) {
                mapping[ch] = start;
                start++;

            }
        }
        // update the mapping
        for(int i=0; i<str.length(); i++) {
            char ch = str[i];
            str[i] = mapping[ch];
        }
    }
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ans;
        // normalise the pattern
        createMapping(pattern);

        // normalise all the words

        for(string s:words) {
            string tempString = s;

            // normalise string
            createMapping(tempString);

            if(tempString == pattern) {
                // it means that "s" string is valid answer
                ans.push_back(s);
            } 
        }

        return ans;
    }
};