
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
#include <algorithm>
using namespace std;


/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer>


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
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

    // escribir la solución
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

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