#include "fecha.h"

//implementacion subprogramas

//cargar Fecha con validacion
void cargarFecha(Fecha &f)
{

    printf("(DD MM AAAA. Ej.:1 1 1999): ");
    scanf("%d %d %d", &f.dia, &f.mes, &f.anio);
}

boolean validarFecha(Fecha f)
{

    boolean validar = FALSE;
    switch (f.mes)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        if ((f.dia >= 1) && (f.dia <= 31))
            validar = TRUE;
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        if (f.dia >= 1 && f.dia <= 30)
            validar = TRUE;
        break;
    case 2:
        if (f.anio % 4 == 0)
        {
            if (f.dia >= 1 && f.dia <= 29)
                validar = TRUE;
        }
        else
        {
            if (f.dia >= 1 && f.dia <= 28)
                validar = TRUE;
        }
        break;
    }

    return validar;
}
//mostrar Fecha
void mostrarFecha(Fecha f)
{
    printf("%d/%d/%d", f.dia, f.mes, f.anio);
}

boolean fechasIguales(Fecha f1, Fecha f2)
{
    boolean iguales = FALSE;
    if ((f1.anio == f2.anio) && (f1.mes == f2.mes) && (f1.dia == f2.dia))
        iguales = TRUE;
    return iguales;
}

boolean primerFechaMayor(Fecha f1, Fecha f2)
{
    boolean mayor = FALSE;
    if (f1.anio > f2.anio)
        mayor = TRUE;
    else if ((f1.anio == f2.anio) && (f1.mes > f2.mes))
        mayor = TRUE;
    else if ((f1.anio == f2.anio) && (f1.mes == f2.mes) && (f1.dia > f2.dia))
        mayor = TRUE;

    return mayor;
}

//funciones selectoras

int darDia(Fecha f)
{
    return f.dia;
}

int darMes(Fecha f)
{
    return f.mes;
}

int darAnio(Fecha f)
{
    return f.anio;
}
