#pragma once
#include "mundo.h"

class Coordinador
{
private: 
	Mundo mundo;
	enum Estado {INICIO, JUEGO, GAMEOVER, FIN, INSTRUCCIONES, PAUSA, HISTORIA, RANKING};
	Estado estado;

public:
	Coordinador();
	void Mueve();
	void Dibuja();
	void Tecla(unsigned char key);
	void teclaEspecial(unsigned char key);
	void NoPresionoTecla(unsigned char key);
};

