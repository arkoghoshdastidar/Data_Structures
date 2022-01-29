// Code : Kruskal's Algorithm
// Send Feedback
// Given an undirected, connected and weighted graph G(V, E) with V number of vertices (which are numbered from 0 to V-1) and E number of edges.
// Find and print the Minimum Spanning Tree (MST) using Kruskal's algorithm.
// For printing MST follow the steps -
// 1. In one line, print an edge which is part of MST in the format -
// v1 v2 w
// where, v1 and v2 are the vertices of the edge which is included in MST and whose weight is w.And v1<=v2 i.e. print the smaller vertex first while printing an edge.
// 2. Print V-1 edges in above format in different lines.
// Note : Order of different edges doesn't matter.
// Input Format :
// Line 1: Two Integers V and E (separated by space)
// Next E lines : Three integers ei, ej and wi, denoting that there exists an edge between vertex ei and vertex ej with weight wi (separated by space)
// Output Format :
// Print the MST, as described in the task.
// Constraints :
// 2 <= V, E <= 10^5
// Time Limit: 1 sec
// Sample Input 1 :
// 4 4
// 0 1 3
// 0 3 5
// 1 2 1
// 2 3 8
// Sample Output 1 :
// 1 2 1
// 0 1 3
// 0 3 5
#include <iostream>
#include <algorithm>
using namespace std;

class edge
{
public:
    int vertex1, vertex2, weight;
    edge() {}
    edge(int vertex1, int vertex2, int weight)
    {
        this->vertex1 = vertex1;
        this->vertex2 = vertex2;
        this->weight = weight;
    }
};

bool find_union(edge e, int *parent)
{
    int v1 = e.vertex1;
    int v2 = e.vertex2;
    int p1 = parent[v1];
    int p2 = parent[v2];
    while (p1 != v1)
    {
        v1 = parent[v1];
        p1 = parent[v1];
    }
    while (p2 != v2)
    {
        v2 = parent[v2];
        p2 = parent[v2];
    }
    if (p1 == p2)
    {
        return false;
    }
    else
    {
        parent[v1] = p2;
    }
    return true;
}

bool comparator(edge e1, edge e2)
{
    return e1.weight <= e2.weight;
}

int main(void)
{
    int num_nodes, num_edges;
    cin >> num_nodes >> num_edges;
    edge *graph = new edge[num_edges];
    for (int i = 0; i < num_edges; i++)
    {
        int vertex1, vertex2, weight;
        cin >> vertex1 >> vertex2 >> weight;
        edge e(vertex1, vertex2, weight);
        graph[i] = e;
    }

    sort(graph, graph + num_edges, comparator);
    int *parent = new int[num_nodes];
    for (int i = 0; i < num_nodes; i++)
    {
        parent[i] = i;
    }
    edge *MST = new edge[num_nodes - 1];
    int count = 0;
    for (int i = 0; i < num_edges && count < num_nodes - 1; i++)
    {
        if (find_union(graph[i], parent))
        {
            MST[count] = graph[i];
            count++;
        }
    }
    for (int i = 0; i < num_nodes - 1; i++)
    {
        if (MST[i].vertex1 < MST[i].vertex2)
        {
            cout << MST[i].vertex1 << " " << MST[i].vertex2 << " " << MST[i].weight << endl;
        }
        else
        {
            cout << MST[i].vertex2 << " " << MST[i].vertex1 << " " << MST[i].weight << endl;
        }
    }
    delete[] MST;
    delete[] graph;
    delete[] parent;
    return 0;
}