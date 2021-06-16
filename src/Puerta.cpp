#include "Puerta.h"

Puerta::Puerta(float x1, float y1, float x2, float y2) :Pared(x1, y1, x2, y2) {
	puerta = new ETSIDI::Sprite("imagenes/castillo.png", 2, 2, 8, 8);
}

Puerta::~Puerta()
{
}

void Puerta::Dibuja() {
	puerta->setPos((limite1.x + limite2.x) / 2, (limite1.y + limite2.y) / 2);
	puerta->draw();
}


void Puerta::SetPos(float lim1x, float lim1y, float lim2x, float lim2y) {
	limite1.x = lim1x;
	limite1.y = lim1y;
	limite2.x = lim2x;
	limite2.y = lim2y;
}

