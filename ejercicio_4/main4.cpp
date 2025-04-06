#include "banco.h"

int main()
{
    shared_ptr<CajaDeAhorro>  Micajadeahorro=make_shared<CajaDeAhorro>(CajaDeAhorro("Zoe Larisson",100));
    CuentaCorriente micuentaCorr= CuentaCorriente("Zoe Larisson",Micajadeahorro,50);
    //los doble endl son adrede
    cout<< "Primero pruebo el funcionamiento de mi caja de ahorro"<<endl;
    cout<< "Estado incial: "<<endl<<endl;
    Micajadeahorro->mostrarInfo();
    
    cout<<endl<< "ingresan 100 pesos a la cuenta de ahorro"<<endl<<endl;
    Micajadeahorro->depositar(100);
    Micajadeahorro->mostrarInfo();
    cout<<endl<<"A partir de ahora cada vez que muestre el estado de la cuenta se quitaran 20$, como ahora:"<<endl<< endl;

    Micajadeahorro->mostrarInfo();

    cout<<endl<< "Primero retiro toda la plata que hay en la cuenta de ahorro "<<endl;
    
    Micajadeahorro->retirar(180);

    cout<<endl<<"Ahora como no tengo dinero en la cuenta suficiente como para imprimir, no me dejar imprimir la informacion, pero no se cortara el programa"<<endl<<endl;

    Micajadeahorro->mostrarInfo();
    cout<<endl<< "Pero si ingreso 20 pesos si va a poder"<<endl<<endl;
    
    Micajadeahorro->depositar(20);
    Micajadeahorro->mostrarInfo();

    cout<<"-----------------------------------------------------------------------------"<<endl<<endl; 

    cout<<"Prueba de la cuenta corriente: "<<endl;
    cout<<endl<<"Establezco que hay 100 pesos en la caja de ahorro asociada y 50 en la cuenta corriente "<<endl<<endl;
    Micajadeahorro->depositar(100);
    micuentaCorr.mostrarInfo();

    cout<<endl<<"Deposito 100 pesos y despues retiro 50"<<endl<<endl;
    micuentaCorr.depositar(100);
    micuentaCorr.mostrarInfo();
    micuentaCorr.retirar(50);
    micuentaCorr.mostrarInfo();
    cout<<endl<<"Retiro 100 y despues 1"<<endl<<endl;
    micuentaCorr.retirar(100);
    micuentaCorr.mostrarInfo();
    micuentaCorr.retirar(1);
    micuentaCorr.mostrarInfo();
    Micajadeahorro->mostrarInfo();
    cout<<endl<<"Ahora retiro 80 de la cuenta corriente y obtengo error: "<<endl<<endl;
    micuentaCorr.retirar(80);
    micuentaCorr.mostrarInfo();
    return 0;
}
