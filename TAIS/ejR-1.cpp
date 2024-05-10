
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

#include "ConjuntosDisjuntos.h"
#include "PriorityQueue.h"
#include "GrafoValorado.h"


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
class ARM_Kruskal {
private:
    std::vector<Arista<Valor>> _ARM;
    Valor coste;
    Valor horas;
    bool conexo;

public:
    Valor costeARM() const {
        return coste;
    }

    Valor getHoras() const {
        return horas;
    }
    std::vector<Arista<Valor>> const& ARM() const {
        return _ARM;
    }
    ARM_Kruskal(GrafoValorado<Valor> const& g) : coste(0), horas(0), conexo(true) {
        PriorityQueue<Arista<Valor>> pq(g.aristas());
        ConjuntosDisjuntos cjtos(g.V());
        while (!pq.empty()) {
            auto a = pq.top(); pq.pop();
            int v = a.uno(), w = a.otro(v);
            if (!cjtos.unidos(v, w)) {
                cjtos.unir(v, w);
                if (a.valor() > horas) horas = a.valor();
                _ARM.push_back(a); coste += a.valor();
                if (_ARM.size() == g.V() - 1) break;
            }
        }
        if (cjtos.num_cjtos() > 1) horas = -1;
    }
};

void resuelveCaso() {


    int n, m;

    cin >> n >> m;
    // leer los datos de la entrada

    GrafoValorado<int> g(n);

    int a1, a2, value;

    for (int i = 0; i < m; i++)
    {
        cin >> a1 >> a2 >> value;

        g.ponArista({ a1 -1 , a2 - 1, value });
    }

    ARM_Kruskal<int> arm(g);

    if (arm.getHoras() == -1 ? cout << "Imposible\n" : cout << arm.getHoras() << "\n");
    // resolver el caso posiblemente llamando a otras funciones

    // escribir la soluci�n
}

//@ </answer>
//  Lo que se escriba dejado de esta l�nea ya no forma parte de la soluci�n.

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("ejR-1.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();

    // para dejar todo como estaba al principio
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
    return 0;
}*/