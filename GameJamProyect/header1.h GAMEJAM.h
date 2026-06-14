#include <iostream>
#include <conio.h>
#include <ctime>

using namespace std;
using namespace System;

// variables en general para el menu y las naves
int n1x = 0, n2x = 40, n3x = 80, n1y = 5, n2y = 12, n3y = 22; //Stephen naves menú
int opMenu = 1, opFinal = 0; //Stephen Opciones menú
int px = 100, py = 11;  //coordenadas de la nave Christian
bool owo; // boleano para el movimiento del cohete
bool yaJugoTutorial = false; // controla si el usuario ya completó el tutorial Stephen
int velCohete = 2; //Velocidad cohete Christian
int animacionpanel = 0, panel2= 0;
bool coheteIzqoDer = true; // boleano para determinar donde aparecerá el cohete cuando choque Christian
int avcx = 0; //Para la animación de la velocidad del cohete Christian
int atpr = 0; //para la animación de recate de personas Christian
//asteroides Christian
int veloA = 5; //velocidad base
int ayx = 27, ayx2 = 10; //coordenadas y aumentos en base x
int ay1 = 0, ay2 = 0, ay3 = 0, ay4 = 0, ay5 = 0, ay6 = 0, ay7 = 0, ay8 = 0; //Coordenadas en tiempo real en base y
int av1 = veloA, av2= veloA+1, av3= veloA+2, av4= veloA+1, av5= veloA+2, av6= veloA, av7= veloA+2, av8= veloA+1; //Velocidades
int at1 = 0, at2 = 0, at3 = 0, at4 = 0, at5 = 0, at6 = 0, at7 = 0, at8 = 0; //tiempo de espera
//Personas Christian
int personasEnT, personasEnL, personasEnNoC; //personas en tierra, personas en luna, personas en nave o cohete
int cicloDePersonas = 3, numeroDePersonas = 4;
//vidas Deivid
int vidas = 0;
//booleanos para bucles Ch
bool whileiniciarjuego = true, jugardenuevo, Tutorialcondicion2;
//Tiempo Christian
int tiempoRestante;

void Posicion(int x, int y){Console::SetCursorPosition(x, y);}

void ColorBlanco()    {Console::ForegroundColor = ConsoleColor::White;}
void ColorAmarillo()  {Console::ForegroundColor = ConsoleColor::Yellow;}
void ColorVerde()     {Console::ForegroundColor = ConsoleColor::Green;}
void ColorRojo()      {Console::ForegroundColor = ConsoleColor::Red;}
void ColorNaranja()   {Console::ForegroundColor = ConsoleColor::DarkYellow;}
void ColorAzul()      {Console::ForegroundColor = ConsoleColor::Blue;}
void ColorNegro()     {Console::ForegroundColor = ConsoleColor::Black;}
void ColorMorado()    {Console::ForegroundColor = ConsoleColor::Magenta;}

void BColorRojo()     {Console::BackgroundColor = ConsoleColor::Red;}
void BColorAzul()     {Console::BackgroundColor = ConsoleColor::Blue;}
void BColorGris()     {Console::BackgroundColor = ConsoleColor::Gray;}
void BColorNegro()    {Console::BackgroundColor = ConsoleColor::Black;}
void BColorVerde()    {Console::BackgroundColor = ConsoleColor::Green;}
void BColorAmarillo() {Console::BackgroundColor = ConsoleColor::Yellow;}
void BColorCafe()     {Console::BackgroundColor = ConsoleColor::DarkYellow;}
void BColorMorado()   {Console::BackgroundColor = ConsoleColor::Magenta;}

