class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        vector<long long> sum;
        
        for (int i=0; i<weights.size()-1; i++) {
            sum.push_back(weights[i] + weights[i + 1]);
        }
        
        sort(sum.begin(), sum.end());
        
        long long maxi = 0;
        long long mini = 0;
        
        for (int i=0; i<k-1; i++) {
            mini += sum[i];
            maxi += sum[sum.size() - 1 - i];
        }
        
        return maxi - mini;
    }
};

