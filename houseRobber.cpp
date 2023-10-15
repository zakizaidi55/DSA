class Solution {
public:
    int solve(vector<int>& nums, int size, int index) {
        // base case
        if(index >= size)
            return 0;
        
        // we did robbery on 0th index
        int option1 = nums[index] + solve(nums, size, index+2);

        // we did not do robbery on 0th index
        int option2 = 0 + solve(nums, size, index+1);

        int finalAns = max(option1, option2);

        return finalAns;
    }
    int rob(vector<int>& nums) {
        int size = nums.size();
        int index = 0;

        int ans = solve(nums, size, index);

        return ans;
    }
};