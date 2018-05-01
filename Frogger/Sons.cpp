#include <iostream>

#include "engcomp_glib.h"

using namespace std;

#include "Sons.h"


Sons::Sons(void)
{
}


Sons::~Sons(void)
{
}

void Sons::SonsCarregar()
{
	tema.carregar("tema.wav");
	pulo.carregar("pulo.wav");
}

void Sons::TemaTocar()
{

	tema.tocar();
}

void Sons::PuloTocar()
{
	pulo.tocar();
}

void Sons::ParaSom()
{
	tema.parar();
}
