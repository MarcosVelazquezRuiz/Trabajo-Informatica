#include "mundo.h"
#include "math.h"
#include "freeglut.h"
#include "ETSIDI.h"

Mundo::Mundo() {
	FinNivel = false;
	muerte = false;
	nivel = 0;
}


void Mundo::inicializa() {
	  // posicion del ojo
	
	FinNivel = false;
	muerte = false;

	hombre.setPos(0, 5);
	hombre.setAc(0, -9.8);
	hombre.setVida(3);
	hombre.setVel(0, 0);
	cargarNivel();
}

void Mundo::dibuja() {

	Vector2D posh = hombre.getPos();
	eyex = posh.x;
	eyey = posh.y;
	int vida = hombre.getVida();

	gluLookAt(eyex, 0, 30,  // posicion del ojo
		eyex, 0, 0,      // hacia que punto mira  (0,0,0) 
		0.0, 1.0, 0.0);

	hombre.Dibuja();
	plataformas.Dibuja();
	puerta.Dibuja();
	disparos.Dibuja();
	verticales.Dibuja();
	corazones.dibuja();
	monedas.dibuja();
	llaves.dibuja();
	barravida.Dibuja(hombre);
	monedero.Dibuja(hombre);
	llavero.Dibuja(hombre);
	enemigosBase.dibuja();
	enemigosMedio.dibuja();
	enemigosAvanzado.dibuja();

	glEnable(GL_TEXTURE_2D);
	if (GetNivel() == 1||GetNivel()==2) {

		
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/bosque.png").id); 
		glDisable(GL_LIGHTING);
		glBegin(GL_POLYGON);
		glColor3f(1, 1, 1);
		glTexCoord2d(0, 1); glVertex2f(-22, -11);
		glTexCoord2d(1, 1); glVertex2f(48, -11);
		glTexCoord2d(1, 0); glVertex2f(48, 11);
		glTexCoord2d(0, 0); glVertex2f(-22, 11);
		glEnd();

		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/bosque.png").id); 
		glBegin(GL_POLYGON);
		glColor3f(1, 1, 1);
		glTexCoord2d(0, 1); glVertex2f(48, -11);
		glTexCoord2d(1, 1); glVertex2f(118, -11);
		glTexCoord2d(1, 0); glVertex2f(118, 11);
		glTexCoord2d(0, 0); glVertex2f(48, 11);
		glEnd();
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/bosque.png").id); 
		glBegin(GL_POLYGON);
		glColor3f(1, 1, 1);
		glTexCoord2d(0, 1); glVertex2f(118, -11);
		glTexCoord2d(1, 1); glVertex2f(188, -11);
		glTexCoord2d(1, 0); glVertex2f(188, 11);
		glTexCoord2d(0, 0); glVertex2f(118, 11);
		glEnd();
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/bosque.png").id); 
		glBegin(GL_POLYGON);
		glColor3f(1, 1, 1);
		glTexCoord2d(0, 1); glVertex2f(188, -11);
		glTexCoord2d(1, 1); glVertex2f(258, -11);
		glTexCoord2d(1, 0); glVertex2f(258, 11);
		glTexCoord2d(0, 0); glVertex2f(188, 11);
		glEnd();	
	

		if (GetNivel() == 2) {
			
			glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/bosque.png").id); 
			glDisable(GL_LIGHTING);
			glBegin(GL_POLYGON);
			glColor3f(1, 1, 1);
			glTexCoord2d(0, 1); glVertex2f(258, -11);
			glTexCoord2d(1, 1); glVertex2f(328, -11);
			glTexCoord2d(1, 0); glVertex2f(328, 11);
			glTexCoord2d(0, 0); glVertex2f(258, 11);
			glEnd();
			glEnable(GL_LIGHTING);
		}


		glDisable(GL_TEXTURE_2D);

	}

	
}

