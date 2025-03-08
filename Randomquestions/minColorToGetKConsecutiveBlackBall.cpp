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



//////////////////////////////Method2////////////////////////////////

class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int ans = INT_MAX;
        int i = 0;
        int j = 0;
        int whiteBalls = 0;
        while(j < blocks.size()) {

            if(blocks[j] == 'W') {
                whiteBalls++;
            }

            //check if we created k size windows
            if(j-i+1 == k) {

                ans = min(ans, whiteBalls);

                //shifting
                if(blocks[i] == 'W') {
                    whiteBalls--;
                }

                i++;
            }

            j++;
        }

        return ans;
    }
};

