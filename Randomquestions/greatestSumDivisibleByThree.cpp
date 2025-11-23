class Solution {
public:
    int solveUsingRec(vector<int>&nums, int index, int mod) {
        if(index >= nums.size()) 
            return mod == 0 ? 0 : INT_MIN;
        
        int include = nums[index] + solveUsingRec(nums, index+1, (mod+nums[index])%3);
        int exclude = 0 + solveUsingRec(nums, index+1, mod);

        return max(include, exclude);
    }

    int solveUsingMem(vector<int>&nums, int index, int mod, vector<vector<int> >&dp) {
        if(index >= nums.size()) 
            return mod == 0 ? 0 : INT_MIN;
        
        if(dp[index][mod] != -1)
            return dp[index][mod];
        
        int include = nums[index] + solveUsingMem(nums, index+1, (mod+nums[index])%3, dp);
        int exclude = 0 + solveUsingMem(nums, index+1, mod, dp);

        dp[index][mod] =  max(include, exclude);

        return dp[index][mod];
    }

    int maxSumDivThree(vector<int>& nums) {
        int index = 0;
        int mod = 0;
        vector<vector<int> >dp(nums.size()+1, vector<int>(3, -1));
        // return solveUsingRec(nums, index, mod);
        return solveUsingMem(nums, index, mod, dp);
    }
};


