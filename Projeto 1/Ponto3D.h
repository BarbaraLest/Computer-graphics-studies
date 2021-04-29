//---------------------------------------------------------------------------

#ifndef Ponto3DH
#define Ponto3DH
#include "uJanela.h"
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.StdCtrls.hpp>
//---------------------------------------------------------------------------
class Ponto3D {
  public:

    double x;
	double y;
	double z;

	Ponto3D(double, double, double);
	int xW2Vp (double xwmax, double xwmin, double vpmax, double vpmin);
    int xW2Vp (Janela mundo, Janela vp);
	int yW2Vp (Janela mundo, Janela vp);
	UnicodeString toString();

	void translada3d(double dx, double dy, double dz);
	void escalona3d(double de);

	void rotaciona3d(int angulo, int eixo);
	void rotacionaN3d(double rad);
	void rotacionaX3d(double rad);
	void rotacionaY3d(double rad);
	void rotacionaZ3d(double rad);


};
#endif
