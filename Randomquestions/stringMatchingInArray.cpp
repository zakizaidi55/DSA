class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        // ------------------------------TC - O(n^2 * lengthOfEachString)------------------------------
        // ------------------------------SC - O(n)------------------------------------------------------
        set<string>st;
        vector<string>ans;

        for(int i=0; i<words.size(); i++) {
            for(int j=0; j<words.size(); j++) {
                if(i != j && words[i].find(words[j]) != string::npos) {
                    st.insert(words[j]);
                }
            }
        }

        for(auto&s: st) {
            ans.push_back(s);
        }
        return ans;
    }
};