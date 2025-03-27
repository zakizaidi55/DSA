class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        unordered_map<int, int>mp1;
        unordered_map<int, int>mp2;

        for(int num: nums) {
            mp2[num]++;
        }

        for(int i=0; i<nums.size(); i++) {
            int num = nums[i];
            mp1[num]++;
            mp2[num]--;

            int n1 = i+1;
            int n2 = nums.size()-i-1;

            if(mp1[num] > n1/2 && mp2[num] > n2/2) {
                return i;
            }
        }

        return -1;
    }
};


