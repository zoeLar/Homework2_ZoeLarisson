#include "ejercicio2.h"

int main()
{   
    
    vector<string> materias={"Algebra","Filosofia"};
    vector<int> notas={8 , 5 , 4 , 9 , 1 , 8 , 4 , 7 , 6 , 9 , 4 , 9 , 3 , 10 , 10 , 5 , 1 , 2 , 2 , 6 , 2 , 1 , 4 , 8 , 7 , 6 , 9 , 1 , 6 , 3 , 2 , 10 , 2 , 4 , 2 , 5 , 7 , 7 , 4 , 4}; //numeros aleatorios sacados de un codigo de python con la libreria random
    vector<string> nombres={"Zoe", "Jose","Juan","Sofia","Luz","Maria","Camila","Ana","Matias","Marcelo","Constanza","Pablo","Mariana","Nelia","Agustin","Sergio","Valentina","Maialen","Rodrigo","Luca"};
    vector<shared_ptr<estudiante>> misalumnos;
    
    for(int i=0; i<20; i++){
        vector<pair<string, int>> mat_nota={pair(materias[0],notas[i*2]),pair(materias[1],notas[i*2+1])}; //creo los cursos con las notas de cada estudiante
        misalumnos.push_back(make_shared<estudiante>(estudiante(nombres[i],100+i,mat_nota)));             //creo smart pointers de objeto estudiante
        //pongo esos punteros en el vector de alumnos 
    }

    curso curso1= curso(misalumnos);
    cout<<"i) iv) y v)"<<endl;

    cout<< "Una vez creado el curso hago otro curso que sea una copia: "<<endl;

    curso curso2=curso1;

    cout<<"Imprimo los dos cursos:"<<endl;
    curso1.print_en_orden();
    curso2.print_en_orden();

    cout<<"Desinscribo a Agustin de Curso1"<<endl;
    cout<<curso1.alumnos_getter()[0]<<endl;
    cout<<curso2.alumnos_getter()[0]<<endl;
    curso1.desinscribir(curso1.alumnos_getter()[0]); //el primer elemento
    
    cout<<"Ahora imprimo los dos cursos"<<endl;
    curso1.print_en_orden();
    curso2.print_en_orden();
    cout<<"Como se ve, se ha desinscrito de curso 1 a Agustin, pero en Curso 2 Agustin sigue estando, esto es porque hice un deep copy de la clase y por lo tanto del vector de estudiantes"<<endl<<
          "pero a los punteros a objeto estudiante les hice un shallow. Esto lo hice ya que al tener un curso muy parecido que comparta"<<endl<<
          "estudiantes, quiero que tenga la posibilidad de quitar estudiantes de su curso, pero que no haga falta que ambos desinscriban al mismo estudiante"<<endl<<
          "Es decir, quiero que sean independientes entre si, pero que compartan los mismos punteros a estudiante"<<endl;
    
    int continuar;
    cout<<"Continuar al siguiente punto?: [si≠0] [no=0]"<<endl;
    cin>> continuar;
    if(continuar==0){
        return 0;
    }
    cout<<"i) e ii) e iv)"<<endl;
    cout<<"Añado un alumno llamado Abril a curso2 que esta lleno"<<endl;
    vector<pair<string, int>> mat_nota={pair(materias[0],8),pair(materias[1],10)}; //creo los cursos con las notas de cada estudiante
    shared_ptr<estudiante> abril=(make_shared<estudiante>(estudiante("Abril",121,mat_nota)));
    bool res=curso2.inscribir(abril);
    cout<<"Resultado de la operacion: "<<res<< " "<<endl;
    
    cout<<"Imprimo los estudiantes:"<<endl;
    curso2.print_en_orden();
    cout<<"Si ingreso a Abril en curso 1 si se va a poder porque tiene 19 integrantes"<<endl;
    curso1.inscribir(abril);
    curso1.print_en_orden();

    //Que relacion tienen curso y estudiante?
    //Tienen una relacion de agregacion. El whole seria el curso, y las parts serian los estudiantes. Un estudiante
    //puede existir sin un curso y al reves tambien.
    
    return 0;
}
