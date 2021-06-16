#pragma once
#include "ETSIDI.h"
#include "Vector2D.h"
#include "Hombre.h"

using ETSIDI::SpriteSequence;

class VidaHUD {

	SpriteSequence barra{ "imagenes/BarraVidaM.png",3};

public:
	VidaHUD();
	~VidaHUD();
	void Dibuja(Hombre h);



protected:
	//float radio;
	//Vector2D posicion;
};

