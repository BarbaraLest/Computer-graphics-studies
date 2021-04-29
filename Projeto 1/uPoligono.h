//---------------------------------------------------------------------------

#ifndef uPoligonoH
#define uPoligonoH
#include "uPonto.h"
#include "Ponto3D.h"
#include <vector>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.StdCtrls.hpp>

//---------------------------------------------------------------------------
class Poligono {
		public:
		std::vector <Ponto> pontos;
        std::vector <Ponto3D> pontos3D;
		int id;
		char tipo;

		void desenha(TCanvas *canvas, Janela mundo, Janela vp, int tipoReta, bool = false);
		UnicodeString toString();
		void mostraPontos(TListBox *listbox);
		void LineTo(TCanvas *canvas, Janela mundo, Janela vp, bool D);
		void Dda(TCanvas *canvas, Janela mundo, Janela vp);
		void DdaAlgoritmo(TCanvas *canvas, int xvp1, int yvp1, int xvp2, int yvp2);
		void Bresenham(TCanvas *canvas, Janela mundo, Janela vp);
		void BresenhamAlgoritmo(TCanvas *canvas, int xvp1, int yvp1, int xvp2, int yvp2);
		void translada(double dx, double dy, bool homo);
		void algoritmoHomogeneo(int x1, int y1);
		double pontoCentralHomogeneo(double aux, char tipo);
		void escalona(double sx, double sy);
		void rotaciona(int angulo);
		void reflexaoX();
		void reflexaoY();
		void pontoCentral();
		void Circunferencia(int xc, int yc, int r);
		void DesenhaPontoCircunferencia(int xc, int yc, int x, int y );
		void cohenSutherland(Janela clipping, Poligono *aux);
		double coeficienteAngular(double x1, double y1, double x2, double y2);
		void casteljau(Poligono *aux);
		void algoritmoCasteljau(Ponto p0, Ponto p1, Ponto p2, Poligono *aux);
		void algoritmoHermite( Poligono *aux);
		void algoritmoBezier( Poligono *aux);
		void algoritmoBspline( Poligono *aux);
		void algoritmoBsplineFoward(Poligono *aux);
		void mostraPontos3D(TListBox *listbox);
		void translada3d(double dx, double dy, double dz);
		void escalona3d(double de);
		void rotaciona3d(double angulo, int eixo);



		};
#endif
