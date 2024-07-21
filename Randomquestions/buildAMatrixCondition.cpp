class Solution {
public:     
    void dfs(int u, vector<int>&visited, unordered_map<int, vector<int> >&adj, stack<int>&st, bool &isCycle) {
        visited[u] = 1;
        for(int &v: adj[u]) {
            if(visited[v] == 0) {
                dfs(v, visited, adj, st, isCycle);
            }
            else if(visited[v] == 1) {
                // dfs chal rha tha dobara aagye matlab cycle present hai
                isCycle = true;
                return;
            }
        }

        visited[u] = 2;
        st.push(u);
    }
    vector<int>toposort(vector<vector<int>>& edges, int k) {
        unordered_map<int, vector<int> >adj;
        for(vector<int>edge: edges) {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
        }

        vector<int>visited(k+1, 0); // k ki values 1 to k h
        // visited[0];  not visited
        // visited[1];  dfs is ongoing
        // visited[2]; dfs is completed
        vector<int>order;
        stack<int>s;
        bool isCycle = false;
        for(int i=1; i<=k; i++) {   
            if(visited[i] == 0) {
                dfs(i, visited, adj, s, isCycle);

                if(isCycle) {
                    return {};
                }
            }
        }

        while(!s.empty()) {
            order.push_back(s.top());
            s.pop();
        }

        return order;
    }

    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        vector<int>topRow = toposort(rowConditions, k);
        vector<int>topCol = toposort(colConditions, k);

        if(topRow.empty() || topCol.empty()) {
            return {};
        }

        vector<vector<int> >ans(k, vector<int>(k, 0));

        for(int i=0; i<k; i++) {
            for(int j=0; j<k; j++) {
                if(topRow[i] == topCol[j]) {
                    ans[i][j] = topRow[i];
                }
            }
        }

        return ans;
    }
};