//Archivo perteneciente a la P2 de Jorge Gutiérrez Segovia grupo C1

#include "objetoRota.h"


ObjRotacion::ObjRotacion(){};


void ObjRotacion::generaRotacion(std::vector<Vertice> aRotar, int iteraciones, bool tapaS, bool tapaI){

    float anguloRotacion = (2.0*3.1415)/(iteraciones*1.0); //Genero ángulo en radianes

  /*  Vertice pTapaSup, pTapaInf; //Punto de la tapa superior y tapa inferior

    if(aRotar[0].x == 0.0){

        //Tras comprobar si hay tapa superior, la introduzco en el vértice
        //creado antes y lo borro del vector de puntos a rotar
        pTapaSup.x= aRotar[0].x;
        pTapaSup.y= aRotar[0].y;
        pTapaSup.z= aRotar[0].z;

        aRotar.erase(aRotar.begin());
    }else{
        //Si no existe el punto, lo creo para crear la tapa en caso de que me la
        //pidan.
        pTapaSup.x = 0;
        pTapaSup.y = aRotar[0].y;
        pTapaSup.z = aRotar[0].z;
      }

    if(aRotar[aRotar.size()-1].x == 0.0){

        //Tras comprobar si hay tapa inferior, la introduzco en el vértice
        // creado antes y lo borro del vector de puntos a rotar
        pTapaInf.x= aRotar[aRotar.size()-1].x;
        pTapaInf.y= aRotar[aRotar.size()-1].y;
        pTapaInf.z= aRotar[aRotar.size()-1].z;

        aRotar.pop_back();
    }else{
      //Si no existe el punto, lo creo para crear la tapa en caso de que me la
      //pidan.
        pTapaInf.x = 0;
        pTapaInf.y = aRotar[aRotar.size()-1].y;
        pTapaInf.z = aRotar[aRotar.size()-1].z;
    }*/

    //Copio los vértices en mi vector de la clase Objeto3D
    vertices = perfil;
    //Creo dos índices para trabajar sobre los vectores de caras y vértices
    //de mi clase Objeto3D
    unsigned int indiceVertice = aRotar.size();
    unsigned int indiceCaras = 0;

    //Redimensiono mi vector, para poder acceder a posiciones independientemente
    vertices.resize(aRotar.size()*(iteraciones+1));

    for(int i=0; i<iteraciones; i++){

        aRotar[0] = rotarPunto(aRotar[0], anguloRotacion);
        vertices[indiceVertice] = aRotar[0];
        indiceVertice++;

        for(unsigned int j=indiceVertice;j < aRotar.size();j++){
            aRotar[j] = rotarPunto(aRotar[j], anguloRotacion);
            vertices[indiceVertice] = aRotar[j];

            //Introduzco la primera "Media Cara"
            Cara c;
            c.v0 = indiceVertice;
            c.v1 = indiceVertice-aRotar.size();
            c.v2 = indiceVertice-1;

            caras.push_back(c);
            indiceCaras++;

            //Introduzco la segunda "Media Cara"
            c.v0 = indiceVertice-aRotar.size();
            c.v1 = indiceVertice-aRotar.size()-1;
            c.v2 = indiceVertice-1;

            caras.push_back(c);
            indiceCaras++;
        }
    }
};

Vertice ObjRotacion::rotarPunto(Vertice v, float ang){

    Vertice sol;

    sol.x = (cos(ang)*v.x) + (sin(ang)*(v.z));
    sol.y = v.y;
    sol.z = (-1.0)*(sin(ang)*v.x)+(cos(ang)*(v.z));

    return sol;
}
