class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int ans = 0;
        long long sum = 0;
        for(auto&num: nums)
            sum += num;
        long long leftSum = 0;
        long long rightSum = 0;
        for(int i=0; i<nums.size()-1; i++) {
            leftSum += nums[i];
            rightSum = sum - leftSum;

            if(leftSum >= rightSum)
                ans++;
        }

        return ans;
    }
};