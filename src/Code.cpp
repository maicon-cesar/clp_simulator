#include "Code.hpp"

void Code::AddCommand(Command *cmd)
{
	Nodo *nodo= new Nodo;
	nodo->item = cmd;
        commands.push(nodo);
}

Command * Code::GetNextCmd()
{
	Command *cmd = NULL;
	Nodo *nodo  = commands.front();

	if (nodo) {
		commands.pop();
		cmd = (Command *)nodo->item;
		commands.push(nodo);
	}

	return cmd;
}

int Code::getSize()
{
	return commands.size();
}
