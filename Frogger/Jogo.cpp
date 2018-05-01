#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "engcomp_glib.h"

using namespace std;

#include "Menus.h"
#include "Carro.h"
#include "Mapa.h"
#include "Mapa2.h"
#include "Flutuantes.h"
#include "Sapinho.h"
#include "Jogo.h"
#include "Vidas.h"
#include "GameOver.h"
#include "YouWin.h"
#include "Sons.h"

string converte(int val)
{
	string temp;
	stringstream conv;

	conv << val;
	conv >> temp;

	return temp;
}

Jogo::Jogo(void)
{
	trocamapa = false;
}


Jogo::~Jogo(void)
{
}

int Jogo::rodar()
{
	egl_inicializar(1024,768,true);
	SDL_ShowCursor(false);
	
	Mapa level;
	Mapa2 leveis;
	Sapinho sapo;
	Menus mens;
	Flutuantes ft;
	Vidas vd;
	GameOver go;
	YouWin yw;
	Sons song;

	sapo.CarregarSprite();
	level.CarregaSprite();
	leveis.CarregaSprites();
	mens.MenuCarregar();
	go.CarregaSprites();
	yw.CarregaSprites();
	song.SonsCarregar();



	cursor.carregar("sapinho_cursor3.png");

	jogando = false;
	menu = true;
	configuracoes = false;
	ajuda = false;
	mapa2 = false;
	gameover = false;
	youwin = false;
	
	trocamapa = false;
	ganhar = false;


	while(!key[SDLK_ESCAPE])
	{
		antes = SDL_GetTicks();

		egl_texto(converte(vd.GetVidas()),915,36);
		
		if (vd.GetVidas()<= 0)
		{
			jogando = false;
			mapa2 = false;
			gameover = true;
			youwin = false;

		}

		if(ganhar = true && vd.GetVidas() > 0 && sapo.GetY() < 460)
		{
			jogando = false;
			mapa2 = false;
			gameover = false;
			youwin = true;
		}

		if(key[SDLK_BACKSPACE])
		{
			menu= true;
			jogando= false;	
			configuracoes = false;
			ajuda = false;
			mapa2 = false;
			youwin = false;
			gameover = false;

		}

		if(jogando == true && key[SDLK_UP])
		{
			song.PuloTocar();
		}

		if(mapa2 == true && key[SDLK_UP])
		{
			song.PuloTocar();
		}

	

		if(key[SDLK_s])
		{

			fstream arqEscreve ("arquivos.dat", ios::out | ios::binary);
			arqEscreve.write((char*)&mapa2, sizeof(mapa2));
			arqEscreve.write((char*)&jogando, sizeof(jogando));
			arqEscreve.write((char*)&gameover, sizeof(gameover));
			arqEscreve.write((char*)&youwin, sizeof(youwin));
			arqEscreve.write((char*)&vd.RetornaVidas(),sizeof(int));
			arqEscreve.write((char*)&sapo.RetornaX(), sizeof(float));
			arqEscreve.write((char*)&sapo.RetornaY(), sizeof(float));
		}

		if(key[SDLK_l])
		{
			fstream arqLer ("arquivos.dat", ios::in | ios::binary);
			arqLer.read((char*)&mapa2, sizeof(mapa2));
			arqLer.read((char*)&jogando, sizeof(jogando));
			arqLer.read((char*)&gameover, sizeof(gameover));
			arqLer.read((char*)&youwin, sizeof(youwin));
			arqLer.read((char*)&vd.RetornaVidas(),sizeof(int));
			arqLer.read((char*)&sapo.RetornaX(), sizeof(float));
			arqLer.read((char*)&sapo.RetornaY(), sizeof(float));

		}


		if (gameover == true && jogando == false && menu == false && configuracoes == false && ajuda == false && mapa2 == false && youwin == false)
		{
			go.Desenha();
			level.Desenha();
			cursor.desenha(mouse_x,mouse_y);
		}

		if (menu == true && jogando == false && configuracoes == false && ajuda == false && mapa2 == false)
		{
			mens.MenuDesenha();
			level.Desenha();
		    cursor.desenha(mouse_x,mouse_y);
		}

		if (jogando == true && menu == false && configuracoes == false && ajuda == false && mapa2 == false && gameover == false && youwin == false)
		{

			sapo.Atualiza();
		    level.DesenhaMapa(&sapo, &vd);
		    sapo.Desenha();
			level.Desenha();
		    cursor.desenha(mouse_x,mouse_y);

			if(sapo.GetY() < 420)
			{
				jogando = false;
				mapa2 = true;
				menu = false;
				configuracoes = false;
				ajuda = false;
				gameover = false;
				youwin = false;

				sapo.Posicao();
			}

			trocamapa = false;

		}


		if(configuracoes == true && menu == false && jogando == false && ajuda == false && mapa2 == false)
		{
			mens.ConfigDesenha();
			level.Desenha();
		    cursor.desenha(mouse_x,mouse_y);

		}

		if( ajuda == true && menu == false && configuracoes == false && jogando == false && mapa2 == false)
		{
			mens.AjudaDesenha();
			level.Desenha();
			cursor.desenha(mouse_x,mouse_y);
		}

		if(mapa2 == true && jogando == false && menu == false && configuracoes ==  false && ajuda == false && gameover == false && youwin == false)
		{

			sapo.Atualiza();
			leveis.Desenha(&sapo, &vd);
			sapo.Desenha();
			level.Desenha();
			cursor.desenha(mouse_x,mouse_y);

			trocamapa = true;
			ganhar = true;
		}

		if(youwin == true && mapa2 == false && jogando == false && menu == false && configuracoes ==  false && ajuda == false && gameover == false)
		{
			yw.Desenha();
			level.Desenha();
			cursor.desenha(mouse_x,mouse_y);

		}



		if(mouse_b && menu == true)
		{
			if(cursor.colide(mouse_x,mouse_y,mens.GetxJogar(),mens.GetyJogar(),mens.GetJogar()))
			{
				if(trocamapa == false)
				{
			jogando = true;
			menu = false;
			configuracoes = false;
			ajuda = false;
				}

				if(trocamapa == true)
				{
			menu = false;
			configuracoes = false;
			ajuda = false;
			mapa2 = true;
				}
		
			}

			if(mouse_b)
			{
				if(cursor.colide(mouse_x,mouse_y,mens.GetXTema(),mens.GetYTema(),mens.GetTema()))
				{
					song.TemaTocar();
				}
			}

			if(cursor.colide(mouse_x,mouse_y,mens.GetxConfig(),mens.GetyConfig(),mens.GetConfig()))
			{
				configuracoes = true;
				jogando = false;
				menu = false;
				ajuda = false;
				mapa2 = false;
				gameover = false;
				youwin = false;
			}

			if(cursor.colide(mouse_x, mouse_y, mens.GetxAjuda(), mens.GetyAjuda(),mens.GetAjuda()))
			{
				ajuda = true;
				configuracoes = false;
				jogando = false;
				menu = false;
				mapa2 = false;
				gameover = false;
				youwin = false;

			}
		}


		for(int i = 0; i<10; i++)
		{
			if(sapo.GetSprite().colide(sapo.GetX(),sapo.GetY(),0,0,level.GetLay()))
			{
				sapo.Posicao();

				vd.Perdevida();

			}
		}

		for(int i = 0; i < 6; i++)
		{
		if(level.GetCarrosBrancos(i).GetSpriteBranco().colide(level.GetCarrosBrancos(i).getXBranco(),level.GetCarrosBrancos(i).getYBranco(),sapo.GetX(),sapo.GetY(),sapo.GetSprite()))
		{
			sapo.Posicao();

			vd.Perdevida();
		}
		}


		for(int j = 0; j < 10; j++)
		{
			if(level.GetCarrosVermelhos(j).GetSpriteVermelho().colide(level.GetCarrosVermelhos(j).GetXVermelho(),level.GetCarrosVermelhos(j).GetYVermelho(),sapo.GetX(),sapo.GetY(),sapo.GetSprite()))
			{
				sapo.Posicao();

				vd.Perdevida();
			}
		}

		if(trocamapa == true && sapo.GetY() > 460 && sapo.GetY() < 660 && leveis.GetColisao()== false)
		{
			sapo.Posicao();
			vd.Perdevida();	
		}

		while(SDL_GetTicks() - antes < 12);

		egl_desenha_frame();
	}

	egl_finalizar();

	return 0;
}
