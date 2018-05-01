#pragma once
class Vidas
{
private:
	int vidas;
public:
	Vidas(void);
	~Vidas(void);
	void Perdevida();
	int GetVidas();
	void SalvaVidas();
	void MostrarVidas();

	int& RetornaVidas();

};

