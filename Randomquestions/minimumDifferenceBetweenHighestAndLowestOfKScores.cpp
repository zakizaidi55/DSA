class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {        
        sort(nums.begin(), nums.end());
        int i = 0;
        int j = i + k - 1;
        int miniDiff = INT_MAX;

        while(j < nums.size()) {
            int mini = nums[i];
            int maxi = nums[j];

            miniDiff = min(miniDiff, maxi-mini);
            i++;
            j++;
        }

        return miniDiff;
    }
};


