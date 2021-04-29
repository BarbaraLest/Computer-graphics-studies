//---------------------------------------------------------------------------

#pragma hdrstop

#include "uDisplay.h"
#include "uJanela.h"
#include "uPoligono.h"
#include "uPonto.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)


void DisplayFile::desenha(TCanvas *canvas, Janela mundo, Janela vp, int tipoReta, int id, bool D){

	canvas->Pen->Color = clRed;
	canvas->Pen->Width = 3;

	canvas->Brush->Color = clWhite;
	canvas->FillRect(Rect(0, 0, 500, 500));

	for(int i = 0; i < poligonos.size(); i++){

	if(i == id){
	poligonos[i].desenha(canvas, mundo, vp, tipoReta,  D);
	}else {
		poligonos[i].desenha(canvas, mundo, vp, tipoReta,  false);
	}



	}
}

void DisplayFile::mostra(TListBox *listbox){
	listbox->Clear();
	for(int i = 0; i < poligonos.size(); i++){
		listbox->Items->Add(poligonos[i].toString());

	}
}

void DisplayFile::mostraPontos(int qualPoligono, TListBox *listbox){
   poligonos[qualPoligono].mostraPontos(listbox);
}

void DisplayFile::clipping(Janela clipping, int *Id){

	Poligono aux;
	int size = poligonos.size();

	for(int i = 3; i < size; i++){

		poligonos[i].cohenSutherland(clipping, &aux);

	  if (aux.pontos.size() != 0){
		 aux.id = *Id;
		*Id = *Id +1;
	  aux.tipo = 'R';
		poligonos.push_back(aux);
		aux.pontos.clear();
	  }
   }


}

void DisplayFile::casteljau(int contaId){

    Poligono aux;

	poligonos[contaId].casteljau(&aux);

	if (aux.pontos.size() != 0){

		aux.id = contaId;
		contaId = contaId + 1;
		aux.tipo = 'A';
		poligonos.push_back(aux);
		aux.pontos.clear();

	}


}

void DisplayFile::hermite(int contaId){

    Poligono aux;

	poligonos[contaId].algoritmoHermite(&aux);

	if (aux.pontos.size() != 0){

		aux.id = contaId;
		contaId = contaId + 1;
		aux.tipo = 'H';
		poligonos.push_back(aux);
		aux.pontos.clear();

	}


}

void DisplayFile::bezier(int contaId){

    Poligono aux;

	poligonos[contaId].algoritmoBezier(&aux);

	if (aux.pontos.size() != 0){

		aux.id = contaId;
		contaId = contaId + 1;
		aux.tipo = 'H';
		poligonos.push_back(aux);
		aux.pontos.clear();

	}


}

void DisplayFile::bspline(int contaId){

	Poligono aux;

	poligonos[contaId].algoritmoBspline(&aux);

	if (aux.pontos.size() != 0){

		aux.id = contaId;
		contaId = contaId + 1;
		aux.tipo = 'S';
		poligonos.push_back(aux);
		aux.pontos.clear();

	}


}

void DisplayFile::bsplineFoward(int contaId){

	Poligono aux;

	poligonos[contaId].algoritmoBspline(&aux);

	if (aux.pontos.size() != 0){

		aux.id = contaId;
		contaId = contaId + 1;
		aux.tipo = 'F';
		poligonos.push_back(aux);
		aux.pontos.clear();

	}


}
