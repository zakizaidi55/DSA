#include<iostream>
#include<unordered_map>
#include<list>
#include<vector>
#include<limits>
#include<stack>
using namespace std;

class Graph{
    public:
        unordered_map<int, list <pair<int, int> > >adj;

        void addEdge(int u, int v, int wt, bool direction) {
            // direction - 0 - undirected
            // direction - 1 - directed

            if(direction == 1) {
                adj[u].push_back({v, wt});
            }

            else {
                adj[u].push_back({v, wt});
                adj[v].push_back({u, wt});
            }
        }

        void printAdjList() {
            for(auto i:adj) {
                cout << i.first << " : { " ;

                for(auto j:i.second) {
                    cout << "( " << j.first << " , " << j.second << " ) " ; 
                }

                cout << " } " << endl;
            }
        }

        void topoOrderDfs(int src, stack<int>& topo, unordered_map<int, bool>&visited) {
            visited[src] = true;
            for(auto nbrPair: adj[src]) {
                int nbrNode = nbrPair.first;
                int nbrDist = nbrPair.second;

                if(!visited[nbrNode]) {
                    topoOrderDfs(nbrNode, topo, visited);
                }
            }

            topo.push(src);
        }

        void shortestPathDfs(stack<int>&topoOrder, int n) {
            vector<int>dist(n, INT_MAX);

            // intiail source maintain
            int src = topoOrder.top();
            topoOrder.pop();

            dist[src] = 0;

            // update the neighbour distance for this src node
            for(auto nbrPair:adj[src]) {
                int nbrNode = nbrPair.first;
                int nbrDist = nbrPair.second;

                if(dist[src] + nbrDist < dist[nbrNode]) {
                    dist[nbrNode] = dist[src] + nbrDist;
                }
            }

            // apply the same above concept for all the remaining nodes
            while(!topoOrder.empty()) {
                int src = topoOrder.top();
                topoOrder.pop();
                for(auto nbrPair:adj[src]) {
                    int nbrNode = nbrPair.first;
                    int nbrDist = nbrPair.second;

                    if(dist[src] + nbrDist < dist[nbrNode]) {
                        dist[nbrNode] = dist[src] + nbrDist;
                    }
                }
            }

            // now the distance array is ready
            cout << "Printing the distance array " << endl;
            for(auto i: dist) {
                cout << i << " ";
            }

        }
};      



int main() {

    Graph g;
    g.addEdge(0,1,5,1);
    g.addEdge(0,2,3,1);
    g.addEdge(2,1,2,1);
    g.addEdge(1,3,3,1);
    g.addEdge(2,3,5,1);
    g.addEdge(2,4,5,1);
    g.addEdge(4,3,1,1);
    g.printAdjList();

    stack<int>topo;
    int src = 0;
    unordered_map<int, bool>visited;
    g.topoOrderDfs(src, topo, visited);

    cout << "printing the topo sort " << endl;

    // while(!topo.empty()) {
    //     cout << topo.top() << endl;
    //     topo.pop();

    // }
    int n = 5;
    g.shortestPathDfs(topo, n);
    return 0;
}