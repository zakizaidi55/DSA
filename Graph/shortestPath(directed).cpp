#include<iostream>
#include<unordered_map>
#include<list>
#include<vector>
#include<limits>
#include<stack>
#include<set>
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

        void dijkstraShortestPath( int n, int src, int dest) {
            vector<int>dist(n+1, INT_MAX);
            set<pair<int, int> >st;

            // initial state
            st.insert({0, src});
            dist[src] = 0;

            // distance updationlogic
            while(!st.empty()) {
                auto topElement = st.begin(); // find the reference of top node
                pair<int, int> topPair = *topElement; // dereference the top node

                int topDistance = topPair.first;
                int topNode = topPair.second;

                // remove the top node
                st.erase(st.begin());

                // update distance of neighbour
                for(pair<int, int> nbrPair: adj[topNode]) {
                    int nbrNode = nbrPair.first;
                    int nbrDist = nbrPair.second;

                    if(topDistance + nbrDist < dist[nbrNode]) {
                        // found a new shorter distance
                        
                        auto previousEntry = st.find({dist[nbrNode], nbrNode});
                        if(previousEntry != st.end()) {
                            // entry present in set
                            st.erase(previousEntry);
                        }

                        // now update the set and dist array
                        dist[nbrNode] = topDistance + nbrDist;
                        st.insert({dist[nbrNode],nbrNode });
                    }
                }
            }

            cout << "shortest distance from" << src << " node to " << dest << " node is " << dist[dest] << endl;
        }
};   




int main() {

    Graph g;
    g.addEdge(1,6,14,0);
    g.addEdge(1,3,9,0);
    g.addEdge(1,2,7,0);
    g.addEdge(2,3,10,0);
    g.addEdge(2,4,15,0);
    g.addEdge(3,4,11,0);
    g.addEdge(3,6,2,0);
    g.addEdge(6,5,9,0);
    g.addEdge(5,4,6,0);
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
    g.dijkstraShortestPath(6, 6, 4);

    
    return 0;
}