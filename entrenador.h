#ifndef ENTRENADOR_PERSONAJE_H
#define ENTRENADOR_PERSONAJE_H

#include <iostream>
#include <string>
#include "pokemon.h"
#include "personaje.h"

class Entrenador: public Personaje{
    private:

        Pokemon equipo[3];
        int max_poke;

    public:

        Entrenador(){
            max_poke = 0;
        }
        Entrenador(std::string nom, std::string city, int lv):
        Personaje(nom, city, lv){
            max_poke = 0;
        }

        void agregar_poke(Pokemon poke){
            if (max_poke < 3){
                equipo[max_poke] = poke;
                max_poke++;
            }
        }

        void quitar_poke(int posicion){
            if (posicion < 0 || posicion >= max_poke) {
                 std::cout << "Posición no válida." << std::endl;
                return;
            }
            for (int i = posicion; i < max_poke - 1; i++) {
                equipo[i] = equipo[i + 1];
            }
            
            --max_poke;
            }

        void mostrar_equipo(){
            for(int i=0; i<max_poke; i++){
                std::cout << equipo[i].get_nombre() << std::endl;
            }
        }
};
#endif