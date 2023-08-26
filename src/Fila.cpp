#include "Fila.hpp"

//******************************************************************************
Fila::Fila()
{
	inicio = 0;
	fim = 0;
	isize = 0;
}

//******************************************************************************
Fila::~Fila()
{
	Nodo *nodo;

	while (inicio) {
		nodo = front();
		pop();
		delete nodo;
	}
}

//******************************************************************************
void Fila::push(Nodo *novo)
{
	novo->proximo = 0;

	if (empty()) {
		inicio = novo;
	} else {
		fim->proximo = novo;
	}
	fim = novo;
	isize++;
}

//******************************************************************************
void Fila::pop()
{
	//Nodo *nodo;

	if (inicio) {
		//nodo = inicio;
		inicio = inicio->proximo;
		//delete nodo;
		isize--;
	}
}

//******************************************************************************
bool Fila::empty()
{
	if (!inicio)
		return true;

	return false;
}

//******************************************************************************
int Fila::size()
{
	return isize;
}

//******************************************************************************
Nodo *Fila::front()
{
	return inicio;
}
