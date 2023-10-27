
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
#include <functional>
#include <queue>
#include <string>

using namespace std;

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



bool resuelveCaso() {

    // leer los datos de la entrada

    int n, medio;

    cin >> medio >> n;

    if (medio == 0 && n == 0)
        return false;

    priority_queue<int, vector<int>, greater<int>> mayores;
    priority_queue<int> menores;


    for (int i = 0; i < n; i++) {

        int first, second;
        cin >> first >> second;

        if (first > medio) mayores.push(first);
        else menores.push(first);

        if (second > medio) mayores.push(second);
        else menores.push(second);

        while (mayores.size() != menores.size()) {

            if (mayores.size() < menores.size()) {

                mayores.push(medio);
                medio = menores.top();
                menores.pop();
            }
            else {

                menores.push(medio);
                medio = mayores.top();
                mayores.pop();
            }
        }

        cout << medio << " ";
    }

    cout << "\n";

    return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta l�nea ya no forma parte de la soluci�n.

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("ej3-2.txt");
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