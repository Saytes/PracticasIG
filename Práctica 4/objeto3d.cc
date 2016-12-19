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

void Objeto3d::generarNormalesCaras(std::vector<Cara> caras, std::vector<std::vector<GLfloat>> &normalCaras ){

    //Generar normales de las caras
	for(unsigned int i=0; i<caras.size();i++){
		Cara c = caras[i]
		float v;
		//Primer vector Vertices 0-1
		std::vector<GLfloat> primerV;
		v = ((c.v1).x) - ((c.v0).x);
		primerV.push_back(v);//Primera cordenada del Vector
		v = ((c.v1).y) - ((c.v0).y);
		primerV.push_back(v);//Segunda cordenada del Vector
		v = ((c.v1).z) - ((c.v0).z);
		primerV.push_back(v);//Tercera cordenada del Vector
		//Primer vector Vertices 0-2
		std::vector<GLfloat> segundoV;
		v = ((c.v2).x) - ((c.v1).x);
		segundoV.push_back(v);//Primera cordenada del Vector
		v = ((c.v2).y) - ((c.v1).y);
		segundoV.push_back(v);//Segunda cordenada del Vector
		v = ((c.v2).z) - ((c.v1).z);
		segundoV.push_back(v);//Tercera cordenada del Vector
		//En los vectores anteriores, x -> 0 , y-> 1, z-> 2

		std::vector<GLfloat> perpendicular;
		//Primera coordenada de la perpendicular
		v = (primerV[1]*segundoV[2])-(primerV(2)*segundoV(1));
		perpendicular.push_back(v);
		//Segunda coordenada de la perpendicular
		v = (primerV[0]*segundoV[2])-(primerV(2)*segundoV(0));
		perpendicular.push_back(v);
		//Tercera coordenada de la perpendicular
		v = (primerV[0]*segundoV[1])-(primerV(1)*segundoV(0));
		perpendicular.push_back(v);

		//Módulo del vector perpendicular
		float modP = (sqrt((perpendicular[0]*perpendicular[0])+(perpendicular[1]*perpendicular[1])+(perpendicular[2]*perpendicular[2])));
		//Valor absoluto
		if(modoP<0){
			modoP=modoP*(-1);
		}
		//Genero la cara normal

		std::vector<GLfloat> cn;
		cn.v0 =perpendicular[0]/modP;
		cn.v1 =perpendicular[1]/modP;
		cn.v2 =perpendicular[2]/modP;

		//Añado al vector de las normales de las caras
		normalCaras.push_back(cn);
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
