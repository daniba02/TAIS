
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
using namespace std;

#include "GrafoValorado.h"
#include "PriorityQueue.h"
#include "ConjuntosDisjuntos.h"

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
class ARM_Kruskal {
private:
    std::vector<Arista<Valor>> _ARM;
    Valor coste;
    int cont;
    int k;

public:
    Valor costeARM() const {
        return coste;
    }

    int getCont() const {
        return cont;
    }

    std::vector<Arista<Valor>> const& ARM() const {
        return _ARM;
    }
    ARM_Kruskal(GrafoValorado<Valor> const& g, int k) : coste(0), cont(0), k(k) {
        PriorityQueue<Arista<Valor>> pq(g.aristas());
        ConjuntosDisjuntos cjtos(g.V());

        while (!pq.empty()) {
            auto a = pq.top(); pq.pop();
            int v = a.uno(), w = a.otro(v);
            if (a.valor() < k && !cjtos.unidos(v, w)) {
                cjtos.unir(v, w);
                _ARM.push_back(a); 
                coste += a.valor();
                if (_ARM.size() == g.V() - 1) break;
            }
        }

        cont = cjtos.num_cjtos();
    }
};

bool resuelveCaso() {

    // leer los datos de la entrada

    int n, m, k;
    cin >> n >> m >> k;

    if (!std::cin)  // fin de la entrada
        return false;

    GrafoValorado<int> g(n);
    // resolver el caso posiblemente llamando a otras funciones

    int x, y, c;
    for (int i = 0; i < m; i++) {

        cin >> x >> y >> c;

        g.ponArista({ x - 1, y - 1, c });
    }
    // escribir la solución

    ARM_Kruskal<int> tree(g, k);

    
    cout << tree.costeARM() + k * tree.getCont() << " " << tree.getCont() << "\n";

    return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("ej6-4.txt");
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