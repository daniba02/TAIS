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

#include "Matriz.h"
#include "EnterosInf.h"
  // propios o los de las estructuras de datos de clase

/*@ <answer>

 Escribe aqu� un comentario general sobre la soluci�n, explicando c�mo
 se resuelve el problema y cu�l es el coste de la soluci�n, en funci�n
 del tama�o del problema.

 @ </answer>


 // ================================================================
 // Escribe el c�digo completo de tu soluci�n aqu� debajo
 // ================================================================
 //@ <answer>

const int INF = INT_MAX;

int costeCortes(vector<int> const& v) {
    int N = v.size();
    Matriz<int> M(N, N, 0);

    for (int d = 2; d < N; d++) {
        for (int i = 0; i < N - d; i++) {
            int j = i + d;
            M[i][j] = INF;
            for (int k = i + 1; k < j; k++) {
                int temp = M[i][k] + M[k][j] + 2 * (v[j] - v[i]);
                if (temp < M[i][j])
                    M[i][j] = temp;
            }
        }
    }
    return M[0][N - 1];
}

bool resuelveCaso() {

    // leer los datos de la entrada

    int n, l;
    cin >> l >> n;

    if (n == 0 && l == 0)
        return false;

    vector<int> v(n + 2);
    v[0] = 0;
    v[n + 1] = l;

    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
    }

    // resolver el caso posiblemente llamando a otras funciones

    cout << costeCortes(v) << "\n";
    // escribir la soluci�n

    return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta l�nea ya no forma parte de la soluci�n.

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("ejC-1.txt");
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