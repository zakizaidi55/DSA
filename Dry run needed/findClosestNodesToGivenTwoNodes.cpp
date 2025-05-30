class Solution {
public:
    void bfs(vector<int>& edges, int startNode, vector<int>& dist_node) {
        int n = edges.size();
        queue<int> que;
        que.push(startNode);
        dist_node[startNode] = 0;
        vector<bool> visited(n, false);
        visited[startNode] = true;
        
        while(!que.empty()) {
            int u = que.front();
            que.pop();
            
            int v = edges[u];
            
            if(v != -1 && !visited[v]) {
                visited[v] = true;
                dist_node[v] = 1 + dist_node[u];
                que.push(v);
            }
        }
    }

    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        vector<int> dist1(n, INT_MAX);
        vector<int> dist2(n, INT_MAX);
        
        bfs(edges, node1, dist1);
        bfs(edges, node2, dist2);
        
        
        int minDistNode = -1;
        int minDistTillNow = INT_MAX;
        for (int i=0; i<n; i++) {
            
            int maxD = max(dist1[i], dist2[i]);
            
            if (minDistTillNow > maxD) {
                minDistNode = i;
                minDistTillNow = maxD;
            }
        }
        return minDistNode;
    }
};


