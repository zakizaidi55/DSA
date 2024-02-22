class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        if(n == 1) {
            return 1;
        }
        vector<int>outDegree(n+1,0);
        vector<int>inDegree(n+1, 0);

        for(auto i:trust) {
            outDegree[i[0]]++;
            inDegree[i[1]]++;
        }

        for(int i=0; i<=n; i++) {
            if((outDegree[i] == 0) && (inDegree[i] == n-1)) {
                return i;
            }
        }

        return -1;
    }
};