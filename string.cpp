#include "string.h"

void strcrear(string &s)
{
    s = new char[1];
    s[0] = '\0';
}
void strdestruir(string &s)
{
    delete[] s;
    strcrear(s);
}
int strlar(string s)
{
    int i = 0;
    while (s[i] != '\0')
        i++;
    return i;
}
void strcop(string &s1, string s2)
{
    int largo = strlar(s2);
    delete[] s1;
    s1 = new char[largo + 1];
    int i = 0;
    while (s2[i] != '\0')
    {
        s1[i] = s2[i];
        i++;
    }
    s1[i] = '\0';
}
void scanStr(string &s)
{

    string aux = new char[MAX];
    int i = 0;
    // comentar la siguiente linea en windows
    fflush(stdin);
    scanf("%c", &aux[i]);
    while ((aux[i] != '\n') && (i < MAX - 1))
    {
        i++;
        scanf("%c", &aux[i]);
    }
    aux[i] = '\0';
    strcop(s, aux);
    strdestruir(aux); /// lo destruimos porque hicimos new
}
void strcon(string &s1, string s2)
{
    string aux = new char[strlar(s1) + strlar(s2) + 1];
    int i = 0, j = 0;
    while (s1[i] != '\0')
    {
        aux[i] = s1[i];
        i++;
    }
    while (s2[j] != '\0')
    {
        aux[i] = s2[j];
        j++;
        i++;
    }
    aux[i] = '\0';
    strdestruir(s1); /// se destruye porque entra por referencia
    s1 = aux;
}
void strswp(string &s1, string &s2)
{
    string aux = s2;
    s2 = s1;
    s1 = aux;
}
void printStr(string s)
{
    int i = 0;
    while (s[i] != '\0')
    {
        printf("%c", s[i]);
        i++;
    }
}

boolean streq(string s1, string s2)
{
    boolean igual = TRUE;
    int i = 0;
    while ((s1[i] != '\0') && (s2[i] != '\0') && igual)
    {
        if (s1[i] != s2[i])
            igual = FALSE;
        i++;
    }
    if ((s1[i] != '\0') || (s2[i] != '\0'))
        igual = FALSE;
    return igual;
}
/// Escribe en el archivo los caracteres del string s (incluido '\0')
/// Precondici�n: El archivo viene abierto para escritura.
void Bajar_String(string s, FILE *f)
{
    int i = 0;
    while (s[i] != '\0')
    {
        fwrite(&s[i], sizeof(char), 1, f);
        i++;
    }
    fwrite(&s[i], sizeof(char), 1, f);
}

/// Lee desde el archivo los caracteres del string s.
/// Precondici�n: El archivo viene abierto para lectura.
void Levantar_String(string &s, FILE *f)
{
    string aux = new char[MAX];

    int i = 0;

    fread(&aux[i], sizeof(char), 1, f);
    while ((aux[i] != '\0'))
    {
        i++;
        fread(&aux[i], sizeof(char), 1, f);
    }
    strcop(s, aux);
    strdestruir(aux); /// lo destruimos porque hicimos new
}
