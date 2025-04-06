#include "numero.h"

int main()
{   
    cout<<endl<<"Realizo operaciones entre los complejos: 3+2i y 5+6i"<<endl<<endl;
    complejo micomplejo=complejo(vector<double> {3,2},vector<double> {5,6});
    micomplejo.suma();
    micomplejo.resta();
    micomplejo.multiplicacion();
    cout<<endl<<"Realizo operaciones entre los enteros: 3 y 5"<<endl<<endl;
    entero mientero=entero(3,4);
    mientero.suma();
    mientero.resta();
    mientero.multiplicacion();
    cout<<endl<<"Realizo operaciones entre los enteros: (valor no entero) 3.5 y 5"<<endl<<endl;
    entero mientero2=entero(3.5,4);
    mientero2.suma();
    mientero2.resta();
    mientero2.multiplicacion();
    cout<<endl<<"Realizo operaciones entre los reales:  3 y 4.123"<<endl<<endl;
    real mireal=real(3,4.123);
    mireal.suma();
    mireal.resta();
    mireal.multiplicacion();

    return 0;
}
