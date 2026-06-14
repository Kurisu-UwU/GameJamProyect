#include "header1.h GAMEJAM.h"

//iniciar todo el juego Christian
void IniciarJuego() {
	whileiniciarjuego = true; // condicion bucle
	coheteIzqoDer = true;  // condicion poscision cohete
	owo = false;  // condicion orientacion cohete
	vidas +=3;
    if (vidas > 3) vidas = 3;
    personasEnL = 0; personasEnT = 12; personasEnNoC = 0; cicloDePersonas = 2, numeroDePersonas=4;
    px = 100, py = 11;
	PaneldeControl();
	DibujarNaveGrande2(px, py);    
	time_t inicio = time(nullptr); //Guarda el tiempo local en la computadora
	int tiempoaleatorio = rand() % 40 + 80;
	do {
		time_t tiempoahora = time(nullptr); //Guarda el tiempo local en la computadora pero en bucle
		time_t tiempoIngame = tiempoahora - inicio; //Compara la diferencia entre el tiempo registrado del principio con el tiempo registrado en bucle
		tiempoRestante = tiempoaleatorio - tiempoIngame; // la diferencia entre el tiempo aleatorio con la diferencia entre el tiempo de la computadora con la diferencia del tiempo registrado de la computadora al inicio del nivel
		DibujarMediaLuna(112, 10);
		DibujarMediaTierra(0, 6);
        DibujarVariasPersonas(1,3);
		Protagonistamover();
		AsteroidesMov();
		AnimacionPanel();
		ColorVerde(); Posicion(50, 28); cout << tiempoRestante << "s  ";
		PoscicionCoheteIzqoDer();
		AnimacionVelocidad(false);
		AnimacionTextoPanelRescate(false);
        if (vidas == 0) { AnimacionNaveExplota(); whileiniciarjuego = false; AnimacionDerrota(); vidas++; } // no sé que está pasando que al empezar de nuevo empiezas con 2 vidas, asi que hice la sumatoria nada mas
		else colision();
		if (tiempoRestante <= 0) { whileiniciarjuego = false; AnimacionDerrota(); }
        if (personasEnL >= 12) { whileiniciarjuego = false; DibujarVictoria(); }
        _sleep(1);
	} while (whileiniciarjuego);
    vidas++;
	AnimacionBorrar();
}

// Iniciar el Tutorial Stephen
void IniciarTutorial() {
    bool enExplicacion = true;
    bool jugarMiniJuego = false;

    // instrucciones del tutorial ;D
    Console::Clear();
    do {
        DibujarFondo();
        BorrarYMovernaves();

        ColorAzul();
        Posicion(35, 4); cout << "=========================================";
        Posicion(35, 5); cout << "|      TUTORIAL: MISION ARTEMIS II      |";
        Posicion(35, 6); cout << "=========================================";

        ColorVerde();  Posicion(20, 10); cout << "CONTROLES:";
        ColorBlanco(); Posicion(20, 11); cout << "- Usa W A S D para pilotar la nave Orion.";

        ColorVerde();  Posicion(20, 14); cout << "REGLAS DEL JUEGO:";
        ColorBlanco(); Posicion(20, 15); cout << "- Recoge personas en la Tierra (Izquierda) y llevalas a la Luna (Derecha).";
        Posicion(20, 16); cout << "- La nave solo tiene espacio para 2 personas por viaje.";
        Posicion(20, 17); cout << "- Evita los meteoritos (@) o perderas una vida.";

        ColorAmarillo();
        Posicion(35, 21); cout << ">> Presiona 'X' para PROBAR LOS CONTROLES";
        Posicion(35, 23); cout << ">> Presiona 'Z' para REGRESAR AL MENU";
        DibujarNaves();
        if (kbhit()) {
            char tecla = getch();
            if (tecla == 'x' || tecla == 'X') {
                jugarMiniJuego = true;
                enExplicacion = false;
            }
            if (tecla == 'z' || tecla == 'Z' || tecla == 13) {
                enExplicacion = false;
            }
        }
        Tutorialcondicion2 = false;
    } while (enExplicacion);

    if (jugarMiniJuego) {
        AnimacionBorrar();
        DibujarFondo();
        px = 15;
        py = 11;
        owo = true;

        bool miniJuegoCorriendo = true;
        bool objetivoCumplido = false;

        do {
            DibujarMediaLuna(112, 10);

            ColorAmarillo(); Posicion(15, 23); cout << "OBJETIVO ACTUAL: ";
            ColorBlanco();

            if (objetivoCumplido == false) {
                Posicion(32, 23); cout << "Mueve la nave con 'D' hasta la Luna (Derecha).           ";
            }
            else {
                ColorVerde();
                Posicion(32, 23); cout << "¡Controles dominados! Presiona 'Z' para salir al menu.   ";
            }
            //logica para evitar que el jugador pueda salir del mini juego sin cumplir el objetivo
            if (kbhit()) {
                char teclaMini = getch();

                //validar
                if ((teclaMini == 'z' || teclaMini == 'Z' || teclaMini == 13) && objetivoCumplido) {
                    miniJuegoCorriendo = false;
                }

                // movimiento del usuario
                BorrarNaveGrande(px, py);
                WASDmover(teclaMini);
                if (teclaMini == 'd' || teclaMini == 'D') owo = true;
                if (teclaMini == 'a' || teclaMini == 'A') owo = false;
            }
            if (owo) DibujarNaveGrande1(px, py);
            else DibujarNaveGrande2(px, py);

            // condicion de victoria del mini juego
            if (px >= 100) {
                objetivoCumplido = true;
                yaJugoTutorial = true;
            }
            _sleep(40);
        } while (miniJuegoCorriendo);
    }
    AnimacionBorrar();
}

