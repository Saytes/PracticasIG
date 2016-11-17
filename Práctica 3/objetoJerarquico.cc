//Archivo perteneciente a la P3 de Jorge Gutiérrez Segovia grupo C1
#include "objetoJerarquico.h"

// Constructor por defecto
ObjetoJerarquico::ObjetoJerarquico(){
}

// Método que dibuja el subidor de la silla
void ObjetoJerarquico::dibujarSubidor(){

	glRotatef(90,0,1,0);
		glPushMatrix();
			glPushMatrix();
				glRotatef(90,0,0,1);
				glScalef(1.0,0.1,1.0);
				cubo.drawObjeto3d(Objeto3d::LINE,false);
			glPopMatrix();
			glPushMatrix();
				glScalef(0.1,1.0,0.1);
				glTranslatef(0.0,1.0,0.0);
				cilindro.drawObjeto3d(Objeto3d::FILL,false);
			glPopMatrix();
		glPopMatrix();
}

// Método que dibuja la base de la silla
void ObjetoJerarquico::dibujarBase(){
			glPushMatrix();
				glTranslatef(1.5,0.0,0.0);
				glTranslatef(0.0,3.0,0.0);
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
/*BASE PUESTA EN ASIENTO
glPushMatrix();
	glTranslatef(0.0,-7.8,0.0);
	dibujarBase();
glPopMatrix();*/

// Método que dibuja el asiento de la silla
void ObjetoJerarquico::dibujarAsiento(){

	glPushMatrix();
		//ReposaPies
		glPushMatrix();
			glTranslatef(0.0,-5.65,7.25);
			dibujarReposaPies();
		glPopMatrix();
		//Asiento
		glPushMatrix();
			glScalef(8.0,1.5,8.0);
			cubo.drawObjeto3d(Objeto3d::LINE,false);
		glPopMatrix();
	glPopMatrix();
}

// Método que dibuja un brazo de la silla
void ObjetoJerarquico::dibujarBrazo(){

}

// Método que dibuja el respaldo de la silla
void ObjetoJerarquico::dibujarRespaldo(){

}
