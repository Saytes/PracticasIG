//Archivo perteneciente a la P1 de Jorge Gutiérrez Segovia

#include<iostream>
#include<objeto3d.h>

Objeto3d::Objeto3d(){

}

void Objeto3d::drawObjeto3d(Objeto3d::TipoDibujo modo,Objeto3d::TipoPoligono polygon,bool modoA) const{

    GLenum modoD, modoP;
    switch (modo) {

        //Caso 1 el objeto es solo con líneas
        case Objeto3d::LINEAS:
            modoD = GL_LINE_STRIP;
            break;
        //Caso 2 el objeto solo se dibuja por puntos
        case Objeto3d::PUNTOS:
            modoD = GL_POINTS;
            break;
        //Como el Ajedrez y el Sólido son practicamente iguales,
        // los pongo en el default
        default:
            modoD = GL_TRIANGLES;
            break;
    }
    switch (polygon) {

        case Objeto3d::LINE:
            modoP = GL_LINE;
            break;

        default:
            modoP = GL_FILL;
            break;

    }
    glPointSize(5);
    glColor3f(0,0,0);

    if(!modoA){
        glEnableClientState(GL_VERTEX_ARRAY);
        glVertexPointer( 3, GL_FLOAT, 0, &vertices[0]);
        glEnable(GL_CULL_FACE);
        glPolygonMode(GL_FRONT_AND_BACK, modoP);
        glDrawElements( modoD,  caras.size() , GL_UNSIGNED_INT, &caras[0]) ;
    }
    else{
        //Modo ajedrez
        glColor3f(0,1,1);
        glEnableClientState(GL_VERTEX_ARRAY);
        glVertexPointer( 3, GL_FLOAT, 0, &vertices[0]);
        glEnable(GL_CULL_FACE);
        glPolygonMode(GL_FRONT_AND_BACK, modoP);
        glDrawElements( modoD,  caras.size()/2 , GL_UNSIGNED_INT, &caras[0]) ;
        glColor3f(1, 1, 0);
        glDrawElements( modoD,  caras.size()/2 , GL_UNSIGNED_INT, &caras[caras.size()/2]) ;
    }


}
