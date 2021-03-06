//---------------------------------------------------------------------------

#pragma hdrstop

#include "Ponto3D.h"
#include "uJanela.h"
#include <cmath>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.StdCtrls.hpp>
//---------------------------------------------------------------------------
#pragma package(smart_init)

Ponto3D::Ponto3D(double nx, double ny, double nz){
    x = nx;
	y = ny;
	z = nz;

}

 int Ponto3D::xW2Vp (double xwmax, double xwmin, double xvpmax, double xvpmin){
  return ((x - xwmin)/(xwmax -xwmin)) * (xvpmax-xvpmin);
}

int Ponto3D::xW2Vp (Janela mundo, Janela vp){
  return ((x - mundo.xmin)/(mundo.xmax - mundo.xmin)) * (vp.xmax-vp.xmin);
}

int Ponto3D::yW2Vp (Janela mundo, Janela vp){
  return (1-((y - mundo.ymin)/(mundo.ymax - mundo.ymin))) * (vp.ymax-vp.ymin);
}

UnicodeString Ponto3D::toString(){
return "(" + FloatToStr(x) + ", " + FloatToStr(y) + FloatToStr(z) +  " )";
}


void Ponto3D::translada3d(double dx, double dy, double dz){

  x += dx;
  y += dy;
  z += dz;
}

void Ponto3D::escalona3d(double de){
	x = x * de;
	y = y * de;
	z = z * de;

}

void Ponto3D::rotaciona3d(int angulo, int eixo){

	int aux = x;

	float rad =  angulo * ( M_PI / 180);

	 if(eixo == 0){
		rotacionaN3d(rad);
	   }
	   if(eixo == 1){
		rotacionaX3d(rad);
	   }
	   if(eixo == 2){
		rotacionaY3d(rad);
	   }
	   if(eixo == 3 ){
		rotacionaZ3d(rad);
	   }

}

void Ponto3D:: rotacionaN3d(double rad){



	double rx[4][4] = { {1, 0, 0, 0}, {0, cos(rad), sin(rad), 0}, {0, -sin(rad), cos(rad), 0 }, {0, 0, 0, 1}};

	double ry[4][4] = { {cos(rad), 0, -sin(rad), 0}, {0, 1, 0, 0}, {sin(rad), 0, cos(rad), 0 }, {0, 0, 0, 1}};

	double raux[4][4] = { {0}, {0}, {0}, {0}};

	double rfinal[4][4] = { {0}, {0}, {0}, {0}};

	double rxyz[1][4] = { {x,y,z,1}};

	double rxyzfinal[1][4] = { {0,0,0,1}};

	double rz[4][4] = {
		{cos(rad), sin(rad), 0, 0}, {-sin(rad), cos(rad), 0, 0}, {0, 0, 1, 0
		}, {0, 0, 0, 1}};


	for (int linha = 0; linha < 4; linha++) {

		for (int coluna = 0; coluna < 4; coluna++) {

			for (int i = 0; i < 4; i++) {

				raux[linha][coluna] += rx[linha][i] * ry[i][coluna];
			}

		}

	}
	for (int linha = 0; linha < 4; linha++) {

		for (int coluna = 0; coluna < 4; coluna++) {


			for (int i = 0; i < 4; i++) {

				rfinal[linha][coluna] += raux[linha][i] * rz[i][coluna];
			}

		}

	}
	for (int linha = 0; linha < 1; linha++) {

		for (int coluna = 0; coluna < 4; coluna++) {

			for (int i = 0; i < 4; i++) {

				rxyzfinal[linha][coluna] += rxyz[linha][i] * rfinal[i][coluna];
			}

		}

	}

	x = rxyzfinal[0][0];
	y = rxyzfinal[0][1];
	z = rxyzfinal[0][2];
}


void Ponto3D:: rotacionaX3d(double rad){

	double rx[4][4] = { {1, 0, 0, 0}, {0, cos(rad), sin(rad), 0}, {0, -sin(rad), cos(rad), 0}, {0, 0, 0, 1}};

	double ry[4][4] = { {cos(rad), 0, -sin(rad), 0}, {0, 1, 0, 0}, {sin(rad), 0, cos(rad), 0 }, {0, 0, 0, 1}};

	double rxyz[1][4] = { {x,y,z,1}};

	double rxyzfinal[1][4] = { {0,0,0,1}};

	double rz[4][4] = { {cos(rad), sin(rad), 0, 0}, {-sin(rad), cos(rad), 0, 0}, {0, 0, 1, 0 }, {0, 0, 0, 1}};


		for (int linha = 0; linha < 1; linha++) {

		for (int coluna = 0; coluna < 4; coluna++) {

			for (int i = 0; i < 4; i++) {

				rxyzfinal[linha][coluna] += rxyz[linha][i] * rx[i][coluna];
			}

		}

	}

	x = rxyzfinal[0][0];
	y = rxyzfinal[0][1];
	z = rxyzfinal[0][2];
}

void Ponto3D:: rotacionaY3d(double rad){

	double rx[4][4] = { {1, 0, 0, 0}, {0, cos(rad), sin(rad), 0}, {0, -sin(rad), cos(rad), 0}, {0, 0, 0, 1}};

	double ry[4][4] = { {cos(rad), 0, -sin(rad), 0}, {0, 1, 0, 0}, {sin(rad), 0, cos(rad), 0 }, {0, 0, 0, 1}};

	double rxyz[1][4] = { {x,y,z,1}};

	double rxyzfinal[1][4] = { {0,0,0,1}};

	double rz[4][4] = { {cos(rad), sin(rad), 0, 0}, {-sin(rad), cos(rad), 0, 0}, {0, 0, 1, 0 }, {0, 0, 0, 1}};


		for (int linha = 0; linha < 1; linha++) {

		for (int coluna = 0; coluna < 4; coluna++) {

			for (int i = 0; i < 4; i++) {

				rxyzfinal[linha][coluna] += rxyz[linha][i] * ry[i][coluna];
			}

		}

	}

	x = rxyzfinal[0][0];
	y = rxyzfinal[0][1];
	z = rxyzfinal[0][2];
}

void Ponto3D:: rotacionaZ3d(double rad){

	double rx[4][4] = { {1, 0, 0, 0}, {0, cos(rad), sin(rad), 0}, {0, -sin(rad), cos(rad), 0}, {0, 0, 0, 1}};

	double ry[4][4] = { {cos(rad), 0, -sin(rad), 0}, {0, 1, 0, 0}, {sin(rad), 0, cos(rad), 0 }, {0, 0, 0, 1}};

	double rxyz[1][4] = { {x,y,z,1}};

	double rxyzfinal[1][4] = { {0,0,0,1}};

	double rz[4][4] = { {cos(rad), sin(rad), 0, 0}, {-sin(rad), cos(rad), 0, 0}, {0, 0, 1, 0 }, {0, 0, 0, 1}};


		for (int linha = 0; linha < 1; linha++) {

		for (int coluna = 0; coluna < 4; coluna++) {

			for (int i = 0; i < 4; i++) {

				rxyzfinal[linha][coluna] += rxyz[linha][i] * rz[i][coluna];
			}

		}

	}

	x = rxyzfinal[0][0];
	y = rxyzfinal[0][1];
	z = rxyzfinal[0][2];
}

