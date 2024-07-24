class Solution {
public:
    string getMappedStr(string&num, vector<int>&mapping) {
        string mappedNum = "";
        for(int i=0; i<num.size(); i++) {
            char ch = num[i];
            int mappedInt = ch - '0';
            mappedNum += to_string(mapping[mappedInt]);
        }

        return mappedNum;
    }
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        int n = nums.size();

        vector<pair<int, int> >vec; //{mappedValue, index};

        for(int i=0; i<n; i++) {
            string numStr = to_string(nums[i]);

            string mappedStr = getMappedStr(numStr, mapping);

            int mappedNum = stoi(mappedStr);

            vec.push_back({mappedNum, i}); 
        }

        sort(vec.begin(), vec.end());

        vector<int>ans;
        for(auto&p: vec) {
            int mappedIndex = p.second;
            ans.push_back(nums[mappedIndex]);
        }

        return ans;
    }
};