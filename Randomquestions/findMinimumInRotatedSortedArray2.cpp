class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int start = 0;
        int end = n-1;

        int resultIndex = 0;
        while(start <= end) {
            while(start < end && nums[start] == nums[start+1]) {
                start++;
            }

            while(start < end && nums[end] == nums[end-1]){
                end--;
            }

            int mid = (start + end)/2;

            if(nums[mid] < nums[resultIndex]) {
                resultIndex = mid;
            }

            if(nums[0] <= nums[mid]) {
                start = mid+1;
            }

            else {
                end = mid-1;
            }
        }

        return nums[resultIndex];
    }
};


