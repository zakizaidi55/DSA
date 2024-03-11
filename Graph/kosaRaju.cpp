#include<iostream>
#include<unordered_map>
#include<list>
#include<stack>
#include<vector>
#include<limits.h>

using namespace std;

 
class Graph{
    public:
        // unordered_map<int, list<pair<int, int> > > adjList;
        unordered_map<int, list<int> > adjList;


        void addEdge(int u, int v, int direction) {
            // direction -> 0 -> undirected
            // direction -> 1 -> directed
            if(direction == 0) {
                adjList[u].push_back(v);
                adjList[v].push_back(u);
            }
            else {
                adjList[u].push_back(v);
            }
        }
        

        // void printAdjList() {
        //     for(auto i: adjList) {
        //         cout << i.first << " -> " ;
        //         for(auto j: i.second) {
        //             cout << " { " << j.first << " , " << j.second << " } " ;
        //         } cout << endl;
        //     }
        // }

        void dfs1(int node, stack<int>&ordering, unordered_map<int, bool>&vis) {
            vis[node] = true;
            for(auto nbr: adjList[node]) {
                if(!vis[nbr]) {
                    dfs1(nbr, ordering, vis);
                }
            }

            ordering.push(node);
        }

        void dfs2(int node, unordered_map<int, bool>&vis2,  unordered_map<int, list<int> >&adjNew) {
            vis2[node] = true;
            cout << node << " " ;
            for(auto nbr: adjNew[node]) {
                if(!vis2[nbr]) {
                    dfs2(nbr, vis2, adjNew);
                }
            }
        }

        int getStronglyConnectedComponents(int n) {
            // step1: get ordering
            stack<int> ordering;
            unordered_map<int, bool>vis;

            for(int i=0; i<n; i++) {
                if(!vis[i]) {
                    dfs1(i,ordering, vis);
                }
            }
            // step2: reverse edges
            unordered_map<int, list<int> >adjNew;
            for(auto a: adjList) {
                for(auto b:a.second) {
                    int u = a.first;
                    int v = b;

                    // v->u
                    adjNew[v].push_back(u);
                }   
            }
            // step3: traverse using ordering and count components
            int count = 0;
            unordered_map<int, bool>vis2;

            while(!ordering.empty()) {
                int node  = ordering.top();
                ordering.pop();

                if(!vis2[node]) {
                    cout << "SCC # " << count+1 << endl; 
                    dfs2(node, vis2, adjNew);
                    count++;
                }

                cout << endl;
            }

            return count;

        }

        
};


int main() {
    Graph g;
    g.addEdge(0,1,1);
    g.addEdge(1,2,1);
    g.addEdge(2,3,1);
    g.addEdge(3,0,1);
    g.addEdge(2,4,1);

    g.addEdge(4,5,1);
    g.addEdge(5,6,1);
    g.addEdge(6,4,1);

    g.addEdge(6,7,1);

    int ans = g.getStronglyConnectedComponents(8);
    cout <<"SCC count " << ans << endl;
    return 0;
}