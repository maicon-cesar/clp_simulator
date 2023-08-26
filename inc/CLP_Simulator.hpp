#ifndef CLP_SIMULATOR_HPP_INCLUDED
#define CLP_SIMULATOR_HPP_INCLUDED

#include "Application.hpp"
#include "Code.hpp"
#include "Task.hpp"
#include "Program.hpp"

class CLP_Simulator
{
public:
        bool Init();
        bool Run(void);
        void Fini();
	int RunTask(Task *task);
    	static CLP_Simulator& GetInstance();
private:
        CLP_Simulator();
        ~CLP_Simulator();
        bool running_;

};

#endif // CLP_SIMULATOR_HPP_INCLUDED

