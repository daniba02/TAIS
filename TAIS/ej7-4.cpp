
/*
@ <authors>
 *
 * Nombre, apellidos y usuario del juez (TAISXX) de los autores de la soluci�n.
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

/*@ <answer>

 Escribe aqu� un comentario general sobre la soluci�n, explicando c�mo
 se resuelve el problema y cu�l es el coste de la soluci�n, en funci�n
 del tama�o del problema.

 @ </answer>


 // ================================================================
 // Escribe el c�digo completo de tu soluci�n aqu� debajo
 // ================================================================
 //@ <answer>
template <typename Valor>

using Camino = deque<Valor>;

template <typename Valor>
class Dijkstra {
public:
    Dijkstra(DigrafoValorado<Valor> const& g, int orig, int dest) : origen(orig),
        dist(g.V(), INF), ulti(g.V()), pq(g.V()), dest(dest), num(g.V(), INF), recor(g.V(), INF) {
        dist[origen] = 0;
        num[origen] = 0;
        recor[origen] = 0;
        pq.push(origen, 0);
        while (!pq.empty()) {
            int v = pq.top().elem; pq.pop();
            for (auto a : g.ady(v))
                relajar(a);
        }
    }

    bool hayCamino(int v) const { return dist[v] != INF; }
    Valor caminoMin(int v) const { return num[v]; }
    Valor caminoReal(int v) const { return recor[v]; }
    Valor distancia(int v) const { return dist[v]; }

    Camino<AristaDirigida<Valor>> camino(int v) const {
        Camino<AristaDirigida<Valor>> cam;
        // recuperamos el camino retrocediendo
        AristaDirigida<Valor> a;
        for (a = ulti[v]; a.desde() != origen; a = ulti[a.desde()]) {
            cam.push_front(a);
        }
        cam.push_front(a);
        return cam;
    }

private:
    const Valor INF = std::numeric_limits<Valor>::max();
    int origen;
    int dest;
    std::vector<Valor> dist;
    vector<Valor> num;
    vector<Valor> recor;
    std::vector<AristaDirigida<Valor>> ulti;
    IndexPQ<Valor> pq;
    void relajar(AristaDirigida<Valor> a) {
        int v = a.desde(), w = a.hasta();

        if (num[v] + 1 < num[w]) num[w] = num[v] + 1;

        if (dist[w] > dist[v] + a.valor()) {
            recor[w] = recor[v] + 1;
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

    int origen , dest;
    cin >> k;
    for (int i = 0; i < k; i++) {
        cin >> origen >> dest;
        origen--;
        dest--;

        Dijkstra<int> sol(g, origen, dest);

        if (sol.hayCamino(dest)) {
            cout << sol.distancia(dest);
            if (sol.caminoReal(dest) <= sol.caminoMin(dest) ? cout << " SI\n" : cout << " NO\n");
        }
        else cout << "SIN CAMINO\n";

    }

    cout << "---\n";

    

    // resolver el caso posiblemente llamando a otras funciones

    // escribir la soluci�n

    return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta l�nea ya no forma parte de la soluci�n.

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