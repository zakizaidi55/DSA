class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        int maxElementIndex = max_element(nums.begin(), nums.end()) - nums.begin();
        int minElementIndex = min_element(nums.begin(), nums.end()) - nums.begin();


        // ab mujhe find karna hai ki left m or right m kon h means ki small left m ha ya right m
        int left = min(maxElementIndex, minElementIndex);
        int right = max(maxElementIndex, minElementIndex);

        return min({1+left + n-right, right+1, n-left});
    }
};
