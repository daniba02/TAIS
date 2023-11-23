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
class Dijkstra {
public:
    Dijkstra(DigrafoValorado<Valor> const& g, int orig) : origen(orig),
        dist(g.V(), INF), ulti(g.V()), pq(g.V()), min(INF), cont(g.V(), 0), dest(g.V() - 1) {
        dist[origen] = 0;
        cont[origen] = 1;
        pq.push(origen, 0);
        while (!pq.empty()) {
            int v = pq.top().elem; pq.pop();
            for (auto a : g.ady(v))
                relajar(a);
        }
    }
    int getCont() const { return cont[dest]; }
    bool hayCamino(int v) const { return dist[v] != INF; }
    Valor distancia(int v) const { return dist[v]; }
    
    //Camino<Valor> camino(int v) const {
       Camino<Valor> cam;
        // recuperamos el camino retrocediendo
        AristaDirigida<Valor> a;
        for (a = ulti[v]; a.desde() != origen; a = ulti[a.desde()])
            cam.push_front(a);
        cam.push_front(a);
        return cam;
    }
private:
    const Valor INF = std::numeric_limits<Valor>::max();
    int origen;
    int dest;
    vector<Valor> cont;
    int min;
    std::vector<Valor> dist;
    std::vector<AristaDirigida<Valor>> ulti;
    IndexPQ<Valor> pq;
    void relajar(AristaDirigida<Valor> a) {
        int v = a.desde(), w = a.hasta();
        int n = dist[v] + a.valor();
        if (dist[w] > dist[v] + a.valor()) {
            dist[w] = dist[v] + a.valor();
            pq.update(w, dist[w]);
            cont[w] = cont[v];
        }
        else if (dist[w] == dist[v] + a.valor()) cont[w] += cont[v];
    }
};

bool resuelveCaso() {

    // leer los datos de la entrada
    int n, m;
    cin >> n;
    if (!std::cin)  // fin de la entrada
        return false;

    DigrafoValorado<int> g(n);
    cin >> m;

    int a1, a2, value;
    for (int i = 0; i < m; i++) {

        cin >> a1 >> a2 >> value;

        g.ponArista({ a1 - 1, a2 - 1, value });
        g.ponArista({ a2 - 1, a1 - 1, value });
    }
    // resolver el caso posiblemente llamando a otras funciones

    Dijkstra<int> sol (g, 0);
    // escribir la soluci�n

    cout << sol.getCont() << "\n";
    return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta l�nea ya no forma parte de la soluci�n.

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("ej7-2.txt");
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