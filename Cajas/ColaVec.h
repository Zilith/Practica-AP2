#include "Nodo.h"
#include "pila.h"

#pragma once
class pila_lista;
class cola
{
private:
	//Atributos
	int tope, limite, *Vcola;
public:
	cola(int); //Constructor
	void encolar(int);
	int desencolar();
	void encolarordenado(int, cola*);
	void ordenarcola();
	bool ColaVacia();
	bool ColaLlena();
	int BuscarMenor(cola*, cola*);
	void llenarCola(cola *);
	void Mostrar();
	void invertircola();
	void SumarPC(pila*, cola*);
	void Trenza(cola*, cola*);
	int getlimite();



};

