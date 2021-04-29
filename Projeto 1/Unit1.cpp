//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "uJanela.h"
#include "uPonto.h"
#include "uPoligono.h"
#include "uDisplay.h"
#include <vector>
#include "Project1PCH1.h"
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.StdCtrls.hpp>
#include "Ponto3D.h"
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <conio.h>
#include <string>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TrgReta *rgReta;
Ponto aux(0,0);
Ponto3D aux3d(0, 0, 0);
Janela mundo(-250, -250, 250, 250);
Janela vp(0,0,500,500);
Janela clipping(-100, -100, 100, 100);
Poligono pol;
DisplayFile display;
int contaId = 0;
bool incluir = false;

double xVp2W (int xvp, Janela mundo, Janela vp){
	return ((xvp-vp.xmin)/(vp.xmax - vp.xmin)) * (mundo.xmax - mundo.xmin) + mundo.xmin;
}

double yVp2W (int yvp, Janela mundo, Janela vp){
	return (1-((yvp-vp.ymin)/(vp.ymax - vp.ymin))) * (mundo.ymax - mundo.ymin) + mundo.ymin;
}
//---------------------------------------------------------------------------
__fastcall TrgReta::TrgReta(TComponent* Owner)
	: TForm(Owner)
{

	//ponto 1 da vertical
	aux.x = 0;
	aux.y = mundo.ymax;
	pol.pontos.push_back(aux);
	//ponto 2 da vertical
	pol.pontos.push_back(Ponto(0, mundo.ymin));
	pol.id = contaId++;
	pol.tipo = 'E'; //eixo
	display.poligonos.push_back(pol);
	pol.pontos.clear();


	//ponto 1 da horizontal
	pol.pontos.push_back(Ponto(mundo.xmin, 0));
	//ponto 2 da horixontal
	pol.pontos.push_back(Ponto(mundo.xmax, 0));
	pol.id = contaId++;
	pol.tipo = 'E'; //eixo
	display.poligonos.push_back(pol);
	pol.pontos.clear();


	//formação janela de clipping
	pol.pontos.push_back(Ponto(clipping.xmin, clipping.ymin));
	pol.pontos.push_back(Ponto(clipping.xmin, clipping.ymax));
	pol.pontos.push_back(Ponto(clipping.xmax, clipping.ymax));
	pol.pontos.push_back(Ponto(clipping.xmax, clipping.ymin));
	pol.pontos.push_back(Ponto(clipping.xmin, clipping.ymin));
	pol.id = contaId++;
	pol.tipo = 'E'; //eixo
	display.poligonos.push_back(pol);
	pol.pontos.clear();

   //	pol.pontos.push_back(Ponto(-250, -250));
   //	pol.pontos.push_back(Ponto(250, 250));
   //	display.poligonos.push_back(pol);



	display.desenha(Image1->Canvas, mundo, vp, rgRetas->ItemIndex);
	display.mostra(lbPoligonos);


}
//---------------------------------------------------------------------------
void __fastcall TrgReta::Button1Click(TObject *Sender)
{
   incluir = true;
}
//---------------------------------------------------------------------------

void __fastcall TrgReta::Image1MouseMove(TObject *Sender, TShiftState Shift, int X,
          int Y)
{
    double xw, yw;
   lbVp->Caption = IntToStr(X) + ", " + IntToStr(Y);
   xw = xVp2W(X, mundo, vp);
   yw = yVp2W(Y, mundo, vp);
   lbMundo->Caption = FloatToStr(xw) + ", " + FloatToStr(yw);
}
//---------------------------------------------------------------------------

void __fastcall TrgReta::Image1MouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y)
{
if(Button == mbLeft){
		if(incluir){
					aux.x = xVp2W(X, mundo, vp);
					aux.y = yVp2W(Y, mundo, vp);
					pol.pontos.push_back(aux);
		}
	}
	else
	if (Button == mbRight) {
		incluir = false;
		if(pol.pontos.size() > 0){
				pol.id = contaId++;
				pol.tipo = 'D'; //desenho
				display.poligonos.push_back(pol);
				pol.pontos.clear();

				display.desenha(Image1->Canvas, mundo, vp, rgRetas->ItemIndex);
				display.mostra(lbPoligonos);
		}
	}

   //ShowMessage(FloatToStr(aux.x) + ", " + FloatToStr(aux.y));
}
//---------------------------------------------------------------------------

