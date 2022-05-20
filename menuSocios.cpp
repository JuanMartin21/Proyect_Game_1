#include "menuSocios.h"

//mostrar menu
void desplegarMenuSocios(int &opcion)
{
  fflush(stdin);
  printf("\n\n **** MENU DE OPCIONES - SOCIOS ****");
  printf("\n 1 - Registrar Mago en Sociedad");
  printf("\n 2 - Mostrar Lista de Socios");
  printf("\n 3 - Cantidad de Magos por Categoria");
  printf("\n 4 - Cantidad de socios nacidos antes de una Fecha X");
  printf("\n 5 - Mostrar el Socio mas poderoso");
  printf("\n 6 - Mostrar Socios SIN Habilidades");
  printf("\n 7 - Mostrar Socios CON Habilidades");
  printf("\n 8 - Ir a Menu Principal");
  printf("\n Ingrese una opcion: ");
  scanf("%d", &opcion);
}
