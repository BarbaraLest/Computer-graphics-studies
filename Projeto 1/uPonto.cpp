//---------------------------------------------------------------------------

#pragma hdrstop

#include "uPonto.h"
#include <cmath>
#include <vcl.h>
//---------------------------------------------------------------------------
#pragma package(smart_init)

Ponto::Ponto(double nx, double ny){
  x = nx;
  y = ny;
}

int Ponto::xW2Vp (double xwmax, double xwmin, double xvpmax, double xvpmin){
  return ((x - xwmin)/(xwmax -xwmin)) * (xvpmax-xvpmin);
}

int Ponto::xW2Vp (Janela mundo, Janela vp){
  return ((x - mundo.xmin)/(mundo.xmax - mundo.xmin)) * (vp.xmax-vp.xmin);
}

int Ponto::yW2Vp (Janela mundo, Janela vp){
  return (1-((y - mundo.ymin)/(mundo.ymax - mundo.ymin))) * (vp.ymax-vp.ymin);
}

UnicodeString Ponto::toString(){
return "(" + FloatToStr(x) + ", " + FloatToStr(y) + " )";
}

void Ponto::translada(double dx, double dy, bool homo){

  x += dx;
  y += dy;
}

void Ponto::escalona(double sx, double sy){
	x = x * sx;
	y = y * sy;

}

void Ponto::rotaciona(int angulo){

	int aux = x;

	float rad =  angulo * ( M_PI / 180);
	x = aux * cos(rad) - y * sin(rad);
	y = aux * sin(rad) + y * cos(rad);
}

void Ponto::reflexaoX(){

x = -1*x;


}

 void Ponto::reflexaoY(){


y = -1*y;

}


void Ponto::pontoCentral(double dx, double dy, double n){

   x = dx/n;
   y = dy/n;
ShowMessage( "(" + FloatToStr(x) + "," + FloatToStr(y) + ")" );
}

int Ponto::regionCode(Janela clipping){


int code = 0 ;

if(x < clipping.xmin){

  code += 1;
}
if(x > clipping.xmax){

   code += 2;
}
if(y < clipping.ymin){

   code  += 4;
}
if(y > clipping.ymax){

   code += 8;
}


  return code;

}
