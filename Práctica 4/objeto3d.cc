//Archivo perteneciente a la P4 de Jorge Gutiérrez Segovia grupo C1

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

void Objeto3d::generarNormales(std::vector<Cara> caras, std::vector<Vertice> vertices, std::vector<Normal> &normalCaras, std::vector<Normal> &normalVertices ){

    Normal inicializar;
    inicializar.v0 = 0.0;
    inicializar.v1 = 0.0;
    inicializar.v2 = 0.0;
    normalVertices = std::vector<Normal> (vertices.size(),inicializar); //Vector que contiene las normales de los vértices
    //Generar normales de las caras
	for(unsigned int i=0; i<caras.size();i++){

		Cara c = caras[i];
		float v;
        int v0,v1,v2; //Indices para acceder al vector de vértices
        v0 = c.v0;
        v1 = c.v1;
        v2 = c.v2;

		//Vector Vertices 0-1
		Normal primerV, segundoV, normalC;
        primerV.crearVector(vertices[v0],vertices[v1]);

		//Vector Vertices 0-2
        segundoV.crearVector(vertices[v0],vertices[v2]);

        //Genero la cara normal
        //Genero la perpendicular con los dos normales anteriores
        normalC.crearPerpendicular(primerV, segundoV);

        //Normalizo la perpendicular creada con anterioridad
		normalC.normalizar();

		//Añado al vector de las normales de las caras(cada vector una cara)
		normalCaras.push_back(normalC);

        //Sumo las normales a los vértices
        normalVertices[v0]+= normalC;
        normalVertices[v1]+= normalC;
        normalVertices[v2]+= normalC;
    }

    for(unsigned int i = 0; i<normalVertices.size();i++){
        normalVertices[i].normalizar();
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
