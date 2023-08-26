#ifndef COMPILER_HPP_INCLUDED
#define COMPILER_HPP_INCLUDED

#include <fstream>
#include <string>
#include "Application.hpp"
#include "Code.hpp"
#include "Task.hpp"
#include "Program.hpp"

class Compiler
{
public:
	static const std::string SourceName;
        bool Init();
        bool Run(void);
        void Fini();
    	static Compiler& GetInstance();
private:
        Compiler();
        ~Compiler();
        bool MakeProgram();
	bool running_;
        std::ifstream file;
};

#endif // COMPILER_HPP_INCLUDED

