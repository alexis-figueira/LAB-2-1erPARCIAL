#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
using namespace std;
#include "rlutil.h"
using namespace rlutil;
#include "Funciones.h"
#include "estructuras.h"
#include "menu.h"
#include "interfaz.h"
#include "reportes.h"
const int tam_formato = 40, alto_formato=25;
const char arch [50]= "ListaUsuarios.dat" ;
const char arch_entrenamiento [50]= "ListaEntrenamientos.dat" ;

void menu_reportes(){
    int m ;
    while (true){
        system ("cls");
        devolucion("REPORTES", "AZUL", tam_formato,alto_formato);
        titulo ("REPORTES",tam_formato);
        guiones (tam_formato);
        msj ("01. REPORTE 1", 2, tam_formato); cout << endl ;
        msj ("02. REPORTE 2", 2, tam_formato); cout << endl ;
        guiones (tam_formato);
        msj ("00. VOLVER AL MENÚ PRINCIPAL", 2 , tam_formato); cout << endl ;
        guiones (tam_formato);
        gotoxy (1, tam_formato/2);
        msj ("INGRESE LA OPCIÓN: ",2 ,tam_formato);
        cin >> m ;
        switch (m){
        case 1:
            float mini, maxi ;

            system ("cls");
            devolucion("REPORTE 1", "AZUL", tam_formato, alto_formato);
            titulo ("REPORTE 1", tam_formato);
            guiones (tam_formato);
            guiones (tam_formato,9);
            gotoxy (1,4) ;
            msj ("INGRESE MÍNIMO DE PESO: ", 2, tam_formato);
            cin >> mini ;
            validar_peso (mini,1);
            cout << endl ;
            msj ("INGRESE MÁXIMO DE PESO: ", 2, tam_formato);
            cin >> maxi ;
            validar_peso (maxi,2);
            cout << endl ;
            reporte1 (maxi, mini);


    anykey ();

            break;
        case 2 :
            system ("cls");
            devolucion ("REPORTE 2", "AZUL", tam_formato, alto_formato);
            titulo("REPORTE 2", tam_formato);
            anykey ();
            break;
        case 0:
            return ;
            break;
        default:
            system ("cls");
            msj ("OPCIÓN INCORRECTA", 2,tam_formato,"ROJO");
            devolucion ("OPCIÓN INCORRECTA", "ROJO", tam_formato, alto_formato);
            anykey ();
            break ;
        }
    }

}

void reporte1 (float maximo , float minimo){ ///A partir del ingreso de un peso mínimo y un peso máximo,
    ///listar el apellido y nombres de todos los usuarios que se encuentren dentro de ese rango.

    system ("cls");
    devolucion ("ENTRE A REPORTE 1", "AZUL", tam_formato, alto_formato);
    anykey ();
    FILE *f ;
    f=fopen(arch,"rb");
    if ( f==NULL){
        cout << "ERROR";
        anykey();
        return ;
    }
    usuario reg ;
    while (fread(&reg,sizeof(usuario),1,f)==1){
        if (reg.peso>=minimo && reg.peso <= maximo){
            mostrar_registro (reg);
        }
    }
    fclose (f);
}

void reporte2 (){


}


float validar_peso (float peso, int opcion){
    while(peso<=0){
        devolucion ("PESO INCORRECTO", "ROJO", tam_formato, alto_formato);
        anykey();
        devolucion("REPORTE 1", "AZUL", tam_formato, alto_formato);
        if (opcion ==1){
        borrar_renglon(4);
        msj ("INGRESE MÍNIMO DE PESO: ", 2, tam_formato-2);
        cin >> peso ;
        }
        else {
            borrar_renglon(6);
            msj ("INGRESE MÁXIMO DE PESO: ", 2, tam_formato-2);
            cin >> peso ;
        }
    }
    return peso ;
}


