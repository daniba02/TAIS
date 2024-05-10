

/*
@ <authors>
 *
 * Nombre, apellidos y usuario del juez (TAISXX) de los autores de la solución.
 *
 * Daniel Barroso Casado
 * TAIS06
 *
 *@ </authors>*/

#include <iostream>
#include <fstream>
#include <vector>
#include <climits>
using namespace std;

#include "DigrafoValorado.h"  // propios o los de las estructuras de datos de clase
#include "IndexPQ.h"
#include "GrafoValorado.h"
#include "PriorityQueue.h"
#include "ConjuntosDisjuntos.h";




/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer>


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>*/

template <typename Valor>
class ARM_Kruskal {
private:
    std::vector<Arista<Valor>> _ARM;
    Valor coste;
public:
    Valor costeARM() const {
        return coste;
    }
    std::vector<Arista<Valor>> const& ARM() const {
        return _ARM;
    }
    ARM_Kruskal(GrafoValorado<Valor> const& g, int origen, int destino) : coste(-1) {
        PriorityQueue<Arista<Valor>> pq(g.aristas());
        ConjuntosDisjuntos cjtos(g.V());
        bool terminado = false;

        while (!pq.empty() && !terminado) {
            auto a = pq.top(); pq.pop();
            int v = a.uno(), w = a.otro(v);

            if (!cjtos.unidos(v, w)) {
                cjtos.unir(v, w);

                if (cjtos.unidos(origen, destino)) {
                    terminado = true;
                    coste = a.valor();
                }
                _ARM.push_back(a);
                if (_ARM.size() == g.V() - 1) break;
            }
        }
    }
};

template <typename Valor>

class Dijkstra{
public:
    Dijkstra(DigrafoValorado<Valor> const& g, int orig) : origen(orig),
        dist(g.V(), INF), ulti(g.V()), pq(g.V()){
        dist[origen] = 0;
        pq.push(origen, 0);
        while (!pq.empty()) {
            int v = pq.top().elem; pq.pop();
            for (auto a : g.ady(v))
                relajar(a);
        }
    }

    Valor distancia(int v) const { return dist[v]; }



private:
    const Valor INF = std::numeric_limits<Valor>::max();
    int origen;
    std::vector<Valor> dist;
    std::vector<AristaDirigida<Valor>> ulti;
    IndexPQ<Valor> pq;
    void relajar(AristaDirigida<Valor> a) {
        int v = a.desde(), w = a.hasta();
        if (dist[w] > a.valor()) {

            AristaDirigida<Valor> aux = ulti[v];
            if (v == origen) {
                dist[w] = a.valor(); 
                ulti[w] = a;
                pq.update(w, dist[w]);
            }
            else {

                if (dist[aux.hasta()] < a.valor() && aux.hasta() != w) {
                    dist[w] = a.valor();
                    ulti[w] = a;
                    pq.update(w, dist[w]);
                }
                else {
                    dist[w] = dist[aux.hasta()];
                    ulti[w] = a;
                }
            }
        }
    }
};

const int INF = INT_MAX;

bool resuelveCaso() {

    // leer los datos de la entrada


    int n, m;

    cin >> n >> m;

    if (!std::cin)  // fin de la entrada
        return false;
    /*
    GrafoValorado<int> g(n);

    int a1, a2, value;
    for (int i = 0; i < m; i++)
    {
        cin >> a1 >> a2 >> value;

        g.ponArista({ a1 - 1, a2 - 1, value });
    }
    // resolver el caso posiblemente llamando a otras funciones

    int origen, dest;
    cin >> origen >> dest;

    if (origen == dest) {
        cout << 0;
    }
    else {
        ARM_Kruskal<int> d(g, origen - 1, dest - 1);
        if(d.costeARM() != -1 ? cout << d.costeARM() : cout << "IMPOSIBLE");
    }*/

    DigrafoValorado<int> g(n);

    int a1, a2, value;
    for (int i = 0; i < m; i++)
    {
        cin >> a1 >> a2 >> value;

        g.ponArista({ a1 - 1, a2 - 1, value });
        g.ponArista({ a2 - 1, a1 - 1, value });
    }
    // resolver el caso posiblemente llamando a otras funciones

    int origen, dest;
    cin >> origen >> dest;

    if (origen == dest) {
        cout << 0;
    }
    else {
        Dijkstra<int> d(g, origen - 1);
        if (d.distancia(dest - 1) != INF ? cout << d.distancia(dest - 1) : cout << "IMPOSIBLE");
    }
    

    cout << "\n";

    // escribir la solución

    return true;
}

/*

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("ejx-1.txt");
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
