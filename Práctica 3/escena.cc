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
    objetoJerarquico = new ObjetoJerarquico();
    ajedrez=false;
    tapaS = false;
    tapaI = false;
    boolp = false;
    iteraciones = 3;
    aum=0;
    dec=0;
    ang=360.0;
  	Objeto3d::TipoPoligono polygon = Objeto3d::FILL;
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

    switch(modo){

        case '1':
            objetoJerarquico -> dibujarAsiento();
            //objetoJerarquico -> dibujarReposaPies();
            //objetoJerarquico -> dibujarBase();
            //objetoJerarquico -> dibujarSubidor();
        break;

        default:
            objeto3d -> drawObjeto3d(polygon,ajedrez);
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
            || toupper(Tecla1)== '-'|| toupper(Tecla1)=='W'|| toupper(Tecla1)=='H' || toupper(Tecla1)=='I'|| toupper(Tecla1)=='E'|| Tecla1=='1'|| Tecla1=='2'){

            modo = toupper(Tecla1);

            switch (modo) {

                case 'A':
                    mostrarM="Alambre";
                    polygon = Objeto3d::LINE;
                    ajedrez=false;
                    break;

                case 'P':
                    mostrarM="Puntos";
                    polygon = Objeto3d::POINTS;
                    ajedrez=false;
                    break;

                case 'S':
                    mostrarM="Sólido";
                    polygon = Objeto3d::FILL;
                    ajedrez=false;
                    break;

                case 'X':
                    mostrarM="Ajedrez";
                    polygon = Objeto3d::FILL;
                    ajedrez=true;
                    break;

                case 'T':
                    mostrarM="Tetraedro";
                    objeto3d = new Tetraedro();
                    ajedrez=false;
                    break;

                case 'C':
                    mostrarM="Cubo";
                    objeto3d = new Cubo();
                    ajedrez=false;
                    break;

                case 'M':
                    {
                        mostrarM = "Rotacion a un PLY";
                        //Compruebo iteraciones y cargo el directorio del PLY
                        iteraciones= comprobarIteraciones();
                        std::cout<<"Introduzca la direccion del fichero PLY" <<std::endl;
                        std::getline(cin,directPLY);
                        std::vector<char> d(directPLY.c_str(), directPLY.c_str() + directPLY.size() + 1);
                        objeto3d = new ObjetoPLY(&d[0]);
                        //Copio los vértices
                        aRotar = objeto3d -> getVertices();
                        //Re-inicializo como ObjetoRotacion
                        objeto3d = new ObjetoRotacion();
                        //Genero rotación
                        objeto3d -> generaRotacion( aRotar,iteraciones, tapaS,tapaI,ang);
                    }
                    break;

              case 'R':
                    {
                        mostrarM="PLY";
                        polygon = Objeto3d::FILL;
                        //Cargo el directorio del PLY
                        std::cout<<"Introduzca la direccion del fichero PLY" <<std::endl;
                        std::getline(cin,directPLY);
                        int tamD = directPLY.size();
                        string extension = directPLY.substr(tamD-5);
                        if(extension != ".ply"){
                            std::cout<< "El archivo introducido no contiene la extensión, se le añadirá automáticamente.\n";
                            directPLY.append(".ply");
                        }
                        std::vector<char> d(directPLY.c_str(), directPLY.c_str() + directPLY.size() + 1);

                        objeto3d = new ObjetoPLY(&d[0]);
                    }
                    break;

                case '+':
                    m = objeto3d -> getVertices();
                    ampliarVertices(m);
                    objeto3d -> setVertices(m);
                    aum++;
                    break;

                case '-':
                    m = objeto3d -> getVertices();
                    reducirVertices(m);
                    objeto3d -> setVertices(m);
                    dec++;
                    break;

                case 'W':
                    mostrarM="Rotacion";
                    polygon = Objeto3d::FILL;
                    objeto3d = new ObjetoRotacion();
                    aRotar.clear();
                    iteraciones = comprobarIteraciones();
                    //Leo un ángulo en grados
                    std::cout << "Introduzca el angulo en grados: ";
                    std::cin >> ang;
                    std::cin.ignore(1);

                    //Introduzco dos vértices por defecto
                    v1.x = 50.0;
                    v1.y = 50.0;
                    v1.z = 0.0;
                    aRotar.push_back(v1);
                    v1.x = 50.0;
                    v1.y = -50.0;
                    v1.z = 0.0;
                    aRotar.push_back(v1);
                    objeto3d -> generaRotacion( aRotar, iteraciones, tapaS,tapaI,ang);
                    ajedrez = false;
                    break;

                case 'H':
                    mostrarM="Tapa superior";
                    if(tapaS==true){
                      tapaS=false;
                    }else tapaS=true;
                    estadoAnterior();
                    break;

                case 'I':
                    mostrarM="Tapa inferior";
                    if(tapaI==true){
                      tapaI=false;
                    }else tapaI=true;
                    estadoAnterior();
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

void Escena::ampliarVertices(std::vector<Vertice> &m){

  for(int i=0; i<m.size();i++){
    m[i].x= m[i].x*1.5;
    m[i].y= m[i].y*1.5;
    m[i].z= m[i].z*1.5;

  }
  std::cout<< "Ampliado\n";
}

void Escena::reducirVertices(std::vector<Vertice> &m){

    for(int i=0; i<m.size();i++){
      m[i].x= m[i].x/1.5;
      m[i].y= m[i].y/1.5;
      m[i].z= m[i].z/1.5;

    }
    std::cout<< "Reducido\n";
}

int Escena::comprobarIteraciones(){

    int it;
    string entrada;
    do{
        std::cout << "Introduzca el numero de iteraciones: ";
        std::cin >> entrada;
        std::cin.ignore(1);
        it = atoi(entrada.c_str());
    }while(it<3);

    return it;
}

void Escena::estadoAnterior(){
    //Conservo el tamaño anterior
    int dif = aum-dec;
    if(dif>0){
      for(int i=0; i<dif;i++){
        ampliarVertices(aRotar);
      }
    }else if(dif<0){
      dif = dif*(-1);
      for(int i=0; i<dif;i++){
        reducirVertices(aRotar);
      }
    }
      aum=0;
      dec=0;
    objeto3d -> generaRotacion( aRotar, iteraciones, tapaS,tapaI,ang);
}
