
//Bibliotecas que se usan en este archivo
#include <iostream>	//Encargada de entrada/salida de datos
#include <string> //Encargada de manipular cadenas de caracteres
#include <stdlib.h>	//Encargada de guardar/usar los valores por defecto para algunas operaciones
#include <time.h>	//Encargada de usar funciones que usan el tiempo

//Modulos que se usan en este archivo
#include "cpu.h"
#include "jugador.h"
#include "tablero.h"

//Permite que la salida y entrada de datos por pantalla sea la estandar
using namespace std;

//Declaracion de funciones auxiliares (no son la funcion principal)
bool comprobar_win(const tJuego& juego, int turno);

//Definicion de la funcion principal
int main() {
	
	//Creamos e inicializamos las variables que usaremos
	tJuego juego;	//Estructura que guarda variables basicas del juego
	int opcion = -1;	//Numero entero que guarda la opcion que elige cada jugador en el menu
	bool salir = false;	//Variable logica que indica si se sale del juego
	bool ganar = false;	//Variable logica que indica si algun jugador ha ganado
	bool fin = false;	//Variable logica que indica si el tablero esta lleno
	inicializa(juego);	//Funcion que inicializa la estructura del juego
	srand(time(NULL));	//Esta funcion hace que los numeros aleatorios puedan variar y no dar el mismo todo el rato
	
	//BUCLE: Mientras la cantidad de jugadores no sea correcta
	while (juego.jugadores < 1 || juego.jugadores > 2) {	
		cout << "Indica el numero de jugadores en la partida: ";	//Mensaje que se muestra en pantalla
		cin >> juego.jugadores;	//Dato que se recoge del teclado
	}
	//CONDICIONALES
		//Condicion 1: Solo juega un jugador
	if (juego.jugadores == 1) {	
		juego.jugador2 = "CPU";		//Decimos que el jugador 2 es la CPU
		poner_nombre_jugador1(juego);	//Funcion que permite al usuario poner un nombre
		juego.turno = 0;	//Indicmos que el turno actual de juego es el jugador 1
	}
		//Condicion 2: Hay 2 jugadores
	else if (juego.jugadores == 2){	
		poner_nombre_jugador1(juego);	//Funcion que permite al jugador 1 poner un nombre
		poner_nombre_jugador2(juego);	//Funcion que permite al jugador 2 poner un nombre
		juego.turno = 0 + rand() % (1 + 1 - 0);	//Se decide el turno de manera aleatoria
	}

	//BUCLE: Mientras no se termine el juego de alguna forma
	while (!ganar && !fin && !salir) {	
		system("cls");	//Borra todo lo que aparezca en pantalla
		dibuja_tablero(juego);	//Dibuja el tablero
		
		//CONDICIONALES
			//Condicion 1: Es el turno del jugador 1
		if (juego.turno == 0) {
			cout << "Es turno de: " << juego.jugador1 << endl;	//Mostramos en pantalla que es su turno
			opcion = menu(juego);	//Averiguamos lo que quiere hacer el jugador
			//CONDICIONALES
				//Condicion 1: Colocar ficha
			if (opcion == 1) {
				if (coloca(juego)) { //Si se puede colocar la ficha
					ganar = comprobar_win(juego, juego.turno);	//Se comprueba si se gana
					fin = tablero_lleno(juego);	//Se comprueba si se ha llenado el tablero
					juego.turno = (juego.turno + 1) % 2;	//Se pasa al siguiente jugador
				}
				else {	//Si no se pueda colocar
					juego.turno = (juego.turno + 1) % 2;	//Se pasa al siguiente jugadore
				}
			}
				//Condicion 2: Salir del juego
			else {
				salir = true;	//Salimos
			}
		}
			//Condicion 2: Es el turno del jugador 2, pero es CPU
		else if (juego.turno == 1 && juego.jugadores == 1) {
			poner_ficha(juego);		//Pone una ficha de forma aleatoria
			ganar = comprobar_win(juego, juego.turno);	//Se comprueba si gana
			fin = tablero_lleno(juego);	//Se comprueba si se ha llenado el tablero
			juego.turno = (juego.turno + 1) % 2;	//Se pasa al siguiente jugador
		}
			//Condicion 3: Es el turno del jugador 2 y no es una CPU
		else if (juego.turno == 1 && juego.jugadores == 2) {
			cout << "Es turno de: " << juego.jugador2 << endl;	//Mostramos en pantalla que es su turno
			opcion = menu(juego);	//Averiguamos lo que quiere hacer el jugador
			//CONDICIONALES
				//Condicion 1: Colocar ficha
			if (opcion == 1) {
				if (coloca(juego)) { //Si se puede colocar la ficha
					ganar = comprobar_win(juego, juego.turno);	//Se comprueba si se gana
					fin = tablero_lleno(juego);	//Se comprueba si se ha llenado el tablero
					juego.turno = (juego.turno + 1) % 2;	//Se pasa al siguiente jugador
				}
				else {	//Si no se pueda colocar
					juego.turno = (juego.turno + 1) % 2;	//Se pasa al siguiente jugadore
				}
			}
			//Condicion 2: Salir del juego
			else {
				salir = true;	//Salimos
			}
		}

	}
	//CONDICIONALES SUELTOS
		//Condicion 1: Si se llena el tablero
	if (fin) {
		system("cls");	//Borra todo lo que aparezca en pantalla
		dibuja_tablero(juego);	//Dibuja el tablero
		cout << "EMPATE" << endl;	//Decimos por pantalla que no gana nadie
	}
		//Condicion 2: Si algun jugador ha ganado
	if (ganar) {
		system("cls");	//Borra todo lo que aparezca en pantalla
		dibuja_tablero(juego);	//Dibuja el tablero
		//CONDICIONAL
			//Condicion 1: Si el jugador 2 ha ganado, como el turno cambia despues de comprobar si se gana al colocar ficha
		if (juego.turno == 0) {
			cout << "HA GANADO: " << juego.jugador2 << endl;	//Decimos por pantalla que ha ganado
		}
			//Condicion 2: Si el jugador 1 ha ganado, como el turno cambia despues de comprobar si se gana al colocar ficha
		else {
			cout << "HA GANADO: " << juego.jugador1 << endl;	//Decimos por pantalla que ha ganado
		}
	}
		//Condicion 3: Si algun jugador decide salir del juego
	if (salir) {
		system("cls");	//Borra todo lo que aparezca en pantalla
		cout << "Has salido del juego" << endl;	//Decimos por pantalla que ha salido del juego
	}
	return 0;
}

