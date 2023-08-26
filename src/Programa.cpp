#include "Program.hpp"

bool CallBackCompare(Nodo *Ref, Nodo* node)
{
	Task *coderef = (Task *) Ref->item;
	Task *codenode = (Task *) node->item;

	return coderef->priority < codenode->priority;
}

Program::Program()
{
	program = new mc::List<Nodo>(CallBackCompare, 10);
}

Program::~Program()
{
	delete program;
}

void Program::AddTask(Task *task)
{
	Nodo *nodo= new Nodo;
	nodo->item = task;
        program->insertElement(nodo);
}

Task *Program::GetFirstTask()
{
	Task *task = NULL;
	Nodo *nodo = program->getBegin();

	if (nodo)
		task = (Task *) nodo->item;

	return task;
}

Task *Program::GetNextTask()
{
	if (CurrentTask == NULL)
		CurrentTask = program->getBegin();
	else
		CurrentTask = CurrentTask->proximo ? CurrentTask->proximo : program->getBegin();

	return (Task *) CurrentTask->item;
}

int Program::getSize()
{
	return program->getSize();
}


Program& Program::GetInstance()
{
	static Program self;
	return self;
}
