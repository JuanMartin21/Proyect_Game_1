#include "tipoHabilidad.h"

void cargaTipoHabilidad(TipoHabilidad &TH)
{
    int valor;

    do
    {
        printf(" 1-Natural , 2-Poco Natural , 3-Sobrenatural : ");
        scanf("%d", &valor);
        switch (valor)
        {
        case 1:
            TH = NATURAL;
            break;
        case 2:
            TH = POCO_NATURAL;
            break;
        case 3:
            TH = SOBRENATURAL;
            break;
        default:
            printf("Opcion invalida");
        }

    } while (valor < 1 || valor > 3);
}
void mostrarTipoHabilidad(TipoHabilidad TH)
{
    switch (TH)
    {
    case NATURAL:
        printf("Natural");
        break;
    case POCO_NATURAL:
        printf("Poco Natural ");
        break;
    case SOBRENATURAL:
        printf("Sobrenatural");
        break;
    }
}
