#include "VidaHUD.h"
#include "freeglut.h"

VidaHUD::VidaHUD() //Constructor
{

	barra.setSize(12, 8);
	barra.setCenter(6, 4);
}

VidaHUD::~VidaHUD() //Destructor
{

}


void VidaHUD::Dibuja(Hombre h)
{
	Vector2D posicion = h.getPos();

	glPushMatrix();
	glTranslatef(posicion.x-10, 9, 0);
	glColor3f(1.0f, 0.0f, 0.0f);

	if (h.getVida() == 1) barra.setState(2);

	if (h.getVida() == 2) barra.setState(1);

	if (h.getVida() == 3) barra.setState(0);

	barra.draw();

	glPopMatrix();


}

