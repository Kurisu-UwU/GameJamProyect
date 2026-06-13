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
int px = 100, py = 11;
bool owo; // boleano para el movimiento del cohete
int Asteroidesmatrix[10][2];
int animacionpanel = 0, panel2= 0;
//asteroides
int veloA = 4; //velocidad base
int ayx = 27, ayx2 = 10; //coordenadas y aumentos en base x
int ay1 = 0, ay2 = 0, ay3 = 0, ay4 = 0, ay5 = 0, ay6 = 0, ay7 = 0, ay8 = 0; //Coordenadas en tiempo real en base y
int av1 = veloA, av2= veloA+1, av3= veloA+2, av4= veloA+1, av5= veloA+2, av6= veloA, av7= veloA+2, av8= veloA+1; //Velocidades
int at1 = 0, at2 = 0, at3 = 0, at4 = 0, at5 = 0, at6 = 0, at7 = 0, at8 = 0; //tiempo de espera

void Posicion(int x, int y){Console::SetCursorPosition(x, y);}
void ColorBlanco()         {Console::ForegroundColor = ConsoleColor::White;}
void ColorAmarillo()       {Console::ForegroundColor = ConsoleColor::Yellow;}
void ColorVerde()          {Console::ForegroundColor = ConsoleColor::Green;}
void ColorRojo()           {Console::ForegroundColor = ConsoleColor::Red;}
void ColorNaranja()        {Console::ForegroundColor = ConsoleColor::DarkYellow;}
void ColorAzul()           {Console::ForegroundColor = ConsoleColor::Blue;}
void ColorNegro()          {Console::ForegroundColor = ConsoleColor::Black;}
void ColorMorado()         {Console::ForegroundColor = ConsoleColor::Magenta;}

