#define FOREGROUND_WHITE		(FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN)  // okreslenie neutralnych barw konsoli
#define BACKGROUND_WHITE		(BACKGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN)  // okreslenie negatywu neutralnych barw konsoli
#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <cstdlib>
#include <string.h>

void gotoxy(int x, int y);
void HideCursor();
void menu();
void podajZnak(char&);
int podajRozmiar(int&);
void print(char, int, int, int&);
void modyfikacja(char&, int&, int&, int&);

int main(){

	char znak, mod;
	int x = 62, y = 21, L = 6;         // x, y okreslaja domyslna pozycje, z ktorej bedzie rysowana figura
    HideCursor();
    menu();
	podajZnak(znak);
	podajRozmiar(L);
	print(znak, x, y, L);

	do {

		modyfikacja(mod, x, y, L);
		print(znak, x, y, L);

	} while (_getch() != 27);
    return 0;
}

void gotoxy(int x, int y){ // Funkcja definiujaca pozycjonowanie kursora

	COORD c;
	c.X = x;
	c.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

void HideCursor(){
	::HANDLE hConsoleOut = ::GetStdHandle(STD_OUTPUT_HANDLE);
	::CONSOLE_CURSOR_INFO hCCI;
	::GetConsoleCursorInfo(hConsoleOut, &hCCI);
	hCCI.bVisible = FALSE;
	::SetConsoleCursorInfo(hConsoleOut, &hCCI);
}

void menu(){ // Funkcja wyswietla menu programu, przedstawia nawigacje

	HANDLE hOut;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hOut, 0x0006);

	gotoxy(31, 5);
	std::cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@";
	gotoxy(31, 6);
	std::cout << "@";
	gotoxy(90, 6);
	std::cout << "@";
	gotoxy(31, 7);
	std::cout << "@";
	gotoxy(49, 7);
	std::cout << "Program rysuje figure -< ";
	gotoxy(90, 7);
	std::cout << "@";
    gotoxy(31, 8);
	std::cout << "@";
	gotoxy(90, 8);
	std::cout << "@";
	gotoxy(31, 9);
	std::cout << "@";
	gotoxy(39,9);
	std::cout << "Uzywaj strzalek aby zmienic polozenie figury";
	gotoxy(90, 9);
	std::cout << "@";
	gotoxy(31, 10);
	std::cout << "@";
	gotoxy(90, 10);
	std::cout << "@";
	gotoxy(31, 11);
	std::cout << "@";
	gotoxy(36,11);
	std::cout << "Figure mozna powiekszyc i zmniejszyc uzywajac + i - ";
	gotoxy(90, 11);
	std::cout << "@";
	gotoxy(31, 12);
	std::cout << "@";
	gotoxy(90, 12);
	std::cout << "@";
	gotoxy(31, 13);
	std::cout << "@";
	gotoxy(39,13);
	std::cout << "Zmiana koloru wyswietlanego tla lub znakow: ";
	gotoxy(90, 13);
	std::cout << "@";
	gotoxy(31, 14);
	std::cout << "@";
	gotoxy(90, 14);
	std::cout << "@";
	gotoxy(31, 15);
	std::cout << "@";
	gotoxy(36, 15);
	std::cout << "R - czerwone tlo";
	gotoxy(65, 15);
	std::cout << "r - czerwone znaki";
	gotoxy(90, 15);
	std::cout << "@";
	gotoxy(31, 16);
	std::cout << "@";
	gotoxy(36, 16);
	std::cout << "G - zielone tlo";
	gotoxy(65, 16);
	std::cout << "g - zielone znaki";
	gotoxy(90, 16);
	std::cout << "@";
	gotoxy(31, 17);
	std::cout << "@";
	gotoxy(36, 17);
	std::cout << "B - niebieskie tlo";
	gotoxy(65, 17);
	std::cout << "b - niebieskie znaki";
	gotoxy(90, 17);
	std::cout << "@";
	gotoxy(31, 18);
	std::cout << "@";
	gotoxy(36, 18);
	std::cout << "Y - zlote tlo";
	gotoxy(65, 18);
	std::cout << "y - zlote znaki";
	gotoxy(90, 18);
	std::cout << "@";
	gotoxy(31, 19);
	std::cout << "@";
	gotoxy(36, 19);
	std::cout << "W - biale tlo";
	gotoxy(65, 19);
	std::cout << "N - domyslnie";
	gotoxy(90, 19);
	std::cout << "@";
	gotoxy(31, 20);
	std::cout << "@";
	gotoxy(90, 20);
	std::cout << "@";
	gotoxy(31, 21);
	std::cout << "@";
	gotoxy(40, 21);
	std::cout << "Aby kontynuowac, wcisnij dowolny przycisk";
	gotoxy(90, 21);
	std::cout << "@";
	gotoxy(31, 22);
	std::cout << "@";
	gotoxy(90, 22);
	std::cout << "@";
	gotoxy(31, 23);
	std::cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@";

	_getch();
}

