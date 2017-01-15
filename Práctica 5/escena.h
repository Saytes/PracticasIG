//Archivo perteneciente a la P2 de Jorge Gutiérrez Segovia grupo C1
#ifndef _ESCENA_H
#define _ESCENA_H
#include <string>
#include <stdlib.h>
#include "ejes.h"
#include "cubo.h"
#include "objeto3d.h"
#include "camara.h"

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
	Objeto3d::TipoPoligono polygon;
	std::string mostrarM;
	char modo;
	bool ajedrez, modoExaminar;
	Camara cam[3];
	int camaraActiva;
	static const unsigned int BUFSIZE = 1024;
	GLuint selectBuf[BUFSIZE];
public:
     Escena();
	void inicializar(int UI_window_width,int UI_window_height);
	void redimensionar(int newWidth,int newHeight) ;

	// Dibujar
	void dibujar() ;

	// Interacci�n con la escena
	int teclaPulsada(unsigned char Tecla1,int x,int y) ;
	void teclaEspecial(int Tecla1,int x,int y);

	//Métodos P5
	void girarCamara(int x, int y);
	void pick( int x, int y);
	void procesarHits(GLint hits, GLuint buffer[]);
};
#endif
