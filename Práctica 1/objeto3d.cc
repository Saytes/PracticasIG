//Archivo perteneciente a la P1 de Jorge Gutiérrez Segovia grupo C1

#include<iostream>
#include<objeto3d.h>

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
    /*float ncolor = 0.0;
    std::vector<float>colores2;
    std::vector<float>colores1;
    for(int i=0; i<vertices.size();i+=3){
            colores1.push_back(1.0);
            colores1.push_back(0.0);
            colores1.push_back(0.0);
            colores2.push_back(0.0);
            colores2.push_back(1.0);
            colores2.push_back(1.0);

    }*/

    if(!modoA){
        glEnableClientState(GL_VERTEX_ARRAY);
        glVertexPointer( 3, GL_FLOAT, 0, &vertices[0]);
        glEnable(GL_CULL_FACE);
        glPolygonMode(GL_FRONT_AND_BACK, modoP);
        glEnableClientState(GL_COLOR_ARRAY);
        glColorPointer(3, GL_FLOAT, 0, &colors[0]);
        glDrawElements( GL_TRIANGLES,  caras.size() , GL_UNSIGNED_INT, &caras[0]) ;
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
        glDrawElements( GL_TRIANGLES,  caras.size()/2 , GL_UNSIGNED_INT, &caras[0]) ;

        //Segunda parte del objeto
        glEnableClientState(GL_COLOR_ARRAY);
        glColorPointer(3, GL_FLOAT, 0, &color2[0]);
        glDrawElements( GL_TRIANGLES,  caras.size()/2 , GL_UNSIGNED_INT, &caras[caras.size()/2]) ;
    }


}
