#include <iostream>
#include <list>
#include <vector>

using namespace std;

class Graph{
    private:
        int numVertices;
        list <int> *adjLists;
        bool *visited;

    public:
        Graph(int v){
            numVertices = v;
            adjLists = new list<int>[v];
            visited = new bool[v];
        }
        //Destructor
        ~Graph(){
            delete [] adjLists;
            delete [] visited;
        }
        void addEdge(int, int);
        void printGraph();
        void ResetVisited();
        void DFS(int);
        void BFS(int);
        bool isBiPartite(int);

};

// Add edges
void Graph::addEdge(int s, int d){
    this -> adjLists[s].push_back(d);
    this -> adjLists[d].push_back(s);
}

// Print the graph
void Graph::printGraph(){
    for(int i = 0; i < this -> numVertices; i++){
        cout << "\nVertex " << i << ":";
        for (auto x : this -> adjLists[i])
            cout << " -> " << x;
        cout << endl;
    }
}

void Graph::ResetVisited(){
    for(int i = 0; i < numVertices; i++){
        visited[i] = false;
    }
}

void Graph::DFS(int vertex){
    this -> visited[vertex] = true;
    list<int> adjVertex = this -> adjLists[vertex];

    cout << vertex << " ";

    for(auto i: adjVertex){
        if(!visited[i]){
            DFS(i);
        }
    }
}

/*/
Create a queue Q mark v as visited and put v into Q
while Q is not empty
    remove the head u of Q
    mark and enqueue all (unvisited) neighbours of u
*/
void Graph::BFS(int startVertex){
    visited[startVertex] = true;
    list<int> queue;
    queue.push_back(startVertex);

    while (!queue.empty()){
        int currentVertex = queue.front();
        cout << currentVertex << " ";
        queue.pop_front();

        for (auto i: adjLists[currentVertex]){
            if (!visited[i]){
                visited[i] = true;
                queue.push_back(i);
            }
        }
    }

}

bool Graph::isBiPartite(int startVertex){
    vector<bool> color(numVertices);

    visited[startVertex] = true;
    color[startVertex] = 0;

    list<int> queue;
    queue.push_back(startVertex);

    while (!queue.empty()){
        int v = queue.front();
        queue.pop_front();

        for (auto u: adjLists[v]){
            if (!visited[u]){
                visited[u] = true;
                color[u] = !color[v];
                queue.push_back(u);
            }
            else if (color[v] == color[u]){
                return false;
            }
        }
    }

    return true;
}

int main(){

    //Create graph
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(0, 3);
    g.addEdge(1, 2);
    g.addEdge(2, 4);

    //Print the graph
    g.printGraph();

    cout << "\nDFS: ";
    g.DFS(0);

    //Reset visited
    g.ResetVisited();

    cout << "\nBFS: ";
    g.BFS(0);

    //Reset visited
    g.ResetVisited();
    cout << endl;
    cout << "\nis BiPartite? " << endl;
    if (g.isBiPartite(0)){
        cout << "Graph is BiPartite" << endl;
    }
    else{
        cout << "Graph is not BiPartite" << endl;
    }
    return 0;
}