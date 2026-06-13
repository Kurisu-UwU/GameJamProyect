#include "header1.h GAMEJAM.h"

void Tutorial() {

}
void IniciarJuego() {
	DibujarNaveGrande2(px, py);
	do {
		DibujarMediaLuna(112, 12);
		DibujarMediaTierra(0, 8);
		Protagonistamover();
		AsteroidesMov();
		_sleep(1);
	} while (1);
}
void IniciarTutorial() {

}
void IniciarCreditos() {
    bool uwu = true;
	do {
		BorrarYMovernaves();
		DibujarFondo();
		DibujarCreditos(24,2);
		Posicion(24, 20); cout << "Creditos etc etc";
		ColorAmarillo(); Posicion(24, 27); cout << "Pulse Z para salir"; ColorBlanco();
		DibujarNaves();
		ColorAmarillo();
        if (kbhit())
        {
            char tecla = getch();
            if (tecla == 'z' || tecla == 'Z' || tecla == 13)
            {
				uwu = false;
            }
        }
	} while (uwu);
	AnimacionBorrar();
}
