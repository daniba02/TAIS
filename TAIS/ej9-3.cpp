
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
#include <algorithm>
using namespace std;


/*@ <answer>

 Escribe aqu� un comentario general sobre la soluci�n, explicando c�mo
 se resuelve el problema y cu�l es el coste de la soluci�n, en funci�n
 del tama�o del problema.

 @ </answer>


 // ================================================================
 // Escribe el c�digo completo de tu soluci�n aqu� debajo
 // ================================================================
 //@ <answer>

int resolver(vector<int>& pilas, const int n, const int k) {

    sort(pilas.begin(), pilas.end(), greater<int>());

    int ini = 0;
    int fin = n - 1;
    int cont = 0;

    while (fin - ini > 0) {
        bool factible = false;

        while (!factible && fin - ini > 0) {

            if (pilas[ini] + pilas[fin] >= k) {
                
                cont++;
                ini++;
                factible = true;
            }

            fin--;
        }
    }

    return cont;
}

void resuelveCaso() {

    // leer los datos de la entrada

    int n, v;
    cin >> n >> v;
    
    vector<int> pilas(n);

    for (int i = 0; i < n; i++)
    {
        cin >> pilas[i];
    }

    cout << resolver(pilas, n, v) << "\n";

    // resolver el caso posiblemente llamando a otras funciones

    // escribir la soluci�n
}

//@ </answer>
//  Lo que se escriba dejado de esta l�nea ya no forma parte de la soluci�n.

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("ej9-3.txt");
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