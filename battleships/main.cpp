#include <iostream>
#include <string.h>
#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>
using namespace std;
// TO_DO napraw stawianie stadkow bo sie baguje, za duzo odstepu robi 
char plansza1[11][11] = {
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

char plansza1_odp[11][11] = {
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
char plansza2[11][11] = {
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

char plansza2_odp[11][11] = {
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
void wypisz_tablice(char plansza1[11][11]) {

	cout << endl;

	for (int i = 0; i < 11; ++i)
	{
		cout << "\t";
		for (int j = 0; j < 11; ++j) {
			if (plansza1[i][j] == 'x') {

				SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
			}
			else {

				SetConsoleTextAttribute(hConsole, 7);
			}
			cout << plansza1[i][j];

			if (j == 0) {
				cout << " ";
			}

		}
		cout << endl;
	}
}

int poz_h, new_poz_v;
char poz_v;
bool poz_pion, koniecbool;
string off_pod;

void konic(char plansza1_odp[11][11], char plansza2_odp[11][11]) {
	int ile_x1 = 0;
	int ile_x2 = 0;
	koniecbool = false;
	for (int i = 0; i < 11; ++i)
	{
		for (int j = 0; j < 11; ++j) {
			if (plansza1_odp[i][j] == 'x') {
				ile_x1++;
			}
			if (plansza2_odp[i][j] == 'x') {
				ile_x2++;
			}
		}
	}
	if (ile_x1 == 20) {
		cout << "gratulacje drogi zawodniku!" << endl;
		koniecbool = true;
	}
	else if (ile_x2 == 20) {
		cout << "gratulacje pierwszy zawodniku!" << endl;
		koniecbool = true;

	}
}

void czy_trafiony(char plansza1[11][11], char plansza1_odp[11][11]) {
	cin >> poz_h >> poz_v;
	poz_v = tolower(poz_v);
	new_poz_v = int(poz_v) - 96;

	for (int i = 0; i < 11; ++i)
	{
		cout << "\t";
		for (int j = 0; j < 11; ++j) {
				if (plansza1[poz_h][new_poz_v] == 'x') {

					plansza1_odp[poz_h][new_poz_v] = 'x';

				}
				else {
					plansza1_odp[poz_h][new_poz_v] = 'v';
				}


			if (plansza1_odp[i][j] == 'x') {

				SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
			}
			else if (plansza1_odp[i][j] == 'v') {

				SetConsoleTextAttribute(hConsole, 3);
			}
			else {
				SetConsoleTextAttribute(hConsole, 7);
			}

			cout << plansza1_odp[i][j];

			if (j == 0) {
				cout << " ";
			}

		}
		cout << endl;

	}
}


void statek_pojedynczy(char plansza1[11][11]) {

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
			cout << "pozycja poza plansza1" << endl;
			can_place = false;
		}
		// tu jest sprawdzanie czy podana pozycja jest zajeta i nie koliduje z innym statkiem
		for (int h = -1; h <= 1; h++)
		{
			for (int v = -1; v <= 1; v++)
			{
				if (poz_h + h < 1 || poz_h + h > 10 || new_poz_v + v < 1 || new_poz_v + v > 10)
				{
					//  cout << "sprawdzenie pozycja poza plansza1" << endl;
				}
				else
				{
					// cout << poz_h + h << ", " << new_poz_v + v << ": ";
					if (plansza1[poz_h + h][new_poz_v + v] == 'x')
					{
						cout << "zajete" << endl;
						can_place = false;
					}

				}
			}
		}
	}
	cout << "pozycja h = " << poz_h << ", v = " << new_poz_v << endl;

	plansza1[poz_h][new_poz_v] = 'x';
}

void statek_podwojny(char plansza1[11][11]) {

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
				cout << "pozycja poza plansza1" << endl;
				can_place = false;
			}
		}
		else {
			if (poz_h < 1 || poz_h > 9 || new_poz_v < 1 || new_poz_v > 10)
			{
				cout << "pozycja poza plansza1" << endl;
				can_place = false;
			}
		}
		// tu jest sprawdzanie czy podana pozycja jest zajeta i nie koliduje z innym statkiem
			if(poz_pion == 1){
			for (int h = -1; h <= 2; h++)
		{
			for (int v = -1; v <= 1; v++)
			{
				if (poz_h + h < 1 || poz_h + h > 10 || new_poz_v + v < 1 || new_poz_v + v > 10)
				{
					//  cout << "sprawdzenie pozycja poza plansza1" << endl;
				}
				else
				{					if (plansza1[poz_h + h][new_poz_v + v] == 'x')
					{
						cout << "zajete" << endl;
						can_place = false;
					}

				}
			}
		    
		}
		}else{

		for (int h = -1; h <= 1; h++)
		{
			for (int v = -1; v <= 2; v++)
			{
				if (poz_h + h < 1 || poz_h + h > 10 || new_poz_v + v < 1 || new_poz_v + v > 10)
				{
					//  cout << "sprawdzenie pozycja poza plansza1" << endl;
				}
				else
				{
					// cout << poz_h + h << ", " << new_poz_v + v << ": ";
					if (plansza1[poz_h + h][new_poz_v + v] == 'x')
					{
						cout << "zajete" << endl;
						can_place = false;
					}

				}
			}}
		}
	}

	if (poz_pion == 0) {
		cout << "0" << endl;
		cout << "pozycja h = " << poz_h << ", v = " << new_poz_v << " konczy sie na " << new_poz_v + 1 << endl;

		plansza1[poz_h][new_poz_v] = 'x';
		plansza1[poz_h][new_poz_v + 1] = 'x';
	}
	else {
		cout << "1" << endl;
		cout << "pozycja h = " << poz_h << " konczy sie na " << poz_h + 1 << ", v = " << new_poz_v << endl;

		plansza1[poz_h][new_poz_v] = 'x';
		plansza1[poz_h + 1][new_poz_v] = 'x';
	}


}

