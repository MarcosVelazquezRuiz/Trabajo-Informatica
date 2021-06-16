#pragma once
#include "ETSIDI.h"
#include "Vector2D.h"
#include "Hombre.h"

#include <iostream>
#include <sstream>
#include <cstdlib>

using ETSIDI::SpriteSequence;

class LlavesHUD {

	SpriteSequence llave{ "imagenes/llaves.png",1 };

public:
	LlavesHUD();
	~LlavesHUD();
	void Dibuja(Hombre h);
	void DibujarTexto(const char* texto, int longitud, int x, int y);;



protected:
	//float radio;
	//Vector2D posicion;
};