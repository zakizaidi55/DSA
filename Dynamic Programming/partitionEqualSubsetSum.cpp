class Solution {
public:
    bool solveUsingRecursion(vector<int>&nums, int index, int sum, int targetSum) {
        if(index >= nums.size()) {
            return false;
        }

        if(sum > targetSum) {
            return false;
        }

        if(sum == targetSum) {
            return true;
        }


        bool include = solveUsingRecursion(nums, index+1, sum+nums[index], targetSum);
        bool exclude = solveUsingRecursion(nums, index+1, sum, targetSum);

        return (include || exclude);

    }
    

    bool solveUsingMem(vector<int>&nums, int index, int sum, int targetSum, vector<vector<int> >&dp) {
        if(index >= nums.size()) {
            return false;
        }

        if(sum > targetSum) {
            return false;
        }

        if(sum == targetSum) {
            return true;
        }

        if(dp[index][sum] != -1) {
            return dp[index][sum];
        }


        bool include = solveUsingMem(nums, index+1, sum+nums[index], targetSum, dp);
        bool exclude = solveUsingMem(nums, index+1, sum, targetSum, dp);

        dp[index][sum] = (include || exclude);
        return dp[index][sum];
    }

    bool solveUsingTab(vector<int>&nums, int targetSum) {
        int n = nums.size();
        vector<vector<int> >dp(n+2, vector<int>(targetSum+2, 0));
        for(int row=0; row<=n; row++) {
            dp[row][targetSum] = 1;
        }

        for(int index=n-1; index>=0; index--) {
            for(int sum=targetSum; sum>=0; sum--) {
                bool include = 0;
                if(sum + nums[index] <= targetSum) 
                    include = dp[index+1][sum+nums[index]];
                bool exclude = dp[index+1][sum];

                dp[index][sum] = (include || exclude);
            }
        }

        return dp[0][0];
    }

    bool solveUsingTabulationSO(vector<int>&arr, int target) {
        int n = arr.size();
        vector<int>curr(target+1, 0);
        vector<int>next(target+1, 0);

        curr[target] = 1;
        next[target] = 1;

        for(int ind=n-1; ind>=0; ind--) {
            for(int s=target; s>=0; s--) {
                bool include = 0;
                if(s + arr[ind] <= target) {
                    include = next[s+arr[ind]];
                }

                bool exclude = next[s];
                curr[s] = (include || exclude);
            }

            // shifting
            next = curr;
        } 

        return next[0];
        
    }

    bool canPartition(vector<int>& nums) {
        int index = 0;
        int totalSum = 0;
        
        for(int i=0; i<nums.size(); i++) {
            totalSum += nums[i];
        }

        if(totalSum &1) {
            // odd cannot be partitioned
            return false;
        }

        int targetSum = totalSum/2;
        int currSum = 0;
        int n = nums.size();
        vector<vector<int> >dp(nums.size()+1, vector<int>(targetSum+1, -1));
        // bool ans = solveUsingRecursion(nums, index, currSum, targetSum);
        // bool ans = solveUsingMem(nums, index, currSum, targetSum, dp);
        // bool ans = solveUsingTab(nums, targetSum);
        bool ans = solveUsingTabulationSO(nums, targetSum);
        return ans;


    }
};