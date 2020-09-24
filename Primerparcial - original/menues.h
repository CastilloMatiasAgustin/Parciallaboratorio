#ifndef MENUES_H_INCLUDED
#define MENUES_H_INCLUDED
#include <cstdlib>
#include <cstdio>
#include <iostream>
#include "Usuario.h"
#include "entrenamientos.h"
using namespace std;

void menu1 ()
{
    cout<<"MENU PRINCIPAL"<<endl;
    cout<<"--------------"<< endl;
    cout<<"1) USUARIOS"<< endl;
    cout<<"2) ENTRENAMIENTOS"<< endl;
    cout<<"3) REPORTES"<< endl;
    cout<<"4) CONFIGURACIÓN"<< endl;
    cout<<"----------------------"<< endl;
    cout<<"0) SALIR DEL PROGRAMA"<< endl;
    cout<<"---------------------"<<endl;
    cout<<"Ingrese una opcion: "<<endl;
}

void menu2 ()
{


    bool s=false;
    int op;

    while (!s)
    {
    system ("cls");
    cout << " --------  MENU USUARIOS ---------" << endl;
    cout << " ---------------------------------" << endl;
    cout << " 1) NUEVO USUARIO                 " << endl;
    cout << " 2) MODIFICAR USUARIO             " << endl;
    cout << " 3) LISTAR USUARIO POR ID         " << endl;
    cout << " 4) LISTAR TODOS LOS USUARIOS     " << endl;
    cout << " 5) ELIMINAR USUARIO              " << endl;
    cout << " -------------------------------- " << endl;
    cout << " 0) VOLVER AL MENU PRINCIPAL      " << endl;
        cin>>op;
        switch (op)
        {
         case 1:
            if (altapersona()==true) {
                cout<< "Se ha guardado el usuario con exito "<<endl;
            }
            else {
                cout<< "No se ha podido guardar el usuario "<<endl;
            }
            break;
       case 2:
        modificarpersona();
       break;
       case 3:
        listarusuarioID();
        break;
        case 4:
            listarpersonas();
          break;
        case 5:
            if (bajausuario()==true)
            {
                cout<<endl;
                cout<< "La baja del usuario se ha realizado con exito "<<endl;
            }
            else {
                cout<<endl;
                cout<< "No se ha podido realizar la baja del usuario "<<endl;
            }
            break;
        case 0:
           s=true;
            break;
        }

        cin.get();
    }


}

void menu3 ()
{
    bool s=false;
    int op;

    while (!s) {
            system ("cls");
cout << " --------  MENU USUARIOS ---------" << endl;
cout << " ---------------------------------" << endl;
cout << " 1) NUEVO ENTRENAMIENTO           " << endl;
cout << " 2) MODIFICAR ENTRENAMIENTO       " << endl;
cout << " 3) LISTAR ENTRENAMIENTO POR ID   " << endl;
cout << " 4) LISTAR ENTRENAMIENTOS POR USUARIO     " << endl;
cout << " 5) LISTAR TODOS LOS ENTRENAMIENTOS       " << endl;
cout << " -------------------------------- " << endl;
cout << " 0) VOLVER AL MENU PRINCIPAL      " << endl;
cin>>op;
        switch (op) {
     case 1 :
         entrenamientos reg;
         reg=nuevoentrenamiento();
         if (guardarentrenamiento(reg)==true)
         {
             cout<< "El entrenamiento se ha guardado con exito "<<endl;
         }
         else {
             cout<< "No se ha podido guardar el entrenamiento "<<endl;
              }
        break;
     case 2:
         modificarentrenamiento ();
        break;
     case 3:
        break;
     case 4:
        break;
     case 5:
        break;
     case 0:
        s=true;
        break;




        }



}

}


#endif // MENUES_H_INCLUDED
