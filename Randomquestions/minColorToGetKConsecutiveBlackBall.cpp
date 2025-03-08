class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int ans = INT_MAX;
        int n = blocks.size();
        for(int i=0; i<=n-k; i++) {
            int whiteBlock = 0;
            for(int j=i; j-i+1<=k; j++) {
                if(blocks[j] == 'W'){
                    whiteBlock++;
                }
            }
            ans = min(ans, whiteBlock);
        }

        return ans;
    }
};
