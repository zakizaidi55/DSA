class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string ans = "";
        for(string&str: words) {
            int charWeight = 0;
            for(char ch: str) {
                charWeight += weights[ch - 'a'];
            }

            ans.push_back('z' - (charWeight % 26));
        }

        return ans;
    }
};


