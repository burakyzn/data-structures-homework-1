/**
* @file KovaKontrol.h
* @description KovaKontrol sinifi baslik dosyasi
* @course 2.Ogretim C Grubu
* @assignment 1.Odev
* @date 18/10/2019
* @author Burak Yazan <burak.yazan@ogr.sakarya.edu.tr>
*/

#ifndef KOVAKONTROL_H
#define KOVAKONTROL_H

#include "Kova.h"
class KovaKontrol
{
public:
	KovaKontrol(int kovaSayisi);
	void TopEkle();
	void TopYokEt();
	void KovaDegistir(int ilkKova, int ikinciKova);
	void TopDegistir(int ilkTop, int ikinciTop);
	void KovalariTerstenYerlestir();
	void ToplariTerstenYerlestir();
	void EkraniCiz();
	void Temizle();
	~KovaKontrol();
private:
	Kova** kovalar;
	int kovaSayisi;
};

#endif