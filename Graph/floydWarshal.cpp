#include<iostream>
#include<unordered_map>
#include<list>
#include<vector>
#include<limits.h>

using namespace std;

class Graph{
    public:
        unordered_map<int, list<pair<int, int> > > adjList;


        void addEdge(int u, int v, int wt, int direction) {
            // direction -> 0 -> undirected
            // direction -> 1 -> directed
            if(direction == 0) {
                adjList[u].push_back({v, wt});
                adjList[v].push_back({u, wt});
            }
            else {
                adjList[u].push_back({v, wt});
            }
        }

        void printAdjList() {
            for(auto i: adjList) {
                cout << i.first << " -> " ;
                for(auto j: i.second) {
                    cout << " { " << j.first << " , " << j.second << " } " ;
                } cout << endl;
            }
        }

        void floydWarshal(int n) {
            vector<vector<int> >dist(n, vector<int>(n, 1e9));

            for(int i=0; i<n; i++) {
                dist[i][i] = 0;
            }

            // kuch weights graph k andar bhi given h
            // update dist array accordingly
            for(auto a: adjList) {
                for(auto b: a.second) {
                    int u = a.first;
                    int v = b.first;
                    int wt = b.second;
                    dist[u][v] = wt;
                }
            }

            // main logic - helper logic
            for(int helper=0; helper<n; helper++) {
                for(int src=0; src<n; src++) {
                    for(int dest=0; dest<n; dest++) {
                        dist[src][dest] = min(dist[src][dest], dist[src][helper] + dist[helper][dest]);
                    }
                }
            }

            for(int i=0; i<n; i++) {
                for(int j=0; j<n; j++) {
                    cout << dist[i][j] << " ";
                }cout << endl;
            }
        } 
};

int main() {
    Graph g;
    g.addEdge(0,1,3,1);
    g.addEdge(1,0,2,1);
    g.addEdge(0,3,5,1);
    g.addEdge(1,3,4,1);
    g.addEdge(3,2,2,1);
    g.addEdge(2,1,1,1);

    g.floydWarshal(4);

    return 0;
}