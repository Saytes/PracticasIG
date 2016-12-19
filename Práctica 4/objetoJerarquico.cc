//Archivo perteneciente a la P3 de Jorge Gutiérrez Segovia grupo C1
#include "objetoJerarquico.h"

// Constructor por defecto
ObjetoJerarquico::ObjetoJerarquico(){
}

// Método que dibuja el subidor de la silla
void ObjetoJerarquico::dibujarSubidor(bool ajedrez,Objeto3d::TipoPoligono polygon){

	glPushMatrix();
		glRotatef(90,0,1,0);
		//Apoyo
		glPushMatrix();
			glPushMatrix();
				glRotatef(90,0,0,1);
				glScalef(1.0,0.1,1.0);
				if(polygon == Objeto3d::FILL){
					cubo.cambiarColor(0.5,0.5,0.5);
					cubo.drawObjeto3d(Objeto3d::LINE,ajedrez);
				}
				cubo.cambiarColor(0.0,0.0,0.0);
				cubo.drawObjeto3d(polygon,ajedrez);
			glPopMatrix();
			//Palanca
			glPushMatrix();
				glTranslatef(0.0,2.5,0.0);
				glScalef(0.1,4.0,0.1);
				cilindro.drawObjeto3d(polygon,ajedrez);
			glPopMatrix();
		glPopMatrix();
	glPopMatrix();
}

// Método que dibuja la base de la silla
void ObjetoJerarquico::dibujarBase(int traslacion, bool ajedrez,Objeto3d::TipoPoligono polygon){
	glPushMatrix();
		glTranslatef(4.5,4.5,0.0);
		glRotatef(115,0,0,1);
		glRotatef(90,0,1,0);
		dibujarSubidor(ajedrez,polygon);
	glPopMatrix();
	glPushMatrix();
		glScalef(1.0,(7.0 + (traslacion*1.0)),1.0);
		glTranslatef(0.0,0.5,0.0);
		cilindro.drawObjeto3d(polygon,ajedrez);
	glPopMatrix();
	glPushMatrix();
		glScalef(5.0,0.5,5.0);
		if(polygon == Objeto3d::FILL){
			cubo.cambiarColor(0.0,0.0,0.0);
			cubo.drawObjeto3d(Objeto3d::LINE,ajedrez);
		}
		cubo.cambiarColor(0.5,0.5,0.5);
		cubo.drawObjeto3d(polygon,ajedrez);
	glPopMatrix();

}

// Método que dibuja el reposa pies de la silla
void ObjetoJerarquico::dibujarReposaPies(bool ajedrez,Objeto3d::TipoPoligono polygon){

		glPushMatrix();
			glPushMatrix();
			//BARRA IZQUIERDA GRANDE
				glTranslatef(-1.0,2.65,-2.75);
				glRotatef(150,1,0,0);
				glScalef(0.1,5.0,0.1);
				cilindro.drawObjeto3d(polygon,ajedrez);
			glPopMatrix();
			//BARRA DERECHA GRANDE
			glPushMatrix();
				glTranslatef(1.0,2.65,-2.75);
				glRotatef(150,1,0,0);
				glScalef(0.1,5.0,0.1);
				cilindro.drawObjeto3d(polygon,ajedrez);
			glPopMatrix();
			//BARRA IZQUIERDA PEQUEÑA
			glPushMatrix();
				glTranslatef(-1.0,0.25,-1.25);
				glRotatef(135,1,0,0);
				glScalef(0.1,0.75,0.1);
				cilindro.drawObjeto3d(polygon,ajedrez);
			glPopMatrix();
			//BARRA DERECHA PEQUEÑA
			glPushMatrix();
				glTranslatef(1.0,0.25,-1.25);
				glRotatef(135,1,0,0);
				glScalef(0.1,0.75,0.1);
				cilindro.drawObjeto3d(polygon,ajedrez);
			glPopMatrix();
			//BASE
			glPushMatrix();
				glScalef(5.0,0.1,2.0);
				if(polygon == Objeto3d::FILL){
					cubo.cambiarColor(0.0,0.0,0.0);
					cubo.drawObjeto3d(Objeto3d::LINE,ajedrez);
				}
				cubo.cambiarColor(0.5,0.5,0.5);
				cubo.drawObjeto3d(polygon,ajedrez);
			glPopMatrix();
		glPopMatrix();
}

