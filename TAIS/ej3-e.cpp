
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
#include <unordered_map>
using namespace std;

#include "Index_PQ.h"  // propios o los de las estructuras de datos de clase

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

    int n;
    
    cin >> n;

    if (!std::cin)  // fin de la entrada
        return false;

    string caso;
    string nombre;
    int num;
    int cont = 0; 

    IndexPQ<int> q(n);
    unordered_map<string, int> m;

    for (int i = 0; i < n; i++) {
        cin >> caso;

        if (caso == "C") {
            
            cin >> nombre;
            cin >> num;

            if (m.count(nombre) == 0) {
                m.insert({ nombre, cont });
                cont++;
            }
            q.update(m.at(nombre), num);
        }
        else if (caso == "E") {

            cin >> nombre;
            cin >> num;

            if (m.count(nombre) == 0) {
                m.insert({ nombre, cont });
                cont++;
            }
            q.update(m.at(nombre), num);
        }
        else if (caso == "TC") {

            for (int i = 0; i < 3; i++)
            {
                cout << q.top().elem;
            }
        }
        
    }
    // resolver el caso posiblemente llamando a otras funciones

    // escribir la soluci�n

    return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta l�nea ya no forma parte de la soluci�n.

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("casos.txt");
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