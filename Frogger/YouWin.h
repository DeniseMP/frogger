#pragma once
class YouWin
{
private:
	imagem youwin;
	int x_win;
	int y_win;

public:
	YouWin(void);
	~YouWin(void);
	void CarregaSprites();
	void Desenha();
};

