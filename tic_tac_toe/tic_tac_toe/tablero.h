
//Definicion del modulo que vamos a usar
#pragma once
#ifndef TABLERO_H

//Bibliotecas que se usan en este archivo
#include <iostream>	//Encargada de entrada/salida de datos
#include <string> //Encargada de manipular cadenas de caracteres
#include <stdlib.h>	//Encargada de guardar/usar los valores por defecto para algunas operaciones

//Permite que la salida y entrada de datos por pantalla sea la estandar
using namespace std;

//Constantes
const int MAX = 3; //Entero que guarda el tamano maximo de de filas o columnas

//Estructuras
typedef struct {
	int tablero[MAX][MAX]; //Matriz con las casillas del tablero
	int jugadores;	//Entero con el numero de jugadores
	int turno;	//Entero con el turno del jugador actual
	string jugador1; //Cadena de caracters con el nombre del jugador 1
	string jugador2; //Cadena de caracters con el nombre del jugador 1
}tJuego; //Estructura correspondiente al juego

//Declaraciones de funciones
void inicializa(tJuego& juego);	//Se encarga de inicializar la estructura de juego
bool casilla_ocupada(const tJuego& juego, int fila, int columna);	//Indica si una casilla tiene una ficha o no
bool tablero_lleno(const tJuego& juego);	//Indica si el tablero esta lleno o no
void dibuja_ficha(int jugador);	//Dibuja la ficha correspondiente al jugador del que es la casilla
void dibuja_tablero(const tJuego& juego); //Dibuja el tablero completo

//Finalizacion de la definicion del modulo
#endif //!TABLERO_H

