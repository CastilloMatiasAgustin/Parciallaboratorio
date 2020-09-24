#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED

struct fechactual
{

    int dia_actual;
    int mes_actual;
    int anio_actual;

};


struct fechadenacimiento
{
    int dia;
    int mes;
    int anio;

};

fechactual hoy();

#endif // FECHA_H_INCLUDED
