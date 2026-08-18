class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {

        if(k == nums.size()) {
            return *max_element(nums.begin(), nums.end());
        }

        int freq[51] = {0};
        for(int i=0; i<nums.size(); i++) {
            freq[nums[i]]++;
        }

        if(k == 1) {
            for(int i=50; i>=0; i--) {
                if(freq[i] == 1) {
                    return i;
                }
            }
        }

        // 1 < k < n
        int result = -1;
        // ab yha par do conditions h ki 
        // case1: pehla element max hoga kyuki bas wo hi ek baar aaya h
        if(freq[nums[0]] == 1) {
            result = max(nums[0], result);
        }
        // case2: last element kyuki wo ek baar aaya h window m
        
        if(freq[nums[nums.size()-1]] == 1) {
            result = max(result, nums[nums.size()-1]);
        }

        return result;


        // ----------------------Approcah1----------------------------------------
    

        // unordered_map<int, int>freq;
        // unordered_set<int>st;
        // int i = 0;
        // int j = 0;

        // while(j < nums.size()) {
        //     if(j-i+1 == k) {
        //         for(int l=i; l<=j; l++) {
        //             st.insert(nums[l]);
        //         }

        //         for(auto i: st) {
        //             freq[i]++;
        //         }

        //         st.erase(nums[i]);
        //         i++;
        //     }

        //     j++;
        // }

        // int result = -1;

        // for(auto[num, count]: freq) {
        //     if(count == 1 && num > result) {
        //         result = num;
        //     }
        // }

        // return result;
    }
};


