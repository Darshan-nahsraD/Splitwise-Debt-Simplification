#ifndef DINIC_H
#define DINIC_H

#include <vector>
using namespace std;

struct Edge {
    int v;
    int flow;
    int capacity;
    int rev;
};

class Dinic {
    int V;
    vector<vector<Edge>> adj;
    vector<int> level;

public:
    Dinic(int V);
    void addEdge(int u, int v, int cap);
    bool bfs(int s, int t);
    int dfs(int u, int t, int flow);
    int maxFlow(int s, int t);
};

#endif