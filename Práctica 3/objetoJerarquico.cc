//Archivo perteneciente a la P3 de Jorge Gutiérrez Segovia grupo C1
#include "objetoJerarquico.h"

// Constructor por defecto
ObjetoJerarquico::ObjetoJerarquico(){
}

// Método que dibuja el subidor de la silla
void ObjetoJerarquico::dibujarSubidor(bool ajedrez){

	glPushMatrix();
		glRotatef(90,0,1,0);
		//Apoyo
		glPushMatrix();
			glPushMatrix();
				glRotatef(90,0,0,1);
				glScalef(1.0,0.1,1.0);
				cubo.cambiarColor(0.5,0.5,0.5);
				cubo.drawObjeto3d(Objeto3d::LINE,ajedrez);
				cubo.cambiarColor(0.0,0.0,0.0);
				cubo.drawObjeto3d(Objeto3d::FILL,ajedrez);
			glPopMatrix();
			//Palanca
			glPushMatrix();
				glTranslatef(0.0,2.5,0.0);
				glScalef(0.1,4.0,0.1);
				cilindro.drawObjeto3d(Objeto3d::FILL,ajedrez);
			glPopMatrix();
		glPopMatrix();
	glPopMatrix();
}

// Método que dibuja la base de la silla
void ObjetoJerarquico::dibujarBase(int traslacion, bool ajedrez){
	glPushMatrix();
		glTranslatef(4.5,4.5,0.0);
		glRotatef(115,0,0,1);
		glRotatef(90,0,1,0);
		dibujarSubidor(ajedrez);
	glPopMatrix();
	glPushMatrix();
		glScalef(1.0,(7.0 + (traslacion*1.0)),1.0);
		glTranslatef(0.0,0.5,0.0);
		cilindro.drawObjeto3d(Objeto3d::FILL,ajedrez);
	glPopMatrix();
	glPushMatrix();
		glScalef(5.0,0.5,5.0);
		cubo.cambiarColor(0.0,0.0,0.0);
		cubo.drawObjeto3d(Objeto3d::LINE,ajedrez);
		cubo.cambiarColor(0.5,0.5,0.5);
		cubo.drawObjeto3d(Objeto3d::FILL,ajedrez);
	glPopMatrix();

}

// Método que dibuja el reposa pies de la silla
void ObjetoJerarquico::dibujarReposaPies(bool ajedrez){

		glPushMatrix();
			glPushMatrix();
			//BARRA IZQUIERDA GRANDE
				glTranslatef(-1.0,2.65,-2.75);
				glRotatef(150,1,0,0);
				glScalef(0.1,5.0,0.1);
				cilindro.drawObjeto3d(Objeto3d::FILL,ajedrez);
			glPopMatrix();
			//BARRA DERECHA GRANDE
			glPushMatrix();
				glTranslatef(1.0,2.65,-2.75);
				glRotatef(150,1,0,0);
				glScalef(0.1,5.0,0.1);
				cilindro.drawObjeto3d(Objeto3d::FILL,ajedrez);
			glPopMatrix();
			//BARRA IZQUIERDA PEQUEÑA
			glPushMatrix();
				glTranslatef(-1.0,0.25,-1.25);
				glRotatef(135,1,0,0);
				glScalef(0.1,0.75,0.1);
				cilindro.drawObjeto3d(Objeto3d::FILL,ajedrez);
			glPopMatrix();
			//BARRA DERECHA PEQUEÑA
			glPushMatrix();
				glTranslatef(1.0,0.25,-1.25);
				glRotatef(135,1,0,0);
				glScalef(0.1,0.75,0.1);
				cilindro.drawObjeto3d(Objeto3d::FILL,ajedrez);
			glPopMatrix();
			//BASE
			glPushMatrix();
				glScalef(5.0,0.1,2.0);
				cubo.cambiarColor(0.0,0.0,0.0);
				cubo.drawObjeto3d(Objeto3d::LINE,ajedrez);
				cubo.cambiarColor(0.5,0.5,0.5);
				cubo.drawObjeto3d(Objeto3d::FILL,ajedrez);
			glPopMatrix();
		glPopMatrix();
}

