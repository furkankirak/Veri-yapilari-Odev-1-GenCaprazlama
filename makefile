Tum: derleme baglama calistirma
derleme:
	g++ -c -I ./include ./src/main.cpp -o ./lib/main.o 
	g++ -c -I ./include ./src/Dugum.cpp -o ./lib/Dugum.o
	g++ -c -I ./include ./src/BagliListe.cpp -o ./lib/BagliListe.o  
baglama:
	g++ ./lib/main.o ./lib/Dugum.o ./lib/BagliListe.o -o ./bin/program 
calistirma:
	./bin/program