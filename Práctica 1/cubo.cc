//Archivo perteneciente a la P1 de Jorge Gutiérrez Segovia grupo C1
#include "cubo.h"

Cubo::Cubo(){

	// Vertice
	Vertice v1;

    //------------------------
    //V0-FRONTAL-IZQ-ABAJO
	v1.x = 0.0;
	v1.y = 0.0;
	v1.z = 75.0;
	vertices.push_back(v1);
    //------------------------
    //V1-FRONTAL-DERECHA-ABAJO
    v1.x = 75.0;
    v1.y = 0.0;
    v1.z = 75.0;
    vertices.push_back(v1);
    //------------------------
    //V2-FRONTAL-DERECHA-ARRIBA
    v1.x = 75.0;
    v1.y = 75.0;
    v1.z = 75.0;
    vertices.push_back(v1);
    //------------------------
    //V3-FRONTAL-IZQ-ARRIBA
    v1.x = 0.0;
    v1.y = 75.0;
    v1.z = 75.0;
    vertices.push_back(v1);
    //------------------------
    //V4-TRASERO-IZQ-ABAJO
    v1.x = 0.0;
    v1.y = 0.0;
    v1.z = 0.0;
    vertices.push_back(v1);
    //------------------------
    //V5-TRASERO-DERECHA-ABAJO
    v1.x = 75.0;
    v1.y = 0.0;
    v1.z = 0.0;
    vertices.push_back(v1);
    //------------------------
    //V6-TRASERO-DERECHA-ARRIBA
    v1.x = 75.0;
    v1.y = 75.0;
    v1.z = 0.0;
    vertices.push_back(v1);
    //V7-TRASERO-IZQ-ARRIBA
    v1.x = 0.0;
    v1.y = 75.0;
    v1.z = 0.0;
    vertices.push_back(v1);
    //------------------------

    for(unsigned int i=0; i<vertices.size();i++){
				Vertice vc;
				vc.x = 0;
				vc.y = 0;
				vc.z = 0;
				colors.push_back(vc);
				vc.x = 1.0;
				vc.y = 0.0;
				vc.z = 0.0;
				color1.push_back(vc);
				vc.x = 0.0;
				vc.y = 1.0;
				vc.z = 1.0;
				color2.push_back(vc);
    }

	// Caras
	Cara c1;
    //DELANTERA
	c1.v0 = 3;
	c1.v1 = 0;
	c1.v2 = 1;
	caras.push_back(c1);
    //----------------
	c1.v0 = 3;
	c1.v1 = 1;
	c1.v2 = 2;
	caras.push_back(c1);
    //----------------
	//LATERAL DERECHO
	c1.v0 = 1;
	c1.v1 = 5;
	c1.v2 = 2;
	caras.push_back(c1);
    //----------------
	c1.v0 = 2;
	c1.v1 = 5;
	c1.v2 = 6;
	caras.push_back(c1);
	//----------------
	//TRASERA
	c1.v0 = 6;
	c1.v1 = 5;
	c1.v2 = 4;
	caras.push_back(c1);
    //----------------
	c1.v0 = 4;
	c1.v1 = 7;
	c1.v2 = 6;
	caras.push_back(c1);
	//----------------
	//LATERAL IZQUIERDO
	c1.v0 = 0;
	c1.v1 = 7;
	c1.v2 = 4;
	caras.push_back(c1);
    //----------------
	c1.v0 = 0;
	c1.v1 = 3;
	c1.v2 = 7;
	caras.push_back(c1);
	//----------------
    //TAPA ARRIBA
	c1.v0 = 2;
	c1.v1 = 7;
	c1.v2 = 3;
	caras.push_back(c1);
    //----------------
    c1.v0 = 2;
	c1.v1 = 6;
	c1.v2 = 7;
	caras.push_back(c1);
	//----------------
	//TAPA ABAJO
	c1.v0 = 0;
	c1.v1 = 4;
	c1.v2 = 5;
	caras.push_back(c1);
    //----------------
	c1.v0 = 0;
	c1.v1 = 5;
	c1.v2 = 1;
	caras.push_back(c1);
	//----------------
	for(int i = 0; i<caras.size(); i+=2){
		caras1.push_back(caras[i]);
		caras2.push_back(caras[i+1]);
	}

}
