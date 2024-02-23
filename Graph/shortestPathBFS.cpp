#include<iostream>
#include<unordered_map>
#include<map>
#include<list>
#include<stack>
#include<queue>
#include<algorithm>
using namespace std;

class Graph{
    public:
        unordered_map<int, list<int> >adjList;

        void addEdge(int u, int v, bool direction) {
            // direction->0 undirected
            // direction->1 directed
            if(direction == 1) {
                adjList[u].push_back(v);
            }

            else {
                adjList[u].push_back(v);
                adjList[v].push_back(u);
            }
        }

        void printAdjList() {
            for(auto i: adjList) {
                cout << i.first << " { ";
                for(auto j:i.second) {
                    cout << j << " , " ;
                } 

                cout << " }" << endl;
            }
        }
        
        void topoSortBfs(int n) {
            queue<int>q;
            map<int, int>indegree;
            for(auto i: adjList) {
                for(auto nbr: i.second) {
                    indegree[nbr]++;
                }
            }

            // put all the indegree wali node into queue
            for(int node=0; node<n; node++) {
                if(indegree[node] == 0) {
                    q.push(node);
                }
            }

            while(!q.empty()) {
                int frontNode = q.front();
                q.pop();
                cout << frontNode << " , " ;
                for(auto nbr:adjList[frontNode]) {
                    indegree[nbr]--;

                    // check for zero
                    if(indegree[nbr] == 0) {
                        q.push(nbr);
                    }
                }
            }

        }

    void shortestPathBFS(int src, int dest) {
            queue<int>q;
            map<int, bool>visited;
            map<int, bool>parent;
            // initial state
            q.push(src);
            visited[src] = true; 
            parent[src] = -1;

            while(!q.empty()) {
                int frontNode = q.front();
                q.pop();
                for(auto nbr: adjList[frontNode]) {
                    if(!visited[nbr]) {
                        q.push(nbr);
                        parent[nbr] = frontNode;
                        visited[nbr] = true; 
                    }
                }
            }

            // parent array is ready
            vector<int>ans;
            while(dest != -1) {
                ans.push_back(dest);
                dest = parent[dest];
            }

            reverse(ans.begin(), ans.end());
            for(auto i: ans) {
                cout << i << " ";
            }
        }
};


int main() {
    Graph g;
    g.addEdge(0,1,1);
    g.addEdge(1,2,1);
    g.addEdge(2,3,1);
    g.addEdge(4,3,1);
    g.addEdge(3,5,1);
    g.addEdge(6,4,1);
    g.addEdge(5,6,1);
    g.addEdge(6,7,1);
    g.printAdjList();
    int n = 8; 

    return 0;
}