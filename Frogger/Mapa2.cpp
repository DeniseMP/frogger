#include <iostream>
#include <vector>
#include "engcomp_glib.h"

#include "Mapa2.h"
#include "Flutuantes.h"
#include "Sapinho.h"
#include "Vidas.h"

Mapa2::Mapa2(void)
{
	colisao = false;

}


Mapa2::~Mapa2(void)
{
}

void Mapa2::CarregaSprites()
{
	mapa2.carregar("mapa4.png");

	AdicionarTartarugas();
	AdicionarTroncos();


}

void Mapa2::Desenha(Sapinho *sp, Vidas *vd)
{

	mapa2.desenha(220,400);


	vector<Flutuantes*>::iterator it = turtle.begin();
	while(it != turtle.end())
	{
		(*it)->DesenhaTartaruga();
		
		Flutuantes* ft = *it;

		if(ft->GetSprite().colide(ft->GetXTartaruga(),ft->GetYTartaruga(),sp->GetX(), sp->GetY(),sp->GetSprite()) && ft->GetSubmerge() == false)
			{
				sp->SetarPos(ft->GetXTartaruga(),ft->GetYTartaruga());

				colisao = true;
		}


		if(ft->GetSubmersa().colide(ft->GetXTartaruga(),ft->GetYTartaruga(),sp->GetX(),sp->GetY(),sp->GetSprite()) && ft->GetSubmerge() == true)
		{
			sp->Posicao();

			vd->Perdevida();

		}


		if(ft->GetXTartaruga() > 720)
		{
			it= turtle.erase(it);

			Flutuantes* temp;
			temp = new Flutuantes();
			temp->CarregaTartaruga();
			temp->SetarPosTartaruga(0,610);
			turtle.push_back(temp);
			colisao = false;

		}

		else
		{
			it++;
		}

	}


	vector<Flutuantes*>::iterator itr= tronco.begin();
	while(itr != tronco.end())
	{
		(*itr)->DesenhaTronco();

		Flutuantes* tron = *itr;


		if(tron->GetTronco().colide(tron->GetXTronco(),tron->GetYTronco(),sp->GetX(),sp->GetY(),sp->GetSprite()) && tron->GetSubmergir()==false)
		{
			sp->SetarPos(tron->GetXTronco(),tron->GetYTronco());

			colisao = true;
		}

		if(tron->GetTroncoSubmerso().colide(tron->GetXTronco(),tron->GetYTronco(),sp->GetX(),sp->GetY(),sp->GetSprite()) && tron->GetSubmergir()==true)
		{
			sp->Posicao();
			vd->Perdevida();

		}


		if(tron->GetXTronco() < 200)
		{
			itr= tronco.erase(itr);

			Flutuantes* tep;
			tep = new Flutuantes();
			tep->CarregaTronco();
			tep->SetarPosTronco(1100, 510);
			tronco.push_back(tep);
			colisao = false;
		}

		else
		{
			itr++;

		}

	}

	
}

void Mapa2::AdicionarTartarugas()
{
	Flutuantes*temp = new Flutuantes();
	temp->CarregaTartaruga();
	temp->SetarPosTartaruga(100, 610);
	turtle.push_back(temp);

	temp = new Flutuantes();
	temp->CarregaTartaruga();
	temp->SetarPosTartaruga(250, 610);
	turtle.push_back(temp);

	temp = new Flutuantes();
	temp->CarregaTartaruga();
	temp->SetarPosTartaruga(400, 610);
	turtle.push_back(temp);

	temp = new Flutuantes();
	temp->CarregaTartaruga();
	temp->SetarPosTartaruga(450, 610);
	turtle.push_back(temp);

}

void Mapa2::AdicionarTroncos()
{
	Flutuantes*tron = new Flutuantes();
	tron->CarregaTronco();
	tron->SetarPosTronco(700, 510);
	tronco.push_back(tron);

	tron = new Flutuantes();
	tron->CarregaTronco();
	tron->SetarPosTronco(1000, 510);
	tronco.push_back(tron);
}

bool Mapa2::GetColisao()
{
	return colisao;
}
