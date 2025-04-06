#pragma once 
#include <string>
#include <iostream>
#include <iomanip>
#include <array>
using namespace std;

//consigue el valor correcto de la variable que se quiere modificar
//el valor tiene que estar en el rango [a,b].
//pide reingresar el dato hasta que el usuario lo ingrese correctamente
//o el usuario puede elegir terminar el programa 
int error(int a, int b);

class reloj{
private:
    unsigned int horas;
    unsigned int minutos;
    unsigned int segundos;
    string horario;
    
    int corrije_horas(unsigned int h,string periodo);
public:
    reloj();
    reloj(unsigned int h,string horario="a.m.");
    reloj(unsigned int h, unsigned int m,string horario="a.m.");
    reloj(unsigned int h, unsigned int m, unsigned int s,string horario="a.m.");
    
    void cambiar_seg(unsigned int s);
    void cambiar_min(unsigned int m);
    void cambiar_hora(unsigned int h);
    void cambiar_periodo(string periodo);

    //restringido a un valor entre 1-6 inclusive 
    /*1=Hora con a.m. o p.m.
    2=Minutos,
    3=Segundos
    4=a.m. o p.m. 
    5=Todo junto
    6=En formato 24hs
    */
    void imprimir_horario(unsigned int tipo);

    

};


