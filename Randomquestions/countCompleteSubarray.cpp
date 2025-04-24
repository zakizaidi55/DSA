class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        unordered_set<int>uniqueCount;
        int n = nums.size();
        for(int i:nums) 
            uniqueCount.insert(i);
        
        int count = uniqueCount.size();

        unordered_map<int, int> mp;

        int i = 0;
        int j = 0;
        int ans = 0;

        while(j < n) {
            mp[nums[j]]++;

            while(mp.size() == count) {
                ans += (n - j);

                mp[nums[i]]--;
                //yha galti kari thi, agr uss entry ka count 0 ho gya toh usko map se remove bhi karna hoga
                if(mp[nums[i]] == 0)
                    mp.erase(nums[i]);
                i++;
            }

            j++;
        }

        return ans;
    }
};


