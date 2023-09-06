class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int maxLen = 0;
        unordered_set<int> s(nums.begin(), nums.end());
        for (int n : nums)
            s.insert(n);
        for (int i=0; i<nums.size(); i++) {
        int count = 1;
        int num = nums[i];
        if (s.find(nums[i]-1) == s.end()) {
            while (s.find(++num) != s.end()) 
                count++;
        }
        if (count > maxLen) 
            maxLen = count;
    }
    return maxLen;

    }
};