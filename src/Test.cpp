/**
* @file Test.cpp
* @description test.cpp kullaniciyla KovaKontrol sinifi arasinda bir bag kurar
* @course 2.Ogretim C Grubu
* @assignment 1.Odev
* @date 18/10/2019
* @author Burak Yazan <burak.yazan@ogr.sakarya.edu.tr>
*/

#include <iostream>
#include <stdlib.h>
#include <Windows.h>
#include <time.h>
#include "KovaKontrol.h"
using namespace std;
int Kova::kovaSayisi = 0;

int main() {
	srand(time(NULL));
	int kovaSayisi = 0;
	cout << "Kova Sayisi : ";
	cin >> kovaSayisi;
	cout << endl;
	
	KovaKontrol *kontrol = new KovaKontrol(kovaSayisi);

	int yapilacakIslem = 0;
	while (yapilacakIslem != 7) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		cout << "[1] Toplari Yerlestir" << endl;
		cout << "[2] Toplari Yoket" << endl;
		cout << "[3] Kova Degistir" << endl;
		cout << "[4] Top Degistir" << endl;
		cout << "[5] Kovalari Tersten Yerlestir" << endl;
		cout << "[6] Toplari Tersten Yerlestir" << endl;
		cout << "[7] Cikis";
		cout << endl << ">>" ;
		cin >> yapilacakIslem;

		if (yapilacakIslem == 1) {
			kontrol->TopEkle();
		}
		else if (yapilacakIslem == 2) {
			kontrol->TopYokEt();
		}
		else if (yapilacakIslem == 3) {
			int ilkKova = 0;
			int ikinciKova = 0;
			cout << "Hangi Kova : " << endl;
			cin >> ilkKova;
			cout << "Hangi Kova ile : " << endl;
			cin >> ikinciKova;

			kontrol->KovaDegistir(ilkKova, ikinciKova);
		}
		else if (yapilacakIslem == 4) {
			int ilkTop = 0;
			int ikinciTop = 0;
			cout << "Hangi Top : " << endl;
			cin >> ilkTop;
			cout << "Hangi Top ile : " << endl;
			cin >> ikinciTop;

			kontrol->TopDegistir(ilkTop, ikinciTop);
		}
		else if (yapilacakIslem == 5) {
			kontrol->KovalariTerstenYerlestir();
		}
		else if (yapilacakIslem == 6) {
			kontrol->ToplariTerstenYerlestir();
		}
		else if (yapilacakIslem == 7) {
			system("cls");
			delete kontrol;
		}
		else {
			kontrol->EkraniCiz();
		}
	}

	return 0;
}