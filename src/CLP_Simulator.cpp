#include "CLP_Simulator.hpp"

void debug(std::string message)
{
	std::cout << message << std::endl;
	std::cout.flush();
}

void debug(std::string message, int var)
{
	std::cout << message << ' ' << var << std::endl;
	std::cout.flush();
}


CLP_Simulator::CLP_Simulator()
{
}

bool CLP_Simulator::Init()
{
	running_ = true;
	return true;
}

CLP_Simulator::~CLP_Simulator()
{
}

bool CLP_Simulator::Run()
{
	Program& program = Program::GetInstance();

	for (int i=0; i < program.getSize(); i++)
		RunTask(program.GetNextTask());

	return running_;
}


int CLP_Simulator::RunTask(Task *task)
{
	Application& app = Application::GetInstance();
	Commands kwords;
	Command *cmd;
	Code *code = task->code;

	switch (task->state) {
	case TASK_RUNNING:
		cmd = code->GetNextCmd();

		if (cmd == NULL) {
			running_ = false;
			task->state = TASK_IDLE;
		} else {
			//kwords.ShowCmd(cmd);

			switch (kwords.getKeyWordId(cmd->keyword)) {
			case Commands::CMD_DESLIGA:
				app.setStateLed(cmd->number, 0);
				break;
			case Commands::CMD_LIGA:
				app.setStateLed(cmd->number, 1);
				break;
			case Commands::CMD_MOSTRA:
				app.setDisplay(cmd->number, cmd->text);
				break;
			case Commands::CMD_PAUSA:
				task->time.restart();
				task->timeout =  sf::milliseconds((cmd->number+1)*1000);
				task->state = TASK_PAUSE;
				break;
			case Commands::CMD_SEL:
				if (!app.getStateButton(cmd->number)) {
					code->GetNextCmd();
					//kwords.ShowCmd(cmd);
				}
				break;
			case Commands::CMD_SED:
				if (app.getStateButton(cmd->number)) {
					code->GetNextCmd();
					//kwords.ShowCmd(cmd);
				}
				break;
			case Commands::CMD_FIM:
				task->state = TASK_IDLE;
				break;
			default:
				break;
			}

			//if (!code->getSize())
			//	std::cout << "\nPronto!\n";
		}
		break;
	case TASK_PAUSE:
		if (task->time.getElapsedTime().asMilliseconds() > task->timeout.asMilliseconds())
			task->state = TASK_RUNNING;
		break;
	case TASK_IDLE:
		break;
	default:
		break;
	}

	return task->state;
}

CLP_Simulator& CLP_Simulator::GetInstance()
{
	static CLP_Simulator self;
	return self;
}

void CLP_Simulator::Fini()
{
	running_ = false;
}
