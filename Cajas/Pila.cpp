#include "pila.h"
#include <iostream>

using namespace std;

pila::pila(int tam)
{
	limite = tam;
	tope = 0;
	Punta = nullptr;
};

void pila::apilar(int d)
{
	tope++;
	InsertarInicio(d);
}

int pila::desapilar()
{
	Nodo* p = Punta;
	int r = p->GetDato();
	Punta = Punta->GetLiga(); 
	tope--;
	delete(p);
	return r;
}

void pila::apilarordenado(pila* a)
{

	int d;
	cout << "Inserte el dato: ";
	cin >> d;
	tope++;
	InsertarInicio(d);
	ordenarpila(a);
	cout << "Se ha ingresado el dato correctamente" << endl;
	cin.get();
}

void pila::ordenarpila(pila* a) //no esta vacia
{
	pila* aux = new pila(limite);
	pila* aux2 = new pila(limite);
	
	bool sw = 1;
	if (GetTope() > 1)
	{

		apilar(BuscarMenor(a, aux)); //El menor se apila

		while (!aux->pilaVacia() || !aux2->pilaVacia())
		{
			if (sw == 1)
			{
				apilar(BuscarMenor(aux, aux2));
				sw = 0;
			}
			else
			{
				apilar(BuscarMenor(aux2, aux));
				sw = 1;
			}
		}
		cout << "La pila se ha ordenado correctamente";
		cin.get();
	}
	else
	{
		cout << "Solo hay un dato en la pila";
	}

}

bool pila::pilaVacia()
{
	bool r = false;
	if (tope == 0)
	{
		r = true;
	}
	return r;
}

bool pila::pilaLlena()
{
	if (tope == limite)
		return true;
	else
		return false;
}

int pila::BuscarMenor(pila* b, pila* aux)
{
	int v;

	v = b->desapilar();
	while (!b->pilaVacia())
	{
		if (v > b->Punta->GetDato())
		{
			aux->apilar(v);
			v = b->desapilar();
		}
		else
		{
			aux->apilar(b->desapilar());
		}
	}
	return v;
}

void pila::llenarPila(pila* a)
{
	while (!a->pilaVacia())
	{
		apilar(a->desapilar());
	}
}

void pila::InsertarInicio(int d)
{
	Nodo* x = new Nodo();

	x->SetDato(d);

	if (Punta == nullptr)
	{
		Punta = x;
	}
	else
	{
		x->SetLiga(Punta);
		Punta = x;
	}

}

void pila::Imprimir()
{
	pila* aux = new pila(limite);
	int r;
	cout << "Los datos son:" << endl;
	while (!pilaVacia())
	{
		r = desapilar();
		cout << "|" << r << "|\n";
		aux->apilar(r);
	}
	llenarPila(aux);
	cin.get();
}

int pila::getlimite()
{
	return limite;
}

int pila::GetTope()
{
	return tope;
}
