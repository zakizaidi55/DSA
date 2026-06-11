class Solution {
public:
    const int M = 1e9 + 7;
    int getMaxDepth(unordered_map<int, vector<int> >&adj, int node, int parent) {
        int maxDepth = 0;
        for(int&nbr :adj[node]) {
            if(nbr == parent)
                continue;
            
            maxDepth = max(maxDepth, getMaxDepth(adj, nbr, node) + 1);
        }

        return maxDepth;
    }

    long long power(int base, int exponent) {
        if(exponent == 0) 
            return 1;
        
        long long half = power(base, exponent/2);

        long long result = (half*half) % M;

        if(exponent%2 == 1) {
            result = (result*base) % M;
        }

        return result % M;
    }

    int assignEdgeWeights(vector<vector<int>>& edges) {
        // build the adjacency matrix
        unordered_map<int, vector<int> >adj;

        for(auto&edge: edges) {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            // undirected
            adj[v].push_back(u);
        }


        int depth = getMaxDepth(adj, 1, -1);

        return power(2, depth-1) % M;
    }
};


