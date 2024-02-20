#include<iostream>
#include<unordered_map>
#include<map>
#include<list>
#include<stack>
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

        void topoSortDfs(int src, map<int,bool>&visited, stack<int>&st) {
            visited[src] = true;
            for(auto nbr: adjList[src]) {
                if((!visited[nbr])) {
                    topoSortDfs(nbr, visited, st);
                }
            }

            st.push(src);
        }
};

int main() {
    Graph g;
    g.addEdge(0,1,1);
    g.addEdge(1,2,1);
    g.addEdge(2,3,1);
    g.addEdge(3,4,1);
    g.addEdge(3,5,1);
    g.addEdge(4,6,1);
    g.addEdge(5,6,1);
    g.addEdge(6,7,1);
    g.printAdjList();
    int n = 8; 
    map<int, bool> visited;

    stack<int>st;

    for(int node=0; node<n; node++) {
        if(!visited[node]) {
            g.topoSortDfs(node, visited, st);
        }
    }

    cout << "printing the topo order " << endl;
    while(!st.empty()) {
        cout << st.top() << endl;
        st.pop();
    }
    return 0;

}