class Solution {
public:
    int solve(vector<int>& nums, int start, int end) {
        if(start == end) {
            return nums[start];
        }

        // diff = p1-p2
        int diffByStart = nums[start] - solve(nums, start+1, end);
        int diffByEnd = nums[end] - solve(nums, start, end-1);

        return max(diffByStart, diffByEnd);
    }

    bool predictTheWinner(vector<int>& nums) {
        return solve(nums, 0, nums.size()-1) >= 0;
    }
};
