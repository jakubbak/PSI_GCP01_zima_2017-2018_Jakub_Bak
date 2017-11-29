//created by Jakub Bak 29.11 - 
#pragma once

#include "Perceptron_pow.h"
#include <cstdlib>
#include <iostream>
using namespace std;


void Perceptron::pobierz_z_txt()
{
	fstream plik;
	plik.open("literki.txt");
	if (!plik.good())
	{
		cout << "ERROR_BLAD OTWARCIA PLIKU" << endl;
		system("PAUSE");
	}
	while (!plik.eof())
	{
		for (int i = 0; i < ilosc_wej; i++)
		{
			for (int j = 0; j < 72; j++)
			{
				plik >> this->literki[i][j];
			}
			plik >> this->wyniki[i];
		}
	}
	plik.close();
}

Perceptron::Perceptron()
{
	this->ilosc_wej = 15; //wprowadzamy test 10
	this->wsp_nauki = 0.2;  

	this->literki = new int*[20];
	
	for (int i = 0; i < 15; i++)
		literki[i] = new int[70];

	this->waga = new float[70];
	
	for (int i = 0; i < 70; i++)
	{
		this->waga[i] = (float)rand() / (float)RAND_MAX;
	}

	pobierz_z_txt();
}



void Perceptron::sprawdzaj(int tab[])
{

	//double global_err = 0.0;
	// nauczony_aktywacji = 1.1;
	//float suma = 0;
	float global_err = 0;
	float nauczony_aktywacji = 1.2;
	float suma = 0;
	float local_err = 0;
	
	
	for (int i = 0; i < 72; i++)
	{
		suma += tab[i] * this->waga[i];
	}
	
	local_err = 1 - suma;
	global_err = local_err*local_err;
	//if (global_err < nauczony_aktywacji)
	if (global_err < nauczony_aktywacji)
		this->wynik = true;
	else
		this->wynik = false;



	if (this->wynik != true)
		//cout << "mala litera!" << endl << endl;
		//else
		cout << "duza litera!" << endl << endl;
}


void Perceptron::ucz_sie()
{
	float blad_wew;
	
	int ID_litery;
	
	int ep = 0;
	float blad_zew = 0;
	float koniec_nauki = 1.20;
	do
	{
		blad_zew = 0;
		for (ID_litery = 0; ID_litery < this->ilosc_wej; ID_litery++)
		{
			blad_wew = this->wyniki[ID_litery] - sumuj(ID_litery);
			for (int i = 0; i < 72; i++)
			{
				this->waga[i] += this->wsp_nauki * blad_wew * this->literki[ID_litery][i];
			}

			blad_zew += (blad_wew*blad_wew);
		}
		ep++;
	} while (blad_zew > koniec_nauki);
	cout << "Liczba sesji nauki perceptronu= " << ep << endl;
}





float Perceptron::sumuj(int i)
{
	float suma = 0;
	
	
	
	for (int j = 0; j < 72; j++)
	{
		suma += this->literki[i][j] * this->waga[j];
	}
	return suma;
}




Perceptron::~Perceptron()
{
}
