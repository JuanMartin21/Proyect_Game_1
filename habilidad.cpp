#include "habilidad.h"

void cargarHabilidad(Habilidad &habil)
{
    fflush(stdin);
    printf("Nombre de la habilidad: ");
    strcrear(habil.nombre_habilidad);
    scanStr(habil.nombre_habilidad);
    printf("Cedula fantastica: ");
    scanf("%ld", &habil.ci_fantastica);
    printf("Fecha de manifestacion: ");
    cargarFecha(habil.f_Manifestacion);
    printf("Tipo de habilidad ");
    cargaTipoHabilidad(habil.tipo_habilidad);
}

void mostrarHabilidad(Habilidad habil)
{
    printStr(habil.nombre_habilidad);
    printf(", ");
    printf("CI - %ld", habil.ci_fantastica);
    printf(", ");
    printf("FM - ");
    mostrarFecha(habil.f_Manifestacion);
    printf(", ");
    mostrarTipoHabilidad(habil.tipo_habilidad);
    printf("\n");
}
void darHabilidad(Habilidad habil)
{
    printStr(habil.nombre_habilidad);
    printf(", ");
    printf(" Cedula fantastica No. %ld ", darCiFantastica(habil));
    printf(", ");
    mostrarFecha(habil.f_Manifestacion);
    mostrarTipoHabilidad(habil.tipo_habilidad);
}
void darnombreHabil(Habilidad habil, string &nom)
{
    strcrear(nom);
    strcop(habil.nombre_habilidad, nom);
}
long int darCiFantastica(Habilidad habil)
{
    return habil.ci_fantastica;
}
Fecha darFechaManifestacion(Habilidad habil)
{
    return habil.f_Manifestacion;
}
TipoHabilidad darTipoHabilidad(Habilidad habil)
{
    return habil.tipo_habilidad;
}

void bajar_habilidad(Habilidad habil, FILE *f)
{
    Bajar_String(habil.nombre_habilidad, f);
    fwrite(&habil.ci_fantastica, sizeof(long int), 1, f);
    fwrite(&habil.f_Manifestacion, sizeof(Fecha), 1, f);
    fwrite(&habil.tipo_habilidad, sizeof(int), 1, f);
}

void levantarHabilidad(Habilidad &habil, FILE *f)
{
    strcrear(habil.nombre_habilidad);
    Levantar_String(habil.nombre_habilidad, f);
    fread(&habil.ci_fantastica, sizeof(long int), 1, f);
    fread(&habil.f_Manifestacion, sizeof(Fecha), 1, f);
    fread(&habil.tipo_habilidad, sizeof(int), 1, f);
}
