#pragma once 
#include <string>
#include <iostream>
#include <memory>
#include <vector>

using namespace std;


class numero{
    public:
    virtual void suma()=0;
    virtual void resta()=0;
    virtual void multiplicacion()=0;
    virtual string toString()=0;
};

class entero: public numero{
    private:
        int numero1;
        int numero2;
        int resultado;
    public:
        entero(int numero, int numero2);
        void suma() override;
        void resta() override;
        void multiplicacion() override;
        string toString() override;
};
class real: public numero{
    private:
        double numero1;
        double numero2;
        double resultado;
    public:
        real(double numero1, double numero2);
        void suma() override;
        void resta() override;
        void multiplicacion() override;
        string toString() override;
};

class complejo: public numero{
    private:
        vector<double> numero1;
        vector<double> numero2;
        vector<double> resultado;
    public:
        complejo(vector<double> numero1,vector<double> numero2);
        void suma() override;
        void resta() override;
        void multiplicacion() override;
        string toString() override;
};