//advertencia del tutorial Stephen
void Tutorial() {
	DibujarFondo();
	ColorAmarillo(); //advertencia para el usuario que no ha jugado el tutorial
	Posicion(40, 11); cout << "=======================================";
	Posicion(40, 12); cout << "|   ADVERTENCIA: NO HAS COMPLETADO    |";
	Posicion(40, 13); cout << "|            EL TUTORIAL              |";
	Posicion(40, 14); cout << "=======================================";
	ColorBlanco();
	Posicion(38, 16); cout << "¿Deseas jugar el tutorial primero? (S/N)";
	char opcionPrevia;
	do {
		opcionPrevia = getch();
	} while (opcionPrevia != 's' && opcionPrevia != 'S' && opcionPrevia != 'n' && opcionPrevia != 'N');
    AnimacionBorrar();
	if (opcionPrevia == 's' || opcionPrevia == 'S') {
		IniciarTutorial();
	}
	else {
		IniciarJuego();
	}	
}

//los créditos deivid
void IniciarCreditos() {
    bool uwu = true;
	do {
		BorrarYMovernaves();  // deivid
		DibujarFondo();
		DibujarCreditos(24,2);
		Posicion(36, 11); cout << "|  [Gracias por jugar Atermis II Expedition]  |";
		Alto(13, 13, 6); Alto(55, 13, 6);
		Ancho(13, 14, 21); Ancho(13, 19, 21);
		Posicion(15, 15); cout << "Integrantes del equipo:";
		Posicion(15, 16); cout << "- Deivid Piero Sequeiros Lancho";
		Posicion(15, 17); cout << "- Christian Santiago Helldorff Gonzalez";
		Posicion(15, 18); cout << "- Stephen Franklin Spencer Barbaran";
		Alto(58, 13, 4); Alto(98, 13, 4);
		Ancho(58, 14, 20); Ancho(56, 18, 21);
		Posicion(60, 15); cout << "Docente:";
		Posicion(60, 16); cout << "- Luis Alberto Raymundo Chacaltana";
		ColorAmarillo(); Posicion(24, 27); cout << "Pulse Z para salir"; ColorBlanco();
		DibujarNaves();
        if (kbhit())
        {
            char tecla = getch();
            if (tecla == 'z' || tecla == 'Z' || tecla == 13) uwu = false;
        }
	} while (uwu);
	AnimacionBorrar();
}
void PantallaContinuar() {
    int opContinuar = 1, opFinalPantalla;
    bool Pantalla;
    do {
        BorrarYMovernaves();
        DibujarLuna();
        DibujarFondo();
        DibujarNaves();
        Posicion(20, 19); cout << "Desea Volver a jugar? Seleccione las opciones con W S";
        Posicion(20, 20);  cout << "Z para confirmar";
        if (opContinuar == 1) { ColorAmarillo(); Posicion(17, 22); cout << ">> "; }
        else { ColorBlanco(); Posicion(17, 22); cout << "   "; }
        Posicion(20, 22); cout << "1. Volver a Jugar    ";
        if (opContinuar == 2) { ColorAmarillo(); ColorAmarillo(); Posicion(17, 24); cout << ">> "; }
        else { ColorBlanco(); Posicion(17, 24); cout << "   "; }
        Posicion(20, 24); cout << "2. Salir al Menu    ";

        if (kbhit()) {
            char tecla2 = _getch();
            if (tecla2 == 'w' || tecla2 == 'W')
            {
                opContinuar--;
                if (opContinuar < 1) opContinuar = 2;
            }
            if (tecla2 == 's' || tecla2 == 'S')
            {
                opContinuar++;
                if (opContinuar > 2) opContinuar = 1;
            }
            if (tecla2 == 'z' || tecla2 == 'Z' || tecla2 == 13)
            {
                AnimacionBorrar();
                opFinalPantalla = opContinuar;
                Pantalla = false;
            }
        }
    } while (Pantalla);
    if (opFinalPantalla == 2) jugardenuevo = false;
    _sleep(100);
}