void podajZnak(char& znak){ // Funkcja do wprowadzenia znaku, ktorym bedzie rysowana figura

	system("cls");

	gotoxy(37,14);
	std::cout << "Podaj znak, ktorym zostanie narysowana figura: ";
	std::cin >> znak;

}

int podajRozmiar(int& L){ // Funkcja do poczatkowego rozmiaru figury

	gotoxy(46,16);

	std::cout << "Podaj rozmiar figury (2-8): ";
	std::cin >> L;

	while(L < 2 || L > 8 ){

        gotoxy(35, 18);
        std::cout << "Nie podano obslugiwanego rozmiaru, podaj ponownie: ";
        std::cin >> L;

    }return L;
}

void print(char znak, int x, int y, int& L){ // Funkcja rysuj¹ca figure -<

	int  x1, y1;
	x1 = x - L;
    y1 = y - L;

	system("cls");

	gotoxy(x, y);

    for(int i=1; i<= L; i++){  // rysuje przekatna "SE -> NW" zaczynajac w prawym dolnym rogu figury

        x--; y--;
        gotoxy(x, y);
        std::cout << znak;

    }

    gotoxy(x1,y1);                   // ustawia pozycje na "srodek" figury

    for(int j=1; j<= L*2 - 1; j++){  // rysuje pozioma linie "E -> W"

        if(j%2==0){

            gotoxy(x-j, y);
            std::cout << znak;

        }else{                       // dla zachowania proporcji figury co druga kolumna jest "pusta"

            gotoxy(x-j, y);
            std::cout << " ";
        }

    }

    gotoxy(x1,y1);                   // ustawia pozycje na "srodek" figury

    for(int k=1; k<= L-1; k++){      // rysuje przekatna "SW -> NE" konczac na prawym gornym rogu figury

        gotoxy(x+k,y-k);
        std::cout << znak;

    }
}

void modyfikacja(char &mod,int &x, int &y,int &L){ // Funkcja zmienia pozycje, rozmiar, kolor figury i tla

    bool zmiana = false;
    mod = _getch();

    do{
        mod = _getch();
        switch (mod){

        case 72: {
            zmiana = true;
            y--;                      // ruch w górê
            break;}
        case 80: {
            zmiana = true;
            y++;                      // ruch w dó³
            break; }
        case 75: {
            zmiana = true;
            x--;                      // ruch w lewo
            break; }
        case 77: {
            zmiana = true;
            x++;                      // ruch w prawo
            break; }
        case 43: {
            zmiana = true;
            L++;                      // powiekszenie
            break; }
        case 45: {
            zmiana = true;
            L--;                      // pomniejszenie
            break; }
        case 82: {                    // Czerwone tlo, czarne znaki
            zmiana = true;
            HANDLE hOut;
            hOut = GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute(hOut, 0x0040);
            break; }
        case 71: {                    // Zielone tlo, czarne znaki
            zmiana = true;
            HANDLE hOut;
            hOut = GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute(hOut, 0x0020);
            break; }
        case 66: {                    // Niebieskie tlo, czarne znaki
            zmiana = true;
            HANDLE hOut;
            hOut = GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute(hOut, 0x0010);
            break; }
        case 89: {                    // Zlote tlo, czarne znaki
            zmiana = true;
            HANDLE hOut;
            hOut = GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute(hOut, 0x0060);
            break; }
        case 78: {                    // Czarne tlo, biale znaki
            zmiana = true;
            HANDLE hOut;
            hOut = GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute(hOut, FOREGROUND_WHITE);
            break; }
        case 87: {                    // Biale tlo, czarne znaki
            zmiana = true;
            HANDLE hOut;
            hOut = GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute(hOut, BACKGROUND_WHITE);
            break; }
        case 98: {                    // Czarne tlo, niebieskie znaki
            zmiana = true;
            HANDLE hOut;
            hOut = GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute(hOut, 0x0001);
            break; }
        case 103: {                    // Czarne tlo, zielone znaki
            zmiana = true;
            HANDLE hOut;
            hOut = GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute(hOut, 0x0002);
            break; }
        case 114: {                    // Czarne tlo, czerwone znaki
            zmiana = true;
            HANDLE hOut;
            hOut = GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute(hOut, 0x0004);
            break; }
        case 121: {                    // Czarne tlo, zlote znaki
            zmiana = true;
            HANDLE hOut;
            hOut = GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute(hOut, 0x0006);
            break; }
        case 27: {
            zmiana = true;
            break;}
        }
    } while (zmiana == false);
}
