#include "Juego.h"

int main()
{
    Console::CursorVisible = false;
    bool enCarga; // condicion para el bucle
    Console::Clear();
    bool enCarga2 = true;
    bool Menucondicioncreditos = true;
    DibujarFondo();
    do {
        do //para mantener el menu en pantalla
        {
            enCarga = true;
            BorrarYMovernaves();

            DibujarLuna();
            DibujarMenu();

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
            _sleep(50);
        } while (enCarga);
        switch (opFinal) {
        case 1:
            IniciarJuego();
            break;
        case 2:
            IniciarTutorial();
        case 3: 
            IniciarCreditos();
        case 4:
            enCarga2 = false;
        }
    } while (enCarga2);
    Console::Clear();
    return 0;
}