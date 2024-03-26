class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, bool>mp;
        int maxi = *max_element(nums.begin(), nums.end());
        for(auto& num: nums) {
            mp[num] = true;
        }

        // check for the first positive missing number
        for(int i=1; i<maxi; i++) {
            if(mp.find(i) == mp.end()) {
                return i;
            }
        }

        // if all the integers are present in the map then return maxi+1;

        return maxi < 0 ? 1 : maxi+1;

    }
};