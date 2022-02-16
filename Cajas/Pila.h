#pragma once
#include "Nodo.h"
class pila
{
private:
	//Atributos.
	Nodo* Punta;
	int limite, tope;

	//Metodos.
public:
	pila(int); //Constructor
	void apilar(int);//Set.
	int desapilar(); //Get.
	void apilarordenado(pila*);
	void ordenarpila(pila*);
	bool pilaVacia();
	bool pilaLlena();
	int BuscarMenor(pila*, pila*);
	void llenarPila(pila*);
	void InsertarInicio(int);
	void Imprimir();
	int getlimite();
	int GetTope();

};