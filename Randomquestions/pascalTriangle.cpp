class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int> >ans;
        for(int i=1; i<=n; i++) {
            vector<int>temp;
            int c = 1;
            for(int j=1; j<=i; j++) {
                temp.push_back(c);
                c = c * (i-j)/j;
            }
            ans.push_back(temp);
        }

        return ans;
    }
};