// Método que dibuja un brazo de la silla
void ObjetoJerarquico::dibujarBrazo(bool ajedrez,Objeto3d::TipoPoligono polygon){

	glPushMatrix();
		glRotatef(270,0,1,0);
		//Parte arriba
		glPushMatrix();
			glTranslatef(0.0,2.9,0.0);
			glRotatef(170,0,0,1);
			glScalef(5.0,0.2,1.5);
			if(polygon == Objeto3d::FILL){
				cubo.cambiarColor(0.35,0.29,0.0);
				cubo.drawObjeto3d(Objeto3d::LINE,ajedrez);
			}
			cubo.cambiarColor(0.0,0.0,0.0);
			cubo.drawObjeto3d(polygon,ajedrez);
		glPopMatrix();
		//Parte izquierda
		glPushMatrix();
			glTranslatef(-2.4,2.0,0.0);
			glRotatef(90,0,0,1);
			glScalef(2.5,0.2,1.5);
			if(polygon == Objeto3d::FILL){
				cubo.cambiarColor(0.35,0.29,0.0);
				cubo.drawObjeto3d(Objeto3d::LINE,ajedrez);
			}
			cubo.cambiarColor(0.0,0.0,0.0);
			cubo.drawObjeto3d(polygon,ajedrez);
		glPopMatrix();
		//Parte derecha
		glPushMatrix();
			glTranslatef(2.4,1.6,0.0);
			glRotatef(90,0,0,1);
			glScalef(1.7,0.2,1.5);
			if(polygon == Objeto3d::FILL){
				cubo.cambiarColor(0.35,0.29,0.0);
				cubo.drawObjeto3d(Objeto3d::LINE,ajedrez);
			}
			cubo.cambiarColor(0.0,0.0,0.0);
			cubo.drawObjeto3d(polygon,ajedrez);
		glPopMatrix();
		//Base
		glPushMatrix();
			glScalef(5.0,1.5,1.5);
			if(polygon == Objeto3d::FILL){
				cubo.cambiarColor(0.35,0.29,0.0);
				cubo.drawObjeto3d(Objeto3d::LINE,ajedrez);
			}
			cubo.cambiarColor(0.0,0.0,0.0);
			cubo.drawObjeto3d(polygon,ajedrez);
		glPopMatrix();
	glPopMatrix();
}

// Método que dibuja el asiento de la silla
void ObjetoJerarquico::dibujarAsiento(int traslacion, bool ajedrez,Objeto3d::TipoPoligono polygon){

	//Asiento
	glPushMatrix();
		glTranslatef(0.0, (traslacion*1.0), 0.0);
		glScalef(13.0,1.5,10.0);
		if(polygon == Objeto3d::FILL){
			cubo.cambiarColor(0.0,0.0,0.0);
			cubo.drawObjeto3d(Objeto3d::LINE,ajedrez);
		}
		cubo.cambiarColor(0.5,0.35,0.05);
		cubo.drawObjeto3d(polygon,ajedrez);
	glPopMatrix();
}

//Metodo que dibuja el cabezal de la silla
void ObjetoJerarquico::dibujarCabezal(bool ajedrez,Objeto3d::TipoPoligono polygon){

	glPushMatrix();
		if(polygon == Objeto3d::FILL){
			cubo.cambiarColor(0.0,0.0,0.0);
			cubo.drawObjeto3d(Objeto3d::LINE,ajedrez);
		}
		cubo.cambiarColor(0.5,0.35,0.05);
		cubo.drawObjeto3d(polygon,ajedrez);
	glPopMatrix();
}

