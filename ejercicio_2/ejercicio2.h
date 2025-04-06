#pragma once 
#include <string>
#include <iostream>
#include <vector>
#include <utility>
#include <memory>
#include <algorithm>

using namespace std;

class estudiante{
    private:
        string nombre;
        unsigned int legajo;
        vector<pair<string, int>> materia_nota;
        double promedio_general;
    public:
        estudiante(string nomb,unsigned int n_legajo,  vector<pair<string, int>> mat_nota);
        ~estudiante();
        unsigned int leer_legajo();
        string leer_nombre();
        double leer_promedio();
        vector<pair<string, int>> leer_materias();
        
        bool operator<(const estudiante &other) const;
    friend ostream & operator << (ostream &  os , const estudiante& est);
        
};

class curso{
private:
    vector<shared_ptr<estudiante>> alum; //No me importa la complejidad de recorrer el vector porque maximo son 20
    unsigned int cant_integrantes;

public:
    curso(vector<shared_ptr<estudiante>> alumnos);
    curso(const curso& cursoAcopiar);
    bool inscribir(shared_ptr<estudiante> alumno);
    void desinscribir(shared_ptr<estudiante> alumno);
    bool buscar(int n_legajo);
    bool curso_completo();
    void print_en_orden();
    vector<shared_ptr<estudiante>> alumnos_getter();
    curso copiar_curso();
    ~curso();
    
};