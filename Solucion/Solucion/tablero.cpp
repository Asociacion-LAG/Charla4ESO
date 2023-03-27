
//Encabezado del modulo al que pertenece
#include "tablero.h"

//Permite que la salida y entrada de datos por pantalla sea la estandar
using namespace std;

//Definicion de funciones
void inicializa(tJuego& juego) {
	juego.jugadores = 0;	//Inicializamos la variable de jugadores
	
	//RECORRIDO: Para todas las filas
	for (int i = 0; i < MAX; i++) {
		//RECORRIDO: Para tadas las columnas
		for (int j = 0; j < MAX; j++) {
			juego.tablero[i][j] = 2;	//Inicializamos la casilla correspondiente
		}
	}
}

bool casilla_ocupada(const tJuego& juego, int fila, int columna) {
	//CONDICIONAL SUELTO: Si la casilla correspondiente tiene una ficha de cualquier jugador
	if (juego.tablero[fila][columna] == 1 || juego.tablero[fila][columna] == 0) {
		return true;	//Devolvemos que esta ocupada
	}
	return false;	//Devolvemos que no esta ocupada
}

bool tablero_lleno(const tJuego& juego) {
	//Icicializamos las variables
	int fila = 0;	//Entero con las filas
	int columna = 0;	//Entero con las columnas
	bool lleno = true;	//Variable logica que indica si el tablero esta lleno
	//BUCLE: Mientras esta lleno y quedan filas por analizar
	while (lleno && fila < MAX) {
		//BUCLE: Mientras esta lleno y quedan columnas
		while (lleno && columna < MAX) {
			//CONDICIONAL SUELTO: SI la casilla correspondiente esta libre
			if (!casilla_ocupada(juego, fila, columna)) {
				lleno = false;	//Indicamos que el tablero esta libre
			}
			columna++;	//Pasamos a la siguiente columna
		}
		fila++;	//Pasamos a la siguiente fila
		columna = 0; //Reiniciamos las columnas
	}
	return lleno;	//Devolvemos si esta lleno o no
}

void dibuja_ficha(int ficha) {
	if (ficha == 0) {
		cout << " X ";
	}
	else if (ficha == 1) {
		cout << " 0 ";
	}
	else {
		cout << "   ";
	}
}

void dibuja_tablero(const tJuego& juego) {
	cout << "-------------" << endl; //Ponemos el borde superior
	//RECORRIDO: Para todas las filas
	for (int i = 0; i < MAX; i++) {
		cout << "|"; //Ponemos el borde izquierdo
		//RECORRIDO: Para todas las columnas
		for (int j = 0; j < MAX; j++) {
			dibuja_ficha(juego.tablero[i][j]);	//Dibujamos el contenido de la casilla
			cout << "|";	//Ponemos el borde de despues de la casilla
		}
		cout << endl;	//Pasamos a la siguiente fila para que no se acumule todo en la misma fila
		cout << "-------------" << endl; //Ponemos el borde de debajo de cada fila
	}
}
