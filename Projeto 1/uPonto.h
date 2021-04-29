//---------------------------------------------------------------------------

#ifndef uPontoH
#define uPontoH
#include "uJanela.h"
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.StdCtrls.hpp>
//---------------------------------------------------------------------------

class Ponto {
  public:
    double x;
    double y;

    Ponto(double, double);
    int xW2Vp (double xwmax, double xwmin, double vpmax, double vpmin);
    int xW2Vp (Janela mundo, Janela vp);
	int yW2Vp (Janela mundo, Janela vp);
	UnicodeString toString();
	void translada(double dx, double dy, bool homo);
	void escalona(double sx, double sy);
	void pontoCentral(double dx, double dy, double n);
	void rotaciona(int angulo);
	void reflexaoX();
	void reflexaoY();
	int regionCode(Janela clipping);

};
#endif
