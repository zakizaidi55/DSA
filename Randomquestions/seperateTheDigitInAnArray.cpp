class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int>ans;

        for(int i: nums) {
            for(char ch: to_string(i)) {
                ans.push_back(ch - '0');
            }
        }
        return ans;
    }
};


