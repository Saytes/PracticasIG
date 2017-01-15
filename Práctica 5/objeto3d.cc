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

void Objeto3d::cambiarColor(float vx, float vy, float vz){
    for(int i =0; i< colors.size();i++){
        colors[i].x = vx;
        colors[i].y = vy;
        colors[i].z = vz;
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

Vertice Objeto3d::cajaEnvolvente(){
	float max_x, min_x;
	float max_y, min_y;
	float max_z, min_z;

	max_x = min_x = vertices[0].x;
	max_y = min_y = vertices[0].y;
	max_z = min_z = vertices[0].z;

	for(int i=1; i<vertices.size(); i++){

		if(vertices[i].x < min_x)
			min_x = vertices[i].x;
		else if(vertices[i].x > max_x)
			max_x = vertices[i].x;

		if(vertices[i].y < min_y)
			min_y = vertices[i].y;
		else if(vertices[i].y > max_y)
			max_y = vertices[i].y;

		if(vertices[i].z < min_z)
			min_z = vertices[i].z;
		else if(vertices[i].z > max_z)
			max_z = vertices[i].z;
	}

	Vertice centro;

	centro.x = (max_x - min_x) + min_x;
	centro.y = (max_y - min_y) + min_y;
	centro.z = (max_z - min_z) + min_z;

	return centro;
}
