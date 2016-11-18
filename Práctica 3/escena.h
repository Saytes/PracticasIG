//Archivo perteneciente a la P2 de Jorge Gutiérrez Segovia grupo C1
#ifndef _ESCENA_H
#define _ESCENA_H
#include <string>
#include <stdlib.h>
#include "ejes.h"
#include "cubo.h"
#include "objeto3d.h"
#include "objetoPLY.h"
#include "objetoRotacion.h"
#include "tetraedro.h"
#include "cilindro.h"
#include "objetoJerarquico.h"

class Escena {
private:
// tama�o de los ejes
#define AXIS_SIZE 5000
Ejes ejes;

// variables que definen la posicion de la camara en coordenadas polares
GLfloat Observer_distance;
GLfloat Observer_angle_x;
GLfloat Observer_angle_y;

// variables que controlan la ventana y la transformacion de perspectiva
GLfloat Width,Height,Front_plane,Back_plane;

private:
	void clear_window();
	void draw_axis();
	void draw_objects();

//Transformaci�n de c�mara
	void change_projection();
	void change_observer();

// Variables para cambiar de modo y objetos
 	Objeto3d *objeto3d;
	ObjetoJerarquico *objetoJerarquico;
	Objeto3d::TipoPoligono polygon;
	std::string mostrarM, directPLY, c;
	std::vector<Vertice> aRotar,m;
	Vertice v1;
	char modo,giro;
  	char* d;
	bool ajedrez,tapaS,tapaI,boolp, primeraVez;
	int iteraciones,aum,dec;
	float ang, rot1, rot2, tr1;
public:
     Escena();
	void inicializar(int UI_window_width,int UI_window_height);
	void redimensionar(int newWidth,int newHeight) ;

	// Dibujar
	void dibujar() ;

	// Interacci�n con la escena
	int teclaPulsada(unsigned char Tecla1,int x,int y) ;
	void teclaEspecial(int Tecla1,int x,int y);
	void ampliarVertices(std::vector<Vertice> &m);
	void reducirVertices(std::vector<Vertice> &m);
	int comprobarIteraciones();
	void estadoAnterior();
};
#endif
