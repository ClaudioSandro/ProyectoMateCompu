#ifndef FORDFULKERSON_H
#define FORDFULKERSON_H

#include <iostream>
#include <limits.h>
#include <string.h>
#include <queue>
#include <ctime>
#include <cstdlib>
#include <algorithm> // Para std::min

class FordFulkerson {
public:
    FordFulkerson(int vertices);
    int findMaxFlow(int** graph, int source, int sink);
    ~FordFulkerson(); // Destructor para liberar memoria

private:
    int vertices;
    bool bfs(int** rGraph, int s, int t, int* parent);
    int** createGraphCopy(int** graph); // Función para crear una copia del gráfico
    int** rGraph; // Matriz para el gráfico residual
};

FordFulkerson::FordFulkerson(int vertices) {
    this->vertices = vertices;
    rGraph = nullptr;
}

FordFulkerson::~FordFulkerson() {
    if (rGraph != nullptr) {
        for (int i = 0; i < vertices; i++) {
            delete[] rGraph[i];
        }
        delete[] rGraph;
    }
}

bool FordFulkerson::bfs(int** rGraph, int s, int t, int* parent) {
    bool* visited = new bool[vertices];
    memset(visited, 0, sizeof(bool) * vertices);

    std::queue<int> q;
    q.push(s);
    visited[s] = true;
    parent[s] = -1;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v = 0; v < vertices; v++) {
            if (!visited[v] && rGraph[u][v] > 0) {
                q.push(v);
                parent[v] = u;
                visited[v] = true;
            }
        }
    }

    // Si llegamos a 't' en BFS, entonces existe un camino
    return visited[t];
}


int FordFulkerson::findMaxFlow(int** graph, int source, int sink) {
    // Crear una copia del gráfico para trabajar con él
    rGraph = createGraphCopy(graph);

    int u, v;
    int* parent = new int[vertices];
    int max_flow = 0; // No hay flujo inicialmente

    while (bfs(rGraph, source, sink, parent)) {
        // Encuentra capacidad residual mínima de los bordes a lo largo del camino
        // llenado por BFS. O podemos decir encontrar el flujo máximo
        // a través de la ruta encontrada.
        int path_flow = INT_MAX;
        for (v = sink; v != source; v = parent[v]) {
            u = parent[v];
            path_flow = std::min(path_flow, rGraph[u][v]);
        }

        // Actualizar las capacidades residuales de las aristas y las aristas a lo largo de la trayectoria inversa
        for (v = sink; v != source; v = parent[v]) {
            u = parent[v];
            rGraph[u][v] -= path_flow;
            rGraph[v][u] += path_flow;
        }

        // Agregar el flujo de la ruta al flujo total
        max_flow += path_flow;
    }

    // Liberar la memoria
    delete[] parent;

    return max_flow;
}

int** FordFulkerson::createGraphCopy(int** graph) {
    int** copy = new int*[vertices];
    for (int i = 0; i < vertices; i++) {
        copy[i] = new int[vertices];
        for (int j = 0; j < vertices; j++) {
            copy[i][j] = graph[i][j];
        }
    }
    return copy;
}

#endif // FORDFULKERSON_H
