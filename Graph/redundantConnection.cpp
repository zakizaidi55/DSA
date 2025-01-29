class Solution {
public:
    bool dfs(int u, int v, vector<bool>&vis, unordered_map<int, vector<int> >&adj) {
        vis[u] = true;

        //if we reach v in the same dfs call
        if(u == v) {
            return true;
        }


        for(int&ngbr: adj[u]) {
            if(vis[ngbr])
                continue;
            
            if(dfs(ngbr, v, vis, adj)) 
                return true;
        }

        return false;

    }

    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();

        unordered_map<int, vector<int> >adj;

        for(auto&edge: edges) {
            int u = edge[0];
            int v = edge[1];

            vector<bool>visited(n, false);
            // check both nodes present in adjacency matrix and also check if it is reachable

            if(adj.find(u) != adj.end() && adj.find(v) != adj.end() && dfs(u, v, visited, adj)) {
                return edge;
            }

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        return {};
    }
};