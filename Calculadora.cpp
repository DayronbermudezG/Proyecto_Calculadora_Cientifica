/***********************************
 * Proyecto calculadora científica *
 *        Desarrolladores:         *
 *                                 *
 * DayronBG                        *
 * Canelo                          *
 ***********************************/

#include <iostream>
#include <string>
#include <windows.h>
#include <conio.h>
#include "lib_dbg/paint.h"
#include "lib_dbg/calc.h"


void command(std::string comando);
void pause();
void wSize(int _x, int _y);
void OcultarCursor();
void mostrarMensaje();
void mostrarMensajeInicio();
void mostrarMenu(int opcion);

////////////////////////////////////////////////// COMIENZO DEL MAIN
int main() {

    std::string blanco       = "70";
    std::string negro        = "07";
    std::string azul         = "17";
    std::string verde        = "27";
    std::string aguamarina   = "37";
    std::string rojo         = "47";
    std::string purpura      = "57";
    std::string amarillo     = "67";
    std::string gris         = "87";
    std::string azul_c       = "97";
    std::string verde_c      = "a7";
    std::string aguamarina_c = "b7";
    std::string rojo_c       = "c7";
    std::string purpura_c    = "d7";
    std::string amarillo_c   = "e7";

    float num1;
    float num2;
    bool salir_mensaje = false;

    wSize(86, 30);
    pintarFondo(azul);
    
    int opcion = 1;
    SetConsoleOutputCP(CP_UTF8); // Esto es para poner la codificacion del programa en utf-8 y asi poder mostrar este mensaje de bienvenida.
    
    do {

        mostrarMensajeInicio();
        Sleep(1000);

        char tecla = _getch();
        if (tecla == 'f') salir_mensaje = true;

    } while (!salir_mensaje);
    
    
    mostrarMenu(opcion);

    bool elegir = false;

    do {
        char tecla = _getch(); // Leer una tecla sin esperar por Enter

        if (tecla == 80) { // Tecla de flecha abajo (ASCII 80)
            opcion++;
            if (opcion > 4) {
                opcion = 1;
            }
            mostrarMenu(opcion);
        }
        else if (tecla == 72) { // Tecla de flecha arriba (ASCII 72)
            opcion--;
            if (opcion < 1) {
                opcion = 4;
            }
            mostrarMenu(opcion);
        }
        else if (tecla == 'f') elegir = true;
    } while (!elegir);

    if (opcion == 1) { // Sumar

        mostrarMensaje();
        std::cout << "     ________________________________Suma________________________________________" << std::endl;
        std::cout << std::endl;

        std::cout << "     Número 1: "; std::cin >> num1;
        std::cout << "     Número 2: "; std::cin >> num2;
        std::cout << "\n     " << num1 << " + " << num2 << " = " << Sumar(num1, num2) << std::endl;
        pause();
    }
    else if (opcion == 2) { // Restar
        mostrarMensaje();
        std::cout << "     ________________________________Resta_______________________________________" << std::endl;
        std::cout << std::endl;

        std::cout << "     Número 1: "; std::cin >> num1;
        std::cout << "     Número 2: "; std::cin >> num2;
        std::cout << "\n     " << num1 << " - " << num2 << " = " << Restar(num1, num2) << std::endl;
        pause();
    }
    else if (opcion == 3) { // Multiplicar
        mostrarMensaje();
        std::cout << "     ________________________________Multiplicación______________________________" << std::endl;
        std::cout << std::endl;

        std::cout << "     Número 1: "; std::cin >> num1;
        std::cout << "     Número 2: "; std::cin >> num2;
        std::cout << "\n     " << num1 << " * " << num2 << " = " << Multiplicar(num1, num2) << std::endl;
        pause();
    }
    else if (opcion == 4) { // Dividir
        mostrarMensaje();
        std::cout << "     ________________________________División____________________________________" << std::endl;
        std::cout << std::endl;

        std::cout << "     Número 1: "; std::cin >> num1;
        std::cout << "     Número 2: "; std::cin >> num2;
        std::cout << "\n     " << num1 << " / " << num2 << " = " << Dividir(num1, num2) << std::endl;
        pause();
    }

    return 0;
}
////////////////////////////////////////////////// FIN DEL MAIN

void command(std::string comando) {

    const char* OutCommand = comando.c_str();
    system(OutCommand);
}

void pause() {
    std::cout << "\n     Para salir puede precionar cualquier tecla, estas utilizando la versión beta\n     del proyecto: Calculadora Científica.\n";
    system("pause>nul");
}

void wSize(int _x, int _y) {

    std::string x = std::to_string(_x);
    std::string y = std::to_string(_y);
    std::string comando = "mode " + x + "," + y;
    const char* comando_tamano = comando.c_str();
    system(comando_tamano);
}

void OcultarCursor() { // Función para ocultar el cursor

    HANDLE hCon;
    hCon = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_CURSOR_INFO cci;
    cci.dwSize = 50; // Especifica el alto del cursor
    cci.bVisible = FALSE; // Si es falso el cursor no sera visible

    SetConsoleCursorInfo(hCon, &cci);
}

