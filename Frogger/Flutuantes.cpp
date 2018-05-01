#include <iostream>
#include "engcomp_glib.h"

#include "Flutuantes.h"


using namespace std;

Flutuantes::Flutuantes(void)
{
	cont = 280;
	submerge = false;

	contador = 460;
	submergir = false;
}


Flutuantes::~Flutuantes(void)
{
}

void Flutuantes::CarregaTartaruga()
{
	tartaruga.carregar("turtle.png");
	submersa.carregar("turtle2.png");
}

void Flutuantes::CarregaTronco()
{
	tronco.carregar("tronco.png");
	troncosubmerso.carregar("tronco2.png");

}

void Flutuantes::DesenhaTartaruga()
{
	if(submerge == false)
	{
		tartaruga.desenha(x_tartaruga, y_tartaruga);
	}

	else
	{
		submersa.desenha(x_tartaruga, y_tartaruga);
	}

	cont --;

	if(cont == 0)
	{
		if(submerge == false)
		{
			submerge = true;
		}
		else
		{
			submerge = false;
		}
		
		cont = 280;
	}
	
	x_tartaruga += 2.1;

}

void Flutuantes::DesenhaTronco()
{
	if(submergir == false)
	{
		tronco.desenha(x_tronco, y_tronco);
	}
	else
	{
		troncosubmerso.desenha(x_tronco, y_tronco);
	}

	contador --;

	if(contador == 0)
	{
		if(submergir == false)
		{
			submergir = true;
		}

		else
		{
			submergir = false;
		}

		contador = 460;
	}

	x_tronco -= 1.2;
}

void Flutuantes::SetarPosTartaruga(float px_tartaruga, float py_tartaruga)
{
	x_tartaruga = px_tartaruga;
	y_tartaruga = py_tartaruga;

}


void Flutuantes::SetarPosTronco(float px_tronco, float py_tronco)
{
	x_tronco = px_tronco;
	y_tronco = py_tronco;
}

float Flutuantes::GetXTartaruga()
{
	return x_tartaruga;
}

float Flutuantes::GetYTartaruga()
{
	return y_tartaruga;
}


float Flutuantes::GetXTronco()
{
	return x_tronco;
}

float Flutuantes::GetYTronco()
{
	return y_tronco;
}


imagem& Flutuantes::GetSprite()
{
	return tartaruga;
}

imagem& Flutuantes::GetSubmersa()
{
	return submersa;
}

imagem& Flutuantes::GetTronco()
{
	return tronco;
}

imagem& Flutuantes::GetTroncoSubmerso()
{
	return troncosubmerso;
}

bool Flutuantes::GetSubmerge()
{
	return submerge;
}

bool Flutuantes::GetSubmergir()
{
	return submergir;
}
