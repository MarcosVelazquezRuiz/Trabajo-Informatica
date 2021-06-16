#include "Vector2D.h"
#include "math.h"

Vector2D::Vector2D(float xv, float yv){
	x = xv;
	y = yv;
}

float Vector2D::modulo(){
	return (float)sqrt(x * x + y * y);
}

float Vector2D::argumento(){
	return (float)atan2(y, x);
}

Vector2D Vector2D::unitario()
{
	Vector2D retorno(x, y);
	float mod = modulo();
	if (mod > 0.00001)
	{
		retorno.x /= mod;
		retorno.y /= mod;
	}
	return retorno;
}

Vector2D Vector2D::operator - (Vector2D v)
{
	Vector2D res;
	res.x = x - v.x;
	res.y = y - v.y;
	return res;
}

Vector2D Vector2D::operator + (Vector2D v){
	Vector2D res;
	res.x = x + v.x;
	res.y = y + v.y;
	return res;
}

float Vector2D::operator *(Vector2D v) {	// (7) producto escalar  vx1vx2+vy1vy2

	float res;

	res = v.x * x + v.y * y;

	return res;
}
	
Vector2D Vector2D::operator *(float factor) {		// (8) producto por un escalar

	Vector2D res;
	res.x = x * factor;
	res.y = y * factor;
	return res;
}