void __fastcall TrgReta::lbPoligonosClick(TObject *Sender)
{
	display.mostraPontos(lbPoligonos->ItemIndex, lbPontos);
}
//---------------------------------------------------------------------------


void __fastcall TrgReta::btnLeftClick(TObject *Sender)
{
		mundo.xmax -= -1*(StrToFloat(lbValor->Text));
		mundo.xmin -= -1*(StrToFloat(lbValor->Text));

		display.poligonos[0].pontos[0].y = mundo.ymax;
		display.poligonos[0].pontos[1].y = mundo.ymin;
		display.poligonos[1].pontos[1].x = mundo.xmax;
		display.poligonos[1].pontos[0].x = mundo.xmin;

		display.desenha(Image1->Canvas, mundo, vp, rgRetas->ItemIndex);
}
//---------------------------------------------------------------------------

void __fastcall TrgReta::btnRightClick(TObject *Sender)
{
	mundo.xmax -= StrToFloat(lbValor->Text);
	mundo.xmin -= StrToFloat(lbValor->Text);

	display.poligonos[0].pontos[0].y = mundo.ymax;
	display.poligonos[0].pontos[1].y = mundo.ymin;
	display.poligonos[1].pontos[1].x = mundo.xmax;
	display.poligonos[1].pontos[0].x = mundo.xmin;

	display.desenha(Image1->Canvas, mundo, vp, rgRetas->ItemIndex);
}
//---------------------------------------------------------------------------

void __fastcall TrgReta::btnUpClick(TObject *Sender)
{
	mundo.ymax -= StrToFloat(lbValor->Text);
	mundo.ymin -= StrToFloat(lbValor->Text);

	display.poligonos[0].pontos[0].y = mundo.ymax;
	display.poligonos[0].pontos[1].y = mundo.ymin;
	display.poligonos[1].pontos[1].x = mundo.xmax;
	display.poligonos[1].pontos[0].x = mundo.xmin;

	display.desenha(Image1->Canvas, mundo, vp, rgRetas->ItemIndex);
}
//---------------------------------------------------------------------------

void __fastcall TrgReta::btnDownClick(TObject *Sender)
{
		mundo.ymax -= -1*(StrToFloat(lbValor->Text));
		mundo.ymin -= -1*(StrToFloat(lbValor->Text));

		display.poligonos[0].pontos[0].y = mundo.ymax;
		display.poligonos[0].pontos[1].y = mundo.ymin;
		display.poligonos[1].pontos[1].x = mundo.xmax;
		display.poligonos[1].pontos[0].x = mundo.xmin;

		display.desenha(Image1->Canvas, mundo, vp, rgRetas->ItemIndex);
}
//---------------------------------------------------------------------------
void __fastcall TrgReta::btnInClick(TObject *Sender)
{
		mundo.ymax -=  20;
		mundo.ymin -=  -1*20;
		mundo.xmax -=  20;
		mundo.xmin -=  -1*20;


		display.poligonos[0].pontos[0].y = mundo.ymax;
		display.poligonos[0].pontos[1].y = mundo.ymin;
		display.poligonos[1].pontos[1].x = mundo.xmax;
		display.poligonos[1].pontos[0].x = mundo.xmin;

		display.desenha(Image1->Canvas, mundo, vp, rgRetas->ItemIndex);
}
//---------------------------------------------------------------------------

