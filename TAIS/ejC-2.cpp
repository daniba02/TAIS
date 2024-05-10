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
using namespace std;

#include "Matriz.h"
#include "EnterosInf.h"
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
    // escribir la soluci�n

    return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta l�nea ya no forma parte de la soluci�n.

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