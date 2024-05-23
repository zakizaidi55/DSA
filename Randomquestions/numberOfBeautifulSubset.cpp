class Solution {
public:
    void solveUsingRecursion(int index, vector<int>&nums, unordered_map<int, int>&mp, int k, int& result) {

        // base case
        if(index >= nums.size()) {
            result++;
            return;
        }
        
        // take
        if(!mp[nums[index]-k] && !mp[nums[index]+k]) {
            // take that number
            mp[nums[index]]++;
            solveUsingRecursion(index+1, nums, mp, k, result);
            mp[nums[index]]--;
        }

        // not take
        solveUsingRecursion(index+1, nums, mp, k, result);

    }
    int beautifulSubsets(vector<int>& nums, int k) {
        int result = 0;
        unordered_map<int, int>mp;

        solveUsingRecursion(0, nums, mp, k, result);
        return result-1;
    }
};