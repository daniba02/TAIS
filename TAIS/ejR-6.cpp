
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
    Dijkstra(DigrafoValorado<Valor> const& aux, int orig, int tiempo) : cont(0), tiempo(tiempo), origen(orig),
        dist(aux.V(), INF), ulti(aux.V()), pq(aux.V()), llega(aux.V(), false) {
        
        DigrafoValorado<Valor> g = aux.inverso();

        dist[origen] = 0;
        pq.push(origen, 0);
        while (!pq.empty()) {
            int v = pq.top().elem; pq.pop();
            for (auto a : g.ady(v))
                relajar(a);
        }
    }

    Valor distancia(int v) const { return dist[v]; }
    int getCont() const { return cont; }

private:
    const Valor INF = std::numeric_limits<Valor>::max();
    int origen;
    int tiempo;
    int cont;
    std::vector<Valor> dist;
    std::vector<AristaDirigida<Valor>> ulti;
    vector<bool> llega;
    IndexPQ<Valor> pq;
    void relajar(AristaDirigida<Valor> a) {
        int v = a.desde(), w = a.hasta();
        if (dist[w] > dist[v] + a.valor()) {
            dist[w] = dist[v] + a.valor(); ulti[w] = a;
            if (!llega[w] && dist[w] <= tiempo) {
                cont++;
                llega[w] = true;
            }
            pq.update(w, dist[w]);
        }
    }
};

bool resuelveCaso() {

    // leer los datos de la entrada

    int n, s, t, p;
    cin >> n >> s >> t >> p;
    if (!std::cin)  // fin de la entrada
        return false;

    DigrafoValorado<int> g(n);
    int a1, a2, value;
    for (int i = 0; i < p; i++)
    {
        cin >> a1 >> a2 >> value;

        g.ponArista({ a1 - 1, a2 - 1, value });
    }

    Dijkstra<int> d(g, s - 1, t);

    cout << d.getCont() << "\n";



    // resolver el caso posiblemente llamando a otras funciones

    // escribir la soluci�n

    return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta l�nea ya no forma parte de la soluci�n.

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("ejR-6.txt");
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