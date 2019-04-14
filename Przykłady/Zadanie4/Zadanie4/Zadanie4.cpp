#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

//ZADANIE 4.1
class Osoba
{
public:
	string Imie;
	string Nazwisko;
	int Wiek;
	float Wzrost;

	Osoba()
	{
		this->Imie = " ";
		this->Nazwisko = " ";
		this->Wiek = 0;
		this->Wzrost = 0.0;
	}

	string const GetImie() { return this->Imie; };
	string const GetNazwisko() { return this->Nazwisko; };
	int const GetWiek() { return this->Wiek; }
	float const GetWzrost() { return this->Wzrost; };

	Osoba(string Imie, string Nazwisko, int Wiek, float Wzrost) : Imie(Imie), Nazwisko(Nazwisko), Wiek(Wiek), Wzrost(Wzrost) {};

	friend ostream& operator <<(ostream& wyjscie, Osoba& data)
	{
		wyjscie << "Imie: " << setw(7) << left << data.GetImie()
			<< "\tNazwisko: " << setw(7) << left << data.GetNazwisko()
			<< "\tWiek: " << setw(7) << left << data.GetWiek()
			<< "\tWzrost: " << setw(7) << left << data.GetWzrost() << endl;
		return wyjscie;
	}
};

//ZADANIE 4.3
bool SortImie(Osoba osoba1, Osoba osoba2)
{
	return osoba1.Imie < osoba2.Imie;
}

//ZADANIE 4.3
void Wyswietl(Osoba osoba)
{
	std::cout << osoba;
}

int main()
{
	//ZADANIE 4.1
//Stworz klase Osoba ktora posiada pola 
	// Imie - string
	// Nazwisko - string
	// Wiek - int
	// Wzrost - float

	//ZADANIE 4.2
//Stworz wektor 4 obiektow tej klasy i wypelnij go przykladowymi osobami (np. Jan Nowak 18 170.5)
	Osoba osoba1{ "Adam","Toron",18,168.7f };
	Osoba osoba2{ "Tomasz","Borek",45,190.2f };
	Osoba osoba3{ "Maria","Kowalska",65,150.0f };
	Osoba osoba4{ "Barbara","Kolanko",23,170.5f };

	vector<Osoba> ListaOsob;
	ListaOsob.push_back(osoba1);
	ListaOsob.push_back(osoba2);
	ListaOsob.push_back(osoba3);
	ListaOsob.push_back(osoba4);

	//ZADANIE 4.3
//Posortuj wektor z ZADANIA 4.2 po imieniu osoby 

	//Rozwiazanie 1 z deklaracj¹ fukcji pomocniczych (wypisanie oraz sortowanie)
	cout << "Przed posortowaniem (ListaOsob)" << endl;
	for_each(ListaOsob.begin(), ListaOsob.end(), Wyswietl);
	sort(ListaOsob.begin(), ListaOsob.end(), SortImie);
	cout << "\nPosortowane po Imie" << endl;
	for_each(ListaOsob.begin(), ListaOsob.end(), Wyswietl);
	cout << endl << "##############################################################################" << endl;

	//Rozwiazanie 2 z wykorzystaniem wyrazenia lambda
	cout << "\nPrzed posortowaniem lambda (ListaOsob)" << endl;
	for_each(ListaOsob.begin(), ListaOsob.end(), [](Osoba wartosc) {cout << wartosc; });
	sort(ListaOsob.begin(), ListaOsob.end(), [](Osoba osoba1, Osoba osoba2) {return osoba1.Imie < osoba2.Imie; });
	cout << "\nPosortowane po Imie" << endl;
	for_each(ListaOsob.begin(), ListaOsob.end(), [](Osoba wartosc) {cout << wartosc; });
	cout << endl << "##############################################################################" << endl;

	//ZADANIE 4.4
//Skopiuj wektor z poprzednigo do innego wektora i posortuj go wedlug pol:
	// - Nazwisko
	// - Wiek
	// - Wzrost
//Za kazdym razem musi to byc nowy wektor 

	vector<Osoba> ListaOsobNazw(4);
	copy(ListaOsob.begin(), ListaOsob.end(), ListaOsobNazw.begin());

	cout << "\nPrzed posortowaniem (ListaOsobNazw kopia z ListaOsob) " << endl;
	for_each(ListaOsobNazw.begin(), ListaOsobNazw.end(), [&](Osoba &wartosc) {cout << wartosc; });
	sort(ListaOsobNazw.begin(), ListaOsobNazw.end(), [](const Osoba &osoba1, const Osoba &osoba2) {return osoba1.Nazwisko < osoba2.Nazwisko; });
	cout << "\nPosortowane po Nazwisko" << endl;
	for_each(ListaOsobNazw.begin(), ListaOsobNazw.end(), [&](Osoba &wartosc) {cout << wartosc; });
	cout << endl << "##############################################################################" << endl;


	vector<Osoba> ListaOsobWiek(4);
	copy(ListaOsob.begin(), ListaOsob.end(), ListaOsobWiek.begin());

	cout << "\nPrzed posortowaniem (ListaOsobWiek kopia z ListaOsob) " << endl;
	for_each(ListaOsobWiek.begin(), ListaOsobWiek.end(), [&](Osoba &wartosc) {cout << wartosc; });
	sort(ListaOsobWiek.begin(), ListaOsobWiek.end(), [](const Osoba &osoba1, const Osoba &osoba2) {return osoba1.Wiek < osoba2.Wiek; });
	cout << "\nPosortowane po Wiek" << endl;
	for_each(ListaOsobWiek.begin(), ListaOsobWiek.end(), [&](Osoba &wartosc) {cout << wartosc; });
	cout << endl << "##############################################################################" << endl;


	vector<Osoba> ListaOsobWzr(4);
	copy(ListaOsob.begin(), ListaOsob.end(), ListaOsobWzr.begin());

	cout << "\nPrzed posortowaniem (ListaOsobWzr kopia z ListaOsob) " << endl;
	for_each(ListaOsobWzr.begin(), ListaOsobWzr.end(), [&](Osoba &wartosc) {cout << wartosc; });
	sort(ListaOsobWzr.begin(), ListaOsobWzr.end(), [](const Osoba &osoba1, const Osoba &osoba2) {return osoba1.Wzrost < osoba2.Wzrost; });
	cout << "\nPosortowane po Wzrost" << endl;
	for_each(ListaOsobWzr.begin(), ListaOsobWzr.end(), [&](Osoba &wartosc) {cout << wartosc; });
	cout << endl << "##############################################################################" << endl;

}