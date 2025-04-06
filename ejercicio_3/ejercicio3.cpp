#include "numero.h"

entero::entero(int numero1, int numero2){
    this->numero1=numero1;
    this->numero2=numero2;
    resultado=0;
}

void entero::suma(){
    resultado=numero1+numero2;
    cout<<"Resultado de la suma: "<< toString()<<endl;
}

void entero::resta(){
    resultado=numero1-numero2;
    cout<<"Resultado de la resta: "<< toString()<<endl;
}

void entero::multiplicacion(){
    resultado=numero1*numero2;
    cout<<"Resultado de la multiplicacion: "<< toString()<<endl;
}

string entero::toString(){
     string numerito=to_string(resultado);
     return numerito;
}

//-------------------------------------------
real::real(double numero1, double numero2){
    this->numero1=numero1;
    this->numero2=numero2;
    resultado=0;
}

void real::suma(){
    resultado=numero1+numero2;
    cout<<"Resultado de la suma: "<< toString()<<endl;
}

void real::resta(){
    resultado=numero1-numero2;
    cout<<"Resultado de la resta: "<< toString()<<endl;
}

void real::multiplicacion(){
    resultado=numero1*numero2;
    cout<<"Resultado de la multiplicacion: "<< toString()<<endl;
}

string real::toString(){
     string numerito=to_string(resultado);
     return numerito;
}

//----------------------------------------------------
complejo::complejo(vector<double> numero1,vector<double> numero2){
    try
    {
        if(numero1.size()!=2 || numero2.size()!=2 ){
            throw runtime_error("ERROR, se ingreso un numero complejo de tamaño incorrecto");
        }
    }
    catch(runtime_error& e)
    {
        std::cerr << e.what() << '\n';
        exit(1);
    }
    
    this->numero1=numero1;
    this->numero2=numero2;
    vector<double> resultado={0,0};
}

void complejo::suma(){
    resultado=vector<double> {numero1[0]+numero2[0],numero1[1]+numero2[1]};
    cout<<"Resultado de la suma: "<< toString()<<endl;
}

void complejo::resta(){
    resultado=vector<double> {numero1[0]-numero2[0],numero1[1]-numero2[1]};
    cout<<"Resultado de la resta: "<< toString()<<endl;
}

void complejo::multiplicacion(){
    resultado=vector<double> {numero1[0]*numero2[0] - numero1[1]*numero2[1] , numero1[0]*numero2[1]+numero1[1]*numero2[0]};
                            // parte realxreal + parte imaginaria*imaginaria*(i^2)||| real_1 * imaginario_2 + imaginario_1 * real_2
    cout<<"Resultado de la multiplicacion: "<< toString()<<endl;
}

string complejo::toString(){
    string res= to_string(resultado[0]) + "+" +  to_string(resultado[1]) + "i";
    return res; 
}

