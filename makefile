# @file makefile
# @description makefile derleme dosyasi
# @course 2.Ogretim C Grubu
# @assignment 1.Odev
# @date 18/10/2019
# @author Burak Yazan <burak.yazan@ogr.sakarya.edu.tr>

hepsi: nesneler derle calistir
nesneler:
	g++ -I ./include/ -o ./lib/Top.o -c ./src/Top.cpp
	g++ -I ./include/ -o ./lib/Kova.o -c ./src/Kova.cpp
	g++ -I ./include/ -o ./lib/KovaKontrol.o -c ./src/KovaKontrol.cpp
derle:	
	g++ -I ./include/ -o ./bin/Test ./lib/Top.o ./lib/Kova.o ./lib/KovaKontrol.o ./src/Test.cpp
calistir:
	./bin/Test