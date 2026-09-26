class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string>mp;
        for(auto str: knowledge) {
            mp[str[0]] = str[1];
        }

        string result = "";
        int i = 0;
        while(i < s.size()) {
            if(isalpha(s[i])) {
                result.push_back(s[i]);
            }
            else {
                // iska matlab mujeh koi open ya close bracket mila hai
                i++;
                string temp = "";
                while(i < s.size() && s[i] != ')') {
                    temp.push_back(s[i]);
                    i++;
                }

                result += mp.count(temp) ? mp[temp] : "?";
            }
            i++;
        }

        return result;
    }
};


