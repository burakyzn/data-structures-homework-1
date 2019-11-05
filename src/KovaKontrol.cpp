/**
* @file KovaKontrol.cpp
* @description KovaKontrol.cpp kovayla ilgili tum olayların yonetildigi kisimdir
* @course 2.Ogretim C Grubu
* @assignment 1.Odev
* @date 18/10/2019
* @author Burak Yazan <burak.yazan@ogr.sakarya.edu.tr>
*/

#include "KovaKontrol.h"
#include "Kova.h"
#include "Top.h"
#include <iostream>
#include <Windows.h>
using namespace std;

KovaKontrol::KovaKontrol(int kovaSayisi)
{
	this->kovaSayisi = kovaSayisi;

	kovalar = new Kova *[this->kovaSayisi];
	for (int i = 0; i < this->kovaSayisi; i++) {
		*(kovalar + i) = new Kova;
	}
}

void KovaKontrol::TopEkle()
{
	if ((*(kovalar))->getTop() == NULL) {
		system("cls");
		Kova::kovaSayisiSifirla();
		for (int i = 0; i < this->kovaSayisi; i++) {
			(*(kovalar + i))->TopOlustur();
		}
	}

	EkraniCiz();
}

void KovaKontrol::TopYokEt()
{
	if ((*(kovalar))->getTop() != NULL) {
		system("cls");
		Kova::kovaSayisiSifirla();
		for (int i = 0; i < kovaSayisi; i++) {
			(*(kovalar + i))->TopYokEt();
		}
	}

	EkraniCiz();
}

void KovaKontrol::KovaDegistir(int ilkKova, int ikinciKova)
{
	if (ilkKova >= 0 && ilkKova <= kovaSayisi && ikinciKova >= 0 && ikinciKova <= kovaSayisi) {
		Kova* ptr_temp = *(kovalar + ilkKova - 1);
		*(kovalar + ilkKova - 1) = *(kovalar + ikinciKova - 1);
		*(kovalar + ikinciKova - 1) = ptr_temp;
	}
	
	EkraniCiz();
}

void KovaKontrol::TopDegistir(int ilkTop, int ikinciTop)
{
	if (ilkTop >= 0 && ilkTop <= kovaSayisi && ikinciTop >= 0 && ikinciTop - 1 <= kovaSayisi) {
		Top* ptr = (*(kovalar + ilkTop - 1))->getTop();
		(*(kovalar + ilkTop - 1))->setTop((*(kovalar + ikinciTop - 1))->getTop());
		(*(kovalar + ikinciTop - 1))->setTop(ptr);
	}

	EkraniCiz();
}

void KovaKontrol::KovalariTerstenYerlestir()
{
	Kova** temp = new Kova * [kovaSayisi];
	for (int i = 0; i < kovaSayisi; i++) {
		*(temp + i) = *(kovalar + i);
	}

	for (int i = 0; i < kovaSayisi; i++) {
		*(kovalar + i) = *(temp + kovaSayisi - i - 1);
	}

	EkraniCiz();

	delete[] temp;
}

void KovaKontrol::ToplariTerstenYerlestir()
{
	Top** temp = new Top * [kovaSayisi];
	for (int i = 0; i < kovaSayisi; i++) {
		*(temp + i) = (*(kovalar + i))->getTop();
	}

	for (int i = 0; i < kovaSayisi; i++) {
		(*(kovalar + i))->setTop(*(temp + kovaSayisi - i - 1));
	}

	EkraniCiz();

	delete[] temp;
}

void KovaKontrol::EkraniCiz()
{
	Kova::kovaSayisiSifirla();
	system("cls");
	for (int i = 0; i < kovaSayisi; i++) {
		(*(kovalar + i))->KovaCiz();
	}
}

KovaKontrol::~KovaKontrol()
{
	for (int i = 0; i < kovaSayisi; i++) {
		delete* (kovalar + i);
	}
	delete[] kovalar;
}