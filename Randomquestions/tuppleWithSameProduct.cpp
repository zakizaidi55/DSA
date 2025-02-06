class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int totalNumberOfTuples = 0;
        int n = nums.size();
        sort(begin(nums), end(nums));

        for (int i = 0; i < n; i++) {          
            for (int j = n - 1; j > i; j--) {  

                int product = nums[i] * nums[j];
                unordered_set<int> st;

                for (int k = i+1; k < j; k++) {  
                    
                    if(product % nums[k] == 0) {
                        int lValue = product/nums[k];

                        if(st.count(lValue)) {
                            totalNumberOfTuples++;
                        }

                        st.insert(nums[k]);
                    }
                }
            }
        }

        return totalNumberOfTuples * 8;
    
    }
};