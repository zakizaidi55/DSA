class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int s = 0; 
        int e = nums.size()-1;
        int ans = -1;
        while(s <= e) {
            int mid = s + (e-s)/2;
            
            if(s == e) {
                ans = nums[s];
                break;
            }


            if(mid & 1) {
                // mid is on odd index
                // check whether we are on left or right
                if(nums[mid] == nums[mid-1]) {
                    // Left side
                    s = mid+1;
                }

                else {
                    e = mid-1;
                }
            }

            else {
                // mid is on even index
                if(nums[mid] == nums[mid+1]) {
                    // left side
                    s = mid+2;
                }

                else {
                    // Whether we are on ans or not
                    e = mid;
                }
            }
        }

        return ans;
    }
};