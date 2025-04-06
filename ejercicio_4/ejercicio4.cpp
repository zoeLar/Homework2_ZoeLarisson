#include "banco.h"

void banco::depositar(double cant){
    balance+=cant;
}

CajaDeAhorro::CajaDeAhorro(string titular,double bal_inicial){
    balance=bal_inicial;
    titularCuenta=titular;
    contador=0;
}
bool CajaDeAhorro::retirar(double cant){
    if((balance-cant)<0){
        cout<<"[ERROR: El proceso ha fallado.No hay suficiente dinero en la caja de ahorro]"<<endl;
        return false;
    }
    balance-=cant;
    return true;
}

void CajaDeAhorro::mostrarInfo(){
    if(contador>=2){
        bool a=retirar(20);
        if(a==false){
            cout<<"[ERROR: NO SE PUEDE MOSTRAR EL ESTADO DE LA CUENTA]"<<endl;
            return;
        }
        
    }
    contador++;
    cout<<"┌-------------------------------------┐"<<endl;
    cout<<" Estado de la cuenta:\n"<<
            " CUENTA DE AHORRO"<<endl<<
            " Titular= "<< titularCuenta << endl<<
            " Balance= "<<fixed<< setprecision(2)<<balance<< " $" <<endl<<
          "└-------------------------------------┘"<<endl;
}

CuentaCorriente::CuentaCorriente( string titular,shared_ptr<CajaDeAhorro> Caja,double bal_inicial){
    titularCuenta=titular; 
    balance=bal_inicial;
    this->Caja=Caja;
    }
bool CuentaCorriente::retirar(double cant){
    if((balance-cant)<0){
        cant=cant-balance;
        cout<<"[Error:La cuenta corriente no posee suficiente balance, se retirara lo que falte de la caja de ahorro]"<<endl;
        
        if(!(Caja->retirar(cant)))
            return false;

        balance=0;
        return true;
    }
    balance=balance-cant;
    return true;
}

void CuentaCorriente::mostrarInfo(){
    cout<<"┌-------------------------------------┐"<<endl;
    cout<<" Estado de la cuenta:\n"<<
            " CUENTA CORRIENTE"<<endl<<
            " Titular= "<< titularCuenta << endl<<
            " Balance= "<<fixed<< setprecision(2)<<balance<< " $" <<endl<<
          "└-------------------------------------┘"<<endl;
}

