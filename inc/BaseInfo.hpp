#ifndef BASEINFO_H
#define BASEINFO_H

#include <SFML/Graphics.hpp>

//Mapeamento de itens

/*
struct {
	int id;
	sf::Color
	sf::String sCor;
	sf::String sName;
};
*/

//ruct { 
	enum eLocomocao	{ ESTEIRA, RODAS, PROPULSORES, LOC_COUNT };	
	sf::String nomeLocomocao[] = { "Esteira", "Rodas", "Propulsores" };         
	sf::String loc_mia[] = { "robot3_", "robo1_", "robo2_" };

	enum eArmadura { MALHA, COURO, FERRO, ARMD_COUNT };
	sf::String nomeArmadura[] = { "Malha", "Couro", "Ferro" };
	sf::String armd_mia[] = { "", "escudo3_", "escudo2_", "escudo1_" };

	enum eArma { PISTOLA, REVOLVER, MAGNET, ARMA_COUNT };
	sf::String nomeArma[] = { "Pistola Parabellum", "Revolver RT 689", "Magnet Gun" };
	sf::String arma_mia[] = { "arma2_", "arma3_", "arma1_" };
//} Itens;

//struct {
	sf::String cor[] = { "AMARELO_", "VERDE_", "AZUL_", "VERMELHO_" };
	sf::String sentido[] = { "direita", "esquerda" };
//} mapa_itens_arquivo;



#endif