void mostrarMensaje() {

    OcultarCursor();

    system("cls");

    std::cout << std::endl;
    std::cout << "       ██╗██╗ ██╗ ██╗       ██████╗ █████╗ ██╗      ██████╗      ██╗ ██╗ ██╗██╗  " << std::endl;
    std::cout << "      ██╔╝╚██╗╚██╗╚██╗     ██╔════╝██╔══██╗██║     ██╔════╝     ██╔╝██╔╝██╔╝╚██╗ " << std::endl;
    std::cout << "     ██╔╝  ╚██╗╚██╗╚██╗    ██║     ███████║██║     ██║         ██╔╝██╔╝██╔╝  ╚██╗" << std::endl;
    std::cout << "     ╚██╗  ██╔╝██╔╝██╔╝    ██║     ██╔══██║██║     ██║         ╚██╗╚██╗╚██╗  ██╔╝" << std::endl;
    std::cout << "      ╚██╗██╔╝██╔╝██╔╝     ╚██████╗██║  ██║███████╗╚██████╗     ╚██╗╚██╗╚██╗██╔╝ " << std::endl;
    std::cout << "       ╚═╝╚═╝ ╚═╝ ╚═╝       ╚═════╝╚═╝  ╚═╝╚══════╝ ╚═════╝      ╚═╝ ╚═╝ ╚═╝╚═╝  " << std::endl;
    std::cout << "                                  Hecho por DayronBG                             " << std::endl;
    std::cout << std::endl;
}

void mostrarMensajeInicio() {

    OcultarCursor();

    system("cls");

    std::cout << std::endl;
    std::cout << "       ██╗██╗ ██╗ ██╗       ██████╗ █████╗ ██╗      ██████╗      ██╗ ██╗ ██╗██╗  " << std::endl;
    std::cout << "      ██╔╝╚██╗╚██╗╚██╗     ██╔════╝██╔══██╗██║     ██╔════╝     ██╔╝██╔╝██╔╝╚██╗ " << std::endl;
    std::cout << "     ██╔╝  ╚██╗╚██╗╚██╗    ██║     ███████║██║     ██║         ██╔╝██╔╝██╔╝  ╚██╗" << std::endl;
    std::cout << "     ╚██╗  ██╔╝██╔╝██╔╝    ██║     ██╔══██║██║     ██║         ╚██╗╚██╗╚██╗  ██╔╝" << std::endl;
    std::cout << "      ╚██╗██╔╝██╔╝██╔╝     ╚██████╗██║  ██║███████╗╚██████╗     ╚██╗╚██╗╚██╗██╔╝ " << std::endl;
    std::cout << "       ╚═╝╚═╝ ╚═╝ ╚═╝       ╚═════╝╚═╝  ╚═╝╚══════╝ ╚═════╝      ╚═╝ ╚═╝ ╚═╝╚═╝  " << std::endl;
    std::cout << "                                  Hecho por DayronBG                             " << std::endl;
    std::cout << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl;

    std::cout << "                           _________________________________                     " << std::endl;
    std::cout << "                          |                                 |                    " << std::endl;
    std::cout << "                          |       INICIAR CALCULADORA       |                    " << std::endl;
    std::cout << "                          |          Precionar[f]           |                    " << std::endl;
    std::cout << "                          |_________________________________|                    " << std::endl;
}

void mostrarMenu(int opcion) {

    OcultarCursor();
    system("cls");

    std::cout << std::endl;
    std::cout << "       ██╗██╗ ██╗ ██╗       ██████╗ █████╗ ██╗      ██████╗      ██╗ ██╗ ██╗██╗  " << std::endl;
    std::cout << "      ██╔╝╚██╗╚██╗╚██╗     ██╔════╝██╔══██╗██║     ██╔════╝     ██╔╝██╔╝██╔╝╚██╗ " << std::endl;
    std::cout << "     ██╔╝  ╚██╗╚██╗╚██╗    ██║     ███████║██║     ██║         ██╔╝██╔╝██╔╝  ╚██╗" << std::endl;
    std::cout << "     ╚██╗  ██╔╝██╔╝██╔╝    ██║     ██╔══██║██║     ██║         ╚██╗╚██╗╚██╗  ██╔╝" << std::endl;
    std::cout << "      ╚██╗██╔╝██╔╝██╔╝     ╚██████╗██║  ██║███████╗╚██████╗     ╚██╗╚██╗╚██╗██╔╝ " << std::endl;
    std::cout << "       ╚═╝╚═╝ ╚═╝ ╚═╝       ╚═════╝╚═╝  ╚═╝╚══════╝ ╚═════╝      ╚═╝ ╚═╝ ╚═╝╚═╝  " << std::endl;
    std::cout << "                                  Hecho por DayronBG                             " << std::endl;
    std::cout << std::endl;

    std::cout << "     ________________________________Operación___________________________________" << std::endl;
    std::cout << std::endl;

    if (opcion == 1) {
        std::cout << "                                   > Sumar       <                               " << std::endl;
    }
    else {
        std::cout << "                                     Sumar                                       " << std::endl;
    }

    if (opcion == 2) {
        std::cout << "                                   > Restar      <                               " << std::endl;
    }
    else {
        std::cout << "                                     Restar                                      " << std::endl;
    }

    if (opcion == 3) {
        std::cout << "                                   > Multiplicar <                               " << std::endl;
    }
    else {
        std::cout << "                                     Multiplicar                                 " << std::endl;
    }
    if (opcion == 4) {
        std::cout << "                                   > Dividir     <                               " << std::endl;
    }
    else {
        std::cout << "                                     Dividir                                     " << std::endl;
    }
    std::cout << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl;
    std::cout << "     Salir[s]     Seleccionar[f]                              Arriba[▲]  Abajo[▼]";
    std::cout << "          Opción salir no disponible.                                            ";
}