void __fastcall TrgReta::Button3Click(TObject *Sender)
{
		mundo.ymax +=  20;
		mundo.ymin +=  -1*20;
		mundo.xmax +=  20;
		mundo.xmin +=  -1*20;


		display.poligonos[0].pontos[0].y = mundo.ymax;
		display.poligonos[0].pontos[1].y = mundo.ymin;
		display.poligonos[1].pontos[1].x = mundo.xmax;
		display.poligonos[1].pontos[0].x = mundo.xmin;

		display.desenha(Image1->Canvas, mundo, vp, rgRetas->ItemIndex);
}
//---------------------------------------------------------------------------


void __fastcall TrgReta::Button2Click(TObject *Sender)
{
		mundo.ymax -=  (StrToFloat(lbValor->Text));
		mundo.ymin -=  -1*(StrToFloat(lbValor->Text));
		mundo.xmax -= (StrToFloat(lbValor->Text));
		mundo.xmin -=  -1*(StrToFloat(lbValor->Text));


		display.poligonos[0].pontos[0].y = mundo.ymax;
		display.poligonos[0].pontos[1].y = mundo.ymin;
		display.poligonos[1].pontos[1].x = mundo.xmax;
		display.poligonos[1].pontos[0].x = mundo.xmin;

		display.desenha(Image1->Canvas, mundo, vp, rgRetas->ItemIndex);
}
//---------------------------------------------------------------------------

void __fastcall TrgReta::Button4Click(TObject *Sender)
{
		mundo.ymax += (StrToFloat(lbValor->Text));
		mundo.ymin +=  -1*(StrToFloat(lbValor->Text));
		mundo.xmax +=  (StrToFloat(lbValor->Text));
		mundo.xmin +=  -1*(StrToFloat(lbValor->Text));


		display.poligonos[0].pontos[0].y = mundo.ymax;
		display.poligonos[0].pontos[1].y = mundo.ymin;
		display.poligonos[1].pontos[1].x = mundo.xmax;
		display.poligonos[1].pontos[0].x = mundo.xmin;

		display.desenha(Image1->Canvas, mundo, vp, rgRetas->ItemIndex);
}
//---------------------------------------------------------------------------

void __fastcall TrgReta::Button6Click(TObject *Sender)
{
	  double dx, dy;
	  dx = StrToFloat(Edit1->Text);
	  dy = StrToFloat(Edit2->Text);

	  bool homo = false;
	  display.poligonos[lbPoligonos->ItemIndex].translada(dx, dy, homo);
	  display.desenha(Image1->Canvas, mundo, vp, rgRetas->ItemIndex);

}
//---------------------------------------------------------------------------


void __fastcall TrgReta::Button7Click(TObject *Sender)
{
	   double sx, sy;
	  sx = StrToFloat(Edit4->Text);
	  sy = StrToFloat(Edit5->Text);

	  display.poligonos[lbPoligonos->ItemIndex].escalona(sx, sy);
	  display.desenha(Image1->Canvas, mundo, vp, rgRetas->ItemIndex);
}
//---------------------------------------------------------------------------


void __fastcall TrgReta::Button5Click(TObject *Sender)
{
	  int angulo;
	  angulo = StrToInt(edit10->Text);


	  display.poligonos[lbPoligonos->ItemIndex].rotaciona(angulo);
	  display.desenha(Image1->Canvas, mundo, vp, rgRetas->ItemIndex);
}
//---------------------------------------------------------------------------

void __fastcall TrgReta::Button8Click(TObject *Sender)
{
	display.poligonos[lbPoligonos->ItemIndex].reflexaoX();
	  display.desenha(Image1->Canvas, mundo, vp, rgRetas->ItemIndex);
}
//---------------------------------------------------------------------------

void __fastcall TrgReta::Button9Click(TObject *Sender)
{

	double xc, yc, r;
	xc = StrToFloat(lbxc -> Text);
	yc = StrToFloat(lbyc -> Text);
	 r = StrToFloat(raio ->Text);

	 pol.Circunferencia(xc, yc, r);
	 pol.id = contaId++;
	 pol.tipo = 'C';

	 display.poligonos.push_back(pol);
	 pol.pontos.clear();

	  display.desenha(Image1->Canvas, mundo, vp, rgRetas->ItemIndex);
	  display.mostra(lbPoligonos);

}
//---------------------------------------------------------------------------

