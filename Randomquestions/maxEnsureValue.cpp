class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int i = 0;
        int j = 0;
        unordered_set<int>st;
        int result = INT_MIN;
        int sum = 0;
        while(j < nums.size()) {
            if(!st.count(nums[j])) {
                sum += nums[j];
                st.insert(nums[j]);
                result = max(sum, result);
                j++;
            }

            else {
                while(st.count(nums[j])) {
                    sum -= nums[i];
                    st.erase(nums[i]);
                    i++;
                }
            }
        }
        return result;
    }
};


