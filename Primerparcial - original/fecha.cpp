#include <iostream>
using namespace std;
#include "fecha.h"
#include <ctime>

fechactual hoy () {

time_t t;
t =time(NULL);
struct tm *f;
f = localtime(&t);
fechactual act;
act.anio_actual = f->tm_year + 1900;
act.mes_actual = f->tm_mon + 1;
act.dia_actual = f->tm_mday;
return act;
}
