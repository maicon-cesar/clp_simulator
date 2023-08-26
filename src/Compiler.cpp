#include "Compiler.hpp"

const std::string Compiler::SourceName = "Commands.clp";

Compiler::Compiler()
{
}

bool Compiler::Init()
{
	running_ = true;
	file.open(SourceName.c_str());
	return file.is_open();
}

Compiler::~Compiler()
{
	file.close();
}

bool Compiler::Run()
{
	return MakeProgram();
}

Compiler& Compiler::GetInstance()
{
	static Compiler self;
	return self;
}

void Compiler::Fini()
{
	running_ = false;
}

/*
bool Compiler::MakeProgram()
{
	Program& program = Program::GetInstance();
        Command *cmd;
	Task *task;


	task = new Task;
	task->state =TASK_RUNNING;
	task->priority = 27;
	task->code = new Code;

	cmd = new Command;
	cmd->keyword = "LIGA";
	cmd->number = 0;
	task->code->AddCommand(cmd);

	cmd = new Command;
	cmd->keyword = "PAUSA";
	cmd->number = 0;
	task->code->AddCommand(cmd);

	cmd = new Command;
	cmd->keyword = "DESLIGA";
	cmd->number = 0;
	task->code->AddCommand(cmd);

	cmd = new Command;
	cmd->keyword = "PAUSA";
	cmd->number = 0;
	task->code->AddCommand(cmd);

	program.AddTask(task);


	task = new Task;
	task->state =TASK_RUNNING;
	task->priority = 56;
	task->code = new Code;

	cmd = new Command;
	cmd->keyword = "LIGA";
	cmd->number = 2;
	task->code->AddCommand(cmd);

	cmd = new Command;
	cmd->keyword = "DESLIGA";
	cmd->number = 3;
	task->code->AddCommand(cmd);

	cmd = new Command;
	cmd->keyword = "PAUSA";
	cmd->number = 0;
	task->code->AddCommand(cmd);

	cmd = new Command;
	cmd->keyword = "DESLIGA";
	cmd->number = 2;
	task->code->AddCommand(cmd);

	cmd = new Command;
	cmd->keyword = "LIGA";
	cmd->number = 3;
	task->code->AddCommand(cmd);

	cmd = new Command;
	cmd->keyword = "PAUSA";
	cmd->number = 0;
	task->code->AddCommand(cmd);

	program.AddTask(task);

	return true;
}
*/


bool Compiler::MakeProgram()
{
	Program& program = Program::GetInstance();
        Command *cmd;
	Task *task;

	while (file.good()) {
		cmd = new Command;
		file >> cmd->keyword;

		if (file.eof())
			break;

		if (!cmd->keyword.compare("TAREFA")) {
			task = new Task;
			task->state =TASK_RUNNING;
			file >> task->priority;
			task->code = new Code;
			if (task)
				program.AddTask(task);
			delete cmd;
			continue;
		}

		if (cmd->keyword.compare("FIM")) {
			file >> cmd->number;
			cmd->number--;  //Porque no codigo começa em 1, mas no
						//simulador começa em zero.

			if (!cmd->keyword.compare("MOSTRA")) {
				file.ignore();
				std::getline(file, cmd->text);
			}
		}
		task->code->AddCommand(cmd);
	}

	return true;
}

