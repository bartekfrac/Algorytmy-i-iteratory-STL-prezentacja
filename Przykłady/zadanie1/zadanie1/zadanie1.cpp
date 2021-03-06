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
	std::vector<std::string>::iterator i;
	for (i = v.begin(); i != v.end(); i++)
	{
		std::cout << *i;
	}
	std::cout << std::endl;
}

int main()
{
	std::vector <std::string> slowa = { " Ala", " ma", " kota" }; // Ala ma kota
	std::vector <std::string> dodatek = { " i", " Roman", "ja" };	
	std::vector<std::string>::iterator miejsceJa = slowa.begin() + 2;
	copy(dodatek.end() - 1, dodatek.end(), inserter(slowa, miejsceJa)); // Ala maja kota
	
	// 1.2 stworz nowy iterator "poczatek" wskazujacy na poczatek vectora slowa
	std::vector<std::string>::iterator poczatek = slowa.begin();
	// 1.3 stworz nowy iterator "miejsceRomka" ktory wskazuje na nastepne miejsce od iteratora poczatek
	// wykorzystaj next( , )
	std::vector<std::string>::iterator miejsceRomka = next(poczatek, 1);

	// 1.4 wykorzystaj funkcje copy( , , ) oraz insterter( , )
	// tak aby " i", " Roman" znalazly sie
	// w vectorze slowa za slowem " Ala"
	// aby powstalo " Ala i Roman maja kota"

	copy(dodatek.begin(), dodatek.end() - 1, inserter(slowa, miejsceRomka));

	// 1.5 
	// przetestuj funkcje wyswietlVector 
	// sprawdz czy wyswietla " Ala i Roman maja kota"

	wyswietlVector(slowa);

	return 0;
}
