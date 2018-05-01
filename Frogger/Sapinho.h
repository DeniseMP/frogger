#pragma once
#define parado 1
#define pulando 2


class Sapinho
{
private:
	float x_sapinho;
	float y_sapinho;
	float rot;
	float vel;
	float rad;
	
	int estado;
	
	imagem sapo;

public:
	Sapinho(void);
	~Sapinho(void);
	void CarregarSprite();
	void Desenha();
	void Atualiza();
	void Posicao();
	imagem& GetSprite();
	float GetX();
	float GetY();
	void SetarPos(int px_sapo, int py_sapo);

	float& RetornaX();
	float& RetornaY();
};

