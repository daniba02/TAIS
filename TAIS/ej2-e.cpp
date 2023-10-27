
/*@ <authors>
 *
 * Daniel Barroso Casado; TAIS06
 * Mario Campos Sobrino; TAIS09
 *
 *@ </authors> 

#include <iostream>
#include <fstream>
#include <queue>
#include <vector>
using namespace std;

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

typedef struct {
	int id;
	int e;
	float v;
	float c;
}tPartido;

bool operator<(tPartido const& a, tPartido const& b) {
	return (b.c > a.c) || (b.c == a.c && b.v > a.v) || (b.c == a.c && b.v == a.v && b.id < a.id);
}

bool resuelveCaso() {
	// leer los datos de la entrada
	int N, C;
	cin >> C >> N;

	if (C == 0 && N == 0)
		return false;

	vector<int> salida(C);
	priority_queue<tPartido> colaPartidos;

	for (int i = 0; i < C; i++) {
		float votos;
		cin >> votos;
		colaPartidos.push({ i, 0, votos, votos });
	}

	// resolver el caso posiblemente llamando a otras funciones
	while (N--) {
		auto partido = colaPartidos.top();
		colaPartidos.pop();
		partido.e++;
		partido.c = partido.v / (1 + partido.e);

		colaPartidos.push(partido);
		salida[partido.id] = partido.e;
	}
	// escribir la soluci�n
	for (int i = 0; i < C; i++) {
		cout << salida[i] << " ";
	}
	cout << endl;

	return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta l�nea ya no forma parte de la soluci�n.

int main() {
	// ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("ej2-e.txt");
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
