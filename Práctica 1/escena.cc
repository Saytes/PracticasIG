//Archivo perteneciente a la P1 de Jorge Gutiérrez Segovia
#ifdef _WIN32
#include <windows.h>
#endif
#include <cstdio>
#include <iostream>
#include <string>
#include <GL/gl.h>
#include <GL/glut.h>
#include "escena.h"



Escena::Escena(){
    Front_plane=50;
    Back_plane=2000;
    Observer_distance = 4*Front_plane;
    Observer_angle_x = Observer_angle_y=0;
    ejes.changeAxisSize(5000);
    cubo1= new Cubo();
    tetraedro1 = new Tetraedro();

}

void Escena::inicializar(int UI_window_width,int UI_window_height) {

	glClearColor(1,1,1,1);// se indica cual sera el color para limpiar la ventana	(r,v,a,al)

	glEnable(GL_DEPTH_TEST);	// se habilita el z-bufer

	this->change_projection();
	Width=UI_window_width/10;
	Height=UI_window_height/10;
	glViewport(0,0,UI_window_width,UI_window_height);

}


//**************************************************************************
// Funcion que dibuja objetos en la escena
//***************************************************************************
void Escena::draw_objects() {

    switch (modoD) {

        case 'A':
            cubo1 -> drawObjeto3d(Objeto3d::LINEAS);
            break;

        case 'S':
            cubo1 -> drawObjeto3d(Objeto3d::NORMAL);
            break;

        case 'P':
                cubo1 -> drawObjeto3d(Objeto3d::PUNTOS);
                break;

        case 'C':
                cubo1 -> drawObjeto3d(Objeto3d::NORMAL);
                break;

        case 'T':
                tetraedro1 -> drawObjeto3d(Objeto3d::LINEAS);
                break;
        }
//cubo1 -> drawObjeto3d(modoD);
}



void Escena::dibujar() {

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT ); // Limpiar la pantalla
	change_observer();
	draw_axis();
	draw_objects();
}

int Escena::teclaPulsada(unsigned char Tecla1,int x,int y) {

    std::cout << "La Tecla pulsada es: " << Tecla1<< std::endl;

    if (toupper(Tecla1)=='Q'){
        std::cout << "La acción es salir."<< std::endl;
        return 1;
    }
    else if (toupper(Tecla1)=='A' || toupper(Tecla1)=='a' || toupper(Tecla1)=='P'
            || toupper(Tecla1)=='p' || toupper(Tecla1)=='S' || toupper(Tecla1)=='s'
            || toupper(Tecla1)=='T' || toupper(Tecla1=='t')){

            modoD = toupper(Tecla1); // Restamos 48 para sacar el valor en código ascii

            switch (modoD) {

                case 'A':
                    mostrarM="Alambre";
                    break;
                case 'P':
                    mostrarM="Puntos";
                    break;
                case 'S':
                    mostrarM="Sólido";
                    break;

                case 'T':
                    mostrarM="Tetraedro";
                    break;

            }
            std::cout << "Cambiado a modo " << mostrarM << std::endl;
            return 0;
    }
	else return 0;
}

void Escena::teclaEspecial(int Tecla1,int x,int y) {
switch (Tecla1){
	case GLUT_KEY_LEFT:Observer_angle_y--;break;
	case GLUT_KEY_RIGHT:Observer_angle_y++;break;
	case GLUT_KEY_UP:Observer_angle_x--;break;
	case GLUT_KEY_DOWN:Observer_angle_x++;break;
	case GLUT_KEY_PAGE_UP:Observer_distance*=1.2;break;
	case GLUT_KEY_PAGE_DOWN:Observer_distance/=1.2;break;
	}

	std::cout << Observer_distance << std::endl;
}


//**************************************************************************
// Funcion para definir la transformaci�n de proyeccion
//***************************************************************************

void Escena::change_projection()  {
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
glFrustum(-Width,Width,-Height,Height,Front_plane,Back_plane);
}


void Escena::redimensionar(int newWidth,int newHeight) {
change_projection();
Width=newWidth/10;
Height=newHeight/10;
glViewport(0,0,newWidth,newHeight);
}


//**************************************************************************
// Funcion para definir la transformaci�n de vista (posicionar la camara)
//***************************************************************************



void Escena::change_observer() {

// posicion del observador
glMatrixMode(GL_MODELVIEW);
glLoadIdentity();
glTranslatef(0,0,-Observer_distance);
glRotatef(Observer_angle_x,1,0,0);
glRotatef(Observer_angle_y,0,1,0);
}


//**************************************************************************
// Funcion que dibuja los ejes utilizando la primitiva grafica de lineas
//***************************************************************************

void Escena::draw_axis()
{
ejes.draw();
}
