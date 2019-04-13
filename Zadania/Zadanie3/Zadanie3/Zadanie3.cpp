#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
const int N = 1000;

void PrintArray(int tab[], int n)
{
	for (int i = 0; i < n; i++)
	{
		std::cout << tab[i] << " ";
	}
	std::cout << std::endl;
}

void LoadArray(int arr[], const int N)
{
	std::ifstream file("tablica.txt");
	if (file.is_open())
	{
		for (int i = 0; i < N; i++)
			file >> arr[i];
	}
}

int main()
{
	//zadanie
	int array3[N];
	LoadArray(array3, N);
	PrintArray(array3, N); //jak wyglada tablica

	//ZADANIE 3

	// MUST HAVE - bo nie bedzie dzialac :(
	//przeksztalc tablice liczb typu int w vektor intow
	

	std::cout << "\nMOJE ROZWIAZANIA\n";
	//ZADANIE 3.1
//Policz ile razy wystepuje jakas cyfra w vektorze (np. 856)
	std::cout << "\nZADANIE 3.1\n";
	

	//ZADANIE 3.2
//Policz parzyste cyfry 
	//WYNIK - 506 liczb
	std::cout << "\nZADANIE 3.2\n";


	//ZADANIE 3.3
//Sprawdz czy  w wketorze znajuduje sie jakas liczba ujemna?
	std::cout << "\nZADANIE 3.3\n";

	

	//ZADANIE 3.4
//Zamien jakies wartosci w wektorze na te z ZADANIA 3.1 i policz ich liczbe po zamianie
	std::cout << "\nZADANIE 3.4\n";
	

	//ZADANIE 3.5
//Znajdz pierwsza pare liczb ktora sie powtarza?
	//Jakie to liczby?
		//WYNIK - 146
	std::cout << "\nZADANIE 3.5\n";


	//ZADANIE 3.6
//Podaj min i max w wektorze
	std::cout << "\nZADANIE 3.6\n";
	
	//3.6.1
	//znajdz i wypisz najwiekszy element korzystajac z bilbioteki algorithm
	
	//3.6.2
	//znajdz i wypisz najmiejszy element korzystajac z bilbioteki algorithm
	
	//3.6.3
	//wypisz min i max korzystajac z jednej funkcji z biblioteki ( + na jakiej pozycji siê znajduj¹ )

	

	return 0;
}