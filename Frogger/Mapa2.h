#include "Flutuantes.h"
#include "Sapinho.h"
#include "Vidas.h"


#pragma once

class Mapa2
{
private:
	imagem mapa2;

	vector<Flutuantes*> turtle; 
	
	vector<Flutuantes*> tronco;

	bool colisao;

public:
	Mapa2(void);
	~Mapa2(void);

	void CarregaSprites();
	void Desenha(Sapinho *sp, Vidas *vd);
	void AdicionarTartarugas();
	void AdicionarTroncos();

	bool GetColisao();
};

