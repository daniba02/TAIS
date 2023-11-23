
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
    Dijkstra(DigrafoValorado<Valor> const& g, int orig, int dest) : origen(orig),
        dist(g.V(), INF), ulti(g.V()), pq(g.V()), dest(dest) {
        dist[origen] = 0;
        pq.push(origen, 0);
        while (!pq.empty()) {
            int v = pq.top().elem; pq.pop();
            for (auto a : g.ady(v))
                relajar(a);
        }
    }
   
    bool hayCamino(int v) const { return dist[v] != INF; }
    Valor distancia(int v) const { return dist[v]; }

private:
    const Valor INF = std::numeric_limits<Valor>::max();
    int origen;
    int dest;
    std::vector<Valor> dist;
    std::vector<AristaDirigida<Valor>> ulti;
    IndexPQ<Valor> pq;
    void relajar(AristaDirigida<Valor> a) {
        int v = a.desde(), w = a.hasta();
        if (dist[w] > dist[v] + a.valor()) {
            dist[w] = dist[v] + a.valor(); ulti[w] = a;
            pq.update(w, dist[w]);
        }
    }
};

bool resuelveCaso() {

    // leer los datos de la entrada

    int n, c, k;
    cin >> n;

    if (!cin)
        return false;

    DigrafoValorado<int> g(n);

    cin >> c;
    int a1, a2, value;

    for (int i = 0; i < c; i++) {

        cin >> a1 >> a2 >> value;
        g.ponArista({ a1 - 1, a2 - 1, value });
        g.ponArista({ a2 - 1, a1 - 1, value });

    }

    cin >> k;
    int origen, destino;

    for (int i = 0; i < k; i++) {
        cin >> origen >> destino;
        origen--;
        destino--;
        Dijkstra<int> sol(g, origen , destino );
        
        if (sol.hayCamino(destino )) cout << sol.distancia(destino ) << "\n";
        else cout << "NO LLEGA\n";
    }

    cout << "---\n";

    // resolver el caso posiblemente llamando a otras funciones

    // escribir la solución

    return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("ej7-3.txt");
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