class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        // create adjlist
        // update indegree
        unordered_map<int, vector<int> >adjList;
        vector<bool>suspicious(n, false);
        vector<int>indegree(n, 0);
        for(auto&vec: invocations) {
            int u = vec[0];
            int v = vec[1];

            adjList[u].push_back(v);
            indegree[v]++;
        }

        // traverese map
        // decrease indegree
        // BFS
        queue<int>q;
        q.push(k);
        suspicious[k] = true;
        while(!q.empty()) {
            int currNode = q.front();
            q.pop();
            for(int nbr: adjList[currNode]) {
                indegree[nbr]--;
                if(!suspicious[nbr]) {
                    q.push(nbr);
                    suspicious[nbr] = true;
                }
            }
        }

        vector<int>ans;
        bool cannotRemove = false;

        for(int i=0; i<n; i++) {
            if(suspicious[i] == true && indegree[i] >= 1) {
                cannotRemove = true;
                break;
            }

            if(!suspicious[i]) {
                ans.push_back(i);
            }
        }

        if(cannotRemove) {
            vector<int>vec;
            for(int i=0; i<n; i++) {
                vec.push_back(i);
            }

            return vec;
        }

        return ans;

    }
};



