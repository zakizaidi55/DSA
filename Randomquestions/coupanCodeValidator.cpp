class Solution {
public:
    bool isValidCode(string &code) {
        if(code.size() == 0)
            return false;
        
        for(auto ch: code) {
            if(!isalnum(ch) && ch != '_')
                return false;
        }

        return true;
    }
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        unordered_map<string, int >mp = {
            {"electronics", 0},
            {"grocery", 1},
            {"pharmacy", 2},
            {"restaurant", 3},
        };

        vector<pair<int, string> >temp; // index, code

        for(int i=0; i<code.size(); i++) {
            if(isActive[i] && mp.count(businessLine[i]) && isValidCode(code[i])) {
                temp.push_back({mp[businessLine[i]], code[i]});
            }
        }

        sort(temp.begin(), temp.end());
        vector<string>ans;

        for(auto&it: temp) {
            ans.push_back(it.second);
        }

        return ans;
    }
};


