class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int left = 0;
        int right = 0;
        int product = 1;
        int count = 0;

        int n = nums.size();
        if(k <= 1) {
            return 0;
        }

        while(right < n){
            product *= nums[right];
            while(product >= k) {
                product = product/nums[left];
                left++;
            }
            count += 1 + (right-left);
            right++;
        }

        return count;
    }
};


// --------------------------Method 2-----------------------------------
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int left = 0;
        int right = 0;
        int product = 1;
        int count = 0;

        int n = nums.size();
        if(k <= 1) {
            return 0;
        }

        while(right < n){
            product *= nums[right];
            while(product >= k) {
                product = product/nums[left];
                left++;
            }
            count += 1 + (right-left);
            right++;
        }

        return count;
    }
};