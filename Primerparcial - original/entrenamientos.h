#ifndef ENTRENAMIENTOS_H_INCLUDED
#define ENTRENAMIENTOS_H_INCLUDED
#include "Usuario.h"
#include <cstdlib>
#include <cstdio>
#include <iostream>
using namespace std;

/// Prototipos
entrenamientos nuevoentrenamiento();
bool guardarentrenamiento ();
int buscarIDentrenamientos(int ID);
entrenamientos leerregistroentrenamientos(int pos);
bool modificarentrenamiento ();
entrenamientos contadoridentificacion(int pos, entrenamientos reg);

/// Fin prototipos

entrenamientos nuevoentrenamiento ()
{
    entrenamientos reg;
    system ("cls");
    int cont=1;
    cout<< "Bienvenido/a! Ingrese sus datos de entrenamiento:  "<<endl;
    cout<< "ID del entrenamiento: "<<endl;
    cout<<reg.identificacion=cont<<endl;
    cout<< "ID del usuario: "<<endl;
    cin>>reg.IDusuario;
    cout<< "Fecha de entrenamiento: "<<endl;
    cout<< "Dia: "<<endl;
    cin>>reg.fecha.dia_actual;
    cout<< "Mes: "<<endl;
    cin>>reg.fecha.mes_actual;
    cout<< "Año: "<<endl;
    cin>>reg.fecha.anio_actual;
    cout<< "Actividad : "<<endl;
    cin>>reg.actividad;
    while (!(reg.actividad>0 && reg.actividad<5))
    {
        cout<< "> Reingrese la actividad por un valor valido: "<<endl;
        cin>>reg.actividad;
    }
    cout<< "Calorias: "<<endl;
    cin>>reg.calorias;
    while (!(reg.calorias>=0))
    {
        cout<< ">Reingrese las calorias por un valor valido: "<<endl;
        cin>>reg.calorias;
    }
    cout<< "Tiempo: "<<endl;
    cin>>reg.tiempo;

    cin.get();

    return reg;

}
void mostrarentrenamiento(entrenamientos reg)
{
    cout<< "ID del entrenamiento: ";
    cout<<reg.identificacion<<endl;
    cout<< "ID del Usuario: ";
    cout<<reg.IDusuario;
    cout<< "Fecha de entrenamiento: ";
    cout<< reg.fecha.dia_actual<< "/"<<reg.fecha.mes_actual<< "/"<<reg.fecha.anio_actual<<endl;
    cout<< "Actividad: ";
    cout<<reg.actividad<<endl;
    cout<< "Calorias: ";
    cout<<reg.calorias<<endl;
    cout<<"Tiempo:";
    cout<<reg.tiempo<<endl;

}
bool guardarusuarioentrenamiento(entrenamientos reg,int pos)
    {
        bool graba;
        FILE *p;
        p=fopen("entrenamientos.dat", "rb+");
        if (p==NULL)
        {
            cout<< "ERROR DE ARCHIVO"<<endl;
            return false;
        }
        fseek (p, sizeof reg*pos, 0);
        graba=fwrite(&reg, sizeof (entrenamientos),1, p);
        fclose(p);
        return graba;

    }
bool guardarentrenamiento (entrenamientos reg)
{
    bool graba;
    FILE *p;
    p=fopen("entrenamientos.dat", "ab");
    if (p==NULL)
    {
        cout<< "ERROR DE ARCHIVO"<<endl;
        return false;
    }
    graba=fwrite(&reg, sizeof (entrenamientos),1, p);
    fclose(p);
    return graba;
}

bool altaentrenamiento ()
{
    int pos;
    bool grabo;
    entrenamientos reg;
    reg=nuevoentrenamiento();
    pos= buscarIDentrenamientos(reg.identificacion);
    if (pos!=-1)
    {
        cout<< "El ID de entrenamientos ingresado ya existe "<<endl;
        return false;
    }

grabo=guardarentrenamiento(reg);

    return grabo;
}
entrenamientos contadoridentificacion(int pos, entrenamientos reg)
{
    FILE *p;
    p=fopen("entrenamientos.dat","rb+");
    if (p==NULL) {
        return reg;
    }
    fseek (p,sizeof reg*pos,0);
    fwrite(&reg,sizeof reg,1,p);
    fclose(p);
    return reg;

}
int buscarIDentrenamientos(int IDentrenamiento)
{
    FILE *p;
    entrenamientos reg;
    int pos=0;
    p=fopen("entrenamientos.dat", "rb");
    if (p==NULL)
    {
        cout<< "Hubo un error con el archivo "<<endl;
        return -1;
    }
    while (fread (&reg, sizeof (entrenamientos), 1, p)==1)
    {
        if (reg.identificacion==IDentrenamiento)
        {
            fclose (p);
            return pos;
        }
        pos++;
    }
    fclose (p);
    return -1;

}

entrenamientos leerregistroentrenamientos (int pos)
{
    FILE *p;
    entrenamientos reg;
    p=fopen("entrenamientos.dat","rb");
    if (p==NULL)
    {
        return reg;
    }
    fseek(p,sizeof reg*pos,0);
    fread(&reg,sizeof reg, 1, p);
    fclose(p);
    return reg;
}

bool modificarentrenamiento ()
{
    entrenamientos reg;
    int opcion;
    bool salir=false;
    int ID, pos;
    system("cls");
    cout << "INGRESAR ID DE ENTRENAMIENTO QUE DESEA MODIFICAR: ";
    cin >> ID;
    pos=buscarIDentrenamientos(ID);
    if (pos!=-1)
    {
        cout << "       ID DE ENTRENAMIENTO A MODIFICAR:         " << endl;
        cout << "------------------------------------------------" << endl;
        reg=leerregistroentrenamientos(pos);
        mostrarentrenamiento(reg);
        cout << endl;
        cout << endl;
        while (!salir)
        {
            cout << "INGRESAR CAMPO QUE DESEA MODIFICAR" << endl;
            cout << "----------------------------------" << endl;
            cout << "1 - TIEMPO EN MINUTOS             " << endl;
            cout << "2 - CALORIAS QUEMADAS             " << endl;
            cout << "----------------------------------" << endl;
            cout << endl;
            cout << "--> ";
            cin >> opcion;
            cin.ignore();
            switch (opcion)
            {
            case 1:
                cout << "INGRESAR NUEVO TIEMPO EN MINUTOS: ";
                cin >> reg.tiempo;
                if (guardarusuarioentrenamiento(reg,pos)==true)
                {
                    cout << "GUARDADO CORRECTAMENTE";
                    cin.get();
                    return true;
                }
                else
                {
                    cout << "NO SE GUARDO CORRECTAMENTE";
                    cin.get();
                    return true;
                }
                break;

            case 2:
                cout << "INGRESAR NUEVAS CALORIAS QUEMADAS: ";
                cin >> reg.calorias;
                if (guardarusuarioentrenamiento(reg, pos)==true)
                {
                    cout << "GUARDADO CORRECTAMENTE";
                    cin.get();
                    return true;
                }
                else
                {
                    cout << "NO SE GUARDO CORRECTAMENTE";
                    cin.get();
                    return true;
                }
                break;

            }
            }


            }


            }




#endif // ENTRENAMIENTOS_H_INCLUDED
