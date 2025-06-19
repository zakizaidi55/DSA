class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int minVal = nums[0];
        int count = 1; // this is the count of first subseq

        for(int i=0; i<nums.size(); i++) {
            if(nums[i] - minVal > k) {
                count++;
                minVal = nums[i];
            } 
        }

        return count;
    }
};


