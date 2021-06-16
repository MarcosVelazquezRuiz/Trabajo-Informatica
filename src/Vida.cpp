#include <Vida.h>


Vida::Vida(float x, float y) {

	posicion.x = x;
	posicion.y = y;
	radio = 3.0f;
	
	vida.setSize(3, 3);
	vida.setCenter(1.5, 1.5);
}
Vida::~Vida() {

}
void Vida::dibuja() {
	
	glPushMatrix();
	glTranslatef(posicion.x, posicion.y, 0);
	vida.draw();
	glPopMatrix();

}
void Vida::setPos(float x, float y) {

	posicion.x = x;
	posicion.y = y;
}
void Vida::setRadio(float r) {

	radio = r;
}
void Vida::mueve() {
	vida.loop();
}