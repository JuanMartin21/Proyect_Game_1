#include "socio.h"

void cargarSocio(Socio &s)
{
    fflush(stdin);
    printf("Nombre completo: ");
    strcrear(s.nombre_socio);
    scanStr(s.nombre_socio);
    printf("Cedula Fantastica: ");
    scanf("%ld", &s.ci_fantastica);
    strcrear(s.dimension);
    printf("Dimension: ");
    scanStr(s.dimension);
    printf("Fecha de nacimiento: ");
    cargarFecha(s.f_nacimiento);
    printf("Tipo de mago ");
    cargarMago(s.tipo_mago);
}

void mostrarSocio(Socio s)
{
    printStr(s.nombre_socio);
    printf(", ");
    printf("CI - %ld", s.ci_fantastica);
    printf(", ");
    printStr(s.dimension);
    printf(", ");
    printf("FN - ");
    mostrarFecha(s.f_nacimiento);
    printf(", ");
    mostrarMago(s.tipo_mago);
}

void darNombreSocio(Socio s, string &nom)
{
    strcrear(nom);
    strcop(s.nombre_socio, nom);
}

long int darCIFantasticaSocio(Socio s)
{
    return s.ci_fantastica;
}

void darDimensionSocio(Socio s, string &dim)
{
    strcrear(dim);
    strcop(s.dimension, dim);
}

Fecha darFnacimientoSocio(Socio s)
{
    return s.f_nacimiento;
}

TipoMago darTipoMago(Socio s)
{
    return s.tipo_mago;
}

void Bajar_Socio(Socio s, FILE *f)
{
    Bajar_String(s.nombre_socio, f);
    fwrite(&s.ci_fantastica, sizeof(long int), 1, f);
    Bajar_String(s.dimension, f);
    fwrite(&s.f_nacimiento, sizeof(Fecha), 1, f);
    fwrite(&s.tipo_mago, sizeof(int), 1, f);
}
void Levantar_Socio(Socio &s, FILE *f)
{
    strcrear(s.nombre_socio);
    Levantar_String(s.nombre_socio, f);
    fread(&s.ci_fantastica, sizeof(long int), 1, f);
    strcrear(s.dimension);
    Levantar_String(s.dimension, f);
    fread(&s.f_nacimiento, sizeof(Fecha), 1, f);
    fread(&s.tipo_mago, sizeof(int), 1, f);
}
