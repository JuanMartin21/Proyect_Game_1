#include "listaHabilidades.h"

void crearLista(Lista &L)
{
    L = NULL;
}

void InsBackIter(Lista &L, Habilidad h)
{

    Lista auxdos = L;
    Lista aux = new nodoL;
    aux->info = h;

    if (auxdos != NULL)
    {
        while (auxdos->sig != NULL)
        {
            auxdos = auxdos->sig;
        }
        auxdos->sig = aux;
    }
    else
    {
        L = aux;
    }

    aux->sig = NULL;
}

void InsFront(Lista &L, Habilidad h)
{
    Lista aux = new nodoL;
    aux->info = h;
    aux->sig = L;
    L = aux;
}

void cargarListaHabilidades(Lista &L, Habilidad h)
{

    if (L == NULL)
    {
        InsFront(L, h);
    }
    else if (fechasIgualOMayor(L, h) == TRUE)
    {
        InsFront(L, h);
    }
}

boolean fechasIgualOMayor(Lista L, Habilidad hab)
{

    if ((primerFechaMayor(darFechaManifestacion(hab), darFechaManifestacion(L->info)) == TRUE) || (fechasIguales(darFechaManifestacion(hab), darFechaManifestacion(L->info)) == TRUE))
    {
        return TRUE;
    }
    else
    {
        ///esta dando un error al entrar en este ELSE. Nunca entra de hecho.
        return FALSE;
    }
}

//tiene como pre condicion chequear que la lista no este vacia
void mostrarListaHabilidades(Lista L)
{
    while (L != NULL)
    {
        mostrarHabilidad(L->info);
        L = L->sig;
    }
}

boolean listaVacia(Lista L)
{
    boolean es = FALSE;
    if (L == NULL)
        es = TRUE;
    return es;
}

void Bajar_Lista(Lista &L, string nomArch)
{
    FILE *f = fopen(nomArch, "ab");
    while (L != NULL)
    {
        bajar_habilidad(L->info, f);
        L = L->sig;
    }
    fclose(f);
}
void Levantar_Lista(Lista &L, string nomArch)
{
    crearLista(L);
    FILE *f = fopen(nomArch, "rb");
    Habilidad h;
    levantarHabilidad(h, f);
    while (!feof(f))
    {
        InsBackIter(L, h);
        levantarHabilidad(h, f);
    }
    fclose(f);
}

int cantidadNaturales(Lista L)
{
    int habs = 0;
    while (L != NULL)
    {
        if (darTipoHabilidad(L->info) == NATURAL)
        {
            habs++;
            L = L->sig;
        }
        else
        {
            L = L->sig;
        }
    }
    return habs;
}
int cantidadPocoNaturales(Lista L)
{
    int habs = 0;
    while (L != NULL)
    {
        if (darTipoHabilidad(L->info) == POCO_NATURAL)
        {
            habs++;
            L = L->sig;
        }
        else
        {
            L = L->sig;
        }
    }
    return habs;
}
int cantidadSobrenaturales(Lista L)
{
    int habs = 0;
    while (L != NULL)
    {
        if (darTipoHabilidad(L->info) == SOBRENATURAL)
        {
            habs++;
            L = L->sig;
        }
        else
        {
            L = L->sig;
        }
    }
    return habs;
}

int cantidadHabilidadesEntreFechas(Lista L, Fecha f1, Fecha f2)
{
    int habs = 0;
    while (L != NULL)
    {
        if (primerFechaMayor(darFechaManifestacion(L->info), f1) == TRUE && primerFechaMayor(f2, darFechaManifestacion(L->info)) == TRUE)
        {
            habs++;
            L = L->sig;
        }
        else
        {
            L = L->sig;
        }
    }
    return habs;
}

int contarHabilidadesPorCI(Lista L, long int ci)
{
    int habs = 0;
    while (L != NULL)
    {
        if (darCiFantastica(L->info) == ci)
        {
            habs++;
            L = L->sig;
        }
        else
        {
            L = L->sig;
        }
    }
    return habs;
}

void mostrarListaHabilidadesPorFecha(Lista L, Fecha f)
{

    while (L != NULL)
    {
        if (fechasIguales(darFechaManifestacion(L->info), f) == TRUE)
        {
            mostrarHabilidad(L->info);
            L = L->sig;
        }
        else
        {
            L = L->sig;
        }
    }
}
