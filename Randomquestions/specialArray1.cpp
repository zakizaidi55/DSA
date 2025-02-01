class Solution {
public: 
bool isArraySpecial(vector<int>& nums) {
// -------------------Method 1 ------------------------
        // for(int i=0; i<nums.size()-1; i++) {
        //     if(nums[i]%2 == nums[i+1]%2)
        //         return false;
        // }

        // return true;

// -------------------Method 2 ------------------------
        for(int i=0; i<nums.size()-1; i++) {
            if((nums[i]&1) == (nums[i+1]&1))
                return false;
        }

        return true;
    }
};