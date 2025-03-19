class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int k = 0;
        for(int i=0; i<=n-3; i++)  {
            if(nums[i] == 0) {
                nums[i] ^= 1;
                nums[i+1] ^= 1;
                nums[i+2] ^= 1;
                k++;
            }
        }

        for(int i=0; i<nums.size(); i++) {
            if(nums[i] == 0)
                return -1;
        }

        return k;
    }
};



