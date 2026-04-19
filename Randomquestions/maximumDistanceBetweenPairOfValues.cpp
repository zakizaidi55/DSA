class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) { 
        int result = 0;

        for(int i=0; i<nums1.size(); i++) {
            int start = i;
            int end = nums2.size() - 1;

            while(start <= end) {
                int mid = start + (end - start)/2;

                if(nums2[mid] >= nums1[i]) {
                    result = max(result, mid - i);
                    start = mid+1;
                } 
                else {
                    end = mid - 1;
                }
            }
        }

        return result;
    }
};


