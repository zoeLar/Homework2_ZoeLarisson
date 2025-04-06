#include "ejercicio1.h"

int main (){
    string ejercicios[]={"a) Inicializacion sin parametros",
                         "b) Inicializacion con solo la hora",
                         "c) Inicializacion con la hora y los minutos",
                         "d) Inicializacion con la hora, los minutos y los segundos",
                         "e) Incializacion con la hora, los minutos, los segundos y a.m. o p.m. segun corresponda"};
    unsigned int hora, minutos, segundos;
    int formato;
    string formato_f;

    cout << "Utilizando los ejercicios siguientes se puede testear el ejercicio f"<<endl;
    string am="a.m.", pm="p.m.";

    for(int i=0; i<5; i++){
        reloj mireloj;
        cout<< ejercicios[i]<<endl;
        
        if (i>=1){
            cout<< "Ingrese una hora: "<<endl;
            cin >> hora;
            if(hora<0 || hora>11)
                hora=error(0,11);
        }
        if (i>=2){
            cout<<"ingrese los minutos: "<<endl;
            cin >> minutos;
        }
        if (i>=3){
            cout<<"ingrese los segundos: "<<endl;
            cin>> segundos;
        }
        if(i==4){
            cout<< "ingrese si es a.m. o p.m.  [0 = a.m.] [1 = p.m.]: "<<endl;
            cin >> formato;

            if (formato<0 || formato>1){
                formato=error(0,1);
            }

            switch(formato){
                case 0:
                formato_f=am;
                case 1:
                formato_f=pm;
            }
        }
        switch(i){
            case 0:
                mireloj=reloj();
                break;
            case 1:
                mireloj=reloj(hora);
                break;

            case 2:
                mireloj=reloj(hora,minutos);
                break;
            case 3:
                mireloj=reloj(hora,minutos,segundos);
                break;
            case 4:
                mireloj=reloj(hora,minutos,segundos,formato_f);
                break;
        }
        mireloj.imprimir_horario(5);
    }

    reloj nuevoreloj=reloj(11,4,59,"a.m.");
    cout<<endl<<"g) Leer por partes: Se va leer un reloj: 11h 4m 59s a.m."<<endl;

    cout<<endl<<"Solo horas  con a.m. o p.m."<<endl;
    nuevoreloj.imprimir_horario(1);

    cout<<endl<<"Solo minutos"<<endl;
    nuevoreloj.imprimir_horario(2);

    cout<<endl<<"Solo segundos"<<endl;
    nuevoreloj.imprimir_horario(3);

    cout<<endl<<"Solo a.m. o p.m."<<endl;
    nuevoreloj.imprimir_horario(4);

    cout<<endl<< "Todo junto"<<endl;
    nuevoreloj.imprimir_horario(5);

    cout<<endl<<"g) Cambiar por partes"<<endl;
    int continuar=1;

    while(continuar){
        cout<<"reloj actual: "<<endl;
        nuevoreloj.imprimir_horario(5);

        cout<<"Ingrese nueva hora: "<<endl;
        cin >>hora;

        if(hora<0 || hora>11)
            hora=error(0,11);
            
        nuevoreloj.cambiar_hora(hora);
        nuevoreloj.imprimir_horario(5);

        cout<<"Ingrese nuevos minutos: "<<endl;
        cin >>minutos;
        nuevoreloj.cambiar_min(minutos);
        nuevoreloj.imprimir_horario(5);

        cout<<"Ingrese nuevos segundos: "<<endl;
        cin >>segundos;
        nuevoreloj.cambiar_seg(segundos);
        nuevoreloj.imprimir_horario(5);

        cout<< "Cambie si es a.m. o p.m. : [0 = a.m.] [1 = p.m.]";
            cin >> formato;

            if (formato<0 || formato>1){
                formato=error(0,1);
            }

            switch(formato){
                case 0:
                nuevoreloj.cambiar_periodo(am); 
                case 1:
                nuevoreloj.cambiar_periodo(pm); 
            }
               
        

        cout<< "Desea seguir cambiando los datos del reloj? [si≠0] [no=0]"<<endl;
        cin>> continuar;
    }

    
    
    return 0;
}