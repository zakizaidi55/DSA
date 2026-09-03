class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int minElement = *min_element(nums1.begin(), nums1.end());
        if((minElement&1) == 1) 
            return true;
        
        else {
            for(int i:nums1) {
                if((i&1) == 1) 
                    return false;
            }
        }

        return true;
    }
};
