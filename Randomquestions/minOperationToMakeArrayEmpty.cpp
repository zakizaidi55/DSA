class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int, int>mp;
        int count = 0;
        for(int i=0; i<nums.size(); i++) {
            mp[nums[i]]++;
        }

        for(auto it: mp) {
            if(it.second == 1) {
                return -1;
            }

            else if(it.second%3 == 0) {
                count += it.second/3;
            }

            else if(it.second%3 == 1) {
                count += 2 + (it.second-4)/3;
            }

            else if(it.second%3 == 2) {
                count += 1 + (it.second-2)/3;
            }
        }

        return count;
    }
};