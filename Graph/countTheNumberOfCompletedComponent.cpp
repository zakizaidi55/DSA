class Solution {
public:
    //catch-> v and e ko by ref pass karna tha nhi toh value reflect nhi hogi origina fn call m
    void dfs(int i, unordered_map<int, vector<int> >&adj, vector<bool>&visited, int &v, int &e) {
        visited[i] = true;
        v++;
        e += adj[i].size();

        for(int&ngbr: adj[i]) {
            if(!visited[ngbr]) {
                dfs(ngbr, adj, visited, v, e);
            }
        }
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {

        // ----------------------------------Condition of connected componet-----------------
        //vertex*(vertex-1)/2 == edges
        int result = 0;
        unordered_map<int, vector<int> >adj;
        //build the graph
        for(auto&edge: edges) {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool>visited(n, false);

        for(int i=0; i<n; i++) {
            if(visited[i] == true) {
                continue;
            }

            int v = 0;
            int e = 0;

            dfs(i, adj, visited, v, e);
            if(v*(v-1) == e) 
                result++;
        }

        return result;
    }
};


