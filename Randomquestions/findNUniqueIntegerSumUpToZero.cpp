class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int>ans(n, 0);
        int i = 0;
        int j = n-1;

        int element = 1;
        while(i < j) {
            ans[i] = element;
            ans[j] = -element;
            element++;
            i++;
            j--;
        }

        return ans;
    }
};


