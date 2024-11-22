//Diego Méndez Morales
//A01713173
//Proyecto Orientado a Objetos
//Simulador batalla pokemon

#ifndef POKEMON_H
#define POKEMON_H

#include "personaje_final.h"
#include "tipo_final.h"
#include "ataque_final.h"

//Creacion de la clase Pokemon, la cual tiene como atributos y métodos los de
//la clase Personaje, sumado a que tiene un atributo de tipo Tipo y una lista 
//de ataques para combatir

class Pokemon : public Personaje {
private:

    //Atributos propios

    int vida;
    Tipo tipo;
    Ataque ataques[3];
    int max_ataques;

public:

    //Prototipo de funciones

    Pokemon();
    Pokemon(std::string nom, std::string city, int lv, int hp, Tipo t);

    int get_vida();
    Tipo get_tipo();
    Ataque get_ataque(int index);

    void agregar_ataq(Ataque a);
    void recibe_dano(int dano);
};

// Implementación de la clase

//Constructores
//Default
Pokemon::Pokemon(){ 
    nombre = "";
    lugar = "";
    nivel = 0;
    vida = 0;
    tipo = Tipo();
    max_ataques = 0;
}
//Por parámetros
Pokemon::Pokemon(std::string nom, std::string city, int lv, int hp, Tipo t){
    nombre = nom;
    lugar = city;
    nivel = lv;
    vida = hp;
    tipo = t;
    max_ataques = 0;
}

//Getters
//@return int: puntos de vida
int Pokemon::get_vida(){ 
    return vida; 
    }
//@return Tipo: tipo del pokemon
Tipo Pokemon::get_tipo(){
    return tipo; 
    }
//@return Ataque; ataque que tiene el pokemon guardado
Ataque Pokemon::get_ataque(int pos){
    if (pos >= 0 && pos < max_ataques){
        return ataques[pos];
    }
    return Ataque();
}

//Funciones para combatir

//Recibe un ataque y lo guarda en su arreglo para despues usarlo
//@return
void Pokemon::agregar_ataq(Ataque a){
    if (max_ataques < 3){
        ataques[max_ataques] = a;
        max_ataques++;
    }
}
//Recibe cierto daño que le quitara a la vida del contrincante
//@return
void Pokemon::recibe_dano(int dano){
    vida -= dano;
    if (vida < 0) vida = 0;
}

#endif
