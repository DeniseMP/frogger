#pragma once
class Carro
{
private:
	imagem carrobranco;
	imagem carrovermelho;
	imagem carroamarelo;

	float x_branco;
	float y_branco;

	float x_vermelho;
	float y_vermelho;

	float x_amarelo;
	float y_amarelo;


public:
	Carro(void);
	~Carro(void);
	void CarregaSpriteBranco();
	void CarregaSpriteVermelho();
	void CarregaSpriteAmarelo();

	void DesenhaBranco();
	void DesenhaVermeho();
	void DesenhaAmarelo();

	void SetarPosBranco (float px_branco, float py_branco);
	void SetarPosVermelho (float px_vermelho, float py_vermelho);
	void SetarPosAmarelo (float px_amarelo, float py_amarelo);

	float getXBranco();
	float getYBranco();

	float getXAmarelo();
	float getYAmaerelo();

	float GetXVermelho();
	float GetYVermelho();

	imagem& GetSpriteAmarelo();
	imagem& GetSpriteBranco();
	imagem& GetSpriteVermelho();
};