void Mundo::mueve() {
	Vector2D poshom = hombre.getPos();

	hombre.mueve(0.025f);
	
	disparos.Mueve(0.025f);
	plataformas.Mueve(0.001f);
	verticales.rebote(hombre);
	plataformas.rebote(hombre);
	
	enemigosBase.mueve(0.025f);
	enemigosBase.colision(hombre);

	enemigosMedio.mueve(0.025f);
	enemigosMedio.colision(hombre);

	enemigosAvanzado.mueve(0.025f);
	enemigosAvanzado.colision(hombre);

	corazones.mueve();
	monedas.mueve();
	llaves.mueve();
	for (int i = 0; i < enemigosBase.getNumeroEnemigos(); i++) {
		plataformas.rebote(*enemigosBase.getEnemigo(i));
	}

	//Interaccion::colision(vidatest, hombre);
	
	Vida* aux = corazones.colision(hombre);
	if (aux != 0) {
		corazones.eliminar(aux);
		
	}

	Moneda* aux2 = monedas.colision(hombre);
	if (aux2 != 0) {
		monedas.eliminar(aux2);
	}
	Llave* aux3 = llaves.colision(hombre);
	if (aux3 != 0) {
		llaves.eliminar(aux3);
	}

	//Interaccion disparos para eliminar
	for (int j = 0; j < disparos.getNumero(); j++) {
		if (disparos[j]->fuerapantalla()) disparos.eliminar(j);
		for (int i = 0; i < verticales.getNum(); i++) {
			if (Interaccion::colision(*disparos[j], *verticales[i])) disparos.eliminar(j);
		}
		for (int i = 0; i < plataformas.getNum(); i++) {
			if (Interaccion::colision(*disparos[j], *plataformas[i])) disparos.eliminar(j);
		}
		for (int i = 0; i < enemigosBase.getNumeroEnemigos(); i++) {
			if (Interaccion::colision(*disparos[j], *enemigosBase[i])) {
				disparos.eliminar(j);
				int vidaBase = enemigosBase[i]->getVida();
				if (vidaBase == 0) {
					ETSIDI::play("sonidos/muerteenemigo.wav");
					enemigosBase.eliminar(i);
				}
			}
		}
		for (int i = 0; i < enemigosMedio.getNumeroEnemigos(); i++) {
			if (Interaccion::colision(*disparos[j], *enemigosMedio[i])) {
				disparos.eliminar(j);
				int vidaMedio = enemigosMedio[i]->getVida();
				if (vidaMedio == 0) {
					ETSIDI::play("sonidos/muerteenemigo.wav");
					enemigosMedio.eliminar(i);
				}
			}

		}
		for (int i = 0; i < enemigosAvanzado.getNumeroEnemigos(); i++) {
			if (Interaccion::colision(*disparos[j], *enemigosAvanzado[i])) {
				disparos.eliminar(j);
				int vidaAvanzado = enemigosAvanzado[i]->getVida();
				if (vidaAvanzado == 0) {
					ETSIDI::play("sonidos/fantasmamuerte.wav");
					enemigosAvanzado.eliminar(i);
				}
			}
		}
	}

	if (hombre.getVida() == 0) {

		ETSIDI::play("sonidos/gameover.wav");
		muerte = true;
		eyex = 7;
		nivel = 0;
	}
	//rotarOjo(); // Aqui veo que puedo usar una funcion dentro de otra

	if (poshom.y < (-10)) {
		
		hombre.setVida(hombre.getVida() - 1);
		Vector2D reinicio = hombre.getPos();
		hombre.setVel(0, 0);
		hombre.setPos(reinicio.x, reinicio.y + 20);
		
		if (hombre.getVida() != 0)
			ETSIDI::play("sonidos/caida.wav");
	}
	


	//condiciones para pasar de nivel
	if ((nivel == 1 || nivel == 2) && hombre.getLlaves() == 3 ) {
		if (hombre.Choque(hombre, puerta)) {
			FinNivel = true;
			ETSIDI::play("sonidos/victoria.mp3");
		}
	}
	}


