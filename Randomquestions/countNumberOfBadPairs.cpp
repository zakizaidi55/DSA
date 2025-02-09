class Solution {
    public:
        long long countBadPairs(vector<int>& nums) {
            long long result = 0;
    
            for(int i=0; i<nums.size(); i++) {
                nums[i] = nums[i] - i;
            }
    
            unordered_map<int, int> mp;
    
            mp[nums[0]] = 1;
    
            for(int j=1; j<nums.size(); j++) {
                int totalNumberBeforej = j;
    
                int freq = mp[nums[j]];
    
                int totalNumberOfBadPair = totalNumberBeforej - freq;
    
                result += totalNumberOfBadPair;
                mp[nums[j]]++;
            }
    
            return result;
        }
    };