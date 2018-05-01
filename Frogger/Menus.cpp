#include <iostream>
#include "engcomp_glib.h"



using namespace std;

#include "Menus.h"


Menus::Menus(void)
{
	x_ajuda = 450;
	y_ajuda = 480;

	x_config = 450;
	y_config = 540;

	x_jogar = 450;
	y_jogar = 600;

	x_tema = 445;
	y_tema = 563;
}


Menus::~Menus(void)
{
}

void Menus::MenuCarregar()
{
	menu.carregar("menu.png");
	ajuda.carregar("ajuda.png");
	configuracoes.carregar("config.png");
	jogar.carregar("jogar.png");
	menuajuda.carregar("menu_ajuda.png");
	tema.carregar("tema.png");

}

void Menus::MenuDesenha()
{

	menu.desenha(220, 405);
	ajuda.desenha(x_ajuda,y_ajuda);
	configuracoes.desenha(x_config,y_config);
	jogar.desenha(x_jogar, y_jogar);
}

void Menus::ConfigDesenha()
{
	menu.desenha(220, 405);
	tema.desenha(x_tema, y_tema);
}

void Menus::AjudaDesenha()
{
	menu.desenha(220, 405);
	menuajuda.desenha(310,435);
}

int Menus::GetxJogar()
{
	return x_jogar;
}

int Menus::GetyJogar()
{
	return y_jogar;
}

imagem& Menus::GetJogar()
{
	return jogar;
}

int Menus::GetxConfig()
{
	return x_config;
}

int Menus::GetyConfig()
{
	return y_config;
}

imagem& Menus::GetConfig()
{
	return configuracoes;
}


int Menus::GetxAjuda()
{
	return x_ajuda;
}

int Menus::GetyAjuda()
{
	return y_ajuda;
}

imagem& Menus::GetAjuda()
{
	return ajuda;
}

imagem& Menus::GetTema()
{
	return tema;
}

int Menus::GetXTema()
{
	return x_tema;
}

int Menus::GetYTema()
{
	return y_tema;
}