void Mundo::tecla(unsigned char key) {
	
	Vector2D vel = hombre.getVel();
	switch (key){
	
	case ' ':


		if (plataformas.rebote(hombre)) {// Habilita el salto al estar encima de una plataforma
			hombre.Salto(10);
		}

		break;
	case 'j':
	case 'J':
		
		if (nivel==1)
			hombre.setPos(230, 5);

		if (nivel == 2)
			hombre.setPos(260, 10);

		break;



	case 'K':
	case 'k':

		hombre.setLlaves(3);;

		break;
	case 'a':
	case 'A':

		hombre.MovLateral(-5);
		if (verticales.rebote(hombre))
		{
			if ('d'||'D')
			{
				hombre.MovLateral(5);
			}
			else
				hombre.MovLateral(0);
		}

		if (plataformas.rebote(hombre)) {
			int flag = 100;
			if (flag==1000) {
				ETSIDI::play("sonidos/pasos.wav");
				flag = 0;
			}
			flag += 1;
		}
			

		orientacion = 0;

		break;

	case 'd':
	case 'D':
	
		hombre.MovLateral(5);
		if (verticales.rebote(hombre))
		{
			if ('a'||'A')
			{
				hombre.MovLateral(-5);
			}
			else
				hombre.MovLateral(0);
		}


		if (plataformas.rebote(hombre))
			ETSIDI::play("sonidos/pasos.wav");

		orientacion = 1;

		break;
	case 's':
	case 'S':
	{
		Vector2D pos = hombre.getPos();
		Disparo* d = new Disparo(orientacion,pos);
		if (orientacion == 1) d->setPos(pos.x+0.2f, pos.y - 1.0f);
		else d->setPos(pos.x-0.2f, pos.y - 1.0f);
		disparos.Agregar(d);
		ETSIDI::play("sonidos/flecha.wav");
		break;
	}
	}
}

void Mundo::teclaEspecial(unsigned char key){
	switch (key){
	}	
}

void Mundo::NoPresionoTecla(unsigned char key) {
	Vector2D vel = hombre.getVel();
	switch (key) {
	case 'd':
	case 'D':

		hombre.MovLateral(0);

		break;
	case 'a':
	case 'A':

		hombre.MovLateral(0);

		break;
	
	}
	
}

