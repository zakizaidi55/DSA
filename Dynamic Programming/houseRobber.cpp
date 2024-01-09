class Solution {
public:
    int solveUsingRec(vector<int>& nums, int size, int index) {
        // base case
        if(index >= size)
            return 0;
        
        // we did robbery on 0th index
        int option1 = nums[index] + solveUsingRec(nums, size, index+2);

        // we did not do robbery on 0th index
        int option2 = 0 + solveUsingRec(nums, size, index+1);

        int finalAns = max(option1, option2);

        return finalAns;
    }

    int solveUsingMem(vector<int>& nums, int index, vector<int>&dp) {
        // base case
        int size = nums.size();
        if(index >= size)
            return 0;

        // step3: check the answer
        if(dp[index] != -1) {
            return dp[index];
        }
        
        // we did robbery on 0th index
        int option1 = nums[index] + solveUsingMem(nums, index+2, dp);

        // we did not do robbery on 0th index
        int option2 = 0 + solveUsingMem(nums, index+1, dp);
        // step2: store the answer in dp array and use it
        dp[index] = max(option1, option2);

        return dp[index];
    }

    int solveUsingTab(vector<int>& nums) {
        int n = nums.size();
        // step1
        vector<int>dp(n, -1);
        // step 2
        dp[n-1] = nums[n-1];

        for(int index=n-2; index>=0; index--) {
            int tempAns = 0;
            if(index + 2 < n) {
                tempAns = dp[index+2];
            }
            int option1 = nums[index] + tempAns;
            int option2 = 0 + dp[index+1];
            dp[index] = max(option1 ,option2);
        }

        return dp[0];
    }
    int rob(vector<int>& nums) {
        int size = nums.size();
        int index = 0;
        // step1: create a DP array
        vector<int>dp(size+1, -1);

        // int ans = solveUsingRec(nums, size, index);
        // int ans = solveUsingMem(nums, index, dp);
        int ans = solveUsingTab(nums);

        return ans;
    }
};