
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

#include "EnterosInf.h"
#include "Matriz.h"

/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer>


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>

vector<int> minDardos(vector<int> const& M, int C) {
    int n = M.size();
    vector<EntInf> monedas(C + 1, Infinito);
    monedas[0] = 0;
    // calcular la matriz sobre el propio vector
    for (int i = 1; i <= n; ++i) {
        for (int j = M[i - 1]; j <= C; ++j) {
            monedas[j] = min(monedas[j], monedas[j - M[i - 1]] + 1);
        }
    }
    vector<int> sol;
    if (monedas[C] != Infinito) {
        int i = n, j = C;
        while (j > 0) { // no se ha pagado todo
            if (M[i - 1] <= j && monedas[j] == monedas[j - M[i - 1]] + 1) {
                // tomamos una moneda de tipo i
                sol.push_back(M[i - 1]);
                j = j - M[i - 1];
            }
            else // no tomamos más monedas de tipo i
                --i;
        }
    }
    return sol;
}


bool resuelveCaso() {

    // leer los datos de la entrada

    int n, c;

    cin >> c >> n;

    if (!std::cin)  // fin de la entrada
        return false;

    vector<int> M(n);

    for (int i = 0; i < n; i++) {
        cin >> M[i];
    }
    // resolver el caso posiblemente llamando a otras funciones

    vector<int> sol = minDardos(M, c);

    if (sol.empty()) cout << "Imposible";
    else cout << sol.size() << ": ";

    for (int a : sol) {

        cout << a << " ";
    }
    cout << "\n";

    
    // escribir la solución

    return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("ejA-2.txt");
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