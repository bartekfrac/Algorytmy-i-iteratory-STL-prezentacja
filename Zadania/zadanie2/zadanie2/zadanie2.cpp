#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>
#include <ctime>

// 2.1 napisz funkcje sortuj ktora sortuje vector o dowolnej wielkosci
// BEZ WYKORZYSTANIA std::sort()
// mozna skorzystac z gotowych funkcji w internecie

// kod

int main()
{
	std::vector<int> losowe1;
	std::vector<int> losowe2;
	const int ROZMIAR = 1000;
	// pseudolosowosc
	std::default_random_engine silnik;
	std::uniform_real_distribution<double> rozklad;
	auto czas = std::chrono::system_clock::now();
	auto interwal = czas.time_since_epoch();
	silnik.seed(interwal.count());

	// 1000 losowych liczb do vectorow losowe1 i losowe2
	for (int i = 0; i < ROZMIAR; i++)
	{
		losowe1.push_back(rozklad(silnik) * 100);
		losowe2.push_back(rozklad(silnik) * 100);
	}

	// 2.2 wywolaj funkcje napisana w zadaniu 2.1 dla vectora losowe1
	// sprawdz jaki program podaje wynik

	auto start1 = std::chrono::system_clock::now();

	// kod

	auto koniec1 = std::chrono::system_clock::now();
	std::chrono::duration<double> uplynelo1 = koniec1 - start1;

	// 2.3 wywolaj funkcje std::sort( , ) dla vectora losowe2
	auto start2 = std::chrono::system_clock::now();

	// kod

	auto koniec2 = std::chrono::system_clock::now();
	std::chrono::duration<double> uplynelo2 = koniec2 - start2;

	// WYNIKI:
	std::cout << "Twoja funkcja: \t" << uplynelo1.count() << "s\n";
	std::cout << "std::sort(): \t" << uplynelo2.count() << "s\n";

	return 0;
}
