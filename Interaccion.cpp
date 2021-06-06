#include "Interaccion.h"
#include "Hombre.h""
#include <math.h>


	// Se pasa por referencia lo que va a cambiar su valor


bool Interaccion::rebote(Hombre &h, Pared p)
{
	Vector2D dir;
	Vector2D vel = h.getVel();
	Vector2D ace = h.getAc();
	float dif = p.distancia(h.posicion, &dir) -2;
	if (dif <= 0.0f && h.posicion.x < p.limite2.x && p.limite1.x<h.posicion.x)
	{
		h.setVel(vel.x, 0);
		h.setAc(ace.x, 0);
		
		return true;
	}
	h.setAc(ace.x, -9.8);
	return false;
}