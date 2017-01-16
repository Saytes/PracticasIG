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
    objeto3d = new Cubo();
  	Objeto3d::TipoPoligono polygon = Objeto3d::FILL;
    ajedrez = false;
    modoExaminar = false;

    //Inicializacion camaras
    camaraActiva = 0;
    cam[0].posicionCamara(0,0,200);
    cam[1].posicionCamara(5,150,5);
    cam[2].posicionCamara(200,0,0);

    cam[0].objetivoCamara(0,0,0);
    cam[1].objetivoCamara(0,0,0);
    cam[2].objetivoCamara(0,0,0);

    cam[0].verticalCamara(0,1,0);
    cam[1].verticalCamara(0,1,0);
    cam[2].verticalCamara(0,1,0);

    cam[0].direccionCamara(cam[0].up,cam[0].at);
    cam[1].direccionCamara(cam[1].up,cam[1].at);
    cam[2].direccionCamara(cam[2].up,cam[2].at);
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
        glScalef(50.0,50.0, 50.0);
        objeto3d -> drawObjeto3d(polygon,ajedrez);
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
    else if (  toupper(Tecla1)=='W' || toupper(Tecla1)=='S' || toupper(Tecla1)=='A'
            || toupper(Tecla1)=='D' || toupper(Tecla1)=='Z' || toupper(Tecla1)=='X'
            || toupper(Tecla1)=='R' || toupper(Tecla1)=='1' || toupper(Tecla1)=='2'
            || toupper(Tecla1)=='3' || toupper(Tecla1)=='E' || toupper(Tecla1)=='N'){

            modo = toupper(Tecla1);

            switch (modo) {

                case 'W':
                    cam[camaraActiva].moverArriba();
                    mostrarM = "Moviendo hacia arriba";
                    break;

                case 'S':
                    cam[camaraActiva].moverAbajo();
                    mostrarM = "Moviendo hacia abajo";
                    break;

                case 'A':
                    cam[camaraActiva].moverIzquierda();
                    mostrarM = "Moviendo hacia izquierda";
                    break;

                case 'D':
                    cam[camaraActiva].moverDerecha();
                    mostrarM = "Moviendo hacia derecha";
                    break;

                case 'Z':
                    cam[camaraActiva].moverDentro();
                    mostrarM = "Moviendo hacia dentro";
                    break;

                case 'X':
                    cam[camaraActiva].moverFuera();
                    mostrarM = "Moviendo hacia fuera";
                    break;

                case 'R':
                    cam[camaraActiva].restablecer();
                    mostrarM = "Restableciendo";
                    break;

                case '1':
                    camaraActiva = 0;
                    cam[camaraActiva].ponerObservador();
                    mostrarM = "Aplicando observador 0";
                    break;

                case '2':
                    camaraActiva = 1;
                    cam[camaraActiva].ponerObservador();
                    mostrarM = "Aplicando observador 1";
                    break;

                case '3':
                    camaraActiva = 2;
                    cam[camaraActiva].ponerObservador();
                    mostrarM = "Aplicando observador 2";
                    break;

                case 'N':
                    modoExaminar=false;
                    mostrarM = "Modo examinar cerrado";
                    break;

                case 'E':
                	Vertice centro = objeto3d -> cajaEnvolvente();
        			cam[camaraActiva].at.x = centro.x;
        			cam[camaraActiva].at.y = centro.y;
        			cam[camaraActiva].at.z = centro.z;
        			modoExaminar = true;
                    mostrarM = "Modo examinar abierto";
                    break;
            }
            std::cout << mostrarM << std::endl;
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

    //glTranslatef(0,0,-Observer_distance);
    //glRotatef(Observer_angle_x,1,0,0);
    //glRotatef(Observer_angle_y,0,1,0);

    cam[camaraActiva].ponerObservador();
}

//**************************************************************************
// Funcion que dibuja los ejes utilizando la primitiva grafica de lineas
//***************************************************************************

void Escena::draw_axis()
{
ejes.draw();
}

//**************************************************************************
//Práctica 5
//***************************************************************************

void Escena::girarCamara(int x, int y){

    	if(!modoExaminar)
    		cam[camaraActiva].girar(x,y);
    	else
    		cam[camaraActiva].examinar(x,y);
}


void Escena::pick( int x, int y) {

	GLint hits, viewport[4];
	glGetIntegerv(GL_VIEWPORT, viewport);
	glSelectBuffer(BUFSIZE, selectBuf);
	glRenderMode(GL_SELECT);
	glInitNames();
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPickMatrix(x, (viewport[3] - y), 5.0, 5.0, viewport);
	glFrustum(-Width,Width,-Height,Height,Front_plane,Back_plane);
	draw_objects();
	hits = glRenderMode(GL_RENDER);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glFrustum(-Width,Width,-Height,Height,Front_plane,Back_plane);
	if(hits!=0){
        procesarHits(hits,selectBuf);
    }

    std::cout << "He realizado el pick" << std::endl;
}

void Escena::procesarHits(GLint hits, GLuint buffer[]){
    unsigned int i, j;
	GLuint names, *ptr, minZ, *ptrNames, numberOfNames;
	printf ("Primitivas intersecadas = %d\n", hits); ptr = (GLuint *) buffer;
	minZ= 0xffffffff;
	for(i=0; i< hits; i++){

		names = *ptr; ptr++;
		if(*ptr < minZ){
			numberOfNames = names;
			minZ = *ptr; ptrNames = ptr+2;
		}
		ptr += names+2;
	}
	printf ("Los nombres de la primitiva mas cercana son: "); ptr = ptrNames;
	for(j=0; j < numberOfNames; j++, ptr++){
		printf ("%d", *ptr);
	}
	printf("\n");
}
