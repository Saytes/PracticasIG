//Archivo perteneciente a la P2 de Jorge Gutiérrez Segovia grupo C1

#include "objetoRota.h"


ObjRotacion::ObjRotacion(){};


void ObjRotacion::generaRotacion(std::vector<GLfloat> perfil, int iteraciones){

    float anguloRotacion = (2.0*3.1415)/(iteraciones*1.0); //Genero ángulo en radianes
    vertices = perfil; //Copio los vértices en mi vector de la clase Objeto3D
    unsigned int indiceVertice = perfil.size();
    unsigned int indiceCara = caras.size();

    for(int i=0; i<iteraciones;i++){

        perfil[indice] = rotar(perfil[indice], anguloRotacion);
        vertices[indiceVertice] = perfil[indice];
        indiceVertice++;

        for(unsigned int j=indiceVertice;j <perfil.size();j++){
          
            perfil[indice2] = rotar(perfil[indice2], anguloRotacion);
            vertices[indiceVertice] = perfil[indice2];

            //Creo la primera cara
            Cara nuevaC;
            nuevaC.v0 = indiceVertice;
            caras[indiceCara]=indiceVertice-perfil.size();
            indiceCara++;
            caras[indiceCara]=indiceVertice-perfil.size();
            indiceCara++;
            //Creo la segunda cara
            caras[indiceCara]=indiceVertice-perfil.size();
            indiceCara++;
            caras[indiceCara]=indiceVertice-perfil.size()-1;
            indiceCara++;
            caras[indiceCara]=indiceVertice-1;
            indiceCara++;
            indiceVertice++;

        }
    }
};

Vertice ObjRotacion::rotar(Vertice v, float ang){

    Vertice sol;

    sol.x = (cos(ang)*v.x) + (sin(ang)*(v.z));
    sol.y = v.y;
    sol.z = (-1.0)*(sin(ang)*v.x)+(cos(ang)*(v.z));

    return sol;
}
