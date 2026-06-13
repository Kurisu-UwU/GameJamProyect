#include "header1.h GAMEJAM.h"

void IniciarJuego() {
	do {
		DibujarMediaLuna(112, 12);
		DibujarMediaTierra(0, 8);
	} while (1);
}
void IniciarTutorial() {

}

void IniciarCreditos() {
	BorrarYMovernaves();
	DibujarNaves();
}