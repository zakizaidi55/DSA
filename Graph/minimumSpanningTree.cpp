class Solution {
  public:
    int getMinValueNode(vector<int>&key, vector<bool>&mst) {
        int temp = INT_MAX;
        int index = -1; // represent actual node having min value
        for(int i=0; i<key.size(); i++) {
            if(key[i] < temp && mst[i] == false) {
                index = i;
                temp = key[i];
            }
        }
        
        return index;
        
    }
    int spanningTree(int V, vector<vector<int>>& edges) {
        vector<int>key(V, INT_MAX);
        key[0] = 0;
        vector<bool>MST(V, false);
        vector<int>parent(V, -1);
        vector<vector<pair<int, int> > > adj(V);
        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        
        while(true) {
            // step 1: find u
            int u = getMinValueNode(key, MST);
            if(u == -1)
                break;
            
            // step:2 MST[u] = true
            MST[u] = true;
            
            // step3: Process all adjacent node of u
            for (auto [v, w] : adj[u]) {
                if (!MST[v] && w < key[v]) {
                    key[v] = w;
                    parent[v] = u;
                }
            }

        }
        
        int sum = 0;
        for(int i=0; i<parent.size(); i++) {
            if(parent[i] == -1)
                continue;
            
            for (auto [v, w] : adj[i]) {
                if(parent[i] == v) {
                    sum += w;
                }
            } 
        }
        
        return sum;
    }
};


