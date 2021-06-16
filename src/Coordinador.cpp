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
			//ETSIDI::play("sonidos/muertehombre.wav"); // no se oye :(
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

		ETSIDI::setTextColor(0, 1, 0);
		ETSIDI::setFont("fuentes/The Flowers St.ttf", 30);
		ETSIDI::printxy("Forest Archer", -5,16);

		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/archer.png").id); 
		glDisable(GL_LIGHTING);
		glBegin(GL_POLYGON);
		glColor3f(1, 1, 1);
		glTexCoord2d(0, 1);    glVertex3f(-6, 6, -0.1);
		glTexCoord2d(1, 1);    glVertex3f(6, 6, -0.1);
		glTexCoord2d(1, 0);    glVertex3f(6, 15, -0.1);
		glTexCoord2d(0, 0);    glVertex3f(-6, 15, -0.1);
		glEnd();
		glEnable(GL_LIGHTING);
		glDisable(GL_TEXTURE_2D);


		ETSIDI::setTextColor(1, 1, 1);
		ETSIDI::setFont("fuentes/Bitwise.ttf", 16);
		ETSIDI::printxy("PULSE LA TECLA -E- PARA EMPEZAR", -10,3);
		ETSIDI::printxy("PULSE LA TECLA -S- PARA SALIR", -10, 2);
		ETSIDI::printxy("PULSE LA TECLA -I- PARA VER LAS INSTRUCCIONES", -10, 1);
		ETSIDI::printxy("Computatis", 1, -2);
	
		hombre.setVida(3);

	}

	else if (estado == JUEGO) 
	{
		mundo.dibuja();
	
	}

	else if (estado == GAMEOVER) {
		gluLookAt(0, 7.5, 30,
			0.0, 7.5, 0.0,
			0.0, 1.0, 0.0);
		ETSIDI::play("sonidos/gameover.wav");
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/gameover.png").id); // es un poco cutre y tal pero bueno
		glDisable(GL_LIGHTING);
		glBegin(GL_POLYGON);
		glColor3f(1, 1, 1);
		glTexCoord2d(0, 1);    glVertex3f(-7, 3, -0.1);
		glTexCoord2d(1, 1);    glVertex3f(7, 3, -0.1);
		glTexCoord2d(1, 0);    glVertex3f(7, 18, -0.1);
		glTexCoord2d(0, 0);    glVertex3f(-7, 18, -0.1);
		glEnd();
		glEnable(GL_LIGHTING);
		glDisable(GL_TEXTURE_2D);

		ETSIDI::setTextColor(1, 1, 1);
		ETSIDI::setFont("fuentes/Bitwise.ttf", 16);
		ETSIDI::printxy("No pudiste salvar a la dama...", -10, 6);
		ETSIDI::printxy("PULSA CUALQUIER TECLA", -10, 5);
	}
	
	else if (estado == FIN) {
		gluLookAt(0, 7.5, 30,
			0.0, 7.5, 0.0,
			0.0, 1.0, 0.0);

		ETSIDI::setTextColor(1, 1, 1);
		ETSIDI::setFont("fuentes/Bitwise.ttf", 16);
		ETSIDI::printxy("FELICIDADES, HAS LLEGADO AL FIN DEL JUEGO", -10, 10);
		ETSIDI::printxy("Pero la bella dama sigue en apuros, ", -10, 9);
		ETSIDI::printxy("termina la historia en Forest Archer 2, disponible en 2022 ", -10, 8);
		ETSIDI::setTextColor(0, 1, 1);
		ETSIDI::printxy("PULSA LA TECLA -C- PARA VOLVER A LA PANTALLA DE INICIO", -12, 5);

	}

	else if (estado == HISTORIA) {
		gluLookAt(0, 7.5, 30,
			0.0, 7.5, 0.0,
			0.0, 1.0, 0.0);
		if (mundo.GetNivel() == 1) {
			ETSIDI::setTextColor(1, 1, 1);
			ETSIDI::setFont("fuentes/Bitwise.ttf", 16);
			ETSIDI::setTextColor(1, 0, 1);
			ETSIDI::printxy("NIVEL 1", -2, 16);
			ETSIDI::setTextColor(0, 1, 1);
			ETSIDI::printxy("Erase una vez un joven arquero, al cual los COMPUTATIS", -12, 14);
			ETSIDI::printxy("secuestraron a su bella dama y la llevaron a su castillo", -12, 13);
			ETSIDI::printxy("al final del bosque. Para que el joven arquero rescate a", -12, 12);
			ETSIDI::printxy("su bella dama, debera recoger 3 llaves que se les cayeron", -12, 11);
			ETSIDI::printxy("a los COMPUTATIS por el camino de vuelta tras raptar a la", -12, 10);
			ETSIDI::printxy("bella dama. Una vez conseguidas las tres llaves el arquero", -12, 9);
			ETSIDI::printxy("podra acceder al castillo y vencer a los COMPUTATIS.", -12, 8);
			ETSIDI::printxy("Por el camino nuestro joven arquero no lo tendra nada fácil,", -12, 7);
			ETSIDI::printxy("ya que debera destruir a los esbirros de los COMPUTATIS , que", -12, 6);
			ETSIDI::printxy("se encuentran viviendo en las profundidades del bosque a la", -12, 5);
			ETSIDI::printxy("espera de que entre en su territorio cualquier persona para", -12, 4);
			ETSIDI::printxy("destruirla. Por ello nuestro joven arquero lleva consigo su.", -12, 3);
			ETSIDI::printxy("leal arco de flechas que le ayudara en esta dura aventura. ", -12, 2);
			ETSIDI::printxy("¿ESTAS LISTO PARA AYUDARLE?", 0, 0);
			ETSIDI::setTextColor(1, 1, 1);
			ETSIDI::printxy("PULSA LA TECLA -G- PARA COMENZAR", -8, -2);
		}
		else if (mundo.GetNivel() == 2) {
			ETSIDI::setTextColor(1, 1, 1);
			ETSIDI::setFont("fuentes/Bitwise.ttf", 16);
			ETSIDI::setTextColor(1, 0, 1);
			ETSIDI::printxy("NIVEL 2", 0, 16);
			ETSIDI::setTextColor(0, 1, 1);
			ETSIDI::printxy("OHHHHHHHH!! las 3 llaves conseguidas solo abren la puerta ", -12, 14);
			ETSIDI::printxy("hacia otro reino, nuestro joven arquero a estado preguntando", -12, 13);
			ETSIDI::printxy("a los pueblerinos de la zona y le han comentado que el verdadero ", -12, 12);
			ETSIDI::printxy("castillo de los COMPUTATIS esta al otro lado de este reino y para", -12, 11);
			ETSIDI::printxy("acceder a este castillo deberá de cruzar todo el  bosque del segundo", -12, 10);
			ETSIDI::printxy("reino repleto nuevamente de numerosos  esbirros y conseguir otras ", -12, 9);
			ETSIDI::printxy("3 llaves que se encuentran esparcidas en el terreno y con ellas  ", -12, 8);
			ETSIDI::printxy("esta vez si conseguira acceder al castillo y rescatar a su bella dama.", -12, 7);
			ETSIDI::printxy("¿ESTAS LISTO PARA AYUDARLE?", 0, 5);
			ETSIDI::setTextColor(1, 1, 1);
			ETSIDI::printxy("PULSA LA TECLA -G- PARA COMENZAR", -8, 0);
		}
	}

	else if (estado == INSTRUCCIONES) {
	gluLookAt(0, 7.5, 30,
		0.0, 7.5, 0.0,
		0.0, 1.0, 0.0);
	
	ETSIDI::setTextColor(0, 1, 1);
	ETSIDI::setFont("fuentes/Bitwise.ttf", 16);
	ETSIDI::printxy("INSTRUCCIONES", -3, 16); //ESCRIBIR LAS INSTRUCCIONES DEL JUEGO
	ETSIDI::setTextColor(1, 1, 1);
	ETSIDI::printxy("PULSA LA TECLA -A- PARA DESPLAZARTE A LA IZQUIERDA", -12, 12);
	ETSIDI::printxy("PULSA LA TECLA -D- PARA DESPLAZARTE A LA DERECHA", -12, 10);
	ETSIDI::printxy("PULSA LA BARRA ESPACIADORA PARA SALTAR", -12, 8);
	ETSIDI::printxy("PULSA LA TECLA -S- PARA  DISPARAR", -12, 6);
	ETSIDI::printxy("PULSA LA TECLA -C- PARA VOLVER A LA PANTALLA DE INICIO", -12, -2);
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
	
}