void DibujarEstrellas()  //deivid
{
    ColorBlanco();
    Posicion(10, 3);   cout << "*";
    Posicion(30, 2);   cout << "*";
    Posicion(90, 4);   cout << "*";
    Posicion(50, 6);   cout << "*";
    Posicion(20, 25);  cout << "*";
    Posicion(85, 20);  cout << "*";
    Posicion(5, 23);   cout << "*";
    Posicion(105, 27); cout << "*";
    Posicion(80, 22);  cout << "*";
    Posicion(55, 24);  cout << "*";
}
void DibujarFondo()
{
    ColorBlanco();
    Posicion(10, 3);   cout << "*";
    Posicion(30, 8);   cout << "*";
    Posicion(90, 4);   cout << "*";
    Posicion(20, 18);  cout << "*";
    Posicion(85, 20);  cout << "*";
    Posicion(15, 25);  cout << "*";
    Posicion(105, 15); cout << "*";
}
void DibujarLuna()
{
    ColorAzul();
    Posicion(50, 2); cout << "     _..._     ";
    Posicion(50, 3); cout << "   .:::::::.   ";
    Posicion(50, 4); cout << "  :::::::::::  ";
    Posicion(50, 5); cout << "  :::::::::::  ";
    Posicion(50, 6); cout << "  `:::::::::'  ";
    Posicion(50, 7); cout << "    `'---'`    ";
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
void DibujarNaveGrande1(int x, int y) {
    ColorBlanco();
    Posicion(x + 2, y);   cout << "=====\\";
    Posicion(x, y + 1); ColorRojo(); cout << "3"; Posicion(x + 1, y + 1); ColorNaranja(); cout << "="; Posicion(x + 2, y + 1); ColorBlanco(); cout << "| | |->";
    Posicion(x + 2, y + 2); cout << "=====/";
    if (personasEnNoC > 1) {
        Posicion(x + 3, y + 1); BColorAmarillo(); cout << " "; Posicion(x + 5, y + 1); cout << " "; 
    }
    else if (personasEnNoC > 0) {
        BColorAmarillo(); Posicion(x + 5, y + 1); cout << " ";
    } BColorNegro();
}
void DibujarNaveGrande2(int x, int y) {
    ColorBlanco();
    Posicion(x + 2, y);     cout << "/=====";
    Posicion(x + 1, y + 1);   cout << "<-| | |"; Posicion(x + 8, y + 1); ColorNaranja(); cout << "="; Posicion(x + 9, y + 1); ColorRojo(); cout << "3"; ColorBlanco();
    Posicion(x + 2, y + 2); cout << "\\=====";
    if (personasEnNoC > 1) {
        Posicion(x + 5, y + 1); BColorAmarillo(); cout << " "; Posicion(x + 7, y + 1); cout << " ";
    }
    else if (personasEnNoC > 0) {
        BColorAmarillo(); Posicion(x + 5, y + 1); cout << " ";
    } BColorNegro();
}
void DibujarNaveExplota1(int x, int y) {
    ColorRojo(); 
    Posicion(x + 2, y);   cout << "=====\\";
    Posicion(x, y + 1);  cout << "3"; Posicion(x + 1, y + 1); cout << "="; Posicion(x + 2, y + 1); cout << "| | |->";
    Posicion(x + 2, y + 2); cout << "=====/";
    BColorRojo();
    if (personasEnNoC > 1) {
        Posicion(x + 3, y + 1);  cout << " "; Posicion(x + 5, y + 1); cout << " ";
    }
    else if (personasEnNoC > 0) {
        Posicion(x + 5, y + 1); cout << " ";
    } BColorNegro(); ColorBlanco();
}
void DibujarNaveExplota2(int x, int y) {
    ColorRojo();
    Posicion(x + 2, y);     cout << "/=====";
    Posicion(x + 1, y + 1);   cout << "<-| | |"; Posicion(x + 8, y + 1); cout << "="; Posicion(x + 9, y + 1); cout << "3";
    Posicion(x + 2, y + 2); cout << "\\=====";
    BColorRojo();
    if (personasEnNoC > 1) {
        Posicion(x + 5, y + 1); cout << " "; Posicion(x + 7, y + 1); cout << " ";
    }
    else if (personasEnNoC > 0) {
        Posicion(x + 5, y + 1); cout << " ";
    } BColorNegro(); ColorBlanco();
}
void BorrarNaveGrande(int x, int y) {
    Posicion(x + 2, y);    cout << "       ";
    Posicion(x, y + 1);   cout << "          ";
    Posicion(x + 2, y + 2);cout << "      ";
}

void DibujarPersona(int x, int y) {      // DIBUJAR PERSONAS
    Posicion(x, y);     cout << "(o)/"; 
    Posicion(x, y + 1); cout << "/[]";
    Posicion(x, y + 2); cout << "/ \\";                       // DIBUJAR CARIAS PEEEEEEEEEERSOOOOOOONAAAAS  //int cicloDePersonas = 3, numeroDePersonas = 4;
}
void BorrarPersona(int x, int y) {
    Posicion(x, y);     cout << "    ";
    Posicion(x, y + 1); cout << "   ";
    Posicion(x, y + 2); cout << "   ";
}
void DibujarVariasPersonas(int x, int y) {                 //int personasEnT, personasEnL, personasEnNoC; //personas en tierra, personas en luna, personas en nave o cohete
    BorrarPersona(x + 2, y);
    BorrarPersona(x + 10, y + 3);
    BorrarPersona(x + 10, y + 13);
    BorrarPersona(x + 2, y + 17); if (numeroDePersonas >= 4) { ColorAmarillo(); DibujarPersona(x + 2, y); }
    if (numeroDePersonas >= 3) { ColorMorado(); DibujarPersona(x + 10, y + 3); }
    if (numeroDePersonas >= 2) { ColorVerde(); DibujarPersona(x + 10, y + 13); }
    if (numeroDePersonas >= 1) { ColorRojo(); DibujarPersona(x + 2, y + 17); }
}
void AnimacionBorrar() {  //animación para borrar pantalla
    for (int i = 120; i > 0; i = i - 6) {
        for (int j = 0; j < 29; j++) { Posicion(i - 6, j); cout << "|      "; }
        _sleep(1);
    }
    Console::Clear();
}
void DibujarMediaLuna(int x, int y) {
    ColorAzul();
    Posicion(x+5, y);      cout << "_..";
    Posicion(x+3, y+1);  cout << ".::::";
    Posicion(x+2, y+2); cout << "::::::";
    Posicion(x+2, y+3); cout << "::::::";
    Posicion(x+2, y+4); cout << "`:::::";
    Posicion(x+4, y+5);   cout << "`'--";
}
void DibujarMediaTierra(int x, int y)
{
    ColorVerde();
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
void Dibujartitulo() {
    ColorMorado();
    Posicion(10, 8); cout << "         _                      _       _____ _____   ________   __               _ _ _   _             ";
    Posicion(10, 9); cout << "    /\\  | |                    (_)     |_   _|_   _| |  ____\\ \\ / /              | (_) | (_)            ";
    Posicion(10, 10); cout << "   /  \\ | |_ ___ _ __ _ __ ___  _ ___    | |   | |   | |__   \\ V / _ __   ___  __| |_| |_ _  ___  _ __  ";
    Posicion(10, 11); cout << "  / /\\ \\| __/ _ \\ '__| '_ ` _ \\| / __|   | |   | |   |  __|   > < | '_ \\ / _ \\/ _` | | __| |/ _ \\| '_ \\ ";
    Posicion(10, 12); cout << " / ____ \\ ||  __/ |  | | | | | | \\__ \\  _| |_ _| |_  | |____ / . \\| |_) |  __/ (_| | | |_| | (_) | | | |";
    Posicion(10, 13); cout << "/_/    \\_\\__\\___|_|  |_| |_| |_|_|___/ |_____|_____| |______/_/ \\_\\ .__/ \\___|\\__,_|_|\\__|_|\\___/|_| |_|";
    Posicion(10, 14); cout << "                                                                  | |";
    Posicion(10, 15); cout << "                                                                  |_|";
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
void DibujarVictoria() {
    bool victoria;
    int vic = 0;
    AnimacionBorrar();
    do {
        BorrarYMovernaves();
        DibujarEstrellas();
        if (vic == 32) { vic = 0; }
        if (vic >= 16) { ColorVerde(); }
        if (vic <= 16) { ColorAzul(); }
        
        Posicion(20, 5); cout << "    _ __  ____      _   __           ______                      ___     __________ ";
        Posicion(20, 6); cout << "   (_)  |/  (_)____(_)_/_/ ____     / ____/_  ______ ___  ____  / (_)___/ /  _  / /";
        Posicion(20, 7); cout << "  / / /|_/ / / ___/ / __ \\/ __ \\   / /   / / / / __ `__ \\/ __ \\/ / / __  / /_/ / /";
        Posicion(20, 8); cout << " / / /  / / (__  ) / /_/ / / / /  / /___/ /_/ / / / / / / /_/ / / / /_/ /  _  /_/ ";
        Posicion(20, 9); cout << "/_/_/  /_/_/____/_/\\____/_/ /_/   \\____/\\__,_/_/ /_/ /_/ .___/_/_/\\__,_/\\/ /_(_)";
        Posicion(20, 10); cout << "                                                      /_/                      ";
        
        ColorVerde();
        Posicion(20, 11); cout << "¡Todas las personas estan a salvo!";
        ColorAmarillo();
        Posicion(10, 27); cout << "Pulse Z para continuar";
        ColorBlanco();
        DibujarNaves();
        vic++;
        if (kbhit()) {
            char tecla = getch();
            if (tecla == 'z' || tecla == 'Z' || tecla == 13) {
                victoria = false;
            }
        }
    } while (victoria);

}                                                                    
void DibujarGameOver(int x, int y, int x1, int y1, int x2, int y2) {
    ColorRojo();
    Posicion(x, y);     cout << "   _____.  __                 __";
    Posicion(x, y + 1); cout << "  /  _  \\ |  |   ____________/  |______   ";
    Posicion(x, y + 2); cout << " /  /_\\  \\|  | _/ __ \\_  __ \\   __\\__  \\";
    Posicion(x, y + 3); cout << "/    |    \\  |_\\  ___/|  | \\/|  |  / __ \\_";
    Posicion(x, y + 4); cout << "\\____|__  /____/\\___  >__|   |__| (____  /";
    Posicion(x, y + 5); cout << "        \\/          \\/                 \\/ ";

    ColorAmarillo();
    Posicion(x1, y1); cout << "==========================================================";
    Posicion(x1, y1 + 1); cout << "[ MISION FALLIDA ]   Artemis II Lunar Expedition";
    Posicion(x1, y1 + 2); cout << "[ CAUSA ]   Impacto de meteorico";
    Posicion(x1, y1 + 3); cout << "==========================================================";

    ColorRojo();
    Posicion(x2, y2);     cout << "_________.                             __                __________.                 ___.__.    ___";
    Posicion(x2, y2 + 1); cout << "\\_   ___ \\  ____   ____   ____ ___  __|__| ____   ____   \\______   \\ ___________  __| _/|__| __| _/____  ";
    Posicion(x2, y2 + 2); cout << "/    \\  \\/ /  _ \\ /    \\_/ __ \\\\  \\/  /  |/  _ \\ /    \\   |     ___// __ \\_  __ \\/ __ | |  |/ __ |\\__  \\  ";
    Posicion(x2, y2 + 3); cout << "\\     \\___(  <_> )   |  \\  ___/ >    <|  (  <_> )   |  \\  |    |   \\  ___/|  | \\/ /_/ | |  / /_/ | / __ \\_";
    Posicion(x2, y2 + 4); cout << " \\______  /\\____/|___|  /\\___  >__/\\_ \\__|\\____/|___|  /  |____|    \\___  >__|  \\____ | |__\\____ |(____  /";
    Posicion(x2, y2 + 5); cout << "        \\/            \\/     \\/      \\/              \\/                 \\/           \\/         \\/     \\/ ";
}
void Presentacion(int x, int y) {
    ColorVerde();
    Posicion(x, y);       cout << "    ____  _                            _     __ ";
    Posicion(x, y+1);     cout << "   / __ )(_)__  ____ _   _____  ____  (_)___/ /___     ____ _ ";
    Posicion(x, y+2);     cout << "  / __  / / _ \\/ __ \\ | / / _ \\/ __ \\/ / __  / __ \\   / __ `/ ";
    Posicion(x, y+3);     cout << " / /_/ / /  __/ / / / |/ /  __/ / / / / /_/ / /_/ /  / /_/ / ";
    Posicion(x, y+4);     cout << "/_____/_/\\___/_/ /_/|___/\\___/_/ /_/_/\\__,_/\\____/   \\__,_/  ";
    Posicion(x, y+5);     cout << "                                                             ";
}
void Animacionpresentacion() {
    for (int i = 60; i>=10;i--) {
        Presentacion(i, 10);
        _sleep(2);
        DibujarEstrellas();
        DibujarFondo();
    }
    _sleep(2000);
    AnimacionBorrar();
}
void Alto(int x, int y, int n) {
    for (int i = 0; i < n; i++) { y++; Posicion(x, y); cout << "*"; }
}
void Ancho(int x, int y, int n) {
    for (int i = 0; i < n; i++) { x += 2; Posicion(x, y); cout << "*"; }
}
void ImprimirWASD() {  //visual
    ColorAzul(); Posicion(34, 27); cout << "W";
    ColorAzul(); Posicion(32, 28); cout << "A";
    ColorAzul(); Posicion(34, 29); cout << "S";
    ColorAzul(); Posicion(36, 28); cout << "D";
}
void AnimacionWASD(int x) {  //visual
    ColorAmarillo();
    switch (x) {
    case 1: Posicion(34, 27); cout << "W"; break;
    case 2: Posicion(32, 28); cout << "A"; break;
    case 3: Posicion(34, 29); cout << "S"; break;
    case 4: Posicion(36, 28); cout << "D"; break;
    }
}
void WASDmover(char teclacohete) { //un movimiento W A S D
    if ((teclacohete == 'w' || teclacohete == 'W') && (py > 0 + velCohete+1)) { py-= velCohete; ImprimirWASD(); AnimacionWASD(1); }
    if ((teclacohete == 's' || teclacohete == 'S') && (py < 23 - velCohete)) { py+= velCohete; ImprimirWASD(); AnimacionWASD(3); }
    if ((teclacohete == 'a' || teclacohete == 'A') && (px > 0 + velCohete)) { px -= velCohete; ImprimirWASD(); AnimacionWASD(2); }
    if ((teclacohete == 'd' || teclacohete == 'D') && (px < 111 - velCohete-1)) { px += velCohete; ImprimirWASD(); AnimacionWASD(4); }
}
void Protagonistamover() {  //movimiento del cohete (lo copié de nuestro proyecto xd)
    if (_kbhit()) {
        BorrarNaveGrande(px, py);
        char tecla2 = _getch();
        WASDmover(tecla2);
        if (tecla2 == 'd' || tecla2 == 'D') owo = true;
        if (tecla2 == 'a' || tecla2 == 'A') owo = false;
    }
    if (owo) DibujarNaveGrande1(px, py);
    if (owo == false) DibujarNaveGrande2(px, py);
}
void AnimacionNaveExplota() {
    if (owo) {
        for (int i = 0; i < 6; i++) { if (i == 0 || i == 2 || i == 4) DibujarNaveExplota1(px, py); else DibujarNaveGrande1(px, py); _sleep(200); }
    }
    if (owo == false) {
        for (int i = 0; i < 6; i++) { if (i == 0 || i == 2 || i == 4) DibujarNaveExplota2(px, py); else DibujarNaveGrande2(px, py); _sleep(200); }
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
    if (ay1 >= 25) { BorrarAsteroide(ayx, ay1);            ay1 = 0; av1 = rand() % 4 + veloA; at1 = 0; }  //ay1..ay2.. etc, son las variables de la posición en tiempo real de los asteroides, cada uno anotado individualmente
    if (ay2 >= 25) { BorrarAsteroide(ayx + ayx2, ay2);     ay2 = 0; av2 = rand() % 4 + veloA; at2 = 0; }
    if (ay3 >= 25) { BorrarAsteroide(ayx + ayx2 * 2, ay3); ay3 = 0; av3 = rand() % 4 + veloA; at3 = 0; }  //av1...av2..etc, variables para generar números aleatorios para la velocidad aleatoria
    if (ay4 >= 25) { BorrarAsteroide(ayx + ayx2 * 3, ay4); ay4 = 0; av4 = rand() % 4 + veloA; at4 = 0; }  //VeloA es solo una variable sumatoria
    if (ay5 >= 25) { BorrarAsteroide(ayx + ayx2 * 4, ay5); ay5 = 0; av5 = rand() % 4 + veloA; at5 = 0; }  //at1..at2.. son la cantidad de "ticks" o "clocks" o las veces que tiene que cargar para avanzar 1 paso por asteroides, por ejemplo si at2 es 8, tendrá que cargar la secuencia repetitiva 8 veces para que pueda avanzar 1 paso
    if (ay6 >= 25) { BorrarAsteroide(ayx + ayx2 * 5, ay6); ay6 = 0; av6 = rand() % 4 + veloA; at6 = 0; }   //ayx es la coordenada orizontal general de todas, todas empiezan con 27 y son sumadas de 10 en 10
    if (ay7 >= 25) { BorrarAsteroide(ayx + ayx2 * 6, ay7); ay7 = 0; av7 = rand() % 4 + veloA; at7 = 0; }    //rand() % 4, número aleatorio entre el 0 y el 3
    if (ay8 >= 25) { BorrarAsteroide(ayx + ayx2 * 7, ay8); ay8 = 0; av8 = rand() % 4 + veloA; at8 = 0; }

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
void AnimacionVelocidad(bool x) {
    if (x) avcx = 48;
    if ((avcx >= 8 && avcx <=16) || (avcx >= 24 && avcx <= 32) || (avcx >= 40 && avcx <= 48)) ColorRojo(); else ColorAmarillo();
    Posicion(70, 28); cout << velCohete << " km/h";
    if (avcx > 0) avcx--;
}
void ImprimirVidas() {
    Posicion(1, 27); cout << "      ";
    Posicion(1, 28); cout << "      ";
    Posicion(1, 29); cout << "      ";

    Posicion(8, 27); cout << "      ";
    Posicion(8, 28); cout << "      ";
    Posicion(8, 29); cout << "      ";

    Posicion(15, 27); cout << "      ";
    Posicion(15, 28); cout << "      ";
    Posicion(15, 29); cout << "      ";

    if (vidas == 1) {
        ImprimirCorazon(1, 27);
    }
    if (vidas == 2) {
        ImprimirCorazon(1, 27); ImprimirCorazon(8, 27);
    }
    if (vidas == 3) {
        ImprimirCorazon(1, 27); ImprimirCorazon(8, 27); ImprimirCorazon(15, 27);
    }
}
void PaneldeControl(){                                         //quité la secuencia repetitiva por que por alguna razón que no supe el por que pues dejó de funcionar, me dió weba asiq lo imprimí :VVVV                                  
    ColorVerde();Posicion(0, 26); cout << "========================================================================================================================";
    ImprimirCorazon(1,27);ImprimirCorazon(8, 27);ImprimirCorazon(15, 27);
    ColorRojo();Posicion(22, 28); cout << "Vidas";
    ImprimirWASD();
    ColorVerde();Posicion(42, 28); cout << "Tiempo:";
    ColorAmarillo();Posicion(59, 28); cout << "Velocidad:";
    ColorAzul() ;Posicion(82, 28); cout << "Personas rescatadas:";
    ColorMorado();Posicion(110, 28); cout << "Nave ORION";
    ImprimirVidas();
}
void AnimacionTextoPanelRescate(int x) {
    if (x) atpr = 48;
    if ((atpr >= 8 && atpr <= 16) || (atpr >= 24 && atpr <= 32) || (atpr >= 40 && atpr <= 48)) ColorRojo(); else ColorAmarillo();
    Posicion(103, 28); cout << personasEnL << "/12";
    if (atpr > 0) atpr--;
}
void AnimacionPanel() {   // Una animación para el panel pq lo sentí muy apagado
    if (animacionpanel == 2) {
        ColorVerde();Posicion(panel2, 26); cout << "==";
        ColorRojo(); Posicion(panel2 + 1, 26); cout << "=="; ColorBlanco();
        panel2++; animacionpanel = 0;
    }
    else {animacionpanel++;}
    if (panel2 == 118) {
        ColorVerde();Posicion(118, 26); cout << "==";
        panel2 = 0;
    }
    ColorBlanco();
}
void ColisionAparecerIzquierda() {
    if (vidas>=1){
        Posicion(px, py); cout << "          ";
        Posicion(px, py + 1); cout << "          ";
        Posicion(px, py + 2); cout << "          ";
        py = 11; if (coheteIzqoDer) px = 105; else px = 10;
    }
}
void colision() {  // colisiones Deivid
    if (vidas >= 1) {
        if (ayx <= px + 7 && ayx >= px + 2 && ay1 < py + 2 && ay1 >= py) { vidas--; ImprimirVidas(); ColisionAparecerIzquierda(); }
        if (ayx + ayx2 <= px + 7 && ayx + ayx2 >= px + 2 && ay2 < py + 2 && ay2 >= py) { vidas--; ImprimirVidas(); ColisionAparecerIzquierda(); }
        if (ayx + ayx2 * 2 <= px + 7 && ayx + ayx2 * 2 >= px + 2 && ay3 < py + 2 && ay3 >= py) { vidas--; ImprimirVidas(); ColisionAparecerIzquierda(); }
        if (ayx + ayx2 * 3 <= px + 7 && ayx + ayx2 * 3 >= px + 2 && ay4 < py + 2 && ay4 >= py) { vidas--; ImprimirVidas(); ColisionAparecerIzquierda(); }
        if (ayx + ayx2 * 4 <= px + 7 && ayx + ayx2 * 4 >= px + 2 && ay5 < py + 2 && ay5 >= py) { vidas--; ImprimirVidas(); ColisionAparecerIzquierda(); }
        if (ayx + ayx2 * 5 <= px + 7 && ayx + ayx2 * 5 >= px + 2 && ay6 < py + 2 && ay6 >= py) { vidas--; ImprimirVidas(); ColisionAparecerIzquierda(); }
        if (ayx + ayx2 * 6 <= px + 7 && ayx + ayx2 * 6 >= px + 2 && ay7 < py + 2 && ay7 >= py) { vidas--; ImprimirVidas(); ColisionAparecerIzquierda(); }
        if (ayx + ayx2 * 7 <= px + 7 && ayx + ayx2 * 7 >= px + 2 && ay8 < py + 2 && ay8 >= py) { vidas--; ImprimirVidas(); ColisionAparecerIzquierda(); }
    }
}
void PoscicionCoheteIzqoDer() {  //px y py == coordenadas de la nave // coheteizoder  // izquierda es falso, derecha es verdadero
    if (px <= 12 && coheteIzqoDer == true) { 
        coheteIzqoDer = false; 
        velCohete = rand() % 3 + 1; 
        AnimacionVelocidad(true); 
        personasEnT -= 2; personasEnNoC += 2;
        BorrarPersona(1 + 2, 3);
        BorrarPersona(1 + 10, 3 + 3);
        BorrarPersona(1 + 10, 3 + 13);
        BorrarPersona(1 + 2, 3 + 17);
        numeroDePersonas -= 2;
    }
    if (px >= 105 && coheteIzqoDer == false) { 
        coheteIzqoDer = true; 
        personasEnNoC -= 2; personasEnL += 2;
        ColorVerde(); Posicion(103, 28); 
        AnimacionTextoPanelRescate(true);
        if (cicloDePersonas!=0)
            if (numeroDePersonas == 0) { numeroDePersonas = 4; cicloDePersonas--; }
    }
}
void AnimacionDerrota() {
    AnimacionBorrar();
    bool derrota;
    DibujarEstrellas();
    DibujarGameOver(10, 7, 10, 13, 10, 17);
    ColorAmarillo();
    Posicion(10, 27); cout << "Pulse Z para continuar";
    ColorBlanco();
    do {
        if (kbhit()) {
            char tecla = getch();
            if (tecla == 'z' || tecla == 'Z' || tecla == 13) {
                derrota = false;
            }
        }
    } while (derrota);
}