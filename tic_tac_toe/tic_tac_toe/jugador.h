
//Definicion del modulo que vamos a usar
#pragma once
#ifndef JUGADOR_H

//Bibliotecas que se usan en este archivo
#include <iostream>	//Encargada de entrada/salida de datos
#include <string> //Encargada de manipular cadenas de caracteres

//Modulos que se usan en este archivo
#include"cpu.h"	
#include"tablero.h"
//Permite que la salida y entrada de datos por pantalla sea la estandar
using namespace std;

//Declaracion de funciones
int menu(const tJuego& juego); //Muestra el menu y devuelve la opcion elegida por el jugador
void poner_nombre_jugador1(tJuego& juego); //Permite al usuario poner nombre al jugador 1
void poner_nombre_jugador2(tJuego& juego); //Permite al usuario poner nombre al jugador 2
bool coloca(tJuego& juego); //Intenta colocar una ficha al tablero e indica si se ha conseguido o no

//Finalizacion de la definicion del modulo
#endif // !JUGADOR_H

