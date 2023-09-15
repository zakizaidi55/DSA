class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int index=0; index<n; index++) {
            sum += nums[index];
        }

        int totalSum = (n*(n+1))/2;
        int ans = totalSum - sum;
        return ans;
    }
};