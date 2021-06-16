#include "PlatMoviles.h"
#include "freeglut.h"
#include "ETSIDI.h"

PlatMoviles::PlatMoviles(float x1, float y1, float x2, float y2) : Pared(x1, y1, x2, y2)
{
	origen.x = x1;
	origen.y = x2;
	limite1.x = x1;
	limite2.x = x2;
	limite1.y = y1;
	limite2.y = y2;
	velocidad.x = 50.0f;
	if ((x2 - x1) > 4) {
		plat = new ETSIDI::Sprite("imagenes/plataforma1.png", 0, 0, x2 - x1, 1.5);
	}
	else {
		plat = new ETSIDI::Sprite("imagenes/plataforma2.png", 0, 0, x2 - x1, 1.5);
	}
}

void PlatMoviles::Dibuja(){
	plat->setPos((limite1.x + limite2.x) / 2, limite1.y - 0.75);
	plat->draw();
}

void PlatMoviles::Mueve(float t)
{
	if (mov == 1) {
		limite1 = limite1 - velocidad * t - aceleracion * (0.5f * t * t);
		velocidad = velocidad - aceleracion * t;
		limite2 = limite2 - velocidad * t - aceleracion * (0.5f * t * t);
		velocidad = velocidad - aceleracion * t;
		if (limite2.x <= origen.y - 5) {
			mov = 0;
		}
	}
	else if (mov == 0) {
		limite1 = limite1 + velocidad * t + aceleracion * (0.5f * t * t);
		velocidad = velocidad + aceleracion * t;
		limite2 = limite2 + velocidad * t + aceleracion * (0.5f * t * t);
		velocidad = velocidad + aceleracion * t;
		if (limite1.x >= origen.x + 5) {
			mov = 1;
		}
	}
}