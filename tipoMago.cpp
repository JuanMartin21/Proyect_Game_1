#include "tipoMago.h"

void cargarMago(TipoMago &TM)
{
    int valor;

    do
    {
        printf("1-Brujo , 2-Hada , 3-Hechicero : ");
        scanf("%d", &valor);
        switch (valor)
        {
        case 1:
            TM = BRUJO;
            break;
        case 2:
            TM = HADA;
            break;
        case 3:
            TM = HECHICERO;
            break;
        default:
            printf("Opcion invalida");
        }

    } while (valor < 1 || valor > 3);
}
void mostrarMago(TipoMago TM)
{
    switch (TM)
    {
    case BRUJO:
        printf("Brujo\n");
        break;
    case HADA:
        printf("Hada\n");
        break;
    case HECHICERO:
        printf("Hechicero\n");
        break;
    }
}
