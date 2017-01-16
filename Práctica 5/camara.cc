//Archivo perteneciente a la P5 de Jorge Gutiérrez Segovia grupo C1
#include "camara.h"
#include <cstdio>
#include <iostream>
#include <GL/gl.h>
#include <GL/glut.h>
#include <math.h>

Camara::Camara(){

	eye.x = 0;
	eye.y = 0;
	eye.z = 0;

	at.x = 0;
	at.y = 0;
	at.z = 0;

	up.x = 0;
	up.y = 1;
	up.z = 0;
}

void Camara::ponerObservador(){

	gluLookAt(eye.x, eye.y, eye.z, at.x, at.y, at.z, up.x, up.y, up.z);

}

void Camara::posicionCamara(int x, int y, int z){

	eyeInicial.x = eye.x = x;
	eyeInicial.y = eye.y = y;
	eyeInicial.z = eye.z = z;

}

void Camara::objetivoCamara(int x, int y, int z){

	atInicial.x = at.x = x;
	atInicial.y = at.y = y;
	atInicial.z = at.z = z;

}

void Camara::verticalCamara(int x, int y, int z){

	upInicial.x = up.x = x;
	upInicial.y = up.y = y;
	upInicial.z = up.z = z;

}

void Camara::direccionCamara(Vertice up, Vertice at){

		 dir.crearVector(eye, at);
		 dirInicial = dir;

		derecha.prodVectorial(up, dir);
		derechaInicial = derecha;
}

void Camara::moverArriba(){

	eye.y+=5;
	at.y+=5;
}

void Camara::moverAbajo(){

	eye.y-=5;
	at.y-=5;
}

void Camara::moverDerecha(){

	eye.x+=(derecha.x*5);
	eye.y+=(derecha.y*5);
	eye.z+=(derecha.z*5);
}

void Camara::moverIzquierda(){

	eye.x-=(derecha.x*5);
	eye.y-=(derecha.y*5);
	eye.z-=(derecha.z*5);
}

void Camara::moverDentro(){

	eye.x+=(dir.x*5);
	eye.y+=(dir.y*5);
	eye.z+=(dir.z*5);
}

void Camara::moverFuera(){

	eye.x-=(dir.x*5);
	eye.y-=(dir.y*5);
	eye.z-=(dir.z*5);
}

void Camara::restablecer(){

	eye = eyeInicial;
	at = atInicial;
	up = upInicial;
	dir = dirInicial;
	derecha = derechaInicial;

}

void Camara::girar(int x, int y){

	float angulox = ((x*1.0)*M_PI)/180;
	float anguloy = ((y*1.0)*M_PI)/180;

	if(x!=0){
		dir.x = dir.x;
		dir.y = (cos(angulox)*dir.y) + (sin(angulox)*(dir.z));
		dir.z = (-1.0)*(sin(angulox)*dir.y)+(cos(angulox)*(dir.z));
	}
	if(y!=0){
		dir.x = (cos(anguloy)*dir.x) + (sin(anguloy)*(dir.z));
		dir.y = dir.y;
		dir.z = (-1.0)*(sin(anguloy)*dir.x)+(cos(anguloy)*(dir.z));
	}
	/*
	eye.x+=(dir.x);
	eye.y+=(dir.y);
	eye.z+=(dir.z);*/
}

void Camara::examinar(int x, int y){

	//Enlace https://es.wikipedia.org/wiki/Esfera#Ecuaci.C3.B3n_param.C3.A9trica
	float angulox, anguloy;
	float radioCircunferencia;

	angulox = (x*1.0)/75;
	anguloy = (y*1.0)/75;

	radioCircunferencia = sqrt( ((eye.x - at.x)*(eye.x - at.x)) + ((eye.y - at.y)*(eye.y - at.y)) + ((eye.z - at.z)*(eye.z - at.z)) );

	eye.x = at.x + radioCircunferencia * cos(angulox)* sin(anguloy);
	eye.y = at.y + radioCircunferencia * sin(angulox)* sin(anguloy);
	eye.z = at.z + radioCircunferencia * cos(anguloy);

}
