class Solution {
public:
    int minOperations(vector<int>& nums) {
        stack<int>st;
        int count = 0;
        for(int i=0; i<nums.size(); i++) {
            while(!st.empty() && st.top() > nums[i]) {
                st.pop();
            }

            if(nums[i] == 0)
                continue;
            

            if(st.empty() || st.top() < nums[i]) {
                st.push(nums[i]);
                count++;
            }
        }

        return count;

        // ----------------- Approach 1 ---------------------
        // unordered_set<int>st(nums.begin(), nums.end());
        // int count = 0;
        
        // for(int element: st) {
        //     bool flow = false;
        //     if(element == 0)
        //         continue;
            
        //     for(int i=0; i<nums.size(); i++) {
        //         if (nums[i] == element) {
        //             if(!flow) {
        //                 flow = true;
        //                 count++;
        //             }
        //         }
        //         else if(nums[i] < element) {
        //             flow = false;
        //         }
        //     }
        // }

        // return count;
    }
};


