#ifndef ARBOL_SOCIEDAD_H
#define ARBOL_SOCIEDAD_H

#include "socio.h"
#include "listaHabilidades.h"

typedef struct nodoA
{
   Socio info;
   nodoA *hizq;
   nodoA *hder;
} nodoA;
typedef nodoA *ABB;

void CrearABB(ABB &a);
void cargarABBSociedad(ABB &a, Socio s);

/// mostrar socios en ORDEN Y datos (CI, nombre, fecha nacimiento, dimension y categoria)de cada socio en una sola linea
void mostrarABBCompleto(ABB a);

void darSocio(ABB a, Socio &s, long int ci);

//determina si el socio esta ingresado en el ABB o no
boolean socioPertenece(long int ci, ABB a);

///mostrar socios en ORDEN Y datos (CI, nombre, fecha nacimiento, dimension y categoria)de cada socio en una sola linea
void mostrarSociosConHabilidades(ABB a, Lista L);

///mostrar socios en ORDEN Y datos (CI, nombre, fecha nacimiento, dimension y categoria)de cada socio en una sola linea
void mostrarSociosSinHabilidades(ABB a, Lista L);

int cantidadBrujos(ABB a);
int cantidadHadas(ABB a);
int cantidadHechiceros(ABB a);

int cantidadDeSociosNacidosAntesDe(ABB a, Fecha f);

//verificar antes que fecha sea valida

void mostrarSocioMasPoderoso(ABB a, Lista L, Socio &s);
/// si hay varios muestra cualquiera de ellos y si no hay ninguno muestra un mensaje.
///(Tiene que recorrer todo el arbol, llamando al procedimiento que cuenta habilidades por CI de listaHabilidades,
///comparando y guardando el que tenga mayor numero en variable aux.
///Por ultimo levantar ese socio de archivo y desplegarlo)

void Bajar_ABB_aux(ABB a, FILE *f);
void Bajar_ABB(ABB a, string nomArch);
void Levantar_ABB(ABB &a, string nomArch);

#endif
