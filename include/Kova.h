/**
* @file Kova.h
* @description Kova sinifi baslik dosyasi
* @course 2.Ogretim C Grubu
* @assignment 1.Odev
* @date 18/10/2019
* @author Burak Yazan <burak.yazan@ogr.sakarya.edu.tr>
*/

#ifndef KOVA_H
#define KOVA_H

#include "Top.h"
class Kova
{
private:
	Top* kovaninTopu;
	int kovaninRengi;
	char kovaninSekli[7][9];
	Kova *kovaninAdresi;
public:
	Kova();
	void TopOlustur();
	void KovaOlustur();
	void KovaCiz();
	void TopYokEt();
	Top* getTop();
	void setTop(Top* top);
	static int kovaSayisi;
	static void kovaSayisiSifirla();
	~Kova();
};

#endif