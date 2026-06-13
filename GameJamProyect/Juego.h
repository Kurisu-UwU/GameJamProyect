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
		Posicion(39, 11); cout << "|  [Gracias por jugar Atermis II Expedition]  |";
		Alto(13, 13, 6);
		Alto(53, 13, 6);
		Ancho(13, 14, 20);
		Ancho(13, 19, 20);
		Posicion(15, 15); cout << "Integrantes del equipo";
		Posicion(15, 16); cout << "- Deivid Piero Sequeiros Lancho";
		Posicion(15, 17); cout << "- Christian Helldorff";
		Posicion(15, 18); cout << "- Stephen Espencer";
		Alto(58, 13, 4);
		Alto(98, 13, 4);
		Ancho(58, 14, 20);
		Ancho(56, 18, 21);
		Posicion(60, 15); cout << "Docente:";
		Posicion(60, 16); cout << "Luis Alberto Raymundo Chacaltana";
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
