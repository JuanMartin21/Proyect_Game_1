#include "menuHabilidades.h"

void desplegarMenuHabilidades(int &opcion)
{
  fflush(stdin);
  printf("\n\n **** MENU DE OPCIONES - HABILIDADES ****");
  printf("\n 1 - Registrar Habilidad");
  printf("\n 2 - Mostrar Lista de Habilidades");
  printf("\n 3 - Cantidad de Habilidades por Tipo");
  printf("\n 4 - Cantidad de habilidades entre Fechas X");
  printf("\n 5 - Cantidad de habilidades por CI magica");
  printf("\n 6 - Lista habilidades manifestadas en una Fecha X");
  printf("\n 7 - Ir a Menu Principal");
  printf("\n Ingrese una opcion: ");
  scanf("%d", &opcion);
}
