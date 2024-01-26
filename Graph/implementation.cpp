#include <iostream>
#include<list>
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

class Graph {
  public:
  unordered_map<int, list<pair<int, int> > >adjList;
   
    void addEdge(int u, int v, int wt, bool direction) {
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

        cout << endl << " printing adjlist " << endl;
        printAdjList();
    }

    void printAdjList() {
        for(auto i:adjList) {
            cout << i.first << " : { " ;

            for(pair<int, int>p: i.second) {
                cout << " { " << p.first << " , " <<p.second << " } " ;
            }

            cout << " } " << endl;
        }
    }
};


int main() {
  Graph g;
  // g.addEdge(0,1,1);
  // g.addEdge(1,2,1);
  // g.addEdge(1,3,1);
  // g.addEdge(2,3,1);
  g.addEdge(0,1,5,0);
  g.addEdge(1,2,10,0);
  g.addEdge(1,3,20,0);
  g.addEdge(2,3,50,0);
  return 0;
}