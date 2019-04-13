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

//Do zadania 3.2 czy parzyste
bool Div2(int x)
{
	return x % 2 == 0;
}

//Do zadania 3.3 czy ujemna w wketorze
bool Neg(int x)
{
	return x < 0;
}

int main()
{
	//zadanie
	int array3[N];
	LoadArray(array3, N);
	PrintArray(array3, N); //jak wyglada tablica

	//przeksztalc tablice liczb typu int w vektor intow
	std::vector<int> v(array3, array3 + N);


	std::cout << "\nMOJE ROZWIAZANIA\n";
	//ZADANIE 3.1
//Policz ile razy wystepuje jakas cyfra w vektorze (np. 856)
	std::cout << "\nZADANIE 3.1\n";
	std::cout << "liczba wystapien 856 to: " << std::count(v.begin(), v.end(), 856) << '\n';


	//ZADANIE 3.2
//Policz parzyste cyfry 
	//WYNIK - 506 liczb
	std::cout << "\nZADANIE 3.2\n";
	std::cout << "Ilosc parzystych: " << count_if(v.begin(), v.end(), Div2) << '\n';
	std::cout << "Ilosc parzystych z uzyciem lambda: " << count_if(v.begin(), v.end(), [](int i) {return i % 2 == 0; }) << '\n';


	//ZADANIE 3.3
//Sprawdz czy  w wketorze znajuduje sie jakas liczba ujemna?
	std::cout << "\nZADANIE 3.3\n";

	//z uzyciem funkcji pomocniczej
	if (std::any_of(v.begin(), v.end(), Neg))
		std::cout << "TAK\n";

	//z wykorzystaniem wyrazenia lambda
	if (std::any_of(v.begin(), v.end(), [](int i) {return i < 0; }))
		std::cout << "TAK z uzyciem lambda\n";

	//ZADANIE 3.4
//Zamien jakies wartosci w wektorze na te z ZADANIA 3.1 i policz ich liczbe po zamianie
	std::cout << "\nZADANIE 3.4\n";
	std::replace(v.begin(), v.end(), 324, 856);
	std::cout << "Nowa liczba wystapien 856 to: " << std::count(v.begin(), v.end(), 856) << '\n';


	//ZADANIE 3.5
//Znajdz pierwsza pare liczb ktora sie powtarza?
	//Jakie to liczby?
		//WYNIK - 146
	std::cout << "\nZADANIE 3.5\n";
	//Rozwiazanie 1 ( deklaracja iteratora)
	std::vector<int>::iterator sameElem;
	sameElem = std::adjacent_find(v.begin(), v.end());
	std::cout << "Pierwsze cyfry, ktore sie powtarzaja to: " << *sameElem << '\n';

	//Rozwiazanie 2 ( fikusne w jednej linijce)
	std::cout << "Fikusnie powtarzaja sie liczby:  " << *std::adjacent_find(v.begin(), v.end()) << '\n';


	//ZADANIE 3.6
//Podaj min i max w wektorze
	std::cout << "\nZADANIE 3.6\n";
	

	//wypisz najwiekszy element korzystajac z bilbioteki algorithm
	std::cout << "max: " << *std::max_element(v.begin(), v.end());
	std::cout << std::endl;
	//wypisz najmiejszy element korzystajac z bilbioteki algorithm
	std::cout << "min:  " << *std::min_element(v.begin(), v.end());
	std::cout << std::endl;


	//wypisz min i max korzystajac z jednej funkcji z biblioteki ( + na jakiej pozycji siê znajduj¹ )
	auto result = std::minmax_element(v.begin(), v.end()); //zwraca iterator
	std::cout << "min: " << *result.first;
	//pozycja z uzyciem distance()
	std::cout << ", na pozycji: " << (std::distance(v.begin(), result.first)) << '\n';
	std::cout << "max: " << *result.second;
	//pozycja przez odjecie iteratorow
	std::cout << ", na pozycji: " << (result.second - v.begin()) << '\n'; //pozycja - 0 = pozycja


	return 0;
}