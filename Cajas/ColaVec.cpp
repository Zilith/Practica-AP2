#include "ColaVec.h"
#include "Nodo.h"
#include <iostream>

using namespace std;

cola::cola(int tam)
{
    limite = tam - 1;
    tope = -1;
    Vcola = new int[tam];
}

void cola::encolar(int d)
{
    tope++;
    Vcola[tope] = d;
}

int cola::desencolar()
{
    int r = Vcola[0], i = 1;
    while (i <= tope)
    {
        Vcola[i - 1] = Vcola[i];
        i++;
    }
    tope--;
    return r;
}

void cola::encolarordenado(int d, cola* c)
{
    cola* aux = new cola(limite);
    int r = 0;
    if (ColaVacia())
        encolar(d);
    else
    {
        r = Vcola[0];
        if (d <= r)
        {
            aux->encolar(d);
            while (!ColaVacia())
                aux->encolar(desencolar());
            llenarCola(aux);
        }
        else
        {
            while (d > r && !ColaVacia())
            {
                aux->encolar(desencolar());
                r = Vcola[0];
            }
            aux->encolar(d);
            aux->llenarCola(c);
            llenarCola(aux);
        }
    }
};

void cola::ordenarcola()
{
    int v;
    cola* c1 = new cola(limite);
    cola* c2 = new cola(limite);

    if (tope > 0)
    {
        v = desencolar();
        while (!ColaVacia())
        {
            if (v < Vcola[0])
                c1->encolar(desencolar());
            else
            {
                c1->encolar(v);
                v = desencolar();
            }
        }
        encolar(v); //el menor se apila.
        v = c1->desencolar();
        c1->invertircola();
        while (!c1->ColaVacia())
        {
            if (v < c1->Vcola[0])
            {
                c2->encolar(v);
                v = c1->desencolar();
            }
            else
            {
                c2->encolar(c1->desencolar());
            }
        }
        c1->encolar(v);
        llenarCola(c2);
        llenarCola(c1);
        cout << "La Cola se ha ordenado correctamente." << endl;
    }
    else
    {
        cout << "La Cola solo tiene un dato" << endl;
    }
};

bool cola::ColaLlena()
{
    if (tope == limite)
        return true;
    else
        return false;
}

bool cola::ColaVacia()
{
    if (tope == -1)
        return true;
    else
        return false;
}

void cola::llenarCola(cola* a)
{
    while (a->ColaVacia() == false)
        encolar(a->desencolar());
}

void cola::SumarPC(pila* p, cola* c)
{
    cola* aux;
    int r = 0, s = 0, t = 0;
    if (p->getlimite() > c->getlimite())
    {
        aux = new cola(c->getlimite() + p->getlimite());
        while (!p->pilaVacia())
        {
            if (!c->ColaVacia() && !p->pilaVacia())
            {
                r = c->desencolar();
                s = p->desapilar();
                t = r + s;
                aux->encolar(t);
            }
            else
            {
                s = p->desapilar();
                aux->encolar(s);
            }
        }
    }
    else
    {
        aux = new cola(c->getlimite() + p->getlimite());
        while (!c->ColaVacia())
        {
            if (!c->ColaVacia() && !p->pilaVacia())
            {
                r = c->desencolar();
                s = p->desapilar();
                t = r + s;
                aux->encolar(t);
            }
            else
            {
                r = c->desencolar();
                aux->encolar(r);
            }
        }
    }
    aux->Mostrar();
}

void cola::Trenza(cola* c, cola* aux)
{
    pila* p = new pila(c->getlimite());

    if (!p->pilaLlena())
    {
        while (!c->ColaVacia() || !aux->ColaVacia())
        {
            if (!c->ColaVacia() && !aux->ColaVacia())
            {
                p->apilar(c->desencolar());
                p->apilar(aux->desencolar());
            }
            else
            {
                if (c->ColaVacia())
                    p->apilar(aux->desencolar());
                else
                {
                     p->apilar(c->desencolar());
                }
            }
        }
        if (!p->pilaVacia())
        {
            p->Imprimir();
        }
        else
        {
            cout << "No hay datos en la pila resultante." << endl;
            cin.get();
        }
    }
    else
    {
        cout << "La pila esta llena." << endl;
        cin.get();
    }
}

void cola::invertircola()
{
    cola* aux1 = new cola(limite);
    cola* aux2 = new cola(limite);
    int r = 0;

    while (!ColaVacia())
    {
        r = desencolar();
        aux1->encolar(r);
    }
    aux2->llenarCola(aux1);
    llenarCola(aux2);
}
void cola::Mostrar()
{
    int r = 0;
    cola* Ca = new cola(limite + 1);
    while (!ColaVacia())
    {
        r = desencolar();
        cout << " |" << r << "|";
        Ca->encolar(r);
    }
    llenarCola(Ca);
}
int cola::getlimite()
{
    return limite;
};