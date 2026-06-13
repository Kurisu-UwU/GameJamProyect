#include <iostream>
#include <conio.h>

using namespace std;
using namespace System;

// variables en general para el menu y las naves
int n1x = 0, n1y = 5;
int n2x = 40, n2y = 12;
int n3x = 80, n3y = 22;
int opMenu = 1;
int opFinal = 0;
int px = 100, py = 13;
bool owo; // boleano para el movimiento del cohete
int Asteroidesmatrix[10][2];

void Posicion(int x, int y)
{
    Console::SetCursorPosition(x, y);
}

void ColorBlanco()
{
    Console::ForegroundColor = ConsoleColor::White;
}
void ColorAmarillo() { Console::ForegroundColor = ConsoleColor::Yellow; }

void DibujarFondo()
{
    ColorBlanco();
    Posicion(10, 3); cout <<   "*";
    Posicion(30, 8); cout <<   "*";
    Posicion(90, 4); cout <<   "*";
    Posicion(20, 18); cout <<  "*";
    Posicion(85, 20); cout <<  "*";
    Posicion(15, 25); cout <<  "*";
    Posicion(105, 15); cout << "*";

    

}

void DibujarLuna()
{
    ColorBlanco();
    Posicion(50, 3);  cout << "     _..._     ";
    Posicion(50, 4);  cout << "   .:::::::.   ";
    Posicion(50, 5);  cout << "  :::::::::::  ";
    Posicion(50, 6);  cout << "  :::::::::::  ";
    Posicion(50, 7);  cout << "  `:::::::::'  ";
    Posicion(50, 8);  cout << "    `'---'`    ";
}

void DibujarMenu()
{
    ColorBlanco();
    Posicion(49, 16);
    if (opMenu == 1) cout << ">> 1. Iniciar    "; else cout << "   1. Iniciar    ";

    Posicion(49, 18);
    if (opMenu == 2) cout << ">> 2. Tutorial   "; else cout << "   2. Tutorial   ";

    Posicion(49, 20);
    if (opMenu == 3) cout << ">> 3. Creditos   "; else cout << "   3. Creditos   ";

    Posicion(49, 22);
    if (opMenu == 4) cout << ">> 4. Salir      "; else cout << "   4. Salir      ";
}

void DibujarNivel() {
}
void DibujarNaveGrande1(int x, int y) {
    Posicion(x+2, y);   cout << "=====\\";
    Posicion(x, y+1); cout << "3=| | | ->";
    Posicion(x+2, y+2); cout << "=====/";
}
void DibujarNaveGrande2(int x, int y) {
    Posicion(x + 2, y);   cout << "/=====";
    Posicion(x, y + 1); cout << "<-| | | =3";
    Posicion(x + 2, y + 2); cout << "\\=====";
}
void BorrarNaveGrande(int x, int y) {
    Posicion(x + 2, y);   cout << "       ";
    Posicion(x, y + 1); cout << "          ";
    Posicion(x + 2, y + 2); cout << "      ";
}
void DibujarPersonas(int x, int y) {
    Posicion(x , y);    cout << "Ö";
    Posicion(x, y + 1); cout << "▀";
}
void DibujarAsteroide(int x) { // asteroidesssssssssss
    int x2 = Asteroidesmatrix[x][1];
    int y2 = Asteroidesmatrix[x][2];
    Posicion(x2, y2); cout << "@";
}
void AnimacionBorrar() {
    for (int i = 120; i > 0; i = i - 6) {
        for (int j = 0; j < 29; j++) {
            Posicion(i - 6, j); cout << "|      ";

        }
        _sleep(1);
    }
    Console::Clear();
}
void DibujarMediaLuna(int x, int y) {
    ColorBlanco();
    Posicion(x+5, y);      cout << "_..";
    Posicion(x+3, y+1);  cout << ".::::";
    Posicion(x+2, y+2); cout << "::::::";
    Posicion(x+2, y+3); cout << "::::::";
    Posicion(x+2, y+4); cout << "`:::::";
    Posicion(x+4, y+5);   cout << "`'--";
}

