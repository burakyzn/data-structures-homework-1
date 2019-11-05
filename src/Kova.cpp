/**
* @file Kova.cpp
* @description Kova.cpp Kova sinifini gercekler
* @course 2.Ogretim C Grubu
* @assignment 1.Odev
* @date 18/10/2019
* @author Burak YAZAN <burak.yazan@ogr.sakarya.edu.tr>
*/

#include "Kova.h"
#include "Top.h"
#include <iostream>
#include <Windows.h>
#include <cstdlib>

using namespace std;

Kova::Kova()
{
	kovaninTopu = NULL;
	kovaninAdresi = this;
	this->kovaninRengi = rand() %15 + 1;
	KovaOlustur();
	KovaCiz();
}

void Kova::KovaOlustur()
{
	char kovaTemp[7][9] = {
	{' ',' ',' ','.','|','.',' ',' ',' '},
	{' ',' ','.',' ',' ',' ','.',' ',' '},
	{' ','.',' ',' ',' ',' ',' ','.',' '},
	{' ','#',' ',' ',' ',' ',' ','#',' '},
	{' ','#',' ',' ','-',' ',' ','#',' '},
	{' ','#',' ',' ',' ',' ',' ','#',' '},
	{' ','#','#','#','#','#','#','#','\0'}
	};

	for (int i = 0; i < 7; i++) {
		for (int j = 0; j < 9; j++) {
			kovaninSekli[i][j] = kovaTemp[i][j];
		}
	}
}

void Kova::KovaCiz()
{
	kovaSayisi++;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	cout << " " << kovaSayisi << ".Kova" << endl;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), this->kovaninRengi);
	for (int i = 0; i < 7; i++) {
		for (int j = 0; j < 9; j++) {
			if (i == 4 && j == 4 && kovaninTopu != NULL) {
				cout << kovaninTopu->getTopTemsilci();
			}
			else {
				cout << kovaninSekli[i][j];
			}		
		}
		cout << endl;
	}

	cout << endl << "Kova adres : " << this->kovaninAdresi << endl;
	if (kovaninTopu == NULL) {
		cout << "Topun adresi  : NULL" << endl;
	}
	else {
		cout << "Topun adresi : " << kovaninTopu << endl;
	}
	cout << endl << endl;
}

void Kova::TopOlustur()
{
	this->kovaninTopu = new Top();
}

void Kova::TopYokEt()
{
	delete kovaninTopu;
	kovaninTopu = NULL;
}

Top* Kova::getTop()
{
	return (this->kovaninTopu);
}

void Kova::setTop(Top* top)
{
	this->kovaninTopu = top;
}

void Kova::kovaSayisiSifirla()
{
	kovaSayisi = 0;
}

Kova::~Kova()
{
	delete kovaninTopu;
}




