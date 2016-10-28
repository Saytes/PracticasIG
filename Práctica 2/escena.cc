//Archivo perteneciente a la P2 de Jorge Gutiérrez Segovia grupo C1
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
    objeto3d = new Objeto3d();
    objetoRotado = new ObjRotacion();
    ajedrez=false;
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

    if(mostrarM=="PLY"){
        std::cout<<"Introduzca la direccion del fichero PLY" <<std::endl;
        std::getline(cin,directPLY);
        std::vector<char> d(directPLY.c_str(), directPLY.c_str() + directPLY.size() + 1);
        objeto3d = new ObjetoPLY(&d[0]);
        mostrarM="";
        modo = 'S';
    }
    if(mostrarM=="PLYR"){
      directPLY="peon.ply";
      std::vector<char> d(directPLY.c_str(), directPLY.c_str() + directPLY.size() + 1);
      objeto3d = new ObjetoPLY(&d[0]);
      aRotar = objeto3d -> getVertices();
      objetoRotado -> generaRotacion( aRotar , 3, false,false);
      mostrarM="";
    }
    else if(mostrarM=="Rotacion"){

    	std::cout<<modo<<std::endl;
      v1.x = 10.0;
      v1.y = 0.0;
      v1.z = 0.0;
      aRotar.push_back(v1);
      v1.x = 10.0;
      v1.y = 10.0;
      v1.z = 0.0;
      aRotar.push_back(v1);

      objetoRotado -> generaRotacion( aRotar, 4, false,false);
      std::vector<Vertice> v = objetoRotado -> getVertices();
      std::vector<Cara> c = objetoRotado -> getCaras();

      std::cout<<v.size() <<" Tamaño v\n";

      std::cout<<c.size()<< "tamaño c\n";

      for(int i=0 ; i<v.size();i++){
        std::cout<< v[i].x<< " x "<< v[i].y<< " y "<< v[i].z << " z\n";
      }
      for(unsigned int i=0 ; i<c.size();i++){
        std::cout<< c[i].v0<< " v0 "<< c[i].v1<< " v1 "<< c[i].v2 << "v2\n";
      }
      mostrarM="";
    }


    switch (modo) {

        case 'A':
            objeto3d -> drawObjeto3d(Objeto3d::LINE,ajedrez);
            break;

        case 'S':
            objeto3d -> drawObjeto3d(Objeto3d::FILL,ajedrez);
            break;

        case 'P':
            objeto3d -> drawObjeto3d(Objeto3d::POINTS,ajedrez);
            break;

        case 'X'://Modo Ajedrez
            objeto3d -> drawObjeto3d(Objeto3d::FILL,ajedrez);
            break;

        case 'C':
            objeto3d -> drawObjeto3d(Objeto3d::FILL,ajedrez);
            break;

        case 'T':
            objeto3d -> drawObjeto3d(Objeto3d::FILL,ajedrez);
            break;

        case 'R':
            objeto3d -> drawObjeto3d(Objeto3d::FILL, ajedrez);
            break;

        case 'W':
            objetoRotado-> drawObjeto3d(Objeto3d::FILL, ajedrez);
            break;

        case '+':
            objeto3d -> drawObjeto3d(Objeto3d::FILL,ajedrez);
            break;

        case '-':
            objeto3d -> drawObjeto3d(Objeto3d::FILL,ajedrez);
            break;


        }
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
    else if (toupper(Tecla1)=='A' || toupper(Tecla1)=='P' || toupper(Tecla1)=='S'
            || toupper(Tecla1)=='T'|| toupper(Tecla1)=='C' || toupper(Tecla1)=='X'|| toupper(Tecla1)=='M' || toupper(Tecla1)=='R' || toupper(Tecla1)== '+'
            || toupper(Tecla1)== '-'|| toupper(Tecla1)=='W'){

            modo = toupper(Tecla1);

            switch (modo) {

                case 'A':
                    mostrarM="Alambre";
                    ajedrez=false;
                    break;
                case 'P':
                    mostrarM="Puntos";
                    ajedrez=false;
                    break;
                case 'S':
                    mostrarM="Sólido";
                    ajedrez=false;
                    break;
                case 'X':
                    mostrarM="Ajedrez";
                    ajedrez=true;
                    break;
                case 'T':
                    objeto3d = new Tetraedro();
                    ajedrez=false;
                    mostrarM="Tetraedro";
                    break;

                case 'C':
                    objeto3d = new Cubo();
                    ajedrez=false;
                    mostrarM="Cubo";
                    break;

                case 'M':
                    mostrarM = "PLY";
                    break;

                case 'R':
                    mostrarM="PLYR";
                    break;

                case '+':
                    objeto3d -> ampliarVertices();
                    objetoRotado -> ampliarVertices();
                    break;

                case '-':
                    objeto3d -> reducirVertices();
                    objetoRotado -> reducirVertices();
                    break;

                case 'W':
                ajedrez = false;
                mostrarM="Rotacion";
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
