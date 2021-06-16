#include "Interaccion.h"
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
bool Interaccion::rebote(Hombre& h, ParedVertical v){
	Vector2D veloc = h.getVel();
	Vector2D acel = h.getAc();
	if ((v.limitev1.x-1) <= h.posicion.x && (v.limitev2.x+1 >= h.posicion.x))
	{
		if (v.limitev1.y >= h.posicion.y && v.limitev2.y <= h.posicion.y)
		{
			h.setAc(acel.x, -9.8f);
			h.setVel(0, veloc.y);
			return true;
		}
		return false;
	}
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

bool Interaccion::contacto(Hombre &h, EnemigoBase &e) {

	//Velocidad inicial del enemigo
	Vector2D vel_inicial = e.getVel();

	//Tratamiento de la colision del personaje (hombre) con el enemigo medio 
	float dist = sqrt(pow(h.posicion.x - e.posicion.x, 2) + pow(h.posicion.y - e.posicion.y, 2));
	Vector2D v_inicial1 = h.velocidad;
	if (round(dist) <= e.radio) {
		if (h.vida != 0) {
			ETSIDI::play("sonidos/impacto.wav");
			ETSIDI::play("sonidos/dolor.wav");
		}
		h.vida = h.vida - e.damage; //Si hay contacto entre ambos se resta un corazon
		if (h.velocidad.modulo() != 0) {
			h.velocidad = v_inicial1 * (-1.5f);
		}
		else{ 
			if(vel_inicial.x<0)h.velocidad = v_inicial1-5.0f;
			else h.velocidad = v_inicial1 + 5.0f;
		}
		if (h.vida <= 0) {
			h.vida = 0;
		}
		return true;
	}
	return false;
}

bool Interaccion::contacto(Hombre& h, EnemigoMedio &e) {

	//Velocidad inicial del enemigo
	Vector2D vel_inicial = e.getVel();

	//Tratamiento de la colision del personaje (hombre) con el enemigo medio 
	float dist = sqrt(pow(h.posicion.x - e.posicion.x, 2) + pow(h.posicion.y - e.posicion.y, 2));
	Vector2D v_inicial1 = h.velocidad;

	if (round(dist) <= e.radio) {
		if (h.vida != 0) {
			ETSIDI::play("sonidos/impacto.wav");
			ETSIDI::play("sonidos/dolor.wav");
		}
		h.vida = h.vida - e.damage; //Si hay contacto entre ambos se restan 2 corazones
		h.velocidad = v_inicial1 * (-1.5f); //Las velocidades de ambos se ven afectadas
		vel_inicial = e.getVel();
		e.velocidad = vel_inicial * (-1);

		if (h.vida <= 0) {

			h.vida = 0;
		}
		return true;
	}
	return false;
}

bool Interaccion::contacto(Hombre &h, EnemigoAvanzado &e) {

	//Tratamiento de la colision del personaje (hombre) con el enemigo avanzado
	float dist = sqrt(pow(h.posicion.x - e.posicion.x, 2) + pow(h.posicion.y - e.posicion.y, 2));
	Vector2D v_inicial1 = h.velocidad;

	if (round(dist) <= e.radio) {
		if (h.vida != 0) {
			ETSIDI::play("sonidos/impacto.wav");
			ETSIDI::play("sonidos/dolor.wav");
		}
		h.vida = h.vida - e.damage; //Si hay contacto entre ambos se restan 3 corazones
		h.velocidad = v_inicial1 * (-1.5f);

		if (h.vida <= 0) {

			h.vida = 0;
		}
		return true;
	}
	return false;
}

bool Interaccion::colision(Disparo d, ParedVertical v) {
	if ((v.limitev1.x - 1) <= d.posicion.x && (v.limitev2.x + 1 >= d.posicion.x)) {
		if (v.limitev1.y >= d.posicion.y && v.limitev2.y <= d.posicion.y) {
			ETSIDI::play("sonidos/flechaclavada.wav");
			return true;
		}
		return false;
	}
	return false;
}

bool Interaccion::colision(Disparo d, Pared p) {
	if ((p.limite1.x) <= d.posicion.x && (p.limite2.x >= d.posicion.x)) {
		if (p.limite1.y >= d.posicion.y && p.limite1.y - 1 <= d.posicion.y) {
			ETSIDI::play("sonidos/flechaclavada.wav");
			return true;
		}
		return false;
	}
	return false;
}

bool Interaccion::colision(Disparo& d, EnemigoBase& e) {
	//Colision del disparo con el enemigo Base
	float distancia = (e.posicion - d.getPos()).modulo();
	if (distancia <= e.radio) {
		//Si hay colision se elimina el disparo y se resta 1 vida al enemigo
		e.vida -= 1;
		if (e.vida !=0)
		ETSIDI::play("sonidos/enemigobase.wav");
		return true;
	}
	return false;
}
bool Interaccion::colision(Disparo& d, EnemigoMedio& e) {
	//Colision del disparo con el enemigo Medio
	float distancia = (e.posicion - d.getPos()).modulo();

	if (distancia <= e.radio) {
		//Si hay colision se elimina el disparo y se resta 1 vida al enemigo
		e.vida -= 1;
		if (e.vida != 0)
		ETSIDI::play("sonidos/enemigobase.wav");
		return true;
	}
	return false;
}

bool Interaccion::colision(Disparo& d, EnemigoAvanzado& e) {
	//Colision del disparo con el enemigo avanzado
	float distancia = (e.posicion - d.getPos()).modulo();

	if (distancia <= e.radio) {
		//Si hay colision se elimina el disparo y se resta 1 vida al enemigo
		e.vida -= 1;
		if (e.vida != 0)
		ETSIDI::play("sonidos/ghostpain.wav");
		return true;
	}
	return false;
}

bool Interaccion::colision(Vida v, Hombre &h) {
	Vector2D pos = h.getPos();
	pos.y += h.getAltura() / 2.0f;

	float distancia = (v.posicion - pos).modulo();
	if (distancia < 1) {
		if (h.getVida() < 3)
			h.setVida(h.getVida() + 1);
		ETSIDI::play("sonidos/vida.wav");
		return true;
	}
	return false;
}

bool Interaccion::colision(Moneda v, Hombre &h) {
	Vector2D pos = h.getPos();
	pos.y += h.getAltura() / 2.0f;

	float distancia = (v.posicion - pos).modulo();
	if (distancia < 1) {
		if (h.getMonedas() < 99)
			h.setMonedas(h.getMonedas() + 1);
		ETSIDI::play("sonidos/gema.wav");
		return true;
	}
	return false;
}

bool Interaccion::colision(Llave l, Hombre& h) {
	Vector2D pos = h.getPos();
	pos.y += h.getAltura() / 2.0f;

	float distancia = (l.posicion - pos).modulo();
	if (distancia < 1) {
		if (h.getLlaves() < 9)
			h.setLlaves(h.getLlaves() + 1);
		ETSIDI::play("sonidos/llaves.wav");
		return true;
	}
	return false;
}
