#include <iostream>

using namespace std;

#include "engcomp_glib.h"
#include "GameOver.h"



GameOver::GameOver(void)
{
	x_gameover = 350;
	y_gameover = 480;
}


GameOver::~GameOver(void)
{
}

void GameOver::CarregaSprites()
{
	gameover.carregar("gameover2.png");
}

void GameOver::Desenha()
{
	gameover.desenha(x_gameover,y_gameover);
}
