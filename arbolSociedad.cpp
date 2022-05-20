
#include "arbolSociedad.h"
#include "listaHabilidades.h"

/* crear un árbol vacío */
void CrearABB(ABB &a)
{
  a = NULL;
}

void cargarABBSociedad(ABB &a, Socio s)
{
  if (a == NULL)
  {
    a = new nodoA;
    a->info = s;
    a->hizq = NULL;
    a->hder = NULL;
  }
  else if (s.ci_fantastica < a->info.ci_fantastica)
    cargarABBSociedad(a->hizq, s);

  else
    cargarABBSociedad(a->hder, s);
}

/// mostrar socios en ORDEN Y datos (CI, nombre, fecha nacimiento, dimension y categoria)de cada socio en una sola linea
void mostrarABBCompleto(ABB a)
{
  if (a != NULL)
  {
    mostrarABBCompleto(a->hizq);
    mostrarSocio(a->info);
    mostrarABBCompleto(a->hder);
  }
}

boolean socioPertenece(long int ci, ABB a)
{
  if (a == NULL)
    return FALSE;
  else if (darCIFantasticaSocio(a->info) == ci)
    return TRUE;
  else if (ci < darCIFantasticaSocio(a->info))
    return socioPertenece(ci, a->hizq);
  else
    return socioPertenece(ci, a->hder);
}

int cantidadBrujos(ABB a)
{
  if (a == NULL)
    return 0;
  else if (darTipoMago(a->info) == BRUJO)
    return 1 + cantidadBrujos(a->hizq) + cantidadBrujos(a->hder);
  else
    return cantidadBrujos(a->hizq) + cantidadBrujos(a->hder);
}

int cantidadHadas(ABB a)
{
  if (a == NULL)
    return 0;
  else if (darTipoMago(a->info) == HADA)
    return 1 + cantidadHadas(a->hizq) + cantidadHadas(a->hder);
  else
    return cantidadHadas(a->hizq) + cantidadHadas(a->hder);
}

int cantidadHechiceros(ABB a)
{
  if (a == NULL)
    return 0;
  else if (darTipoMago(a->info) == HECHICERO)
    return 1 + cantidadHechiceros(a->hizq) + cantidadHechiceros(a->hder);
  else
    return cantidadHechiceros(a->hizq) + cantidadHechiceros(a->hder);
}

//verificar antes que fecha sea valida
int cantidadDeSociosNacidosAntesDe(ABB a, Fecha f)
{

  if (a == NULL)
    return 0;
  else if (primerFechaMayor(f, darFnacimientoSocio(a->info)) == TRUE)
  {
    return 1 + cantidadDeSociosNacidosAntesDe(a->hizq, f) + cantidadDeSociosNacidosAntesDe(a->hder, f);
  }
  else
  {
    return cantidadDeSociosNacidosAntesDe(a->hizq, f) + cantidadDeSociosNacidosAntesDe(a->hder, f);
  }
}

///mostrar socios en ORDEN Y datos (CI, nombre, fecha nacimiento, dimension y categoria)de cada socio en una sola linea
void mostrarSociosConHabilidades(ABB a, Lista L)
{

  if (a != NULL)
  {
    if (contarHabilidadesPorCI(L, darCIFantasticaSocio(a->info)) > 0)
    {
      mostrarSocio(a->info);
    }
    mostrarSociosConHabilidades(a->hizq, L);
    mostrarSociosConHabilidades(a->hder, L);
  }
}

///mostrar socios en ORDEN Y datos (CI, nombre, fecha nacimiento, dimension y categoria)de cada socio en una sola linea
void mostrarSociosSinHabilidades(ABB a, Lista L)
{
  if (a != NULL)
  {
    if (contarHabilidadesPorCI(L, darCIFantasticaSocio(a->info)) == 0)
    {
      mostrarSocio(a->info);
    }
    mostrarSociosSinHabilidades(a->hizq, L);
    mostrarSociosSinHabilidades(a->hder, L);
  }
}

/// si hay varios muestra cualquiera de ellos y si no hay ninguno muestra un mensaje.
///(Tiene que recorrer todo el arbol, llamando al procedimiento que cuenta habilidades por CI de listaHabilidades,
///comparando y guardando el que tenga mayor numero en variable aux.
///Por ultimo levantar ese socio de archivo y desplegarlo)

void mostrarSocioMasPoderoso(ABB a, Lista L, Socio &s)
{
  int cant = 0;
  if (a != NULL)
  {
    if (contarHabilidadesPorCI(L, darCIFantasticaSocio(a->info)) > cant)
    {
      int cantHabilSoc = contarHabilidadesPorCI(L, darCIFantasticaSocio(a->info));
      cant = cantHabilSoc;
      s = a->info;
    }
    mostrarSocioMasPoderoso(a->hizq, L, s);
    mostrarSocioMasPoderoso(a->hder, L, s);
  }
}

void Bajar_ABB_aux(ABB a, FILE *f)
{
  if (a != NULL)
  {
    fwrite(&(a->info), sizeof(int), 1, f);
    Bajar_ABB_aux(a->hizq, f);
    Bajar_ABB_aux(a->hder, f);
  }
}
void Bajar_ABB(ABB a, string nomArch)
{
  FILE *f = fopen(nomArch, "wb");
  Bajar_ABB_aux(a, f);
  fclose(f);
}

void Levantar_ABB(ABB &a, string nomArch)
{
  FILE *f = fopen(nomArch, "rb");
  Socio buffer;
  CrearABB(a);
  Levantar_Socio(buffer, f);
  while (!feof(f))
  {
    cargarABBSociedad(a, buffer);
    Levantar_Socio(buffer, f);
  }
  fclose(f);
}
