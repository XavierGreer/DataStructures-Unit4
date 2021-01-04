//==========================================
//  main.cpp
//  Unit 4 Submission node 1
//  Created by Xavier Greer
//  Due Date: 12-6-20
//==========================================
#include <iostream>
#include "/Users/xaviergreer/stdc++.h"

using namespace std;

# define INF 0x3f3f3f3f

class Graph
{
    int vertex;
    list< pair<int, int> > *lists;

public:
    Graph(int v);
    void Add(int u, int v, int w);
    void Print(int s, int W);
};

Graph::Graph(int v)
{
    this->vertex = v;
    lists = new list< pair<int, int> >[v];
}

void Graph::Add(int u, int v, int w)
{
    lists[u].push_back(make_pair(v, w));
    lists[v].push_back(make_pair(u, w));
}

void Graph::Print(int src, int W)
{
    vector<pair<int, list<int>::iterator> > Distance(vertex);

    for (int i = 0; i < vertex; i++)
        Distance[i].first = INF;

    list<int> Buckets[W * vertex + 1];

    Buckets[0].push_back(src);
    Distance[src].first = 0;

    int idx = 0;
    while (1)
    {
        while (Buckets[idx].size() == 0 && idx < W*vertex)
            idx++;

        if (idx == W * vertex)
            break;

        int u = Buckets[idx].front();
        Buckets[idx].pop_front();

        for (auto i = lists[u].begin(); i != lists[u].end(); ++i)
        {
            int v = (*i).first;
            int weight = (*i).second;
            int du = Distance[u].first;
            int dv = Distance[v].first;

            if (dv > du + weight)
            {
                if (dv != INF)
                    Buckets[dv].erase(Distance[v].second);

                Distance[v].first = du + weight;
                dv = Distance[v].first;
                Buckets[dv].push_front(v);
                Distance[v].second = Buckets[dv].begin();
            }
        }
    }
    printf("The distance shortest distance between node 0 and node 7 is %d\n", Distance[7].first);
}

int main()
{
    int V = 9;
    Graph graph(V);

    graph.Add(0, 1, 4);
    graph.Add(0, 7, 8);
    graph.Add(1, 2, 8);
    graph.Add(1, 7, 11);
    graph.Add(2, 3, 7);
    graph.Add(2, 8, 2);
    graph.Add(2, 5, 4);
    graph.Add(3, 4, 9);
    graph.Add(3, 5, 14);
    graph.Add(4, 5, 10);
    graph.Add(5, 6, 2);
    graph.Add(6, 7, 1);
    graph.Add(6, 8, 6);
    graph.Add(7, 8, 7);

    graph.Print(0, 14);

    return 0;
}

