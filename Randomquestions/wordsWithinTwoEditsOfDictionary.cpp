class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector<string>ans;

        for(string&query: queries) {
            for(string&dict: dictionary) {
                int diff = 0;
                for(int i=0; i<query.size(); i++) {
                    if(dict[i] != query[i]) {
                        diff++;
                    }

                    if(diff > 2) {
                        break;
                    }
                }

                if(diff <= 2) {
                    ans.push_back(query);
                    break;
                }
            }

            
        }
        return ans;
    }
};


