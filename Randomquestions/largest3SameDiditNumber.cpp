class Solution {
public:
    string largestGoodInteger(string num) {
        string ans = "";

        for(int i=0; i<num.size()-2; i++) {
            if(num[i] == num[i+1] && num[i+1] == num[i+2]) {
                if(ans[0] < num[i] || ans.size() == 0) {
                    ans = "";
                    for(int j=0; j<3; j++) {
                        ans.push_back(num[i]);
                    }
                }
            }
        }

        return ans;
    }
};