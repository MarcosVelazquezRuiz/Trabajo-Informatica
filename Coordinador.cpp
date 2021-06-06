#include "Coordinador.h"
#include "ETSIDI.h"

Coordinador::Coordinador()
{
	estado = INICIO;
}

void Coordinador::Mueve()
{
	if (estado == JUEGO) {
		mundo.mueve();
		if (mundo.GetMuerte()) {
			estado = GAMEOVER;
			//añadir sonido
		}
		else if (mundo.GetFin()) {
			if (mundo.cargarNivel()) {
				estado = HISTORIA;
			}
			else {
				estado = FIN;
				//añadir sonido
			}
		}
	}
}

void Coordinador::Dibuja()
{
	if (estado == INICIO)
	{
		gluLookAt(0, 7.5, 30,
			0.0, 7.5, 0.0,
			0.0, 1.0, 0.0);

		ETSIDI::setTextColor(1, 1, 0);
		ETSIDI::setFont("fuentes/Bitwise.ttf", 16);
		ETSIDI::printxy("Juego", -5,8);
		ETSIDI::setTextColor(1, 1, 1);
		ETSIDI::setFont("fuentes/Bitwise.ttf", 16);
		ETSIDI::printxy("PULSE LA TECLA -E- PARA EMPEZAR", -10,7);
		ETSIDI::printxy("PULSE LA TECLA -S- PARA SALIR", -10, 6);
		ETSIDI::printxy("PULSE LA TECLA -I- PARA VER LAS INSTRUCCIONES", -10, 5);
		ETSIDI::printxy("PULSE LA TECLA -R- PARA VER EL RANKINE", -10, 4);
		ETSIDI::printxy("Computatis", 2, 1);
	}

	else if (estado == JUEGO) 
	{
		mundo.dibuja();
	}

	else if (estado == GAMEOVER) {
		gluLookAt(0, 7.5, 30,
			0.0, 7.5, 0.0,
			0.0, 1.0, 0.0);
		
		ETSIDI::setTextColor(1, 1, 1);
		ETSIDI::setFont("fuentes/Bitwise.ttf", 16);
		ETSIDI::printxy("GAMEOVER", -10, 8);
		ETSIDI::printxy("PULSA LA TECLA -C- PARA VOLVER A EMPEZAR", -10, 5);
	}

	else if (estado == FIN) {
		gluLookAt(0, 7.5, 30,
			0.0, 7.5, 0.0,
			0.0, 1.0, 0.0);

		ETSIDI::setTextColor(1, 1, 1);
		ETSIDI::setFont("fuentes/Bitwise.ttf", 16);
		ETSIDI::printxy("FIN DEL JUEGO", -10, 8);
		ETSIDI::printxy("PULSA LA TECLA -C- PARA VOLVER A LA PANTALLA DE INCIO", -12, 5);

	}

	else if (estado == HISTORIA) {
		gluLookAt(0, 7.5, 30,
			0.0, 7.5, 0.0,
			0.0, 1.0, 0.0);
		if (mundo.GetNivel() == 1) {
			ETSIDI::setTextColor(1, 1, 1);
			ETSIDI::setFont("fuentes/Bitwise.ttf", 16);
			ETSIDI::printxy("PULSA LA TECLA -G- PARA COMENZAR", -10, 5);

		}
		else if (mundo.GetNivel() == 2) {
			ETSIDI::setTextColor(1, 1, 1);
			ETSIDI::setFont("fuentes/Bitwise.ttf", 16);
			ETSIDI::printxy("PULSA LA TECLA -G- PARA COMENZAR", -10, 5);
		}
	}

	else if (estado == INSTRUCCIONES) {
	gluLookAt(0, 7.5, 30,
		0.0, 7.5, 0.0,
		0.0, 1.0, 0.0);
	
	ETSIDI::setTextColor(1, 1, 1);
	ETSIDI::setFont("fuentes/Bitwise.ttf", 16);
	ETSIDI::printxy("INSTRUCCIONES", -10, 8); //ESCRIBIR LAS INSTRUCCIONES DEL JUEGO
	ETSIDI::printxy("PULSA LA TECLA -C- PARA VOLVER A LA PANTALLA DE INICIO", -12, 5);
	}

	else if (estado == PAUSA) {
	gluLookAt(0, 7.5, 30,
		0.0, 7.5, 0.0,
		0.0, 1.0, 0.0);
	
	ETSIDI::setTextColor(1, 1, 1);
	ETSIDI::setFont("fuentes/Bitwise.ttf", 16);
	ETSIDI::printxy("PAUSE", -10, 8);
	ETSIDI::printxy("PULSA LA TECLA -C- PARA VOLVER A EMPEZAR", -10, 5);

	}
	else if (estado == RANKING) {
		gluLookAt(0, 7.5, 30,
			0.0, 7.5, 0.0,
			0.0, 1.0, 0.0);
		// ¡¡¡¡¡¡¡¡¡¡¡¡¡COMPLETAR!!!!!!!!!!!!!
		ETSIDI::setTextColor(1, 1, 1);
		ETSIDI::setFont("fuentes/Bitwise.ttf", 16);
		ETSIDI::printxy("FIN DEL JUEGO", -10, 8);
		ETSIDI::printxy("PULSA LA TECLA -C- PARA VOLVER A LA PANTALLA DE INCIO", -12, 5);
	}
}

void Coordinador::Tecla(unsigned char key) {
	if (estado == INICIO) {
		if (key == 'e') {
			mundo.inicializa();
			estado = HISTORIA;
		}
		if (key == 's') {
			exit(0);
		}if (key == 'i') {
			estado = INSTRUCCIONES;
		}
		if (key == 'r') {
			estado = RANKING;
		}
	}
	else if (estado == JUEGO) {
		mundo.tecla(key);
		if (key == 'p') {
			estado = PAUSA;
		}
	}
	else if (estado == GAMEOVER) {
		if (key == 'c')
			mundo.reset();
		estado = INICIO;
	}
	else if (estado == FIN) {
		if (key == 'c')
			mundo.reset();
		estado = INICIO;
	}
	else if (estado == HISTORIA) {
		if (key == 'g') {
			estado = JUEGO;
		}
	}
	else if (estado == INSTRUCCIONES) {
		if (key == 'c') {
			estado = INICIO;
		}
	}
	else if (estado == PAUSA) {
		if (key == 'c') {
			estado = JUEGO;
		}
	}
	else if (estado == RANKING) {
		if (key == 'c') {
			estado = INICIO;
		}
	}
}

void Coordinador::NoPresionoTecla(unsigned char key)
{
	mundo.NoPresionoTecla(key);
}