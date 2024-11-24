//Diego Méndez Morales
//A01713173
//Proyecto Orientado a Objetos
//Simulador batalla pokemon

#ifndef TIPO_H
#define TIPO_H

#include <string>
#include <iostream>

//Creacion de la clase Tipo la cual guarda todo el sistema de ventajas y
//debilidades entre los Pokemon y los ataques que usan.

class Tipo {
private:

    //Atributos

    std::string nombre;
    std::string ventajas[5];
    std::string debilidades[5];
    int max_ven;
    int max_deb;

public:

    //Prototipo de funciones

    Tipo();
    Tipo(std::string nom);

    std::string get_nombre();
    void set_nombre(std::string nom);

    void agregar_ventaja(std::string type);
    void agregar_debilidad(std::string type);

    void mostrar_ventajas();
    void mostrar_debilidades();

    int multiplica(std::string nom);
};

// Implementación de la clase

//Constructores
//Default
Tipo::Tipo(){ 
    nombre = "";
    max_ven = 0;
    max_deb = 0;
}
//Por parámetros
Tipo::Tipo(std::string nom){
    nombre = nom;
    max_ven = 0;
    max_deb = 0;
}

//Get y set para el nombre
//@return string: nombre del tipo
std::string Tipo::get_nombre(){
    return nombre;
    }
//@return
void Tipo::set_nombre(std::string nom){ 
    nombre = nom;
    }

//Funciones donde se almacenan las compatibilidades entre tipos
//Recibe un string de un tipo para agregarlo a sus listas para después 
//determinar su compatibilidad
//@return
void Tipo::agregar_ventaja(std::string type){
    if (max_ven < 5){
        ventajas[max_ven] = type;
        max_ven++;
    }
}
//@return
void Tipo::agregar_debilidad(std::string type){
    if (max_deb < 5){
        debilidades[max_deb] = type;
        max_deb++;
    }
}

//Funciones para mostrar las compatibilidades
//@return
void Tipo::mostrar_ventajas(){
    for (int i = 0; i < max_ven; i++){
        std::cout << ventajas[i] << std::endl;
    }
}
//@return
void Tipo::mostrar_debilidades(){
    for (int i = 0; i < max_deb; i++){
        std::cout << debilidades[i] << std::endl;
    }
}

//Funcion para determinar el aumento de la carácteristica de poder del ataque
//que se usará en combate, recibe el tipo del contrincante y lo busca dentro
//de sus listas para determinar cuanto daño le hará
//@return int: aumento de daño
int Tipo::multiplica(std::string nom){
    for (int i = 0; i < 5; i++){
        if (ventajas[i] == nom){
            return 1.5;
        }
        if (debilidades[i] == nom){
            return 0.0;
        }
    }
    return 1.0;
}

#endif