// Método que dibuja un brazo de la silla
void ObjetoJerarquico::dibujarBrazo(bool ajedrez){

	glPushMatrix();
		glRotatef(270,0,1,0);
		//Parte arriba
		glPushMatrix();
			glTranslatef(0.0,2.9,0.0);
			glRotatef(170,0,0,1);
			glScalef(5.0,0.2,1.5);
			cubo.cambiarColor(0.35,0.29,0.0);
			cubo.drawObjeto3d(Objeto3d::LINE,ajedrez);
			cubo.cambiarColor(0.0,0.0,0.0);
			cubo.drawObjeto3d(Objeto3d::FILL,ajedrez);
		glPopMatrix();
		//Parte izquierda
		glPushMatrix();
			glTranslatef(-2.4,2.0,0.0);
			glRotatef(90,0,0,1);
			glScalef(2.5,0.2,1.5);
			cubo.cambiarColor(0.35,0.29,0.0);
			cubo.drawObjeto3d(Objeto3d::LINE,ajedrez);
			cubo.cambiarColor(0.0,0.0,0.0);
			cubo.drawObjeto3d(Objeto3d::FILL,ajedrez);
		glPopMatrix();
		//Parte derecha
		glPushMatrix();
			glTranslatef(2.4,1.6,0.0);
			glRotatef(90,0,0,1);
			glScalef(1.7,0.2,1.5);
			cubo.cambiarColor(0.35,0.29,0.0);
			cubo.drawObjeto3d(Objeto3d::LINE,ajedrez);
			cubo.cambiarColor(0.0,0.0,0.0);
			cubo.drawObjeto3d(Objeto3d::FILL,ajedrez);
		glPopMatrix();
		//Base
		glPushMatrix();
			glScalef(5.0,1.5,1.5);
			cubo.cambiarColor(0.35,0.29,0.0);
			cubo.drawObjeto3d(Objeto3d::LINE,ajedrez);
			cubo.cambiarColor(0.0,0.0,0.0);
			cubo.drawObjeto3d(Objeto3d::FILL,ajedrez);
		glPopMatrix();
	glPopMatrix();
}

// Método que dibuja el asiento de la silla
void ObjetoJerarquico::dibujarAsiento(int traslacion, bool ajedrez){

	//Asiento
	glPushMatrix();
		glTranslatef(0.0, (traslacion*1.0), 0.0);
		glScalef(13.0,1.5,10.0);
		cubo.cambiarColor(0.0,0.0,0.0);
		cubo.drawObjeto3d(Objeto3d::LINE,ajedrez);
		cubo.cambiarColor(0.5,0.35,0.05);
		cubo.drawObjeto3d(Objeto3d::FILL,ajedrez);
	glPopMatrix();
}

// Método que dibuja el respaldo de la silla
// y los brazos
void ObjetoJerarquico::dibujarRespaldo(bool ajedrez){

	//Brazo izquierdo
	glPushMatrix();
		glTranslatef(-7.2,-5.8,4.9);
		glScalef(1.0,1.0,1.8);
		dibujarBrazo(ajedrez);
	glPopMatrix();
	//Brazo derecho
	glPushMatrix();
		glTranslatef(7.2,-5.8,4.9);
		glScalef(1.0,1.0,1.8);
		dibujarBrazo(ajedrez);
	glPopMatrix();
	//Cabezal
	glPushMatrix();
		glTranslatef(0.0,8.5,0.0);
		glRotatef(90,1,0,0);
		glScalef(4.0,1.5,4.0);
		cubo.cambiarColor(0.0,0.0,0.0);
		cubo.drawObjeto3d(Objeto3d::LINE,ajedrez);
		cubo.cambiarColor(0.5,0.35,0.05);
		cubo.drawObjeto3d(Objeto3d::FILL,ajedrez);
	glPopMatrix();
	//Respaldo
	glPushMatrix();
		glRotatef(90,1,0,0);
		glScalef(13.0,1.5,13.0);
		cubo.cambiarColor(0.0,0.0,0.0);
		cubo.drawObjeto3d(Objeto3d::LINE,ajedrez);
		cubo.cambiarColor(0.5,0.35,0.05);
		cubo.drawObjeto3d(Objeto3d::FILL,ajedrez);
	glPopMatrix();
}

//Método que dibuja la silla completa
void ObjetoJerarquico::dibujarSilla(float angulo1, float angulo2, int traslacion, bool ajedrez){
	glPushMatrix();
		glScalef(5.0,5.0,5.0);
		//Base con subidor
		glPushMatrix();
			glTranslatef(0.0,-7.8,0.0);
			dibujarBase(traslacion, ajedrez);
		glPopMatrix();
			glPushMatrix();
				glRotatef(angulo1, 0,1,0);
				glPushMatrix();
					glRotatef(angulo2,1,0,0);
					//Respaldo
					glPushMatrix();
						glTranslatef(0.0, 5.8+(traslacion*1.0),-5.7);
						dibujarRespaldo(ajedrez);
					glPopMatrix();
					//ReposaPies
					glPushMatrix();
						glTranslatef(0.0,-5.65+(traslacion*1.0),8.25);
						dibujarReposaPies(ajedrez);
					glPopMatrix();
				glPopMatrix();
				//Asiento
				glPushMatrix();
					dibujarAsiento(traslacion,ajedrez);
				glPopMatrix();
		glPopMatrix();
	glPopMatrix();
}
