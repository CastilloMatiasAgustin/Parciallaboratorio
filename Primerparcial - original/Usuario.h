#ifndef ESTRUCTS_H_INCLUDED
#define ESTRUCTS_H_INCLUDED
#include "fecha.h"


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

struct entrenamientos
{
int identificacion;
int IDusuario;
fechactual fecha;
int actividad;
float calorias;
int tiempo;
};

bool altapersona();
void listarpersonas();
bool bajausuario ();
bool modificarpersona();
void listarusuarioID();






#endif // USUARIO_H_INCLUDED
