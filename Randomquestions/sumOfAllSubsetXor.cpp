class Solution {
public:
    void solve(vector<int>& nums, int index, vector<int>&currSubset, vector<vector<int>>& subsets) {
        if(index == nums.size()) {
            subsets.push_back(currSubset);
            return;
        }

        currSubset.push_back(nums[index]);
        solve(nums, index+1, currSubset, subsets);

        // backtrack
        currSubset.pop_back();

        solve(nums, index+1, currSubset, subsets);
    }

    int subsetXORSum(vector<int>& nums) {
        vector<vector<int> >subsets;

        vector<int>currSubset;

        solve(nums, 0, currSubset, subsets);

        int result = 0;
        for(auto subset: subsets) {
            int Xor = 0;
            for(int num: subset) {
                Xor ^= num;
            }

            result += Xor;
        }

        return result;
    }
};