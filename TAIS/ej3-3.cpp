
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
#include <functional>
#include <queue>
#include <string>
//#include <xtree>
//#include "BInTree.h";
//#include "Index_PQ.h"

using namespace std;

// propios o los de las estructuras de datos de clase

/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer>


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>



bool resuelveCaso() {

    // leer los datos de la entrada

    int N, A, B;

    cin >> N >> A >> B;

    if (!std::cin) return false;


    priority_queue<long long int> cola1;
    priority_queue<long long int> cola2;

    for (int i = 0; i < A; i++) {
        long long int time;
        cin >> time;
        cola1.push(time);
    }
    for (int i = 0; i < B; i++) {
        long long int time;
        cin >> time;
        cola2.push(time);
    }

    int suma;

    queue<pair<int, int>> pilas;


    while (!cola1.empty() && !cola2.empty()) {

        suma = 0;
        int i = 0;

        int v9;
        int v1;

        while (i < N && !cola1.empty() && !cola2.empty()) {

            v9 = cola1.top();
            v1 = cola2.top();
            int resto = min(v9, v1);
            cola1.pop();
            cola2.pop();
            suma += resto;

            v9 -= resto;
            v1 -= resto;

            pilas.push({ v9, v1 });

            /*
            if (cola1.top() < cola2.top()) {
                resto = cola2.top() - cola1.top();
                suma += cola1.top();
                cola1.pop();
                cola2.pop();
                cola2.push(resto);
            }
            else if (cola2.top() < cola1.top()) {
                resto = cola1.top() - cola2.top();
                suma += cola2.top();
                cola1.pop();
                cola2.pop();
                cola1.push(resto);
            }
            else {
                suma += cola1.top();
                cola1.pop();
                cola2.pop();
            }
            i++;
            i++;
        }

        while (!pilas.empty()) {

            if (pilas.front().first != 0) cola1.push(pilas.front().first);
            if (pilas.front().second != 0) cola2.push(pilas.front().second);

            pilas.pop();

        }
        //if (resto1 != 0) cola1.push(resto1);
        //if (resto2 != 0) cola2.push(resto2);

        cout << suma << " ";
    }
    cout << "\n";

    

    return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("ej3-3.txt");
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