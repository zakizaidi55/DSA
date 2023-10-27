class Solution {
public:
    int maxSubArrayhelper(vector<int>& nums, int start, int end) {
        if(start == end) {
            return nums[start];
        }

        int maxLeftBorderSum = INT_MIN;
        int maxRightBorderSum = INT_MIN;
        int leftBorderSum = 0;
        int rightBorderSum = 0;
        int mid = start + ((end-start) >>1);

        int maxLeftSum = maxSubArrayhelper(nums, start, mid);
        int maxRightSum = maxSubArrayhelper(nums, mid+1, end);

        // maximum cross border sum
        for(int i=mid; i>=start; i--) {
            leftBorderSum += nums[i];
            if(leftBorderSum > maxLeftBorderSum) {
                maxLeftBorderSum = leftBorderSum;
            }
        } 

        for(int i=mid+1; i<=end; i++) {
            rightBorderSum += nums[i];
            if(rightBorderSum > maxRightBorderSum) {
                maxRightBorderSum = rightBorderSum;
            }
        }

        int crossBorderSum = maxLeftBorderSum + maxRightBorderSum;
        return max(maxLeftSum, max(maxRightSum, crossBorderSum));
    }
    int maxSubArray(vector<int>& nums) {
        return maxSubArrayhelper(nums, 0, nums.size()-1);
    }
};