void statek_potrjny(char plansza1[11][11]) {

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
				cout << "pozycja poza plansza1" << endl;
				can_place = false;
			}
		}
		else {
			if (poz_h < 1 || poz_h > 8 || new_poz_v < 1 || new_poz_v > 10)
			{
				cout << "pozycja poza plansza1" << endl;
				can_place = false;
			}
		}
			if(poz_pion == 1){
			for (int h = -1; h <= 3; h++)
		{
			for (int v = -1; v <= 1; v++)
			{
				if (poz_h + h < 1 || poz_h + h > 10 || new_poz_v + v < 1 || new_poz_v + v > 10)
				{
					//  cout << "sprawdzenie pozycja poza plansza1" << endl;
				}
				else
				{					if (plansza1[poz_h + h][new_poz_v + v] == 'x')
					{
						cout << "zajete" << endl;
						can_place = false;
					}

				}
			}
		    
		}
		}else{

		for (int h = -1; h <= 1; h++)
		{
			for (int v = -1; v <= 3; v++)
			{
				if (poz_h + h < 1 || poz_h + h > 10 || new_poz_v + v < 1 || new_poz_v + v > 10)
				{
				}
				else
				{
					if (plansza1[poz_h + h][new_poz_v + v] == 'x')
					{
						cout << "zajete" << endl;
						can_place = false;
					}

				}
			}
		}}
	}

	if (poz_pion == 0) {
		cout << "0" << endl;
		cout << "pozycja h = " << poz_h << ", v = " << new_poz_v << " konczy sie na " << new_poz_v + 2 << endl;

		plansza1[poz_h][new_poz_v] = 'x';
		plansza1[poz_h][new_poz_v + 1] = 'x';
		plansza1[poz_h][new_poz_v + 2] = 'x';
	}
	else {
		cout << "1" << endl;
		cout << "pozycja h = " << poz_h << " konczy sie na " << poz_h + 2 << ", v = " << new_poz_v << endl;

		plansza1[poz_h][new_poz_v] = 'x';
		plansza1[poz_h + 1][new_poz_v] = 'x';
		plansza1[poz_h + 2][new_poz_v] = 'x';
	}


}

void statek_poczworny(char plansza1[11][11]) {

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
				cout << "pozycja poza plansza1" << endl;
				can_place = false;
			}
		}
		else {
			if (poz_h < 1 || poz_h > 7 || new_poz_v < 1 || new_poz_v > 10)
			{
				cout << "pozycja poza plansza1" << endl;
				can_place = false;
			}
		}
	if(poz_pion == 1){
			for (int h = -1; h <= 4; h++)
		{
			for (int v = -1; v <= 1; v++)
			{
				if (poz_h + h < 1 || poz_h + h > 10 || new_poz_v + v < 1 || new_poz_v + v > 10)
				{
					//  cout << "sprawdzenie pozycja poza plansza1" << endl;
				}
				else
				{					if (plansza1[poz_h + h][new_poz_v + v] == 'x')
					{
						cout << "zajete" << endl;
						can_place = false;
					}

				}
			}
		    
		}
		}else{

		for (int h = -1; h <= 1; h++)
		{
			for (int v = -1; v <= 4; v++)
			{
				if (poz_h + h < 1 || poz_h + h > 10 || new_poz_v + v < 1 || new_poz_v + v > 10)
				{
				}
				else
				{
					if (plansza1[poz_h + h][new_poz_v + v] == 'x')
					{
						cout << "zajete" << endl;
						can_place = false;
					}

				}
			}
		}
	}
	}

	if (poz_pion == 0) {
		cout << "0" << endl;
		cout << "pozycja h = " << poz_h << ", v = " << new_poz_v << " konczy sie na " << new_poz_v + 3 << endl;

		plansza1[poz_h][new_poz_v] = 'x';
		plansza1[poz_h][new_poz_v + 1] = 'x';
		plansza1[poz_h][new_poz_v + 2] = 'x';
		plansza1[poz_h][new_poz_v + 3] = 'x';
	}
	else {
		cout << "1" << endl;
		cout << "pozycja h = " << poz_h << " konczy sie na " << poz_h + 3 << ", v = " << new_poz_v << endl;

		plansza1[poz_h][new_poz_v] = 'x';
		plansza1[poz_h + 1][new_poz_v] = 'x';
		plansza1[poz_h + 2][new_poz_v] = 'x';
		plansza1[poz_h + 3][new_poz_v] = 'x';
	}


}

