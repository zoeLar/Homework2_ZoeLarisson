#include "ejercicio2.h"

//--------------------

bool compara_estudiantes(const shared_ptr<estudiante> a, const shared_ptr<estudiante> b) {
    return *a < *b; 
}
//--------------------
estudiante::estudiante(string nomb,unsigned int n_legajo, vector<pair<string, int>> mat_nota){
    nombre=nomb;
    legajo=n_legajo;
    materia_nota=mat_nota;
    int suma=0, total=mat_nota.size();

    for( int i=0; i<total; i++){
        suma+=mat_nota[i].second;
    }
    promedio_general= (double)suma/(double)total;
}

estudiante::~estudiante(){}

unsigned int estudiante::leer_legajo(){
    return legajo;
}

string estudiante::leer_nombre(){
    return nombre;
}

double estudiante::leer_promedio(){
    return promedio_general;
}

vector<pair<string, int>> estudiante::leer_materias(){
    return materia_nota;
}

bool estudiante::operator<(const estudiante &other) const{ //utilizo const para indicar que no se modifica nada
    return this->nombre<other.nombre;                      //compara los nombres
};

//---------------------------------------------------------------

curso::curso(vector<shared_ptr<estudiante>> alumnos){
    alum=alumnos;
    cant_integrantes=alumnos.size();
}

curso::~curso(){
    alum.clear();
}

bool curso::inscribir(shared_ptr<estudiante> alumno){
    if(curso_completo()){
        return false;
    }
    alum.push_back(alumno);
    cant_integrantes++;
    return true;
}

void curso::desinscribir(shared_ptr<estudiante> alumno){
    unsigned int n_legajo=alumno->leer_legajo();
    cout<<n_legajo<<endl<<endl;

    for(int i=0; i<cant_integrantes; i++){
        unsigned int n_legajo2=alum[i]->leer_legajo();

        if (n_legajo==n_legajo2){
            alum.erase(alum.begin()+i);  
            cant_integrantes--;
            return;}
        
    }
}

bool curso::buscar(int n_legajo){

    for(int i=0; i<cant_integrantes; i++){
        unsigned int n_legajo2=alum[i]->leer_legajo();

        if (n_legajo==n_legajo2)
            return true;
    }
    return false; //si no lo encuentra
}

bool curso::curso_completo(){
    if(cant_integrantes==20){
        return true;
    }
    return false;
}

ostream & operator << (ostream &  os , const estudiante& est) {
    string cursos;
    for (int i=0; i<est.materia_nota.size(); i++){
        cursos.append("{" + est.materia_nota[i].first + " : " + to_string(est.materia_nota[i].second) + "}, ");
    }
    os << "[ Legajo: " << est.legajo 
    << " | Nombre: " << est.nombre 
    <<" | "<< cursos<< " ]"<<endl;

    return os;
}

void curso::print_en_orden(){
   sort(alum.begin(),alum.end(),compara_estudiantes);
   cout<<"-----------------------------------------------------------------"<<endl;
   for(int i=0; i<cant_integrantes;i++){
        cout<<*alum[i];
   }
   cout<<"-----------------------------------------------------------------"<<endl;
   
}
curso::curso(const curso& cursoAcopiar){
    alum=cursoAcopiar.alum; 
    cant_integrantes=cursoAcopiar.alum.size();
}

vector<shared_ptr<estudiante>> curso::alumnos_getter(){
    return alum;
}



