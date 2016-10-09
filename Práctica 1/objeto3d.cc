//Archivo perteneciente a la P1 de Jorge Gutiérrez Segovia

#include<iostream>
#include<objeto3d.h>

Objeto3d::Objeto3d(){

}

void Objeto3d::drawObjeto3d(Objeto3d::TipoDibujo modo) const{

    GLenum modoD;
    switch (modo) {

        //Caso 1 el objeto es solo con líneas
        case Objeto3d::LINEAS:
            modoD = GL_LINE_STRIP;
            break;
        //Caso 2 el objeto solo se dibuja por puntos
        case Objeto3d::PUNTOS:
            modoD = GL_POINTS;
            break;
        //Como el Ajedrez y el Normal se dibujan con triangulos
        //lo pongo en el default
        default:
            modoD = GL_TRIANGLES;
            break;
    }
    glPointSize(5);
    glColor3f(0,0,0);
    /*for (int i= 0; i < caras.size(); i++){
         // Cambio de color para el ajedrez
         if (modo == AJEDREZ && i %2 == 0)
             glColor3f(1, 0, 0);
         else
             glColor3f(0, 1, 0);
    }*/
    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer( 3, GL_FLOAT, 0, &vertices[0]);
    glDrawElements( modoD,  caras.size() , GL_UNSIGNED_INT, &caras[0]) ;

}
