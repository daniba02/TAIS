
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
#include <queue>
using namespace std;

#include "PriorityQueue.h"

/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer>


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer^

struct bateria {
    int id;
    int capacidad;
    int momento;
};

bool operator<(bateria const& a, bateria const& b) {

    return (a.momento < b.momento) || (a.momento == b.momento && a.id < b.id);
}

void resolver(PriorityQueue <bateria> tiempo, vector<bateria>& carga, const int z, const int t, const int b) {

    int fin = 0; 
    int cont = 0;

    while (!tiempo.empty() && tiempo.top().momento <= t) {

        bateria aux = tiempo.top();
        tiempo.pop();

        fin = aux.momento;
        aux.capacidad -= z;
        aux.momento = aux.momento + aux.capacidad;

        if (aux.capacidad > 0) {

            tiempo.push(aux);
        }
        else if (cont < carga.size()) {

            carga[cont].momento = carga[cont].capacidad + fin;
            tiempo.push(carga[cont]);
            cont++;
        }
    }

    if(tiempo.size() == b) {
        cout << "CORRECTO\n";
    }
    else if (tiempo.empty()) {
        cout << "ABANDONEN INMEDIATAMENTE LA BASE\n";
    }
    else {
        cout << "FALLO EN EL SISTEMA\n";
    }

    while (!tiempo.empty()) {
        cout << tiempo.top().id << " " << tiempo.top().momento << "\n";
        tiempo.pop();
    }
    
    cout << "---\n";
     
}

bool resuelveCaso() {

    // leer los datos de la entrada

    int b;
    cin >> b;

    if (!std::cin)  // fin de la entrada
        return false;

    PriorityQueue<bateria> tiempo;

    int c;
    for (int i = 0; i < b; i++)
    {
        cin >> c;
        tiempo.push({ i + 1, c, c});

        //cin >> tiempo[i].carga;
        //tiempo[i].id = i;
    }

    int r;
    cin >> r;
    vector<bateria> rep(r);
    //tiempo.resize(b + r);

    for (int i = 0; i < r; i++)
    {
        //cin >> tiempo[b + i];
        cin >> c;
        rep[i] = { i + 1 + b, c, -1 };
    }

    int z, t;

    cin >> z >> t;

    resolver(tiempo, rep, z, t, b);

    // resolver el caso posiblemente llamando a otras funciones

    // escribir la solución

    return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("ejR-9.txt");
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