/*******************************************************************************

UNIVERSIDADE DO VALE DO RIO DOS SINOS
Description: Projeto Grau B - Algoritmos e Estruturas de Dados em C++
Simulador de Controlador Lógico Programável (CLP)
Author:      Maicon Cesar Canales de Oliveira
Prof. MSc.   Vinícius Cassol
Date:        05/12/2013

*******************************************************************************/

#include "Application.hpp"
#include "CLP_Simulator.hpp"
#include "Compiler.hpp"

int main()
{
	bool running = true;

	Compiler& CompilerCLP = Compiler::GetInstance();
	Application& InterfaceCLP = Application::GetInstance();
	CLP_Simulator& SimulatorCLP = CLP_Simulator::GetInstance();

	if (!CompilerCLP.Init())
		return EXIT_FAILURE;

	if (!CompilerCLP.Run())
		return EXIT_FAILURE;

	if (!InterfaceCLP.Init())
		return EXIT_FAILURE;

	if (!SimulatorCLP.Init())
		return EXIT_FAILURE;

	InterfaceCLP.Run();

	do {
		SimulatorCLP.Run();
		running = InterfaceCLP.Run();

	} while (running);

	return EXIT_SUCCESS;
}

