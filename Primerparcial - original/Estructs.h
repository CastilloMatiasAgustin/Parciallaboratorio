#ifndef ESTRUCTS_H_INCLUDED
#define ESTRUCTS_H_INCLUDED
#include <cstdlib>
#include <cstdio>
#include <iostream>
#include "menues.h"
#include "Usuario.h"
#include "Estructs.h"


using namespace std;

struct fechadenacimiento
{
    int dia;
    int mes;
    int anio;
};

struct persona
{
    int ID;
    char apellidos [50];
    char nombre [50];
    fechadenacimiento fecha;
    float altura;
    float kg;
    char Perfilactividad;
    bool aptomedico;
    bool estado;
};


#endif // ESTRUCTS_H_INCLUDED
