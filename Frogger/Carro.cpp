#include <iostream>
#include "engcomp_glib.h"

using namespace std;

#include "Carro.h"


Carro::Carro(void)
{
}


Carro::~Carro(void)
{
}

void Carro::CarregaSpriteBranco()
{
	carrobranco.carregar("carro.png");
}

void Carro::CarregaSpriteVermelho()
{
	carrovermelho.carregar("carro3.png");

}

void Carro::CarregaSpriteAmarelo()
{
	carroamarelo.carregar("carro2.png");

}

void Carro::DesenhaBranco()
{
	carrobranco.desenha(x_branco, y_branco);

	x_branco -=2.5;

	if(x_branco < 200)
	{
		x_branco = 800;

	}



}

void Carro::DesenhaVermeho()
{
	carrovermelho.desenha(x_vermelho, y_vermelho);

	x_vermelho -=2.5;

	if(x_vermelho < 200)
	{
		x_vermelho = 1550;
	}

}

void Carro::DesenhaAmarelo()
{
	carroamarelo.desenha(x_amarelo, y_amarelo);

	x_amarelo +=3.1;
}

void Carro::SetarPosBranco(float px_branco, float py_branco)
{
	x_branco = px_branco;
	y_branco = py_branco;
}

void Carro::SetarPosAmarelo(float px_amarelo, float py_amarelo)
{
	x_amarelo = px_amarelo;
	y_amarelo = py_amarelo;
}

void Carro::SetarPosVermelho(float px_vermelho, float py_vermelho)
{
	x_vermelho = px_vermelho;
	y_vermelho = py_vermelho;

}


float Carro::getXBranco()
{
	return x_branco;
}

float Carro::getYBranco()
{
	return y_branco;
}

float Carro::getXAmarelo()
{
	return x_amarelo;
}

float Carro::getYAmaerelo()
{
	return y_amarelo;
}

float Carro::GetXVermelho()
{
	return x_vermelho;
}

float Carro::GetYVermelho()
{
	return y_vermelho;
}

imagem& Carro::GetSpriteAmarelo()
{
	return carroamarelo;
}

imagem& Carro::GetSpriteBranco()
{
	return carrobranco;
}

imagem& Carro::GetSpriteVermelho()
{
	return carrovermelho;
}