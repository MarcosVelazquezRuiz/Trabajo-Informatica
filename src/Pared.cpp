#include "Pared.h"
#include "freeglut.h"


Pared::Pared(float x1, float y1, float x2, float y2) {
	limite1.x = x1;
	limite1.y = y1;
	limite2.x = x2;
	limite2.y = y2;
	if ((x2 - x1)>4){
		plat = new ETSIDI::Sprite("imagenes/plataforma1.png", 0, 0, x2 - x1, 1.5);
	}else {
		plat = new ETSIDI::Sprite("imagenes/plataforma2.png", 0, 0, x2 - x1, 1.5);
	}
}

void Pared::Dibuja(){
	plat->setPos((limite1.x + limite2.x) / 2, limite1.y - 0.75);
	plat->draw();
}

void Pared::Mueve(float t) {}


void Pared::setPos(float lim1x, float lim1y, float lim2x, float lim2y){
	limite1.x = lim1x;
	limite1.y = lim1y;
	limite2.x = lim2x;
	limite2.y = lim2y;
}

float Pared::distancia(Vector2D punto, Vector2D* direccion) {

	Vector2D u = (punto - limite1);
	Vector2D v = (limite2 - limite1).unitario();
	float longitud = (limite1 - limite2).modulo();
	Vector2D dir;
	float valor = u * v;
	float distancia = 0;

	if (valor < 0)
		dir = u;
	else if (valor > longitud)
		dir = (punto - limite2);
	else
		dir = u - v * valor;
	distancia = dir.modulo();
	if (direccion != 0) //si nos dan un vector… 
		*direccion = dir.unitario();
	return distancia;
}

Vector2D Pared::GetPos(int num) {
	if (num == 1) {
		return limite1;
	}
	else {
		return limite2;
	}
}