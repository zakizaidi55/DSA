class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int result = 0;
        unordered_map<string, int>mp;

        for(string&word: words) {
            string rev = word;
            swap(rev[0], rev[1]);

            if(mp[rev] > 0) {
                result += 4;
                mp[rev]--;
            } 
            else {
                mp[word]++;
            }
        }

        //check for equal characters
        for(auto it: mp) {
            string word = it.first;
            int count = it.second;

            if(word[0] == word[1] && count > 0) {
                result += 2;
                break;
            }
        }

        return result;
    }
};


