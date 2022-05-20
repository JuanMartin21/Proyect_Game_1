#ifndef LISTA_HABILIDADES_H
#define LISTA_HABILIDADES_H
#include "habilidad.h"

typedef struct nodoL
{
    Habilidad info;
    nodoL *sig;
} nodoL;
typedef nodoL *Lista;

void crearLista(Lista &L);

//agrega la habilidad al final
void InsBackIter(Lista &L, Habilidad h);

//agrega la habildiad al principio
void InsFront(Lista &L, Habilidad h);

//carga lista en orden de fecha de Mayor a Menor
void cargarListaHabilidades(Lista &L, Habilidad h);

boolean fechasIgualOMayor(Lista L, Habilidad hab);

void mostrarListaHabilidades(Lista L);

boolean listaVacia(Lista L);

void Bajar_Lista(Lista L, string nomArch);

void Levantar_Lista(Lista &L, string nomArch);

int cantidadNaturales(Lista L);
int cantidadPocoNaturales(Lista L);
int cantidadSobrenaturales(Lista L);

/// verificar si f1>f2
int cantidadHabilidadesEntreFechas(Lista L, Fecha f1, Fecha f2);

int contarHabilidadesPorCI(Lista L, long int ci);

void mostrarListaHabilidadesPorFecha(Lista L, Fecha f);

#endif
