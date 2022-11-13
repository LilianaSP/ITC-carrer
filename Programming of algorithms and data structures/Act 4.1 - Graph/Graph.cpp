#include <iostream>
#include <list>
#include <vector>

using namespace std;

class Graph
{
private:
    int numVertices;
    list<int> *adjLists;
    bool *visited;
    bool ** adjMatrix;

public:
    Graph(int V){
        this -> numVertices = V;
        adjLists = new list<int>[V];
        visited = new bool[V];
        adjMatrix = new bool*[V]; //we create a matrix of size V of pointers to bool
        for(int i = 0; i < V; i++)
        {
            adjMatrix[i] = new bool[V]; //we create a row of size V of bools
            for(int j = 0; j < V; j++)
            {
                adjMatrix[i][j] = false; //we initialize all the values to false
            }
        }
    }

    ~Graph(){
        delete[] adjLists;
        delete[] visited;
        //We delete the matrix
        for(int i = 0; i < numVertices; i ++){
            delete[] adjMatrix[i]; //We delete the column
        }
        delete[] adjMatrix; //We delete the row
    }

    void addEdge(int, int);
    void printGraph();
    void ResetVisited();
    void printMatrix();

    void DFS(int);
    void BFS(int);
    bool isBipartite(int);
};

//------------Function AddEdge (Load the graph)----------------
//------------ Time Complexity: O(1) --------------------------
void Graph::addEdge(int s, int d)
{
    this->adjLists[s].push_back(d);
    this->adjLists[d].push_back(s);
    //We add the edge to the matrix
    this->adjMatrix[s][d] = true;
    this->adjMatrix[d][s] = true;
}

//------------Function PrintGraph (Print the graph)------------
//------------ Time Complexity: O(V + E) ----------------------
void Graph::printGraph()
{
    for (int i = 0; i < this->numVertices; i++)
    {
        cout << "\nVertex " << i << ":";
        for (auto x : this->adjLists[i])
            cout << " -> " << x;
        cout << endl;
    }
}

//------------Function to print the matrix---------------------
//------------ Time Complexity: O(V^2) ------------------------
//Print the matrix
void Graph::printMatrix(){
    for(int i = 0; i < this -> numVertices; i++){
        cout << i << " : ";
        for(int j = 0; j < this -> numVertices; j++){
            cout << adjMatrix[i][j] << " ";
        }
        cout << endl;
    }
}

//------------Function ResetVisited (Reset the visited array)--
//------------ Time Complexity: O(V) --------------------------
void Graph::ResetVisited()
{
    for (int i = 0; i < this->numVertices; i++)
        this->visited[i] = false;
}

//------------Function DFS (Depth First Search)----------------
//  DFS Function complexity - O(V + E) - Space Complexity O(V)
void Graph::DFS(int vertex)
{
    this->visited[vertex] = true;
    list<int> adjVertex = this->adjLists[vertex];

    cout << vertex << " ";

    for (auto i : adjVertex)
        if (!this->visited[i])
            DFS(i);
}

//------------Function BFS (Breadth First Search)--------------
//  BFS Function complexity - O(V + E) - Space Complexity O(V)
void Graph::BFS(int startVertex)
{
    visited[startVertex] = true;

    list<int> queue;
    queue.push_back(startVertex);

    while (!queue.empty())
    {
        int currVertex = queue.front();

        cout << currVertex << " ";

        queue.pop_front();

        for (auto i : adjLists[currVertex])
        {
            if (!visited[i])
            {
                visited[i] = true;
                queue.push_back(i);
            }
        }
    }
}

//------------Function isBipartite (Check if the graph is bipartite)--------------
//  isBipartite Function complexity - O(V + E) - Space Complexity O(V)
bool Graph::isBipartite(int startVertex)
{
    vector<bool> color(numVertices);

    visited[startVertex] = true;
    color[startVertex] = 0;

    list<int> queue;
    queue.push_back(startVertex);

    while (!queue.empty())
    {
        int v = queue.front();
        queue.pop_front();

        for (auto u : adjLists[v])
        {
            if (!visited[u])
            {
                visited[u] = true;
                color[u] = !color[v];

                queue.push_back(u);
            }
            else if (color[v] == color[u])
            {
                return false;
            }
        }
    }

    return true;
}

int main()
{
    // We create a big graph with 15 vertices
    cout << endl;
    cout << "------We create a big graph with 15 vertices------" << endl;
    Graph g(15);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 5);
    g.addEdge(2, 6);
    g.addEdge(3, 7);
    g.addEdge(3, 8);
    g.addEdge(4, 9);
    g.addEdge(4, 10);
    g.addEdge(5, 11);
    g.addEdge(5, 12);
    g.addEdge(6, 13);
    g.addEdge(6, 14);

    //------------ We create our four test cases -------------
    // We print our graph
    g.printGraph();

    // -------- Fisrt test case ---------
    g.ResetVisited();
    cout << "\nFirst test case DFS(1): ";
    g.DFS(1);
    g.ResetVisited();
    cout << "\nFirst test case BFS(1): ";
    g.BFS(0);

    cout << endl;
    // -------- Second test case ---------
    g.ResetVisited();
    cout << "\nSecond test case DFS(3): ";
    g.DFS(3);
    g.ResetVisited();
    cout << "\nSecond test case BFS(3): ";
    g.BFS(3);

    cout << endl;

    // -------- Third test case ---------
    g.ResetVisited();
    cout << "\nThird econd test case DFS(5): ";
    g.DFS(5);
    g.ResetVisited();
    cout << "\nThird test case BFS(5): ";
    g.BFS(5);

    cout << endl;

    // -------- Fourth test case ---------
    g.ResetVisited();
    cout << "\nFourth econd test case DFS(7): ";
    g.DFS(7);
    g.ResetVisited();
    cout << "\nFourth test case BFS(7): ";
    g.BFS(7);

    cout << endl;
    
    g.ResetVisited();
    //We print the matrix
    cout << "\nAdjacency Matrix: " << endl;
    cout << endl;
    g.printMatrix();


    cout << "\n-----Is Bipartite?----- " << endl;
    if (g.isBipartite(0))
        cout << "Graph is Bipartite";
    else
        cout << "Graph is not Bipartite";
    cout << endl;

    return 0;
}