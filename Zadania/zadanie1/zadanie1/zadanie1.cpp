#include "pch.h"
#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
#include <string>

// 1.1 
// napisz funkcje ktora wyswietli zawartosc vectora 
// wykorzystaj interator oraz begin() i end()
void wyswietlVector(std::vector<std::string> v)
{
	// kod 
}

int main()
{
	std::vector <std::string> slowa = { " Ala", " ma", " kota" }; // Ala ma kota
	std::vector <std::string> dodatek = { " i", " Roman", "ja" };
	std::vector<std::string>::iterator miejsceJa = slowa.begin() + 2;
	copy(dodatek.end() - 1, dodatek.end(), inserter(slowa, miejsceJa)); // Ala maja kota

	// 1.2 stworz nowy iterator "poczatek" wskazujacy na poczatek vectora slowa
	
	// kod

	// 1.3 stworz nowy iterator "miejsceRomka" ktory wskazuje na nastepne miejsce od iteratora poczatek
	// wykorzystaj next( , )
	
	// kod

	// 1.4 wykorzystaj funkcje copy( , , ) oraz insterter( , )
	// tak aby " i", " Roman" znalazly sie
	// w vectorze slowa za slowem " Ala"
	// aby powstalo " Ala i Roman maja kota"
	// PRZYKLAD DZIALANIA COPY I INSERTER WYKOMENTOWANY NA POCZĄTKU MAINA PO PRAWEJ STRONIE

	// kod

	// 1.5 
	// przetestuj funkcje wyswietlVector 
	// sprawdz czy wyswietla " Ala i Roman maja kota"

	// kod

	return 0;
}
