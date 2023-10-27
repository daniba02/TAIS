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
//#include "PriorityQueue.h"
#include <vector>
#include <functional>
#include <queue>

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

bool resuelveCaso() {

    // leer los datos de la entrada

    long long int n, num1, num2, suma = 0, effort = 0;

    priority_queue<long long int, vector<long long int>, greater<long long int>> cola;
   

    cin >> n;

    if (n == 0)
        return false;

    for (long long int i = 0; i < n; i++) {

        cin >> num1;
        cola.push(num1);
    }

    

    while (cola.size() > 0) {


        num1 = cola.top(); // 1

        if (cola.size() > 1) { // 1 2 3 4 5


            cola.pop();
            num2 = cola.top(); // 2
            

            suma = num1 + num2; // 1 + 2

            effort += suma; //0 + 3

            
            cola.pop();
            cola.push(suma); 

            
        }
        else {
            cola.pop();
        }
        

    }

    // resolver el caso posiblemente llamando a otras funciones

    // escribir la solución

    cout << effort << endl;

    return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("ej2-1.txt");
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