void BColorRojo()    {Console::BackgroundColor = ConsoleColor::Red;}
void BColorAzul()    {Console::BackgroundColor = ConsoleColor::Blue;}
void BColorGris()    {Console::BackgroundColor = ConsoleColor::Gray;}
void BColorNegro()   {Console::BackgroundColor = ConsoleColor::Black;}
void BColorVerde()   {Console::BackgroundColor = ConsoleColor::Green;}
void BColorAmarillo(){Console::BackgroundColor = ConsoleColor::Yellow;}
void BColorCafe()    {Console::BackgroundColor = ConsoleColor::DarkYellow;}
void BColorMorado()  {Console::BackgroundColor = ConsoleColor::Magenta;}

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
    Posicion(x, y + 1); ColorRojo(); cout << "3"; Posicion(x + 1, y + 1); ColorNaranja(); cout << "="; Posicion(x + 2, y + 1); ColorBlanco(); cout << "| | | ->"; 
    Posicion(x+2, y+2); cout << "=====/";
}
void DibujarNaveGrande2(int x, int y) {
    Posicion(x + 2, y);   cout << "/=====";
    Posicion(x, y + 1); cout << "<-| | | "; Posicion(x + 8, y + 1); ColorNaranja(); cout << "="; Posicion(x+9, y + 1); ColorRojo(); cout << "3"; ColorBlanco();
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
void WASDmover(char teclacohete) { //un movimiento W A S D
    if ((teclacohete == 'w' || teclacohete == 'W') && (py > 1)) {py--;}
    if ((teclacohete == 's' || teclacohete == 'S') && (py < 23)) {py++;}
    if ((teclacohete == 'a' || teclacohete == 'A') && (px > 0)) { px -= 1;}
    if ((teclacohete == 'd' || teclacohete == 'D') && (px < 110)) {px += 1;}
}
void Protagonistamover() {  //movimiento del cohete (lo copié de nuestro proyecto xd)
    if (_kbhit()) {
        BorrarNaveGrande(px, py);
        char tecla2 = _getch();
        WASDmover(tecla2);
        if (tecla2 == 'd' || tecla2 == 'D') owo = true;
        if (tecla2 == 'a' || tecla2 == 'A') owo = false;
    }
    if (owo) {
        DibujarNaveGrande1(px, py);
    }
    if (owo == false) {
        DibujarNaveGrande2(px, py);
    }
}
void DibujarAsteroide(int x, int y) { // asteroidesssssssssss
    Posicion(x, y); cout << "@";
}
void BorrarAsteroide(int x, int y) { // asteroidesssssssssss
    Posicion(x, y); cout << " ";
}
void AsteroidesMov() {  //IMPORTANTE
    ColorMorado();
    if (ay1 >= 24) { BorrarAsteroide(ayx, ay1);            ay1 = 0; av1 = rand() % 4 + veloA; at1 = 0; }  //ay1..ay2.. etc, son las variables de la posición en tiempo real de los asteroides, cada uno anotado individualmente
    if (ay2 >= 24) { BorrarAsteroide(ayx + ayx2, ay2);     ay2 = 0; av2 = rand() % 4 + veloA; at2 = 0; }
    if (ay3 >= 24) { BorrarAsteroide(ayx + ayx2 * 2, ay3); ay3 = 0; av3 = rand() % 4 + veloA; at3 = 0; }  //av1...av2..etc, variables para generar números aleatorios para la velocidad aleatoria
    if (ay4 >= 24) { BorrarAsteroide(ayx + ayx2 * 3, ay4); ay4 = 0; av4 = rand() % 4 + veloA; at4 = 0; }  //VeloA es solo una variable sumatoria
    if (ay5 >= 24) { BorrarAsteroide(ayx + ayx2 * 4, ay5); ay5 = 0; av5 = rand() % 4 + veloA; at5 = 0; }  //at1..at2.. son la cantidad de "ticks" o "clocks" o las veces que tiene que cargar para avanzar 1 paso por asteroides, por ejemplo si at2 es 8, tendrá que cargar la secuencia repetitiva 8 veces para que pueda avanzar 1 paso
    if (ay6 >= 24) { BorrarAsteroide(ayx + ayx2 * 5, ay6); ay6 = 0; av6 = rand() % 4 + veloA; at6 = 0; }   //ayx es la coordenada orizontal general de todas, todas empiezan con 27 y son sumadas de 10 en 10
    if (ay7 >= 24) { BorrarAsteroide(ayx + ayx2 * 6, ay7); ay7 = 0; av7 = rand() % 4 + veloA; at7 = 0; }    //
    if (ay8 >= 24) { BorrarAsteroide(ayx + ayx2 * 7, ay8); ay8 = 0; av8 = rand() % 4 + veloA; at8 = 0; }

    if (at1 >= av1) { BorrarAsteroide(ayx, ay1);            ay1++; DibujarAsteroide(ayx, ay1);            at1=0; }  //esta locura
    if (at2 >= av2) { BorrarAsteroide(ayx + ayx2, ay2);     ay2++; DibujarAsteroide(ayx + ayx2, ay2);     at2=0; }
    if (at3 >= av3) { BorrarAsteroide(ayx + ayx2 * 2, ay3); ay3++; DibujarAsteroide(ayx + ayx2 * 2, ay3); at3=0; }
    if (at4 >= av4) { BorrarAsteroide(ayx + ayx2 * 3, ay4); ay4++; DibujarAsteroide(ayx + ayx2 * 3, ay4); at4=0; }
    if (at5 >= av5) { BorrarAsteroide(ayx + ayx2 * 4, ay5); ay5++; DibujarAsteroide(ayx + ayx2 * 4, ay5); at5=0; }
    if (at6 >= av6) { BorrarAsteroide(ayx + ayx2 * 5, ay6); ay6++; DibujarAsteroide(ayx + ayx2 * 5, ay6); at6=0; }
    if (at7 >= av7) { BorrarAsteroide(ayx + ayx2 * 6, ay7); ay7++; DibujarAsteroide(ayx + ayx2 * 6, ay7); at7=0; }
    if (at8 >= av8) { BorrarAsteroide(ayx + ayx2 * 7, ay8); ay8++; DibujarAsteroide(ayx + ayx2 * 7, ay8); at8=0; }
    at1++; at2++; at3++; at4++; at5++; at6++; at7++; at8++;

}
void ImprimirCorazon(int x, int y) {    // un corazoncito uwu
    Posicion(x, y); BColorRojo(); cout << "  ";
    Posicion(x + 4, y); cout << "  ";
    Posicion(x, y + 1); cout << "      ";
    Posicion(x + 2, y + 2); cout << "  "; BColorNegro();
}
void PaneldeControl(){
                                                                    //quité la secuencia repetitiva por que por alguna razón que no supe el por que pues dejó de funcionar, me dió weba asiq lo imprimí :VVVV
    ColorVerde();Posicion(0, 26); cout << "========================================================================================================================";
    ImprimirCorazon(1,27);ImprimirCorazon(8, 27);ImprimirCorazon(15, 27);
    ColorRojo();Posicion(22, 28); cout << "Vidas";
    ColorAzul();Posicion(33, 28); cout << "WASD";
    ColorVerde();Posicion(44, 28); cout << "Tiempo:";
    ColorAmarillo();Posicion(60, 28); cout << "Velocidad:";
    ColorVerde();Posicion(80, 28); cout << "Personas rescatadas:";
    ColorMorado();Posicion(110, 28); cout << "Nave ORION";
}
void AnimacionPanel() {   // Una animación para el panel pq lo sentí muy apagado
    if (animacionpanel == 2) {
        ColorVerde();Posicion(panel2, 26); cout << "= ";
        BColorRojo(); Posicion(panel2 + 1, 26); cout << "  "; BColorNegro();
        panel2++; animacionpanel = 0;
    }
    else {animacionpanel++;}
    if (panel2 == 118) {
        ColorVerde();Posicion(118, 26); cout << "==";
        panel2 = 0;
    }
    ColorBlanco();
}