class Solution {
public:
    int minMoves(vector<int>& nums) {
        if (nums.size() == 0) { 
            return 0;
        }
        int sum = 0; 
        int mini = INT_MAX;
        for (int num: nums) { 
            sum += num; 
            mini = min(mini, num);
        }
        return sum - nums.size() * mini;
    }
};