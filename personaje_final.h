//Diego Méndez Morales
//A01713173
//Proyecto Orientado a Objetos
//Simulador batalla pokemon

#ifndef PERSONAJE_H
#define PERSONAJE_H

#include <string>
#include <iostream>

//Creacion de la clase abstracta Personaje
//De la cual se desprenden las clases Pokemon y Entrenador

class Personaje {
protected:

    //Atributos a heredar

    std::string nombre;
    std::string lugar;
    int nivel;

public:

    //Métodos a heredar
    //Prototipo de funciones

    Personaje();
    Personaje(std::string nom, std::string city, int lv);

    std::string get_nombre();
    std::string get_lugar();
    int get_nivel();

    void set_nombre(std::string nom);
    void set_lugar(std::string city);
    void set_nivel(int lv);

    void aumento_lv();
    void mostrar();
};

// Implementación de la clase

//Constructores
//Default
Personaje::Personaje(){ 
    nombre = "";
    lugar = "";
    nivel = 0;
}
//Por parámetros
Personaje::Personaje(std::string nom, std::string city, int lv){ 
    nombre = nom;
    lugar = city;
    nivel = lv;
}

//Getters
//@return string: nombre del personaje
std::string Personaje::get_nombre(){ 
    return nombre; 
    }
//@return string: lugar de origen
std::string Personaje::get_lugar(){ 
    return lugar;
    }
//@return int: nivel del personaje
int Personaje::get_nivel(){ 
    return nivel;
    }

//Setters
//@return
void Personaje::set_nombre(std::string nom){ 
    nombre = nom;
    }
//@return
void Personaje::set_lugar(std::string city){ 
    lugar = city;
    }
//@return
void Personaje::set_nivel(int lv){ 
    nivel = lv;
    }

//Función para aumentar el nivel del Pokemon o Entrenador por batalla ganada
//@return
void Personaje::aumento_lv() { nivel++; }

//Función para mostrar atributos
//@return
void Personaje::mostrar() {
    std::cout << "Nombre: " << nombre << std::endl;
    std::cout << "Lugar: " << lugar << std::endl;
    std::cout << "Nivel: " << nivel << std::endl;
}

#endif