// Método que dibuja el respaldo de la silla
// y los brazos
void ObjetoJerarquico::dibujarRespaldo(bool ajedrez,float prueba,Objeto3d::TipoPoligono polygon){

	//Brazo izquierdo
	glPushMatrix();
		glTranslatef(-7.2,-5.8,4.9);
		glScalef(1.0,1.0,1.8);
		dibujarBrazo(ajedrez,polygon);
	glPopMatrix();
	//Brazo derecho
	glPushMatrix();
		glTranslatef(7.2,-5.8,4.9);
		glScalef(1.0,1.0,1.8);
		dibujarBrazo(ajedrez,polygon);
	glPopMatrix();
	glPushMatrix();
		glScalef(prueba,prueba,prueba);
		//Cabezal
		glPushMatrix();
			glTranslatef(0.0,8.5,0.0);
			glRotatef(90,1,0,0);
			glScalef(4.0,1.5,4.0);
			dibujarCabezal(ajedrez,polygon);
		glPopMatrix();
		//Respaldo
		glPushMatrix();
			glRotatef(90,1,0,0);
			glScalef(13.0,1.5,13.0);
			if(polygon == Objeto3d::FILL){
				cubo.cambiarColor(0.0,0.0,0.0);
				cubo.drawObjeto3d(Objeto3d::LINE,ajedrez);
			}
			cubo.cambiarColor(0.5,0.35,0.05);
			cubo.drawObjeto3d(polygon,ajedrez);
		glPopMatrix();
	glPopMatrix();
}

//Método que dibuja la silla completa
void ObjetoJerarquico::dibujarSilla(float angulo1, float angulo2, int traslacion, bool ajedrez, float sca,float prueba,Objeto3d::TipoPoligono polygon){
	glPushMatrix();
		glScalef(sca,sca,sca);
		//Base con subidor
		glPushMatrix();
			glTranslatef(0.0,-7.8,0.0);
			dibujarBase(traslacion, ajedrez,polygon);
		glPopMatrix();
			glPushMatrix();
				glRotatef(angulo1, 0,1,0);
				glPushMatrix();
					glRotatef(angulo2,1,0,0);
					//Respaldo
					glPushMatrix();
						glTranslatef(0.0, 5.8+(traslacion*1.0),-5.7);
						dibujarRespaldo(ajedrez,prueba,polygon);
					glPopMatrix();
					//ReposaPies
					glPushMatrix();
						glTranslatef(0.0,-5.65+(traslacion*1.0),8.25);
						dibujarReposaPies(ajedrez,polygon);
					glPopMatrix();
				glPopMatrix();
				//Asiento
				glPushMatrix();
					dibujarAsiento(traslacion,ajedrez,polygon);
				glPopMatrix();
		glPopMatrix();
	glPopMatrix();

}



///-------------------------MÉTODOS DE LA TRANSFOMACIÓN DE LA SILLA-------------------------///
void ObjetoJerarquico::dibujarBrazoT(bool ajedrez,Objeto3d::TipoPoligono polygon){

	glPushMatrix();
		glTranslatef(0.5,-4.6,0.0);
		glScalef(2.0,2.0,2.0);
		esfera.cambiarColor(0.0,0.0,0.0);
		esfera.drawObjeto3d(Objeto3d::FILL,ajedrez);
	glPopMatrix();
	glPushMatrix();
		glRotatef(90,0,1,0);
		glRotatef(90,1,0,0);
		glScalef(1.0,0.5,1.3);
		dibujarBrazo(ajedrez,polygon);
	glPopMatrix();
}

void ObjetoJerarquico::dibujarAbdominalesT(bool ajedrez){

	//Abajo derecha
	glPushMatrix();
		glTranslatef(0.5,-1.0,0.0);
		cubo.cambiarColor(0.0,0.0,0.0);
		cubo.drawObjeto3d(Objeto3d::LINE,ajedrez);
		cubo.cambiarColor(0.5,0.35,0.05);
		cubo.drawObjeto3d(Objeto3d::FILL,ajedrez);
	glPopMatrix();
	//Abajo izq
	glPushMatrix();
		glTranslatef(-0.5,-1.0,0.0);
		cubo.cambiarColor(0.0,0.0,0.0);
		cubo.drawObjeto3d(Objeto3d::LINE,ajedrez);
		cubo.cambiarColor(0.5,0.35,0.05);
		cubo.drawObjeto3d(Objeto3d::FILL,ajedrez);
	glPopMatrix();
	//Arriba izq
	glPushMatrix();
		glTranslatef(-0.5,1.0,0.0);
		cubo.cambiarColor(0.0,0.0,0.0);
		cubo.drawObjeto3d(Objeto3d::LINE,ajedrez);
		cubo.cambiarColor(0.5,0.35,0.05);
		cubo.drawObjeto3d(Objeto3d::FILL,ajedrez);
	glPopMatrix();
	//Arriba derecha
	glPushMatrix();
		glTranslatef(0.5,1.0,0.0);
		cubo.cambiarColor(0.0,0.0,0.0);
		cubo.drawObjeto3d(Objeto3d::LINE,ajedrez);
		cubo.cambiarColor(0.5,0.35,0.05);
		cubo.drawObjeto3d(Objeto3d::FILL,ajedrez);
	glPopMatrix();
	//Medio izq
	glPushMatrix();
		glTranslatef(-0.5,0.0,0.0);
		cubo.cambiarColor(0.0,0.0,0.0);
		cubo.drawObjeto3d(Objeto3d::LINE,ajedrez);
		cubo.cambiarColor(0.5,0.35,0.05);
		cubo.drawObjeto3d(Objeto3d::FILL,ajedrez);
	glPopMatrix();
	//Medio derecha
	glPushMatrix();
		glTranslatef(0.5,0.0,0.0);
		cubo.cambiarColor(0.0,0.0,0.0);
		cubo.drawObjeto3d(Objeto3d::LINE,ajedrez);
		cubo.cambiarColor(0.5,0.35,0.05);
		cubo.drawObjeto3d(Objeto3d::FILL,ajedrez);
	glPopMatrix();

}

