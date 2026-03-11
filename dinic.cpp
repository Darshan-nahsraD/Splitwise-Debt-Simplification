#include "dinic.h"
#include <queue>
#include <limits>

Dinic::Dinic(int V) {
    this->V = V;
    adj.resize(V);
    level.resize(V);
}

void Dinic::addEdge(int u, int v, int cap) {
    Edge a{v, 0, cap, (int)adj[v].size()};
    Edge b{u, 0, 0, (int)adj[u].size()};

    adj[u].push_back(a);
    adj[v].push_back(b);
}

bool Dinic::bfs(int s, int t) {
    fill(level.begin(), level.end(), -1);
    level[s] = 0;

    queue<int> q;
    q.push(s);

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (auto &e : adj[u]) {
            if (level[e.v] < 0 && e.flow < e.capacity) {
                level[e.v] = level[u] + 1;
                q.push(e.v);
            }
        }
    }

    return level[t] >= 0;
}

int Dinic::dfs(int u, int t, int flow) {
    if (u == t)
        return flow;

    for (auto &e : adj[u]) {
        if (level[e.v] == level[u] + 1 && e.flow < e.capacity) {
            int curr_flow = min(flow, e.capacity - e.flow);
            int temp_flow = dfs(e.v, t, curr_flow);

            if (temp_flow > 0) {
                e.flow += temp_flow;
                adj[e.v][e.rev].flow -= temp_flow;
                return temp_flow;
            }
        }
    }

    return 0;
}

int Dinic::maxFlow(int s, int t) {
    if (s == t)
        return -1;

    int total = 0;

    while (bfs(s, t)) {
        while (int flow = dfs(s, t, INT_MAX))
            total += flow;
    }

    return total;
}