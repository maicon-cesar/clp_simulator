#ifndef COMMAND_HPP_INCLUDED
#define COMMAND_HPP_INCLUDED

#include <iostream>
#include <map>

struct Command {
	std::string keyword;
	int number;
	std::string text;
};

class Commands {
public:
	Commands();
	void ShowCmd(Command *cmd);
	int getKeyWordId(std::string key) { return keywords[key]; }
	enum eKEYWORDS { CMD_TAREFA, CMD_LIGA, CMD_DESLIGA, CMD_MOSTRA, CMD_PAUSA, CMD_SEL, CMD_SED, CMD_FIM, CMD_LEN};

	static const int COMMANDS_SIZE;
	static const std::string  InstructionList[];

private:
	std::map<std::string,int> keywords;
};

#endif // COMMAND_HPP_INCLUDED