void ObjetoJerarquico::dibujarOjoT(bool ajedrez){

	glPushMatrix();
		glScalef(0.6,0.6,0.6);
		//Reflejo
		glPushMatrix();
			glTranslatef(0.1,0.1,1.2);
			glScalef(0.3,0.3,0.3);
			esfera.cambiarColor(1.0,1.0,1.0);
			esfera.drawObjeto3d(Objeto3d::FILL,ajedrez);
		glPopMatrix();
		//Pupila
		glPushMatrix();
			glTranslatef(0.0,0.0,1.0);
			glScalef(0.7,0.7,0.7);
			esfera.cambiarColor(0.0,0.0,0.0);
			esfera.drawObjeto3d(Objeto3d::FILL,ajedrez);
		glPopMatrix();
		//Iris
		glPushMatrix();
			glTranslatef(0.0,0.0,0.75);
			glScalef(1.1,1.1,1.1);
			esfera.cambiarColor(0.5,0.35,0.05);
			esfera.drawObjeto3d(Objeto3d::FILL,ajedrez);
		glPopMatrix();
		//Cornea
		glPushMatrix();
			glTranslatef(0.0,0.0,0.6);
			glScalef(1.3,1.3,1.3);
			esfera.cambiarColor(0.0,0.0,0.0);
			esfera.drawObjeto3d(Objeto3d::FILL,ajedrez);
		glPopMatrix();
		//Ojo
		glPushMatrix();
			esfera.cambiarColor(1.0,1.0,1.0);
			glScalef(2.0,2.0,2.0);
			esfera.drawObjeto3d(Objeto3d::FILL,ajedrez);
		glPopMatrix();
	glPopMatrix();
}
void ObjetoJerarquico::dibujarCabezaT(bool ajedrez,Objeto3d::TipoPoligono polygon){

	//Cejas
	glPushMatrix();
		glTranslatef(0.0,0.9,0.0);
		//Ceja izq
		glPushMatrix();
			glRotatef(-20,0,0,1);
			glTranslatef(-1.2,0.4,0.5);
			glScalef(1.5,0.3,0.3);
			cubo.cambiarColor(0.0,0.0,0.0);
			cubo.drawObjeto3d(Objeto3d::FILL,ajedrez);
		glPopMatrix();
		//Ceja dere
		glPushMatrix();
			glRotatef(20,0,0,1);
			glTranslatef(1.2,0.4,0.5);
			glScalef(1.5,0.3,0.3);
			cubo.cambiarColor(0.0,0.0,0.0);
			cubo.drawObjeto3d(Objeto3d::FILL,ajedrez);
		glPopMatrix();
	glPopMatrix();
	//Ojos
	glPushMatrix();
		glTranslatef(0.0,0.9,0.0);
		//Ojo izq
		glPushMatrix();
			glTranslatef(-1.1,0.0,0.2);
			dibujarOjoT(ajedrez);
		glPopMatrix();
		//Ojo der
		glPushMatrix();
			glTranslatef(1.1,0.0,0.2);
			dibujarOjoT(ajedrez);
		glPopMatrix();
	glPopMatrix();
	//Boca
	glPushMatrix();
		glTranslatef(0.0,-1.0, 0.5);
		glScalef(2.5,0.8,0.3);
		cubo.cambiarColor(0.0,0.0,0.0);
		cubo.drawObjeto3d(Objeto3d::FILL,ajedrez);
	glPopMatrix();
	//Cabeza
	glPushMatrix();
		glScalef(5.0,5.0,1.0);
		dibujarCabezal(ajedrez,polygon);
	glPopMatrix();

}

