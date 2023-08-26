#ifndef PILHA_HPP_INCLUDED
#define PILHA_HPP_INCLUDED

#include "Nodo.hpp"

class Pilha
{
public:
	Pilha(int size);
	void push(Nodo *novo);
	void pop();
	bool isEmpty();
	int getSize();
	Nodo *top();
private:
	int Size(Nodo *nodo, int &conta);
	Nodo *topo;
	int TamanhoMaximo;
};

#endif // PILHA_HPP_INCLUDED
