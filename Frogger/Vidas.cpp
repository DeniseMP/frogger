#include <iostream>
#include <fstream>

using namespace std;

#include "Vidas.h"


Vidas::Vidas(void)
{
	vidas = 5;

}


Vidas::~Vidas(void)
{
}

void Vidas::Perdevida()
{
	vidas--;
}

int Vidas::GetVidas()
{
	return vidas;
}

void Vidas::SalvaVidas()
{
	fstream arqEscreve ("arquivos.dat", ios::out | ios::binary);
	arqEscreve.write((char*)&vidas, sizeof(vidas));
}

void Vidas::MostrarVidas()
{
	fstream arqLer ("arquivos.dat", ios::in | ios::binary);
	arqLer.read((char*)&vidas, sizeof(vidas));
}

int& Vidas::RetornaVidas()
{
	return vidas;
}
