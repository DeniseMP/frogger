#pragma once
class Jogo
{
private:
	
	int antes;
	int depois;

	imagem cursor;



	bool jogando;
	bool menu;
	bool configuracoes;
	bool ajuda;
	bool mapa2;
	bool gameover;
	bool youwin;

	bool trocamapa;
	bool ganhar;


public:
	Jogo(void);
	~Jogo(void);
	int rodar();

};

