
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

#include "EnterosInf.h"  // propios o los de las estructuras de datos de clase
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

int resolver(Matriz<char> const& M, const int n, const int m) {

    int k = (n - 1) + (m - 1);

    vector<int> C(m);

   //
   //  00000    11111
   //  0X000    10123
   //  00X0X    11020
   //  00000    12244
   // 

    C[0] = 1;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (M[i][j] == 'X') {
                C[j] = 0;
            }
            else {

                int a;
                if (j - 1 >= 0) a = C[j - 1];
                else a = 0;

                C[j] = C[j] + a;
            }
        }
    }

    return C[m - 1];

}

bool resuelveCaso() {

    // leer los datos de la entrada

    int n, m;

    cin >> n;

    if (!std::cin)  // fin de la entrada
        return false;

    cin >> m;

    Matriz<char> v(n, m);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
        {
            cin >> v[i][j];
        }
    }

    cout << resolver(v, n, m) << "\n";
    // resolver el caso posiblemente llamando a otras funciones

    // escribir la soluci�n

    return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta l�nea ya no forma parte de la soluci�n.

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("ejA-3.txt");
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