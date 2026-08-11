class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int seqSum = nums[0];
        for(int i=1; i<nums.size(); i++) {
            if(nums[i] - nums[i-1] == 1) {
                seqSum += nums[i];
            }
            else 
                break;
        }

        unordered_set<int>st;
        for(int i=0; i<nums.size(); i++) {
            st.insert(nums[i]);
        }


        while(st.count(seqSum)) {
            seqSum++;
        }

        return seqSum;
    }
};
