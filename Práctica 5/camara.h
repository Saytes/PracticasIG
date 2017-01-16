//Archivo perteneciente a la P5 de Jorge Gutiérrez Segovia grupo C1
#ifndef _CAMARA_H
#define _CAMARA_H
#include "objeto3d.h"

class Camara{

    public:
        //Variables
        Vertice eye, at, up, dir, derecha;
        Vertice eyeInicial, atInicial, upInicial, dirInicial, derechaInicial;

        //Constructor por defecto
        Camara();
        //Métodos para el estado de la cámara
        void ponerObservador();
        void posicionCamara(int x, int y, int z);
        void objetivoCamara(int x, int y, int z);
        void verticalCamara(int x, int y, int z);
        void direccionCamara(Vertice up, Vertice at);
        //Métodos para el manejo de la cámara
        void moverArriba();
        void moverAbajo();
        void moverDerecha();
        void moverIzquierda();
        void moverDentro();
        void moverFuera();
        void restablecer();
        void girar(int x, int y);
        void examinar(int x, int y);
};

#endif
