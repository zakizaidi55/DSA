class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_map<int, bool>mp;
        for(int i: nums) {
            mp[i] = true;
        }
        int curr = k;
        // while(true) {
        //     int multiple = k*i;
        //     if(mp.find(multiple) == mp.end()) {
        //         return multiple;
        //     }

        //     i++;
        // }


        while(mp.count(curr)) {
            curr += k;
        }
        return curr;
    }
};


