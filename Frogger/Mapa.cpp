#include <iostream>
#include <list>
#include "engcomp_glib.h"

using namespace std;

#include "Carro.h"
#include "Mapa.h"
#include "Sapinho.h"
#include "Vidas.h"


Mapa::Mapa(void)
{
}


Mapa::~Mapa(void)
{
}

void Mapa::CarregaSprite()
{

	mapa.carregar("mapa1.png");


	lay.carregar("sapo1.png");
	lay.carregar("sapo2.png");



    AdicionarCarrosBrancos();
	AdicionarCarrosVermelhos();
	AdicionarCarrosAmarelos();

}

void Mapa::Desenha()
{
	
	lay.desenha(0,0);

}

void Mapa::DesenhaMapa(Sapinho *sp, Vidas *vd)
{
	mapa.desenha(220, 405);

	for (int j = 0; j < 6; j++)
	{
		vetorcarrobranco[j].DesenhaBranco();

	}

	for(int i = 0; i < 10; i++)
	{
		vetorcarrovermelho[i].DesenhaVermeho();
	}

	list<Carro*>::iterator it = lista.begin();
	while(it != lista.end())
	{
		(*it)->DesenhaAmarelo();

		Carro* cr = *it;

		if(cr->GetSpriteAmarelo().colide(cr->getXAmarelo(),cr->getYAmaerelo(),sp->GetX(),sp->GetY(),sp->GetSprite()))
		{
			sp->Posicao();

			vd->Perdevida();
		}

		if(cr->getXAmarelo() > 780)
		{
			it = lista.erase(it);

			Carro* temp;
			temp = new Carro();
			temp->CarregaSpriteAmarelo();
			temp->SetarPosAmarelo(0,550);
			lista.push_back(temp);
		}
		else
		{
			it++;
		}

		
	}	



}


imagem& Mapa::GetLay()
{
	return lay;
}

void Mapa::AdicionarCarrosBrancos()
{
	vetorcarrobranco[0].SetarPosBranco(500,490);
	vetorcarrobranco[0].CarregaSpriteBranco();

	vetorcarrobranco[1].SetarPosBranco(570,450);
	vetorcarrobranco[1].CarregaSpriteBranco();

	vetorcarrobranco[2].SetarPosBranco(750,467);
	vetorcarrobranco[2].CarregaSpriteBranco();
	
	vetorcarrobranco[3].SetarPosBranco(890,470);
	vetorcarrobranco[3].CarregaSpriteBranco();

	vetorcarrobranco[4].SetarPosBranco(940,450);
	vetorcarrobranco[4].CarregaSpriteBranco();

	vetorcarrobranco[5].SetarPosBranco(1000,480);
	vetorcarrobranco[5].CarregaSpriteBranco();

}

void Mapa::AdicionarCarrosAmarelos()
{
	Carro* temp = new Carro();
	temp->CarregaSpriteAmarelo();
	temp->SetarPosAmarelo(200,550);
	lista.push_back(temp);

	temp = new Carro();
	temp->CarregaSpriteAmarelo();
	temp->SetarPosAmarelo(100,550);
	lista.push_back(temp);

	temp = new Carro();
	temp->CarregaSpriteAmarelo();
	temp->SetarPosAmarelo(0,550);
	lista.push_back(temp);
}

void Mapa::AdicionarCarrosVermelhos()
{
	vetorcarrovermelho[0].SetarPosVermelho(500,630);
	vetorcarrovermelho[0].CarregaSpriteVermelho();

	vetorcarrovermelho[1].SetarPosVermelho(600,650);
	vetorcarrovermelho[1].CarregaSpriteVermelho();

	vetorcarrovermelho[2].SetarPosVermelho(700,660);
	vetorcarrovermelho[2].CarregaSpriteVermelho();

	vetorcarrovermelho[3].SetarPosVermelho(800,630);
	vetorcarrovermelho[3].CarregaSpriteVermelho();

	vetorcarrovermelho[4].SetarPosVermelho(950,650);
	vetorcarrovermelho[4].CarregaSpriteVermelho();

	vetorcarrovermelho[5].SetarPosVermelho(1200,660);
	vetorcarrovermelho[5].CarregaSpriteVermelho();

	vetorcarrovermelho[6].SetarPosVermelho(1300,630);
	vetorcarrovermelho[6].CarregaSpriteVermelho();

	vetorcarrovermelho[7].SetarPosVermelho(1400,660);
	vetorcarrovermelho[7].CarregaSpriteVermelho();

	vetorcarrovermelho[8].SetarPosVermelho(1550,630);
	vetorcarrovermelho[8].CarregaSpriteVermelho();

	vetorcarrovermelho[9].SetarPosVermelho(1650,660);
	vetorcarrovermelho[9].CarregaSpriteVermelho();
}

Carro& Mapa::GetCarrosBrancos(int i)
{
	return vetorcarrobranco[i];
}

Carro& Mapa::GetCarrosVermelhos(int j)
{
	return vetorcarrovermelho[j];
}


