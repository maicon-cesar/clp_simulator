#ifndef TELA_CREDITOS_HPP
#define TELA_CREDTTOS_HPP

#include "BaseMenu.hpp"

class Tela_Creditos: public BaseMenu
{
public:
	Tela_Creditos();

private:
	void EventCallback(int id);
};

#endif // TELA_CREDITOS_HPP

