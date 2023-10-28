
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
using namespace std;

#include "DigrafoValorado.h"  // propios o los de las estructuras de datos de clase
#include "Index_PQ.h"

/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer>


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>

template <typename Valor>
class Dijkstra {
public:
    Dijkstra(DigrafoValorado<Valor> const& g, vector<int> v) : origen(0), dest(g.V() - 1), dist(g.V(), INF), ulti(g.V()), pq(g.V()), coste(v) {
        dist[origen] = coste[0];
        pq.push(origen, coste[0]);
        while (!pq.empty()) {
            int v = pq.top().elem; pq.pop();
            for (auto a : g.ady(v))
                relajar(a);
        }
    }
    bool hayCamino(int v) const { return dist[v] != INF; }

    int getDistancia() {
        if (dist[dest] != INF) return dist[dest];
        else return -1;
    }

    Valor distancia(int v) const { return dist[v]; }

private:
    const Valor INF = std::numeric_limits<Valor>::max();
    int origen;
    int dest;
    vector<int> coste;
    std::vector<Valor> dist;
    std::vector<AristaDirigida<Valor>> ulti;
    IndexPQ<Valor> pq;

    void relajar(AristaDirigida<Valor> a) {
        int v = a.desde(), w = a.hasta();
        if (dist[w] > dist[v] + a.valor() + coste[w]) {
            dist[w] = dist[v] + a.valor() + coste[w];
            pq.update(w, dist[w]);
        }
    }
};

bool resuelveCaso() {

    // leer los datos de la entrada

    int n, m;
    cin >> n;

    if (n == 0)
        return false;

    vector<int> v(n);
    int mx = 0;

    for (int i = 0; i < n; i++) {
        cin >> v[i];
        mx = max(mx, v[i]);    
    }

    DigrafoValorado<int> g(n);

    cin >> m;
    int a1, a2, value;

    for (int i = 0; i < m; i++) {

        cin >> a1 >> a2 >> value;
        g.ponArista({ a1 - 1, a2 - 1, value });

    }

    Dijkstra<int> sol (g, v);

    if (sol.getDistancia() == -1) cout << "IMPOSIBLE\n";
    else cout << sol.getDistancia() << "\n";
    // resolver el caso posiblemente llamando a otras funciones

    // escribir la solución

    return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("ej7-1.txt");
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
