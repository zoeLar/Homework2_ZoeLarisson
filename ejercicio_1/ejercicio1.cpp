#include "ejercicio1.h"

int reloj::corrije_horas(unsigned int h,string periodo){

    try{
        if(h>11)
            throw runtime_error("Error: horas tiene un valor > 11\n");
    }
    catch(const exception& e){
        cerr<< e.what();
        exit(1);
    }

    return h;
}

reloj::reloj(){
    segundos=0;
    minutos=0;
    horas=0;
    horario="a.m.";
}
//se toma como maximo 12
reloj::reloj(unsigned int h,string periodo){
    h=corrije_horas(h,periodo);

    segundos=0;
    minutos=0;
    horas=h;
    horario=periodo;
}

reloj::reloj(unsigned int h, unsigned int m,string periodo){
    //minutos
    int contador_h=0;
    if(m>59){
        contador_h=m/60;
        m=m%60;
    }
    //horas
    h+=contador_h;
    h=corrije_horas(h,periodo);

    segundos=0;
    minutos=m;
    horas=h;
    horario=periodo;
}

reloj::reloj(unsigned int h, unsigned int m, unsigned int s,string periodo){
    //segundos
    int contador_m=0;
    if(s>59){
        contador_m=s/60;
        s=s%60;
    }
    //minutos
    int contador_h=0;
    m+=contador_m;
    if(m>59){
        contador_h=m/60;
        m=m%60;
    }
    //horas
    h+=contador_h;

    h=corrije_horas(h,periodo);

    segundos=s;
    minutos=m;
    horas=h;
    horario=periodo;
}

void reloj::cambiar_seg(unsigned int s){
    int contador_m=0, m=minutos, h=horas;
    if(s>59){
        contador_m=s/60;
        s=s%60;
    }
    //minutos
    m+=contador_m;
    int contador_h=0;
    if(m>59){
        contador_h=m/60;
        m=m%60;
    }
    //horas
    h+=contador_h;
    h=corrije_horas(h,horario);

    horas=h;
    minutos=m;
    segundos=s;
}

void reloj::cambiar_min(unsigned int m){
    int h=horas;
    int contador_h=0;

    if(m>59){
        contador_h=m/60;
        m=m%60;
    }
    
    //horas
    h+=contador_h;
    h=corrije_horas(h,horario);

    horas=h;
    minutos=m;
}

void reloj::cambiar_hora(unsigned int h){

    h=corrije_horas(h,horario);

    horas=h;
}

void reloj::cambiar_periodo(string periodo){
    horario=periodo;
}

void reloj::imprimir_horario(unsigned int tipo){
    try{
        if (tipo<1 || tipo>6)
            throw runtime_error("Error: valor no esta en [1,5]\n");
    }
    catch(const exception& e){
        cerr << e.what() << '\n';
    }

    switch (tipo){
    case 1:{
        cout << setfill('0') <<setw(2) <<horas<<"h "<<horario<<endl;
        break;
        }
    case 2:
        cout << setfill('0') <<setw(2) <<minutos<<"m"<<endl;
        break;
    case 3:
        cout << setfill('0') <<setw(2) <<segundos<<"s"<<endl;
        break;
    case 4:
        cout <<horario<<endl;
        break;
    case 5:
        cout << setfill('0') <<setw(2) <<horas<<"h, ";
        cout << setfill('0') <<setw(2) <<minutos<<"m, ";
        cout << setfill('0') <<setw(2) <<segundos<<"s ";
        cout <<horario<<endl;
        break;
    case 6:
        if(horario=="p.m.")
            cout << setfill('0') <<setw(2) <<horas+12<<"h"<<endl;
        else
            cout << setfill('0') <<setw(2) <<horas<<"h"<<endl;
    }
}

int error(int a, int b){
    int correcto=1;
    int res=-1;
    while(correcto){
        
        cout<<"Error: los datos son erroneos, quiere volver a intentarlo?: [si≠0] [no=0] "<<endl;
        cin>>correcto;
        cin.ignore();

        if(!correcto)
            break;
        
        cout<<"Ingrese los datos correctamente"<<endl;
        cin>>res;
        //este caso significa que ha fallado 
        if(res<a || res>b)
            continue;
        //Si el dato es correcto se devuelve
        correcto=false;
    }
    return res; 
}



