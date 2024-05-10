
/*
@ <authors>
 *
 * Nombre, apellidos y usuario del juez (TAISXX) de los autores de la solución.
 *
 * Daniel Barroso Casado
 * TAIS06
 *
 *@ </authors>

#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
using namespace std;

#include "DigrafoValorado.h"  // propios o los de las estructuras de datos de clase
#include "Index_PQ.h"
#include "PriorityQueue.h"


/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer>


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>


class MejorCamino {
public:
    MejorCamino(DigrafoValorado<int> const& g, int orig, int dest) : origen(orig), dest(dest),
        dist(g.V(), INF), distreal(g.V(), INF), distNodos(g.V(), INF), ant(g.V(), INF), visit(g.V(), false), ulti(g.V()), pq(g.V()), q() {

        dist[origen] = 0;
        distreal[origen] = 0;
        pq.push(origen, 0);
        while (!pq.empty()) {
            int v = pq.top().elem; pq.pop();

            for (auto a : g.ady(v))
                relajar(a);
        }

        if (dist[dest] < INF) {
            bfs(g);
        }
        

        solucion();
    }

    bool hayCamino(int v) const { return dist[v] != INF; }
    int distancia(int v) const { return dist[v]; }
    int getDistNodos(int v) const { return distNodos[v]; }

    void solucion() const{

        if (dist[dest] == INF) {
            cout << "SIN CAMINO\n";
        }
        else if (distreal[dest] > distNodos[dest]) {
            cout << dist[dest] << " NO\n";
        }
        else if (distreal[dest] == distNodos[dest]) {
            cout << dist[dest] << " SI\n";
        }

    }


private:

    const int INF = std::numeric_limits<int>::max();
    int origen;
    int dest;
    std::vector<int> dist;
    vector<int> distreal;
    std::vector<AristaDirigida<int>> ulti;
    IndexPQ<int> pq;

    std::vector<int> distNodos;
    vector<bool> visit;
    vector<int> ant;
    PriorityQueue<int> q;


    void bfs(DigrafoValorado<int> const& g) {
        std::queue<int> q;
        distNodos[origen] = 0; visit[origen] = true;
        q.push(origen);
        while (!q.empty()) {
            int v = q.front(); q.pop();
            for (auto a : g.ady(v)) {
                int w = a.hasta();
                if (!visit[w]) {
                    ant[w] = v;
                    distNodos[w] = distNodos[v] + 1; 
                    visit[w] = true;
                    q.push(w);
                }
            }
        }
    }

    void relajar(AristaDirigida<int> a) {
        int v = a.desde(), w = a.hasta();
        if (dist[w] > dist[v] + a.valor()) {
            dist[w] = dist[v] + a.valor();
            distreal[w] = distreal[v] + 1;
            ulti[w] = a;
            pq.update(w, dist[w]);
        }
        else if (dist[w] == dist[v] + a.valor() && distreal[w] > distreal[v] + 1) {
            distreal[w] = distreal[v] + 1;
        }
    }
};

bool resuelveCaso() {

    // leer los datos de la entrada

    int n, c, k;
    cin >> n;

    if (!cin)
        return false;

    cin >> c;

    DigrafoValorado<int> g(n);
    // resolver el caso posiblemente llamando a otras funciones

    int a1, a2, value;

    for (int i = 0; i < c; i++)
    {
        cin >> a1 >> a2 >> value;

        g.ponArista({ a1 - 1, a2 - 1, value });
        g.ponArista({ a2 - 1, a1 - 1, value });
    }
    // escribir la solución

    cin >> k;

    for (int i = 0; i < k; i++)
    {
        cin >> a1 >> a2;
        MejorCamino d(g, a1 - 1, a2 - 1);
    }
    cout << "---\n";

    return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("ej7-4.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    while (resuelveCaso());

    // para dejar todo como estaba al principio
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
    return 0;
}*/