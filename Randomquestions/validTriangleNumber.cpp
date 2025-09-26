class Solution {
public:
    int binarySearch(vector<int>&nums, int s, int e, int target) {
        int k = -1;

        while(s <= e) {
            int mid = (s + e)/2;
            if(nums[mid] < target) {
                k = mid;
                s = mid+1;
            }

            else {
                e = mid-1;
            }
        }

        return k;
    }
    int triangleNumber(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int result = 0;
        for(int i=0; i<n; i++) {
            for(int j=i+1; j<n; j++) {
                int sum = nums[i] + nums[j];
                // now i need to find 3rd index k
                int k = binarySearch(nums, j+1, n-1, sum);

                if(k != -1) {
                    result += (k-j);
                }
            }
        }

        return result;
    }
};


