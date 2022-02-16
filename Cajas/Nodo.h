#pragma once
class Nodo
{
	//Stributos
private:
	int Dato;
	Nodo* Liga;
	//Metodos
public:
	Nodo();
	int GetDato();
	void SetDato(int);
	Nodo* GetLiga();
	void SetLiga(Nodo*);

};

