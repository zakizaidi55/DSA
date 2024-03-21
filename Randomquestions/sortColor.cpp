    void sortColors(vector<int>& nums) {
        int low = 0, mid = 0, high = nums.size() - 1;
        while(mid <= high) {
            if(nums[mid] == 0) {
                swap(nums[low], nums[mid]);
                low++;
                mid++;
            }

            else if(nums[mid] == 1){
                mid++;
            }

            else {
                swap(nums[mid], nums[high]);
                high--;
            }

        }
    }

// ---------------------Method 2------------------------------------------- 
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int left = 0;
        int right = nums.size()-1;
        int index = 0;

        while(index <= right) {
            if(nums[index] == 0) {
                swap(nums[left], nums[index]);
                left++;
                index++;

            }

            else if(nums[index] == 2) {
                swap(nums[right], nums[index]);
                right--;
                // catch -> no need of index++;
            }
            else {
                index++;
            }
        }
    }
};