void __fastcall TrgReta::Button11Click(TObject *Sender)
{

	display.poligonos[lbPoligonos->ItemIndex].pontoCentral();


}
//---------------------------------------------------------------------------

void __fastcall TrgReta::Button10Click(TObject *Sender)
{
   double angulo;
   int x,  y;
   bool homo = true;
   char tipo;

  angulo = StrToInt(edit10->Text);
  tipo = 'x';
  x =  display.poligonos[lbPoligonos->ItemIndex].pontoCentralHomogeneo(x, tipo);

  tipo = 'y';
  y =  display.poligonos[lbPoligonos->ItemIndex].pontoCentralHomogeneo(y, tipo);

	display.poligonos[lbPoligonos->ItemIndex].translada(0 , 0, homo);
	display.poligonos[lbPoligonos->ItemIndex].rotaciona(angulo);
	display.poligonos[lbPoligonos->ItemIndex].translada(x , y, homo);

	display.desenha(Image1->Canvas, mundo, vp, rgRetas->ItemIndex);


}
//---------------------------------------------------------------------------


void __fastcall TrgReta::Button14Click(TObject *Sender)
{
	display.clipping(clipping, &contaId);

	display.desenha(Image1->Canvas, mundo, vp, rgRetas->ItemIndex);
	display.mostra(lbPoligonos);
}
//---------------------------------------------------------------------------


void __fastcall TrgReta::Button15Click(TObject *Sender)

{   mundo.xmax = StrToFloat(edxmax->Text);
	mundo.xmin = StrToFloat(edxmin->Text);
	mundo.ymax = StrToFloat(edymax->Text);
	mundo.ymin = StrToFloat(edymin->Text);

	display.poligonos[0].pontos[0].y = mundo.ymax;
	display.poligonos[1].pontos[1].x = mundo.xmax;
	display.poligonos[0].pontos[1].y = mundo.ymin;
	display.poligonos[1].pontos[0].x = mundo.xmin;


	display.desenha(Image1->Canvas, mundo, vp, rgRetas->ItemIndex);

}
//---------------------------------------------------------------------------

void __fastcall TrgReta::Button16Click(TObject *Sender)
{
	display.casteljau(lbPoligonos->ItemIndex);

	display.desenha(Image1->Canvas, mundo, vp, rgRetas->ItemIndex);
	display.mostra(lbPoligonos);
}
//---------------------------------------------------------------------------

void __fastcall TrgReta::Button17Click(TObject *Sender)
{
	display.hermite(lbPoligonos->ItemIndex);

	display.desenha(Image1->Canvas, mundo, vp, rgRetas->ItemIndex);
	display.mostra(lbPoligonos);
}
//---------------------------------------------------------------------------

void __fastcall TrgReta::Button18Click(TObject *Sender)
{
	display.bezier(lbPoligonos->ItemIndex);

	display.desenha(Image1->Canvas, mundo, vp, rgRetas->ItemIndex);
	display.mostra(lbPoligonos);
}
//---------------------------------------------------------------------------

void __fastcall TrgReta::Button19Click(TObject *Sender)
{
	display.bspline(lbPoligonos->ItemIndex);

	display.desenha(Image1->Canvas, mundo, vp, rgRetas->ItemIndex);
	display.mostra(lbPoligonos);

}
//---------------------------------------------------------------------------

void __fastcall TrgReta::Button20Click(TObject *Sender)
{
   display.bsplineFoward(lbPoligonos->ItemIndex);

	display.desenha(Image1->Canvas, mundo, vp, rgRetas->ItemIndex);
	display.mostra(lbPoligonos);

}
//---------------------------------------------------------------------------

