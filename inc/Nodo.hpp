#ifndef NODO_HPP_INCLUDED
#define NODO_HPP_INCLUDED

struct Nodo {
	void *item;
	Nodo *anterior;
	Nodo *proximo;
};

#endif // NODO_HPP_INCLUDED
