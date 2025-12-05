class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int totalSum = 0;
        for(int num: nums) {
            totalSum += num;
        }

        int i = 1;
        int leftSum = nums[0];
        int rightSum = totalSum - leftSum;
        int ans = 0;
        while(i < nums.size()) {
            int sum = leftSum - rightSum;
            if(sum%2 == 0) {
                ans++;
            }

            leftSum += nums[i];
            rightSum -= nums[i];
            i++;
        }

        return ans;
    }
};
