
#pragma once
#include "ETSIDI.h"
#include "Vector2D.h"
#include "Hombre.h"

#include <iostream>
#include <sstream>
#include <cstdlib>

using ETSIDI::SpriteSequence;

class MonedasHUD {

	SpriteSequence moneda{ "imagenes/gema.png",4 };

public:
	MonedasHUD();
	~MonedasHUD();
	void Dibuja(Hombre h);
	void DibujarTexto(const char* texto, int longitud, int x, int y);;
	


protected:
	//float radio;
	//Vector2D posicion;
};