int main() {

	cout << "witamy w grze w statki \n twoje statki to: \n \t jeden czteromasztowiec; \n \t dwa trzymasztowce; \n \t trzy dwumasztowce; \n \t cztery jednomasztowce; " << endl;

	wypisz_tablice(plansza1);


	cout << "\n Pierwszy gracz ustawia \n Podaj pozycje od 1A-10-J najpeirw v pozniej h" << endl;
	cout << "poazycje pojedynczych:";

	statek_pojedynczy(plansza1);
	statek_pojedynczy(plansza1);
	statek_pojedynczy(plansza1);
	statek_pojedynczy(plansza1);

	wypisz_tablice(plansza1);

	SetConsoleTextAttribute(hConsole, 7);
	cout << "poazycje podojnych:";

	statek_podwojny(plansza1);
	statek_podwojny(plansza1);
	statek_podwojny(plansza1);

	wypisz_tablice(plansza1);

	SetConsoleTextAttribute(hConsole, 7);
	cout << "poazycje potrojnych:";

	statek_potrjny(plansza1);
	statek_potrjny(plansza1);

	wypisz_tablice(plansza1);

	SetConsoleTextAttribute(hConsole, 7);
	cout << "poazycje poczworny:";

	statek_poczworny(plansza1);
	
	wypisz_tablice(plansza1);
	

	cout << "napisz 'ok' kiedy bedziesz chial usunac podglad planszy " << endl;
	cin >> off_pod;
	if (off_pod != "ok") {
		while (off_pod != "ok")
			cin >> off_pod;
	}
	system("CLS");

	off_pod = "x";

	cout << "\n Drugi gracz ustawia \n Twoje statki to: \n \t jeden czteromasztowiec; \n \t dwa trzymasztowce; \n \t trzy dwumasztowce; \n \t cztery jednomasztowce;   \n Podaj pozycje od 1A-10-J najpeirw v pozniej h" << endl;
	cout << "poazycje pojedynczych:";

		statek_pojedynczy(plansza2);
		statek_pojedynczy(plansza2);
		statek_pojedynczy(plansza2);
		statek_pojedynczy(plansza2);

		wypisz_tablice(plansza2);
	
		SetConsoleTextAttribute(hConsole, 7);
		cout << "poazycje podojnych:";

		statek_podwojny(plansza2);
		statek_podwojny(plansza2);
		statek_podwojny(plansza2);

		wypisz_tablice(plansza2);

		SetConsoleTextAttribute(hConsole, 7);
		cout << "poazycje potrojnych:";

		statek_potrjny(plansza2);
		statek_potrjny(plansza2);

		wypisz_tablice(plansza2);

		SetConsoleTextAttribute(hConsole, 7);
		cout << "poazycje poczworny:";

		statek_poczworny(plansza2);

		wypisz_tablice(plansza2);
		
	cout << "napisz 'ok' kiedy bedziesz chial usunac podglad planszy " << endl;
	cin >> off_pod;

	if (off_pod != "ok") {
		while (off_pod != "ok")
			cin >> off_pod;
	}
	system("CLS");

	off_pod = "x";
	while (!koniecbool) {

	
		cout << "pierwszy zawodnik: sprawdz czy trafiony" << endl;

		czy_trafiony(plansza2, plansza2_odp);

		cout << "drogi zawodnik: sprawdz czy trafiony" << endl;
		czy_trafiony(plansza1, plansza1_odp);
		konic(plansza1_odp, plansza2_odp);
}
	return 0;
}
