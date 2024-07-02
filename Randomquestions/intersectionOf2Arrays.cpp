class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        int firstArrPointer = 0;
        int secondArrPointer = 0;
        vector<int>ans;
        while(firstArrPointer < nums1.size() && secondArrPointer < nums2.size()) {
            if(nums1[firstArrPointer] == nums2[secondArrPointer]) {
                ans.push_back(nums1[firstArrPointer]);
                firstArrPointer++;
                secondArrPointer++;
            }

            else if(nums1[firstArrPointer] < nums2[secondArrPointer]) {
                firstArrPointer++;
            }

            else {
                secondArrPointer++;
            }
        }

        return ans;
    }
};