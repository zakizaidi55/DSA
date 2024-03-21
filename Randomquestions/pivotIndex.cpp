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


// ------------------Method 2------------------------------------

class Solution {
public:
    int prefixSumApproach(vector<int>& nums) {
        vector<int> lSum(nums.size(), 0);
        vector<int> rSum(nums.size(), 0);
        // calculte left sum array 
        for(int i=1; i<nums.size(); i++) {
            lSum[i] = lSum[i-1] + nums[i-1];
        }
        // calculate right sum array
        for(int i = nums.size()-2; i>=0; i--) {
            rSum[i] = rSum[i+1] + nums[i+1];
        }

        for(int i=0; i<nums.size(); i++) {
            if(lSum[i] == rSum[i])
                return i;
        }

        return -1;
    }

    int pivotIndex(vector<int>& nums) {
        return prefixSumApproach(nums);
    }
};