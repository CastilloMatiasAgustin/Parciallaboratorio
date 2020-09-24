#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include "menues.h"
using namespace std;

int main()
{
    menu1 ();
    int op;
    while (true)
    {
        system ("cls");
        menu1();
        cin>>op;
        cin.ignore();
        switch (op)
        {
        case 1:
            menu2 ();
            break;
        case 2:
            menu3 ();
            break;
        case 3:
            break;
        case 4:
            break;
        case 0:
           return false;
            break;

        }
        cin.get();

    }

    return 0;


}
