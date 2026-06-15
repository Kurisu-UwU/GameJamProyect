#include "Juego.h"

int main() // Todo esto es el menú
{
    Console::CursorVisible = false;
    Animacionpresentacion();
    bool enCarga; // condicion para el bucle
    Console::Clear();
    bool enCarga2 = true;
    bool Menucondicioncreditos = true;
    do {
        srand(time(0)); // condición aleatoria Christian
        do //para mantener el menu en pantalla
        {
            enCarga = true;
            BorrarYMovernaves();
            DibujarLuna();
            DibujarMenu();
            DibujarFondo();
            ColorMorado();
            Dibujartitulo();
            DibujarNaves();
            if (kbhit())
            {
                char tecla = getch();
                if (tecla == 'w' || tecla == 'W')
                {
                    opMenu--;
                    if (opMenu < 1) opMenu = 4;
                }
                if (tecla == 's' || tecla == 'S')
                {
                    opMenu++;
                    if (opMenu > 4) opMenu = 1;
                }
                if (tecla == 'z' || tecla == 'Z' || tecla == 13)
                {
                    AnimacionBorrar();
                    opFinal = opMenu;  // saber que opción eligió
                    enCarga = false;
                }
            }
        } while (enCarga);
        switch (opFinal) {
        case 1:
            Tutorialcondicion2 = true;
            do {
                if (yaJugoTutorial == false) { Tutorial(); } // condición para saber si ya jugaste el tutorial
                else { IniciarJuego(); }
                if (Tutorialcondicion2) {
                    jugardenuevo = true;
                    PantallaContinuar();
                }
            } while (jugardenuevo);
            break;
        case 2:
            IniciarTutorial();
            break;
        case 3: 
            IniciarCreditos();
            break;
        case 4:
            enCarga2 = false;
            break;
        }
        //if (jugardenuevo) IniciarJuego(); else enCarga2 = false;
    } while (enCarga2);
    Console::Clear();
    return 0;
}