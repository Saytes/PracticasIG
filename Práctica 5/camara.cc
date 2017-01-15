//Archivo perteneciente a la P5 de Jorge Gutiérrez Segovia grupo C1
#include "camara.h"
#include <cstdio>
#include <iostream>
#include <GL/gl.h>
#include <GL/glut.h>
#include <math.h>

Camara::Camara(){

	camara.x = 0;
	camara.y = 0;
	camara.z = 0;

	objetivo.x = 0;
	objetivo.y = 0;
	objetivo.z = 0;

	vertical.x = 0;
	vertical.y = 1;
	vertical.z = 0;

}

void Camara::ponerObservador(){

	gluLookAt(camara.x, camara.y, camara.z, objetivo.x, objetivo.y, objetivo.z, vertical.x, vertical.y, vertical.z);

}

void Camara::posicionCamara(int x, int y, int z){

	camaraInicial.x = camara.x = x;
	camaraInicial.y = camara.y = y;
	camaraInicial.z = camara.z = z;

}

void Camara::objetivoCamara(int x, int y, int z){

	objetivoInicial.x = objetivo.x = x;
	objetivoInicial.y = objetivo.y = y;
	objetivoInicial.z = objetivo.z = z;

}

void Camara::verticalCamara(int x, int y, int z){

	verticalInicial.x = vertical.x = x;
	verticalInicial.y = vertical.y = y;
	verticalInicial.z = vertical.z = z;

}

void Camara::moverArriba(){

	camara.y+=5;
	objetivo.y+=5;
}

void Camara::moverAbajo(){

	camara.y-=5;
	objetivo.y-=5;
}

void Camara::moverDerecha(){

	camara.x+=5;
	objetivo.x+=5;
}

void Camara::moverIzquierda(){

	camara.x-=5;
	objetivo.x-=5;
}

void Camara::moverDentro(){

	camara.z-=5;
	objetivo.z-=5;
}

void Camara::moverFuera(){

	camara.z+=5;
	objetivo.z+=5;
}

void Camara::restablecer(){

	camara.x = camaraInicial.x;
	camara.y = camaraInicial.y;
	camara.z = camaraInicial.z;

	objetivo.x = objetivoInicial.x;
	objetivo.y = objetivoInicial.y;
	objetivo.z = objetivoInicial.z;

	vertical.x = verticalInicial.x;
	vertical.y = verticalInicial.y;
	vertical.z = verticalInicial.z;

}

void Camara::girar(int x, int y){

	objetivo.x += x/75;
	objetivo.y += y/75;

}

void Camara::examinar(int x, int y){
	float angulox, anguloy;
	float radio;

	angulox = (x*1.0)/100;
	anguloy = (y*1.0)/100;
	radio = sqrt(((camara.x - objetivo.x)*(camara.x - objetivo.x)) + ((camara.y - objetivo.y)*(camara.y - objetivo.y)) + ((camara.z - objetivo.z)*(camara.z - objetivo.z)));
	camara.x = objetivo.x + radio * cos(angulox)* sin(anguloy);
	camara.y = objetivo.y + radio * sin(angulox)* sin(anguloy);
	camara.z = objetivo.z + radio * cos(anguloy);

}
