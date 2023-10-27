
/*@ <answer>
 *
 * Nombre y Apellidos: Diego Flores Sim�n
 *
 *@ </answer> 

#include <iostream>
#include <fstream>
#include "bintree.h"
	using namespace std;

// propios o los de las estructuras de datos de clase
/**
 * Implementaci�n din�mica del TAD Arbol Binario con conteo manual de referencias
 * (c) Marco Antonio G�mez Mart�n, 2012
 * Modificado por Ignacio F�bregas, 2022
*/

/*@ <answer>

 Escribe aqu� un comentario general sobre la soluci�n, explicando c�mo
 se resuelve el problema y cu�l es el coste de la soluci�n, en funci�n
 del tama�o del problema.

 @ </answer> 


 // ================================================================
 // Escribe el c�digo completo de tu soluci�n aqu� debajo
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
	// escribir la soluci�n
	if (s) {
		cout << "SI";
	}
	else {
		cout << "NO";
	}
	cout << '\n';
}

//@ </answer>
//  Lo que se escriba dejado de esta l�nea ya no forma parte de la soluci�n.

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