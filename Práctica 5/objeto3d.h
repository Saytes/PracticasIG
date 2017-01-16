//Archivo perteneciente a la P2 de Jorge Gutiérrez Segovia grupo C1
#ifndef _OBJETO3D_H
#define _OBJETO3D_H
#include<vector>
#include<GL/gl.h>
#include <math.h>

//Clase principal de la cual heredan Cubo y Tetraedro


struct Vertice{

    GLfloat x,y,z;

    //Método que crea un vector a raiz de dos vértices
    void crearVector(Vertice v0, Vertice v1){
        this->x = (v1.x) - (v0.x);//Primera cordenada del primer Vector
        this->y = (v1.y) - (v0.y);//Segunda cordenada del primer Vector
        this->z = (v1.z) - (v0.z);//Tercera cordenada del primer Vector

        this->normalizar();
    }

    void prodVectorial(Vertice v0, Vertice v1){
        this->x = (v0.y*v1.z) - (v0.z*v1.y);
        this->y = (v0.x*v1.z) - (v0.z*v1.x);
        this->z = (v0.x*v1.y) - (v0.y*v1.x);
    }

    Vertice normalizar(){
        //Módulo del vector perpendicular
        float mod = this->modulo();

        this->x = (this->x /mod);
        this->y = (this->y /mod);
        this->z = (this->z /mod);

    }
    //Método que hace el módulo de una normal
    float modulo(){
        float solucion;

        solucion = (this->x*this->x) + (this->y*this->y) + (this->z*this->z);
        solucion = sqrt(solucion);
        //Valor absoluto
        if(solucion<0){
            solucion=solucion*(-1);
        }
        return solucion;
    }

    Vertice &operator=(const Vertice &valor){
        this->x = valor.x;
        this->y = valor.y;
        this->z = valor.z;

        return *this;
    }

};

struct Cara{

    GLuint v0,v1,v2;
};

class Objeto3d{

	public:
		Objeto3d(); // Constructor por defecto
		enum TipoPoligono{
			FILL, LINE, POINTS
		};

	void drawObjeto3d(TipoPoligono polygon = FILL, bool modoA=false) const;
    void cambiarColor(float vx, float vy, float vz);
    std::vector<Vertice> getVertices();
    void setVertices(std::vector<Vertice> v);
    std::vector<Cara> getCaras();
    virtual void generaRotacion(std::vector<Vertice> aRotar, int iteraciones,bool tapaS, bool tapaI,float anguloRotacion,float v1, float v2 ,float v3);
    Vertice cajaEnvolvente();

	protected:

		bool modoA;       //Booleano que regula el modo ajedrez
        std::vector<Vertice> vertices, colors,color1,color2;		// Vectores de Vértices
		std::vector<Cara> caras, caras1, caras2;		// Vectores de Caras
};

#endif
