class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>maxElement(n, 0);
        vector<int>minElement(n, 0);

        maxElement[0] = nums[0];
        minElement[n-1] = nums[n-1];

        for(int i=1; i<n; i++) {
            maxElement[i] = max(maxElement[i-1], nums[i]);
        }

        for(int i=n-2; i>=0; i--) {
            minElement[i] = min(minElement[i+1], nums[i]);
        }

        for(int i=0; i<n; i++) {
            int stability = maxElement[i] - minElement[i];
            if(stability <= k)
                return i;
        }

        return -1;
    }
};


