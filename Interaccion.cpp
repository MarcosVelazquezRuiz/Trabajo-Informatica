#include "Interaccion.h"
#include "Hombre.h"
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

bool Interaccion::rebote(EnemigoBase &e, Pared p) {

	//Devuelve true si se ha producido colision entre ambos objetos
	Vector2D dir;
	Vector2D pos = e.getPos();
	float dif = p.distancia(e.posicion, &dir) - e.radio; //Calculo de la diferencia de distancia entre la pared y el centro de la esfera (Enemigo)
	if (dif <= 0.0f) {
		//Si hay colision se modifica la velocidad del enemigo
		Vector2D v_inicial = e.velocidad;
		e.posicion = e.posicion - dir * dif;
		if (round(pos.x) == p.limite1.x) {
			//De esta forma se evita que el enemigo salga de la plataforma
			e.velocidad = v_inicial.x*(-1); 
		}
		if (round(pos.x) == p.limite2.x) {

			e.velocidad.x = v_inicial.x * (-1);
		}
		return true;
	}
	return false;
}

int Interaccion::contacto(Hombre& h, EnemigoBase& e) {

	float dist = sqrt(pow(h.posicion.x - e.posicion.x, 2) + pow(h.posicion.y - e.posicion.y, 2));
	Vector2D v_inicial1 = h.velocidad;

	if (round(dist) <= e.radio) {

		h.vida = h.vida - e.damage; //Si hay contacto entre ambos se resta un corazon
		h.velocidad = v_inicial1*(-1.5f);

		if (h.vida == 0) {
			//Como el enemigo base tiene daño 1 para GAME OVER le debe dar 3 veces
			return 0;
		}
	}
	return h.vida; //Devuelve la vida del personaje
}