class Solution {
public:
    int findNonMinOrMax(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int startingIndex = 0;
        int lastIndex = nums.size()-1;
    
        int findIndex = lastIndex - startingIndex;
        // cout << "findIndex" << findIndex;
        if(findIndex == 1 || nums.size() == 1 )
            return -1;

        return nums[1];
        

    }
};