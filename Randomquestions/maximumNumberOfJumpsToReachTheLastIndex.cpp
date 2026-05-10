class Solution {
public:
    int solveUsingRec(vector<int>& nums, int target, int i) {
        if(i == nums.size()-1)
            return 0;
        
        int result = INT_MIN;

        for(int j=i+1; j<nums.size(); j++) {
            if(abs(nums[j] - nums[i]) <= target) {
                int temp = 1 + solveUsingRec(nums, target, j);

                result = max(result, temp);
            }
        }

        return result;
    }


    int solveUsingMem(vector<int>& nums, int target, int i, vector<int>&dp) {
        if(i == nums.size()-1)
            return 0;
        
        int result = INT_MIN;

        if(dp[i] != -1)
            return dp[i];

        for(int j=i+1; j<nums.size(); j++) {
            if(abs(nums[j] - nums[i]) <= target) {
                int temp = 1 + solveUsingMem(nums, target, j, dp);

                result = max(result, temp);
            }
        }

        return dp[i] = result;
    }
    int maximumJumps(vector<int>& nums, int target) {
        // int result = solveUsingRec(nums, target, 0);
        vector<int>dp(nums.size()+1, -1);
        int result = solveUsingMem(nums, target, 0, dp);
        return result < 0 ? -1 : result;
    }
};


