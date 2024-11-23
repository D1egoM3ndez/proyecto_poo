//Diego Méndez Morales
//A01713173
//Proyecto Orientado a Objetos
//Simulador batalla pokemon

#ifndef ENTRENADOR_H
#define ENTRENADOR_H

#include <string>

#include "personaje_final.h"
#include "pokemon_final.h"

//Creacion de la clase Entrenador, la cual hereda junto con la clase Pokemon
//los atributos y métodos de la clase Personaje
//Esta clase guarda el equipo de cada entrenador para despues usarlo

class Entrenador : public Personaje {
private:

    //Atributos propios

    Pokemon equipo[3];
    int max_pokemon;

public:

    //Prototipo de funciones

    Entrenador();
    Entrenador(std::string nom, std::string city, int lv);

    Pokemon get_poke(int index);
    void agregar_poke(Pokemon p);
};

// Implementación de la clase

//Constructores
//Default
Entrenador::Entrenador(){
    nombre = "";
    lugar = "";
    nivel = 0;
    max_pokemon = 0;
}
//Por parámetros
Entrenador::Entrenador(std::string nom, std::string city, int lv){
    nombre = nom;
    lugar = city;
    nivel = lv;
    max_pokemon = 0;
}

//Funcion para obtener un pokemon del equipo
//@return Pokemon: pokemon del equipo seleccionado
Pokemon Entrenador::get_poke(int index){
    if (index >= 0 && index < max_pokemon){
        return equipo[index];
    }
    return Pokemon();
}

//Funcion para agregar pokemon al equipo
//@return
void Entrenador::agregar_poke(Pokemon p){
    if (max_pokemon < 3) {
        equipo[max_pokemon] = p;
        max_pokemon++;
    }
}

#endif
