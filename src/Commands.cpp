#include "Command.hpp"

const std::string Commands::InstructionList[] = { "TAREFA", "LIGA", "DESLIGA", "MOSTRA", "PAUSA", "SEL", "SED", "FIM" };
const int Commands::COMMANDS_SIZE = CMD_LEN;

Commands::Commands()
{
	for (int i=0; i < COMMANDS_SIZE; i++)
		keywords.insert(std::pair<std::string, int>(InstructionList[i], i));
}

void Commands::ShowCmd(Command *cmd)
{
	std::cout << cmd->keyword << ' ' << cmd->number+1 << std::endl;
}
