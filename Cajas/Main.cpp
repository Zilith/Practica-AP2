#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <wchar.h>
#include "pila.h"
#include "ColaVec.h"

using namespace std;

void MenuPilas();
void MenuColas();
void MainMenu();


int main()
{
	int opcM = 0, opcP = 0, opcC = 0, dato = 0, n = 0, m = 0, ncola;
	//Instancia.

	cout << "Ingrese el tamano de las pilas" << endl;
	cin >> n;
	cout << "Ingrese el tamano de las colas" << endl;
	cin >> m;
	system("cls");
	pila* p1 = new pila(n);;
	pila* p2 = new pila(n);;
	pila* p3 = new pila(n);;
	cola* C1 = new cola(m);;
	cola* C2 = new cola(m);;
	cola* C3 = new cola(m);;
	do
	{
		MainMenu();
		cin >> opcM;
		system("cls");
		switch (opcM)
		{
		case 1: // Edit pilas
			do
			{
				MenuPilas();
				cin >> opcP;
				switch (opcP)
				{
				case 1:// Apilar.
					if (!p1->pilaLlena())
					{
						cout << "Ingrese un dato: ";
						cin >> dato;
						p1->apilar(dato);
					}
					else
					{
						cout << "La pila esta llena." << endl;

					}
					cin.get();
					break;
				case 2://Desapilar.
					if (!p1->pilaVacia())
					{
						cout << "Se desapilo el ultimo dato: " << p1->desapilar() << " endl";
					}
					else
					{
						cout << "La pila esta vacia." << endl;
					}
					cin.get();
					break;
				case 3: //Apilarordenado
					if (!p1->pilaLlena())
					{
						p1->apilarordenado(p1);
					}
					else
					{
						cout << "La pila está llena." << endl;
						cin.get();
					}

					break;
				case 4: //Ordenar
						p1->ordenarpila(p1);
						cin.get();
					break;
				case 5: // Mostrar pila.
					cout << "Mostrando pila: \n";
					p1->Imprimir();
					cin.get();
					break;
				case 6: //Salir
					cout << "Volviendo al menú anterior" << endl;
					cin.get();
					break;
				default:
					cout << "Se ingreso el numero erroneamente" << endl;
					break;
				}
				system("cls");
			} while (opcP != 6);
			break;
		case 2://Editar Colas
			cout << "Que cola desea editar?  (1 // 2)" << endl;
			cin >> ncola;
			switch (ncola)
			{
			case 1:
				C1 = C2;
					do
					{
						MenuColas();
						cin >> opcC;
						switch (opcC)
						{
						case 1: //Encolar
							if (!C1->ColaLlena())
							{
								cout << "\nIngrese numero a encolar: ";
								cin >> dato;
								C1->encolar(dato);
							}
							cin.get();
							break;
						case 2: //Desencolar
							if (C1->ColaVacia())
							{
								cout << "\nCola Vacia.";
							}
							else
							{
								cout << "\nDato desencolado --> " << C1->desencolar();
							}
							cin.get();
							break;
						case 3: //Encolar ordenado
							if (!C1->ColaLlena())
							{
								cout << "Ingrese el dato: " << endl;
								cin >> dato;
								C1->encolarordenado(dato, C1);

							}
							else
							{
								cout << "La cola esta llena." << endl;
								cin.get();
							}
							break;
						case 4: //Ordenar Cola
							C1->ordenarcola();
							break;
						case 5: //Mostrar cola
							if (!C1->ColaVacia())
							{
								cout << "\nMostrar Cola.\n";
								C1->Mostrar();
								cin.get();
								cin.get();
							}
							else
							{
								cout << "La cola está vacia" << endl;
							}
							break;
						case 6: //Salir
							cout << "Volviendo al menú anterior" << endl;
							cin.get();
							break;
						default:
							cout << "Se ingreso el numero erroneamente" << endl;
							cin.get();
							break;
						}
						C2 = C1;
						system("cls");
					} while (opcC != 6);
					system("cls");
					break;
			case 2:
				C1 = C3;
				do
				{
					MenuColas();
					cin >> opcC;
					switch (opcC)
					{
					case 1: //Encolar
						if (!C1->ColaLlena())
						{
							cout << "\nIngrese numero a encolar: ";
							cin >> dato;
							C1->encolar(dato);
						}
						cin.get();
						break;
					case 2: //Desencolar
						if (C1->ColaVacia())
						{
							cout << "\nCola Vacia.";
						}
						else
						{
							cout << "\nDato desencolado --> " << C1->desencolar();
						}
						cin.get();
						break;
					case 3: //Encolar ordenado
						break;
					case 4: //Ordenar Cola
						C1->ordenarcola();
						break;
					case 5: //Mostrar cola
						if (!C1->ColaVacia())
						{
							cout << "\nMostrar Cola.\n";
							C1->Mostrar();
							cin.get();
							cin.get();
						}
						else
						{
							cout << "La cola está vacia" << endl;
						}
						break;
					case 6: //Salir
						cout << "Volviendo al menú anterior" << endl;
						cin.get();
						break;
					default:
						cout << "Se ingreso el numero erroneamente" << endl;
						cin.get();
						break;
					}
					C3 = C1;
					system("cls");
				} while (opcC != 6);
				system("cls");
				break;
			default:
				cout << "Se ingreso el numero erroneamente" << endl;
				cin.get();
				break;
			}
			break;
		case 3: //Sumar pila mas cola
			C1->SumarPC(p1, C1);
			cout << "Se ha realizado la suma de manera correcta" << endl;
			cin.get();
			break;
		case 4: // Trenza
			if (!C2->ColaVacia() || !C3->ColaVacia())
			{
				C1->Trenza(C2, C3);
			}
			else
			{
				cout << "No hay datos para trenzar " << endl;
				cin.get();
			}
			break;
		case 5: //Salir
			cout << "Gracias por su uso" << endl;
			cin.get();
			break;
		default:
			cout << "Ha ingresado un dato incorrecto";
			break;
		}
	} while (opcM != 5);
	return 0;

}
void MenuPilas()
{
	cout << "\n \t Pilas\n\n";
	cout << "1. Apilar" << endl;
	cout << "2. Desapilar" << endl;
	cout << "3. Apilar Ordenado" << endl;
	cout << "4. Ordenar" << endl;
	cout << "5. Mostrar Pila" << endl;
	cout << "6. Salir" << endl;
	cout << "\t Que desea hacer?\n";
}

void MenuColas()
{
	cout << "\n \t Colas\n\n";
	cout << "1. Encolar" << endl;
	cout << "2. Desencolar" << endl;
	cout << "3. Encolar Ordenado" << endl;
	cout << "4. Ordenar Cola" << endl;
	cout << "5. Mostrar Cola" << endl;
	cout << "6. Salir. " << endl;
	cout << "\t Que desea hacer?\n";
}

void MainMenu()
{
	cout << "\n \tBienvenido a la practica de pilas y colas\n\t\t\t\t\t\t\t\t Creado por: Diego Alejandro Zapata Garcia & Maria Camila Hernandez Munoz\n\n ";
	cout << "1. Editar Pilas" << endl;
	cout << "2. Editar colas" << endl;
	cout << "3. Sumar una pila mas una cola" << endl;
	cout << "4. Trenza de vector a lista" << endl;
	cout << "5. Salir" << endl;
}