void ObjetoJerarquico::dibujarTroncoT(bool ajedrez){
	//Abdominales
	glPushMatrix();
		glTranslatef(0.0,-0.5,0.0);
		glScalef(4.0,2.5,1.6);
		dibujarAbdominalesT(ajedrez);
	glPopMatrix();
	//Pecho
	glPushMatrix();
		glRotatef(90,1,0,0);
		glScalef(13.0,1.5,13.0);
		cubo.cambiarColor(0.0,0.0,0.0);
		cubo.drawObjeto3d(Objeto3d::LINE,ajedrez);
		cubo.cambiarColor(0.5,0.35,0.05);
		cubo.drawObjeto3d(Objeto3d::FILL,ajedrez);
	glPopMatrix();

}

void ObjetoJerarquico::dibujarHachaT(bool ajedrez){
	glPushMatrix();
		//Agarre
		glPushMatrix();
			glScalef(1.0, 12.0 ,1.0);
			glTranslatef(0.0,-0.21,0.0);
			cilindro.cambiarColor(0.0,0.0,0.0);
			cilindro.drawObjeto3d(Objeto3d::FILL,ajedrez);
		glPopMatrix();
		//Cuchilla
		glPushMatrix();
			glRotatef(45,0,0,1);
			glRotatef(90,0,1,0);
			glRotatef(90,0,0,1);
			glScalef(5.0,0.3,5.0);
			cubo.cambiarColor(0.0,0.0,0.0);
			cubo.drawObjeto3d(Objeto3d::LINE,ajedrez);
			cubo.cambiarColor(0.5,0.5,0.5);
			cubo.drawObjeto3d(Objeto3d::FILL,ajedrez);
		glPopMatrix();
	glPopMatrix();
}

void ObjetoJerarquico::dibujarPieT(bool ajedrez){

	glPushMatrix();
		//glScalef(10.0,10.0,10.0);
		glRotatef(-90,0,0,1);
		//BASE
		glPushMatrix();
			glScalef(2.5,0.1,2.0);
			cubo.cambiarColor(0.0,0.0,0.0);
			cubo.drawObjeto3d(Objeto3d::LINE,ajedrez);
			cubo.cambiarColor(0.5,0.5,0.5);
			cubo.drawObjeto3d(Objeto3d::FILL,ajedrez);
			glPopMatrix();
			glPushMatrix();
			glTranslatef(0.0,-0.5,0.0);
			glRotatef(25,1,0,0);
			glPushMatrix();
			//BARRA GRANDE
				glTranslatef(0.0,2.65,-2.75);
				glRotatef(150,1,0,0);
				glScalef(0.1,5.0,0.1);
				cilindro.drawObjeto3d(Objeto3d::FILL,ajedrez);
			glPopMatrix();
			//BARRA PEQUEÑA
			glPushMatrix();
				glTranslatef(0.0,0.25,-1.25);
				glRotatef(135,1,0,0);
				glScalef(0.1,0.75,0.1);
				cilindro.drawObjeto3d(Objeto3d::FILL,ajedrez);
			glPopMatrix();
		glPopMatrix();
	glPopMatrix();
}

