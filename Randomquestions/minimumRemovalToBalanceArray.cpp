class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int i = 0;
        int j = 0;
        int maxValidLength = 0;

        while(j < n) {
            long long mini = nums[i];
            long long maxi = nums[j];

            if(maxi <= mini * k) {
                int length = j - i + 1;
                maxValidLength = max(maxValidLength, length);
                j++;
            }

            else {
                i++;
            }
        }

        return n - maxValidLength;
    }
};


