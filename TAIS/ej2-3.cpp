
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
using namespace std;
#include <vector>
#include <functional>
#include <queue>
#include <string>



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


struct tPaciente {

    string nombre;
    int gravedad;
    int posicion;

};

bool operator<(tPaciente const& a, tPaciente const& b) {

    return a.gravedad < b.gravedad || (b.gravedad == a.gravedad && b.posicion < a.posicion);

}

bool resuelveCaso() {

    // leer los datos de la entrada

    int n, k, posicion = 0;;

    cin >> n;

    if (n == 0)
        return false;

    priority_queue<tPaciente> cola;

    while (n--) {

        char event;
        cin >> event;

        if (event == 'I') {

            int gravedad;
            string nombre;

            cin >> nombre >> gravedad;

            cola.push({ nombre, gravedad, posicion });
            posicion++;
        }
        else if (event == 'A') {
            
            auto e = cola.top();
            cola.pop();

            cout << e.nombre << '\n';
        }
    }
 


    cout << "---\n";

    // resolver el caso posiblemente llamando a otras funciones

    // escribir la solución

    return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("ej2-3.txt");
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