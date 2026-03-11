#include <iostream>
#include "dinic.h"

using namespace std;

int main() {

    int people = 4;

    Dinic g(people + 2);

    int source = 0;
    int sink = people + 1;

    g.addEdge(source,1,50);
    g.addEdge(source,2,30);

    g.addEdge(3,sink,40);
    g.addEdge(4,sink,40);

    g.addEdge(1,3,50);
    g.addEdge(1,4,50);
    g.addEdge(2,3,30);
    g.addEdge(2,4,30);

    cout << "Maximum settlement flow: "
         << g.maxFlow(source,sink) << endl;
}