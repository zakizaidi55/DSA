class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int i = -1;
        int j = 0;

        while(j < nums.size()) {
            if(nums[j] == 1 && i == -1) {
                // first 1 encounter
                i = j;
            } 

            else if(nums[j] == 1) {
                // encounter second 1
                if(j - (i + 1) < k)
                    return false;
                
                i = j;
            }

            j++;
        }

        return true;
    }
};
