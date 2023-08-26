#include "Pilha.hpp"

//***********************************************************
Pilha::Pilha(int size)
{
	topo = 0;
	TamanhoMaximo = size;
}

//***********************************************************
void Pilha::push(Nodo *novo)
{
	if (getSize() == TamanhoMaximo)
		return;
	novo->anterior = topo;
	topo = novo;
}

//***********************************************************
void Pilha::pop()
{
	if (topo)
		topo = topo->anterior;
}

//***********************************************************
bool Pilha::isEmpty()
{
	return  topo ? false : true;
}

//***********************************************************
int Pilha::Size(Nodo *nodo, int &conta)
{
	if (!nodo->anterior)
		return conta;
	else
		return Size(nodo->anterior, ++conta);
}

//***********************************************************
int Pilha::getSize()
{
	int conta = 1;

	if (isEmpty())
		return 0;

	return Size(topo, conta);
}

//***********************************************************
Nodo *Pilha::top()
{
	return topo;
}



