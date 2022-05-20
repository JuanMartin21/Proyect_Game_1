#include "menu.h"
#include "menuHabilidades.h"
#include "menuSocios.h"
//mostrar menu
void desplegarMenu(int &opcion)
{
    fflush(stdin);
    printf("\n\n **** MENU DE OPCIONES ****");
    printf("\n 1 - Menu de Socios");
    printf("\n 2 - Menu de Habilidades");
    printf("\n 3 - Salir del programa");
    printf("\n Ingrese una opcion: ");
    scanf("%d", &opcion);
}
