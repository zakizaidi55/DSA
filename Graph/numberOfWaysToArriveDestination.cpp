class Solution {
public:
    int M = 1e9 + 7;
    int countPaths(int n, vector<vector<int>>& roads) {
        unordered_map<int, vector<pair<int, int>>> adj;
        for (auto&road: roads) {
            int u = road[0];
            int v = road[1];
            int time = road[2];
            adj[u].push_back({v, time});
            adj[v].push_back({u, time});
        }

        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        vector<long long> result(n, LLONG_MAX);
        vector<int> pathCount(n, 0);

        result[0] = 0;
        pathCount[0] = 1;
        pq.push({0, 0});

        while (!pq.empty()) {
            long long currTime = pq.top().first;
            int currNode = pq.top().second;
            pq.pop();

            if (currTime > result[currNode]) 
                continue;

            for (auto &vec: adj[currNode]) {
                int adjNode  = vec.first;
                int roadTime = vec.second;

                if(currTime + roadTime < result[adjNode]) {
                    result[adjNode] = currTime + roadTime;
                    pathCount[adjNode] = pathCount[currNode];
                    pq.push({result[adjNode], adjNode});
                } 
                else if(currTime + roadTime == result[adjNode]) {
                    pathCount[adjNode] = (pathCount[adjNode] + pathCount[currNode]) % M;
                }
            }
        }
        
        return pathCount[n - 1];
    }
};


