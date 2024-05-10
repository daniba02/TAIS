
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


/*@ <answer>

 Escribe aqu� un comentario general sobre la soluci�n, explicando c�mo
 se resuelve el problema y cu�l es el coste de la soluci�n, en funci�n
 del tama�o del problema.

 @ </answer>


 // ================================================================
 // Escribe el c�digo completo de tu soluci�n aqu� debajo
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
//  Lo que se escriba dejado de esta l�nea ya no forma parte de la soluci�n.

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