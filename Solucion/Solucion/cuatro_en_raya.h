//Definicion y creacion del modulo

#pragma once
#ifndef CUATRO_H
#define CUATRO_H

//Inclusion de bibliotecas y modulos

#include<iostream>	//Entrada y salida de datos
#include<string>	//Manejo de cadenas de caracteres
#include<fstream>	//


//Definicion de constantes y estructuras para el juego

const int MAX_F = 6;	//Constante con el numero de filas del tablero
const int MAX_C = 7;	//Constante con el numero de columnas del juego

const char J1 = 'a';	//Constante con el color de las fichas del jugador 1
const char J2 = 'r';	//Constante con el color de las fichas del jugador 2

typedef struct {
	int jugadores;				//Guarda el numero de jugadores en partida
	char tablero[MAX_F][MAX_C];	//Matriz que crea el tablero del juego
	bool lleno[MAX_C];			//Indica si una columna esta llena
}tJuego;


//Declaracion de funciones

void cuatro_en_raya(int opcion, const tJuego& juego);		//Realiza la funcion que le ha pedido el jugador (jugar,mostrar o salir)
void ponerFicha(int jugador, const tJuego& juego);			//Hace que el jugador que tiene el turno coloque ficha
void mostrarFicha(int fila, int columna);					//Muestra la ficha en pantalla
void mostrarTablero(const tJuego& juego);					//Muestra el tablero completo en pantalla
void comportamientoCPU(const tJuego& juego);				//Hace que la CPU coloque ficha
bool comprobarVertical(const tJuego& juego, int jugador);	//Indica si hay 4 fichas iguales en vertical
bool comprobarHorizontal(const tJuego& juego);				//Indica si hay 4 fichas iguales en horizontal
bool comprobarDiagonal1(const tJuego& juego);				//Indica si hay 4 fichas iguales en diagonal(arriba-izquierda)
bool comprobarDiagonal2(const tJuego& juego);				//Indica si hay 4 fichas iguales en diagonal(arriba-derecha)
bool comprobarDiagonal3(const tJuego& juego);				//Indica si hay 4 fichas iguales en diagonal(abajo-izquierda)
bool comprobarDiagonal4(const tJuego& juego);				//Indica si hay 4 fichas iguales en diagonal(abajo-derecha)
bool comprobarWin(const tJuego& juego, int& jugador);		//Comprueba que jugador ha ganado el juego


//Finalizacion del modulo

#endif //!CUATRO_H