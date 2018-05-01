#include <iostream>
#include "engcomp_glib.h"

using namespace std;

#include "YouWin.h"



YouWin::YouWin(void)
{
	x_win = 230;
	y_win = 405;
}


YouWin::~YouWin(void)
{
}

void YouWin::CarregaSprites()
{
	youwin.carregar("youwin.png");
}

void YouWin::Desenha()
{
	youwin.desenha(x_win,y_win);
}
