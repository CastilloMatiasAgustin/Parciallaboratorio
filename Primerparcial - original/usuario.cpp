#include <iostream>
using namespace std;
#include <cstdlib>
#include <cstdio>
#include "Usuario.h"

///Prototipos

bool altapersona ();
bool modificarpersona ();
void listarusuarioID();
void listarpersonas ();
bool bajausuario ();

void mostrarpersona(persona);
persona cargar_persona ();
bool guardarpersona ();
int buscarID (int ID);
persona leerregistrousuario(int pos);
bool escriturasobreusuariobaja (persona reg, int pos);
bool modificarpersona ();
bool guardarusuario(persona reg,int pos);

///Fin Prototipos


persona cargar_persona ()
{
    persona reg;

    system ("cls");
    /// validacion ID
    cout<< "Ingrese el Id del usuario: "<<endl;
    cin>>reg.ID;
    while (!(reg.ID >=0))
    {
        cout<< "> Ingrese el Id del usuario: "<<endl;
        cin>>reg.ID;
    }
    /// validacion apellidos y nombres
    cout<< "Ingrese Apellidos : "<<endl;
    fflush(stdin);
    cin.getline(reg.apellidos,50);
    while (reg.apellidos [0] == 00 || reg.apellidos [0] == 32)
    {
        cout<< " > Ingrese apellidos : " <<endl;
        cin.getline(reg.apellidos,50);
    }
    fflush(stdin);
    cout<< "Ingrese Nombres : "<<endl;
    fflush(stdin);
    cin.getline (reg.nombre,50);
    while (reg.nombre[0]== 00 || reg.nombre[0]== 32)
    {
        cout<< "> Ingrese nombre : "<<endl;
        cin.getline (reg.nombre,50);
    }
    fflush(stdin);
    /// validacion fecha de nacimiento
    fechactual act;
    act = hoy();
    cout<< "Ingrese la fecha de nacimiento : " <<endl;
    cout<< "Dia : "<<endl;
    cin>>reg.fecha.dia;
    while (!(reg.fecha.dia <= 31))
    {
        cout<< ">Ingrese la fecha de nacimiento : " <<endl;
        cout<< "Dia : "<<endl;
        cin>>reg.fecha.dia;
    }
    cout<< "Mes : "<<endl;
    cin>>reg.fecha.mes;
    while (!(reg.fecha.mes <= 12))
    {
        cout<< ">Mes : "<<endl;
        cin>>reg.fecha.mes;
    }
    cout<< "Año : "<<endl;
    cin>>reg.fecha.anio;
    while (!(reg.fecha.anio <= 2007))
    {
        cout<< ">Año : "<<endl;
        cin>>reg.fecha.anio;
    }
    ///Validacion Altura
    cout<< "Ingrese la altura : " <<endl;
    cin>>reg.altura;
    while (!(reg.altura>=0))
    {
        cout<< "> Ingrese la altura : " <<endl;
        cin>>reg.altura;
    }
    ///Validacion peso
    cout<< "Ingrese el peso (kg) : " <<endl;
    cin>>reg.kg;
    while (!(reg.kg>=0))
    {
        cout<< "> Ingrese el peso (kg) : " <<endl;
        cin>>reg.kg;
    }
    ///Validacion Perfil de Actividad
    cout<< "Ingrese el perfil de actividad 'a', 'b' o 'c' : " <<endl;
    cin>>reg.Perfilactividad;
    while(reg.Perfilactividad!= 'a' && reg.Perfilactividad !='A' &&
            reg.Perfilactividad!= 'b' && reg.Perfilactividad !='B' &&
            reg.Perfilactividad!= 'c' && reg.Perfilactividad !='C')
    {
        cout<< "> Ingrese el perfil de actividad : " <<endl;
        cin>>reg.Perfilactividad;
    }
    /// Validacion Apto Medico
    int apto;
    cout<< "Ingrese el apto medico : "<<endl;
    cin>>apto;
    while (!(apto==1 || apto==0))
    {
        cout<< ">Ingrese el apto medico : "<<endl;
        cin>>apto;
    }
    if (apto==1)
    {
        reg.aptomedico=true;
    }
    else
    {
        reg.aptomedico=false;
    }

    /// Estado por defecto en true

    reg.estado=true;

    cin.get();

    return reg;
}

void mostrarpersona (persona reg)
{
    if (reg.estado==true)
    {
        cout<< "Id del Usuario : ";
        cout<< reg.ID<<endl;
        cout<< "Apellidos: ";
        cout<< reg.apellidos<<endl;
        cout<< "Nombres: ";
        cout<< reg.nombre<<endl;
        cout<< "Fecha de nacimiento : "<<endl;
        cout<< reg.fecha.dia<< "/"<<reg.fecha.mes<< "/"<<reg.fecha.anio<<endl;
        cout<< "Altura : ";
        cout<< reg.altura<<endl;
        cout<< "Kilogramos : ";
        cout<<reg.kg<<endl;
        cout << "Perfil de actividad: ";
        cout<< reg.Perfilactividad<<endl;
        cout<< "Apto medico:  ";
        cout<<reg.aptomedico<<endl;
    }
}

bool guardarpersona (persona reg)
{
    bool graba;
    FILE *p;
    p=fopen("personas.dat", "ab");
    if (p==NULL)
    {
        cout<< "ERROR DE ARCHIVO"<<endl;
        return false;
    }
    graba=fwrite(&reg, sizeof (persona),1, p);
    fclose(p);
    return graba;
}

