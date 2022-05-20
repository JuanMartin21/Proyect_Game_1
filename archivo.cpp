#include "archivo.h"

void agregarSocioArch(string nomArch, Socio s)
{
    FILE *f = fopen(nomArch, "ab");
    Bajar_Socio(s, f);
    fclose(f);
}

void agregarHabilidadArch(string nomArch, Habilidad h)
{
    FILE *f = fopen(nomArch, "ab");
    bajar_habilidad(h, f);
    fclose(f);
}

void desplegarSocioArch(string nomArch)
{
    FILE *f = fopen(nomArch, "rb");
    Socio buffer;
    Levantar_Socio(buffer, f);
    while (!feof(f))
    {
        mostrarSocio(buffer);
        Levantar_Socio(buffer, f);
    }
    fclose(f);
}

void desplegarHabilidadArch(string nomArch)
{
    FILE *f = fopen(nomArch, "rb");
    Habilidad buffer;
    levantarHabilidad(buffer, f);
    while (!feof(f))
    {
        mostrarHabilidad(buffer);
        levantarHabilidad(buffer, f);
    }
    fclose(f);
}
