
//Encabezado del modulo al que pertenece
#include "cpu.h"
//Permite que la salida y entrada de datos por pantalla sea la estandar
using namespace std;

//Definicion de funciones
bool poner_ficha(tJuego& juego) {
	//Inicializamos valriables
	int fila = -1; //Entero con la fila
	int columna = -1; //Entero con la columna
	bool colocada = false; //Variable logica que indica si se puede colocar la ficha o no
	srand(time(NULL));	//Esta funcion hace que los numeros aleatorios puedan variar y no dar el mismo todo el rato
	
	//BUCLE: Mientras la fila o columna sea incorrecta o si no se ha colocado
	while ((fila < 0 || fila > 2) || (columna < 0||columna > 2)||!colocada) {
		fila = 0 + rand() % (2 + 1 - 0); //Elegimos una fila al azar
		columna = 0 + rand() % (2 + 1 - 0); //Elegimos una columna al azar
		//CONDICIONAL SUELTO: Si la casilla esta libre
		if (!casilla_ocupada(juego, fila, columna)) {
			colocada = true;	//Indicamos que se puede colocar la ficha
		}
	}
	//CONDICIONAL SUELTO: Si se puede colocar la ficha
	if (colocada) {
		juego.tablero[fila][columna] = 1;	//Se coloca en la casilla que se ha elegido al azar
	}
	return colocada;	//Se devuelve si se ha colocado o no
}
