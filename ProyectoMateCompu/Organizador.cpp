#pragma once
#include "Recursos.h"

bool bfs(int rGraph[V][V], int s, int t, int parent[])
{
    // Crear una matriz visitado y marcar todos los vértices como no visitados
    bool visited[V];
    memset(visited, 0, sizeof(visited));
    // Creación de una cola, vértice fuente encola y marcar vértices fuente
    // como visitado
    queue <int> q;
    q.push(s);
    visited[s] = true;
    parent[s] = -1;
    // Standard BFS Loop
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int v = 0; v < t + 1; v++)
        {
            if (visited[v] == false && rGraph[u][v] > 0)
            {
                q.push(v);
                parent[v] = u;
                visited[v] = true;
            }
        }
    }
    //Si llegamos a caer en BFS a partir de la fuente, y luego volver
    // true, else false
    return (visited[t] == true);
}

int fordFulkerson(int graph[V][V], int s, int t)
{
    int u, v;
    // Crear un gráfico residual y llenar la gráfica residual con
    //capacidades que figuran en el gráfico original como las capacidades residuales
    //En el gráfico residual
    int rGraph[V][V]; // Gráfica residual donde rGraph [i] [j]
    //indica la capacidad residual de borde de i a j (si hay un borde.
    //Si rGraph [i] [j] es 0, entonces todavía no hay)
    for (u = 0; u < (t + 1); u++)
        for (v = 0; v < (t + 1); v++)
            rGraph[u][v] = graph[u][v];
    int parent[V]; // Esta matriz es llenada por BFS y ruta almacenada
    int max_flow = 0; // No hay flujo inicialmente
    // Aumentar el flujo mientras que hay camino desde la fuente al sumidero

    while (bfs(rGraph, s, t, parent))
    {
        // Encuentra capacidad residual mínima de los bordes a lo largo del camino
        // llenado por BFS. O podemos decir encontrar el flujo máximo
        // a través de la ruta encontrada.
        int path_flow = INT_MAX;
        for (v = t; v != s; v = parent[v])
        {
            u = parent[v];
            path_flow = min(path_flow, rGraph[u][v]);
        }
        // Actualizar las capacidades residuales de las aristas y las aristas a lo largo de la trayectoria inversa

        for (v = t; v != s; v = parent[v])
        {
            u = parent[v];
            rGraph[u][v] -= path_flow;
            rGraph[v][u] += path_flow;
        }
        // Add path flow to overall flow
        max_flow += path_flow;
    }
    // Devuelve el flujo total

    return max_flow;

}

int main()
{
    //bool lel = true;
    //while (lel) {
    //    cout << "Elige la cantidad de nodos.";
    //    int asd;
    //    cin >> asd;
    //    switch (asd) {
    //    case 5:
    //        const int b = 5;
    //    }
    //}
    // Vamos a crear un gráfico que se muestra en el ejemplo anterior
    /*int graph[V][V] = {{0, 17, 13, 10, 0, 0}, //c01c02
                        {0, 0, 10, 12, 0, 0}, //c12c13
                        {0, 4, 0, 0, 4, 0}, //c21c24
                        {0, 0, 9, 0, 0, 20}, //c32c35
                        {0, 0, 0, 7, 0, 4}, //c43c45
                        {0, 0, 0, 0, 0, 0}

    };*/

    srand(time(0));
    bool lel = true;
    int a;
    while (lel) {
        cout << "Elige la cantidad de nodos.";
        int asd; cin >> asd;
        if (asd >= 5 && asd <= 15) { a = asd; break; }
    }
    int graph[V][V];
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < a; j++) {
            graph[i][j] = rand() % 21;
        }

    }


    cout << "Matriz: " << endl << endl;
    for (int i = 0; i <= a; i++) {
        if (i != 0) cout << i << " ";
        else cout << "   ";
        if (i < 10) cout << " ";
    }
    cout << endl << endl;
    for (int i = 0; i < a; i++) {
        cout << i + 1 << ":  ";
        for (int j = 0; j < a; j++) {
            cout << graph[i][j] << " ";
            if (graph[i][j] < 10) cout << " ";
        }
        cout << endl;
    }
    cout << endl;
    cout << "El flujo máximo posible es: " << fordFulkerson(graph, 0, (a - 1)) << "\n";
    return 0;
}
