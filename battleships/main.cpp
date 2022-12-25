#include <iostream>
#include <string.h>
#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>
using namespace std;

char plansza[11][11] = {
{ ' ','A','B','C','D','E','F','G','H','I','J'},
{ '1','o','o','o','o','o','o','o','o','o','o'},
{ '2','o','o','o','o','o','o','o','o','o','o'},
{ '3','o','o','o','o','o','o','o','o','o','o'},
{ '4','o','o','o','o','o','o','o','o','o','o'},
{ '5','o','o','o','o','o','o','o','o','o','o'},
{ '6','o','o','o','o','o','o','o','o','o','o'},
{ '7','o','o','o','o','o','o','o','o','o','o'},
{ '8','o','o','o','o','o','o','o','o','o','o'},
{ '9','o','o','o','o','o','o','o','o','o','o'},
{ '10','o','o','o','o','o','o','o','o','o','o'},
};



HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
void wypisz_tablice() {

	cout << endl;

	for (int i = 0; i < 11; ++i)
	{
		cout << "\t";
		for (int j = 0; j < 11; ++j) {
			if (plansza[i][j] == 'x') {

				SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
			}
			else {

				SetConsoleTextAttribute(hConsole, 7);
			}
			cout << plansza[i][j];

			if (j == 0) {
				cout << " ";
			}

		}
		cout << endl;
	}
}

int poz_h, new_poz_v;
char poz_v;
bool poz_pion;
string off_pod;

void statek_pojedynczy() {

	bool can_place = false;

	while (!can_place)
	{
		can_place = true;
		cin >> poz_h >> poz_v;
		poz_v = tolower(poz_v);
		new_poz_v = int(poz_v) - 96;

		// tu jest sprawdzanie, czy podana pozycja jest na planszy
		if (poz_h < 1 || poz_h > 10 || new_poz_v < 1 || new_poz_v > 10)
		{
			cout << "pozycja poza plansza" << endl;
			can_place = false;
		}
		// tu jest sprawdzanie czy podana pozycja jest zajeta i nie koliduje z innym statkiem
		for (int h = -1; h <= 1; h++)
		{
			for (int v = -1; v <= 1; v++)
			{
				if (poz_h + h < 1 || poz_h + h > 10 || new_poz_v + v < 1 || new_poz_v + v > 10)
				{
					//  cout << "sprawdzenie pozycja poza plansza" << endl;
				}
				else
				{
					// cout << poz_h + h << ", " << new_poz_v + v << ": ";
					if (plansza[poz_h + h][new_poz_v + v] == 'x')
					{
						cout << "zajete" << endl;
						can_place = false;
					}

				}
			}
		}
	}
	cout << "pozycja h = " << poz_h << ", v = " << new_poz_v << endl;

	plansza[poz_h][new_poz_v] = 'x';
}

void czy_trafiony() {

	//TO_DO nowa tablica ktora pokazuje zgadywania, najelpeij kopia 0
}

void statek_podwojny() {

	cout << "statek ma isc w poziomie (wpisz 0) czy pionie (wpisz 1): " << endl;
	cin >> poz_pion;
	cout << "gdzie ma sie zaczynac: " << endl;
	bool can_place = false;

	while (!can_place)
	{
		can_place = true;
		cin >> poz_h >> poz_v;
		poz_v = tolower(poz_v);
		new_poz_v = int(poz_v) - 96;

		if (poz_pion == 0) {

			if (poz_h < 1 || poz_h > 10 || new_poz_v < 1 || new_poz_v > 9)
			{
				cout << "pozycja poza plansza" << endl;
				can_place = false;
			}
		}
		else {
			if (poz_h < 1 || poz_h > 9 || new_poz_v < 1 || new_poz_v > 10)
			{
				cout << "pozycja poza plansza" << endl;
				can_place = false;
			}
		}
		// tu jest sprawdzanie czy podana pozycja jest zajeta i nie koliduje z innym statkiem
		for (int h = -1; h <= 2; h++)
		{
			for (int v = -1; v <= 2; v++)
			{
				if (poz_h + h < 1 || poz_h + h > 10 || new_poz_v + v < 1 || new_poz_v + v > 10)
				{
					//  cout << "sprawdzenie pozycja poza plansza" << endl;
				}
				else
				{
					// cout << poz_h + h << ", " << new_poz_v + v << ": ";
					if (plansza[poz_h + h][new_poz_v + v] == 'x')
					{
						cout << "zajete" << endl;
						can_place = false;
					}

				}
			}
		}
	}

	if (poz_pion == 0) {
		cout << "0" << endl;
		cout << "pozycja h = " << poz_h << ", v = " << new_poz_v << " konczy sie na " << new_poz_v + 1 << endl;

		plansza[poz_h][new_poz_v] = 'x';
		plansza[poz_h][new_poz_v + 1] = 'x';
	}
	else {
		cout << "1" << endl;
		cout << "pozycja h = " << poz_h << " konczy sie na " << poz_h + 1 << ", v = " << new_poz_v << endl;

		plansza[poz_h][new_poz_v] = 'x';
		plansza[poz_h + 1][new_poz_v] = 'x';
	}


}
void statek_potrjny() {

	cout << "statek ma isc w poziomie (wpisz 0) czy pionie (wpisz 1): " << endl;
	cin >> poz_pion;
	cout << "gdzie ma sie zaczynac: " << endl;
	bool can_place = false;

	while (!can_place)
	{
		can_place = true;
		cin >> poz_h >> poz_v;
		poz_v = tolower(poz_v);
		new_poz_v = int(poz_v) - 96;

		if (poz_pion == 0) {

			if (poz_h < 1 || poz_h > 10 || new_poz_v < 1 || new_poz_v > 8)
			{
				cout << "pozycja poza plansza" << endl;
				can_place = false;
			}
		}
		else {
			if (poz_h < 1 || poz_h > 8 || new_poz_v < 1 || new_poz_v > 10)
			{
				cout << "pozycja poza plansza" << endl;
				can_place = false;
			}
		}
		for (int h = -1; h <= 3; h++)
		{
			for (int v = -1; v <= 3; v++)
			{
				if (poz_h + h < 1 || poz_h + h > 10 || new_poz_v + v < 1 || new_poz_v + v > 10)
				{
				}
				else
				{
					if (plansza[poz_h + h][new_poz_v + v] == 'x')
					{
						cout << "zajete" << endl;
						can_place = false;
					}

				}
			}
		}
	}

	if (poz_pion == 0) {
		cout << "0" << endl;
		cout << "pozycja h = " << poz_h << ", v = " << new_poz_v << " konczy sie na " << new_poz_v + 2 << endl;

		plansza[poz_h][new_poz_v] = 'x';
		plansza[poz_h][new_poz_v + 1] = 'x';
		plansza[poz_h][new_poz_v + 2] = 'x';
	}
	else {
		cout << "1" << endl;
		cout << "pozycja h = " << poz_h << " konczy sie na " << poz_h + 2 << ", v = " << new_poz_v << endl;

		plansza[poz_h][new_poz_v] = 'x';
		plansza[poz_h + 1][new_poz_v] = 'x';
		plansza[poz_h + 2][new_poz_v] = 'x';
	}


}

