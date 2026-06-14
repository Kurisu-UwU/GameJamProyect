#include "header1.h GAMEJAM.h"

void Tutorial() {

}
void IniciarJuego() {
	PaneldeControl();
	DibujarNaveGrande2(px, py);    
	time_t inicio = time(nullptr);
	time_t tiempopasao = 0;
	do {
		time_t tiempoahora = time(nullptr);
		time_t tiempoIngame = tiempoahora - inicio;
		time_t tiempoRestante = 120 - tiempoIngame;
		DibujarMediaLuna(112, 10);
		DibujarMediaTierra(0, 6);
		Protagonistamover();
		AsteroidesMov();
		AnimacionPanel();
		ColorVerde(); Posicion(50, 28); cout << tiempoRestante << "s  ";
		if (tiempoRestante == 90) velCohete = 2;
		if (tiempoRestante == 60) velCohete = 3;
		if (tiempoRestante == 30) velCohete = 4;
		PoscicionCoheteIzqoDer();
		VelocidadCohete();
		_sleep(1);
		colision();
	} while (1);
}
void IniciarTutorial() {

}
void IniciarCreditos() {
    bool uwu = true;
	do {
		BorrarYMovernaves();  // deivid
		DibujarFondo();
		DibujarCreditos(24,2);
		Posicion(36, 11); cout << "|  [Gracias por jugar Atermis II Expedition]  |";
		Alto(13, 13, 6);
		Alto(55, 13, 6);
		Ancho(13, 14, 21);
		Ancho(13, 19, 21);
		Posicion(15, 15); cout << "Integrantes del equipo:";
		Posicion(15, 16); cout << "- Deivid Piero Sequeiros Lancho";
		Posicion(15, 17); cout << "- Christian Santiago Helldorff Gonzalez";
		Posicion(15, 18); cout << "- Stephen Franklin Spencer Barbaran";
		Alto(58, 13, 4);
		Alto(98, 13, 4);
		Ancho(58, 14, 20);
		Ancho(56, 18, 21);
		Posicion(60, 15); cout << "Docente:";
		Posicion(60, 16); cout << "- Luis Alberto Raymundo Chacaltana";
		ColorAmarillo(); Posicion(24, 27); cout << "Pulse Z para salir"; ColorBlanco();
		DibujarNaves();
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
