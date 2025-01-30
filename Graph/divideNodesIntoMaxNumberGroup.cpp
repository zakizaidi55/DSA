class Solution {
public:
    int magnificentSets(int n, vector<vector<int>>& edges) {
        //create adjacency matrix
        vector<vector<int>> adjacencyList(n);
        for (auto&edge: edges) {
            int node1 = edge[0] - 1;
            int node2 = edge[1] - 1;
            adjacencyList[node1].push_back(node2);
            adjacencyList[node2].push_back(node1);
        }

        vector<int> nodeDistances(n);
        for (int startNode=0; startNode<n; startNode++) {
            queue<int> nodeQueue{{startNode}};
            vector<int> distance(n);
            distance[startNode] = 1;
            int maxDistance = 1;
            int rootNode = startNode;
            while (!nodeQueue.empty()) {
                int currentNode = nodeQueue.front();
                nodeQueue.pop();
                rootNode = min(rootNode, currentNode);
                for (int neighbor: adjacencyList[currentNode]) {
                    if (distance[neighbor] == 0) {
                        distance[neighbor] = distance[currentNode] + 1;
                        maxDistance = max(maxDistance, distance[neighbor]);
                        nodeQueue.push(neighbor);
                    } 
                    else if (abs(distance[neighbor] - distance[currentNode]) != 1) {
                        return -1;
                    }
                }
            }
            nodeDistances[rootNode] = max(nodeDistances[rootNode], maxDistance);
        }
        return accumulate(nodeDistances.begin(), nodeDistances.end(), 0);
    }
};