#pragma once
class GameOver
{
private:
	imagem gameover;
	int x_gameover;
	int y_gameover;
public:
	GameOver(void);
	~GameOver(void);
	void CarregaSprites();
	void Desenha();
};