//DEeinicion de funciones auxiliares
bool comprobar_win(const tJuego& juego, int turno) {
	//Iniciamos las variables
	bool ganar = false;	//Variable logica que indica si se ha ganado
	int fila = 0;	//Numero entero con las filas
	int col = 0;	//Numero entero con las columnas

	//BUCLE: Mientras no se haya ganado y queden filas
	while (fila < MAX && !ganar) {
		//CONDICIONAL SUELTO: Si las tras casillas de dicha fila tienen la ficha del jugador correspondiente
		if (juego.tablero[fila][0] == turno && juego.tablero[fila][1] == turno && juego.tablero[fila][2] == turno) {
			ganar = true;	//Se indica que se ha ganado
		}
		fila++;	//Pasamos a la siguiente fila
	}
	//BUCLE: Mientras no se haya ganado y queden columnas
	while (col < MAX && !ganar) {
		//CONDICIONAL SUELTO: Si las tras casillas de dicha columna tienen la ficha del jugador correspondiente
		if (juego.tablero[0][col] == turno && juego.tablero[1][col] == turno && juego.tablero[2][col] == turno) {
			ganar = true;	//Se indica que se ha ganado
		}
		col++;	//Pasamos a la siguiente columna
	}
	//CONDICIONAL SUELTO: Si no se ha gando y las fichas de la diagonal tienen la ficha del jugador correspondiente
		//Diagonal arriba-izquerda/abajo-derecha
	if (!ganar && (juego.tablero[1][1] == turno && juego.tablero[0][0] == turno && juego.tablero[2][2] == turno)) {
		ganar = true;	//Se indica que se ha gando
	}
	//CONDICIONAL SUELTO: Si no se ha gando y las fichas de la diagonal tienen la ficha del jugador correspondiente
		//Diagonal abajo-izquerda/arriba-derecha
	if	(!ganar && (juego.tablero[1][1] == turno && juego.tablero[0][2] == turno && juego.tablero[2][0] == turno)) {
		ganar = true;	//Se indica que se ha gando
	}
	return ganar;	//Devolvemos si se ha gando o no
}
