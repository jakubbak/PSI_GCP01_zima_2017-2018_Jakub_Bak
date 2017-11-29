#pragma once
#include <iostream>

#include <ctime>
#include <fstream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cmath>





using namespace std;

class Perceptron
{
	
	
	//double wejs;
	int ilosc_wej;
	float wsp_nauki;
	//float waga;

	int **literki;
	float *waga;

	int wyniki[20];
	bool wynik;
	

public:
	Perceptron();
	void ucz_sie();
	void pobierz_z_txt();
	
	//sprawdz(int p[]);
	
	void sprawdzaj(int tab[]);
	float sumuj(int i);



	~Perceptron();
};
