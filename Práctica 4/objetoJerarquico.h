//Archivo perteneciente a la P4 de Jorge Gutiérrez Segovia grupo C1
#ifndef _OBJETOJERARQUICO_H
#define _OBJETOJERARQUICO_H
#include "cilindro.h"
#include "cubo.h"
#include "esfera.h"
class ObjetoJerarquico{

	public:
		ObjetoJerarquico(); // Constructor por defecto
		void dibujarSubidor(bool ajedrez,Objeto3d::TipoPoligono polygon);
        void dibujarBase(int traslacion, bool ajedrez,Objeto3d::TipoPoligono polygon);
		void dibujarRespaldo(bool ajedrez,float prueba,Objeto3d::TipoPoligono polygon);
        void dibujarCabezal(bool ajedrez, Objeto3d::TipoPoligono polygon);
        void dibujarAsiento(int traslacion, bool ajedrez,Objeto3d::TipoPoligono polygon);
        void dibujarReposaPies(bool ajedrez,Objeto3d::TipoPoligono polygon);
        void dibujarBrazo(bool ajedrez,Objeto3d::TipoPoligono polygon);
		void dibujarSilla(float angulo1, float angulo2, int traslacion, bool ajedrez,float sca,float prueba,Objeto3d::TipoPoligono polygon);
		//-----------TRANSFORMACION------------//
		void dibujarBrazoT(bool ajedrez,Objeto3d::TipoPoligono polygon);
		void dibujarAbdominalesT(bool ajedrez);
		void dibujarOjoT(bool ajedrez);
		void dibujarCabezaT(bool ajedrez,Objeto3d::TipoPoligono polygon);
		void dibujarTroncoT(bool ajedrez);
		void dibujarHachaT(bool ajedrez);
		void dibujarPieT(bool ajedrez);
		void dibujarPiernasT(bool ajedrez);
		void dibujarTransformacion(bool ajedrez,float sca,Objeto3d::TipoPoligono polygon);
		void dibujaEsT(bool ajedrez, float esf, float sca);

		//------------------ANIMACIONES--------/
		//void animacionT(float t, bool ajedrez,float sca);

    private:
        Cubo cubo;
        Cilindro cilindro;
		Esfera esfera;
		int vObj;

};

#endif
