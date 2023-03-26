
//Encabezado del modulo al que pertenece
#include"jugador.h"

//Permite que la salida y entrada de datos por pantalla sea la estandar
using namespace std;

//Definicion de funciones
int menu(const tJuego& juego) {
	//Inicializamos variables
	int opcion = -1;	//Entero que guarda la opcion elegida
	//BUCLE: Mientras la opcion es incorrecta
	while (opcion < 0 || opcion > 1) {
		cout << "\t\tMENU" << endl;	//Mostramos el menu
		cout << "1. Colocar ficha" << endl;	//Mostramos la opcion de colocar ficha
		cout << "0. Salir" << endl;	//Mostramos la opcion de salir del juego
		cin >> opcion;	//Guardamos el dato en pantalla con la opcion que elige el jugador
		//CONDICIONAL SUELTO: Si la opcion escogida no es correcta
		if (opcion < 0 || opcion > 1) {	
			cout << "Opcion Incorrecta"<<endl;	//Decimos que es incorrecta
		}
	}
	return opcion;	//Devolvemos la opcion del usuario
}

void poner_nombre_jugador1(tJuego& juego) {
	//BUCLE: Mientras que el nombre este vacio
	while (juego.jugador1.empty()) {
		cout << "Introduce tu nombre: ";	//Mostramos en pantalla que el jugador escriba el nombre
		cin >> juego.jugador1;	//Guardamos lo que se diga en pantalla
	}
}

void poner_nombre_jugador2(tJuego& juego) {

}

bool coloca(tJuego& juego) {
	//Inicializamos variables
	int fila = -1;	//Entero con la fila
	int columna = -1; //Entero con la columna
	bool colocada = false; //Variable logica que indica si se ha colocado o no la ficha

	//BUCLE: Mientras que la fila o columna sea incorrecta o la casilla este llena
	while ((fila < 0 || fila>2) || (columna < 0 || columna>2) || casilla_ocupada(juego, fila, columna)) {
		cout << "Introduce una fila (del 0 al 2): "; //Indicamos que el jugador elija una fila
		cin >> fila;	//Guardamos la fila
		cout << endl << "Introduce una columna(del 0 al 2): "; //Indicamos que el jugador elija una columna
		cin >> columna; //Guardamos la columna
		//CONDICIONAL SUELTO: La casilla ya esta ocupada
		if (casilla_ocupada(juego, fila, columna)) {
			cout << "CASILLA OCUPADA" << endl;	//Indicamos lo esta
		}
	}
	//CONDICIONAL SUELTO: La casilla esta libre
	if (!casilla_ocupada(juego, fila, columna)) {
		//CONDICIONAL
			//Condicion 1: Si el turno es del jugador 1
		if (juego.turno == 0) {
			juego.tablero[fila][columna] = 0;	//Indicamos que la ficha es de dicho jugador
		}
			//Condicion 2: Si el turno es del jugador 2
		else {
			juego.tablero[fila][columna] = 1;	//Indicamos que la ficha es de dicho jugador
		}
		colocada = true;	//Indicamos que se ha colocado
	}
	return colocada;	//Devolver si se ha colocado o no
}
