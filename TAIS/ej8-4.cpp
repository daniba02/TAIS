
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

struct pelicula {

    int ini;
    int fin;
};

bool operator<(pelicula const& a, pelicula const& b) {
    return a.fin < b.fin;
}

int resolver(vector<pelicula>& v, const int n) {

    sort(v.begin(), v.end());

    int peliculas = 0; 
    int hora = 0;

    for (int i = 0; i < n; i++) {

        if (v[i].ini >= hora) {
            peliculas++;
            hora = v[i].fin + 10;
        }
    }

    return peliculas;
}

bool resuelveCaso() {

    // leer los datos de la entrada

    int n;

    cin >> n;

    if (n == 0)  // fin de la entrada
        return false;

   
    int hora;
    int minuto;
    int duracion;
    char c;

    vector<pelicula> v(n);

    for (int i = 0; i < n; i++)
    {
        cin >> hora;
        cin >> c;
        cin >> minuto;

        v[i].ini = hora * 60 + minuto;
        cin >> duracion;

        v[i].fin = v[i].ini + duracion;
    }

    cout << resolver(v, n) << "\n";

    return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("ej8-4.txt");
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