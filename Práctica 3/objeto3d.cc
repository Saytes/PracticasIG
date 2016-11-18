//Archivo perteneciente a la P2 de Jorge Gutiérrez Segovia grupo C1

#include<iostream>
#include <string>
#include"objeto3d.h"

Objeto3d::Objeto3d(){

}

void Objeto3d::drawObjeto3d(Objeto3d::TipoPoligono polygon,bool modoA) const{

    GLenum modoP;
    switch (polygon) {

        case Objeto3d::LINE:
            modoP = GL_LINE;
            break;

        case Objeto3d::POINTS:
            modoP = GL_POINT;
            break;
        default:
            modoP = GL_FILL;
            break;

    }
    glPointSize(5);

    if(!modoA){
        glEnableClientState(GL_VERTEX_ARRAY);
        glVertexPointer( 3, GL_FLOAT, 0, &vertices[0]);
        glEnable(GL_CULL_FACE);
        glPolygonMode(GL_FRONT_AND_BACK, modoP);
        glEnableClientState(GL_COLOR_ARRAY);
        glColorPointer(3, GL_FLOAT, 0, &colors[0]);
        glDrawElements( GL_TRIANGLES,  caras.size()*3 , GL_UNSIGNED_INT, &caras[0]) ;

    }
    else{
        //Modo ajedrez
        glEnableClientState(GL_VERTEX_ARRAY);
        glVertexPointer( 3, GL_FLOAT, 0, &vertices[0]);
        glEnable(GL_CULL_FACE);
        glPolygonMode(GL_FRONT_AND_BACK, modoP);

        //Primera parte del objeto
        glEnableClientState(GL_COLOR_ARRAY);
        glColorPointer(3, GL_FLOAT, 0, &color1[0]);
        glDrawElements( GL_TRIANGLES,  caras1.size()*3 , GL_UNSIGNED_INT, &caras1[0]) ;

        //Segunda parte del objeto
        glEnableClientState(GL_COLOR_ARRAY);
        glColorPointer(3, GL_FLOAT, 0, &color2[0]);
        glDrawElements( GL_TRIANGLES,  caras2.size()*3 , GL_UNSIGNED_INT, &caras2[0]) ;

    }



}

std::vector<Vertice> Objeto3d::getVertices(){
  return vertices;
}

void Objeto3d::setVertices(std::vector<Vertice> v){
  vertices = v;
}


std::vector<Cara> Objeto3d::getCaras(){
  return caras;
}

void Objeto3d::generaRotacion(std::vector<Vertice> aRotar,int iteraciones, bool tapaS, bool tapaI,float anguloRotacion,float v1, float v2 ,float v3){
}
