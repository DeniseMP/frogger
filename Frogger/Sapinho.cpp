#include <iostream>
#include <string>
#include <sstream>
#include "engcomp_glib.h"

using namespace std;

#include "Sapinho.h"




Sapinho::Sapinho(void)
{
	x_sapinho = 510;
	y_sapinho = 690;

	rot = 0;
	vel = 0.8;

	estado = parado;
}


Sapinho::~Sapinho(void)
{
}

void Sapinho::CarregarSprite()
{
	sapo.carregar("frog2.png");
}

void Sapinho::Desenha()
{
	sapo.desenha_rotacionado(x_sapinho,y_sapinho,rot);
}

void Sapinho::Atualiza()
{
	const float pi= (3.1416/180);


	if (key[SDLK_LEFT])
	{
		rot+=vel;
	}

	if(key[SDLK_RIGHT])
	{
		rot-=vel;
	}
	if (key[SDLK_UP] && estado != pulando)
	{
		rad = rot*pi;
		x_sapinho += (cos(rad)*vel)*118.4;
		y_sapinho += (-sin(rad) *vel)*118.4;

		estado = pulando;
	
	}
	if (key[SDLK_DOWN] && estado != pulando)
	{
		rad = rot*pi;
		x_sapinho -= (cos(rad)*vel)*80.4;
		y_sapinho -= (-sin(rad) *vel)*80.4;

		estado = pulando;

	}

	if(!key[SDLK_UP] && !key[SDLK_DOWN])
	{
		estado = parado;
	}
}

void Sapinho::Posicao()
{
	x_sapinho = 510;
	y_sapinho = 690;
}

imagem& Sapinho::GetSprite()
{
	return sapo;
}

float Sapinho::GetX()
{
	return x_sapinho;
}

float Sapinho::GetY()
{
	return y_sapinho;
}

void Sapinho::SetarPos(int px_sapo, int py_sapo)
{
	x_sapinho = px_sapo;
	y_sapinho = py_sapo;
}

float& Sapinho::RetornaX()
{
	return x_sapinho;
}

float& Sapinho::RetornaY()
{
	return y_sapinho;
}


