#include "mundo.h"
#include "math.h"
#include "freeglut.h"
#include "ETSIDI.h"

Mundo::Mundo() {
	FinNivel = false;
	muerte = false;
	nivel = 0;
}

void Mundo::rotarOjo() {

	float DistY;
	DistY = sqrt(pow(eyex - lookx, 2) + pow(eyey - looky, 2));
	float theta;
	theta = atan2(eyey, eyex);
	theta += 0.025;

	eyex = DistY * cos(theta);
	eyey = DistY * sin(theta);

}

void Mundo::MoverCamara() {

	float DistY;
	DistY = sqrt(pow(eyex - lookx, 2) + pow(eyey - looky, 2));
	float theta;
	theta = atan2(eyey, eyex); 
	theta += 0.025;

	eyex = DistY * cos(theta);
	eyey = DistY * sin(theta);

}

void Mundo::inicializa() {
	  // posicion del ojo
	
	FinNivel = false;
	muerte = false;

	hombre.setPos(0, 5);
	hombre.setAc(0, -9.8);
	enemigo.setPos(9.0f, 2.0f);
	enemigo1.setPos(84.0f, 2.0f);
	enemigo2.setPos(141.0f, 7.0f);
	enemigo3.setPos(207.0f, 7.0f);

	cargarNivel();
}

void Mundo::dibuja() {

	Vector2D posh = hombre.getPos();
	eyex = posh.x;
	eyey = posh.y;

	gluLookAt(eyex, 10, 30,  // posicion del ojo
		eyex, 0, 0,      // hacia que punto mira  (0,0,0) 
		0.0, 1.0, 0.0);

	hombre.Dibuja();
	plataformas.Dibuja();
	enemigo.dibuja();
	enemigo1.dibuja();
	enemigo2.dibuja();
	enemigo3.dibuja();
	
	glEnable(GL_TEXTURE_2D);
	if (GetNivel() == 1) {
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/fondo.png").id); //cambiar imagen de fondo por queeeee que fea
		glDisable(GL_LIGHTING);
		glBegin(GL_POLYGON);
		glColor3f(1, 1, 1);
		glTexCoord2d(0, 1); glVertex3f(-50, -10, -5);
		glTexCoord2d(1, 1); glVertex3f(250, -10, -5);
		glTexCoord2d(1, 0); glVertex3f(250, 50, -5);
		glTexCoord2d(0, 0); glVertex3f(-50, 50, -5);
		glEnd();
		glEnable(GL_LIGHTING);
		glDisable(GL_TEXTURE_2D);
	}
	if (GetNivel() == 2) {
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/fondo.jpg").id); //cambiar tmbn
		glDisable(GL_LIGHTING);
		glBegin(GL_POLYGON);
		glColor3f(1, 1, 1);
		glTexCoord2d(0, 1); glVertex3f(-50, -10, -5);
		glTexCoord2d(1, 1); glVertex3f(300, -10, -5);
		glTexCoord2d(1, 0); glVertex3f(300, 50, -5);
		glTexCoord2d(0, 0); glVertex3f(-50, 50, -5);
		glEnd();
		glEnable(GL_LIGHTING);
		glDisable(GL_TEXTURE_2D);
	}
}

void Mundo::mueve() {
	Vector2D poshom = hombre.getPos();

	hombre.mueve(0.025f);
	plataformas.rebote(hombre);
	enemigo.mueve(0.025f);
	enemigo1.mueve(0.025f);
	enemigo2.mueve(0.025f);
	enemigo3.mueve(0.025f);
	plataformas.Mueve(0.001f);
	plataformas.rebote(enemigo);
	plataformas.rebote(enemigo1);
	plataformas.rebote(enemigo2);
	plataformas.rebote(enemigo3);
	if (Interaccion::contacto(hombre, enemigo) == 0 || Interaccion::contacto(hombre, enemigo1) == 0) {
		muerte = true;
		eyex = 7;
		nivel--;
		cargarNivel();
	}

	if (Interaccion::contacto(hombre, enemigo2) == 0 || Interaccion::contacto(hombre, enemigo3) == 0) {
		muerte = true;
		eyex = 7;
		nivel--;
		cargarNivel();
	}
	//rotarOjo(); // Aqui veo que puedo usar una funcion dentro de otra

	if (poshom.y < (-3)) {
		muerte = true;
		eyex = 7;
		nivel--;
		cargarNivel();
	}


	//condiciones para pasar de nivel
	if (nivel == 1) {
		
	}
}

