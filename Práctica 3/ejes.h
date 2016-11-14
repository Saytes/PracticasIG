//Archivo perteneciente a la P2 de Jorge Gutiérrez Segovia grupo C1
#ifndef _EJES_H
#define _EJES_H

class Ejes {

private:
	float axisSize;
	float vertexArray[18];
	float colorArray[18];

public:
	Ejes();
	void changeAxisSize(float newSize);
	void draw();

private:
	void createArrayData();
	void drawBeginEnd();
	void drawArray();
};
#endif
