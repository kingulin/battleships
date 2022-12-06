#include <iostream>
#include <string.h>
#include <stdio.h>
//#include <Windows.h>
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
{ '0','o','o','o','o','o','o','o','o','o','o'},
};



 void wypisz_tablice() {

    // HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
     cout << endl;

     for (int i = 0; i < 11; ++i)
     {
         cout << "\t";
         for (int j = 0; j < 11; ++j) {
             if (plansza[i][j] == 'x') {

          //       SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
          cout << "\033[32m" << plansza[i][j] ;
            }
          else {

                 cout << "\033[0m"<< plansza[i][j];
          //       SetConsoleTextAttribute(hConsole, 7);
        }

             if (j == 0) {
                 cout << " ";
             }

         }
         cout << endl;
     }
 }

 void statek_pojedynczy(int poz_h,char poz_v,int new_poz_v) {

     cin >> poz_h >> poz_v;
     poz_v = tolower(poz_v);

     new_poz_v = int(poz_v);
     new_poz_v -= 96;

     while (poz_h == 0 || poz_h > 10 || new_poz_v == 0 || new_poz_v > 10) {

         cout << "podaj prawidlowie dane" << endl;
         cin >> poz_h >> new_poz_v;
     }
     cout << "pozycja h = " << poz_h << ", v = " << new_poz_v << endl;

     plansza[poz_h][new_poz_v] = 'x';
 }

int poz_h, new_poz_v;
char poz_v;
int main(){

	 cout << "witamy w grze w statki \n twoje statki to: \n \t jeden czteromasztowiec; \n \t dwa trzymasztowce; \n \t trzy dwumasztowce; \n \t cztery jednomasztowce; " << endl;

     wypisz_tablice();


     cout << "ustawnianie 1 \n podaj pozycje od 1A-10-J najpeirw v pozniej h" << endl;
     cout << "poazycje pojedynczych:";

     statek_pojedynczy( poz_h, poz_v, new_poz_v);
     statek_pojedynczy( poz_h, poz_v, new_poz_v);
     statek_pojedynczy( poz_h, poz_v, new_poz_v);
     statek_pojedynczy( poz_h, poz_v, new_poz_v);

         wypisz_tablice();


         return 0;
}