void Mundo::tecla(unsigned char key) {
	switch (key){
	
	case ' ':

		if (plataformas.rebote(hombre)) {// Definir algo que cuando este en el "suelo" pueda saltar otra vez
			hombre.Salto(10);
		}

		break;
	case 'a':
		
		hombre.MovLateral(-5);

		//dispder = 0;
		break;

	case 'd':
		
		hombre.MovLateral(5);

		break;

	}

}

void Mundo::NoPresionoTecla(unsigned char key) {
	switch (key) {
	case 'd':

		hombre.MovLateral(0);

		break;
	case 'a':

		hombre.MovLateral(0);

		break;
	case ' ':

		hombre.Salto(0);

		break;
	}
	
}

bool Mundo::cargarNivel()
{
	nivel++;
	FinNivel = false;

	if (nivel == 1)
	{
		Pared* inferior1 = new Pared(-5, 1.01, 2, 1.01);
		inferior1->setColor(0, 200, 0);
		plataformas.Agregar(inferior1);

		Pared* inferior2 = new Pared(4, 1.01, 10, 1.01);
		inferior2->setColor(0, 200, 0);
		plataformas.Agregar(inferior2);
	
		Pared* inferior3 = new Pared(14, 5, 16, 5);
		inferior3->setColor(0, 200, 0);
		plataformas.Agregar(inferior3);

		Pared* inferior4 = new Pared(19, 0, 27, 0);
		inferior4->setColor(0, 200, 0);
		plataformas.Agregar(inferior4);

		Pared* inferior5 = new Pared(30, 4, 35, 4);
		inferior5->setColor(0, 200, 0);
		plataformas.Agregar(inferior5);

		Pared* inferior6 = new Pared(39, 3, 45, 3);
		inferior6->setColor(0, 200, 0);
		plataformas.Agregar(inferior6);

		Pared* inferior7 = new Pared(48, 7, 51, 7);
		inferior7->setColor(0, 200, 0);
		plataformas.Agregar(inferior7);

		Pared* inferior8 = new Pared(55, 2, 60, 2);
		inferior8->setColor(0, 200, 0);
		plataformas.Agregar(inferior8);

		Pared* inferior9 = new Pared(64, 0, 66, 0);
		inferior9->setColor(0, 200, 0);
		plataformas.Agregar(inferior9);

		Pared* inferior10 = new Pared(70, 4, 73, 4);
		inferior10->setColor(0, 200, 0);
		plataformas.Agregar(inferior10);

		Pared* inferior11 = new Pared(75, 6, 78, 6);
		inferior11->setColor(0, 200, 0);
		plataformas.Agregar(inferior11);

		Pared* inferior12 = new Pared(80, 0, 86, 0);
		inferior12->setColor(0, 200, 0);
		plataformas.Agregar(inferior12);

		Pared* inferior13 = new Pared(88, 4, 90, 4);
		inferior13->setColor(0, 200, 0);
		plataformas.Agregar(inferior13);

		Pared* inferior26 = new Pared(92, 7, 92, 0); //vertical
		inferior26->setColor(0, 200, 0);
		plataformas.Agregar(inferior26);

		Pared* inferior14 = new Pared(94, 4, 97, 4);
		inferior14->setColor(0, 200, 0);
		plataformas.Agregar(inferior14);

		Pared* inferior15 = new Pared(100, 3, 110, 3);
		inferior15->setColor(0, 200, 0);
		plataformas.Agregar(inferior15);

		Pared* inferior27 = new Pared(113, 7, 113, 0); //vertical
		inferior27->setColor(0, 200, 0);
		plataformas.Agregar(inferior27);

		Pared* inferior16 = new Pared(117, 3, 120, 3);
		inferior16->setColor(0, 200, 0);
		plataformas.Agregar(inferior16);

		Pared* inferior17 = new Pared(125, 6, 127, 6);
		inferior17->setColor(0, 200, 0);
		plataformas.Agregar(inferior17);

		Pared* inferior28 = new Pared(130, 8, 130, 0); //vertical
		inferior28->setColor(0, 200, 0);
		plataformas.Agregar(inferior28);

		Pared* inferior18 = new Pared(132, 3, 135, 3);
		inferior18->setColor(0, 200, 0);
		plataformas.Agregar(inferior18);

		Pared* inferior19 = new Pared(139, 6, 145, 6);
		inferior19->setColor(0, 200, 0);
		plataformas.Agregar(inferior19);

		Pared* inferior20 = new Pared(148, 0, 155, 0);
		inferior20->setColor(0, 200, 0);
		plataformas.Agregar(inferior20);

		Pared* inferior21 = new Pared(158, 6, 162, 6);
		inferior21->setColor(0, 200, 0);
		plataformas.Agregar(inferior21);

		Pared* inferior29 = new Pared(164, 8, 164, 0); //vertical
		inferior29->setColor(0, 200, 0);
		plataformas.Agregar(inferior29);

		Pared* inferior22 = new Pared(165, 3, 175, 3);
		inferior22->setColor(0, 200, 0);
		plataformas.Agregar(inferior22);

		Pared* inferior23 = new Pared(179, 8, 185, 8);
		inferior23->setColor(0, 200, 0);
		plataformas.Agregar(inferior23);

		Pared* inferior24 = new Pared(190, 2, 200, 2);
		inferior24->setColor(0, 200, 0);
		plataformas.Agregar(inferior24);

		Pared* inferior25 = new Pared(204, 6, 210, 6);
		inferior25->setColor(0, 200, 0);
		plataformas.Agregar(inferior25);

		Pared* inferior30 = new Pared(218, 0, 238, 0);
		inferior30->setColor(0, 200, 0);
		plataformas.Agregar(inferior30);
	}

	if (nivel == 2)
	{
		Pared* inferior1 = new Pared(-5, 1.01, 2, 1.01);
		inferior1->setColor(0, 0, 200);
		plataformas.Agregar(inferior1);

		Pared* inferior2 = new Pared(5, 4.01, 10, 4.01);
		inferior2->setColor(0, 0, 200);
		plataformas.Agregar(inferior2);

		Pared* inferior3 = new Pared(13, 6, 20, 6);
		inferior3->setColor(0, 0, 200);
		plataformas.Agregar(inferior3);

		Pared* inferior4 = new Pared(26, 0, 30, 0);
		inferior4->setColor(0, 0, 200);
		plataformas.Agregar(inferior4);

		Pared* inferior5 = new Pared(32, 4, 35, 4);
		inferior5->setColor(0, 0, 200);
		plataformas.Agregar(inferior5);

		PlatMoviles* inferior6 = new PlatMoviles(37, 7, 43, 7); //será movil
		inferior6->setColor(0, 0, 200);
		plataformas.Agregar(inferior6);

		PlatMoviles* inferior7 = new PlatMoviles(45, 0, 51, 0); //será movil
		inferior7->setColor(0, 200, 0);
		plataformas.Agregar(inferior7);

		Pared* inferior8 = new Pared(55, 5, 60, 5);
		inferior8->setColor(0, 0, 200);
		plataformas.Agregar(inferior8);

		Pared* inferior9 = new Pared(62, 5, 64, 5);
		inferior9->setColor(0, 0, 200);
		plataformas.Agregar(inferior9);

		PlatMoviles* inferior10 = new PlatMoviles(68, 4, 73, 4); //será movil
		inferior10->setColor(0, 0, 200);
		plataformas.Agregar(inferior10);

		PlatMoviles* inferior11 = new PlatMoviles(75, 6, 78, 6); //será movil
		inferior11->setColor(0, 0, 200);
		plataformas.Agregar(inferior11);

		Pared* inferior12 = new Pared(83, 3, 86, 3);
		inferior12->setColor(0, 0, 200);
		plataformas.Agregar(inferior12);

		Pared* inferior13 = new Pared(88, 0, 95, 0);
		inferior13->setColor(0, 0, 200);
		plataformas.Agregar(inferior13);

		PlatMoviles* inferior14 = new PlatMoviles(97, 0, 100, 0); //será movil
		inferior14->setColor(0, 0, 200);
		plataformas.Agregar(inferior14);

		Pared* inferior15 = new Pared(103, 1.01, 116, 1.01);
		inferior15->setColor(0, 0, 200);
		plataformas.Agregar(inferior15);

		Pared* inferior16 = new Pared(118, 4, 122, 4);
		inferior16->setColor(0, 0, 200);
		plataformas.Agregar(inferior16);

		Pared* inferior17 = new Pared(125, 6, 125, 0); //vertical
		inferior17->setColor(0, 0, 200);
		plataformas.Agregar(inferior17);

		PlatMoviles* inferior18 = new PlatMoviles(127, 3, 130, 3); //movil
		inferior18->setColor(0, 0, 200);
		plataformas.Agregar(inferior18);

		Pared* inferior19 = new Pared(137, 0, 145, 0);
		inferior19->setColor(0, 0, 200);
		plataformas.Agregar(inferior19);

		PlatMoviles* inferior20 = new PlatMoviles(148, 4, 152, 4); //movil
		inferior20->setColor(0, 0, 200);
		plataformas.Agregar(inferior20);

		Pared* inferior21 = new Pared(156, 7, 156, 0); //vertical
		inferior21->setColor(0, 0, 200);
		plataformas.Agregar(inferior21);

		Pared* inferior22 = new Pared(158, 5, 166, 5);
		inferior22->setColor(0, 0, 200);
		plataformas.Agregar(inferior22);

		Pared* inferior23 = new Pared(170, 8, 180, 8);
		inferior23->setColor(0, 0, 200);
		plataformas.Agregar(inferior23);

		PlatMoviles* inferior24 = new PlatMoviles(184, 4, 190, 4); //movil
		inferior24->setColor(0, 0, 200);
		plataformas.Agregar(inferior24);

		PlatMoviles* inferior25 = new PlatMoviles(195, 0, 210, 0); //movil
		inferior25->setColor(0, 0, 200);
		plataformas.Agregar(inferior25);

		Pared* inferior26 = new Pared(214, 4, 214, 0); //vertical
		inferior26->setColor(0, 0, 200);
		plataformas.Agregar(inferior26);

		Pared* inferior27 = new Pared(217, 2, 225, 2);
		inferior27->setColor(0, 0, 200);
		plataformas.Agregar(inferior27);

		Pared* inferior28 = new Pared(230, 6, 237, 6);
		inferior28->setColor(0, 0, 200);
		plataformas.Agregar(inferior28);

		PlatMoviles* inferior29 = new PlatMoviles(240, 3, 248, 3);
		inferior29->setColor(0, 0, 200);
		plataformas.Agregar(inferior29);

		Pared* inferior30 = new Pared(253, 7, 273, 7);
		inferior30->setColor(0, 0, 200);
		plataformas.Agregar(inferior30);
	}

	if (nivel <= 2)
	{
		return true;
	}
	return false;
}

void Mundo::reset()
{
	nivel = 1;
}