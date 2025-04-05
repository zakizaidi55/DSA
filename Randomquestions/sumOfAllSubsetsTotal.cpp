class Solution {
public:
    int solveUsingRec(vector<int>&nums, int index, int Xor) {
        if(index >= nums.size())
            return Xor;
        
        int include = solveUsingRec(nums, index+1, nums[index]^Xor);
        int exclude = solveUsingRec(nums, index+1, Xor);

        return include + exclude;
    }
    int subsetXORSum(vector<int>& nums) {
        int Xor = 0;
        int index = 0;
        return solveUsingRec(nums, index, Xor);
    }
};

