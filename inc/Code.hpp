#ifndef CODE_HPP_INCLUDED
#define CODE_HPP_INCLUDED

#include <iostream>
#include <string>
#include "Fila.hpp"
#include "Command.hpp"

class Code
{
public:
	void AddCommand(Command *cmd);
	Command * GetNextCmd();
	int getSize();
private:
	Fila commands;
};

#endif // CODE_HPP_INCLUDED
