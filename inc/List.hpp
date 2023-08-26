#ifndef LIST_H_
#define LIST_H_

#include <iostream>
#include <fstream>
#include "Nodo.hpp"

namespace mc {

template <class T>
class List
{
public:
	typedef bool (*CallBackCompare)(T *Ref, T *node);
	List(CallBackCompare callbackcompare, size_t maxsize);
	~List(void);

	void insertBegin(T *newNode);
	void insertPrevious(T *n, T *newNode);
	void insertAfter(T *n, T *newNode);
	void insertElement(T *newNode);
	void eraseElement(T *n);
	bool empty();
	T *getBegin() { return begin; }
	T *getEnd() { return end; }
	size_t getSize() { return size; }
private:
	void insert(T *iniBusca, T *newNode);
	CallBackCompare callbackcompare;
	T *begin;
	T *end;
	size_t size;
	size_t maxsize;
};

} //namespace

#endif
