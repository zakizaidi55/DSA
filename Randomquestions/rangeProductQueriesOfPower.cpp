class Solution {
public:
    const int MOD = 1e9+7;
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int>powers;
        vector<int>ans;

        for(int i=0; i<32; i++) {
            if((n & (1 << i)) != 0) {
                // it means ith bit is set(1)
                powers.push_back(1 << i);
            }
        }

        for(auto&query: queries) {
            int start = query[0];
            int end = query[1];

            long long product = 1;
            for(int i=start; i<=end; i++) {
                product = (product*powers[i])%MOD;
            }
            ans.push_back(product);
        }

        return ans;
    }
};


