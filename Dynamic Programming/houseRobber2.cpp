class Solution {
public:
    int solve(vector<int>& nums, int s, int e) {
        // base case
        if(s > e)
            return 0;
        
        // we did robbery on 0th index
        int option1 = nums[s] + solve(nums, s+2, e);

        // we did not do robbery on 0th index
        int option2 = 0 + solve(nums, s+1, e);

        int finalAns = max(option1, option2);

        return finalAns;
    }


    int solveUsingMem(vector<int>& nums, int s, int e, vector<vector<int> >&dp) {
        // base case
        if(s > e)
            return 0;
        
        if(dp[s][e] != -1) 
            return dp[s][e];
        // we did robbery on 0th index
        int option1 = nums[s] + solveUsingMem(nums, s+2, e, dp);

        // we did not do robbery on 0th index
        int option2 = 0 + solveUsingMem(nums, s+1, e, dp);

        int finalAns = max(option1, option2);

        dp[s][e] = finalAns;
        return dp[s][e];
    }

    int rob(vector<int>& nums) {
        
        int size = nums.size();
        // single element case
        if(size == 1)
            return nums[0]; //yha par galti kari thi
        vector<vector<int> >dp(size+1, vector<int>(size+1, -1));
        // int option1 = solve(nums, 0, size-2);
        // int option2 = solve(nums, 1, size-1);
        int option1 = solveUsingMem(nums, 0, size-2, dp);
        int option2 = solveUsingMem(nums, 1, size-1, dp);
        int ans = max(option1, option2);
        return ans;
    }
};