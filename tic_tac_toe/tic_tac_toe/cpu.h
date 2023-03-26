
//Definicion del modulo que vamos a usar
#pragma once
#ifndef CPU_H

//Bibliotecas que se usan en este archivo
#include <stdlib.h>	//Encargada de guardar/usar los valores por defecto para algunas operaciones
#include <time.h>	//Encargada de usar funciones que usan el tiempo

//Modulos que se usan en este archivo
#include"tablero.h"

//Permite que la salida y entrada de datos por pantalla sea la estandar
using namespace std;

//Declaracion de funciones
bool poner_ficha(tJuego& juego);

//Finalizacion de la definicion del modulo
#endif // !CPU_H
