
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

#include "PriorityQueue.h"

/*@ <answer>

 Escribe aqu� un comentario general sobre la soluci�n, explicando c�mo
 se resuelve el problema y cu�l es el coste de la soluci�n, en funci�n
 del tama�o del problema.

 @ </answer>


 // ================================================================
 // Escribe el c�digo completo de tu soluci�n aqu� debajo
 // ================================================================
 //@ <answer>

long long int resolver(PriorityQueue<long long int>& q) {
    
    long long int acum = 0;

    while (q.size() > 1) {

        long long int e1 = q.top();
        q.pop();
        long long int e2 = q.top();
        q.pop();

        long long int suma = e1 + e2;

        if(!q.empty()) q.push(suma);

        acum += suma;
    }
    
    return acum;
}

bool resuelveCaso() {

    // leer los datos de la entrada

    int n;
    cin >> n;

    if (n == 0)  // fin de la entrada
        return false;

    PriorityQueue<long long int> v;
    long long int value;

    for (int i = 0; i < n; i++)
    {
        cin >> value;
        v.push(value);
    }
    // resolver el caso posiblemente llamando a otras funciones

    cout << resolver(v) << "\n";
    // escribir la soluci�n

    return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta l�nea ya no forma parte de la soluci�n.

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("ejR-7.txt");
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