
/*
@ <authors>
 *
 * Nombre, apellidos y usuario del juez (TAISXX) de los autores de la soluci�n.
 *
 * Daniel Barroso Casado
 * TAIS06
 *
 *@ </authors>*/

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

#include "DigrafoValorado.h"  // propios o los de las estructuras de datos de clase
#include "Index_PQ.h"

/*@ <answer>

 Escribe aqu� un comentario general sobre la soluci�n, explicando c�mo
 se resuelve el problema y cu�l es el coste de la soluci�n, en funci�n
 del tama�o del problema.

 @ </answer>


 // ================================================================
 // Escribe el c�digo completo de tu soluci�n aqu� debajo
 // ================================================================
 //@ <answer>*/

template <typename Valor>
class Dijkstra {
public:
    Dijkstra(DigrafoValorado<Valor> const& g, int orig, int dest) : origen(orig), dest(dest), dist(g.V(), INF), ulti(g.V()), pq(g.V()) {
        dist[origen] = origen;
        pq.push(origen, 0);
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
    /*
    Camino<Valor> camino(int v) const {
        Camino<Valor> cam;
        // recuperamos el camino retrocediendo
        AristaDirigida<Valor> a;
        for (a = ulti[v]; a.desde() != origen; a = ulti[a.desde()])
            cam.push_front(a);
        cam.push_front(a);
        return cam;
    }*/
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
            dist[w] = dist[v] + a.valor() + a.hasta(); ulti[w] = a;
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

    DigrafoValorado<int> g(mx + 1);

    cin >> m;
    int a1, a2, value;

    for (int i = 0; i < m; i++) {

        cin >> a1 >> a2 >> value;
        g.ponArista({ v[a1 - 1], v[a2 - 1], value });

    }

    Dijkstra<int> sol (g, v[0], v[n - 1]);

    if (sol.getDistancia() == -1) cout << "IMPOSIBLE\n";
    else cout << sol.getDistancia() << "\n";
    // resolver el caso posiblemente llamando a otras funciones

    // escribir la soluci�n

    return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta l�nea ya no forma parte de la soluci�n.

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
}