void Coordinador::Tecla(unsigned char key) {

	if (estado == INICIO) {
		ETSIDI::play("sonidos/menu.wav");
		if (key == 'e'|| key=='E') {
			mundo.inicializa();
			estado = HISTORIA;
		}
		if (key == 's' || key == 'S') {
			exit(0);
		}if (key == 'i' || key == 'I') {
			estado = INSTRUCCIONES;
		}
	}
	else if (estado == JUEGO) {
		mundo.tecla(key);
		if (key == 'p' || key == 'P') {
			estado = PAUSA;
		}
	}
	else if (estado == GAMEOVER) {
		if (key == 'c' || key == 'C') {
			mundo.reset();
			estado = INICIO;
		}
		else {
			mundo.reset();
			estado = INICIO;
		}
		
	}
	else if (estado == FIN) {
		if (key == 'c' || key == 'C') {
			mundo.reset();
			estado = INICIO;
		}
		else {
			mundo.reset();
			estado = INICIO;
		}
	}
	else if (estado == HISTORIA) {
		if (key == 'g' || key == 'G') {
			estado = JUEGO;
		}
	}
	else if (estado == INSTRUCCIONES) {
		ETSIDI::play("sonidos/menu.wav");
		if (key == 'c' || key == 'C') {
			estado = INICIO;
		}
	}
	else if (estado == PAUSA) {
		ETSIDI::play("sonidos/menu.wav");
		if (key == 'c' || key == 'C') {
			estado = JUEGO;
		}
	}
	
}

void Coordinador::NoPresionoTecla(unsigned char key)
{
	mundo.NoPresionoTecla(key);
}