void ObjetoJerarquico::dibujarPiernasT(bool ajedrez){

	glPushMatrix();
		glRotatef(90,0,0,1);
		//Pierna derecha
		glPushMatrix();
			glRotatef(-10,0,0,1);
			glPushMatrix();
				glTranslatef(0.0,4.0,0.0);
				glScalef(9.5,4.0,1.0);
				cubo.cambiarColor(0.0,0.0,0.0);
				cubo.drawObjeto3d(Objeto3d::LINE,ajedrez);
				cubo.cambiarColor(0.5,0.35,0.05);
				cubo.drawObjeto3d(Objeto3d::FILL,ajedrez);
			glPopMatrix();
			//Pie derecho
			glPushMatrix();
				glTranslatef(-6.0,4.0,1.3);
				dibujarPieT(ajedrez);
			glPopMatrix();
		glPopMatrix();

		//Pierna izq
		glPushMatrix();
			glRotatef(10,0,0,1);
			glPushMatrix();
				glTranslatef(0.0,-4.0,0.0);
				glScalef(9.5,4.0,1.0);
				cubo.cambiarColor(0.0,0.0,0.0);
				cubo.drawObjeto3d(Objeto3d::LINE,ajedrez);
				cubo.cambiarColor(0.5,0.35,0.05);
				cubo.drawObjeto3d(Objeto3d::FILL,ajedrez);
			glPopMatrix();
			//Pie izquierdo
			glPushMatrix();
				glTranslatef(-6.0,-4.0,1.3);
				dibujarPieT(ajedrez);
			glPopMatrix();
		glPopMatrix();
	glPopMatrix();

}

void ObjetoJerarquico::dibujarTransformacion(bool ajedrez,float sca,Objeto3d::TipoPoligono polygon){
	glPushMatrix();
		glScalef(sca,sca,sca);
		glTranslatef(0.0,5.0,0.0);
			//Cabeza
			glPushMatrix();
				glTranslatef(0.0,10.0,0.0);
				dibujarCabezaT(ajedrez,polygon);
			glPopMatrix();
			glPushMatrix();
				glTranslatef(0.0,-1.0,0.0);
				//Piernas
				glPushMatrix();
					glTranslatef(0.0,-12.0,0.0);
					dibujarPiernasT(ajedrez);
				glPopMatrix();
				//"COLA"(Subidor)
				glPushMatrix();
					glTranslatef(0.0,-8.0,-3.5);
					glRotatef(45, 1,0,0);
					dibujarSubidor(ajedrez, polygon);
				glPopMatrix();
				//Brazo izq
				glPushMatrix();
					glRotatef(-15,0,0,1);
					glTranslatef(-9.0, 0.0, 0.0);
					glRotatef(180,0,1,0);
					dibujarBrazoT(ajedrez,polygon);
				glPopMatrix();
				//Hacha
				glPushMatrix();
					glRotatef(-40,1,0,0);
					glRotatef(15,0,0,1);
					glTranslatef(9.5,-11.0,-2.0);
					glRotatef(180,1,0,0);
					glRotatef(-15,0,1,0);
					dibujarHachaT(ajedrez);
				glPopMatrix();
				//Brazo dere
				glPushMatrix();
					glRotatef(15,0,0,1);
					glTranslatef(9.0, 0.0, 0.0);
					dibujarBrazoT(ajedrez,polygon);
				glPopMatrix();
			glPopMatrix();
			//Tronco
			glPushMatrix();
				dibujarTroncoT(ajedrez);
			glPopMatrix();
		glPopMatrix();

}
void ObjetoJerarquico::dibujaEsT(bool ajedrez, float esf, float sca){
	glPushMatrix();
		glRotatef(esf,0,1,0);
		glTranslatef(0.0,(20.0),0.0);
		glScalef(250.0+sca,250.0+sca,250.0+sca);
		esfera.cambiarColor(1.0,1.0,1.0);
		esfera.drawObjeto3d(Objeto3d::LINE,ajedrez);
		esfera.cambiarColor(0.0,0.0,0.0);
		esfera.drawObjeto3d(Objeto3d::FILL,ajedrez);
	glPopMatrix();
}

/* void ObjetoJerarquico::animacionT(float t, bool ajedrez,float sca){

	float s1; // Escalado de la silla
	float alfa; //Giro de la silla
	float beta=0.0; //Ángulo de la inclinación de la silla
	float traslacion=0.0; //Traslación de la silla en el origen

	if(t < 1/3){
		vObj = 1;
	}else if(t > 1/3 && t < 2/3){
		vObj = 2;
	}else if(t > 2/3){
		vObj = 3;
	}

	switch (vObj) {
		case 1:
			s1 = sca * (1 - t/0.33);
			alfa = t*360;
			dibujarSilla(alfa, beta, traslacion, false, s1);
		break;

		/*case 2:
			s2 = sca * ()
	}
}*/
