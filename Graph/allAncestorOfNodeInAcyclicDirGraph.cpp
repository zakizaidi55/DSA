class Solution {
public:
    void dfs(int ancestor, unordered_map<int, vector<int> >&adj, int currNode, vector<vector<int> >&result) {
        for(int &nbr: adj[currNode]) {
            if(result[nbr].empty() || result[nbr].back() != ancestor) {
                result[nbr].push_back(ancestor);
                dfs(ancestor, adj, nbr, result);
            }
        }
    }
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int> >result(n);
        unordered_map<int, vector<int> >adj;

        for(auto vec: edges) {
            int u = vec[0];
            int v = vec[1];

            adj[u].push_back(v); 
        }

        for(int i=0; i<n; i++) {
            int ancestor = i;
            dfs(ancestor, adj, i, result);
        }

        return result;
    }
};