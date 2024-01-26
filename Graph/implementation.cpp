#include <iostream>
#include<list>
#include<queue>
#include<unordered_map>
using namespace std;


// class Graph {
//   public:
//     unordered_map<int, list<int> >adjList;
//     void addEdge(int u, int v, bool direction) {
//       // direction = 0-> undirected
//       // direction = 1->directed

//       if(direction == 1) {
//         // u to v ki taraf ki ek edge
//         // u->v
//         adjList[u].push_back(v);
//       }

//       else {
//         // u-v
//         adjList[u].push_back(v);
//         adjList[v].push_back(u);
//       }

//       cout << endl << " printing adjlist " << endl;
//       printAdjList();
//     }

//     void printAdjList() {
//       for(auto i: adjList) {
//         cout << i.first << " -> { ";
//         for(auto neighbour: i.second) {
//           cout << neighbour << " , ";
//         }
//         cout << " } "<< endl;
//       }
//     }
// };

template <typename T>

class Graph {
  public:
  unordered_map<T, list<pair<T, int> > >adjList;
   
    void addEdge(T u, T v, int wt, bool direction) {
        // direction = 0 ->undirected
        // direction = 1-> directed
        if(direction == 1) {
            // u->v
            adjList[u].push_back({v, wt});
        }

        else {
            // u-v
            // v-u

            adjList[u].push_back(make_pair(v, wt));
            adjList[v].push_back(make_pair(u, wt));

        }

        // cout << endl << " printing adjlist " << endl;
        // printAdjList();
    }

    void printAdjList() {
        for(auto i:adjList) {
            cout << i.first << " : { " ;

            for(pair<T, int>p: i.second) {
                cout << " { " << p.first << " , " <<p.second << " } " ;
            }

            cout << " } " << endl;
        }
    }


    void bfsTraversal(T src, unordered_map<T, bool>&visited) {
        // adjlist already bni hui h
        // visited
        
        // queue
        queue<T>q;

        // initial node
        q.push(src);
        visited[src] = true;

        while(!q.empty()) {
            T frontNode = q.front();
            cout << frontNode << " ";
            q.pop();

            // go to neighbour
            for(auto nbr : adjList[frontNode]) {
                T nbrData = nbr.first;

                if(!visited[nbrData]) {
                    q.push(nbrData);
                    visited[nbrData] = true;
                }
            }
        }
    }


    void dfsTraversal(T src, unordered_map<T, bool>&vis) {
        vis[src] = true;
        cout << src << " ";

        for(auto nbr:adjList[src] ) {
            T nbrData = nbr.first;
            if(!vis[nbrData]) {
                dfsTraversal(nbrData, vis);
            }
        } 
    }
};


int main() {
  Graph<char> g;
  // g.addEdge(0,1,1);
  // g.addEdge(1,2,1);
  // g.addEdge(1,3,1);
  // g.addEdge(2,3,1);
  g.addEdge('a','b',5,0);
  g.addEdge('a','c',10,0);

  g.addEdge('c','d',20,0);

  g.addEdge('c','e',50,0);
  g.addEdge('d','e',50,0);
  g.addEdge('e','f',50,0);

  unordered_map<char, bool>visited;
//   for(char node='a'; node<='f'; node++) {
//     if(!visited[node]) {
//         g.bfsTraversal(node, visited);
//     }
//   }
 for(char node='a'; node<='f'; node++) {
    if(!visited[node]) {
        g.dfsTraversal('a', visited);
    }
 }
  
  return 0;
}