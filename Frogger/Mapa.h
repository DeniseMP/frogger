#pragma once

#include "Carro.h"
#include "Sapinho.h"
#include "Vidas.h"

class Mapa
{
private:

	imagem lay;
	imagem mapa;
	imagem vidas;
	int x_mapa;
	int y_mapa;
	Carro vetorcarrobranco[6];
	Carro vetorcarrovermelho[10];
	list<Carro*>lista;


public:
	Mapa(void);
	~Mapa(void);
	void CarregaSprite();
	void Desenha();
	void DesenhaMapa(Sapinho *sp, Vidas *vd);
	imagem& GetLay();

	void AdicionarCarrosBrancos();
	void AdicionarCarrosVermelhos();
	void AdicionarCarrosAmarelos();

	Carro& GetCarrosBrancos(int i);
	Carro& GetCarrosVermelhos(int j);

};

