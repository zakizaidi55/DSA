class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int ans = INT_MIN;
        int n = energy.size();
        vector<int>prefixSum(n);
        for (int i=n-1; i>=0; i--) {
            if(i+k < n) {
                prefixSum[i] = energy[i] + prefixSum[i+k];
            }

            else {
                prefixSum[i] = energy[i];
            }

            ans = max(ans, prefixSum[i]);
        }

        return ans;
    }
};
