class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int maxDiff = -1;
        int minElement = nums[0];
        int j = 1;

        while(j < nums.size()) {
            if(nums[j] > minElement) {
                maxDiff = max(maxDiff, nums[j] - minElement);
            }

            else {
                minElement = nums[j];
            }
            j++;
        }

        return maxDiff;
    }
};
