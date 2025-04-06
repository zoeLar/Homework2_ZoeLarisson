#pragma once 
#include <string>
#include <iostream>
#include <vector>
#include <iomanip>
#include <memory>

using namespace std;


class banco{
    protected:
        double balance;
        string titularCuenta;
    public: 
        virtual void depositar(double cant);
        virtual bool retirar(double cant)=0;
        virtual void mostrarInfo()=0;
        
};

class CajaDeAhorro: public banco{
    private: 
        int contador;
    public:
        CajaDeAhorro( string titular,double bal_inicial=0);
        bool retirar(double cant) override;
        void mostrarInfo() override;
    friend class cuentacorriente;

};
class CuentaCorriente: public banco{
    private:
    shared_ptr<CajaDeAhorro> Caja;
    public:
        CuentaCorriente( string titular,shared_ptr<CajaDeAhorro> Caja,double bal_inicial=0);
        bool retirar(double cant) override;
        void mostrarInfo() override;
};

//explicacion:
/* Utilice en banco protected para los atributos ya que no tienen que ser accesible para un "usuario" para mantener el encapuslamiento, 
pero si deberian ser accesibles para las clases hijas. Usee public para los metodos ya que deben ser posibles de usar fuera de la clase al instanciar un objeto (en este caso lo
que se instancia son las clases hijas, ya que banco es una clase abstracta)

Para caja de ahorro y cuenta corriente use private para los atributos que no heredaron de banco, ya que no deberian ser accesibles 
para mantener el encapsulamiento, mientras que los metodos si deberian serlo. 
Ademas al heredar de banco utilice un acceso public, ya que queria mantener lo heredado por banco como llego: lo public, public y lo protected, protected.
*/