#pragma once
class Menus
{
private:
	imagem menu;
	imagem ajuda;
	imagem configuracoes;
	imagem jogar;

	imagem tema;

	imagem menuajuda;

	int x_ajuda;
	int y_ajuda;

	int x_config;
	int y_config;

	int x_jogar;
	int y_jogar;

	int x_tema;
	int y_tema;


public:
	Menus(void);
	~Menus(void);

	void MenuCarregar();
	void MenuDesenha();

	void ConfigDesenha();

	void AjudaDesenha();


	int GetxJogar();
	int GetyJogar();

	imagem& GetJogar();

	int GetxConfig();
	int GetyConfig();

	imagem& GetConfig();

	int GetxAjuda();
	int GetyAjuda();

	imagem& GetAjuda();

	int GetXTema();
	int GetYTema();

	imagem& GetTema();
	



};

