#pragma once
#ifndef CARTAS_H
#define CARTAS_H


//Inclusion de bibliotecas y modulos

#include<iostream>	//Entrada y salida de datos
#include<string>	//Manejo de cadenas de caracteres
#include<fstream>	//


//Definicion de constantes y estructuras para el juego

const int MAX_PALO = 4;	//Constante con el numero de palos en la baraja
const int MAX_NUM = 12;	//Constante con el total de cartas por palo

typedef struct {
	int cartas;			//Guarda el numero de cartas
	int mano[MAX_NUM];	//Vector con las cartas del jugador
}tJugador;

typedef struct {
	int jugadores;					//Guarda el numero de jugadores
	tJugador jugadores[MAX_PALO];	//Guarda la mano de los jugadores
	int baraja[MAX_PALO][MAX_NUM];	//Matriz que crea el tablero del juego
}tJuego;


//Declaracion de funciones

void blackjack(int opcion, tJuego& juego);		//Realiza la funcion que le ha pedido el jugador (pasar, robar, mostrar o salir)
void reset(tJuego& juego);						//Devuelve las cartas a la baraja
void resetJugador(tJugador& jugador);			//Vacia la mano del jugador
void robarCarta(int jugador, tJuego& juego);	//Hace que el jugador robe carta
void mostrarMano(tJugador jugador);				//Muestra una mano en pantalla
void mostrarPartida(const tJuego& juego);		//Muestra todas las manos y la baraja en pantalla
bool comprobarWin(tJugador jugador);			//Comprueba que jugador ha ganado el juego


//Finalizacion del modulo

#endif //!CARTAS_H

