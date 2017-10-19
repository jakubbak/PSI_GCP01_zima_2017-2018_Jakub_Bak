#pragma once
#include <iostream>
#include <cmath>

using namespace std;



struct Perceptron {
	int wejscia;
	int bias;
	double *wagi;
	
	
	
	bool czy_dziala(double suma) {
		if (suma > 0)
			return 1;//aktywujemy (ustawiamy)
		else
			return 0;

	};
	double wynik(int tab[]) {
		double sum = 0;
		for (int i = 0; i < this->wejscia; i++) {
			sum += tab[i] * this->wagi[i];
		}
		return czy_dziala(sum);
	};

	void uczenie_perceptronu(int tab[], double y, double z) {
		double x = this->wynik(tab);

		for (int i = 0; i < this->wejscia; i++) {
			this->wagi[i] += (y - x) * z * tab[i];
		}
	}
	Perceptron(int wejsciaa) {
		this->wejscia = wejsciaa;
		this->wagi = new double[wejscia];

		for (int i = 0; i < wejscia; i++) {
			this->wagi[i] = 0.5;
		}
	};
};