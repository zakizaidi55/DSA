class Solution {
    public:
        vector<vector<int>> adj;
        unordered_map<int, int> bobPath;
        int maxProfit = INT_MIN;
        vector<int> amount;
        vector<bool> visited;
        bool findBobPath(int node, int time) {
            visited[node] = true;
            bobPath[node] = time;
            if (node == 0) return true;
            
            for (int nbr : adj[node]) {
                if (!visited[nbr] && findBobPath(nbr, time + 1)) {
                    return true;
                }
            }
            bobPath.erase(node);
            return false;
        }
    
        void findAlicePath(int node, int time, int income) {
            visited[node] = true;
            if (!bobPath.count(node) || time < bobPath[node])
                income += amount[node];
            else if (time == bobPath[node])
                income += amount[node] / 2;
            
            if (adj[node].size() == 1 && node != 0)
                maxProfit = max(maxProfit, income);
            
            for (int nbr : adj[node]) {
                if (!visited[nbr]) {
                    findAlicePath(nbr, time + 1, income);
                }
            }
        }
    
    
        int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
            int n = amount.size();
            this->amount = amount;
            adj.resize(n);
            visited.resize(n, false);
            
            for (auto& edge : edges) {
                adj[edge[0]].push_back(edge[1]);
                adj[edge[1]].push_back(edge[0]);
            }
            
            findBobPath(bob, 0);
            fill(visited.begin(), visited.end(), false);
            findAlicePath(0, 0, 0);
            return maxProfit;
        }
    };