#include <iostream>
#include "Perceptron.h"

using namespace std;

void main() {


	
	
	
	
	//liczba sesji do modyfikacji (testowanie)
	
	
	int ilosc_uczenia_sie = 5; 
	int bias = 1;
	
	//double wskazniki=0.2;
	double wspolczynnik_uczenia = 0.4;
	int wejscia = 3;

	int tablica1[] = { bias,0,0 };
	int tablica2[] = { bias,0,1 };
	int tablica3[] = { bias,1,0 };
	int tablica4[] = { bias,1,1 };
	//int tablica
	/*int tablica1[] = { bias,0,0 };
	int tablica2[] = { bias,1,0 };
	int tablica3[] = { bias,0,1 };
	int tablica4[] = { bias,1,1 };
	*/

	int tab1[] = { 0,1,0,1 };
	int tab2[] = { 0,0,1,1 };
	int taby[] = { 0,0,0,1 };



	Perceptron *perceptron = new Perceptron(wejscia);



		for (int i = 0; i < ilosc_uczenia_sie; i++) {
			for (int j = 0; j < 4; j++) {
				int wartosci[] = { bias, tab1[j], tab2[j] };
					perceptron->uczenie_perceptronu(wartosci, taby[j], wspolczynnik_uczenia);
		}

	}


		cout << " 4 dobre 0,0,0,1 " << endl;
		cout << " 3 dobre 0,0,1,1 " << endl;
		cout << " 2 dobre 0,1,1,1 " << endl;
		cout << "WYPISANIE WYNIKOW" << endl;

		cout << "1 wynik="<< perceptron->wynik(tablica1) << endl;
	
	cout << "2 wynik="<<perceptron->wynik(tablica2) << endl;
	
	cout << "3 wynik="<<perceptron->wynik(tablica3) << endl;
	
	cout << "4 wynik="<<perceptron->wynik(tablica4) << endl;

	cout << "KONIEC" << endl;

	system("PAUSE");

}