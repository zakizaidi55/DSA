class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        int maxElemet = *max_element(nums.begin(), nums.end());
        vector<int>v(maxElemet+1, 0);
        for(int i=0; i<nums.size(); i++) {
            for(int j=i+1; j<nums.size(); j++) {
                int dist = abs(nums[i]-nums[j]);
                v[dist]++;
            }
        }

        for(int i=0; i<v.size(); i++) {
            k -= v[i];
            if(k <= 0) {
                return i;
            }
        }

        return -1;
    }
};