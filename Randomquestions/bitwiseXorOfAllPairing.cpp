class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        
        unordered_map<int, long long>mp;

        int m = nums1.size();
        int n = nums2.size();

        for(auto&num: nums1) {
            mp[num] += n;
        }


        for(auto&num: nums2) {
            mp[num] += m;
        }


        int result = 0;

        for(auto&it: mp) {
            int num = it.first;
            int freq = it.second;

            if(freq % 2 != 0) {
                result ^= num;
            }
        }

        return result;
        

        // ------------------- Brute Force -------------------
        // int m = nums1.size();
        // int n = nums2.size();


        // vector<int>nums3;
        // for(int i=0; i<m; i++) {
        //     for(int j=0; j<n; j++) {
        //         nums3.push_back(nums1[i]^nums2[j]);
        //     }
        // }

        // int result = 0;

        // for(int i=0; i<nums3.size(); i++) {
        //     result ^= nums3[i];
        // }

        // return result;
    }
};