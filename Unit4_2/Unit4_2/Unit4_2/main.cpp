//===========================
//  main.cpp
//  Unit4_2
//  Created by Xavier Greer
//===========================
#include <iostream>
#include <list>
using namespace std;

class Graph{
    int V;
    list<int> *adjacent;
public:
    Graph(int V) { this->V = V; adjacent = new list<int>[V]; }
    ~Graph()     { delete [] adjacent; }

    void addEdge(int x, int y);
    void Coloring();
};

void Graph::addEdge(int x, int y){
    adjacent[x].push_back(y);
    adjacent[y].push_back(x);
}

void Graph::Coloring(){
    int result[V];
    result[0] = 0;

    for (int u = 1; u < V; u++)
        result[u] = -1;

    bool available[V];
    for (int cr = 0; cr < V; cr++)
        available[cr] = false;

    for (int u = 1; u < V; u++){
        list<int>::iterator i;
        for (i = adjacent[u].begin(); i != adjacent[u].end(); ++i)
            if (result[*i] != -1)
                available[result[*i]] = true;

        int cr;
        for (cr = 0; cr < V; cr++)
            if (available[cr] == false)
                break;

        result[u] = cr;

        for (i = adjacent[u].begin(); i != adjacent[u].end(); ++i)
            if (result[*i] != -1)
                available[result[*i]] = false;
    }
    for (int u = 0; u < V; u++)
    {
        if (result[u] == 0)
        {
            cout << "Vertex " << u << "'s color is blue." << endl;
        }
        if (result[u] == 1)
        {
            cout << "Vertex " << u << "'s color is green." << endl;
        }
        if (result[u] == 2)
        {
            cout << "Vertex " << u << "'s color is red." << endl;
        }
    }
}
int main(){
    Graph graph(6);
    graph.addEdge(0, 1);
    graph.addEdge(0, 4);
    graph.addEdge(0, 5);
    graph.addEdge(1, 3);
    graph.addEdge(1, 4);
    graph.addEdge(2, 3);
    graph.addEdge(2, 4);
    graph.addEdge(4, 5);
    cout << "Graph Coloring is:\n";
    graph.Coloring();

    return 0;
}
