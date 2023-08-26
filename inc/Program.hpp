#ifndef PROGRAM_HPP_INCLUDED
#define PROGRAM_HPP_INCLUDED

#include "List.hpp"
#include "Task.hpp"

class Program
{
public:
	void AddTask(Task *task);
	Task *GetFirstTask();
	Task *GetNextTask();
	int getSize();
	static Program& GetInstance();
private:
	Nodo *CurrentTask;
	Program();
	~Program();
	mc::List<Nodo> *program;
};

#endif // PROGRAM_HPP_INCLUDED
