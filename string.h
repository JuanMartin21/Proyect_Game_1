#ifndef STRING_H
#define STRING_H
#include "boolean.h"

const int MAX = 80;
typedef char *string;

void strcrear(string &s);
void strdestruir(string &s);
int strlar(string s);
void strcop(string &s1, string s2);
void scanStr(string &s);
void strcon(string &s1, string s2);
void strswp(string &s1, string &s2);
void printStr(string s);
boolean streq(string s1, string s2);

// Precondicion archivo aabierto para escritura.
void Bajar_String(string s, FILE *f);

// Precondicion archivo aabierto para escritura.
void Levantar_String(string &s, FILE *f);

#endif
