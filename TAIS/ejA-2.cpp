
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

#include "EnterosInf.h"
#include "Matriz.h"

/*@ <answer>

 Escribe aqu� un comentario general sobre la soluci�n, explicando c�mo
 se resuelve el problema y cu�l es el coste de la soluci�n, en funci�n
 del tama�o del problema.

 @ </answer>


 // ================================================================
 // Escribe el c�digo completo de tu soluci�n aqu� debajo
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
            else // no tomamos m�s monedas de tipo i
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

    
    // escribir la soluci�n

    return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta l�nea ya no forma parte de la soluci�n.

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