class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int s = 0;
        int e = nums.size() - 1;
        int mid = s + (e-s)/2;

        while(s < e) {
            if(nums[mid] < nums[mid+1]) {
                // we are on left side, peak should be present on right
                s = mid+1;
            }

            else {
                // Whether I am on peak or right side
                e = mid;
            }

            mid = s + (e-s)/2;
        }

        return s;
    }
};