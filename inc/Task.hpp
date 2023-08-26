#ifndef TASK_HPP_INCLUDED
#define TASK_HPP_INCLUDED

#include "Code.hpp"
#include <SFML/System/Clock.hpp>

enum eTASK { TASK_IDLE, TASK_RUNNING, TASK_PAUSE };

struct Task
{
	int state;
	int priority;
	Code *code;
	sf::Clock time;
	sf::Time timeout;
};

#endif // TASK_HPP_INCLUDED
