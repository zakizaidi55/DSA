// -------------------------------Method 1------------------------------------
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        for(int i=0; i<nums.size(); i++) {
            int lSum = 0;
            int rSum = 0;
            // find Left sum excluding the current index
            for(int j=0; j<i; j++) {
                lSum += nums[j];
            }

            // find right sum excluding the current index
            for(int j=i+1; j<nums.size(); j++) {
                rSum += nums[j];
            } 

            if(lSum == rSum)
                return i;
        }

        return -1;
    }
};