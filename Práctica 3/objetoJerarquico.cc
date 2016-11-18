//Archivo perteneciente a la P3 de Jorge Gutiérrez Segovia grupo C1
#include "objetoJerarquico.h"

// Constructor por defecto
ObjetoJerarquico::ObjetoJerarquico(){
}

// Método que dibuja el subidor de la silla
void ObjetoJerarquico::dibujarSubidor(){

	//glScalef(30.0, 30.0,30.0);
	glRotatef(90,0,1,0);
		//Apoyo
		glPushMatrix();
			glPushMatrix();
				glRotatef(90,0,0,1);
				glScalef(1.0,0.1,1.0);
				cubo.drawObjeto3d(Objeto3d::FILL,false);
			glPopMatrix();
			//Palanca
			glPushMatrix();
				glTranslatef(0.0,2.5,0.0);
				glScalef(0.1,4.0,0.1);
				cilindro.drawObjeto3d(Objeto3d::FILL,false);
			glPopMatrix();
		glPopMatrix();
}

// Método que dibuja la base de la silla
void ObjetoJerarquico::dibujarBase(){
			glPushMatrix();
				glTranslatef(4.5,4.5,0.0);
				glRotatef(115,0,0,1);
				glRotatef(90,0,1,0);
				dibujarSubidor();
			glPopMatrix();
			glPushMatrix();
				glScalef(1.0,7.0,1.0);
				glTranslatef(0.0,0.5,0.0);
				cilindro.drawObjeto3d(Objeto3d::FILL,false);
			glPopMatrix();
			glPushMatrix();
				glScalef(5.0,0.5,5.0);
				cubo.drawObjeto3d(Objeto3d::FILL,false);
			glPopMatrix();

}

// Método que dibuja el reposa pies de la silla
void ObjetoJerarquico::dibujarReposaPies(){
		glPushMatrix();
			glPushMatrix();
			//BARRA IZQUIERDA GRANDE
				glTranslatef(-1.0,2.65,-2.75);
				glRotatef(150,1,0,0);
				glScalef(0.1,5.0,0.1);
				cilindro.drawObjeto3d(Objeto3d::FILL,false);
			glPopMatrix();
			//BARRA DERECHA GRANDE
			glPushMatrix();
				glTranslatef(1.0,2.65,-2.75);
				glRotatef(150,1,0,0);
				glScalef(0.1,5.0,0.1);
				cilindro.drawObjeto3d(Objeto3d::FILL,false);
			glPopMatrix();
			//BARRA IZQUIERDA PEQUEÑA
			glPushMatrix();
				glTranslatef(-1.0,0.25,-1.25);
				glRotatef(135,1,0,0);
				glScalef(0.1,0.75,0.1);
				cilindro.drawObjeto3d(Objeto3d::FILL,false);
			glPopMatrix();
			//BARRA DERECHA PEQUEÑA
			glPushMatrix();
				glTranslatef(1.0,0.25,-1.25);
				glRotatef(135,1,0,0);
				glScalef(0.1,0.75,0.1);
				cilindro.drawObjeto3d(Objeto3d::FILL,false);
			glPopMatrix();
			//BASE
			glPushMatrix();
				glScalef(5.0,0.1,2.0);
				cubo.drawObjeto3d(Objeto3d::FILL,false);
			glPopMatrix();
		glPopMatrix();
}

// Método que dibuja un brazo de la silla
void ObjetoJerarquico::dibujarBrazo(){

	glRotatef(270,0,1,0);
	//Parte arriba
	glPushMatrix();
		glTranslatef(0.0,2.9,0.0);
		glRotatef(170,0,0,1);
		glScalef(5.0,0.2,1.5);
		cubo.drawObjeto3d(Objeto3d::FILL,false);
	glPopMatrix();
	//Parte izquierda
	glPushMatrix();
		glTranslatef(-2.4,2.0,0.0);
		glRotatef(90,0,0,1);
		glScalef(2.5,0.2,1.5);
		cubo.drawObjeto3d(Objeto3d::FILL,false);
	glPopMatrix();
	//Parte derecha
	glPushMatrix();
		glTranslatef(2.4,1.6,0.0);
		glRotatef(90,0,0,1);
		glScalef(1.7,0.2,1.5);
		cubo.drawObjeto3d(Objeto3d::FILL,false);
	glPopMatrix();
	//Base
	glPushMatrix();
		glScalef(5.0,1.5,1.5);
		cubo.drawObjeto3d(Objeto3d::FILL,false);
	glPopMatrix();
}

// Método que dibuja el asiento de la silla
void ObjetoJerarquico::dibujarAsiento(){

	//Asiento
	glPushMatrix();
		glScalef(13.0,1.5,10.0);
		cubo.drawObjeto3d(Objeto3d::FILL,false);
	glPopMatrix();
}

// Método que dibuja el respaldo de la silla
// y los brazos
void ObjetoJerarquico::dibujarRespaldo(){

	//Brazo izquierdo
	glPushMatrix();
		glTranslatef(-7.2,-5.8,4.9);
		glScalef(1.0,1.0,1.8);
		dibujarBrazo();
	glPopMatrix();
	//Brazo derecho
	glPushMatrix();
		glTranslatef(7.2,-5.8,4.9);
		glScalef(1.0,1.0,1.8);
		dibujarBrazo();
	glPopMatrix();
	//Cabezal
	glPushMatrix();
		glTranslatef(0.0,8.5,0.0);
		glRotatef(90,1,0,0);
		glScalef(4.0,1.5,4.0);
		cubo.drawObjeto3d(Objeto3d::FILL,false);
	glPopMatrix();
	//Respaldo
	glPushMatrix();
		glRotatef(90,1,0,0);
		glScalef(13.0,1.5,13.0);
		cubo.drawObjeto3d(Objeto3d::FILL,false);
	glPopMatrix();
}

//Método que dibuja la silla completa
void ObjetoJerarquico::dibujarSilla(){

	glScalef(10.0,10.0,10.0);
	//Respaldo
	glPushMatrix();
		glTranslatef(0.0,5.8,-5.7);
		dibujarRespaldo();
	glPopMatrix();
	//ReposaPies
	glPushMatrix();
		glTranslatef(0.0,-5.65,8.25);
		dibujarReposaPies();
	glPopMatrix();
	//Base con subidor
	glPushMatrix();
		glTranslatef(0.0,-7.8,0.0);
		dibujarBase();
	glPopMatrix();
	//Asiento
	glPushMatrix();
		dibujarAsiento();
	glPopMatrix();
}