void __fastcall TrgReta::Button21Click(TObject *Sender)
{
FILE *arquivo = NULL;
	char palavra[10], caracter[4];
	int i = 0, j = 0, x, y, z;
	arquivo = fopen("C:/Users/barba/OneDrive/Documentos/GitHub/CGI/Projeto/piramidePontos.txt", "r+");

	while(!feof(arquivo)){
		fgets(palavra, 255, arquivo);

		  if (i == 1) {
			y =std::stoi(palavra);
		 }
		 if (i == 0) {
			x =std::stoi(palavra);
		 }
		 if (i == 2) {
			z =std::stoi(palavra);
		 }

		 i++;

		 if (i == 3){
			 i = 0;
			 aux3d.x = x;
			 aux3d.y = y;
			 aux3d.z = z;

			pol.pontos3D.push_back(aux3d);
		 }
	}


	if(pol.pontos3D.size() >0){

		pol.id = contaId++;
		pol.tipo = 'I'; //Desenho
		display.poligonos.push_back(pol);
		pol.pontos3D.clear();
		display.desenha(Image1->Canvas, mundo, vp, rgRetas->ItemIndex, pol.id, true);
		display.mostra(lbPoligonos);
	}

	fclose(arquivo);


}
//---------------------------------------------------------------------------

void __fastcall TrgReta::Button23Click(TObject *Sender)
{
 double dx, dy, dz;
	  dx = StrToFloat(Edit3->Text);
	  dy = StrToFloat(Edit8->Text);
	  dz = StrToFloat(Edit9->Text);

	  display.poligonos[lbPoligonos->ItemIndex].translada3d(dx, dy, dz);
	  int id = lbPoligonos->ItemIndex;
	  display.desenha(Image1->Canvas, mundo, vp, rgRetas->ItemIndex, id, true);
}
//---------------------------------------------------------------------------








void __fastcall TrgReta::Button24Click(TObject *Sender)
{

	double angulo = StrToFloat(Edit11->Text);
	int eixo =   StrToFloat(Edit13->Text);

	display.poligonos[lbPoligonos->ItemIndex].rotaciona3d(angulo, eixo);
	  int id = lbPoligonos->ItemIndex;
	  display.desenha(Image1->Canvas, mundo, vp, rgRetas->ItemIndex, id, true);


}
//---------------------------------------------------------------------------

void __fastcall TrgReta::Button25Click(TObject *Sender)
{
	double dz = StrToFloat(Edit17->Text);

	display.poligonos[lbPoligonos->ItemIndex].escalona3d(dz);
	  int id = lbPoligonos->ItemIndex;
	  display.desenha(Image1->Canvas, mundo, vp, rgRetas->ItemIndex, id, true);}
//---------------------------------------------------------------------------

void __fastcall TrgReta::Button22Click(TObject *Sender)
{
FILE *arquivo = NULL;
	char palavra[10], caracter[4];
	int i = 0, j = 0, x, y, z;
	arquivo = fopen("C:/Users/barba/OneDrive/Documentos/GitHub/CGI/Projeto/paralelepipedoPontos.txt", "r+");

	while(!feof(arquivo)){
		fgets(palavra, 255, arquivo);

		  if (i == 1) {
			y =std::stoi(palavra);
		 }
		 if (i == 0) {
			x =std::stoi(palavra);
		 }
		 if (i == 2) {
			z =std::stoi(palavra);
		 }

		 i++;

		 if (i == 3){
			 i = 0;
			 aux3d.x = x;
			 aux3d.y = y;
			 aux3d.z = z;

			pol.pontos3D.push_back(aux3d);
		 }
	}


	if(pol.pontos3D.size() >0){

		pol.id = contaId++;
		pol.tipo = 'P'; //Desenho
		display.poligonos.push_back(pol);
		pol.pontos3D.clear();
		display.desenha(Image1->Canvas, mundo, vp, rgRetas->ItemIndex, pol.id, true);
		display.mostra(lbPoligonos);
	}

	fclose(arquivo);
}
//---------------------------------------------------------------------------

void __fastcall TrgReta::Button26Click(TObject *Sender)
{

	display.poligonos[lbPoligonos->ItemIndex].reflexaoY();
	  display.desenha(Image1->Canvas, mundo, vp, rgRetas->ItemIndex);
}
//---------------------------------------------------------------------------

