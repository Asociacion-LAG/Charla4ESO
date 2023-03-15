//Definicion y creacion del modulo

#pragma once
#ifndef TIC_TAC_TOE_H
#define TIC_TAC_TOE_H


//Inclusion de bibliotecas y modulos

#include<iostream>	//Entrada y salida de datos
#include<string>	//Manejo de cadenas de caracteres
#include<fstream>	//


//Definicion de constantes y estructuras para el juego

const int MAX = 3;		//Constante con el tamaño del tablero

const char J1 = 'X';	//Constante con el simbolo del jugador 1
const char J2 = '0';	//Constante con el simbolo del jugador 2

typedef struct {
	int jugadores;			//Guarda el numero de jugadores
	char tablero[MAX][MAX];	//Matriz que crea el tablero del juego
}tJuego;


//Declaracion de funciones

void ponerFicha(int jugador, const tJuego& juego);	//Hace que el jugador que tiene el turno coloque ficha
void mostrarFicha(int fila, int columna);	//Muestra la ficha en pantalla
void mostrarTablero(const tJuego& juego);	//Muestra el tablero completo en pantalla
void comportamientoCPU(const tJuego& juego);	//Hace que la CPU coloque ficha
bool comprobarWin(const tJuego& juego,int& jugador);	//Comprueba que jugador ha ganado el juego


//Finalizacion del modulo

#endif //!TIC_TAC_TOE_H
