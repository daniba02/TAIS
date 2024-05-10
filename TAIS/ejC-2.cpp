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
using namespace std;

#include "Matriz.h"
#include "EnterosInf.h"
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

struct horas {
    int ini;
    int fin;
    int duracion;
};

bool operator<(horas const& a, horas const& b) {
    return a.ini < b.ini;
}

void resolver(vector<horas> const& v) {

    int n = v.size() - 1;


    

    //aqui se resuelve el problema :)
}

bool resuelveCaso() {

    // leer los datos de la entrada

    int n;
    cin >> n;

    if (n == 0)
        return false;

    vector<horas> v(n);

    int h;
    char c;
    int m;
    int duracion;

    for (int i = 0; i < n; i++)
    {
        
        cin >> h >> c >> m >> duracion;
        m += h * 60;
        v[i].ini = m;
        v[i].fin = m + duracion;
        v[i].duracion = duracion;
    }

    // resolver el caso posiblemente llamando a otras funciones

    resolver(v);
    // escribir la solución

    return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("ejC-2.txt");
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