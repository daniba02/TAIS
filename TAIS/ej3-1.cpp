
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
using namespace std;
#include <vector>
#include <functional>
#include <queue>
#include <string>



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


struct tCliente {

    
    int tiempo;
    int caja;
};

bool operator<(tCliente const& a, tCliente const& b) {

    return b.tiempo < a.tiempo || (b.tiempo == a.tiempo && b.caja < a.caja);

}

bool resuelveCaso() {

    // leer los datos de la entrada

    int n, c;

    cin >> n >> c;

    if (n == 0 && c == 0)
        return false;



    priority_queue<tCliente> cola;

    for (int i = 0; i < n; i++) {
        cola.push({ 0, i + 1 });
    }


    for (int i = 0; i < c; i++) {

        int tiempo;
        cin >> tiempo;

        auto e = cola.top();
        cola.pop();
        tiempo += e.tiempo;

        cola.push({ tiempo, e.caja });
    }
        
    cout << cola.top().caja << "\n";


    // resolver el caso posiblemente llamando a otras funciones

    // escribir la soluci�n

    return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta l�nea ya no forma parte de la soluci�n.

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("ej2-5.txt");
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