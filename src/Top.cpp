/**
* @file Top.cpp
* @description Top.cpp top sinifini gercekler
* @course 2.Ogretim C Grubu
* @assignment 1.Odev
* @date 18/10/2019
* @author Burak Yazan <burak.yazan@ogr.sakarya.edu.tr>
*/

#include "Top.h"
#include <iostream>
#include <cstdlib>

Top::Top()
{
	int harf = rand() % 26 + 65;
	this->topTemsilci = char(harf);
}

char Top::getTopTemsilci()
{
	return (this->topTemsilci);
}
