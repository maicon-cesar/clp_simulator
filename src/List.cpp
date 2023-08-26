#include "List.hpp"

namespace mc {

template <class T>
List<T>::List(CallBackCompare callbackcompare, size_t maxsize)
{
	this->callbackcompare = callbackcompare;
	this->maxsize = maxsize;
	size = 0;
	begin = 0;
	end = 0;
}

template <class T>
List<T>::~List(void)
{
	T *tmp, *n = begin;

	while (n) {
		tmp = n;
		n = n->proximo;
		delete tmp;
	}
}

template <class T>
void List<T>::insertBegin(T *newT)
{
	if (empty())
		end = newT;
	else
		begin->anterior = newT;

	newT->proximo = begin;
	newT->anterior = 0;
	begin = newT;
	size++;
}

template <class T>
void List<T>::insertPrevious(T *n, T *newT)
{
	if (n == begin) {
		begin = newT;
		newT->anterior = 0;
	} else {
		n->anterior->proximo = newT;
		newT->anterior = n->anterior;
	}

	newT->proximo = n;
	n->anterior = newT;
	size++;
}

template <class T>
void List<T>::insertAfter(T *n, T *newT)
{
	if (n == end) {
		end = newT;
		newT->proximo = 0;
	} else {
		newT->proximo = n->proximo;
	}

	newT->anterior = n;
	n->proximo = newT;
	size++;
}

template <class T>
void List<T>::insertElement(T *newT)
{
	if (empty())
		insertBegin(newT);
	else
		insert(begin, newT);

	if (size > maxsize)
		eraseElement(end);
}

template <class T>
void List<T>::insert(T *TCompare, T *newT)
{
	if ((*callbackcompare)(TCompare, newT))
		insertPrevious(TCompare, newT); //stopping criterion
	else if (TCompare->proximo)
		insert(TCompare->proximo, newT);
	else
		insertAfter(TCompare, newT); //stopping criterion
}

template <class T>
void List<T>::eraseElement(T *n)
{
	if (n == begin) {
		if (n->proximo)
			n->proximo->anterior = 0;
		begin = n->proximo;
	} else {
		if (n->proximo)
			n->proximo->anterior = n->anterior;
		n->anterior->proximo = n->proximo;
	}

	size--;
	delete n;
}

template <class T>
bool List<T>::empty()
{
	return (!begin);
}

template class List<Nodo>;

} //namespace