bool altapersona ()
{
    int pos;
    bool grabo;
    persona reg;

    reg=cargar_persona();
    pos= buscarID(reg.ID);
    if (pos!=-1)
    {
        cout<< "El ID Ingresado ya existe "<<endl;
        return false;
    }
    grabo=guardarpersona(reg);
    return grabo;
}
void listarusuarioID() {
persona reg;
int IDusuario,pos;
bool grabo;
FILE *p;
system ("cls");
cout<<"Ingrese el id del usuario al cual quiere buscar: "<<endl;
cin>>IDusuario;
p=fopen("personas.dat","rb");
if (p==NULL){
    cout<< "Hubo un error con el usuario a encontrar "<<endl;
}
pos=buscarID (IDusuario);
fseek(p,sizeof reg*pos,0);
fread(&reg,sizeof reg,1,p);
mostrarpersona(reg);
cin.get();
fclose(p);
}

    int buscarID (int identificacion)
    {
        FILE *p;
        persona reg;
        int pos=0;
        p=fopen("personas.dat", "rb");
        if (p==NULL)
        {
            cout<< "Hubo un error con el archivo "<<endl;
            return -1;
        }
        while (fread (&reg, sizeof (persona), 1, p)==1)
        {
            if (reg.ID==identificacion)
            {
                fclose (p);
                return pos;
            }
            pos++;
        }
        fclose (p);
        return -1;

    }

    void listarpersonas ()
    {
        system ("cls");
        FILE *p;
        persona reg;
        p=fopen("personas.dat","rb");
        if (p==NULL)
        {
            return;
        }
        cout<< "Listado de Usuarios : "<<endl;
        while (fread(&reg, sizeof reg,1,p)==1)
        {
            mostrarpersona(reg);
            cout<<endl<<endl;
        }
        cin.get();
        fclose (p);
    }

    bool bajausuario ()
    {
        int identidad, pos;
        persona reg;
        bool baja;
        system ("cls");
        cout<< "Ingrese el ID del usuario al cual desea dar de baja:  ";
        cin>>identidad;
        pos=buscarID(identidad);
        if (pos==-1)
        {
            return false;
        }
        reg=leerregistrousuario(pos);
        mostrarpersona(reg);
        cin.get();
        reg.estado=false;
        baja=escriturasobreusuariobaja (reg, pos);
        return baja;
    }

    persona leerregistrousuario(int pos)
    {
        FILE *p;
        persona reg;
        reg.estado=false;
        p=fopen("personas.dat","rb");
        if (p==NULL)
        {
            return reg;
        }
        fseek(p,sizeof reg*pos,0);
        fread(&reg,sizeof reg, 1, p);
        fclose(p);
        return reg;
    }

    bool escriturasobreusuariobaja (persona reg,int pos)
    {
        bool grabo;
        FILE *p;
        p=fopen("personas.dat","rb+");
        if (p==NULL)
        {
            return false;
        }
        fseek(p,sizeof reg*pos,0);
        grabo=fwrite(&reg,sizeof reg,1,p);
        fclose(p);
        return grabo;
    }
    bool guardarusuario(persona reg,int pos)
    {
        bool graba;
        FILE *p;
        p=fopen("personas.dat", "rb+");
        if (p==NULL)
        {
            cout<< "ERROR DE ARCHIVO"<<endl;
            return false;
        }
        fseek (p, sizeof reg*pos, 0);
        graba=fwrite(&reg, sizeof (persona),1, p);
        fclose(p);
        return graba;

    }

    bool modificarpersona()
    {
        int opcion;
        bool salir=false;
        persona reg;
        int ID, pos;
        system("cls");
        cout << "INGRESAR ID QUE DESEA MODIFICAR: ";
        cin >> ID;
        pos=buscarID(ID);
        if (pos>=0)
        {
            cout << "          ID A MODIFICAR:         " << endl;
            cout << "----------------------------------" << endl;
            reg=leerregistrousuario(pos);
            mostrarpersona(reg);
            cout << endl;
            cout << endl;
            while (!salir)
            {
                cout << "INGRESAR CAMPO QUE DESEA MODIFICAR" << endl;
                cout << "----------------------------------" << endl;
                cout << "1 - PESO                          " << endl;
                cout << "2 - PERFIL DE ACTIVIDAD           " << endl;
                cout << "3 - APTO MEDICO                   " << endl;
                cout << "----------------------------------" << endl;
                cout << endl;
                cout << "--> ";
                cin >> opcion;
                cin.ignore();
                switch (opcion)
                {
                case 1:
                    cout << "INGRESAR NUEVO PESO: ";
                    cin >> reg.kg;
                    while (!(reg.kg>=0))
                    {
                        cout<< "> Reingrese el peso (kg) : " <<endl;
                        cin>>reg.kg;
                    }
                    if (guardarusuario(reg, pos)==true)
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
                    cout << "INGRESAR NUEVO PERFIL DE ACTIVIDAD : ";
                    cin >> reg.Perfilactividad;
                    while(reg.Perfilactividad!= 'a' && reg.Perfilactividad !='A' &&
                            reg.Perfilactividad!= 'b' && reg.Perfilactividad !='B' &&
                            reg.Perfilactividad!= 'c' && reg.Perfilactividad !='C')
                    {
                        cout<< "> Reingrese el perfil de actividad : " <<endl;
                        cin>>reg.Perfilactividad;
                    }
                    if (guardarusuario(reg, pos)==true)
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
                case 3:
                    int apto;
                    cout << "INGRESAR EL NUEVO APTO MEDICO : ";
                    cin>>apto;
                    while (!(apto==1 || apto==0))
                    {
                        cout<< ">Reingrese el apto medico : "<<endl;
                        cin>>apto;
                    }
                    if (apto==1)
                    {
                        reg.aptomedico=true;
                    }
                    else
                    {
                        reg.aptomedico=false;
                    }
                    if (guardarusuario(reg, pos)==true)
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

