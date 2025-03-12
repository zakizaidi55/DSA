class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int left = 0;
        int right = nums.size()-1;

        //find first positive integer, greater than 0

        while(left <= right) {
            int mid = left + (right-left)/2;
            if(nums[mid] > 0) {
                right = mid-1;
            }

            else {
                left = mid+1;
            }
        }

        //left store last index of positive number
        int positiveCount = nums.size()-left;

        //find position of last negative number
        left = 0;
        right = nums.size()-1;

        while(left <= right) {
            int mid = left + (right-left)/2;
            if(nums[mid] < 0) {
                left = mid+1;
            }

            else {
                right = mid-1;
            }
        }

        int nagativeCount = right+1;
        
        return max(positiveCount, nagativeCount);
    }
};

