//Archivo perteneciente a la P4 de Jorge Gutiérrez Segovia grupo C1
#ifndef _OBJETO3D_H
#define _OBJETO3D_H
#include<vector>
#include<math.h>
#include<GL/gl.h>
//Clase principal de la cual heredan Cubo y Tetraedro


struct Vertice{

    GLfloat x,y,z;
};

struct Cara{

    GLuint v0,v1,v2;
};

struct Normal{

    //Variables
    GLfloat v0,v1,v2;

    //Método que crea un vector a raiz de dos vértices
    void crearVector(Vertice v0, Vertice v1){
        this->v0 = (v1.x) - (v0.x);//Primera cordenada del primer Vector
        this->v1 = (v1.y) - (v0.y);//Segunda cordenada del primer Vector
        this->v2 = (v1.z) - (v0.z);//Tercera cordenada del primer Vector

        this->normalizar();
    }

    //Método que crea la perpendicular a raiz de dos normales
    void crearPerpendicular(Normal n0, Normal n1){
        //Primera coordenada de la perpendicular
        this->v0 = (n0.v1*n1.v2) - (n0.v2*n1.v1);
        //Segunda coordenada de la perpendicular
        this->v1 = (n0.v0*n1.v2) - (n0.v2*n1.v0);
        //Tercera coordenada de la perpendicular
        this->v2 = (n0.v0*n1.v1) - (n0.v1*n1.v0);
    }

    //Método que hace el módulo de una normal
    float modulo(){
        float solucion;

        solucion = (this->v0*this->v0) + (this->v1*this->v1) + (this->v2*this->v2);
        solucion = sqrt(solucion);
        //Valor absoluto
        if(solucion<0){
            solucion=solucion*(-1);
        }
        return solucion;
    }

    //Método que normaliza una Normal
    Normal normalizar(){
        //Módulo del vector perpendicular
        float mod = this->modulo();

        this->v0 = (this->v0 /mod);
        this->v1 = (this->v1 /mod);
        this->v2 = (this->v2 /mod);

    }

    Normal &operator+=(const float &valor){
        this->v0 += valor;
        this->v1 += valor;
        this->v2 += valor;

        return *this;
    }

    Normal &operator+=(const Normal &valor){
        this->v0 += valor.v0;
        this->v1 += valor.v1;
        this->v2 += valor.v2;

        return *this;
    }

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
    void generarNormales(std::vector<Cara> caras, std::vector<Vertice> vertices, std::vector<Normal> &normalCaras, std::vector<Normal> &normalVertices );

	protected:

		bool modoA;       //Booleano que regula el modo ajedrez
        std::vector<Vertice> vertices, colors,color1,color2;		// Vectores de Vértices
		std::vector<Cara> caras, caras1, caras2;		// Vectores de Caras
        std::vector<Normal> normalCaras;    //Vector que contiene las normales de las caras
        std::vector<Normal> normalVertices; //Vector que contiene las normales de los vértices
};

#endif
