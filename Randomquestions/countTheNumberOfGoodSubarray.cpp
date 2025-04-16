class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mp;
        int i = 0;
        int j = 0;

        long long pair = 0;
        long long result = 0;

        while(j < n) {
            //first check ki humne yeh number map m dekha h
            pair += mp[nums[j]];

            //update the freq of number in map
            mp[nums[j]]++;

            while(pair >= k) {
                //jab humko k pairs mil jayege toh result add kar dege
                result += (n-j);
                // ab i ko aage badhayege or freq m se -- karege
                mp[nums[i]]--;

                //pairs se bhi wo count delete ho jayega
                pair -= mp[nums[i]];
                i++;
            }

            j++;
        }

        return result;
    }
};

