//Diego Méndez Morales
//A01713173
//Proyecto Orientado a Objetos
//Simulador batalla pokemon

#ifndef ATAQUE_H
#define ATAQUE_H

#include <string>
#include "tipo_final.h"

//Creación de la clase Ataque, la cual guarda el poder de daño de cada ataque
//junto con su tipo para despues utilizar ambos en combate

class Ataque {
private:

    // Atributos

    std::string nombre;
    float poder;
    int precision;
    Tipo tipo;

public:

    //Prototipo de funciones

    Ataque();
    Ataque(std::string nom, float pow, int prec, Tipo t);

    std::string get_nombre();
    float get_poder();
    int get_precision();
    Tipo get_tipo();
};

// Implementación de la clase
//Construtores
//Default
Ataque::Ataque() {
    nombre = "";
    poder = 0.0;
    precision = 0;
    tipo = Tipo();
}
//Por parámetros
Ataque::Ataque(std::string nom, float pow, int prec, Tipo t) {
    nombre = nom;
    poder = pow;
    precision = prec;
    tipo = t;
}

//Getters para los atributos
//@return string: nombre del ataque
std::string Ataque::get_nombre(){ 
    return nombre; 
    }
//@return int: poder de daño normal (sin considerar el tipo)
float Ataque::get_poder(){ 
    return poder;
    }
//@return int: presicion del ataque
int Ataque::get_precision(){ 
    return precision; 
    }
//@return Tipo: tipo del ataque
Tipo Ataque::get_tipo(){ 
    return tipo; 
    }

#endif

