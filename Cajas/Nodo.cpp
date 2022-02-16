#include "Nodo.h"

Nodo::Nodo()
{
	Dato = 0;
	Liga = nullptr;
}
int Nodo::GetDato()
{
	return Dato;
}
void Nodo::SetDato(int d)
{
	Dato = d;
}

Nodo* Nodo::GetLiga()
{
	return Liga;
}

void Nodo::SetLiga(Nodo* l)
{
	Liga = l;
}

