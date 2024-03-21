class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        long long currSum = 0;
        long long potentialSum = 0;

        for(int i=0; i<nums.size(); i++) {
            if(nums[i] < currSum) {
                potentialSum = currSum + nums[i];
            }

            currSum += nums[i];
        }

        if(potentialSum == 0) {
            return -1;
        }

        return potentialSum;
    }
};