void DibujarMediaTierra(int x, int y)
{
    ColorBlanco();
    Posicion(x, y);    cout << "..._";
    Posicion(x, y+1);  cout << "::::::..";
    Posicion(x, y+2);  cout << ":::::::::.";
    Posicion(x, y+3);  cout << "::::::::::.";
    Posicion(x, y+4);  cout << ":::::::::::.";
    Posicion(x, y+5);  cout << "::::::::::::";
    Posicion(x, y+6);  cout << "::::::::::::";
    Posicion(x, y+7);  cout << "::::::::::::";
    Posicion(x, y+8);  cout << "::::::::::::";
    Posicion(x, y+9);  cout << ":::::::::::`";
    Posicion(x, y+10); cout << "::::::::::`";
    Posicion(x, y+11); cout << ":::::::::`";
    Posicion(x, y+12); cout << ":::::::`";
    Posicion(x, y+13); cout << "---'";
}
void BorrarYMovernaves() {
    // Borrar naves que se mueven
    Posicion(n1x, n1y); cout << "   ";
    Posicion(n2x, n2y); cout << "   ";
    Posicion(n3x, n3y); cout << "   ";

    // para mover las naves a la derecha
    n1x++; n2x += 2; n3x += 1;
    if (n1x > 115) n1x = 0;
    if (n2x > 115) n2x = 0;
    if (n3x > 115) n3x = 0;
}
void DibujarNaves() {
    ColorBlanco();
    Posicion(n1x, n1y); cout << ">=>";
    Posicion(n2x, n2y); cout << ">=>";
    Posicion(n3x, n3y); cout << ">=>";
    _sleep(50);
}
void DibujarCreditos(int x, int y) {
    Posicion(x, y);   cout << " _______  ______    _______  ______   ___   _______  _______  _______";
    Posicion(x, y+1); cout << "|       ||    _ |  |       ||      | |   | |       ||       ||       |";
    Posicion(x, y+2); cout << "|       ||   | ||  |    ___||  _    ||   | |_     _||   _   ||  _____|";
    Posicion(x, y+3); cout << "|       ||   |_||_ |   |___ | | |   ||   |   |   |  |  | |  || |_____ ";
    Posicion(x, y+4); cout << "|      _||    __  ||    ___|| |_|   ||   |   |   |  |  |_|  ||_____  |";
    Posicion(x, y+5); cout << "|     |_ |   |  | ||   |___ |       ||   |   |   |  |       | _____| |";
    Posicion(x, y+6); cout << "|_______||___|  |_||_______||______| |___|   |___|  |_______||_______|";
}
void Alto(int x, int y, int n) {
    for (int i = 0; i < n; i++) {
        y++;
        Posicion(x, y); cout << "*";
    }
}
void Ancho(int x, int y, int n) {
    for (int i = 0; i < n; i++) {
        x += 2;
        Posicion(x, y); cout << "*";
    }
}
}
void WASDmover(char teclacohete) {
    if ((teclacohete == 'w' || teclacohete == 'W') && (py > 1)) {
        py--;
    }
    if ((teclacohete == 's' || teclacohete == 'S') && (py < 27)) {
        py++;
    }
    if ((teclacohete == 'a' || teclacohete == 'A') && (px > 0)) {
        px -= 1;
    }
    if ((teclacohete == 'd' || teclacohete == 'D') && (px < 110)) {
        px += 1;
    }
}
void Protagonistamover() {
    if (_kbhit()) {
        BorrarNaveGrande(px, py);
        char tecla2 = _getch();
        WASDmover(tecla2);
        if (tecla2 == 'd' || tecla2 == 'D') owo = true;
        if (tecla2 == 'a' || tecla2 == 'a') owo = false;
    }
    if (owo) {
        DibujarNaveGrande1(px, py);
    }
    else {
        DibujarNaveGrande2(px, py);
    }
}
void AsteroideConvertor(int x, int y) {
}
void AsteroidesMov() {
}