void statek_poczworny() {

	cout << "statek ma isc w poziomie (wpisz 0) czy pionie (wpisz 1): " << endl;
	cin >> poz_pion;
	cout << "gdzie ma sie zaczynac: " << endl;
	bool can_place = false;

	while (!can_place)
	{
		can_place = true;
		cin >> poz_h >> poz_v;
		poz_v = tolower(poz_v);
		new_poz_v = int(poz_v) - 96;

		if (poz_pion == 0) {

			if (poz_h < 1 || poz_h > 10 || new_poz_v < 1 || new_poz_v > 7)
			{
				cout << "pozycja poza plansza" << endl;
				can_place = false;
			}
		}
		else {
			if (poz_h < 1 || poz_h > 7 || new_poz_v < 1 || new_poz_v > 10)
			{
				cout << "pozycja poza plansza" << endl;
				can_place = false;
			}
		}

		for (int h = -1; h <= 4; h++)
		{
			for (int v = -1; v <= 4; v++)
			{
				if (poz_h + h < 1 || poz_h + h > 10 || new_poz_v + v < 1 || new_poz_v + v > 10)
				{
				}
				else
				{
					if (plansza[poz_h + h][new_poz_v + v] == 'x')
					{
						cout << "zajete" << endl;
						can_place = false;
					}

				}
			}
		}
	}

	if (poz_pion == 0) {
		cout << "0" << endl;
		cout << "pozycja h = " << poz_h << ", v = " << new_poz_v << " konczy sie na " << new_poz_v + 3 << endl;

		plansza[poz_h][new_poz_v] = 'x';
		plansza[poz_h][new_poz_v + 1] = 'x';
		plansza[poz_h][new_poz_v + 2] = 'x';
		plansza[poz_h][new_poz_v + 3] = 'x';
	}
	else {
		cout << "1" << endl;
		cout << "pozycja h = " << poz_h << " konczy sie na " << poz_h + 3 << ", v = " << new_poz_v << endl;

		plansza[poz_h][new_poz_v] = 'x';
		plansza[poz_h + 1][new_poz_v] = 'x';
		plansza[poz_h + 2][new_poz_v] = 'x';
		plansza[poz_h + 3][new_poz_v] = 'x';
	}


}

int main() {

	cout << "witamy w grze w statki \n twoje statki to: \n \t jeden czteromasztowiec; \n \t dwa trzymasztowce; \n \t trzy dwumasztowce; \n \t cztery jednomasztowce; " << endl;

	wypisz_tablice();


	cout << "ustawnianie 1 \n podaj pozycje od 1A-10-J najpeirw v pozniej h" << endl;
	cout << "poazycje pojedynczych:";

	statek_pojedynczy();

	wypisz_tablice();
/*
	SetConsoleTextAttribute(hConsole, 7);
	cout << "poazycje podojnych:";

	statek_podwojny();

	wypisz_tablice();

	SetConsoleTextAttribute(hConsole, 7);
	cout << "poazycje potrojnych:";

	statek_potrjny();

	wypisz_tablice();

	SetConsoleTextAttribute(hConsole, 7);
	cout << "poazycje poczworny:";

	statek_poczworny();
	*/
	wypisz_tablice();

	cout << "napisz 'ok' kiedy bedziesz chial usunac podglad planszy " << endl;
	cin >> off_pod;
	if (off_pod == "ok") {
		system("CLS");
	}

	cout << "sprawdz czy trafiony" << endl;

	return 0;
}