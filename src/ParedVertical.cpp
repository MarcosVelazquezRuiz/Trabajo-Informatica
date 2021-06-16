#include "ParedVertical.h"
#include "freeglut.h"
#include "ETSIDI.h"

ParedVertical::ParedVertical(float x1, float y1, float x2, float y2){
	limitev1.x = x1;
	limitev1.y = y1;
	limitev2.x = x2;
	limitev2.y = y2;
	vert = new ETSIDI::Sprite("imagenes/MuroPiedra.png", 0, 0, 1.5, y1-y2);
}

void ParedVertical::Dibuja()
{
	vert->setPos(limitev1.x, (limitev1.y - limitev2.y) / 2);
	vert->draw();
}

void ParedVertical::setPos(float lim1x, float lim1y, float lim2x, float lim2y)
{
	limitev1.x = lim1x;
	limitev1.y = lim1y;
	limitev2.x = lim2x;
	limitev2.y = lim2y;
}

float ParedVertical::distancia(Vector2D punto, Vector2D* direccion) {

	Vector2D u = (punto - limitev1);
	Vector2D v = (limitev2 - limitev1).unitario();
	float longitud = (limitev1 - limitev2).modulo();
	Vector2D dir;
	float valor = u * v;
	float distancia = 0;

	if (valor < 0)
		dir = u;
	else if (valor > longitud)
		dir = (punto - limitev2);
	else
		dir = u - v * valor;
	distancia = dir.modulo();
	if (direccion != 0) //si nos dan un vector… 
		*direccion = dir.unitario();
	return distancia;
}