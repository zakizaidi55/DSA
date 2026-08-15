class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int result = 0;
        bool allZero = true;
        for(int i: nums ) {
            result ^= i;

            if(i != 0)
                allZero = false;
        }

        if(allZero) 
            return 0;

        return result == 0 ? nums.size()-1 : nums.size(); 
    }
};


