
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

int resolver(vector<int>& jug, vector<int>& tallas, const int n) {

    sort(jug.begin(), jug.end(), greater<int>());

    int comprar = 0; 
    int cont = 0; 

    for (int i = 0; i < n; i++)
    {

        if (tallas[jug[i] + 1] > 0){
            tallas[jug[i] + 1]--;
        }
        else if (tallas[jug[i]] > 0) {
            tallas[jug[i]]--;
        }
        else {
            comprar++;
        }
    }

    return comprar;
}

bool resuelveCaso() {

    // leer los datos de la entrada

    int n, m;

    cin >> n >> m;

    if (!std::cin)  // fin de la entrada
        return false;
    
    vector<int> jug(n);
    vector<int> tallas(100001);

    for (int i = 0; i < n; i++)
    {
        cin >> jug[i];
    }

    int talla;
    for (int i = 0; i < m; i++)
    {
        cin >> talla;
        tallas[talla]++;

        //cin >> tallas[i];
    }

    cout << resolver(jug, tallas, n) << "\n";
    // resolver el caso posiblemente llamando a otras funciones

    // escribir la solución

    return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("ej8-3.txt");
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