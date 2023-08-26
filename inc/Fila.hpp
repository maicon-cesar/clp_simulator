#ifndef FILA_HPP_INCLUDED
#define FILA_HPP_INCLUDED

#include "Nodo.hpp"

class Fila
{
public:
	Fila();
	~Fila();
	void push(Nodo *novo);
	void pop();
	Nodo *front();
	bool empty();
	int size();
	Nodo *top();
private:
	Nodo *inicio, *fim;
	int isize;
};

#endif // FILA_HPP_INCLUDED