bool Mundo::cargarNivel()
{
	nivel++;
	FinNivel = false;
	// Eliminar todo (enemigos, corazones, monedas,Llaves...)
	plataformas.destruirContenido();
	disparos.DestruirContenido();
	enemigosAvanzado.destruirContenido();
	enemigosMedio.destruirContenido();
	enemigosBase.destruirContenido();
	monedas.destruirContenido();
	corazones.destruirContenido();
	llaves.destruirContenido();
	ETSIDI::stopMusica();
	hombre.setPos(0, 5);
	if (nivel == 1){
		ETSIDI::playMusica("sonidos/ambiente.mp3",true);
		
		Vida* c1 = new Vida(-5, 5);
		corazones.agregar(c1);

		Moneda* m1 = new Moneda(-3, 5);
		monedas.agregar(m1);

		Llave* l1 = new Llave(-7, 5);
		llaves.agregar(l1);
		Llave* l2 = new Llave(164, 8);
		llaves.agregar(l2);
		Llave* l3 = new Llave(222, 0);
		llaves.agregar(l3);
		EnemigoAvanzado* En10 = new EnemigoAvanzado;
		En10->setPos(39.0f, 5.0f);
		En10->setLimites(8.0f, 4.0f, 46.0f, 38.0f);
		enemigosAvanzado.agregar(En10);

		EnemigoAvanzado* En11 = new EnemigoAvanzado;
		En11->setPos(39.0f, 5.0f);
		En11->setLimites(8.0f, 4.0f, 110.0f, 100.0f);
		enemigosAvanzado.agregar(En11);

		EnemigoAvanzado* En12 = new EnemigoAvanzado;
		En12->setPos(39.0f, 4.0f);
		En12->setLimites(8.0f, 2.0f, 156.0f, 147.0f);
		enemigosAvanzado.agregar(En12);

		EnemigoAvanzado* En13 = new EnemigoAvanzado;
		En13->setPos(39.0f, 4.0f);
		En13->setLimites(14.0f, 9.0f, 186.0f, 178.0f);
		enemigosAvanzado.agregar(En13);
	
		EnemigoAvanzado* En14 = new EnemigoAvanzado;
		En14->setPos(39.0f, 4.0f);
		En14->setLimites(8.0f, 3.0f, 201.0f, 189.0f);
		enemigosAvanzado.agregar(En14);
	
		Pared* inferior1 = new Pared(-5, -2, 2, -2);
		plataformas.Agregar(inferior1);
	
		Moneda* m2 = new Moneda(2, 5);
		monedas.agregar(m2);

		Moneda* m3 = new Moneda(2, 3);
		monedas.agregar(m3);

		Pared* inferior2 = new Pared(4, -2, 10, -2);
		plataformas.Agregar(inferior2);

		Moneda* m4 = new Moneda(10, 5);
		monedas.agregar(m4);

		EnemigoBase* En = new EnemigoBase;
		En->setPos(5.0f, -1.0f);
		enemigosBase.agregar(En);

		Pared* inferior3 = new Pared(13, 3, 16, 3);
		plataformas.Agregar(inferior3);

		Moneda* m5 = new Moneda(14, 7);
		monedas.agregar(m5);

		Pared* inferior4 = new Pared(19, -2, 27, -2);
		plataformas.Agregar(inferior4);
	
		Vida* c3 = new Vida(20, 5);
		corazones.agregar(c3);

		Moneda* m6 = new Moneda(27, 5);
		monedas.agregar(m6);
	
		EnemigoMedio* En4 = new EnemigoMedio;
		En4->setPos(18.0f, 6.0f);
		enemigosMedio.agregar(En4);

		Pared* inferior5 = new Pared(30, 2, 35, 2);
		plataformas.Agregar(inferior5);

		Pared* inferior6 = new Pared(39, 1, 45, 1);
		plataformas.Agregar(inferior6);

		Moneda* m7 = new Moneda(42, 5);
		monedas.agregar(m7);
	
		Pared* inferior7 = new Pared(48, 5, 51, 5);
		plataformas.Agregar(inferior7);

		EnemigoMedio* En5 = new EnemigoMedio;
		En5->setPos(53.0f, 8.0f);
		enemigosMedio.agregar(En5);

		Pared* inferior8 = new Pared(55, 0, 60, 0);
		plataformas.Agregar(inferior8);

		Moneda* m8 = new Moneda(56, 5);
		monedas.agregar(m8);

		Vida* c4 = new Vida(58, 5);
		corazones.agregar(c4);

		Pared* inferior9 = new Pared(63.5, -2, 66.5, -2);
		plataformas.Agregar(inferior9);

		Moneda* m9 = new Moneda(65, 3);
		monedas.agregar(m9);
		
		Pared* inferior10 = new Pared(70, 2, 73, 2);
		plataformas.Agregar(inferior10);

		Moneda* m10 = new Moneda(71, 5);
		monedas.agregar(m10);

		Pared* inferior11 = new Pared(75, 4, 78, 4);
		plataformas.Agregar(inferior11);
	
		Moneda* m11 = new Moneda(75, 6);
		monedas.agregar(m11);

		Pared* inferior12 = new Pared(80, -2, 86, -2);
		plataformas.Agregar(inferior12);

		Moneda* m12 = new Moneda(83, 3);
		monedas.agregar(m12);

		EnemigoBase* En1 = new EnemigoBase;
		En1->setPos(84.0f, 0.0f);
		enemigosBase.agregar(En1);

		EnemigoMedio* En6 = new EnemigoMedio;
		En6->setPos(87.0f, 8.0f);
		enemigosMedio.agregar(En6);

		Pared* inferior13 = new Pared(88, 2, 90, 2);
		plataformas.Agregar(inferior13);

		Moneda* m13 = new Moneda(89, 5);
		monedas.agregar(m13);

		ParedVertical* inferior26 = new ParedVertical(92, 7, 92, 0); //vertical 
		verticales.Agregar(inferior26);

		Moneda* m14 = new Moneda(92, 8);
		monedas.agregar(m14);

		Pared* inferior14 = new Pared(94, 2, 97, 2);
		plataformas.Agregar(inferior14);

		Moneda* m15 = new Moneda(95, 5);
		monedas.agregar(m15);

		Pared* inferior15 = new Pared(100, 1, 110, 1);
		plataformas.Agregar(inferior15);

		Moneda* m16 = new Moneda(106, 6);
		monedas.agregar(m16);

		ParedVertical* inferior27 = new ParedVertical(113, 5, 113, -2); //vertical
		verticales.Agregar(inferior27);

		Pared* inferior16 = new Pared(117, 1, 120, 1);
		plataformas.Agregar(inferior16);

		Pared* inferior17 = new Pared(124.5, 4, 127.5, 4);
		plataformas.Agregar(inferior17);

		ParedVertical* inferior28 = new ParedVertical(130, 6, 130, -2); //vertical
		verticales.Agregar(inferior28);

		Moneda* m17 = new Moneda(130, 7);
		monedas.agregar(m17);

		Pared* inferior18 = new Pared(132, 1, 135, 1);
		plataformas.Agregar(inferior18);

		Moneda* m18 = new Moneda(137, 2);
		monedas.agregar(m18);

		EnemigoMedio* En7 = new EnemigoMedio;
		En7->setPos(137.0f, 8.0f);
		enemigosMedio.agregar(En7);

		Pared* inferior19 = new Pared(139, 4, 145, 4);
		plataformas.Agregar(inferior19);

		Vida* c5 = new Vida(142, 8);
		corazones.agregar(c5);

		EnemigoBase* En2 = new EnemigoBase;
		En2->setPos(141.0f, 5.0f);
		enemigosBase.agregar(En2);

		Pared* inferior20 = new Pared(148, -2, 155, -2);
		plataformas.Agregar(inferior20);

		Moneda* m19 = new Moneda(151, 3);
		monedas.agregar(m19);

		Pared* inferior21 = new Pared(158, 3, 162, 3);
		plataformas.Agregar(inferior21);

		Moneda* m20 = new Moneda(159, 6);
		monedas.agregar(m20);

		Moneda* m21 = new Moneda(161, 6);
		monedas.agregar(m21);

		ParedVertical* inferior29 = new ParedVertical(164, 5, 164, -2); //vertical
		verticales.Agregar(inferior29);

		Moneda* m22 = new Moneda(164, 6);
		monedas.agregar(m22);

		Pared* inferior22 = new Pared(165, 1, 175, 1);
		plataformas.Agregar(inferior22);

		Moneda* m23 = new Moneda(167, 3);
		monedas.agregar(m23);

		Moneda* m24 = new Moneda(169, 3);
		monedas.agregar(m24);

		Moneda* m25 = new Moneda(171, 3);
		monedas.agregar(m25);

		Pared* inferior23 = new Pared(179, 6, 185, 6);
		plataformas.Agregar(inferior23);

		Vida* c6 = new Vida(183, 8);
		corazones.agregar(c6);
	
		EnemigoMedio* En8 = new EnemigoMedio;
		En8->setPos(187.0f, 8.0f);
		enemigosMedio.agregar(En8); 

		Pared* inferior24 = new Pared(190, 0, 200, 0);
		plataformas.Agregar(inferior24);

		Moneda* m26 = new Moneda(195, 2);
		monedas.agregar(m26);

		Moneda* m27 = new Moneda(195, 4);
		monedas.agregar(m27);
		
		Pared* inferior25 = new Pared(204, 4, 210, 4);
		plataformas.Agregar(inferior25);

		EnemigoBase* En3 = new EnemigoBase;
		En3->setPos(207.0f, 4.0f);
		enemigosBase.agregar(En3);

		EnemigoMedio* En9 = new EnemigoMedio;
		En9->setPos(216.0f, 8.0f);
		enemigosMedio.agregar(En9);

		Pared* inferior30 = new Pared(218, -4, 238, -4);
		plataformas.Agregar(inferior30);

		Moneda* m28 = new Moneda(220, 3);
		monedas.agregar(m28);

		Moneda* m29 = new Moneda(222, 3);
		monedas.agregar(m29);

		Moneda* m33 = new Moneda(224, 0);
		monedas.agregar(m33);

		Moneda* m30 = new Moneda(226, 0);
		monedas.agregar(m30);

		Moneda* m31 = new Moneda(228, 0);
		monedas.agregar(m31);

		Moneda* m32 = new Moneda(230, 0);
		monedas.agregar(m32);

		puerta.setPos(231, -4, 237, 2.9);
	}


	if (nivel == 2){
		ETSIDI::playMusica("sonidos/ambiente.mp3", true);

		hombre.setLlaves(0);

		Llave* l1 = new Llave(8, 8.5);
		llaves.agregar(l1);
		Llave* l2 = new Llave(104, 5);
		llaves.agregar(l2);
		Llave* l3 = new Llave(247, 5);
		llaves.agregar(l3);
		Vida* c1 = new Vida(-5, 5);
		corazones.agregar(c1);

		Vida* c2 = new Vida(115, 8);
		corazones.agregar(c2);

		Vida* c3 = new Vida(210, 7);
		corazones.agregar(c3);

		Moneda* m1 = new Moneda(8, 8);
		monedas.agregar(m1);

		Moneda* m2 = new Moneda(33, 7);
		monedas.agregar(m2);

		Moneda* m3 = new Moneda(58, 9);
		monedas.agregar(m3);

		Moneda* m4 = new Moneda(78, 10);
		monedas.agregar(m4);

		Moneda* m5 = new Moneda(104, 4);
		monedas.agregar(m5);

		Moneda* m6 = new Moneda(172, 10);
		monedas.agregar(m6);

		Moneda* m7 = new Moneda(190, 2);
		monedas.agregar(m7);

		Moneda* m8 = new Moneda(247, 11);
		monedas.agregar(m8);

		EnemigoBase* En = new EnemigoBase;
		En->setPos(17.0f, 7.0f);
		enemigosBase.agregar(En);

		EnemigoBase* En1 = new EnemigoBase;
		En1->setPos(90.0f, 1.0f);
		enemigosBase.agregar(En1);

		EnemigoBase* En2 = new EnemigoBase;
		En2->setPos(139.0f, 2.0f);
		enemigosBase.agregar(En2);

		EnemigoBase* En3 = new EnemigoBase;
		En3->setPos(160.0f, 6.0f);
		enemigosBase.agregar(En3);

		EnemigoBase* En4 = new EnemigoBase;
		En4->setPos(172.0f, 9.0f);
		enemigosBase.agregar(En4);

		EnemigoBase* En5 = new EnemigoBase;
		En5->setPos(220.0f, 3.0f);
		enemigosBase.agregar(En5);

		EnemigoBase* En6 = new EnemigoBase;
		En6->setPos(243.0f, 4.0f);
		enemigosBase.agregar(En6);

		EnemigoMedio* En7 = new EnemigoMedio;
		En7->setPos(3.0f, 11.0f);
		enemigosMedio.agregar(En7);

		EnemigoMedio* En8 = new EnemigoMedio;
		En8->setPos(12.0f, 11.0f);
		enemigosMedio.agregar(En8);

		EnemigoMedio* En9 = new EnemigoMedio;
		En9->setPos(22.0f, 11.0f);
		enemigosMedio.agregar(En9);

		EnemigoMedio* En10 = new EnemigoMedio;
		En10->setPos(61.0f, 11.0f);
		enemigosMedio.agregar(En10);

		EnemigoMedio* En11 = new EnemigoMedio;
		En11->setPos(126.0f, 11.0f);
		enemigosMedio.agregar(En11);

		EnemigoMedio* En12 = new EnemigoMedio;
		En12->setPos(133.0f, 11.0f);
		enemigosMedio.agregar(En12);

		EnemigoMedio* En13 = new EnemigoMedio;
		En13->setPos(215.0f, 11.0f);
		enemigosMedio.agregar(En13);

		EnemigoMedio* En14 = new EnemigoMedio;
		En14->setPos(227.0f, 11.0f);
		enemigosMedio.agregar(En14);

		EnemigoAvanzado* En15 = new EnemigoAvanzado;
		En15->setPos(50.0f, 5.0f);
		En15->setLimites(5.0f, 2.0f, 54.0f, 40.0f);
		enemigosAvanzado.agregar(En15);

		EnemigoAvanzado* En16 = new EnemigoAvanzado;
		En16->setPos(114.0f, 6.0f);
		En16->setLimites(6.0f, 3.0f, 116.0f, 103.0f);
		enemigosAvanzado.agregar(En16);

		EnemigoAvanzado* En17 = new EnemigoAvanzado;
		En17->setPos(238.0f, 8.0f);
		En17->setLimites(11.0f, 8.0f, 237.0f, 230.0f);
		enemigosAvanzado.agregar(En17);

		EnemigoAvanzado* En18 = new EnemigoAvanzado;
		En18->setPos(250.0f, 12.0f);
		En18->setLimites(12.0f, 9.0f, 263.0f, 253.0f);
		enemigosAvanzado.agregar(En18);

		Pared* inferior1 = new Pared(-5, 1.01, 2, 1.01);
		plataformas.Agregar(inferior1);

		Pared* inferior2 = new Pared(5, 4.01, 10, 4.01);
		plataformas.Agregar(inferior2);

		Pared* inferior3 = new Pared(13, 6, 20, 6);
		plataformas.Agregar(inferior3);

		Pared* inferior4 = new Pared(26, 0, 30, 0);
		plataformas.Agregar(inferior4);

		Pared* inferior5 = new Pared(32, 4, 35, 4);
		plataformas.Agregar(inferior5);

		PlatMoviles* inferior6 = new PlatMoviles(39, 7, 43, 7); //movil
		plataformas.Agregar(inferior6);

		PlatMoviles* inferior7 = new PlatMoviles(45, 0, 51, 0); //movil
		plataformas.Agregar(inferior7);

		Pared* inferior8 = new Pared(55, 5, 60, 5);
		plataformas.Agregar(inferior8);

		Pared* inferior9 = new Pared(62, 5, 64, 5);
		plataformas.Agregar(inferior9);

		PlatMoviles* inferior10 = new PlatMoviles(68, 4, 72, 4); //movil
		plataformas.Agregar(inferior10);

		PlatMoviles* inferior11 = new PlatMoviles(75, 6, 78, 6); //movil
		plataformas.Agregar(inferior11);

		Pared* inferior12 = new Pared(83, 3, 86, 3);
		plataformas.Agregar(inferior12);

		Pared* inferior13 = new Pared(88, 0, 95, 0);
		plataformas.Agregar(inferior13);

		PlatMoviles* inferior14 = new PlatMoviles(97, 0, 100, 0); //movil
		plataformas.Agregar(inferior14);

		Pared* inferior15 = new Pared(103, 1.01, 116, 1.01);
		plataformas.Agregar(inferior15);

		PlatMoviles* inferior16 = new PlatMoviles(118, 4, 120, 4); //movil
		plataformas.Agregar(inferior16);

		Pared* inferior17 = new Pared(125, 6, 125, 0); //vertical
		plataformas.Agregar(inferior17);

		Pared* inferior18 = new Pared(127, 3, 130, 3);
		plataformas.Agregar(inferior18);

		Pared* inferior19 = new Pared(137, 0, 145, 0);
		plataformas.Agregar(inferior19);

		PlatMoviles* inferior20 = new PlatMoviles(148, 4, 150, 4); //movil
		plataformas.Agregar(inferior20);

		Pared* inferior21 = new Pared(156, 7, 156, 0); //vertical
		plataformas.Agregar(inferior21);

		Pared* inferior22 = new Pared(158, 5, 166, 5);
		plataformas.Agregar(inferior22);

		Pared* inferior23 = new Pared(170, 8, 180, 8);
		plataformas.Agregar(inferior23);

		PlatMoviles* inferior24 = new PlatMoviles(184, 4, 187, 4); //movil
		plataformas.Agregar(inferior24);

		PlatMoviles* inferior25 = new PlatMoviles(195, 0, 207, 0); //movil
		plataformas.Agregar(inferior25);

		Pared* inferior26 = new Pared(214, 4, 214, 0); //vertical
		plataformas.Agregar(inferior26);

		Pared* inferior27 = new Pared(217, 2, 225, 2);
		plataformas.Agregar(inferior27);

		Pared* inferior28 = new Pared(230, 6, 237, 6);
		plataformas.Agregar(inferior28);

		PlatMoviles* inferior29 = new PlatMoviles(240, 3, 248, 3);
		plataformas.Agregar(inferior29);

		Pared* inferior30 = new Pared(253, 7, 273, 7);
		plataformas.Agregar(inferior30);

		puerta.setPos(267, 7, 273, 13.9);
	}

	if (nivel <= 2){
		return true;
	}
	return false;
}

void Mundo::reset(){
	hombre.setMonedas(0);
	hombre.setVida(3);
	hombre.setLlaves(0);
	muerte = false;
	nivel = 0;

}
Mundo::~Mundo() {
	enemigosBase.destruirContenido();
	enemigosMedio.destruirContenido();
	enemigosAvanzado.destruirContenido();
	corazones.destruirContenido();
	monedas.destruirContenido();
	llaves.destruirContenido();
	disparos.DestruirContenido();
}