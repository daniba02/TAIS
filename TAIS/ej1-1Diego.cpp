
/*@ <answer>
 *
 * Nombre y Apellidos: Diego Flores Simón
 *
 *@ </answer> 

#include <iostream>
#include <fstream>
#include "bintree.h"
	using namespace std;

// propios o los de las estructuras de datos de clase
/**
 * Implementación dinámica del TAD Arbol Binario con conteo manual de referencias
 * (c) Marco Antonio Gómez Martín, 2012
 * Modificado por Ignacio Fábregas, 2022
*/

/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer> 


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>


struct sol {
	bool avl;
	int altura, min, max;
};

sol treeAvlRec(const BinTree<int>& t) {
	if (t.empty()) {
		return { true, 0, -1, -1 };
	}
	else {
		sol izq = treeAvlRec(t.left());
		sol der = treeAvlRec(t.right());

		bool avl = izq.avl && der.avl;
		avl = avl && (izq.max == -1 || izq.max < t.root()) && (der.min == -1 || der.min > t.root());
		avl = avl && abs(izq.altura - der.altura) <= 1;

		int mx, mn;
		if (t.right().empty()) {
			mx = t.root();
		}
		else {
			mx = der.max;
		}

		if (t.left().empty()) {
			mn = t.root();
		}
		else {
			mn = izq.max;
		}

		return { avl, max(izq.altura, der.altura) + 1, mn, mx };
	}
}

bool treeAvl(const BinTree<int>& t) {
	return treeAvlRec(t).avl;
}

void resuelveCaso() {
	int x;
	// leer los datos de la entrada
	//cin >> x;
	BinTree<int> tree = read_tree<int>(cin);
	// resolver el caso posiblemente llamando a otras funciones
	bool s = treeAvl(tree);
	// escribir la solución
	if (s) {
		cout << "SI";
	}
	else {
		cout << "NO";
	}
	cout << '\n';
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

int main() {
	// ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	int numCasos;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; ++i)
		resuelveCaso();

	// para dejar todo como estaba al principio
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}
*/