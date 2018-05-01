#pragma once


class Flutuantes
{
private:

imagem tartaruga;
imagem submersa;

imagem tronco;
imagem troncosubmerso;

float x_tartaruga;
float y_tartaruga;

float x_tronco;
float y_tronco;

int cont;
bool submerge;

int contador;
bool submergir;


public:
	Flutuantes(void);
	~Flutuantes(void);
	void CarregaTartaruga();
	void DesenhaTartaruga();

	void CarregaTronco();
	void DesenhaTronco();

	void SetarPosTartaruga(float px_tartaruga, float py_tartaruga);
	
	void SetarPosTronco(float px_tronco, float py_tronco);

    float GetXTartaruga();
	float GetYTartaruga();

	float GetXTronco();
	float GetYTronco();

	imagem& GetSprite();
	imagem& GetSubmersa();

	imagem& GetTronco();
	imagem& GetTroncoSubmerso();
	
	bool GetSubmerge();

	bool GetSubmergir();

};

