class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int>indegree(n, 0);

        for(auto&edge: edges) {
            int u = edge[0];
            int v = edge[1];

            indegree[v]++;
        }
        int countZeroIndegree = 0;
        int indegreeNumber = -1;
        for(int i=0; i<n; i++) {
            if(indegree[i] == 0) {
                countZeroIndegree++;
                indegreeNumber = i;

                if(countZeroIndegree > 1) {
                    return -1;
                }
            }
        }

        return indegreeNumber;
    }
};