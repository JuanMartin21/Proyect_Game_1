#include "arbolSociedad.h"
#include "archivo.h"
#include "menu.h"

int main()
{

    int opcion;
    long int CIbusqueda;
    string nomArchHab, nomArchSoc;
    Socio socio, socioMasPoderoso;
    ABB sociedad;
    CrearABB(sociedad);
    Fecha fechaNac, fechaManif, f1, f2;
    Lista habilidades;
    crearLista(habilidades);
    Habilidad hab;
    printf("\nIngrese el nombre del archivo de Habilidades: ");
    strcrear(nomArchHab);
    scanStr(nomArchHab);
    printf("\nIngrese el nombre del archivo de Socios: ");
    strcrear(nomArchSoc);
    scanStr(nomArchSoc);
    Levantar_Lista(habilidades, nomArchHab);
    Levantar_ABB(sociedad, nomArchSoc);

    do
    {
        desplegarMenu(opcion);
        switch (opcion)
        {
        case 1:
            do
            {

                desplegarMenuSocios(opcion);
                switch (opcion)
                {
                case 1:
                    printf("\nRegistrar Mago en Sociedad:\n");
                    cargarSocio(socio);
                    cargarABBSociedad(sociedad, socio);
                    agregarSocioArch(nomArchSoc, socio);
                    break;
                case 2:
                    printf("Lista de Socios (Ordenada por CI de menor a mayor): \n");
                    mostrarABBCompleto(sociedad);
                    break;
                case 3:
                    printf("\nLa sociedad tiene un total de: ");
                    printf("\n* %d Brujos", cantidadBrujos(sociedad));
                    printf("\n* %d Hadas", cantidadHadas(sociedad));
                    printf("\n* %d Hechiceros", cantidadHechiceros(sociedad));
                    break;
                case 4:
                    printf("\nIngrese la fecha que desea consultar: ");
                    cargarFecha(fechaNac);
                    if (validarFecha(fechaNac))
                    {
                        printf("\nLa sociedad tiene un total de %d Magos nacidos antes de ", cantidadDeSociosNacidosAntesDe(sociedad, fechaNac));
                        mostrarFecha(fechaNac);
                        printf("\n");
                    }
                    else
                    {
                        printf("La fecha ingresada no es valida.\n");
                    }
                    break;

                case 5:
                    printf("El socio mas poderoso es:\n ");
                    mostrarSocioMasPoderoso(sociedad, habilidades, socioMasPoderoso);
                    mostrarSocio(socioMasPoderoso);
                    break;
                case 6:
                    printf("Los socios que NO tienen habilidades manifestadas son: \n");
                    mostrarSociosSinHabilidades(sociedad, habilidades);
                    break;
                case 7:
                    printf("Los socios que SI tienen habilidades manifestadas son: \n");
                    mostrarSociosConHabilidades(sociedad, habilidades);
                    break;
                case 8:
                    printf("\n Saliste del Menu Socios \n");
                    break;
                default:
                    printf("\n Opcion invalida, intente nuevamente\n");
                }
            } while (opcion != 8);
            break;
        case 2:
            do
            {
                desplegarMenuHabilidades(opcion);
                switch (opcion)
                {
                case 1:
                    printf("\nAgregar Habilidad a la Lista:\n");
                    fflush(stdin);
                    cargarHabilidad(hab);
                    if (socioPertenece(darCiFantastica(hab), sociedad) == TRUE)
                    {
                        cargarListaHabilidades(habilidades, hab);
                        agregarHabilidadArch(nomArchHab, hab);
                    }
                    else
                    {
                        printf("No existe ningun socio cargado con la CI Fantastica %ld. Vaya al Menu de Socio y cargue uno nuevo", darCiFantastica(hab));
                    }
                    break;
                case 2:
                    printf("Lista de Habilidades en memoria (Ordenada por Fecha de Manifestacion): \n");
                    if (listaVacia(habilidades) == FALSE)
                        mostrarListaHabilidades(habilidades);
                    else
                        printf("La lista en memoria esta vacia. Ingrese nuevas habilidades.\n");
                    break;
                case 3:
                    printf("\nLa lista de habilidades tiene un total de: ");
                    printf("\n* %d Naturales", cantidadNaturales(habilidades));
                    printf("\n* %d Poco Naturales", cantidadPocoNaturales(habilidades));
                    printf("\n* %d Sobrenaturales", cantidadSobrenaturales(habilidades));
                    break;
                case 4:
                    printf("Ingrese la primera fecha de busqueda: ");
                    cargarFecha(f1);
                    printf("Ingrese la segunda fecha de busqueda: ");
                    cargarFecha(f2);
                    while ((primerFechaMayor(f1, f2)) == TRUE)
                    {
                        printf("La segunda fecha no puede ser menor que la primera, ingrese otra: ");
                        cargarFecha(f2);
                    }
                    printf("Se registraron %d habilidades entre esas fechas.\n", cantidadHabilidadesEntreFechas(habilidades, f1, f2));
                    break;
                case 5:
                    printf("Ingrese la CI del Socio que desea buscar: ");
                    scanf("%ld", &CIbusqueda);
                    printf("El socio registra %d habilidades.\n", contarHabilidadesPorCI(habilidades, CIbusqueda));
                    break;
                case 6:
                    printf("Ingrese la fecha de busqueda: ");
                    cargarFecha(fechaManif);
                    printf("Estas son las habilidades que se registran en esa fecha:\n");
                    mostrarListaHabilidadesPorFecha(habilidades, fechaManif);
                    break;
                case 7:
                    printf("\n Saliste del Menu Habilidades \n");
                    break;
                default:
                    printf("\n Opcion invalida, intente nuevamente\n");
                }
            } while (opcion != 7);
            break;

        case 3:
            printf("\n Adios! \n");
            break;
        default:
            printf("\n Opcion invalida, intente nuevamente\n");
        }
    } while (opcion != 3);

    return 0;
}
