class Solution {
public:
    int solveUsingRec(vector<int>& nums1, vector<int>& nums2, int m, int n, int i, int j, vector<vector<int> >&dp) {
        if(i >= m || j >= n)
            return -1e9;
        
        if(dp[i][j] != -1e9)
            return dp[i][j];
        
        int option1 = nums1[i] * nums2[j];
        int option2 = nums1[i] * nums2[j] + solveUsingRec(nums1, nums2, m, n, i+1, j+1, dp);
        int option3 = solveUsingRec(nums1, nums2, m, n, i, j+1, dp);
        int option4 = solveUsingRec(nums1, nums2, m, n, i+1, j, dp);

        return dp[i][j] = max(option1, max(option2, max(option3, option4)));
    }
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        vector<vector<int> >dp(501, vector<int>(501, -1e9));
        return solveUsingRec(nums1, nums2, m, n, 0, 0, dp);
    }
};


